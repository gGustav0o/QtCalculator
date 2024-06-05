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
    operations = stack<char>();
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
}

void Calculator::pushNumbers(const double number)
{
    numbers.push(number);
}

double Calculator::popNumbers()
{
    double temp = numbers.top();
    numbers.pop();
    return temp;
}

void Calculator::pushOperations(const char operation)
{
    operations.push(operation);
}

char Calculator::popOperations()
{
    char temp = operations.top();
    operations.pop();
    return temp;
}


QString& Calculator::calcValue(){
    return m_calcValue;
}

void Calculator::numberPressed(const int number){

    if(dot){
        numberBuffer += number * demicalPosition;
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
    pushOperations(operation);
    m_calcValue += operation;
    qDebug() << operation;
    emit calcValueChanged();
}

void Calculator::equalsPressed()
{

}

void Calculator::clearPressed()
{
    clearOperations();
    clearNumbers();
}

void Calculator::dotPressed()
{
    dot = true;
}


