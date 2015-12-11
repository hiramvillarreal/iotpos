#ifndef LEMON_BASKETPRICECALCULATIONSERVICE_H
#define LEMON_BASKETPRICECALCULATIONSERVICE_H

#include <QHash>

#include "nouns/BasketPriceSummary.h"
#include "nouns/User.h"
#include "structs.h"

class BasketPriceCalculationService {
public:
    BasketPriceSummary calculateBasketPrice(QHash<qulonglong, ProductInfo> & products, ClientInfo & client, double salesmanDiscount);
private:
    double calculateEntryDiscount(ProductInfo & prod, ClientInfo & client, bool forceGross);
    BasketEntryPriceSummary calculateBasketEntry(ProductInfo & prod, ClientInfo & client, bool applyDiscounts);
};


#endif //LEMON_BASKETPRICECALCULATIONSERVICE_H
