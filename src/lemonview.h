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
 ***************************************************************************/

#ifndef LEMONVIEW_H
#define LEMONVIEW_H

class QStringList;
class QTableWidgetItem;
class LoginWindow;
class MibitTip;
class MibitPasswordDialog;
class MibitFloatPanel;
class MibitNotifier;

#include <qwidget.h>
#include <QList>
#include <QtSql>

#include "enums.h"
#include "gaveta.h"
#include "loginwindow.h"
#include "ui_mainview.h"
#include "bundlelist.h"

#include "nouns/BasketPriceSummary.h"

/**
 * This is the main view class for lemon.  Most of the non-menu,
 * non-toolbar, and non-statusbar (e.g., non frame) GUI code should go
 * here.
 *
 * @short Main view
 * @author Miguel Chavez Gamboa <miguel.chavez.gamboa@gmail.com>
 * @version 2007.11
 */
class lemonView : public QWidget, public Ui::mainview
{
    Q_OBJECT
public:
    lemonView();

    virtual ~lemonView();

    QString getLoggedUser();
    QString getLoggedUserName(QString id);
    qulonglong getLoggedUserId(QString uname); //BUG FIXED on nov82009: it was unsigned int...
    int getUserRole(qulonglong id);
    int getLoggedUserRole() { return loggedUserRole; }
    QString getCurrentTransactionString();
    qulonglong     getCurrentTransaction();
    QList<int> getTheSplitterSizes();
    QList<int> getTheGridSplitterSizes();
    int rmSeason;
    QList<qulonglong> rmExcluded;

    void setTheSplitterSizes(QList<int> s);
    void setTheGridSplitterSizes(QList<int> s);
    bool isTransactionInProgress() { return transactionInProgress;}
    void cancelByExit();
    bool canStartSelling() {return operationStarted;}
    bool validAdminUser();
    void corteDeCaja(); //to allow lemon class to doit

    QWidget *frameLeft, *frame;
  private:
    Ui::mainview ui_mainview;
    QString loggedUser;
    QString loggedUserName;
    int     loggedUserRole;
    qulonglong loggedUserId;
    qulonglong currentTransaction;
    qulonglong currentBalanceId;
    double  totalSum;
    double  totalTax; // in money.
    Gaveta *drawer;
    bool   drawerCreated;
    bool   modelsCreated;
    bool   operationStarted;
    bool   transactionInProgress;
    QSqlDatabase db;
    LoginWindow *dlgLogin;
    LoginWindow *dlgPassword;
    QHash<qulonglong, ProductInfo> productsHash;
    QSqlTableModel *productsModel;
    QSqlQueryModel *clientsModel; //for the credits panel, completer.
    QHash<QString, int> categoriesHash;
    QHash<QString, int> subcategoriesHash;
    ClientInfo clientInfo;
    QHash<QString, ClientInfo> clientsHash;
    qulonglong buyPoints;
    double discMoney;
    double globalDiscount; //%
    double totalSumWODisc;
    double subTotalSum;
    double reservationPayment;
    QDateTime transDateTime;
    double lastDiscount;
    bool completingOrder;

    bool availabilityDoesNotMatters;
    bool doNotAddMoreItems;
    bool finishingReservation;
    bool startingReservation;
    qulonglong reservationId;

    QHash<qulonglong, SpecialOrderInfo> specialOrders;
    
    QSqlRelationalTableModel *historyTicketsModel;

    MibitTip *tipCode, *tipAmount;
    MibitPasswordDialog *lockDialog;
    MibitFloatPanel *currencyPanel;
    MibitFloatPanel *discountPanel;
    MibitFloatPanel *creditPanel;
    MibitNotifier *notifierPanel;

    double oDiscountMoney;
    double gTaxPercentage;

    ClientInfo crClientInfo;
    CreditInfo crInfo;

    QDoubleValidator *valPercentage;
    QDoubleValidator *valMoney;
    
