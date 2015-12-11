#include "BasketPriceCalculationService.h"
#include "settings.h"

double BasketPriceCalculationService::calculateEntryDiscount(ProductInfo & prod, ClientInfo & client, bool forceGross) {
    bool pricesAreGross = !Settings::addTax(); //just a better name to understant what to do.
    double entryTotal = prod.qtyOnList * prod.price;
    double entryDiscount = 0.0;

    // Product discount. validDiscount==true -> use absolute; validDiscount==false -> use percentage
    if (prod.validDiscount) {
        entryDiscount += prod.qtyOnList * prod.disc;
    }
    else {
        entryDiscount += (prod.discpercentage * entryTotal) / 100;
    }


    if (!Settings::firstDiscountOnly() || entryDiscount <= 0) {
        // Client discount
        if (!prod.isNotDiscountable && client.discount >= 0) {
            entryDiscount += (client.discount * entryTotal) / 100;
        }
    }
    else {
        qDebug() << "firstDiscountOnly was set and product is already discounted\n";
    }

    if (!pricesAreGross && forceGross) {
        double taxFactor = (prod.tax + prod.extratax) / 100;
        if (taxFactor > 0) {
            entryDiscount *= (1.0 + taxFactor);
        }
    }

    return entryDiscount;
}

BasketEntryPriceSummary BasketPriceCalculationService::calculateBasketEntry(ProductInfo & prod, ClientInfo & client, bool applyDiscounts) {
    bool pricesAreGross = !Settings::addTax(); //just a better name to understant what to do.

    Currency entryTotal(prod.qtyOnList * prod.price);

    Currency entryDiscount(applyDiscounts ? this->calculateEntryDiscount(prod, client, pricesAreGross) : 0.0);
    Currency entryDiscountGross(applyDiscounts ? this->calculateEntryDiscount(prod, client, true) : 0.0);

    Currency entryBasePrice(entryTotal);
    entryBasePrice.substract(entryDiscount);


    double taxFactor = (prod.tax + prod.extratax) / 100;
    Currency entryTax;
    Currency entryNetPrice;
    Currency entryGrossPrice;

    if (pricesAreGross) {
        entryNetPrice.set(entryBasePrice);
        entryNetPrice.divide(1 + taxFactor);

        entryGrossPrice.set(entryBasePrice);

        entryTax.set(entryBasePrice);
        entryTax.substract(entryNetPrice);
    }
    else {
        entryNetPrice.set(entryBasePrice);

        entryTax.set(entryBasePrice);
        entryTax.multiply(taxFactor);

        entryGrossPrice.set(entryNetPrice);
        entryGrossPrice.add(entryTax);
    }


    BasketEntryPriceSummary result(entryNetPrice, entryGrossPrice, entryTax, entryDiscountGross, prod.points * prod.qtyOnList);
    return result;
}

BasketPriceSummary BasketPriceCalculationService::calculateBasketPrice(QHash<qulonglong, ProductInfo> & products, ClientInfo & client, double salesmanDiscount)
{
    BasketPriceSummary basketPriceSummary;

    bool useSalesmanDiscount = client.discount == 0 && salesmanDiscount > 0;

    foreach (ProductInfo prod, products) {
        BasketEntryPriceSummary basketEntryPriceSummary = this->calculateBasketEntry(prod, client, !useSalesmanDiscount);
        basketPriceSummary.add(basketEntryPriceSummary);
    }

    if (useSalesmanDiscount) {
        // apply absolut discount
        double factor = salesmanDiscount / basketPriceSummary.getGross().toDouble();
        BasketPriceSummary salesmanDiscountedBasketPriceSummary(basketPriceSummary.getNet().toDouble() * factor, basketPriceSummary.getGross().toDouble() * factor, basketPriceSummary.getTax().toDouble() * factor, salesmanDiscount, basketPriceSummary.getPoints());
        return salesmanDiscountedBasketPriceSummary;
    }

    return basketPriceSummary;
}
