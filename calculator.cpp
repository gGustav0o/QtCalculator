#include "calculator.h"

Calculator::Calculator(QObject *parent)
    : QObject{parent}
    , m_result("0")
    , numberBuffer("0")
    , demicalPosition("0.1")
    , m_calcValue("")
    , time()
{

}

void Calculator::setCalcValue(const QString &calcValue)
{
    m_calcValue = calcValue;
}

void Calculator::setIsSecretMenuVisible(const bool isSecretMenuVisible)
{
    m_isSecretMenuVisible = isSecretMenuVisible;
}

void Calculator::clearNumbers()
{
    numbers = stack<LongDouble>();
}

void Calculator::clearOperations()
{
    operations = stack<QChar>();
}

int Calculator::getOperationPriority(QChar operation) const
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

LongDouble Calculator::calculate()
{
    LongDouble a_number, b_number, result;
    a_number = LongDouble(popNumbers());
    b_number = LongDouble(popNumbers());
    char o = popOperations().toLatin1();

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
        if(b_number == LongDouble("0")){
            throw string("division by zero");
        }
        break;
    }

    pushNumbers(result);
    return numbers.top();
}

int Calculator::getOperationsSize() const
{
    return operations.size();
}

int Calculator::getNumbersSize() const
{
    return numbers.size();
}

void Calculator::clearDemicalPosition()
{
    dot = false;
    demicalPosition = LongDouble("0.1");
}

void Calculator::readNumberBuffer()
{
    pushNumbers(numberBuffer);
    numberBuffer.reset();
    clearDemicalPosition();
    bufferReaded = true;
    bufferLength = 0;
}

void Calculator::pushNumbers(const LongDouble number)
{
    numbers.push(number);
}

LongDouble Calculator::popNumbers()
{
    LongDouble temp;
    temp = LongDouble(numbers.top());
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


QString Calculator::calcValue() const
{
    return m_calcValue;
}

QString Calculator::result() const
{
    return this->m_result;
}

bool Calculator::isSecretMenuVisible() const
{
    return m_isSecretMenuVisible;
}


void Calculator::equalsActivated()
{
    secretMenuActivated = true;
    time.restart();
}

void Calculator::numberPressed(const int number){

    bufferLength++;
    numberLast = true;
    operationLast = false;
    bufferReaded = false;
    bracketLast = false;

    if(dot){
        LongDouble tmp = LongDouble(std::to_string(number)) * demicalPosition;
        numberBuffer = LongDouble(numberBuffer + tmp);
        demicalPosition = demicalPosition * LongDouble("0.1");
    } else {
        numberBuffer = numberBuffer * LongDouble(std::to_string(10));
        numberBuffer = numberBuffer + LongDouble(std::to_string(number));
    }

    if(secretMenuActivated && time.elapsed() <= 5000) {
        if(numberBuffer == LongDouble("123")) {
            setIsSecretMenuVisible(true);
            emit isSecretMenuVisibleChanged();
        }
    }

    m_calcValue += QString::number(number);
    emit calcValueChanged();

}

void Calculator::changeSignPressed()
{
    if(!bracketLast){
        int bufferLength = this->bufferLength;
        numberBuffer = numberBuffer * LongDouble("-1");
        if(!bufferReaded) readNumberBuffer();
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

    if(!bufferReaded) readNumberBuffer();
    m_calcValue += operation;

    while(operations.size() >= 0){
        if(operations.size() == 0
            || getOperationPriority(operation) > getOperationPriority(operations.top()))
        {
            pushOperations(operation);
            break;
        } else {
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
    LongDouble result;
    while(operations.size() > 0){
        result = LongDouble(calculate());
    }
    setResult(result.toString());
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
    m_result = LongDouble("0").toString();

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
    if(bracketLast) return;

    bracketLast = true;

    if(numbers.size() > 0 && !bufferReaded) readNumberBuffer();

    if(openBracket) {
        pushOperations(QChar::fromLatin1('('));
        openBracket = false;
        m_calcValue += '(';
    } else {
        while(operations.top() != '('){
            calculate();
        }
        popOperations();
        openBracket = true;
        m_calcValue += ')';
    }

    emit calcValueChanged();
}

void Calculator::percentPressed()
{
    readNumberBuffer();
    LongDouble percent = popNumbers() * LongDouble("0.01");
    setResult(percent.toString());
    emit resultChanged();
}

void Calculator::setResult(const QString& result)
{
    this->m_result = result;
}
