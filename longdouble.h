#ifndef LONGDOUBLE_H
#define LONGDOUBLE_H

#include <iostream>
#include <string>
#include <vector>
#include <QObject>

#define DIV_DIGITS 1000

using namespace std;

class LongDouble {

private:
    int sign;
    vector<int> digits;
    long exponent;
    void removeZeroes();

public:
    LongDouble();
    LongDouble(const LongDouble& x);
    LongDouble(const string &value);
    LongDouble inverse() const;
    QString toString() const;
    LongDouble operator*(const LongDouble& x) const;
    LongDouble operator-() const;
    bool operator>(const LongDouble& x) const;
    bool operator<(const LongDouble& x) const;
    LongDouble operator+(const LongDouble& x) const;
    bool operator==(const LongDouble& x) const;
    bool operator!=(const LongDouble& x) const;
    bool operator>=(const LongDouble& x) const;
    bool operator<=(const LongDouble& x) const;
    LongDouble operator-(const LongDouble& x) const;
    LongDouble operator/(const LongDouble& x) const;
    inline LongDouble &operator=(const LongDouble &x);
    void reset();
};

#endif // LONGDOUBLE_H
