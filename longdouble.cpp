#include "longdouble.h"


LongDouble::LongDouble() {
    sign = 1;
    digits = vector<int>(1, 0);
    exponent = 1;
}


LongDouble::LongDouble(const LongDouble& x) {
    sign = x.sign;
    exponent = x.exponent;
    digits = vector<int>(x.digits);
}


LongDouble::LongDouble(const string& value){
    size_t index = 0;

    if (value[0] == '-') {
        sign = -1;
        index = 1;
    } else {
        sign = 1;
        index = 0;
    }

    exponent = value.length() - index;

    while (index < value.length()) {
        if (value[index] == '.')
            exponent = sign == 1 ? index : index - 1;
        else
            digits.push_back(value[index] - '0');

        index++;
    }
    removeZeroes();
}

void LongDouble::removeZeroes() {
    size_t n = max((long) 1, exponent);

    while (digits.size() > n && digits[digits.size() - 1] == 0)
        digits.erase(digits.end() - 1);

    while (digits.size() > 1 && digits[0] == 0) {
        digits.erase(digits.begin());
        exponent--;
    }

    while (digits.size() > 1 && digits[digits.size() - 1] == 0)
        digits.erase(digits.end() - 1);

    if (digits.size() == 1 && digits[0] == 0) {
        exponent = 1;
        sign = 1;
    }
}

LongDouble LongDouble::operator*(const LongDouble& x) const {
    size_t len = digits.size() + x.digits.size();

    LongDouble res;

    res.sign = sign * x.sign;
    res.digits = vector<int>(len, 0);
    res.exponent = exponent + x.exponent;

    for (size_t i = 0; i < digits.size(); i++)
        for (size_t j = 0; j < x.digits.size(); j++)
            res.digits[i + j + 1] += digits[i] * x.digits[j];

    for (size_t i = len - 1; i > 0; i--) {
        res.digits[i - 1] += res.digits[i] / 10;
        res.digits[i] %= 10;
    }

    res.removeZeroes();
    return res;
}


LongDouble LongDouble::operator-() const {
    LongDouble res;
    res.sign = -sign;
    res.exponent = exponent;
    res.digits = vector<int>(digits);

    return res;
}


bool LongDouble::operator>(const LongDouble& x) const {
    if (sign != x.sign)
        return sign > x.sign;

    if (exponent != x.exponent)
        return (exponent > x.exponent) ^ (sign == -1);

    vector<int> d1(digits);
    vector<int> d2(x.digits);
    size_t size = max(d1.size(), d2.size());

    while (d1.size() != size)
        d1.push_back(0);

    while (d2.size() != size)
        d2.push_back(0);

    for (size_t i = 0; i < size; i++)
        if (d1[i] != d2[i])
            return (d1[i] > d2[i]) ^ (sign == -1);

    return false;
}

LongDouble LongDouble::operator+(const LongDouble& x) const {
    if (sign == x.sign) {
        long exp1 = exponent;
        long exp2 = x.exponent;
        long exp = max(exp1, exp2);

        vector<int> d1(digits);
        vector<int> d2(x.digits);

        while (exp1 != exp) {
            d1.insert(d1.begin(), 0);
            exp1++;
        }

        while (exp2 != exp) {
            d2.insert(d2.begin(), 0);
            exp2++;
        }

        size_t size = max(d1.size(), d2.size());

        while (d1.size() != size)
            d1.push_back(0);

        while (d2.size() != size)
            d2.push_back(0);

        size_t len = 1 + size;

        LongDouble res;

        res.sign = sign;
        res.digits = vector<int>(len, 0);

        for (size_t i = 0; i < size; i++)
            res.digits[i + 1] = d1[i] + d2[i];

        for (size_t i = len - 1; i > 0; i--) {
            res.digits[i - 1] += res.digits[i] / 10;
            res.digits[i] %= 10;
        }

        res.exponent = exp + 1;
        res.removeZeroes();

        return res;
    }

    if (sign == -1)
        return x - (-(*this));

    return *this - (-x);
}

bool LongDouble::operator==(const LongDouble &x) const
{
    return (sign == x.sign && exponent == exponent && digits == x.digits);
}

bool LongDouble::operator!=(const LongDouble &x) const
{
    return !(*this == x);
}

bool LongDouble::operator>=(const LongDouble &x) const
{
    return (*this == x || *this > x);
}

