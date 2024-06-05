#include "calculator.h"

Calculator::Calculator(QObject *parent)
    : QObject{parent}
{

}

void Calculator::numberPressed()
{
    qDebug() << "WORKING!!";
}


