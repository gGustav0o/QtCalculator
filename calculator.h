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
public:
    explicit Calculator(QObject *parent = nullptr);
    QString& calcValue();
public slots:

    void numberPressed(const int number);
    void changeSignPressed();
    void operationPressed(const QChar);
    void equalsPressed();
    void clearPressed();

    void setCalcValue(const QString&);
    QString& getCalcValue();

private:
    stack<double> numbers;
    stack<char> operations;
    QString m_calcValue = "";
    void clearNumbers();
    void clearOperations();

    void pushNumbers(const double);
    double popNumbers();
    void pushOperations(const char);
    char popOperations();

signals:
    void calcValueChanged();
};


#endif // CALCULATOR_H