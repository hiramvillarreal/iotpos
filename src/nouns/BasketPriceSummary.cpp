//
// Created by krzysiek on 15.04.15.
//

#include "BasketPriceSummary.h"
#include <QDebug>

BasketPriceSummary::BasketPriceSummary() {
}

BasketPriceSummary::BasketPriceSummary(Currency net, Currency gross, Currency tax, Currency discountGross, qulonglong points) {
    this->net = net;
    this->gross = gross;
    this->tax = tax;
    this->discountGross = discountGross;
    this->points = points;
}

QString BasketPriceSummary::toString() {
    QString result;
    QTextStream out(&result);
    out.setRealNumberPrecision(2);
    out.setRealNumberNotation(QTextStream::FixedNotation);
    out.setFieldWidth(10);
    out.setFieldAlignment(QTextStream::AlignLeft);
    out << "net" << net << "gross" << gross << "tax" << tax << "discount" << discountGross << "points" << points;
    return result;
}


void BasketPriceSummary::add(BasketEntryPriceSummary basketEntryPriceSummary) {
    QString before = this->toString();

    net.add(basketEntryPriceSummary.getNet());
    gross.add(basketEntryPriceSummary.getGross());
    tax.add(basketEntryPriceSummary.getTax());
    discountGross.add(basketEntryPriceSummary.getDiscountGross());
    points += basketEntryPriceSummary.getPoints();

    qDebug() << "!!! Adding:  " << basketEntryPriceSummary.toString() << "\nto:          " << before << "\nthat gives:  " << this->toString();
}

BasketPriceSummary::~BasketPriceSummary() {
}

Currency BasketPriceSummary::getNet() {
    return this->net;
}

Currency BasketPriceSummary::getGross() {
    return this->gross;
}

Currency BasketPriceSummary::getTax() {
    return this->tax;
}

Currency BasketPriceSummary::getDiscountGross() {
    return this->discountGross;
}

qulonglong BasketPriceSummary::getPoints() {
    return this->points;
}
