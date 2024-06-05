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

double Calculator::calculate()
{

    double a_number, b_number, result;
    a_number = popNumbers();
    char o = popOperations().toLatin1();
    switch(o){
    case '+':
        b_number = popNumbers();
        result = a_number + b_number;
        pushNumbers(result);
        break;
    case '-':
        b_number = popNumbers();
        result = b_number - a_number;
        pushNumbers(result);
        break;
    case '*':
        b_number = popNumbers();
        result = a_number * b_number;
        pushNumbers(result);
        break;
    case '/':
        b_number = popNumbers();
        if(b_number == 0.0){
            // TODO : ERROR
        }
        result = b_number / a_number;
        pushNumbers(result);
        break;
    }
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
    qDebug() << "THE NUMBER IS " << numbers.top();
}

void Calculator::pushNumbers(const double number)
{
    numbers.push(number);
}

double Calculator::popNumbers()
{
    qDebug() << "POPPING";
    double temp = -1;
    qDebug() << "POP: TOP IS " << numbers.top();
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

void Calculator::numberPressed(const int number){

    qDebug()<< "dot " << dot  << "; NUMBER BUFFER "<< numberBuffer <<"; N * DP " <<number * demicalPosition;
    if(dot){
        double tmp = (double)number * demicalPosition;
        numberBuffer += tmp;
        demicalPosition *= 0.1;
    } else {
        numberBuffer *= 10;
        numberBuffer += number;
    }



    m_calcValue += QString::number(number);
    qDebug() << number;
    emit calcValueChanged();

}

void Calculator::changeSignPressed()
{

}

void Calculator::operationPressed(const QChar operation)
{
    readNumberBuffer();
    pushOperations(operation);
    m_calcValue += operation;
    qDebug() << operation;
    emit calcValueChanged();
}

void Calculator::equalsPressed()
{
    readNumberBuffer();
    setResult(calculate());
    emit resultChanged();
}

void Calculator::clearPressed()
{
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

void Calculator::setResult(const double result)
{
    this->m_result = result;
}