    //QMultiHash<qulonglong, BundleInfo> bundlesHash;
    BundleList *bundlesHash;

    void loadIcons();
    void setUpInputs();
    void setupModel();
    void setupClientsModel();

    RoundingInfo roundUsStandard(const double &number);

    BasketPriceSummary recalculateBasket(double oDiscountMoney);

  signals:
    /**
   * Use this signal to change the content of the statusbar
     */
    void signalChangeStatusbar(const QString& text);

    /**
     * Use this signal to change the content of the caption
     */
    void signalChangeCaption(const QString& text);
    /**
     * Use this signal to inform that the administrator has logged on.
     **/
    void signalAdminLoggedOn();
    void signalSupervisorLoggedOn();
    /**
     * Use this signal to inform that the administrator has logged off.
     **/
    void signalAdminLoggedOff();
    void signalSupervisorLoggedOff();
    /**
     * Use this signal to inform that no user has logged on.
     **/
    void signalNoLoggedUser();
    /**
     * Use this signal to inform that an user has logged on (!=admin).
     **/
    void signalLoggedUser();
    /**
     * Use this signal to update the clock on the statusbar
     */
    void signalUpdateClock();

    void signalQueryDb(QString code);
    /**
     * Signal used to update transaction number
     */
    void signalUpdateTransactionInfo();
    /**
     * Signal used to inform the start of operation.
     */
    void signalStartedOperation();

    void signalShowProdGrid();

    void signalShowDbConfig();

    void signalEnableUI();
    void signalDisableUI();
    void signalEnableLogin();
    void signalDisableLogin();
    void signalEnableStartOperationAction();
    void signalDisableStartOperationAction();


  private slots:
    void setUpTable();
    /**
     * Slot used to show the "enter code" widget
     */
    void showEnterCodeWidget();
    /**
     * Slot used to show the "search item" widget
     */
    void showSearchItemWidget();
    /**
     * Slot used to search an item description into database, to get the code.
     */
    void doSearchItemDesc();
    /**
      * Slot to search for a product code in the table, if found then qty is incremented.
    */
    bool incrementTableItemQty(QString code, double q);
    /**
      * Slot used to get a product info from the database and insert it to the table
      */
    void insertItem(QString code);
    /**
     * Slot used to insert an item into the buy list, do the real insert
     */
    int doInsertItem(QString itemCode, QString itemDesc, double itemQty, double itemPrice, double itemDiscount, QString itemUnits);
    void updateItem(ProductInfo prod);
    /**
     * Slot used to delete the current item.
    */
    void deleteSelectedItem();
   /**
     * Slot used to increment qty on doubleclick on an item
    */
    void itemDoubleClicked(QTableWidgetItem* item);
   /**
     * Slot used to add clicked item to shopping list...
     */
    void itemSearchDoubleClicked(QTableWidgetItem *item);
   /**
     * Slot used to refresh (recalculate) the total due.
    */
    void refreshTotalLabel();
  /**
     * Slot used to display product information on the left panel.
   */
    void displayItemInfo(QTableWidgetItem* item);
  /**
     * Slot used to create a new transaction. It gets last transaction number from database, and creates a new one.
   */
    void createNewTransaction(TransactionType type); //NOTE: With parameter transactionType ??
  /**
     * Slot used to finish current TRansaction. It saves transaction on database.
   */
    void finishCurrentTransaction();
  /**
     * Slot used to cancel the current transaction on the database.
   */
    void cancelCurrentTransaction();
    void preCancelCurrentTransaction();
    void deleteCurrentTransaction();
  /**
     * Slot used to cancel a transaction from database
   */
    void cancelTransaction(qulonglong transactionNumber);
    void askForIdToCancel();
    void askForTicketToReturnProduct();
  /**
     * Slot used to start store operation, gaveta qty is set to 0.
   */
    void startOperation(const QString &adminUser);
    void _slotDoStartOperation();
    void slotDoStartOperation(const bool &ask = true);
  /**
     * Slot used to clear the tableWidget, totals, amount and card number.
   */
    void clearUsedWidgets();
  /**
     * Slot used to print the ticket, show a frame message and wait a few seconds...
   **/
    void printTicket(TicketInfo ticket);
  /**
     * Slot used to print balance for the user.
   */
    void printBalance(QStringList lines);
    void showBalance(QStringList lines);
  /**
     * This slot is used to make a balance for the user (initial + in - out = drawer amount).
   */
    //void corteDeCaja();  GONE TO PUBLIC
    void doCorteDeCaja();
    void endOfDay();

