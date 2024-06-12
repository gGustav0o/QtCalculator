#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>
#include <QDebug>
#include <stack>
#include <QTime>
#include <QQuickView>
#include "longdouble.h"

using namespace std;

class Calculator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString calcValue READ calcValue WRITE setCalcValue NOTIFY calcValueChanged FINAL)
    Q_PROPERTY(QString result READ result WRITE setResult NOTIFY resultChanged FINAL)
    Q_PROPERTY(bool isSecretMenuVisible READ isSecretMenuVisible WRITE setIsSecretMenuVisible NOTIFY isSecretMenuVisibleChanged FINAL)
public:
    explicit Calculator(QObject *parent = nullptr);
    QString calcValue() const;
    QString result() const;
    bool isSecretMenuVisible() const;
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
    void setIsSecretMenuVisible(const bool);

private:
    QString m_result       = "";
    QString m_calcValue    = "";

    QTime time;

    stack<LongDouble>    numbers;
    stack<QChar>         operations;

    LongDouble numberBuffer;
    LongDouble demicalPosition;

    bool m_isSecretMenuVisible    = true;
    bool openBracket              = true;
    bool operationLast            = true;

    bool bufferReaded             = false;
    bool numberLast               = false;
    bool bracketLast              = false;
    bool secretMenuActivated      = false;
    bool dot                      = false;

    int    bufferLength       = 0;

    QChar      popOperations();
    LongDouble popNumbers();

    LongDouble calculate();

    void pushOperations(const QChar);
    void pushNumbers(const LongDouble);

    void clearNumbers();
    void clearOperations();
    void clearDemicalPosition();
    void readNumberBuffer();

    int getOperationPriority(QChar) const;
    int getOperationsSize()         const;
    int getNumbersSize()            const;

signals:
    void calcValueChanged();
    void resultChanged();
    void resultLengthChanged();
    void isSecretMenuVisibleChanged();
};



#endif // CALCULATOR_H
