#include "Currency.h"
#include <QTextStream>

Currency::Currency()
{
    this->amount = 0;
}

Currency::Currency(double amount)
{
    this->amount = amount * 100.0 + 0.5;
}

Currency::~Currency()
{
}

void Currency::set(Currency newValue)
{
    this->amount = newValue.amount;
}

void Currency::set(double newValue)
{
    this->amount = newValue * 100.0 + 0.5;
}


void Currency::substract(Currency currency)
{
    this->amount -= currency.amount;
}

void Currency::add(Currency currency)
{
    this->amount += currency.amount;
}

void Currency::multiply(double multiplier)
{
    this->amount = this->amount * multiplier + 0.5;
}

void Currency::divide(double divider)
{
    this->amount = this->amount / divider + 0.5;
}

double Currency::toDouble() const {
    double result = this->amount / 100.0;
    return result;
}

QString Currency::toString() const {
    QString result;
    QTextStream out(&result);
    out.setRealNumberPrecision(2);
    out.setRealNumberNotation(QTextStream::FixedNotation);
    out << this->toDouble();
    return result;
}


QTextStream& operator<<(QTextStream& os, const Currency& obj) {
    os << obj.toString();
    return os;
}

QDebug& operator<<(QDebug& os, const Currency& obj) {
    os << obj.toString();
    return os;
}
