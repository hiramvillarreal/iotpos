/**************************************************************************
*   Copyright © 2007-2011 by Miguel Chavez Gamboa                         *
*   miguel@lemonpos.org                                                   *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
**************************************************************************/

#ifndef MYSTRUCTS_H
#define MYSTRUCTS_H

#include <QString>
#include <QByteArray>
#include <QPixmap>
#include <QDateTime>
#include <QDate>
#include <QHash>

struct ProductInfo {
  qulonglong code;
  QString desc;
  double price;
  double disc;
  double discpercentage;
  bool   validDiscount;
  double cost;
  double tax;
  double extratax;
  double totaltax;//in money...
  QByteArray photo;
  double stockqty;
  int units;
  QString unitStr;
  int department;
  int category;
  int subcategory;
  double utility;
  int row; // New: Sept 30, 2007: To store the row where the product is located in the listView.
  qulonglong points; //New: Dec 15 2007: To store the points the product gives.
  double qtyOnList;
  double purchaseQty; //New: Jan 13 2007: For purchase editor...
  qulonglong lastProviderId;
  QString alphaCode;
  QString vendorCode; // ben branch
  double soldUnits; // mch 21Nov09 FOR PRINTED REPORT - LOW STOCK
  // for grouped products and special orders
  bool isAGroup;
  bool isARawProduct;
  QString groupElementsStr;
  double groupPriceDrop;
  //for later use:
  qulonglong taxmodelid;
  QString taxElements;
  //aug 11 2011, for 0.9.4.rc9
  bool hasUnlimitedStock;
  bool isNotDiscountable;
};

struct UserInfo
{
  unsigned int id;
  QString username;
  QString password;
  QString salt;
  QString name;
  QString address;
  QString cell;
  QString phone;
  QByteArray photo;
  int role;
};

struct ClientInfo
{
  unsigned int id;
  QString      code;
  QString      name;
  QString      address;
  QString      phone;
  QString      cell;
  qulonglong   points;
  double discount;
  QByteArray   photo;
  QDate        since;
};

struct OfferInfo
{
  qulonglong productCode;
  double     discount;
  QDate      dateStart;
  QDate      dateEnd;
};

struct TransactionInfo
{
  qulonglong id;
  int        type;
  double     amount;
  QDate      date;
  QTime      time;
  double     paywith;
  double     changegiven;
  int        paymethod;
  int        state;
  qulonglong userid;
  qulonglong clientid;
  QString    cardnumber;
  QString    cardauthnum;
  QString    cardTypeStr;
  int        cardType;
  int        itemcount;
  QString    itemlist;
  double     disc;
  double     discmoney;
  qulonglong points;
  double     utility;
  int        terminalnum;
  //QString    groups;  //DEPRECATED
  QString    specialOrders;
  qulonglong providerid;
  qulonglong balanceId; //to store balance where it was sold. For SESSIONS.
  double     totalTax; //in money.
};

struct BalanceInfo
{
  qulonglong id;
  QDateTime  dateTimeStart;
  QDateTime  dateTimeEnd;
  qulonglong userid;
  QString    username;
  double     initamount;
  double     in;
  double     out;
  double     cash;
  double     card;
  QString    transactions;
  int        terminal;
  QString    cashflows;//28DIC09
  bool       done;
};

struct PrintBalanceInfo
{
  QString     thBalanceId;
  QString     storeName;
  QString     storeAddr;
  QString     thTitle;
  QString     thDeposit;
  QString     thIn;
  QString     thOut;
  QString     thInDrawer;
  QString     thTitleDetails;
  QString     thTitleCFDetails;
  QString     thTrId;
  QString     thTrTime;
  QString     thTrAmount;
  QString     thTrPaidW;
  QString     thTrPayMethod;
  QPixmap     storeLogo;
  QString     startDate;
  QString     endDate;
  // qtys as string - local aware / translated
  QString     initAmount;
  QString     inAmount;
  QString     outAmount;
  QString     cashAvailable;
  bool        logoOnTop;
  QString     thCFType;
  QString     thCFReason;
  QString     thCFDate;
  QStringList trList;
  QStringList cfList;
  QString     reservationNote;
  QString     notCashNote;
};

struct pieProdInfo
{
  double count;
  QString name;
  QString unitStr;
  qulonglong code;
};

struct ProfitRange
{
  double min;
  double max;
};

