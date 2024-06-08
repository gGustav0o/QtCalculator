#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>
#include <QDebug>
#include <stack>

using namespace std;

class Calculator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString calcValue READ calcValue WRITE setCalcValue NOTIFY calcValueChanged FINAL)
    Q_PROPERTY(double result READ result WRITE setResult NOTIFY resultChanged FINAL)
    Q_PROPERTY(int resultLength READ resultLength NOTIFY resultLengthChanged FINAL)
public:
    explicit Calculator(QObject *parent = nullptr);
    QString& calcValue();
    double result();
    int resultLength();
public slots:

    void numberPressed(const int number);
    void changeSignPressed();
    void operationPressed(const QChar);
    void equalsPressed();
    void clearPressed();
    void dotPressed();
    void bracketPressed();
    void percentPressed();

    void setResult(const double);
    void setCalcValue(const QString&);
    QString& getCalcValue();

private:
    stack<double> numbers;
    stack<QChar> operations;
    int m_resultLength = 0;
    double m_result = 0.0;
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
    double calculate();
    int getOperationsSize();
    int getNumbersSize();
    void clearDemicalPosition();
    bool dot = false;
    double demicalPosition = 0.1;
    double numberBuffer = 0.0;
    void readNumberBuffer();
    void pushNumbers(const double);
    double popNumbers();
    void pushOperations(const QChar);
    QChar popOperations();

signals:
    void calcValueChanged();
    void resultChanged();
    void resultLengthChanged();
};



#endif // CALCULATOR_H
