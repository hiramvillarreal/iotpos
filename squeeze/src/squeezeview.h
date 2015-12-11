/***************************************************************************
 *   Copyright © 2007-2012 by Miguel Chavez Gamboa                         *
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

#ifndef SQUEEZEVIEW_H
#define SQUEEZEVIEW_H

#include <QWidget>
#include <QtSql>

#include "ui_squeezeview_base.h"
#include "../../src/loginwindow.h"

class QPainter;
class LoginWindow;
class KPlotObject;
class MibitFloatPanel;
class QListWidgetItem;
class MibitNotifier;

/**
 * This is the main view class for squeeze.  Most of the non-menu,
 * non-toolbar, and non-statusbar (e.g., non frame) GUI code should go
 * here.
 *
 * @short Main view
 * @author Miguel Chavez Gamboa <miguel.chavez.gamboa@gmail.com>
 */
class squeezeView : public QWidget, public Ui::squeezeview_base
{
    Q_OBJECT
public:
    squeezeView(QWidget *parent);
    virtual ~squeezeView();
    bool isConnected() { return db.isOpen(); };
    bool modelsAreCreated() { return modelsCreated; };
    void closeDB();
    void openDB();
    bool isAdminUser() { return adminIsLogged; }

  private:
    QTimer *rmTimer;
    Ui::squeezeview_base ui_mainview;
    QString activeDb;
    QSqlDatabase db;
    bool adminIsLogged;
    LoginWindow *dlgPassword;
    QHash<QString, int> categoriesHash;
    QHash<QString, int> cardTypesHash;
    QHash<QString, int> departmentsHash;
    QHash<QString, int> subcategoriesHash;
    QSqlRelationalTableModel *productsModel;
    QSqlRelationalTableModel *offersModel;
    QSqlRelationalTableModel *cashflowModel;
    QSqlRelationalTableModel *specialOrdersModel;
    QSqlTableModel *usersModel;
    QSqlTableModel *measuresModel;
    QSqlTableModel *categoriesModel;
    QSqlTableModel *departmentsModel;
    QSqlRelationalTableModel *subcategoriesModel;
    QSqlTableModel *balancesModel;
    QSqlTableModel *clientsModel;
    QSqlTableModel *randomMsgModel;
    QSqlRelationalTableModel *reservationsModel;
    QSqlRelationalTableModel *logsModel;
    QSqlRelationalTableModel *transactionsModel;
    QSqlTableModel *currenciesModel;
    int productCodeIndex, productDescIndex, productPriceIndex, productStockIndex, productCostIndex,
    productSoldUnitsIndex, productLastSoldIndex, productUnitsIndex, productTaxIndex, productETaxIndex,
    productPhotoIndex, productCategoryIndex, productPointsIndex, productLastProviderIndex, productAlphaCodeIndex, productIsAGroupIndex, productIsARawIndex, productGEIndex, productIsNotDiscountable;
    int offerIdIndex, offerDiscountIndex, offerDateStartIndex, offerDateEndIndex,offerProdIdIndex;
    int userIdIndex, usernameIndex, nameIndex, passwordIndex, saltIndex, addressIndex, phoneIndex, cellIndex, roleIndex,
    photoIndex;
    int transIdIndex, transClientidIndex, transTypeIndex,transAmountIndex,transDateIndex,transTimeIndex,transPaidWithIndex,
    transChangeGivenIndex,transPayMethodIndex,transStateIndex,transUseridIndex,transCardNumIndex,transItemCountIndex,transPointsIndex,
    transDiscMoneyIndex,transDiscIndex,transCardAuthNumberIndex,transUtilityIndex,transTerminalNumIndex,transItemsListIndex,  transSOIndex, transProvIdIndex;
    QTimer *timerCheckDb, *timerUpdateGraphs;
    int balanceIdIndex, balanceDateEndIndex, balanceUserNameIndex, balanceInitAmountIndex, balanceInIndex, balanceOutIndex, balanceCashIndex, balanceCardIndex,balanceTransIndex, balanceTerminalNumIndex, balanceDateStartIndex, balanceUseridIndex;
    int cashflowIdIndex, cashflowDateIndex, cashflowTimeIndex, cashflowUseridIndex, cashflowReasonIndex, cashflowAmountIndex,    cashflowTerminalNumIndex, cashflowTypeIndex;
    int counter;
    bool modelsCreated,graphSoldItemsCreated;
    KPlotObject *objProfit, *objSales, *objMostSold, *objMostSoldB;
    MibitFloatPanel *fpFilterTrans, *fpFilterProducts, *fpFilterBalances, *fpFilterOffers, *fpFilterSpecialOrders;

