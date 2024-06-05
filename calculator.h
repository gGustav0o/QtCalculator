#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>
#include <QDebug>
#include <QtQml>

class Calculator : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Calculator(QObject *parent = nullptr);

public slots:
    void numberPressed();
private:

signals:
    //double resultEmitted();
};

#endif // CALCULATOR_H