    void startAgain();
  /**
     * Slot used to get the row where an item with code is at the main table.
     * Returns -1 if not found, else returns table row where is located.
   **/
    int getItemRow(QString c);

    void buttonDone();
    void checksChanged();
    void focusPayInput();
    void plusPressed();
    void setupGridView();


    void doEmitSignalQueryDb();

    void settingsChanged();
    void settingsChangedOnInitConfig();
    void login();
    void setupDB();
    void connectToDb();
    void setupClients();
    void timerTimeout();
    void clearLabelSearchMsg();
    void goSelectCardAuthNumber();


    void listViewOnMouseMove(const QModelIndex & index);
    void listViewOnClick( const QModelIndex & index );
    void clientChanged();
    void updateClientInfo();
    void updateModelView();
    void showProductsGrid(bool show);
    void showPriceChecker();
    void hideProductsGrid();
    void populateCategoriesHash();
    void populateCardTypes();
    void populateSubCategoriesHash();
    void setFilter();
    void showChangeDate();

    void showReprintTicket();
    void setupTicketView();
    void setupHistoryTicketsModel();
    void printTicketFromTransaction(qulonglong transactionNumber);
    void printSelTicket();
    void setHistoryFilter();
    void btnTicketsDone() {  ui_mainview.mainPanel->setCurrentIndex(0); };
    void itemHIDoubleClicked(const QModelIndex &index);

    void cashOut();
    void cashIn();
    void cashAvailable();

    void freezeWidgets();
    void unfreezeWidgets();
    void addSpecialOrder();
    void specialOrderComplete();
    void lockScreen();
    void unlockScreen();
    void suspendSale();
    void resumeSale();
    void changeSOStatus();

    void updateTransaction();
    void updateBalance(bool finish); //implies the drawer content
    void insertBalance();

    void occasionalDiscount();
    void applyOccasionalDiscount();
    void changeDiscValidator();
    double getTotalQtyOnList(const ProductInfo &info);

    void log(const qulonglong &uid, const QDate &date, const QTime &time, const QString &text);
    void syncSettingsOnDb();

    void getCurrencies();
    void comboCurrencyOnChange();
    void doCurrencyConversion();
    void acceptCurrencyConversion();

    void reserveItems();
    void suspendReservation();
    void resumeReservation();
    void postponeReservation();
    void addReservationPayment(); //used to add a payment to a reservation without paying it totally.
    void insertCashInForReservationPayment(const qulonglong &rid, const double &amount);

    void showCredits();
    void filterClientForCredit();
    void filterClient();
    void calculateTotalForClient();
    void showCreditPayment();
    void tenderedChanged();
    void doCreditPayment();
    void insertCashInForCredit(const CreditInfo &credit, const double &amount);
    void printCreditReport();

    void qtyChanged(QTableWidgetItem *item);
    void modifyClientsFilterModel();
    void modifyClientsFilterModelB();
    void verifyDiscountEntry();
    void createClient();
    void printFactura(FacturaCBB factura);
    void cancelarFactura();
    void emitirFactura();
    void reprintFactura();
    void facturasLibres();
    void resizeSearchTable();
    
};

#endif // LEMONVIEW_H
