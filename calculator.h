#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>
#include <QDebug>
#include <stack>
#include "longdouble.h"

using namespace std;

class Calculator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString calcValue READ calcValue WRITE setCalcValue NOTIFY calcValueChanged FINAL)
    Q_PROPERTY(QString result READ result WRITE setResult NOTIFY resultChanged FINAL)
public:
    explicit Calculator(QObject *parent = nullptr);
    QString& calcValue();
    QString result();
    int resultLength();
public slots:

    void equalsActivated();
    void numberPressed(const int number);
    void changeSignPressed();
    void operationPressed(const QChar);
    void equalsPressed();
    void clearPressed();
    void dotPressed();
    void bracketPressed();
    void percentPressed();

    void setResult(const QString&);
    void setCalcValue(const QString&);
    QString& getCalcValue();

private:
    stack<LongDouble> numbers;
    stack<QChar> operations;
    QString m_result;
    QString m_calcValue = "";
    void clearNumbers();
    void clearOperations();

    bool bufferReaded = false;
    bool openBracket = true;
    bool operationLast = true;
    bool numberLast = false;
    bool bracketLast = false;
    int bufferLength = 0;

    int getOperationPriority(QChar);
    LongDouble calculate();
    int getOperationsSize();
    int getNumbersSize();
    void clearDemicalPosition();
    bool dot = false;
    double demicalPosition = 0.1;
    LongDouble numberBuffer;
    void readNumberBuffer();
    void pushNumbers(const LongDouble);
    LongDouble popNumbers();
    void pushOperations(const QChar);
    QChar popOperations();

signals:
    void calcValueChanged();
    void resultChanged();
    void resultLengthChanged();
};



#endif // CALCULATOR_H