struct TicketLineInfo {
  double qty;
  QString unitStr;
  QString desc;
  double price;
  double disc;
  double partialDisc;
  double total;
  double gtotal;
  QString geForPrint;
  bool   completePayment;
  bool   isGroup;
  double payment;
  QDateTime  deliveryDateTime;
  double tax; //total tax in Percentage.
};

struct TicketInfo {
  qulonglong number;
  double total; //this is the total amount of THIS TICKET.
  double change;
  double paidwith;
  int itemcount;
  QString cardnum;
  QString cardAuthNum;
  bool paidWithCard;
  double clientDisc;
  double clientDiscMoney;
  qulonglong buyPoints;
  qulonglong clientPoints;
  qulonglong clientid; // 14 Abril 08
  QList<TicketLineInfo> lines;
  QDateTime datetime;
  bool hasSpecialOrders;
  bool completingSpecialOrder;
  double totalTax;
  QDateTime deliveryDT;
  double soTotal; //this is the total for the SO (nextpayment + prepayment)
  QString subTotal;
  QString terminal;
  //for reservations:
  bool isAReservation;
  bool reservationStarted;
  double reservationPayment;
  double purchaseTotal;
  qulonglong reservationId;
};

struct PrintTicketInfo {
  QString    storeName;
  QString    storeAddr;
  QString    storePhone;
  QString    ticketMsg;
  QPixmap    storeLogo;
  QString    salesPerson;
  QString    terminal;
  QString    thPhone;
  QString    thDate;
  QString    thProduct;
  QString    thQty;
  QString    thPrice;
  QString    thTotal;
  QString    thTotals;
  QString    thDiscount;
  QString    thArticles;
  QString    thPoints;
  QString    thTicket;
  QString    thPaid;
  QString    thChange;
  QString    tDisc;
  QString    thCard;
  QString    thCardAuth;
  double     totDisc;
  TicketInfo ticketInfo;
  bool       logoOnTop;
  QString    paymentStrComplete;
  QString    paymentStrPrePayment;
  QString    nextPaymentStr;
  QString    lastPaymentStr;
  QString    deliveryDateStr;
  QString    clientDiscountStr;
  double     clientDiscMoney;
  QString    randomMsg;
  QString    thChangeStr;
  QString    taxes;
  QString    thTax;
  QString    thTendered;
  QString    thSubtotal;
  QString    subtotal;
  QString    resTotalAmountStr;
  QString    hdrReservation;
};

//TODO: add grouped products and special orders
//      is it convenient? in case a pack of 6 water botles is not convenient, but a combo "My burger package"
//      consisting of one burger, one soda and one fried potatoes.
struct TransactionItemInfo
{
  qulonglong transactionid;
  int        position;
  qulonglong productCode;
  double     qty;
  double     points;
  QString    unitStr;
  double     cost;
  double     price;
  double     disc;
  double     total;
  QString    name;
  //for special orders, also productCode will be 0 for special orders
  QString    soId;
  double     payment;
  bool       completePayment;
  bool       isGroup;
  QDateTime  deliveryDateTime;
  double     tax; // total tax in percentage.
};


struct CashFlowInfo
{
  qulonglong id;
  int type;
  qulonglong userid;
  double amount;
  QString reason;
  QDate date;
  QTime time;
  qulonglong terminalNum;
  //next are for cashflow into balance printing
  QString typeStr;
};

struct AmountAndProfitInfo
{
    double amount;
    double profit;
};

struct PrintEndOfDayInfo
{
  QString    storeName;
  QString    storeAddr;
  QPixmap    storeLogo;
  QString    salesPerson;
  QString    terminal;
  QString    thTitle;
  QString    thDate;
  QString    thTime;
  QString    thTicket;
  QString    thAmount;
  QString    thProfit;
  QString    thPayMethod;
  QString    thTotalSales;
  QString    thTotalProfit;
  QString    thTotalTaxes;
  QStringList trLines;
  bool       logoOnTop;
};

struct PrintLowStockInfo
{
  QString    storeName;
  QString    storeAddr;
  QPixmap    storeLogo;
  QString    hTitle;
  QString    hDate; //and time
  QString    hDesc;
  QString    hCode;
  QString    hQty;
  QString    hUnitStr;
  QString    hSoldU;
  QStringList pLines;
  bool       logoOnTop;
};