bool LongDouble::operator<=(const LongDouble &x) const
{
    return (*this == x || *this < x);
}

LongDouble LongDouble::operator-(const LongDouble& x) const {
    if (sign == 1 && x.sign == 1) {
        bool cmp = *this > x;

        long exp1 = cmp ? exponent : x.exponent;
        long exp2 = cmp ? x.exponent : exponent;
        long exp = max(exp1, exp2);

        vector<int> d1(cmp ? digits : x.digits);
        vector<int> d2(cmp ? x.digits : digits);

        while (exp1 != exp) {
            d1.insert(d1.begin(), 0);
            exp1++;
        }

        while (exp2 != exp) {
            d2.insert(d2.begin(), 0);
            exp2++;
        }

        size_t size = max(d1.size(), d2.size());

        while (d1.size() != size)
            d1.push_back(0);

        while (d2.size() != size)
            d2.push_back(0);

        size_t len = 1 + size;

        LongDouble res;

        res.sign = cmp ? 1 : -1;
        res.digits = vector<int>(len, 0);

        for (size_t i = 0; i < size; i++)
            res.digits[i + 1] = d1[i] - d2[i];

        for (size_t i = len - 1; i > 0; i--) {
            if (res.digits[i] < 0) {
                res.digits[i] += 10;
                res.digits[i - 1]--;
            }
        }

        res.exponent = exp + 1;
        res.removeZeroes();

        return res;
    }

    if (sign == -1 && x.sign == -1)
        return (-x) - (-(*this));

    return *this + (-x);
}

bool LongDouble::operator<(const LongDouble& x) const {
    return !(*this > x);
}

LongDouble LongDouble::inverse() const {
    if (digits.size() == 1 && digits[0] == 0)
        throw string("LongDouble LongDouble::inverse() - division by zero!");

    LongDouble x(*this);
    x.sign = 1;

    LongDouble d("1");

    LongDouble res;
    res.sign = sign;
    res.exponent = 1;
    res.digits = vector<int>();

    while (x < LongDouble("1")) {
        x.exponent++;
        res.exponent++;
    }

    while (d < x)
        d.exponent++;

    res.exponent -= d.exponent - 1;

    size_t numbers = 0;
    size_t totalNumbers = DIV_DIGITS + max((long) 0, res.exponent);

    do {
        int div = 0;

        while (d >= x) {
            div++;
            d = d - x;
        }

        d.exponent++;
        d.removeZeroes();
        res.digits.push_back(div);
        numbers++;
    } while (d != LongDouble("0") && numbers < totalNumbers);

    return res;
}

QString LongDouble::toString() const
{
    QString str = "";
    if (this->sign == -1)
        str += '-';

    if (this->exponent > 0) {
        size_t i = 0;
        size_t e = this->exponent;

        while(i < this->digits.size() && i < e)
            str += QString::number(this->digits[i++]);

        while (i < e) {
            str += '0';
            i++;
        }

        if (i < this->digits.size()) {
            str += '.';

            while(i < this->digits.size())
                str += QString::number(this->digits[i++]);
        }
    }
    else {
        str += QString::fromStdString("0.");

        for (long i = 0; i < -this->exponent; i++)
            str += '0';

        for (size_t i = 0; i < this->digits.size(); i++)
            str += QString::number(this->digits[i]);
    }

    return str;
}

LongDouble LongDouble::operator/(const LongDouble& x) const {
    LongDouble res = *this * x.inverse();

    size_t i = res.digits.size() - 1 - max((long)0, exponent);
    size_t n = max((long) 0, res.exponent);

    if (i > n && res.digits[i] == 9) {
        while (i > n && res.digits[i] == 9)
            i--;

        if (res.digits[i] == 9) {
            res.digits.erase(res.digits.begin() + n, res.digits.end());
            res = res + LongDouble(std::to_string(1 * res.sign));
        }
        else {
            res.digits.erase(res.digits.begin() + i + 1, res.digits.end());
            res.digits[i]++;
        }
    }

    return res;
}

inline LongDouble &LongDouble::operator=(const LongDouble &x)
{
    sign = x.sign;
    digits = x.digits;
    exponent = x.exponent;
    return *this;
}

void LongDouble::reset()
{
    sign = 1;
    digits = vector<int>(1, 0);
    exponent = 1;
}

