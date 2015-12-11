#ifndef BASKETENTRYPRICESUMMARY_H
#define BASKETENTRYPRICESUMMARY_H

#include <QString>
#include <QtGlobal>
#include "Currency.h"

class BasketEntryPriceSummary {
private:
    Currency net;
    Currency gross;
    Currency tax;
    Currency discountGross;
    qulonglong points;

public:
    BasketEntryPriceSummary(double net, double gross, double tax, double discountGross, qulonglong points);
    BasketEntryPriceSummary(Currency net, Currency gross, Currency tax, Currency discountGross, qulonglong points);
    virtual ~BasketEntryPriceSummary();
    QString toString();

public: //getters
    Currency getNet();
    Currency getGross();
    Currency getTax();
    Currency getDiscountGross();
    qulonglong getPoints();
};

#endif // BASKETENTRYPRICESUMMARY_H
