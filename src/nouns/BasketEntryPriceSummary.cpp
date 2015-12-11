#include "BasketEntryPriceSummary.h"
#include <QTextStream>

BasketEntryPriceSummary::BasketEntryPriceSummary(double net, double gross, double tax, double discountGross, qulonglong points) {
    this->net = Currency(net);
    this->gross = Currency(gross);
    this->tax = Currency(tax);
    this->discountGross = Currency(discountGross);
    this->points = points;
}

BasketEntryPriceSummary::BasketEntryPriceSummary(Currency net, Currency gross, Currency tax, Currency discountGross, qulonglong points) {
    this->net = net;
    this->gross = gross;
    this->tax = tax;
    this->discountGross = discountGross;
    this->points = points;
}

BasketEntryPriceSummary::~BasketEntryPriceSummary() {
}

QString BasketEntryPriceSummary::toString() {
    QString result;
    QTextStream out(&result);
    out.setRealNumberPrecision(2);
    out.setRealNumberNotation(QTextStream::FixedNotation);
    out.setFieldWidth(10);
    out.setFieldAlignment(QTextStream::AlignLeft);

    QString points = QString::number(this->points);
    out << "net" << net << "gross" << gross << "tax" << tax << "discount" << discountGross << "points" << points;
    return result;
}

Currency BasketEntryPriceSummary::getNet() {
    return this->net;
}

Currency BasketEntryPriceSummary::getGross() {
    return this->gross;
}

Currency BasketEntryPriceSummary::getTax() {
    return this->tax;
}

Currency BasketEntryPriceSummary::getDiscountGross() {
    return this->discountGross;
}

qulonglong BasketEntryPriceSummary::getPoints() {
    return this->points;
}
