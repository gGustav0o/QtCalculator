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
public:
    explicit Calculator(QObject *parent = nullptr);
    QString& calcValue();
    double result();
public slots:

    void numberPressed(const int number);
    void changeSignPressed();
    void operationPressed(const QChar);
    void equalsPressed();
    void clearPressed();
    void dotPressed();

    void setResult(const double);
    void setCalcValue(const QString&);
    QString& getCalcValue();

private:
    stack<double> numbers;
    stack<QChar> operations;
    double m_result = 0.0;
    QString m_calcValue = "";
    void clearNumbers();
    void clearOperations();

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
};



#endif // CALCULATOR_H
