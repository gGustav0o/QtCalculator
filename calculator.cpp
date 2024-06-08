#include "calculator.h"

Calculator::Calculator(QObject *parent)
    : QObject{parent}
    , m_calcValue("")
{

}

void Calculator::setCalcValue(const QString &calcValue)
{
    this->m_calcValue = calcValue;
}

QString& Calculator::getCalcValue()
{
    return m_calcValue;
}

void Calculator::clearNumbers()
{
    numbers = stack<double>();
}

void Calculator::clearOperations()
{
    operations = stack<QChar>();
}

int Calculator::getOperationPriority(QChar operation)
{
    switch(operation.toLatin1()){
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '(':
        return 0;
    }
    return -1;
}

double Calculator::calculate()
{
    double a_number, b_number, result;
    a_number = popNumbers();
    b_number = popNumbers();
    char o = popOperations().toLatin1();

    qDebug() << QString::fromStdString("CALCULATING: ")
                    + QString::fromStdString(std::to_string(a_number))
                    + " "
                    + o
                    + " "
                    + QString::fromStdString(std::to_string(b_number));
    switch(o){
    case '+':
        result = a_number + b_number;
        break;
    case '-':
        result = b_number - a_number;
        break;
    case '*':
        result = a_number * b_number;
        break;
    case '/':
        if(b_number == 0.0){
            // TODO : ERROR
        }
        break;
    }


    pushNumbers(result);


    return numbers.top();
}

int Calculator::getOperationsSize()
{
    return operations.size();
}

int Calculator::getNumbersSize()
{
    return numbers.size();
}

void Calculator::clearDemicalPosition()
{
    dot = false;
    demicalPosition = 0.1;
}

void Calculator::readNumberBuffer()
{
    pushNumbers(numberBuffer);
    numberBuffer = 0.0;
    clearDemicalPosition();
    bufferReaded = true;
    bufferLength = 0;
}

void Calculator::pushNumbers(const double number)
{
    numbers.push(number);
}

double Calculator::popNumbers()
{
    double temp = -1;
    temp = numbers.top();
    numbers.pop();

    return temp;
}

void Calculator::pushOperations(const QChar operation)
{
    operations.push(operation);
}

QChar Calculator::popOperations()
{
    QChar temp = operations.top();
    operations.pop();
    return temp;
}


QString& Calculator::calcValue(){
    return m_calcValue;
}

double Calculator::result()
{
    return this->m_result;
}

int Calculator::resultLength()
{
    return m_resultLength;
}

void Calculator::numberPressed(const int number){

    bufferLength++;
    numberLast = true;
    operationLast = false;
    bufferReaded = false;
    bracketLast = false;

    if(dot){
        double tmp = (double)number * demicalPosition;
        numberBuffer += tmp;
        demicalPosition *= 0.1;
    } else {
        numberBuffer *= 10;
        numberBuffer += number;
    }



    m_calcValue += QString::number(number);
    emit calcValueChanged();

}

void Calculator::changeSignPressed()
{
    qDebug() << !bracketLast;
    if(!bracketLast){
        int bufferLength = this->bufferLength;
        numberBuffer *= -1;
        if(!bufferReaded) readNumberBuffer();
        qDebug() << m_calcValue.left(m_calcValue.length() - bufferLength);
        setCalcValue(m_calcValue.left(m_calcValue.length() - bufferLength) + "(-" + m_calcValue.right(bufferLength) + ')');
        emit calcValueChanged();
    }
}

void Calculator::operationPressed(const QChar operation)
{

    if(operationLast){
        if(operations.size() == 0) return;
        m_calcValue.chop(1);
    }

    operationLast = true;
    numberLast = false;
    bracketLast = false;

    if(!bufferReaded) readNumberBuffer(); //TODO
    m_calcValue += operation;

    while(true){
        if(operations.size() == 0
            || getOperationPriority(operation) > getOperationPriority(operations.top()))
        {
            pushOperations(operation);
            break;
        } else {
            //TODO:checkErrors
            calculate();
        }
    }

    emit calcValueChanged();
}

void Calculator::equalsPressed()
{
    operationLast = true;
    numberLast = false;
    if(!bufferReaded) readNumberBuffer();
    double result = 0.0;
    while(operations.size() > 0){
        result = calculate();
    }
    setResult(result);
    emit resultChanged();
}

void Calculator::clearPressed()
{
    operationLast = true;
    numberLast = false;
    openBracket = true;
    bufferReaded = false;
    bracketLast = false;

    clearOperations();
    clearNumbers();

    m_calcValue = "";
    m_result = 0.0;

    emit calcValueChanged();
    emit resultChanged();
}

void Calculator::dotPressed()
{
    if(!dot){
        dot = true;
        m_calcValue += '.';
        emit calcValueChanged();
    }
}

void Calculator::bracketPressed()
{
    qDebug() << "bracketPressed";
    if(bracketLast) return;

    bracketLast = true;

    if(numbers.size() > 0 && !bufferReaded) readNumberBuffer();

    if(openBracket) {
        pushOperations(QChar::fromLatin1('('));
        openBracket = false;
        m_calcValue += '(';
        qDebug() << "OPEN";
    } else {
        while(operations.top() != '('){
            calculate();
        }
        popOperations();
        openBracket = true;
        m_calcValue += ')';
        qDebug() << "CLOSE";
    }

    if(numbers.size() > 0) qDebug() << "RESULT";
    if(numbers.size() > 0) qDebug() << numbers.top();
    emit calcValueChanged();
}

void Calculator::percentPressed()
{
    readNumberBuffer();
    setResult(popNumbers() * 0.01);
    emit resultChanged();
}

void Calculator::setResult(const double result)
{
    this->m_result = result;
}
