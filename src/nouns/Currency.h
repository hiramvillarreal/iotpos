#ifndef CURRENCY_H
#define CURRENCY_H

#include <QString>
#include <QTextStream>
#include <QDebug>

/**
 * @brief The Currency class
 * Objects of this class are mutable. Methods such as add, substract, multiply, divide are modifying
 * current object and returning "this" pointer to make it possible to chain calls.
 */
class Currency
{
private:
    long amount;

public:
    Currency();
    Currency(double amount);
    virtual ~Currency();

    void set(Currency newValue);
    void set(double newValue);

    void substract(Currency currency);
    void add(Currency currency);
    void multiply(double multiplier);
    void divide(double divider);

    double toDouble() const;
    QString toString() const;
};

QTextStream& operator<<(QTextStream& os, const Currency& obj);
QDebug& operator<<(QDebug& os, const Currency& obj);

#endif // CURRENCY_H
