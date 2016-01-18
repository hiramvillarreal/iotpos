//
// Created by krzysiek on 15.04.15.
//

#ifndef IOTPOS_BASKETPRICESUMMARY_H
#define IOTPOS_BASKETPRICESUMMARY_H

#include "BasketEntryPriceSummary.h"

class BasketPriceSummary {
private:
    Currency net;
    Currency gross;
    Currency tax;
    Currency discountGross;
    qulonglong points;

public:
    BasketPriceSummary();
    BasketPriceSummary(Currency net, Currency gross, Currency tax, Currency discountGross, qulonglong points);
    virtual ~BasketPriceSummary();
    QString toString();

    void add(BasketEntryPriceSummary basketEntryPriceSummary);
public: //getters
    Currency getNet();
    Currency getGross();
    Currency getTax();
    Currency getDiscountGross();
    qulonglong getPoints();
};


#endif //IOTPOS_BASKETPRICESUMMARY_H