    QListWidgetItem *itmEndOfMonth;
    QListWidgetItem *itmGralEndOfDay;
    QListWidgetItem *itmEndOfDay;

    QListWidgetItem *itmPrintSoldOutProducts;
    QListWidgetItem *itmPrintLowStockProducts;
    QListWidgetItem *itmPrintStock;
    //QListWidgetItem *itmPrintBalance;

    MibitNotifier *notifierPanel;

    qulonglong loggedUserId;



signals:
    void signalChangeStatusbar(const QString& text);
    void signalChangeCaption(const QString& text);
    void signalConnected();
    void signalDisconnected();
    void signalConnectActions();
    void signalShowPrefs();
    void signalAdminLoggedOn();
    void signalSupervisorLoggedOn();
    void signalAdminLoggedOff();
    void signalSalir();
    void signalShowDbConfig();

 private slots:
   /* Ui related slot */
   void login();
   void settingsChanged();
   void settingsChangedOnInitConfig();
   void setupSignalConnections();
   void setOffersFilter();
   void toggleFilterBox(bool show);
   void showProductsPage();
   void showOffersPage();
   void showUsersPage();
   void showMeasuresPage();
   void showCategoriesPage();
   void showDepartmentsPage();
   void showSubCategoriesPage();
   void showClientsPage();
   void showTransactionsPage();
   void showReports();
   void showRandomMsgs();
   void usersViewOnSelected(const QModelIndex & index);
   void productsViewOnSelected(const QModelIndex &index);
   void clientsViewOnSelected(const QModelIndex &index);
   void doPurchase();
   void stockCorrection();
   void adjustOffersTable();
   void showPrefs();
   void cleanErrorLabel();
   void showWelcomeGraphs();
   void setupGraphs();
   void updateGraphs();
   void disableUI();
   void enableUI();
   void doEmitSignalSalir();
   void updateDepartmentsCombo();
   void updateCategoriesCombo();
   void updateCardTypesCombo();
   void updateSubCategoriesCombo();
   void showProdListAsGrid();
   void showProdListAsTable();
   void adjustProductsTable();
   void showBalancesPage();
   void setupBalancesModel();
   void showCashFlowPage();
   void showSpecialOrders();
   void setupCashFlowModel();
   void setupSpecialOrdersModel();
   void setSpecialOrdersFilter();
   void setupRandomMsgModel();
   void showCurrencies();

   void reportActivated(QListWidgetItem *);
   void printGralEndOfDay();
   void printEndOfDay();
   void printEndOfMonth();
   void printLowStockProducts();
   void printSoldOutProducts();
   void printStock();
   void printSelectedBalance();

    /* DB slots */
   void createUser();
   void createOffer();
   void createProduct();
   void createMeasure();
   void createCategory();
   void createDepartment();
   void createSubCategory();
   void createClient();
   void createRandomMsg();
   void createCurrency();
   void deleteSelectedCurrency();
   void deleteSelectedOffer();
   void deleteSelectedUser();
   void deleteSelectedProduct();
   void deleteSelectedMeasure();
   void deleteSelectedDepartment();
   void deleteSelectedCategory();
   void deleteSelectedSubCategory();
   void deleteSelectedClient();
   void populateDepartmentsHash();
   void populateCategoriesHash();
   void populateCardTypesHash();
   void populateSubCategoriesHash();
   void setProductsFilter();
   void setTransactionsFilter();
   void setBalancesFilter();

   void correctStock(qulonglong code, double oldStock, double newStock, const QString &reason);
   TransactionInfo createPurchase(ProductInfo info);

   void setupDb();
   void setupUsersModel();
   void setupOffersModel();
   void setupProductsModel();
   void setupMeasuresModel();
   void setupCategoriesModel();
   void setupDepartmentsModel();
   void setupSubCategoriesModel();
   void setupClientsModel();
   void setupTransactionsModel();
   void setupCurrenciesModel();
   void checkDBStatus();
   void connectToDb();


   //Biel - export products
   void exportTable();
   void exportQTableView(QAbstractItemView *tableview);

   //LOGS
   void log(const qulonglong &uid, const QDate &date, const QTime &time, const QString &text);
   void showLogs();
   void setupLogsModel();

   //reservations
   void showReservations();
   void setupReservationsModel();
   void reservationsOnSelected(const QModelIndex &index);

   void createFloatingPanels();
   void reSelectModels();

   void checkDefaultView();

   void agregarSerieFolios(); //Facturacion MX
   void cancelarFactura();
   void departmentsOnSelected(const QModelIndex &index);
   void categoriesOnSelected(const QModelIndex &index);
   
};

#endif // SQUEEZEVIEW_H