struct SpecialOrderInfo
{
  qulonglong orderid;
  qulonglong saleid;
  QString    name;
  double     qty;
  double     price;
  double     cost;
  int        status;
  int        units;
  QString    unitStr;
  QString    groupElements;
  QString    notes;
  int        insertedAtRow;
  QString    geForPrint;
  double     payment; //anticipos
  bool       completePayment;
  QDateTime  dateTime;
  qulonglong completedOnTrNum;
  QDateTime  deliveryDateTime;
  qulonglong userId;
  qulonglong clientId;
  double     averageTax;
  double     disc;
};

struct GroupInfo
{
  QString name;
  double  cost;
  double  price;
  double  taxMoney;
  double  tax;
  double  priceDrop;
  double  count; // total of items in the group
  bool    isAvailable; //based on stockqty for each product (and its qtys).
  QHash<qulonglong, ProductInfo> productsList;
};

struct CurrencyInfo
{
    qulonglong id;
    QString name;
    double  factor;
};

struct ReservationInfo
{
    qulonglong id;
    qulonglong transaction_id;
    qulonglong client_id;
    QDate      date;
    double     payment;
    double     total;
    double     totalTaxes;
    double     profit;
    int        status;
    double     discount;
    QString    item_discounts;
};

struct ReservationPayment
{
    qulonglong id;
    qulonglong reservation_id;
    double     amount;
    QDate      date;
};

struct CreditInfo
{
    qulonglong id;
    qulonglong clientId;
    double     total;
};

struct CreditHistoryInfo
{
    qulonglong id;
    qulonglong customerId;
    qulonglong saleId;
    QDate      date;
    QTime      time;
    double     amount;
};

struct RoundingInfo
{
    QString strResult;
    double  doubleResult;
    int     intDecPart;
    int     intIntPart;
};

struct FoliosPool
{
    QDate   fechaAprobacion; //FIXME: Es Fecha o Fecha Y HORA ???
    QString numAprobacion; //El número de aprobación del folio asignado por SICOFI. Este es el primary key.
    QByteArray cbb;
    QString folioInicial; // 'A101', incluye la serie (A,B,C...)
    QString folioFinal;   // 'A200'
    int     cantidadFolios;
};

//NOTE:Tomar en cuenta 'race conditions'. Si dos terminales piden un folio al mismo tiempo, podrian tener el mismo numero ambos, siendo que esta 'usado=false'
//     Para solucionar esto, en el mismo momento de pedir un folio, se marca como usado. (como en un stack, se retira.)
//     Un problema es que no se puede regresar al stack con 'usado=false', porque entonces se podrian estar usando folios no consecutivos.
//     ejemplo: Hoy dos terminales compiten por un folio, una obtiene el A101, otra el A102. La del A101 cancela y se regresa A101 con usado=false.
//              Al dia siguiente, se pide un folio libre, y A102 se devuelve. Entonces A101 se factura con una fecha POSTERIOR a la de A102. Este
//              seria un problema ante hacienda porque A101 es de una fecha posterior a A102 y no deberia de ser.
struct FolioInfo
{
    QString poolId; //al pool que pertenece (La serie de folios pedidos al sat)
    QString    numero; // Este es la primary key de la tabla, asi no se permiten duplicados.
    bool       usado; //indica si el folio ya fue usado o esta libre para ser usado.
    bool       valido; //indica si el folio es valido o cancelado.
    QByteArray cbb;
};

struct FacturaCBB
{
    QDate   fecha;
    QString folio; //este es el primary key
    QString authFolios;
    QDate   fechaAutFolios;
    QByteArray cbb; //QR Code, PNG.  NOTE: Podia ser un apuntador a otra tabla, ya que una serie de folios comparten CBB.
    bool    valida; //Para cancelar facturas.
    QString nombreCliente;
    QString RFCCliente;
    QString direccionCliente;
    QList<TicketLineInfo> lineas;
    qulonglong trId;
    double  subTotal; // Sin Impuestos, sin descuentos.
    double  descuentos;
    double  impuestos; // IVA... alguno mas ?
    double  impuestosTasa; // impuestos en %
    double  total; // Incluyendo iva, y descuentos.
    ///not stored on db:
    QString totalLetra;
    QString storeName;
    QString storeRFC;
    QString storeRegimen;
    QString storeAddr;
    QString storeLugar;
    QString storePhone;
    QPixmap storeLogo;
};

//TODO: Operaciones relacionadas con facturas:
//      Cancelacion
//      Notas de Credito (No necesario sobre una factura) [Ver si esto requiere FOLIO del SAT]
//      Pagos a una factura, saldo sobre la factura.  Relacion entre factura->Credito->Abono

struct BundleInfo
{
    qulonglong product_id;
    double     price;
    double     qty;
};

#endif
