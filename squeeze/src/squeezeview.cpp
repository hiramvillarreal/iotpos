/**************************************************************************
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

#define QT_GUI_LIB
//The above line is because that define is needed, and as i dont use qmake, i must define it here..
//And only caused problems with the QSqlRelationalDelegate.. what a thing.

#include "squeezeview.h"
#include "settings.h"
#include "usersdelegate.h"
#include "usereditor.h"
#include "clienteditor.h"
#include "promoeditor.h"
#include "producteditor.h"
#include "purchaseeditor.h"
#include "dialogseriefolios.h"
#include "subcategoryeditor.h"
#include "../../src/hash.h"
#include "../../src/misc.h"
#include "../../src/structs.h"
#include "../../src/enums.h"
#include "../../src/productdelegate.h"
#include "offersdelegate.h"
#include "../../dataAccess/azahar.h"
#include "../../src/inputdialog.h"
#include "../../mibitWidgets/mibitfloatpanel.h"
#include "../../mibitWidgets/mibitnotifier.h"
#include "../../printing/print-dev.h"
#include "../../printing/print-cups.h"

#include <QLabel>
#include <QPixmap>
#include <QByteArray>
#include <QBuffer>
#include <QTimer>
#include <QDoubleValidator>
#include <QRegExp>
#include <QTableView>
#include <QInputDialog>
#include <QListWidgetItem>

#include <QDataWidgetMapper>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QItemDelegate>
#include <QHeaderView>
#include <QDir>

#include <klocale.h>
#include <kfiledialog.h>
#include <kiconloader.h>
#include <kmessagebox.h>
#include <kactioncollection.h>
#include <kaction.h>
#include <kstandarddirs.h>

#include <kplotobject.h>
#include <kplotwidget.h>
#include <kplotaxis.h>
#include <kplotpoint.h>

#include <KNotification>

//TODO: Change all qDebug to errorDialogs or remove them.
//NOTE: Common configuration fields need to be shared between lemon and squeeze (low stock alarm value).

enum {pWelcome=0, pBrowseProduct=1, pBrowseOffers=2, pBrowseUsers=3, pBrowseMeasures=4, pBrowseCategories=5, pBrowseClients=6, pBrowseRandomMessages=7, pBrowseLogs=8, pBrowseSO=9, pReports=10, pBrowseCurrencies=11, pBrowseReservations=12, pBrowseSubCategories=14, pBrowseDepartments=15};


squeezeView::squeezeView(QWidget *parent)
    : QWidget(parent)
{
  qDebug()<<"===STARTING SQUEEZE AT "<<QDateTime::currentDateTime().toString()<<" ===";
  adminIsLogged = false;
  ui_mainview.setupUi(this);
  setAutoFillBackground(true);

  // The db = QSqlDatabase called multiple times is causing a crash on certain installations (Not on kubuntu 8.10).
  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
  db = QSqlDatabase::addDatabase("QMYSQL");

  ///Login dialog
  dlgPassword = new LoginWindow(i18n("Authorisation Required"),
                                 i18n("Enter administrator/supervisor user and password please."),
                                 LoginWindow::PasswordOnly);


  
  ui_mainview.headerLabel->setText(i18n("Basic Information"));
  ui_mainview.headerImg->setPixmap((DesktopIcon("view-statistics", 48)));

  ///other things
  counter = 5;
  modelsCreated = false;
  graphSoldItemsCreated = false;
  timerCheckDb = new QTimer(this);
  timerCheckDb->setInterval(1000);
  timerUpdateGraphs = new QTimer(this);
  timerUpdateGraphs->setInterval(10000);
  categoriesHash.clear();
  subcategoriesHash.clear();
  departmentsHash.clear();
  setupSignalConnections();
  QTimer::singleShot(1100, this, SLOT(setupDb()));
  QTimer::singleShot(2000, timerCheckDb, SLOT(start()));
  QTimer::singleShot(20000, timerUpdateGraphs, SLOT(start()));
  QTimer::singleShot(2010, this, SLOT(showWelcomeGraphs()));
  QTimer::singleShot(2000, this, SLOT(login()));
  rmTimer = new QTimer(this);
  connect(rmTimer, SIGNAL(timeout()), SLOT(reSelectModels()) );
  rmTimer->start(1000*60*2);

  ui_mainview.stackedWidget->setCurrentIndex(pWelcome);
  ui_mainview.errLabel->hide();
  ui_mainview.productsViewAlt->hide();

  QString logoBottomFile = KStandardDirs::locate("appdata", "images/logo.png");
  ui_mainview.logoLabel->setPixmap(QPixmap(logoBottomFile));
  ui_mainview.logoLabel->setAlignment(Qt::AlignCenter);

  itmEndOfDay     = new QListWidgetItem(DesktopIcon("lemon-reports", 96), i18n("End of Day"), ui_mainview.reportsList);
  itmGralEndOfDay = new QListWidgetItem(DesktopIcon("lemon-reports", 96), i18n("General End of Day"), ui_mainview.reportsList);
  itmEndOfMonth   = new QListWidgetItem(DesktopIcon("lemon-reports", 96), i18n("End of Month"), ui_mainview.reportsList);
  itmPrintSoldOutProducts = new QListWidgetItem(DesktopIcon("lemon-reports", 96), i18n("Sold Out Products"), ui_mainview.reportsList);
  itmPrintLowStockProducts = new QListWidgetItem(DesktopIcon("lemon-reports", 96), i18n("Low Stock Products"), ui_mainview.reportsList);
  itmPrintStock   = new QListWidgetItem(DesktopIcon("lemon-reports", 96), i18n("Stock Report"), ui_mainview.reportsList);
  //itmPrintBalance = new QListWidgetItem(DesktopIcon("lemon-reports", 96), i18n("A Balance"), ui_mainview.reportsList);

  
  ui_mainview.btnBalances->setIcon(DesktopIcon("lemonbalance", 32));
  ui_mainview.btnCashFlow->setIcon(DesktopIcon("lemon-cashout", 32));
  ui_mainview.btnTransactions->setIcon(DesktopIcon("wallet-open", 32));
  ui_mainview.btnSO->setIcon(DesktopIcon("lemon-box", 32));


  QTimer::singleShot(500,this, SLOT(createFloatingPanels()) );
  QTimer::singleShot(1000,this, SLOT(checkDefaultView()) );

  logoBottomFile = KStandardDirs::locate("appdata", "styles/");
  logoBottomFile = logoBottomFile+"tip.svg";
  notifierPanel = new MibitNotifier(this,logoBottomFile, DesktopIcon("dialog-warning", 32));

}

void squeezeView::checkDefaultView()
{
  if (Settings::isProductsGridDefault()) {
    ui_mainview.productsView->show();
    ui_mainview.productsViewAlt->hide();
    ui_mainview.chViewProductsListAsGrid->setChecked(true);
  } else {
    ui_mainview.productsView->hide();
    ui_mainview.productsViewAlt->show();
    fpFilterProducts->reParent(ui_mainview.productsViewAlt);
    ui_mainview.chViewProductsListAsTable->setChecked(true);
  }
}

void squeezeView::createFloatingPanels()
{
  QString path = KStandardDirs::locate("appdata", "styles/");
  path = path+"floating_top.svg";
  fpFilterTrans    = new MibitFloatPanel(ui_mainview.transactionsTable, path, Top,700,300);
  fpFilterProducts = new MibitFloatPanel(ui_mainview.productsView, path, Top,700,200);
  fpFilterOffers   = new MibitFloatPanel(ui_mainview.tableBrowseOffers, path, Top,500,200);
  fpFilterBalances = new MibitFloatPanel(ui_mainview.balancesTable, path, Top,700,240);
  fpFilterSpecialOrders = new MibitFloatPanel(ui_mainview.tableSO, path, Top,700,240);
  fpFilterTrans->addWidget(ui_mainview.groupFilterTransactions);
  fpFilterProducts->addWidget(ui_mainview.groupFilterProducts);
  fpFilterBalances->addWidget(ui_mainview.groupFilterBalances);
  fpFilterOffers->addWidget(ui_mainview.groupFilterOffers);
  fpFilterSpecialOrders->addWidget(ui_mainview.groupSOFilter);
}

void squeezeView::cleanErrorLabel()
{
  ui_mainview.errLabel->clear();
  ui_mainview.errLabel->hide();
}

void squeezeView::login(){
  qDebug()<<"Login()";
  adminIsLogged = false;
  loggedUserId = 0;
  disableUI();
  emit signalAdminLoggedOff();
  dlgPassword->clearLines();
  if (!db.isOpen()) {
    db.open(); //try to open connection
    qDebug()<<"(1): Trying to open connection to database..";
  }
  if (!db.isOpen()) {
    QString details = db.lastError().text();
    //KPassivePopup::message( i18n("Error:"),details, DesktopIcon("dialog-error", 48), this );
    KNotification *notify = new KNotification(i18n("Unable to connect to the database"), this);
    notify->setText(details);
    QPixmap pixmap = DesktopIcon("dialog-error",32); //NOTE: This does not works
    notify->setPixmap(pixmap);
    notify->sendEvent();
    
    emit signalShowDbConfig();
  } else {
    bool doit = false;
      if (!Settings::lowSecurityMode()) {
        doit = dlgPassword->exec();
      } else { //this is a low security mode!
        adminIsLogged = true;
        loggedUserId  = 1; //default admin.
        emit signalAdminLoggedOn();
        enableUI();
      }
    
    if ( doit ) {
      int role = dlgPassword->getUserRole();
      loggedUserId = dlgPassword->getUserId();
      if ( role == roleAdmin) {
        adminIsLogged = true;
        emit signalAdminLoggedOn();
        qDebug()<<"Admin Logged on..";
      }
      else if (role == roleSupervisor) {
        adminIsLogged = false;
        emit signalSupervisorLoggedOn();
        qDebug()<<"Supervisor Logged on..";
       }
      else {
        emit signalAdminLoggedOff();
        adminIsLogged = false;
      }
      enableUI();
    } else {
      //restrict only if NOT low sec mode
      if (!Settings::lowSecurityMode()) {
        emit signalAdminLoggedOff();
        loggedUserId = 0;
        disableUI();
        qDebug()<<"login cancelled...";
      }
    }
  }
}

void squeezeView::setupSignalConnections()
{
  //NOTE: Use activated or double clicked??? sometimes doubleclicked does not work! by using activated and setting "double clicks activate" on
  //      kde systemsettings preference dialog (mose and keyboard config) is fine for squeeze, but not for lemon using a touchscreen. In this
  //      last case, it make sense to let "single click activates" setting on kde systemsettings since is rarely used lemon and squeeze in the same pc.
  
  connect(ui_mainview.usersView, SIGNAL(activated(const QModelIndex &)), SLOT(usersViewOnSelected(const QModelIndex &)));
  connect(ui_mainview.clientsView, SIGNAL(activated(const QModelIndex &)), SLOT(clientsViewOnSelected(const QModelIndex &)));
  connect(ui_mainview.productsView, SIGNAL(activated(const QModelIndex &)), SLOT(productsViewOnSelected(const QModelIndex &)));
  connect(ui_mainview.productsViewAlt, SIGNAL(activated(const QModelIndex &)), SLOT(productsViewOnSelected(const QModelIndex &)));
  connect(ui_mainview.tableReservations, SIGNAL(activated(const QModelIndex &)), SLOT(reservationsOnSelected(const QModelIndex &)));
  connect(ui_mainview.tableReservations, SIGNAL(entered(const QModelIndex &)), SLOT(reservationsOnSelected(const QModelIndex &)));
  ui_mainview.tableReservations->setMouseTracking(true); //to allow the entered signal works on the previous line.

  connect(ui_mainview.tableDepartments, SIGNAL(activated(const QModelIndex &)), SLOT(departmentsOnSelected(const QModelIndex &)));
  connect(ui_mainview.tableCategories, SIGNAL(activated(const QModelIndex &)), SLOT(categoriesOnSelected(const QModelIndex &)));

  connect(ui_mainview.groupFilterOffers, SIGNAL(toggled(bool)), SLOT(setOffersFilter()));
  connect(ui_mainview.chOffersSelectDate, SIGNAL(toggled(bool)), SLOT(setOffersFilter()));
  connect(ui_mainview.chOffersTodayDiscounts, SIGNAL(toggled(bool)), SLOT(setOffersFilter()));
  connect(ui_mainview.chOffersOldDiscounts, SIGNAL(toggled(bool)), SLOT(setOffersFilter()));
  connect(ui_mainview.chOffersFilterByProduct, SIGNAL(toggled(bool)), SLOT(setOffersFilter()));
  connect(ui_mainview.editOffersFilterByProduct, SIGNAL( textEdited(const QString &) ), SLOT(setOffersFilter()));
  connect(ui_mainview.btnAddUser, SIGNAL(clicked()), SLOT(createUser()));
  connect(ui_mainview.btnAddOffer, SIGNAL(clicked()), SLOT(createOffer()));
  connect(ui_mainview.btnDeleteUser, SIGNAL(clicked()), SLOT(deleteSelectedUser()));
  connect(ui_mainview.btnDeleteOffer, SIGNAL(clicked()), SLOT(deleteSelectedOffer()));
  connect(ui_mainview.btnAddProduct, SIGNAL(clicked()), SLOT(createProduct()) );
  connect(ui_mainview.btnAddMeasure, SIGNAL(clicked()), SLOT(createMeasure()) );
  connect(ui_mainview.btnAddDepartment, SIGNAL(clicked()), SLOT(createDepartment()) );
  connect(ui_mainview.btnAddCategory, SIGNAL(clicked()), SLOT(createCategory()) );
  connect(ui_mainview.btnAddSubCategory, SIGNAL(clicked()), SLOT(createSubCategory()) );
  connect(ui_mainview.btnAddClient, SIGNAL(clicked()), SLOT(createClient()));
  connect(ui_mainview.btnDeleteProduct, SIGNAL(clicked()), SLOT(deleteSelectedProduct()) );
  connect(ui_mainview.btnDeleteMeasure, SIGNAL(clicked()), SLOT(deleteSelectedMeasure()) );
  connect(ui_mainview.btnDeleteDepartment, SIGNAL(clicked()), SLOT(deleteSelectedDepartment()) );
  connect(ui_mainview.btnDeleteCategory, SIGNAL(clicked()), SLOT(deleteSelectedCategory()) );
  connect(ui_mainview.btnDeleteSubCategory, SIGNAL(clicked()), SLOT(deleteSelectedSubCategory()) );
  connect(ui_mainview.btnDeleteClient, SIGNAL(clicked()), SLOT(deleteSelectedClient()));
  //connect(ui_mainview.btnConfigure, SIGNAL(clicked()),  SLOT( showPrefs()));

  connect(ui_mainview.btnAddRandomMsg, SIGNAL(clicked()), SLOT(createRandomMsg()));

  connect(timerCheckDb, SIGNAL(timeout()), this, SLOT(checkDBStatus()));
  connect(timerUpdateGraphs, SIGNAL(timeout()), this, SLOT(updateGraphs()));
  connect(ui_mainview.offersDateEditor, SIGNAL(changed(const QDate &)), this, SLOT(setOffersFilter()));

  connect(this, SIGNAL(signalAdminLoggedOn()),  SLOT( enableUI()));
  connect(this, SIGNAL(signalAdminLoggedOff()),  SLOT( disableUI()));
  //connect(ui_mainview.btnExit, SIGNAL(clicked()),  SLOT( doEmitSignalSalir()));

  
  connect(ui_mainview.chViewProductsListAsGrid, SIGNAL(toggled(bool)), SLOT(showProdListAsGrid()));
  connect(ui_mainview.chViewProductsListAsTable, SIGNAL(toggled(bool)), SLOT(showProdListAsTable() ));

  //connect actions for transactions filters
  connect(ui_mainview.groupFilterTransactions, SIGNAL(toggled(bool)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.rbTransFilterByStateFinished, SIGNAL(toggled(bool)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.rbTransFilterByStateCancelled, SIGNAL(toggled(bool)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.rbTransFilterByPaidCash, SIGNAL(toggled(bool)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.rbTransFilterByPaidCredit, SIGNAL(toggled(bool)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.comboCardTypes, SIGNAL(currentIndexChanged(int)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.rbTransFilterByDate, SIGNAL(toggled(bool)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.transactionsDateEditor, SIGNAL( changed(const QDate &) ), SLOT(setTransactionsFilter()));
  connect(ui_mainview.rbTransFilterByUser, SIGNAL(toggled(bool)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.editTransUsersFilter,SIGNAL(textEdited( const QString &)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.rbTransFilterByClient, SIGNAL(toggled(bool)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.editTransClientsFilter,SIGNAL(textEdited( const QString &)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.rbTransFilterByAmountLess, SIGNAL(toggled(bool)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.rbTransFilterByAmountGreater, SIGNAL(toggled(bool)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.editTransAmountLess ,SIGNAL(valueChanged ( double ) ), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.editTransAmountGreater,SIGNAL(valueChanged ( double ) ), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.rbTransFilterTerminalNum, SIGNAL(toggled(bool)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.editTransTermNum,SIGNAL(valueChanged ( int ) ), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.rbTransactionsFilterOnlySales, SIGNAL(toggled(bool)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.rbTransactionsFilterOnlyPurchases, SIGNAL(toggled(bool)), this, SLOT( setTransactionsFilter()) );
  connect(ui_mainview.rbTransactionsFilterOnlyChangesReturns, SIGNAL(toggled(bool)), this, SLOT( setTransactionsFilter()) );

  //connect actions for balances filters
  connect(ui_mainview.groupFilterBalances, SIGNAL(toggled(bool)), this, SLOT( setBalancesFilter()) );
  connect(ui_mainview.rbBalancesFilterByState, SIGNAL(toggled(bool)), this, SLOT( setBalancesFilter()) );
  connect(ui_mainview.rbBalancesFilterBySuspicious, SIGNAL(toggled(bool)), this, SLOT( setBalancesFilter()) );
  connect(ui_mainview.rbBalancesFilterByDate, SIGNAL(toggled(bool)), this, SLOT( setBalancesFilter()) );
  connect(ui_mainview.rbBalancesFilterByUser, SIGNAL(toggled(bool)), this, SLOT( setBalancesFilter()) );
  connect(ui_mainview.rbBalancesFilterByCashInLess, SIGNAL(toggled(bool)), this, SLOT( setBalancesFilter()) );
  connect(ui_mainview.rbBalancesFilterByCashInGrater, SIGNAL(toggled(bool)), this, SLOT( setBalancesFilter()) );
  connect(ui_mainview.editBalancesFilterByDate, SIGNAL( changed(const QDate &) ), SLOT(setBalancesFilter()));
  connect(ui_mainview.rbBalancesFilgerByTerminalNum, SIGNAL(toggled(bool)), this, SLOT( setBalancesFilter()) );
  connect(ui_mainview.editBalancesFilterByVendor,SIGNAL(textEdited( const QString &)), this, SLOT( setBalancesFilter()) );
  connect(ui_mainview.editBalancesFilterByCasInLess ,SIGNAL(valueChanged ( double ) ), this, SLOT( setBalancesFilter()) );
  connect(ui_mainview.editBalancesFilterByCashInGrater,SIGNAL(valueChanged ( double ) ), this, SLOT( setBalancesFilter()) );
  connect(ui_mainview.editBalancesFilterByTermNum,SIGNAL(valueChanged ( int ) ), this, SLOT( setBalancesFilter()) );

  connect(ui_mainview.btnPrintBalance, SIGNAL(clicked()) ,SLOT(printSelectedBalance()) );

  connect(ui_mainview.comboProductsFilterByCategory,SIGNAL(currentIndexChanged(int)), this, SLOT( setProductsFilter()) );
  connect(ui_mainview.editProductsFilterByDesc,SIGNAL(textEdited(const QString &)), this, SLOT( setProductsFilter()) );
  connect(ui_mainview.rbProductsFilterByDesc, SIGNAL(toggled(bool)), this, SLOT( setProductsFilter()) );
  connect(ui_mainview.rbProductsFilterByCategory, SIGNAL(toggled(bool)), this, SLOT( setProductsFilter()) );
  connect(ui_mainview.rbProductsFilterByAvailable, SIGNAL(toggled(bool)), this, SLOT( setProductsFilter()) );
  connect(ui_mainview.rbProductsFilterByNotAvailable, SIGNAL(toggled(bool)), this, SLOT( setProductsFilter()) );
  connect(ui_mainview.rbProductsFilterByMostSold, SIGNAL(toggled(bool)), this, SLOT( setProductsFilter()) );
  connect(ui_mainview.rbProductsFilterByLessSold, SIGNAL(toggled(bool)), this, SLOT( setProductsFilter()) );
  connect(ui_mainview.rbProductsFilterByAlmostSoldOut, SIGNAL(toggled(bool)), this, SLOT( setProductsFilter()) );
  connect(ui_mainview.rbProductsFilterByRaw, SIGNAL(toggled(bool)), this, SLOT( setProductsFilter()) );
  connect(ui_mainview.rbProductsFilterByGroup, SIGNAL(toggled(bool)), this, SLOT( setProductsFilter()) );
  connect(ui_mainview.groupFilterProducts, SIGNAL(toggled(bool)), this, SLOT( setProductsFilter()) );
  connect(ui_mainview.comboProductsFilterBySubCategory,SIGNAL(currentIndexChanged(int)), this, SLOT( setProductsFilter()) );
  connect(ui_mainview.rbProductsFilterBySubCategory, SIGNAL(toggled(bool)), this, SLOT( setProductsFilter()) );
  connect(ui_mainview.chChainiedFilterForCategories, SIGNAL(toggled(bool)), this, SLOT( setProductsFilter()) );
  
  // BFB: New, export qtableview
  connect(ui_mainview.btnExport, SIGNAL(clicked()),  SLOT( exportTable()));
  connect(ui_mainview.btnExportProducts, SIGNAL(clicked()),  SLOT( exportTable()));
  connect(ui_mainview.btnExportOffers, SIGNAL(clicked()),  SLOT( exportTable()));
  connect(ui_mainview.btnExportUsers, SIGNAL(clicked()),  SLOT( exportTable()));
  connect(ui_mainview.btnExportClients, SIGNAL(clicked()),  SLOT( exportTable()));
  connect(ui_mainview.btnExportMeasures, SIGNAL(clicked()),  SLOT( exportTable()));
  connect(ui_mainview.btnExportCategories, SIGNAL(clicked()),  SLOT( exportTable()));
  connect(ui_mainview.btnExportSubCategories, SIGNAL(clicked()),  SLOT( exportTable()));
  //connect(ui_mainview.btnExportCustomReports, SIGNAL(clicked()),  SLOT( exportTable()));

  //connect(ui_mainview.btnLogin, SIGNAL(clicked()), this, SLOT(login()));

  connect(ui_mainview.btnBalances, SIGNAL(clicked()),  SLOT(showBalancesPage()));
  connect(ui_mainview.btnTransactions, SIGNAL(clicked()),  SLOT(showTransactionsPage()));
  connect(ui_mainview.btnCashFlow, SIGNAL(clicked()),  SLOT(showCashFlowPage()));
  connect(ui_mainview.btnSO, SIGNAL(clicked()),  SLOT(showSpecialOrders()));

  connect(ui_mainview.reportsList, SIGNAL(itemActivated(QListWidgetItem *)), SLOT(reportActivated(QListWidgetItem *)));

  //connect actions for special orders filters
  connect(ui_mainview.groupSOFilter, SIGNAL(toggled(bool)), this, SLOT( setSpecialOrdersFilter()) );
  connect(ui_mainview.rbSOByDate, SIGNAL(toggled(bool)), this, SLOT( setSpecialOrdersFilter()) );
  connect(ui_mainview.rbSOByThisWeek, SIGNAL(toggled(bool)), this, SLOT( setSpecialOrdersFilter()) );
  connect(ui_mainview.rbSOByThisMonth, SIGNAL(toggled(bool)), this, SLOT( setSpecialOrdersFilter()) );
  connect(ui_mainview.rbSOByStatusPending, SIGNAL(toggled(bool)), this, SLOT( setSpecialOrdersFilter()) );
  connect(ui_mainview.rbSOByStatusReady, SIGNAL(toggled(bool)), this, SLOT( setSpecialOrdersFilter()) );
  connect(ui_mainview.rbSOByStatusDelivered, SIGNAL( toggled(bool) ), SLOT(setSpecialOrdersFilter()));
  connect(ui_mainview.rbSOByStatusCancelled, SIGNAL(toggled(bool)), this, SLOT( setSpecialOrdersFilter()) );
  connect(ui_mainview.datePicker,SIGNAL(changed(const QDate &)), this, SLOT( setSpecialOrdersFilter()) );


  connect(ui_mainview.btnAddCurrency, SIGNAL(clicked()), SLOT(createCurrency()));
  connect(ui_mainview.btnDeleteCurrency, SIGNAL(clicked()), SLOT(deleteSelectedCurrency()));
}

void squeezeView::doEmitSignalSalir()
{
  emit signalSalir();
}

void squeezeView::enableUI()
{
  ui_mainview.stackedWidget->show();
}

void squeezeView::disableUI()
{
  ui_mainview.stackedWidget->hide();
}

void squeezeView::showWelcomeGraphs()
{
  if (!graphSoldItemsCreated) setupGraphs();
  ui_mainview.stackedWidget->setCurrentIndex(pWelcome);
  ui_mainview.headerLabel->setText(i18n("Quick Information"));
  ui_mainview.headerImg->setPixmap((DesktopIcon("view-statistics",48)));
  ui_mainview.btnPrintBalance->hide();
}


void squeezeView::showPrefs()
{
  emit signalShowPrefs();
}

void squeezeView::showProductsPage()
{
  ui_mainview.stackedWidget->setCurrentIndex(pBrowseProduct);
  if (productsModel->tableName().isEmpty()) setupProductsModel();
  ui_mainview.headerLabel->setText(i18n("Products"));
  ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-box",48)));
  ui_mainview.btnPrintBalance->hide();
  QTimer::singleShot(200,this, SLOT(adjustProductsTable()));
  qDebug()<<"view ALT geometry:"<<ui_mainview.productsViewAlt->geometry()<<" NORM Geom:"<<ui_mainview.productsView->geometry();
  QTimer::singleShot(500,fpFilterProducts, SLOT(fixPos()));
}

void squeezeView::showOffersPage()
{
  ui_mainview.stackedWidget->setCurrentIndex(pBrowseOffers);
  if (offersModel->tableName().isEmpty()) setupOffersModel();
  ui_mainview.headerLabel->setText(i18n("Offers"));
  ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-offers",48)));
  ui_mainview.offersDateEditor->setDate(QDate::currentDate());
  QTimer::singleShot(500,this, SLOT(adjustOffersTable()));
  ui_mainview.btnPrintBalance->hide();
  QTimer::singleShot(200,fpFilterOffers, SLOT(fixPos()));

  //FIXME & NOTE: Offers that does not have existing products are ignored (hidden) on the view, but still exists on Database.
  //              This happens when an offer exists for a product, but the product code is changed or deleted later.
}

void squeezeView::showUsersPage()
{
  ui_mainview.stackedWidget->setCurrentIndex(pBrowseUsers);
  if (usersModel->tableName().isEmpty()) setupUsersModel();
  ui_mainview.headerLabel->setText(i18n("Vendors"));
  ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-user",48)));
  ui_mainview.btnPrintBalance->hide();
}

void squeezeView::showMeasuresPage()
{
  ui_mainview.stackedWidget->setCurrentIndex(pBrowseMeasures);
  if (measuresModel->tableName().isEmpty()) setupMeasuresModel();
  ui_mainview.headerLabel->setText(i18n("Weight and Measures"));
  ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-ruler",48)));
  ui_mainview.btnPrintBalance->hide();
}

void squeezeView::showDepartmentsPage()
{
    ui_mainview.stackedWidget->setCurrentIndex(pBrowseDepartments);
    if (departmentsModel->tableName().isEmpty()) setupDepartmentsModel();
    ui_mainview.headerLabel->setText(i18n("Departments"));
    ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-categories",48)));
    ui_mainview.btnPrintBalance->hide();
}

void squeezeView::showCategoriesPage()
{
  ui_mainview.stackedWidget->setCurrentIndex(pBrowseCategories);
  if (categoriesModel->tableName().isEmpty()) setupCategoriesModel();
  ui_mainview.headerLabel->setText(i18n("Categories"));
  ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-categories",48)));
  ui_mainview.btnPrintBalance->hide();
}

void squeezeView::showSubCategoriesPage()
{
    ui_mainview.stackedWidget->setCurrentIndex(pBrowseSubCategories);
    if (subcategoriesModel->tableName().isEmpty()) setupSubCategoriesModel();
    ui_mainview.headerLabel->setText(i18n("Subcategories"));
    ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-categories",48)));
    ui_mainview.btnPrintBalance->hide();
}

void squeezeView::showClientsPage()
{
  ui_mainview.stackedWidget->setCurrentIndex(pBrowseClients);
  if (clientsModel->tableName().isEmpty()) setupClientsModel();
  ui_mainview.headerLabel->setText(i18n("Clients"));
  ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-user",48)));
  ui_mainview.btnPrintBalance->hide();
}

void squeezeView::showTransactionsPage()
{
  ui_mainview.stackedWidget->setCurrentIndex(pReports);
  ui_mainview.stackedWidget2->setCurrentIndex(1);
  if (transactionsModel->tableName().isEmpty()) setupTransactionsModel();
  ui_mainview.headerLabel->setText(i18n("Transactions"));
  ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-reports",48)));
  ui_mainview.transactionsDateEditor->setDate(QDate::currentDate());
  ui_mainview.btnPrintBalance->hide();
  QTimer::singleShot(200,fpFilterTrans, SLOT(fixPos()));
}

void squeezeView::showBalancesPage()
{
  ui_mainview.stackedWidget->setCurrentIndex(pReports);
  ui_mainview.stackedWidget2->setCurrentIndex(2);
  if (balancesModel->tableName().isEmpty()) setupBalancesModel();
  ui_mainview.headerLabel->setText(i18n("Balances"));
  ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-balance",48)));
  ui_mainview.btnPrintBalance->show();
  QTimer::singleShot(200,fpFilterBalances, SLOT(fixPos()));
}

void squeezeView::showSpecialOrders()
{
  ui_mainview.stackedWidget->setCurrentIndex(pReports);
  ui_mainview.stackedWidget2->setCurrentIndex(3);
  if (specialOrdersModel->tableName().isEmpty()) setupSpecialOrdersModel();
  ui_mainview.headerLabel->setText(i18n("Special Orders"));
  ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-box",48))); //FIXME: Create an icon
  QTimer::singleShot(200,fpFilterSpecialOrders, SLOT(fixPos()));
  ui_mainview.datePicker->setDate(QDate::currentDate());
}


void squeezeView::showCashFlowPage()
{
  ui_mainview.stackedWidget->setCurrentIndex(pReports);
  ui_mainview.stackedWidget2->setCurrentIndex(0);
  if (cashflowModel->tableName().isEmpty()) setupCashFlowModel();
  ui_mainview.headerLabel->setText(i18n("Cash Flow"));
  ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-cashout",48)));
  ui_mainview.cashFlowTable->resizeColumnsToContents();
  ui_mainview.btnPrintBalance->hide();
}

void squeezeView::showReports()
{
  ui_mainview.stackedWidget->setCurrentIndex(pReports);
  ui_mainview.headerLabel->setText(i18n("Reports"));
  ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-reports",48)));

  if (ui_mainview.stackedWidget2->currentIndex() == 2)
    ui_mainview.btnPrintBalance->show();
  else
    ui_mainview.btnPrintBalance->hide();
}

void squeezeView::showRandomMsgs()
{
  ui_mainview.stackedWidget->setCurrentIndex(pBrowseRandomMessages);
  ui_mainview.headerLabel->setText(i18n("Ticket Messages"));
  ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-ticket",48)));
  if (randomMsgModel->tableName().isEmpty()) setupRandomMsgModel();
}

void squeezeView::showCurrencies()
{
    ui_mainview.stackedWidget->setCurrentIndex(pBrowseCurrencies);
    ui_mainview.headerLabel->setText(i18n("Currencies"));
    ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-money",48)));
    if (currenciesModel->tableName().isEmpty()) setupCurrenciesModel();
}

void squeezeView::showReservations()
{
    ui_mainview.stackedWidget->setCurrentIndex(pBrowseReservations);//TODO:Remember to change the page number when merging with 0.9.3rc2
    ui_mainview.headerLabel->setText(i18n("Reservations"));
    ui_mainview.headerImg->setPixmap((DesktopIcon("lemon-box",48)));
    if (reservationsModel->tableName().isEmpty()) setupReservationsModel();
}

void squeezeView::toggleFilterBox(bool show)
{
  if (show) {
    switch (ui_mainview.stackedWidget->currentIndex())
    {
      case pBrowseProduct: ui_mainview.groupFilterProducts->show(); break;
      case pBrowseOffers:ui_mainview.groupFilterOffers->show(); break;
      case pWelcome: break;
      default: break;
    }
  }
  else {
    switch (ui_mainview.stackedWidget->currentIndex())
    {
      case pBrowseProduct: ui_mainview.groupFilterProducts->hide(); break;
      case pBrowseOffers:ui_mainview.groupFilterOffers->hide(); break;
      case pWelcome: break;
      default: break;
    }
  }
}


void squeezeView::adjustProductsTable()
{
  QSize size = ui_mainview.productsViewAlt->size();
  int portion = size.width()/11;
  ui_mainview.productsViewAlt->horizontalHeader()->setResizeMode(QHeaderView::Interactive);
  ui_mainview.productsViewAlt->horizontalHeader()->resizeSection(0, portion*1.5); // CODE
  ui_mainview.productsViewAlt->horizontalHeader()->resizeSection(1, portion*3.5); //Name
  ui_mainview.productsViewAlt->horizontalHeader()->resizeSection(2, portion); //Price
  ui_mainview.productsViewAlt->horizontalHeader()->resizeSection(3, portion);  //Stock
  ui_mainview.productsViewAlt->horizontalHeader()->resizeSection(4, portion); //Cost
  ui_mainview.productsViewAlt->horizontalHeader()->resizeSection(5, portion); //Sold Units
  ui_mainview.productsViewAlt->horizontalHeader()->resizeSection(6, portion); //Last Sold
  ui_mainview.productsViewAlt->horizontalHeader()->resizeSection(7, portion);  //Category
}

void squeezeView::adjustOffersTable()
{
  QSize size = ui_mainview.tableBrowseOffers->size();
  int portion = size.width()/6;
  ui_mainview.tableBrowseOffers->horizontalHeader()->setResizeMode(QHeaderView::Interactive);
  ui_mainview.tableBrowseOffers->horizontalHeader()->resizeSection(1, portion*1.5); //PRODUCT DESC
  ui_mainview.tableBrowseOffers->horizontalHeader()->resizeSection(2, portion); //Qty
  ui_mainview.tableBrowseOffers->horizontalHeader()->resizeSection(3, portion); //Date start
  ui_mainview.tableBrowseOffers->horizontalHeader()->resizeSection(4, portion*2.5);  //date end
}

void squeezeView::showProdListAsGrid()
{
  if (ui_mainview.chViewProductsListAsGrid->isChecked()) {
    ui_mainview.productsView->show();
    ui_mainview.productsViewAlt->hide();
    //reparent the filter panel
    fpFilterProducts->reParent(ui_mainview.productsView);
    QTimer::singleShot(200,fpFilterProducts, SLOT(fixPos()));
  }
}

void squeezeView::showProdListAsTable()
{
  if (ui_mainview.chViewProductsListAsTable->isChecked()) {
    ui_mainview.productsViewAlt->show();
    ui_mainview.productsView->hide();
    // BFB: There's no need to adjust product table. We could do a resizeColumnsToContents() after model.select()
    QTimer::singleShot(200,this, SLOT(adjustProductsTable()));
    //reparent the filter panel
    fpFilterProducts->reParent(ui_mainview.productsViewAlt);
    QTimer::singleShot(200,fpFilterProducts, SLOT(fixPos()));
  }
}

squeezeView::~squeezeView()
{
}

void squeezeView::setupGraphs()
{
  //plots...
  QString mes = (QDate::longMonthName(QDate::currentDate().month())).toUpper();
  ui_mainview.plotSales->setMinimumSize( 200, 200 );
  ui_mainview.plotSales->setAntialiasing( true );
  objSales = new KPlotObject( Qt::yellow, KPlotObject::Bars, KPlotObject::Star);
  ui_mainview.plotSales->addPlotObject( objSales );
  ui_mainview.plotSales->axis( KPlotWidget::BottomAxis )->setLabel( i18n("%1", mes) );
  ui_mainview.plotSales->axis( KPlotWidget::LeftAxis )->setLabel( i18n("Month Sales (%1)", KGlobal::locale()->currencySymbol()) );
  ui_mainview.plotProfit->setMinimumSize( 200, 200 );
  ui_mainview.plotProfit->setAntialiasing( true );
  objProfit = new KPlotObject( Qt::yellow, KPlotObject::Bars, KPlotObject::Star);
  ui_mainview.plotProfit->addPlotObject( objProfit );
  ui_mainview.plotProfit->axis( KPlotWidget::BottomAxis )->setLabel( i18n("%1", mes) );
  ui_mainview.plotProfit->axis( KPlotWidget::LeftAxis )->setLabel( i18n("Month Profit (%1)", KGlobal::locale()->currencySymbol()) );

  ui_mainview.plotMostSold->setMinimumSize( 200, 200 );
  ui_mainview.plotMostSold->setAntialiasing( true );
  objMostSold  = new KPlotObject( Qt::white, KPlotObject::Bars, KPlotObject::Star);
  objMostSoldB = new KPlotObject( Qt::green, KPlotObject::Bars, KPlotObject::Star);
  ui_mainview.plotMostSold->addPlotObject( objMostSold  );
  ui_mainview.plotMostSold->addPlotObject( objMostSoldB );
  ui_mainview.plotMostSold->axis( KPlotWidget::BottomAxis )->setLabel( i18n("Products") );
  ui_mainview.plotMostSold->axis( KPlotWidget::LeftAxis )->setLabel( i18n("Sold Units") );
  objMostSold->setShowBars(true);
  objMostSold->setShowPoints(true);
  objMostSold->setShowLines(false);
  objMostSoldB->setShowBars(true);
  objMostSoldB->setShowPoints(true);
  objMostSoldB->setShowLines(false);
  ui_mainview.plotMostSold->setShowGrid(false);
  objMostSold->setBarBrush( QBrush( Qt::blue, Qt::SolidPattern ) );
  objMostSold->setBarPen(QPen(Qt::white));
  objMostSold->setPointStyle(KPlotObject::Star);
  objMostSoldB->setBarBrush( QBrush( Qt::darkYellow, Qt::SolidPattern ) );
  objMostSoldB->setBarPen(QPen(Qt::white));
  objMostSoldB->setPointStyle(KPlotObject::Star);

  objSales->setShowBars(true);
  objSales->setShowPoints(true);
  objSales->setShowLines(true);
  objSales->setLinePen( QPen( Qt::blue, 1.5, Qt::DashDotLine ) );
  objSales->setBarBrush( QBrush( Qt::lightGray, Qt::Dense6Pattern ) );
  objSales->setBarPen(QPen(Qt::lightGray));
  objSales->setPointStyle(KPlotObject::Star);

  objProfit->setShowBars(true);
  objProfit->setShowPoints(true);
  objProfit->setShowLines(true);
  objProfit->setLinePen( QPen( Qt::blue, 1.5, Qt::DashDotLine ) );
  objProfit->setBarBrush( QBrush( Qt::lightGray, Qt::Dense7Pattern ) );
  objProfit->setBarPen(QPen(Qt::lightGray));
  objProfit->setPointStyle(KPlotObject::Star);
  
  graphSoldItemsCreated = true;
  updateGraphs();
}


// UI and Database -- GRAPHS.
void squeezeView::updateGraphs()
{
  if (!db.isOpen()) openDB();
  if (db.isOpen()) {
    if (!graphSoldItemsCreated ) setupGraphs();
    else {
      Azahar *myDb = new Azahar(this);
      myDb->setDatabase(db);
      ///First we need to get data for the plots
      QList<TransactionInfo> monthTrans = myDb->getMonthTransactionsForPie();
      ProfitRange rangeP = myDb->getMonthProfitRange();
      ProfitRange rangeS = myDb->getMonthSalesRange();
      //qDebug()<<"** [Ranges] Profit:"<<rangeP.min<<","<<rangeP.max<<" Sales:"<<rangeS.min<<","<<rangeS.max;
      TransactionInfo info;
      ///plots
      //clear data
      objSales->clearPoints();
      objProfit->clearPoints();
      // X = date, Y=profit
      int hoy=0;
      hoy = QDate::currentDate().day();

      //NOTE:Set the same scale for both plots?? to compare.. or his own range to each one. if profit>sales?
      ui_mainview.plotSales->setLimits(0, hoy+1, rangeS.min-rangeS.min*.10, rangeS.max+rangeS.max*.10);
      ui_mainview.plotProfit->setLimits(0, hoy+1, rangeP.min-rangeS.min*.10, rangeP.max+rangeP.max*.10);
      //insert each day's sales and profit.
      int day=0; double AccSales=0.0; double AccProfit=0.0;
      //BEGIN Fix old issue. This is to fix the not shown values, the first and last days are not shown, fixed by adding day 0 and one after the last.
      objSales->addPoint(0,0, "0");
      objProfit->addPoint(0,0, "0");
      if (!monthTrans.isEmpty()) {
        TransactionInfo inf;
        inf.date = monthTrans.last().date.addDays(1);
        inf.amount = 0;
        inf.utility = 0;
        monthTrans.append(inf);
      }
      //END Fix old issue.
      for (int i = 0; i < monthTrans.size(); ++i) {
        info = monthTrans.at(i);
        ///we got one result per day (sum)
        //insert the day,profit to the plot
        AccSales  = info.amount;
        AccProfit = info.utility;
        day       = info.date.day();
        objSales->addPoint(day,AccSales, QString::number(AccSales));
        objProfit->addPoint(day,AccProfit, QString::number(AccProfit));
        //qDebug()<<"ITERATING MONTH TRANSACTIONS  |  "<<day<<", sales:"<<info.amount<<" profit:"<<info.utility<<" AccSales:"<<AccSales<<" AccProfit:"<<AccProfit;
      } //for each eleement
      

      ui_mainview.plotSales->update();
      ui_mainview.plotProfit->update();

      //MOST SOLD PRODUCTS
      objMostSold->clearPoints();
      objMostSoldB->clearPoints();
      QList<pieProdInfo> plist = myDb->getTop5SoldProducts();
      double maxPoint = myDb->getTopFiveMaximum();
      if (maxPoint < 4 ) maxPoint = maxPoint+1;
      ui_mainview.plotMostSold->setLimits(0, 7, 0, maxPoint+maxPoint*.10);

       if (!plist.isEmpty()) {
         if (!graphSoldItemsCreated) setupGraphs();
         else {
           int count = 0;
           foreach(pieProdInfo ppInfo, plist) {
             count++;
             objMostSold->addPoint(count, ppInfo.count, ppInfo.name);
             //if (count==2) objMostSoldB->addPoint(count, ppInfo.count, ppInfo.name);
             //qDebug()<<"# "<<count<<"product Count:"<<ppInfo.count<<" Name:"<<ppInfo.name;
           } //foreach
           objMostSold->addPoint(6,0,""); // workaround!
         }//else
       }

      //NOW ALMOST SOLD OUT PRODUCTS (top 5)
      maxPoint = myDb->getAlmostSoldOutMaximum(Settings::mostSoldMaxValue());
      plist    = myDb->getAlmostSoldOutProducts(Settings::mostSoldMaxValue());

      if (!plist.isEmpty()) {
        if (!graphSoldItemsCreated) setupGraphs();
        else {
          int count = 0;
          foreach(pieProdInfo ppInfo, plist) {
            count++;
            switch (count) {
             case 1:
              ui_mainview.lblProd1->setText(ppInfo.name+QString(" [%1]").arg(ppInfo.code));
               ui_mainview.counter1->setText(QString::number(ppInfo.count)+" "+ppInfo.unitStr);
               break;
             case 2:
               ui_mainview.lblProd2->setText(ppInfo.name+QString(" [%1]").arg(ppInfo.code));
               ui_mainview.counter2->setText(QString::number(ppInfo.count)+" "+ppInfo.unitStr);
               break;
             case 3:
               ui_mainview.lblProd3->setText(ppInfo.name+QString(" [%1]").arg(ppInfo.code));
               ui_mainview.counter3->setText(QString::number(ppInfo.count)+" "+ppInfo.unitStr);
               break;
             case 4:
               ui_mainview.lblProd4->setText(ppInfo.name+QString(" [%1]").arg(ppInfo.code));
               ui_mainview.counter4->setText(QString::number(ppInfo.count)+" "+ppInfo.unitStr);
               break;
             case 5:
               ui_mainview.lblProd5->setText(ppInfo.name+QString(" [%1]").arg(ppInfo.code));
               ui_mainview.counter5->setText(QString::number(ppInfo.count)+" "+ppInfo.unitStr);
               break;
             }
          } //foreach
        }//else
      } //if not empty

      delete myDb;
    }
  } // if connected to db
}


/*  ----------------- Database ----------------- */
void squeezeView::setupDb()
{
  if (db.isOpen()) db.close();
  db.setHostName(Settings::editDBServer());
  db.setDatabaseName(Settings::editDBName());
  db.setUserName(Settings::editDBUsername());
  db.setPassword(Settings::editDBPassword());
  db.open();
  dlgPassword->setDb(db);
  if (db.isOpen()) {
    emit signalConnected();
    enableUI(); //enable until logged in...
    productsModel   = new QSqlRelationalTableModel();
    offersModel     = new QSqlRelationalTableModel();
    usersModel      = new QSqlTableModel();
    measuresModel   = new QSqlTableModel();
    departmentsModel = new QSqlTableModel();
    categoriesModel = new QSqlTableModel();
    subcategoriesModel = new QSqlRelationalTableModel();
    clientsModel    = new QSqlTableModel();
    transactionsModel = new QSqlRelationalTableModel();
    balancesModel   = new QSqlTableModel();
    cashflowModel   = new QSqlRelationalTableModel();
    specialOrdersModel   = new QSqlRelationalTableModel();
    randomMsgModel  = new QSqlTableModel();
    logsModel       = new QSqlRelationalTableModel();
    reservationsModel = new QSqlRelationalTableModel();
    currenciesModel = new QSqlTableModel();
    modelsCreated   = true;
    setupProductsModel();
    setupMeasuresModel();
    setupClientsModel();
    setupUsersModel();
    setupTransactionsModel();
    setupCategoriesModel();
    setupDepartmentsModel();
    setupSubCategoriesModel();
    setupOffersModel();
    setupBalancesModel();
    setupCashFlowModel();
    setupSpecialOrdersModel();
    setupRandomMsgModel();
    setupLogsModel();
    setupCurrenciesModel();
    setupReservationsModel();
  } else {
    emit signalDisconnected();
    disableUI();
  }
}

void squeezeView::openDB()
{
 bool ok=false;
  if (!db.isOpen()) {
   ok = db.open();
  } else ok = true;

  if (!ok) {
   emit signalDisconnected();
   qDebug()<<db.lastError();
  } else {
    emit signalConnected();
    if (!modelsAreCreated()) setupDb();
  }
}

void squeezeView::connectToDb()
{
  if (!db.open()) {
    db.open(); //try to open connection
    qDebug()<<"(1/connectToDb) Trying to open connection to database..";
    emit signalDisconnected();
    disableUI();
  }
  if (!db.isOpen()) {
    qDebug()<<"(2/connectToDb) Configuring..";
    emit signalDisconnected();
    disableUI();
  } else {
    //finally, when connection stablished, setup all models.
    if (!modelsCreated) { //Create models...
      productsModel   = new QSqlRelationalTableModel();
      offersModel     = new QSqlRelationalTableModel();
      usersModel      = new QSqlTableModel();
      measuresModel   = new QSqlTableModel();
      categoriesModel = new QSqlTableModel();
      departmentsModel = new QSqlTableModel();
      subcategoriesModel = new QSqlRelationalTableModel();
      clientsModel    = new QSqlTableModel();
      transactionsModel = new QSqlRelationalTableModel();
      balancesModel   = new QSqlTableModel();
      cashflowModel   = new QSqlRelationalTableModel();
      specialOrdersModel   = new QSqlRelationalTableModel();
      randomMsgModel  = new QSqlTableModel();
      logsModel       = new QSqlRelationalTableModel();
      currenciesModel = new QSqlTableModel();
      reservationsModel = new QSqlRelationalTableModel();
      modelsCreated = true;
    }
    dlgPassword->setDb(db);
    emit signalConnected();
    enableUI();
    setupProductsModel();
    setupMeasuresModel();
    setupClientsModel();
    setupUsersModel();
    setupTransactionsModel();
    setupCategoriesModel();
    setupDepartmentsModel();
    setupSubCategoriesModel();
    setupOffersModel();
    setupBalancesModel();
    setupCashFlowModel();
    setupSpecialOrdersModel();
    setupRandomMsgModel();
    setupLogsModel();
    setupCurrenciesModel();
    setupReservationsModel();
  }
}


//NOTE:There is a problem if connected and then mysql stop... db.isOpen() returns true.
void squeezeView::checkDBStatus()
{
 if (!isConnected()) {
  if (counter < 4) {
    counter++;
    emit signalChangeStatusbar(i18n("Trying connection in %1 seconds...", 5-counter));
  }
  else {
    counter = 0;
    emit signalChangeStatusbar(i18n("Connecting..."));
    openDB();
  }
 } else emit signalChangeStatusbar("");
}

void squeezeView::closeDB()
{
  db.close();
}

void squeezeView::setupUsersModel()
{
  if (db.isOpen()) {
    usersModel->setTable("users");

    ui_mainview.usersView->setModel(usersModel);
    ui_mainview.usersView->setViewMode(QListView::IconMode);
    ui_mainview.usersView->setGridSize(QSize(170,170));
    ui_mainview.usersView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui_mainview.usersView->setResizeMode(QListView::Adjust);
    ui_mainview.usersView->setModelColumn(usersModel->fieldIndex("photo"));
    ui_mainview.usersView->setSelectionMode(QAbstractItemView::SingleSelection);


    UsersDelegate *delegate = new UsersDelegate(ui_mainview.usersView);
    ui_mainview.usersView->setItemDelegate(delegate);

    usersModel->select();

  }
  else {
      //At this point, what to do?
     // inform to the user about the error and finish app  or retry again some time later?
    QString details = db.lastError().text();
    KMessageBox::detailedError(this, i18n("Squeeze has encountered an error, click details to see the error details."), details, i18n("Error"));
    QTimer::singleShot(10000, this, SLOT(setupUsersModel()));
  }
}

void squeezeView::setupProductsModel()
{
  openDB();
  qDebug()<<"setupProducts..";
  if (db.isOpen()) {
    productsModel->setTable("products");

    productCodeIndex = productsModel->fieldIndex("code");
    productDescIndex = productsModel->fieldIndex("name");
    productPriceIndex= productsModel->fieldIndex("price");
    productStockIndex= productsModel->fieldIndex("stockqty");
    productCostIndex = productsModel->fieldIndex("cost");
    productSoldUnitsIndex= productsModel->fieldIndex("soldunits");
    productLastSoldIndex= productsModel->fieldIndex("datelastsold");
    productUnitsIndex= productsModel->fieldIndex("units");
    productTaxIndex = productsModel->fieldIndex("taxpercentage");
    productETaxIndex= productsModel->fieldIndex("extrataxes");
    productPhotoIndex=productsModel->fieldIndex("photo");
    productCategoryIndex=productsModel->fieldIndex("category");
    productPointsIndex=productsModel->fieldIndex("points");
    productLastProviderIndex = productsModel->fieldIndex("lastproviderid");
    productAlphaCodeIndex = productsModel->fieldIndex("alphacode");
    productIsAGroupIndex  = productsModel->fieldIndex("isAGroup");
    productIsARawIndex    = productsModel->fieldIndex("isARawProduct");
    productIsNotDiscountable = productsModel->fieldIndex("isNotDiscountable");
    productGEIndex        = productsModel->fieldIndex("groupElements");


    ui_mainview.productsView->setModel(productsModel);
    ui_mainview.productsView->setViewMode(QListView::IconMode);
    ui_mainview.productsView->setGridSize(QSize(170,170));
    ui_mainview.productsView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui_mainview.productsView->setResizeMode(QListView::Adjust);
    ui_mainview.productsView->setModelColumn(productsModel->fieldIndex("photo"));

    ui_mainview.productsViewAlt->setModel(productsModel);
    ui_mainview.productsViewAlt->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui_mainview.productsViewAlt->setSelectionMode(QAbstractItemView::SingleSelection);

    ui_mainview.productsViewAlt->setColumnHidden(productPhotoIndex, true);
    ui_mainview.productsViewAlt->setColumnHidden(productUnitsIndex, true);
    ui_mainview.productsViewAlt->setColumnHidden(productTaxIndex, true);
    ui_mainview.productsViewAlt->setColumnHidden(productETaxIndex, true);
    ui_mainview.productsViewAlt->setColumnHidden(productPointsIndex, true);
    ui_mainview.productsViewAlt->setColumnHidden(productGEIndex, true);
    ui_mainview.productsViewAlt->setColumnHidden(productIsAGroupIndex, true);
    ui_mainview.productsViewAlt->setColumnHidden(productIsARawIndex, true);
    ui_mainview.productsViewAlt->setColumnHidden(productIsNotDiscountable, true);

    /// 0.7 version : hidden next columns
    ui_mainview.productsViewAlt->setColumnHidden(productLastProviderIndex, true);
    ui_mainview.productsViewAlt->setColumnHidden(productAlphaCodeIndex, true);

    productsModel->setRelation(productCategoryIndex, QSqlRelation("categories", "catid", "text"));
    productsModel->setRelation(productLastProviderIndex, QSqlRelation("providers", "id", "name"));

    productsModel->setHeaderData(productCodeIndex, Qt::Horizontal, i18n("Code"));
    productsModel->setHeaderData(productDescIndex, Qt::Horizontal, i18n("Name"));
    productsModel->setHeaderData(productCategoryIndex, Qt::Horizontal, i18n("Category") );
    productsModel->setHeaderData(productPriceIndex, Qt::Horizontal, i18n("Price") );
    productsModel->setHeaderData(productCostIndex, Qt::Horizontal, i18n("Cost") );
    productsModel->setHeaderData(productStockIndex, Qt::Horizontal, i18n("Stock Qty") );
    productsModel->setHeaderData(productSoldUnitsIndex, Qt::Horizontal, i18n("Sold Units") );
    productsModel->setHeaderData(productLastSoldIndex, Qt::Horizontal, i18n("Last Sold") );
    productsModel->setHeaderData(productLastProviderIndex, Qt::Horizontal, i18n("Last Provider") );
    productsModel->setHeaderData(productAlphaCodeIndex, Qt::Horizontal, i18n("Alpha Code") );
    
    ProductDelegate *delegate = new ProductDelegate(ui_mainview.productsView);
    ui_mainview.productsView->setItemDelegate(delegate);
    ui_mainview.productsView->setSelectionMode(QAbstractItemView::SingleSelection);

    productsModel->select();
    ui_mainview.productsViewAlt->resizeColumnsToContents();

    //populate Categories...
    populateCategoriesHash();
    populateSubCategoriesHash();
    populateDepartmentsHash();
    ui_mainview.comboProductsFilterByCategory->clear();
    ui_mainview.comboProductsFilterBySubCategory->clear();
    ui_mainview.comboProductsFilterByDepartment->clear();
    QHashIterator<QString, int> item(categoriesHash);
    while (item.hasNext()) {
      item.next();
      ui_mainview.comboProductsFilterByCategory->addItem(item.key());
    }
    ui_mainview.comboProductsFilterByCategory->setCurrentIndex(0);

    //populate SubCategories...
    QHashIterator<QString, int> itemS(subcategoriesHash);
    while (itemS.hasNext()) {
        itemS.next();
        ui_mainview.comboProductsFilterBySubCategory->addItem(itemS.key());
    }
    ui_mainview.comboProductsFilterBySubCategory->setCurrentIndex(0);
      
    QHashIterator<QString, int> itemD(departmentsHash);
    while (itemD.hasNext()) {
      itemD.next();
      ui_mainview.comboProductsFilterByDepartment->addItem(itemD.key());
    }
    ui_mainview.comboProductsFilterByDepartment->setCurrentIndex(0);

    ui_mainview.rbProductsFilterByAvailable->setChecked(true);
    ui_mainview.productsViewAlt->setCurrentIndex(productsModel->index(0, 0));
    setProductsFilter();
 }
 qDebug()<<"setupProducts.. done.";
}

void squeezeView::populateDepartmentsHash()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  departmentsHash.clear();
  departmentsHash = myDb->getDepartmentsHash();
  delete myDb;
}

void squeezeView::populateCategoriesHash()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  categoriesHash.clear();
  categoriesHash = myDb->getCategoriesHash();
  delete myDb;
}

void squeezeView::populateCardTypesHash()
{
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    cardTypesHash.clear();
    cardTypesHash = myDb->getCardTypesHash();
    delete myDb;
}

void squeezeView::populateSubCategoriesHash()
{
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    subcategoriesHash.clear();
    subcategoriesHash = myDb->getSubCategoriesHash();
    delete myDb;
}

void squeezeView::setProductsFilter()
{
//NOTE: This is a QT BUG.
//   If filter by description is selected and the text is empty, and later is re-filtered
//   then NO pictures are shown; even if is refiltered again.
QRegExp regexp = QRegExp(ui_mainview.editProductsFilterByDesc->text());
if (!ui_mainview.groupFilterProducts->isChecked()) productsModel->setFilter("");
else {
  if (ui_mainview.rbProductsFilterByDesc->isChecked()) {
  //1st if: Filter by DESC.
    if (!regexp.isValid())  ui_mainview.editProductsFilterByDesc->setText("");
    if (ui_mainview.editProductsFilterByDesc->text()=="*" || ui_mainview.editProductsFilterByDesc->text()=="") productsModel->setFilter("");
    else  productsModel->setFilter(QString("products.name REGEXP '%1'").arg(ui_mainview.editProductsFilterByDesc->text()));
    productsModel->setSort(productStockIndex, Qt::DescendingOrder);
  }
  else if (ui_mainview.rbProductsFilterByAvailable->isChecked()) {
  //3rd if: filter by Available items
    productsModel->setFilter(QString("products.stockqty>0"));
    productsModel->setSort(productStockIndex, Qt::DescendingOrder);
  }
  else if (ui_mainview.rbProductsFilterByNotAvailable->isChecked()) {
  //4th if: filter by NOT Available items
    productsModel->setFilter(QString("products.stockqty=0"));
    productsModel->setSort(productSoldUnitsIndex, Qt::DescendingOrder);
  }
  else if (ui_mainview.rbProductsFilterByMostSold->isChecked()) {
  //5th if: filter by Most Sold items
    productsModel->setFilter("");
    productsModel->setSort(productSoldUnitsIndex, Qt::DescendingOrder);
  }
  else if (ui_mainview.rbProductsFilterByAlmostSoldOut->isChecked()) {
    //6th if: filter by ALMOST sold-out items
    productsModel->setFilter(QString("products.stockqty<%1 AND products.stockqty>0").arg(Settings::mostSoldMaxValue()));
    productsModel->setSort(productSoldUnitsIndex, Qt::AscendingOrder);
  }
  else if (ui_mainview.rbProductsFilterByRaw->isChecked()) {
    //7th if: filter by raw products
    productsModel->setFilter(QString("products.isARawProduct=true"));
    productsModel->setSort(productCodeIndex, Qt::AscendingOrder);
  }
  else if (ui_mainview.rbProductsFilterByGroup->isChecked()) {
    //8th if: filter by GROUPS
    productsModel->setFilter(QString("products.isAGroup=true"));
    productsModel->setSort(productCodeIndex, Qt::AscendingOrder);
  }
  else if (ui_mainview.rbProductsFilterByLessSold->isChecked()) {
  //else: filter by less sold items
    productsModel->setFilter("");
    productsModel->setSort(productSoldUnitsIndex, Qt::AscendingOrder);
  }
  else {  //if (ui_mainview.rbProductsFilterByDepartment->isChecked()) {
    //Filter by DEPARTMENT/CATEGORY/SUBCATEGORY
    qDebug()<<"Last check, Department/Category/Subcategory filter";
    bool chained = ui_mainview.chChainiedFilterForCategories->isChecked();
    bool depChecked = ui_mainview.rbProductsFilterByDepartment->isChecked();
    bool catChecked = ui_mainview.rbProductsFilterByCategory->isChecked();
    //NOTE:NOT NEEDED. bool subChecked = ui_mainview.rbProductsFilterBySubCategory->isChecked();
    //Find catId for the text on the combobox.
    int depId=-1;
    int catId=-1;
    int subCatId=-1;
    QString depText = ui_mainview.comboProductsFilterByDepartment->currentText();
    QString catText = ui_mainview.comboProductsFilterByCategory->currentText();
    QString subCatText = ui_mainview.comboProductsFilterBySubCategory->currentText();
    
    //enable/disable the chainedFilter checkbox (only allow on dep/cat checkbox is checked; subcat does not has children.
    ui_mainview.chChainiedFilterForCategories->setEnabled( depChecked || catChecked );
    
    if (categoriesHash.contains(catText))
      catId = categoriesHash.value(catText);
    if (departmentsHash.contains(depText))
      depId = departmentsHash.value(depText);
    if (subcategoriesHash.contains(subCatText))
      subCatId = subcategoriesHash.value(subCatText);
    
    QString qryStr;
    //check if chained filter for dep/cat/subcat is checked. Then we will AND the query filter.
    if (chained) {
      //if department is checked then chain dep->cat->subcat
      if (depChecked) 
	qryStr = QString("products.department=%1 AND products.category=%2 AND products.subcategory=%3").arg(depId).arg(catId).arg(subCatId);
      //if category is checked then chain cat->subcat
      else if (catChecked)
	qryStr = QString("products.category=%1 and products.subcategory=%2").arg(catId).arg(subCatId);
      //if subcat is checked then nothing is chained (subcat has no children)
      else
	qryStr = QString("products.category=%1").arg(catId);
    } //if chained filters
    else {
      if (depChecked)
	qryStr = QString("products.department=%1").arg(depId);
      else if (catChecked)
	qryStr = QString("products.category=%1").arg(catId);
      else
	qryStr = QString("products.subcategory=%1").arg(subCatId);
    }// no chained filters.. check only the selected one.
    
    qDebug()<<"Setting Filter:"<<qryStr;
    productsModel->setFilter(qryStr);
    productsModel->setSort(productStockIndex, Qt::DescendingOrder);
  } //filter by category

  //enable/disable the chainedFilter checkbox (only allow on dep/cat checkbox is checked; subcat does not has children.
  bool depChecked = ui_mainview.rbProductsFilterByDepartment->isChecked();
  bool catChecked = ui_mainview.rbProductsFilterByCategory->isChecked();
  ui_mainview.chChainiedFilterForCategories->setEnabled( depChecked || catChecked );
    
  productsModel->select();
 }
}

void squeezeView::setupOffersModel()
{
  offersModel->setTable("offers");
  offersModel->setEditStrategy(QSqlTableModel::OnFieldChange);

  offerIdIndex       = offersModel->fieldIndex("id");
  offerProdIdIndex   = offersModel->fieldIndex("product_id");
  offerDiscountIndex = offersModel->fieldIndex("discount");
  offerDateStartIndex= offersModel->fieldIndex("datestart");
  offerDateEndIndex  = offersModel->fieldIndex("dateend");

  offersModel->setRelation(offerProdIdIndex, QSqlRelation("products", "code", "name"));

  offersModel->setHeaderData(offerIdIndex, Qt::Horizontal, i18n("Id"));
  offersModel->setHeaderData(offerProdIdIndex, Qt::Horizontal, i18n("Product Affected"));
  offersModel->setHeaderData(offerDiscountIndex, Qt::Horizontal, i18n("Discount Applied (%)") );
  offersModel->setHeaderData(offerDateStartIndex, Qt::Horizontal, i18n("Valid from") );
  offersModel->setHeaderData(offerDateEndIndex, Qt::Horizontal, i18n("Valid until") );

  ui_mainview.tableBrowseOffers->setModel(offersModel);
  //QSqlRelationalDelegate *itemOffersDelegate = new QSqlRelationalDelegate(ui_mainview.tableBrowseOffers);
  OffersDelegate *itemOffersDelegate = new OffersDelegate(ui_mainview.tableBrowseOffers);
  ui_mainview.tableBrowseOffers->setItemDelegate(itemOffersDelegate);

  ui_mainview.tableBrowseOffers->setColumnHidden(offerIdIndex, true);

  offersModel->select();
  setOffersFilter();

  ui_mainview.tableBrowseOffers->setSelectionMode(QAbstractItemView::SingleSelection);

//    connect(ui_mainview.tableBrowseOffers->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
//            this, SLOT(offersTableSelectionChanged(QModelIndex)));
//   connect(ui_mainview.tableBrowseOffers->horizontalHeader(), SIGNAL(sectionClicked(int )),
//           this, SLOT(offerTableHeaderClicked(int)));
//   connect(offersModel, SIGNAL(modelReset()), this, SLOT(onOffersModelReset()) );

  ui_mainview.tableBrowseOffers->setCurrentIndex(offersModel->index(0, 0));
}

void squeezeView::setupMeasuresModel()
{
  if (db.isOpen()) {
    measuresModel->setTable("measures");
    measuresModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    measuresModel->setHeaderData(measuresModel->fieldIndex("text"), Qt::Horizontal, i18n("Description"));

    ui_mainview.tableMeasures->setModel(measuresModel);
    ui_mainview.tableMeasures->setSelectionMode(QAbstractItemView::SingleSelection);
    ui_mainview.tableMeasures->setColumnHidden(measuresModel->fieldIndex("id"), true);
    ui_mainview.tableMeasures->setItemDelegate(new QItemDelegate(ui_mainview.tableMeasures));

    measuresModel->select();
    ui_mainview.tableMeasures->setCurrentIndex(measuresModel->index(0, 0));

  }
  else {
      //At this point, what to do?
     // inform to the user about the error and finish app  or retry again some time later?
    QString details = db.lastError().text();
    KMessageBox::detailedError(this, i18n("Squeeze has encountered an error, click details to see the error details."), details, i18n("Error"));
    QTimer::singleShot(10000, this, SLOT(setupMeasuresModel()));
  }
}

void squeezeView::setupCategoriesModel()
{
  if (db.isOpen()) {
    categoriesModel->setTable("categories");
    categoriesModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    categoriesModel->setHeaderData(categoriesModel->fieldIndex("text"), Qt::Horizontal, i18n("Description"));

    ui_mainview.tableCategories->setModel(categoriesModel);
    ui_mainview.tableCategories->setSelectionMode(QAbstractItemView::SingleSelection);
    ui_mainview.tableCategories->setColumnHidden(categoriesModel->fieldIndex("catid"), true);
    //ui_mainview.tableCategories->setItemDelegate(new QItemDelegate(ui_mainview.tableCategories));

    categoriesModel->select();
    ui_mainview.tableCategories->setCurrentIndex(categoriesModel->index(0, 0));
    // BFB: Adjust column width to content
    ui_mainview.tableCategories->resizeColumnsToContents();

  }
  else {
      //At this point, what to do?
     // inform to the user about the error and finish app  or retry again some time later?
    QString details = db.lastError().text();
    KMessageBox::detailedError(this, i18n("Squeeze has encountered an error, click details to see the error details."), details, i18n("Error"));
    QTimer::singleShot(10000, this, SLOT(setupCategoriesModel()));
  }
}

void squeezeView::setupDepartmentsModel()
{
    if (db.isOpen()) {
        departmentsModel->setTable("departments");
        departmentsModel->setEditStrategy(QSqlTableModel::OnFieldChange);
        departmentsModel->setHeaderData(departmentsModel->fieldIndex("text"), Qt::Horizontal, i18n("Description"));
        
        ui_mainview.tableDepartments->setModel(departmentsModel);
        ui_mainview.tableDepartments->setSelectionMode(QAbstractItemView::SingleSelection);
        ui_mainview.tableDepartments->setColumnHidden(departmentsModel->fieldIndex("id"), true);
        //ui_mainview.tableDepartments->setItemDelegate(new QItemDelegate(ui_mainview.tableDepartments));
        
        departmentsModel->select();
        ui_mainview.tableDepartments->setCurrentIndex(departmentsModel->index(0, 0));
        // BFB: Adjust column width to content
        ui_mainview.tableDepartments->resizeColumnsToContents();
        
    }
    else {
        //At this point, what to do?
        // inform to the user about the error and finish app  or retry again some time later?
        QString details = db.lastError().text();
        KMessageBox::detailedError(this, i18n("Squeeze has encountered an error, click details to see the error details."), details, i18n("Error"));
        QTimer::singleShot(10000, this, SLOT(setupCategoriesModel()));
    }
}

void squeezeView::setupSubCategoriesModel()
{
    if (db.isOpen()) {
        subcategoriesModel->setTable("subcategories");
        subcategoriesModel->setEditStrategy(QSqlTableModel::OnFieldChange);
        subcategoriesModel->setHeaderData(subcategoriesModel->fieldIndex("text"), Qt::Horizontal, i18n("Description"));
        
        ui_mainview.tableSubCategories->setModel(subcategoriesModel);
        ui_mainview.tableSubCategories->setSelectionMode(QAbstractItemView::SingleSelection);
        ui_mainview.tableSubCategories->setColumnHidden(subcategoriesModel->fieldIndex("id"), true);
        //ui_mainview.tableSubCategories->setColumnHidden(subcategoriesModel->fieldIndex("parent"), true);
        ui_mainview.tableSubCategories->setItemDelegate(new QItemDelegate(ui_mainview.tableSubCategories));
        
        subcategoriesModel->setRelation(subcategoriesModel->fieldIndex("parent"), QSqlRelation("categories", "catid", "text"));
        subcategoriesModel->setHeaderData(subcategoriesModel->fieldIndex("parent"), Qt::Horizontal, i18n("Parent Category"));
        //NOTE: The problem with relations is that parent must point to an existent category, 0/NULL makes to show NOTHING in the table.
        ui_mainview.tableSubCategories->setItemDelegate(new QSqlRelationalDelegate(ui_mainview.tableSubCategories));
        
        subcategoriesModel->select();
        ui_mainview.tableSubCategories->setCurrentIndex(subcategoriesModel->index(0, 0));
        ui_mainview.tableSubCategories->resizeColumnsToContents();
        
    }
    else {
        //At this point, what to do?
        // inform to the user about the error and finish app  or retry again some time later?
        QString details = db.lastError().text();
        KMessageBox::detailedError(this, i18n("Squeeze has encountered an error, click details to see the error details."), details, i18n("Error"));
        QTimer::singleShot(10000, this, SLOT(setupSubCategoriesModel()));
    }
}


void squeezeView::setupClientsModel()
{
  if (db.isOpen()) {
    clientsModel->setTable("clients");
    ui_mainview.clientsView->setViewMode(QListView::IconMode);
    ui_mainview.clientsView->setGridSize(QSize(170,170));
    ui_mainview.clientsView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui_mainview.clientsView->setResizeMode(QListView::Adjust);
    ui_mainview.clientsView->setModel(clientsModel);
    ui_mainview.clientsView->setModelColumn(clientsModel->fieldIndex("photo"));
    ui_mainview.clientsView->setSelectionMode(QAbstractItemView::SingleSelection);

    UsersDelegate *delegate = new UsersDelegate(ui_mainview.clientsView);
    ui_mainview.clientsView->setItemDelegate(delegate);

    clientsModel->select();
    ui_mainview.clientsView->setCurrentIndex(clientsModel->index(0, 0));

  }
  else {
      //At this point, what to do?
     // inform to the user about the error and finish app  or retry again some time later?
    QString details = db.lastError().text();
    KMessageBox::detailedError(this, i18n("Squeeze has encountered an error, click details to see the error details."), details, i18n("Error"));
    QTimer::singleShot(10000, this, SLOT(setupClientsModel()));
  }
}

void squeezeView::setupTransactionsModel()
{
  openDB();
  qDebug()<<"setupTransactions..";
  if (db.isOpen()) {
    transactionsModel->setTable("transactions");
    
    transIdIndex = transactionsModel->fieldIndex("id");
    transClientidIndex = transactionsModel->fieldIndex("clientid");
    transTypeIndex= transactionsModel->fieldIndex("type");
    transAmountIndex= transactionsModel->fieldIndex("amount");
    transDateIndex = transactionsModel->fieldIndex("date");
    transTimeIndex= transactionsModel->fieldIndex("time");
    transPaidWithIndex= transactionsModel->fieldIndex("paidwith");
    transChangeGivenIndex= transactionsModel->fieldIndex("changegiven");
    transPayMethodIndex = transactionsModel->fieldIndex("paymethod");
    transStateIndex= transactionsModel->fieldIndex("state");
    transUseridIndex=transactionsModel->fieldIndex("userid");
    transCardNumIndex=transactionsModel->fieldIndex("cardnumber");
    transItemCountIndex=transactionsModel->fieldIndex("itemcount");
    transItemsListIndex=transactionsModel->fieldIndex("itemslist");
    transPointsIndex=transactionsModel->fieldIndex("points");
    transDiscMoneyIndex=transactionsModel->fieldIndex("discmoney");
    transDiscIndex=transactionsModel->fieldIndex("disc");
    transCardAuthNumberIndex=transactionsModel->fieldIndex("cardauthnumber");
    transUtilityIndex=transactionsModel->fieldIndex("utility");
    transTerminalNumIndex=transactionsModel->fieldIndex("terminalnum");
    transProvIdIndex = transactionsModel->fieldIndex("providerid");
    transSOIndex = transactionsModel->fieldIndex("specialOrders");
    int transCardTypeId = transactionsModel->fieldIndex("cardtype"); 

    
    ui_mainview.transactionsTable->setModel(transactionsModel);
    ui_mainview.transactionsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui_mainview.transactionsTable->setColumnHidden(transItemsListIndex, true);
    ui_mainview.transactionsTable->setColumnHidden(transSOIndex, true);

    transactionsModel->setRelation(transTypeIndex, QSqlRelation("transactiontypes", "ttypeid", "text"));
    transactionsModel->setRelation(transStateIndex, QSqlRelation("transactionstates", "stateid", "text"));
    transactionsModel->setRelation(transPayMethodIndex, QSqlRelation("paytypes", "typeid", "text"));
    transactionsModel->setRelation(transClientidIndex, QSqlRelation("clients", "id", "name"));
    transactionsModel->setRelation(transUseridIndex, QSqlRelation("users", "id", "username"));
    transactionsModel->setRelation(transProvIdIndex, QSqlRelation("providers", "id", "name"));
    transactionsModel->setRelation(transCardTypeId, QSqlRelation("cardtypes", "typeid", "text"));
    
    transactionsModel->setHeaderData(transIdIndex, Qt::Horizontal, i18n("Id"));
    transactionsModel->setHeaderData(transClientidIndex, Qt::Horizontal, i18n("Client"));
    transactionsModel->setHeaderData(transTypeIndex, Qt::Horizontal, i18n("Type") );
    transactionsModel->setHeaderData(transAmountIndex, Qt::Horizontal, i18n("Amount") );
    transactionsModel->setHeaderData(transDateIndex, Qt::Horizontal, i18n("Date") );
    transactionsModel->setHeaderData(transTimeIndex, Qt::Horizontal, i18n("Time") );
    transactionsModel->setHeaderData(transPaidWithIndex, Qt::Horizontal, i18n("Paid with") );
    transactionsModel->setHeaderData(transChangeGivenIndex, Qt::Horizontal, i18n("Change Given") );
    transactionsModel->setHeaderData(transPayMethodIndex, Qt::Horizontal, i18n("Pay Method") );
    transactionsModel->setHeaderData(transStateIndex, Qt::Horizontal, i18n("State") );
    transactionsModel->setHeaderData(transUseridIndex, Qt::Horizontal, i18n("Vendor") );
    transactionsModel->setHeaderData(transCardNumIndex, Qt::Horizontal, i18n("Card Num") );
    transactionsModel->setHeaderData(transItemCountIndex, Qt::Horizontal, i18n("Items Count") );
    transactionsModel->setHeaderData(transPointsIndex, Qt::Horizontal, i18n("Points") );
    transactionsModel->setHeaderData(transDiscMoneyIndex, Qt::Horizontal, i18n("Discount %1", KGlobal::locale()->currencySymbol()) );
    transactionsModel->setHeaderData(transDiscIndex, Qt::Horizontal, i18n("Discount %") );
    transactionsModel->setHeaderData(transCardAuthNumberIndex, Qt::Horizontal, i18n("Card Authorization #") );
    transactionsModel->setHeaderData(transUtilityIndex, Qt::Horizontal, i18n("Profit") );
    transactionsModel->setHeaderData(transTerminalNumIndex, Qt::Horizontal, i18n("Terminal #") );
    transactionsModel->setHeaderData(transProvIdIndex, Qt::Horizontal, i18n("Provider") );
    transactionsModel->setHeaderData(transCardTypeId, Qt::Horizontal, i18n("Card Type") );

    ui_mainview.transactionsTable->setColumnHidden(transactionsModel->fieldIndex("totalTax"), true);
    ui_mainview.transactionsTable->setColumnHidden(transactionsModel->fieldIndex("specialOrders"), true);
    ui_mainview.transactionsTable->setColumnHidden(transactionsModel->fieldIndex("itemlist"), true);
    //ui_mainview.transactionsTable->setColumnHidden(transactionsModel->fieldIndex("disc"), true);
    
    ui_mainview.transactionsTable->setSelectionMode(QAbstractItemView::SingleSelection);
    
    transactionsModel->select();
    updateCardTypesCombo();
  }
  qDebug()<<"setupTransactions.. done, "<<transactionsModel->lastError();
}

//FIXME: When filtering by User/Client, we need filter by user or username? and just = or with a regexp or a 'like' search??
void squeezeView::setTransactionsFilter()
{
  //NOTE: This is a QT BUG.
  //   If filter by description is selected and the text is empty, and later is re-filtered
  //   then NO pictures are shown; even if is refiltered again.
  QRegExp regexp;
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  
  if (!ui_mainview.groupFilterTransactions->isChecked()) transactionsModel->setFilter("");
  else {
    if (ui_mainview.rbTransFilterByUser->isChecked()) {
      //1st if: Filter by Users.
      regexp = QRegExp(ui_mainview.editTransUsersFilter->text());
      if (!regexp.isValid() || ui_mainview.editTransUsersFilter->text().isEmpty())  ui_mainview.editTransUsersFilter->setText("*");
      if (ui_mainview.editTransUsersFilter->text()=="*") transactionsModel->setFilter("");
      else {
        unsigned int uid = myDb->getUserId(ui_mainview.editTransUsersFilter->text());
        transactionsModel->setFilter(QString("transactions.userid=%1").arg(uid));
      }
      transactionsModel->setSort(transIdIndex, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbTransFilterByClient->isChecked()) {
      //2nd if: Filter by CLIENTS
      regexp = QRegExp(ui_mainview.editTransClientsFilter->text());
      if (!regexp.isValid() || ui_mainview.editTransClientsFilter->text().isEmpty())  ui_mainview.editTransClientsFilter->setText("");
      if (ui_mainview.editTransClientsFilter->text()=="") transactionsModel->setFilter("");
      else {
        unsigned int cid = myDb->getClientId(ui_mainview.editTransClientsFilter->text());
        transactionsModel->setFilter(QString("transactions.clientid=%1").arg(cid));
      }
      transactionsModel->setSort(transIdIndex, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbTransFilterByStateFinished->isChecked()) {
      //3rd if: filter by FINISHED TRANSACTIONS
      transactionsModel->setFilter(QString("transactions.state=2")); //tCompleted=2
      transactionsModel->setSort(transIdIndex, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbTransFilterByStateCancelled->isChecked()) {
      //4th if: filter by CANCELLED TRANSACTIONS
      transactionsModel->setFilter(QString("transactions.state=3")); //tCancelled=3
      transactionsModel->setSort(transIdIndex, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbTransFilterByPaidCash->isChecked()) {
      //5th if: filter by PAID IN CASH
      transactionsModel->setFilter("transactions.paymethod=1 and transactions.state=2"); // paid in cash and finished
      transactionsModel->setSort(transIdIndex, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbTransFilterByPaidCredit->isChecked()) {
      //6th if: filter by PAID WITH CARD
      QString cardTypeStr = ui_mainview.comboCardTypes->currentText();
      int cardTypeId = cardTypesHash.value(cardTypeStr);
      transactionsModel->setFilter(QString("transactions.paymethod=2 and transactions.state=2 and transactions.cardtype=%1").arg(cardTypeId)); //paid with card and finished only
      transactionsModel->setSort(transIdIndex, Qt::AscendingOrder);
    }
    else if (ui_mainview.rbTransFilterByDate->isChecked()) {
      //7th if: filter by DATE
      QDate date = ui_mainview.transactionsDateEditor->date();
      transactionsModel->setFilter(QString("transactions.date = '%1'").arg(date.toString("yyyy-MM-dd")));
      qDebug()<<"Filtro:"<<transactionsModel->filter();
      transactionsModel->setSort(transIdIndex, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbTransFilterByAmountLess->isChecked()) {
      //6th if: filter by AMOUNT <
      double amo = ui_mainview.editTransAmountLess->value();
      transactionsModel->setFilter(QString("transactions.amount<%1").arg(amo));
      transactionsModel->setSort(transIdIndex, Qt::AscendingOrder);
    }
    else if (ui_mainview.rbTransFilterByAmountGreater->isChecked()) {
      //6th if: filter by AMOUNT >
      double amo = ui_mainview.editTransAmountGreater->value();
      transactionsModel->setFilter(QString("transactions.amount>%1").arg(amo));
      transactionsModel->setSort(transIdIndex, Qt::AscendingOrder);
    }
    //NOTE: in the next 3 ifs, transactions.type=X is hardcoded... I assume the user did not change the default values.
    else if (ui_mainview.rbTransactionsFilterOnlySales->isChecked()) {
      transactionsModel->setFilter("transactions.type=1");
      transactionsModel->setSort(transIdIndex, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbTransactionsFilterOnlyPurchases->isChecked()) {
      transactionsModel->setFilter("transactions.type=2");
      transactionsModel->setSort(transIdIndex, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbTransactionsFilterOnlyChangesReturns->isChecked()) {
      transactionsModel->setFilter("transactions.type=3 OR transactions.type=4");
      transactionsModel->setSort(transIdIndex, Qt::DescendingOrder);
    }
    else {
      //else: filter by terminal number
      unsigned int tnum = ui_mainview.editTransTermNum->value();
      transactionsModel->setFilter(QString("transactions.terminalnum=%1").arg(tnum));
      transactionsModel->setSort(transIdIndex, Qt::AscendingOrder);
    }
    
    transactionsModel->select();
  }
  delete myDb;
}


//CURRENCIES
void squeezeView::setupCurrenciesModel()
{
    if (db.isOpen()) {
        currenciesModel->setTable("currencies");
        currenciesModel->setEditStrategy(QSqlTableModel::OnFieldChange);
        currenciesModel->setHeaderData(currenciesModel->fieldIndex("name"), Qt::Horizontal, i18n("Name"));
        
        ui_mainview.tableCurrencies->setModel(currenciesModel);
        ui_mainview.tableCurrencies->setSelectionMode(QAbstractItemView::SingleSelection);
        ui_mainview.tableCurrencies->setColumnHidden(currenciesModel->fieldIndex("id"), true);
        ui_mainview.tableCurrencies->setItemDelegate(new QItemDelegate(ui_mainview.tableCurrencies));
        
        currenciesModel->select();
        ui_mainview.tableCurrencies->setCurrentIndex(currenciesModel->index(0, 0));
        
    }
    else {
        //At this point, what to do?
        // inform to the user about the error and finish app  or retry again some time later?
        QString details = db.lastError().text();
        KMessageBox::detailedError(this, i18n("Squeeze has encountered an error, click details to see the error details."), details, i18n("Error"));
        QTimer::singleShot(10000, this, SLOT(setupCurrenciesModel()));
    }
}


// BALANCES

void squeezeView::setupBalancesModel()
{
  openDB();
  qDebug()<<"setupBalances.. after openDB";
  if (db.isOpen()) {
    balancesModel->setTable("balances");
    
    balanceIdIndex = balancesModel->fieldIndex("id");
    balanceDateEndIndex = balancesModel->fieldIndex("datetime_end"); //just one date...
    balanceUserNameIndex= balancesModel->fieldIndex("usern");
    balanceInitAmountIndex= balancesModel->fieldIndex("initamount");
    balanceInIndex = balancesModel->fieldIndex("in");
    balanceOutIndex= balancesModel->fieldIndex("out");
    balanceCashIndex= balancesModel->fieldIndex("cash");
    balanceCardIndex= balancesModel->fieldIndex("card");
    balanceTransIndex = balancesModel->fieldIndex("transactions");
    balanceTerminalNumIndex= balancesModel->fieldIndex("terminalnum");
    balanceDateStartIndex=balancesModel->fieldIndex("datetime_start"); //to hide
    balanceUseridIndex=balancesModel->fieldIndex("userid"); //to hide
    
    
    ui_mainview.balancesTable->setModel(balancesModel);
    ui_mainview.balancesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui_mainview.balancesTable->setColumnHidden(balanceDateStartIndex, true);
    ui_mainview.balancesTable->setColumnHidden(balanceUseridIndex, true);
    
    balancesModel->setHeaderData(balanceIdIndex, Qt::Horizontal, i18n("Id"));
    balancesModel->setHeaderData(balanceDateEndIndex, Qt::Horizontal, i18n("Date"));
    balancesModel->setHeaderData(balanceUserNameIndex, Qt::Horizontal, i18n("Vendor") );
    balancesModel->setHeaderData(balanceInitAmountIndex, Qt::Horizontal, i18n("Initial amount") );
    balancesModel->setHeaderData(balanceInIndex, Qt::Horizontal, i18n("In") );
    balancesModel->setHeaderData(balanceOutIndex, Qt::Horizontal, i18n("Out") );
    balancesModel->setHeaderData(balanceCashIndex, Qt::Horizontal, i18n("Cash in drawer") );
    balancesModel->setHeaderData(balanceCardIndex, Qt::Horizontal, i18n("Received by Card") );
    balancesModel->setHeaderData(balanceTransIndex, Qt::Horizontal, i18n("Transactions") );
    balancesModel->setHeaderData(balanceTerminalNumIndex, Qt::Horizontal, i18n("Terminal #") );
    
    
    ui_mainview.balancesTable->setSelectionMode(QAbstractItemView::SingleSelection);
    //     ProductDelegate *delegate = new ProductDelegate(ui_mainview.productsView);
    //     ui_mainview.productsView->setItemDelegate(delegate);
    
    balancesModel->select();
  }
  qDebug()<<"setupBalances.. done.";
}

//FIXME: When filtering by User, we need filter by user or username? and just = or with a regexp or a 'like' search??
void squeezeView::setBalancesFilter()
{
  //NOTE: This is a QT BUG.
  //   If filter by description is selected and the text is empty, and later is re-filtered
  //   then NO pictures are shown; even if is refiltered again.
  
  if (!ui_mainview.groupFilterBalances->isChecked()) balancesModel->setFilter("");
  else {
    if (ui_mainview.rbBalancesFilterByState->isChecked()) {
      //1st if: Filter by NOT EMPTY Transactions on balances
      balancesModel->setFilter(QString("balances.transactions!='EMPTY'"));
      balancesModel->setSort(balanceIdIndex, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbBalancesFilterBySuspicious->isChecked()) {
      //2nd if: Filter by Suspicious balances
      balancesModel->setFilter(QString("balances.initamount+balances.in-balances.out!=balances.cash"));
      balancesModel->setSort(balanceIdIndex, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbBalancesFilterByDate->isChecked()) {
      //3rd if: filter by DATE
      QDate date = ui_mainview.editBalancesFilterByDate->date();
      QDateTime dt = QDateTime(date); //time 00:00:00
      QString dtStr = dt.toString("yyyy-MM-dd hh:mm:ss");
      QString dtStr2= date.toString("yyyy-MM-dd")+" 23:59:59";
      balancesModel->setFilter(QString("balances.datetime_end>='%1' and balances.datetime_end<='%2'").arg(dtStr).arg(dtStr2));
      qDebug()<<"Filtro:"<<balancesModel->filter();
      balancesModel->setSort(balanceIdIndex, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbBalancesFilterByCashInLess->isChecked()) {
      //4th if: filter by CASH IN <
      double amo = ui_mainview.editBalancesFilterByCasInLess->value();
      balancesModel->setFilter(QString("balances.in<%1").arg(amo));
      balancesModel->setSort(balanceIdIndex, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbBalancesFilterByCashInGrater->isChecked()) {
      //5th if: filter by CASH IN >
      double csh = ui_mainview.editBalancesFilterByCashInGrater->value();
      balancesModel->setFilter(QString("balances.in>%1").arg(csh));
      balancesModel->setSort(balanceIdIndex, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbBalancesFilterByUser->isChecked()) {
      //6th if: filter by vendor
      balancesModel->setFilter(QString("balances.usern='%1'").arg(ui_mainview.editBalancesFilterByVendor->text()));
      balancesModel->setSort(balanceIdIndex, Qt::DescendingOrder);
    }
    else {
      //7th else: filter by terminal number
      unsigned int tnum = ui_mainview.editBalancesFilterByTermNum->value();
      balancesModel->setFilter(QString("balances.terminalnum=%1").arg(tnum));
      balancesModel->setSort(balanceIdIndex, Qt::DescendingOrder);
    }
    
    balancesModel->select();
  }
}


// Special Orders

void squeezeView::setupSpecialOrdersModel()
{
  openDB();
  qDebug()<<"setup special orders.. after openDB";
  if (db.isOpen()) {
    specialOrdersModel->setTable("special_orders");

    ///NOTE: Here we can use the v_groupedSO table instead, to group them by saleid
    ///      I dont know how convenient is this.
    
   int soIdIndex = specialOrdersModel->fieldIndex("orderid");
   int soDateIndex = specialOrdersModel->fieldIndex("dateTime");
   int soNameIndex= specialOrdersModel->fieldIndex("name");
   int soGroupElemIndex= specialOrdersModel->fieldIndex("groupElements");
   int soQtyIndex = specialOrdersModel->fieldIndex("qty");
   int soPriceIndex= specialOrdersModel->fieldIndex("price");
   int soCostIndex= specialOrdersModel->fieldIndex("cost");
   int soUnitsIndex= specialOrdersModel->fieldIndex("units");
   int soStatusIndex = specialOrdersModel->fieldIndex("status");
   int soSaleIdIndex= specialOrdersModel->fieldIndex("saleid");
   int soNotesIndex=specialOrdersModel->fieldIndex("notes");
   int soPaymentIndex=specialOrdersModel->fieldIndex("payment");
   int soCompletePaymentIndex=specialOrdersModel->fieldIndex("completePayment");
    
    
    ui_mainview.tableSO->setModel(specialOrdersModel);
    ui_mainview.tableSO->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui_mainview.tableSO->setColumnHidden(soGroupElemIndex, true);
    ui_mainview.tableSO->setColumnHidden(soUnitsIndex, true);

    specialOrdersModel->setHeaderData(soIdIndex, Qt::Horizontal, i18n("Order #"));
    specialOrdersModel->setHeaderData(soNameIndex, Qt::Horizontal, i18n("Name"));
    specialOrdersModel->setHeaderData(soDateIndex, Qt::Horizontal, i18n("Date") );
    specialOrdersModel->setHeaderData(soQtyIndex, Qt::Horizontal, i18n("Qty") );
    specialOrdersModel->setHeaderData(soPriceIndex, Qt::Horizontal, i18n("Price") );
    specialOrdersModel->setHeaderData(soCostIndex, Qt::Horizontal, i18n("Cost") );
    specialOrdersModel->setHeaderData(soUnitsIndex, Qt::Horizontal, i18n("Sold by") );
    specialOrdersModel->setHeaderData(soStatusIndex, Qt::Horizontal, i18n("Status") );
    specialOrdersModel->setHeaderData(soSaleIdIndex, Qt::Horizontal, i18n("Tr. Id") );
    specialOrdersModel->setHeaderData(soNotesIndex, Qt::Horizontal, i18n("Notes") );
    specialOrdersModel->setHeaderData(soPaymentIndex, Qt::Horizontal, i18n("Payment") );
    specialOrdersModel->setHeaderData(soCompletePaymentIndex, Qt::Horizontal, i18n("Payment Complete") );

    //relations
    specialOrdersModel->setRelation(soUnitsIndex, QSqlRelation("measures", "id", "text"));
    specialOrdersModel->setRelation(soStatusIndex, QSqlRelation("so_status", "id", "text"));
    specialOrdersModel->setRelation(soCompletePaymentIndex, QSqlRelation("bool_values", "id", "text"));
    
    ui_mainview.tableSO->setSelectionMode(QAbstractItemView::SingleSelection);
    specialOrdersModel->select();
  }
  qDebug()<<"setup special orders.. done.";
}

void squeezeView::setSpecialOrdersFilter()
{
  if (!ui_mainview.groupSOFilter->isChecked()) specialOrdersModel->setFilter("");
  else {
    if (ui_mainview.rbSOByDate->isChecked()) {
      //1st if: Filter by date
      QDate d = ui_mainview.datePicker->date();
      QDateTime dt = QDateTime(d);
      QString dtStr = dt.toString("yyyy-MM-dd hh:mm:ss");
      QString dtStr2= d.toString("yyyy-MM-dd")+" 23:59:59";
      specialOrdersModel->setFilter(QString("special_orders.dateTime>='%1' and special_orders.dateTime<='%2'").arg(dtStr).arg(dtStr2));
      specialOrdersModel->setSort(12, Qt::DescendingOrder); //by date
    }
    else if (ui_mainview.rbSOByThisWeek->isChecked()) {
      //2nd if: Filter by one week
      specialOrdersModel->setFilter(QString("special_orders.dateTime > ADDDATE(sysdate( ), INTERVAL -8 DAY )"));
      specialOrdersModel->setSort(0, Qt::DescendingOrder); //orderid
    }
    else if (ui_mainview.rbSOByThisMonth->isChecked()) {
      //3rd if: filter by ONE Month
      specialOrdersModel->setFilter(QString("special_orders.dateTime > ADDDATE(sysdate( ), INTERVAL -31 DAY )"));
      specialOrdersModel->setSort(0, Qt::DescendingOrder); //orderid
    }
    else if (ui_mainview.rbSOByStatusPending->isChecked()) {
      //4th if: filter by STATUS PENDING
      specialOrdersModel->setFilter(QString("special_orders.status=0"));
      specialOrdersModel->setSort(0, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbSOByStatusInProgress->isChecked()) {
      //4th if: filter by STATUS IN PROGRESS
      specialOrdersModel->setFilter(QString("special_orders.status=1"));
      specialOrdersModel->setSort(0, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbSOByStatusReady->isChecked()) {
      //4th if: filter by STATUS READY
      specialOrdersModel->setFilter(QString("special_orders.status=2"));
      specialOrdersModel->setSort(0, Qt::DescendingOrder);
    }
    else if (ui_mainview.rbSOByStatusDelivered->isChecked()) {
      //4th if: filter by STATUS DELIVERED
      specialOrdersModel->setFilter(QString("special_orders.status=3"));
      specialOrdersModel->setSort(0, Qt::DescendingOrder);
    }
    else {
      //4th if: filter by STATUS CANCELLED
      specialOrdersModel->setFilter(QString("special_orders.status=4"));
      specialOrdersModel->setSort(0, Qt::DescendingOrder);
    }
    
    specialOrdersModel->select();
  }
}


//reservationsModel
void squeezeView::setupReservationsModel()
{
    if (db.isOpen()) {
        reservationsModel->setTable("reservations");
        reservationsModel->setEditStrategy(QSqlTableModel::OnFieldChange);
        reservationsModel->setHeaderData(reservationsModel->fieldIndex("id"), Qt::Horizontal, i18n("Reservation"));
        reservationsModel->setHeaderData(reservationsModel->fieldIndex("transaction_id"), Qt::Horizontal, i18n("Tr. #"));
        reservationsModel->setHeaderData(reservationsModel->fieldIndex("client_id"), Qt::Horizontal, i18n("Client"));
        reservationsModel->setHeaderData(reservationsModel->fieldIndex("date"), Qt::Horizontal, i18n("Date"));
        reservationsModel->setHeaderData(reservationsModel->fieldIndex("status"), Qt::Horizontal, i18n("Status"));
        reservationsModel->setHeaderData(reservationsModel->fieldIndex("payment"), Qt::Horizontal, i18n("Prepayment"));
        reservationsModel->setHeaderData(reservationsModel->fieldIndex("total"), Qt::Horizontal, i18n("Total"));

        reservationsModel->setRelation(reservationsModel->fieldIndex("client_id"), QSqlRelation("clients", "id", "name"));
        reservationsModel->setRelation(reservationsModel->fieldIndex("status_id"), QSqlRelation("transactionstates", "stateid", "text"));
        
        ui_mainview.tableReservations->setModel(reservationsModel);
        ui_mainview.tableReservations->setSelectionMode(QAbstractItemView::SingleSelection);
        ui_mainview.tableReservations->setColumnHidden(reservationsModel->fieldIndex("totaltaxes"), true);
        ui_mainview.tableReservations->setItemDelegate(new QItemDelegate(ui_mainview.tableReservations));
        
        reservationsModel->select();
        ui_mainview.tableReservations->setCurrentIndex(reservationsModel->index(0, 0));
        
    }
    else {
        //At this point, what to do?
        // inform to the user about the error and finish app  or retry again some time later?
        QString details = db.lastError().text();
        KMessageBox::detailedError(this, i18n("Squeeze has encountered an error, click details to see the error details."), details, i18n("Error"));
        QTimer::singleShot(10000, this, SLOT(setupReservationsModel()));
    }
}


void squeezeView::reservationsOnSelected(const QModelIndex &index)
{
    if (db.isOpen()) {
        //getting data from model...
        const QAbstractItemModel *model = index.model();
        int row = index.row();
        QModelIndex indx = model->index(row, reservationsModel->fieldIndex("id"));
        qulonglong id = model->data(indx, Qt::DisplayRole).toULongLong();

        ReservationInfo rInfo;
        QList<TransactionItemInfo> rItems;
        Azahar *myDb = new Azahar;
        myDb->setDatabase(db);

        rInfo  = myDb->getReservationInfo(id);
        rItems = myDb->getTransactionItems(rInfo.transaction_id);

        delete myDb;

        //Draw the reservation details
        QString text = QString("<b><span style=\" font-size:13pt;\">%1 <br>%2 </span></b><br><br><i>%3</i><br><ul>")
        .arg(tr("Transaction No.%1").arg(rInfo.transaction_id))
        .arg(tr("Reservation No.%1").arg(rInfo.id))
        .arg(tr("Reserved Items:"));
        //get each item
        foreach(TransactionItemInfo item, rItems ) {
            text += QString("<li> %1 x %2</li>").arg(QString::number(item.qty)).arg(item.name);
            //TODO: display nested items if the item is a group
        }
        text += "</ul>";
        ui_mainview.lblReservationDetails->setText(text);
    }
}


/* widgets */

void squeezeView::settingsChanged()
{
  emit signalChangeStatusbar( i18n("Settings changed") );

  db.setHostName(Settings::editDBServer());
  db.setDatabaseName(Settings::editDBName());
  db.setUserName(Settings::editDBUsername());
  db.setPassword(Settings::editDBPassword());

  connectToDb();

  updateGraphs();
}

void squeezeView::settingsChangedOnInitConfig()
{
  qDebug()<<"==> Initial Config Changed- connecting to database and calling login...";
  db.setHostName(Settings::editDBServer());
  db.setDatabaseName(Settings::editDBName());
  db.setUserName(Settings::editDBUsername());
  db.setPassword(Settings::editDBPassword());
  
  connectToDb();
  login();
}


void squeezeView::setOffersFilter()
{
  if (ui_mainview.groupFilterOffers->isChecked()) {
    if (ui_mainview.chOffersFilterByProduct->isChecked()) {
      ui_mainview.editOffersFilterByProduct->setFocus();
      //Get codes and names from offers and products
      QString myFilter;
      QStringList codes;
      QString desc;
      if (ui_mainview.editOffersFilterByProduct->text().isEmpty()) desc = "."; else desc =ui_mainview.editOffersFilterByProduct->text();

      Azahar *myDb = new Azahar;
      myDb->setDatabase(db);
      myFilter = myDb->getOffersFilterWithText(desc);
      delete myDb;

      if (myFilter == "") myFilter = "offers.product_id=0"; //there should not be a product with code=0
      offersModel->setFilter(myFilter);
    }
    else if (ui_mainview.chOffersTodayDiscounts->isChecked()) {
        //Today Offers
        QDate date = QDate::currentDate();
        QString today = date.toString("yyyy-MM-dd");
        offersModel->setFilter(QString(" offers.datestart <= '%1' and offers.dateend >='%1' ").arg(today));
        //offers.datestart between '%1' and '%2' or offers.dateend between %3 and %4
        qDebug()<<"Filtro:"<<offersModel->filter();
    }
    else if (ui_mainview.chOffersSelectDate->isChecked()) {
        //Selected Date Offers
        QDate date = ui_mainview.offersDateEditor->date();
//         offersModel->setFilter(QString("offers.dateend='%1'").arg());
        offersModel->setFilter(QString(" offers.datestart <= '%1' and offers.dateend >='%1' ").arg(date.toString("yyyy-MM-dd")));
        qDebug()<<"Filtro:"<<offersModel->filter();
    }
    else { //old offers, non valid anymore...
        QDate date = QDate::currentDate();
        offersModel->setFilter(QString("offers.dateend<'%1'").arg(date.toString("yyyy-MM-dd")));
        qDebug()<<"Filtro: "<<offersModel->filter();
    }
    //Faltaria las ofertas aun no validas (futuras)
  }
  else offersModel->setFilter(""); //show all offers...
  offersModel->select();
}


void squeezeView::usersViewOnSelected(const QModelIndex & index)
{
 if (db.isOpen()) {
    //getting data from model...
    const QAbstractItemModel *model = index.model();
    int row = index.row();
    QModelIndex indx = model->index(row, usersModel->fieldIndex("id"));
    int id = model->data(indx, Qt::DisplayRole).toInt();
    indx = model->index(row, usersModel->fieldIndex("username"));
    QString username = model->data(indx, Qt::DisplayRole).toString();
    indx = model->index(row, usersModel->fieldIndex("name"));
    QString name = model->data(indx, Qt::DisplayRole).toString();
    indx = model->index(row, usersModel->fieldIndex("address"));
    QString address = model->data(indx, Qt::DisplayRole).toString();
    indx = model->index(row, usersModel->fieldIndex("phone"));
    QString phone = model->data(indx, Qt::DisplayRole).toString();
    indx = model->index(row, usersModel->fieldIndex("phone_movil"));
    QString cell = model->data(indx, Qt::DisplayRole).toString();
    indx = model->index(row, usersModel->fieldIndex("photo"));
    QByteArray photoBA = model->data(indx, Qt::DisplayRole).toByteArray();
    indx = model->index(row, usersModel->fieldIndex("password"));
    QString oldPassword = model->data(indx, Qt::DisplayRole).toString();
    indx = model->index(row, usersModel->fieldIndex("salt"));
    QString oldSalt = model->data(indx, Qt::DisplayRole).toString();
    indx = model->index(row, usersModel->fieldIndex("role"));
    int role = model->data(indx, Qt::DisplayRole).toInt();

    QPixmap photo;
    photo.loadFromData(photoBA);
    UserInfo uInfo;

    //Launch Edit dialog
    UserEditor *userEditorDlg = new UserEditor(this);
    //Set data on dialog
    userEditorDlg->setId(id);
    userEditorDlg->setUserName(username);
    userEditorDlg->setRealName(name);
    userEditorDlg->setAddress(address);
    userEditorDlg->setPhone(phone);
    userEditorDlg->setCell(cell);
    userEditorDlg->setPhoto(photo);
    userEditorDlg->setUserRole(role);
    //dont allow to scale privilages to supervisors.
    userEditorDlg->disableRoles(!adminIsLogged);
    //dont allow to change admin's password/info to a supervisor.
    userEditorDlg->disallowAdminChange(!adminIsLogged);

    if (userEditorDlg->exec() ) {
      uInfo.id = id;
      uInfo.username = userEditorDlg->getUserName();
      uInfo.name     = userEditorDlg->getRealName();
      uInfo.address  = userEditorDlg->getAddress();
      uInfo.phone    = userEditorDlg->getPhone();
      uInfo.cell     = userEditorDlg->getCell();
      photo    = userEditorDlg->getPhoto();
      uInfo.role     = userEditorDlg->getUserRole();

      uInfo.photo = Misc::pixmap2ByteArray(new QPixmap(photo));

      //Password
      if (!userEditorDlg->getNewPassword().isEmpty()) {
        QByteArray saltBA = Hash::getSalt();
        uInfo.salt = QString(saltBA);
        QString pswdTmp = uInfo.salt+userEditorDlg->getNewPassword();
        QByteArray passwdBA = pswdTmp.toLocal8Bit();
        uInfo.password = Hash::password2hash(passwdBA);
      }
      else {
        uInfo.password = oldPassword;
        uInfo.salt = oldSalt;
      }

      //Modify data on mysql...
      Azahar *myDb = new Azahar;
      myDb->setDatabase(db);
      if (!myDb->updateUser(uInfo)) qDebug()<<"ERROR | Updating user:"<<myDb->lastError();
      //reload loginWindow's users
      dlgPassword->reloadUsers();
      delete myDb;

      usersModel->select();
    }
    delete userEditorDlg;
  }
}


void squeezeView::productsViewOnSelected(const QModelIndex &index)
{
 if (db.isOpen()) {
  //getting data from model...
    const QAbstractItemModel *model = index.model();
    int row = index.row();
    QModelIndex indx = model->index(row, productsModel->fieldIndex("code"));
    qulonglong id = model->data(indx, Qt::DisplayRole).toULongLong();
    
    indx = model->index(row, productsModel->fieldIndex("photo"));
    QByteArray photoBA = model->data(indx, Qt::DisplayRole).toByteArray();
    QPixmap photo;
    photo.loadFromData(photoBA);

    ProductInfo pInfo;

    //Launch Edit dialog
    ProductEditor *productEditorDlg = new ProductEditor(this, false);
    //Set data on dialog
    productEditorDlg->setModel(productsModel);
    productEditorDlg->disableCode(); //On Edit product, code cannot be changed.
    productEditorDlg->setStockQtyReadOnly(true); //on edit, cannot change qty to force use stockCorrection
    productEditorDlg->setDb(db);
    productEditorDlg->setCode(id);
   
    qulonglong newcode=0;
    //Launch dialog, and if dialog is accepted...
    if (productEditorDlg->exec() ) {
      //get changed|unchanged values
      newcode        = productEditorDlg->getCode();
      pInfo.alphaCode= productEditorDlg->getAlphacode();
      pInfo.vendorCode= productEditorDlg->getVendorcode();
      pInfo.code     = newcode;
      pInfo.desc     = productEditorDlg->getDescription();
      //be aware of grouped products related to stock.
      if (productEditorDlg->isGroup()) {
        pInfo.stockqty = productEditorDlg->getGRoupStockMax();
        pInfo.groupElementsStr = productEditorDlg->getGroupElementsStr();
        pInfo.groupPriceDrop = productEditorDlg->getGroupPriceDrop(); 
      }
      else {
        pInfo.stockqty = productEditorDlg->getStockQty();
        pInfo.groupElementsStr = "";
        pInfo.groupPriceDrop = 0;
      }

      pInfo.hasUnlimitedStock = productEditorDlg->hasUnlimitedStock();
      pInfo.isNotDiscountable = productEditorDlg->isNotDiscountable();
      
      pInfo.price    = productEditorDlg->getPrice();
      pInfo.cost     = productEditorDlg->getCost();
      pInfo.units    = productEditorDlg->getMeasureId();
      pInfo.tax      = productEditorDlg->getTax1();
      pInfo.extratax = productEditorDlg->getTax2();
      pInfo.department= productEditorDlg->getDepartmentId();
      pInfo.category = productEditorDlg->getCategoryId();
      pInfo.subcategory = productEditorDlg->getSubCategoryId();
      pInfo.points   = productEditorDlg->getPoints();
      photo          = productEditorDlg->getPhoto();
      pInfo.photo    = Misc::pixmap2ByteArray(new QPixmap(photo)); //Photo ByteArray
      //FIXME: NEXT line is temporal remove on 0.8 version
      pInfo.lastProviderId = 1;
      //Next lines are for groups
      pInfo.isAGroup = productEditorDlg->isGroup();
      pInfo.isARawProduct = productEditorDlg->isRaw();
      

      //Update database
      Azahar *myDb = new Azahar;
      myDb->setDatabase(db);
      if (!myDb->updateProduct(pInfo, id)) qDebug()<<myDb->lastError();
      // Checar ofertas y cambiarlas/borrarlas
      if (id != newcode) {
        if (!myDb->moveOffer(id, newcode)) qDebug()<<myDb->lastError();
      }
      //now change stock if so --7/Sept/09
      if (productEditorDlg->isCorrectingStock()) {
        qDebug()<<"Correcting stock. Old:"<<productEditorDlg->getOldStock()<<" New:"<<productEditorDlg->getStockQty()<<" Reason"<<productEditorDlg->getReason();
        correctStock(pInfo.code, productEditorDlg->getOldStock(), productEditorDlg->getStockQty(), productEditorDlg->getReason());
      }
      //FIXME: We must see error types, which ones are for duplicate KEYS (codes) to advertise the user.
      productsModel->select();
      delete myDb;
    }
    delete productEditorDlg;
    setProductsFilter();
  }
}

void squeezeView::clientsViewOnSelected(const QModelIndex & index)
{
  if (db.isOpen()) {
    //getting data from model...
    const QAbstractItemModel *model = index.model();
    int row = index.row();
    QModelIndex indx = model->index(row, clientsModel->fieldIndex("id"));
    int id = model->data(indx, Qt::DisplayRole).toInt();
    indx = model->index(row, clientsModel->fieldIndex("name"));
    QString name = model->data(indx, Qt::DisplayRole).toString();
    indx = model->index(row, clientsModel->fieldIndex("code"));
    QString code = model->data(indx, Qt::DisplayRole).toString();
    indx = model->index(row, clientsModel->fieldIndex("address"));
    QString address = model->data(indx, Qt::DisplayRole).toString();
    indx = model->index(row, clientsModel->fieldIndex("phone"));
    QString phone = model->data(indx, Qt::DisplayRole).toString();
    indx = model->index(row, clientsModel->fieldIndex("phone_movil"));
    QString cell = model->data(indx, Qt::DisplayRole).toString();
    indx = model->index(row, clientsModel->fieldIndex("points"));
    qulonglong points = model->data(indx, Qt::DisplayRole).toULongLong();
    indx = model->index(row, clientsModel->fieldIndex("discount"));
    double discount = model->data(indx, Qt::DisplayRole).toDouble();
    indx = model->index(row, clientsModel->fieldIndex("photo"));
    QByteArray photoBA = model->data(indx, Qt::DisplayRole).toByteArray();
    indx = model->index(row, clientsModel->fieldIndex("since"));
    QDate sinceDate = model->data(indx, Qt::DisplayRole).toDate();

    ClientInfo cInfo;
    QPixmap photo;
    photo.loadFromData(photoBA);

    //Launch Edit dialog
    ClientEditor *clientEditorDlg = new ClientEditor(this);
    //Set data on dialog
    clientEditorDlg->setCode(code);
    clientEditorDlg->setId(id);
    clientEditorDlg->setName(name);
    clientEditorDlg->setAddress(address);
    clientEditorDlg->setPhone(phone);
    clientEditorDlg->setCell(cell);
    clientEditorDlg->setPhoto(photo);
    clientEditorDlg->setPoints(points);
    clientEditorDlg->setDiscount(discount);
    clientEditorDlg->setSinceDate(sinceDate);

    if (clientEditorDlg->exec() ) {
      cInfo.id       = id;
      cInfo.code     = clientEditorDlg->getCode();
      cInfo.name     = clientEditorDlg->getName();
      cInfo.address  = clientEditorDlg->getAddress();
      cInfo.phone    = clientEditorDlg->getPhone();
      cInfo.cell     = clientEditorDlg->getCell();
      photo          = clientEditorDlg->getPhoto();
      cInfo.points   = clientEditorDlg->getPoints();
      cInfo.discount = clientEditorDlg->getDiscount();
      cInfo.since    = clientEditorDlg->getSinceDate();

      cInfo.photo    = Misc::pixmap2ByteArray(new QPixmap(photo));

      //Modify data on mysql...
      if (!db.isOpen()) openDB();
      Azahar *myDb = new Azahar;
      myDb->setDatabase(db);
      myDb->updateClient(cInfo);
      delete myDb;

      clientsModel->select();
    }
    delete clientEditorDlg;
  }
}

void squeezeView::doPurchase()
{
//NOTE: Unlimited stock items cannot be purchased. This limitation is in the purchase editor, so here we do not need to do anything.
  if (db.isOpen()) {
    QStringList items;
    items.clear();

    //temporal items list
    items.append("empty list"); //just a tweak for creating the transaction, celaning after creating it.

    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);

    qDebug()<<"doPurchase...";
    PurchaseEditor *purchaseEditorDlg = new PurchaseEditor(this);
    purchaseEditorDlg->setDb(db);
    if (purchaseEditorDlg->exec()) {
      //Now add a transaction for buy
      QDate date = QDate::currentDate();
      QTime time = QTime::currentTime();
      TransactionInfo tInfo;
      tInfo.type    = tBuy;
      tInfo.amount  = purchaseEditorDlg->getTotalBuy();
      tInfo.date    = date;
      tInfo.time    = time;
      tInfo.paywith = 0.0;
      tInfo.changegiven = 0.0;
      tInfo.paymethod   = pCash;
      tInfo.state   = tCompleted;
      tInfo.userid  = 1;
      tInfo.clientid= 1;
      tInfo.cardnumber  = "-NA-";
      tInfo.cardauthnum = "-NA-";
      tInfo.itemcount   = purchaseEditorDlg->getItemCount();
      tInfo.itemlist    = items.join(";");
      tInfo.utility     = 0; //FIXME: utility is calculated until products are sold, not before.
      tInfo.terminalnum = 0; //NOTE: Not really a terminal... from admin computer.
      tInfo.providerid  = 1; //FIXME!
      //tInfo.groups      = ""; //DEPRECATED
      tInfo.specialOrders = "";
      tInfo.balanceId = 0;
      tInfo.totalTax  = purchaseEditorDlg->getTotalTaxes();
      qulonglong trnum = myDb->insertTransaction(tInfo); //to get the transaction number to insert in the log.
      if ( trnum <= 0 ) {
          qDebug()<<"ERROR: Could not create a Purchase Transaction ::doPurchase()";
          qDebug()<<"Error:"<<myDb->lastError();
          //TODO: Notify the user about the error.
      }

      //Now cleaning the items to fill with real items...
      items.clear();
      //assigning new transaction id to the tInfo.
      tInfo.id = trnum;

      QHash<qulonglong, ProductInfo> hash = purchaseEditorDlg->getHash();
      ProductInfo info;
      //Iterate the hash
      QHashIterator<qulonglong, ProductInfo> i(hash);
      while (i.hasNext()) {
          i.next();
          info = i.value();
          double oldstockqty = info.stockqty;
          info.stockqty = info.purchaseQty+oldstockqty;
          //Modify data on mysql...
          //validDiscount is for checking if product already exists on db. see line # 396 of purchaseeditor.cpp
          if (info.validDiscount) {
              if (!myDb->updateProduct(info, info.code))
                  qDebug()<<myDb->lastError();
              else {
                  log(loggedUserId, QDate::currentDate(), QTime::currentTime(), i18n("Purchase #%4 - %1 x %2 (%3)", info.purchaseQty, info.desc, info.code, trnum) );
                  qDebug()<<"Product updated [purchase] ok...";
              }
              
          } else {
              if (!myDb->insertProduct(info))
                  qDebug()<<myDb->lastError();
              else {
                  log(loggedUserId, QDate::currentDate(), QTime::currentTime(), i18n("Purchase #%4 - [new] - %1 x %2 (%3)", info.purchaseQty, info.desc, info.code, trnum) );
              }
          }
          
          productsModel->select();
          items.append(QString::number(info.code)+"/"+QString::number(info.purchaseQty));
      }
      //update items in transaction data
      tInfo.itemlist = items.join(";");
      myDb->updateTransaction(tInfo);
    }
  delete myDb;
  }
}

void squeezeView::stockCorrection()
{
  //launch a dialong asking: Item code, New stockQty, and reason.
  double newStockQty =0;
  double oldStockQty = 0;
  qulonglong pcode=0;
  QString reason;
  bool ok = false;
  InputDialog *dlg = new InputDialog(this, false, dialogStockCorrection, i18n("Enter the quantity and reason for the change, then press <ENTER> to accept, <ESC> to cancel"));
  if (dlg->exec())
  {
    newStockQty = dlg->dValue;
    reason = dlg->reason;
    pcode  = dlg->getPCode();
    ok = true;
  }
  if (ok) { //send data to database...
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    oldStockQty = myDb->getProductStockQty(pcode);
    ProductInfo p = myDb->getProductInfo(QString::number(pcode));
    bool isAGroup = p.isAGroup;

    //if is an Unlimited stock product, do not allow to make the correction.
    if (p.hasUnlimitedStock)  {
        notifierPanel->setSize(350,150);
        notifierPanel->setOnBottom(false);
        notifierPanel->showNotification("<b>Unlimited Stock Products cannot be purchased.</b>",5000);
        qDebug()<<"Unlimited Stock Products cannot be purchased.";
        return;
    }
    
    if (isAGroup) {
      //Notify to the user that this product's stock cannot be modified.
      //This is because if we modify each content's stock, all items will be at the same stock level, and it may not be desired.
      //We can even ask the user to do it anyway. For now, it is forbiden.
      //At the product editor, the stock correction button is disabled.
      KMessageBox::information(this, i18n("The desired product is a group and its stock cannot be modified, try modifying each of its contents."), i18n("Cannot modify stock"));
      delete myDb;
      return;
    }
    qDebug()<<"New Qty:"<<newStockQty<<" Reason:"<<reason;
    correctStock(pcode, oldStockQty, newStockQty, reason);
    delete myDb;
  }
}

void squeezeView::correctStock(qulonglong code, double oldStock, double newStock, const QString &reason)
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  if (!myDb->correctStock(code, oldStock, newStock, reason ))
      qDebug()<<myDb->lastError();
  else {
      //Log event.
      log(loggedUserId,QDate::currentDate(), QTime::currentTime(), i18n("Stock Correction: [Product %1] from %2 to %3. Reason:%4",code,oldStock,newStock, reason));
  }
  delete myDb;
}

void squeezeView::createUser()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  UserInfo info;

  if (!db.isOpen()) openDB();
  if (db.isOpen()) {
    UserEditor *userEditorDlg = new UserEditor(this);
    userEditorDlg->setUserRole(roleBasic); //preset as default the basic role
    //dont allow to scale privilages to supervisors. (or create new admins)
    userEditorDlg->disableRoles(!adminIsLogged);
    QPixmap photo;

    if (userEditorDlg->exec() ) {
      info.username = userEditorDlg->getUserName();
      info.name     = userEditorDlg->getRealName();
      info.address  = userEditorDlg->getAddress();
      info.phone    = userEditorDlg->getPhone();
      info.cell     = userEditorDlg->getCell();
      photo    = userEditorDlg->getPhoto();
      info.photo = Misc::pixmap2ByteArray(new QPixmap(photo));
      info.role    = userEditorDlg->getUserRole();

      QByteArray saltBA = Hash::getSalt();
      info.salt = QString(saltBA);
      QString pswdTmp = info.salt+userEditorDlg->getNewPassword();
      QByteArray passwdBA = pswdTmp.toLocal8Bit();
      info.password = Hash::password2hash(passwdBA);

      if (!myDb->insertUser(info)) qDebug()<<myDb->lastError();

      usersModel->select();
      //reload loginWindow's users
      dlgPassword->reloadUsers();
    }
    delete userEditorDlg;
  }
  delete myDb;
}

void squeezeView::createOffer()
{
  if (db.isOpen()) {
    PromoEditor *promoEditorDlg = new PromoEditor(this);
    promoEditorDlg->setDb(db);
    if (promoEditorDlg->exec() ) {

      QDate dateStart = promoEditorDlg->getDateStart();
      QDate dateEnd = promoEditorDlg->getDateEnd();

      OfferInfo offerInfo;
      offerInfo.productCode = promoEditorDlg->getSelectedProductCode();
      offerInfo.discount = promoEditorDlg->getDiscount();
      offerInfo.dateStart = dateStart;
      offerInfo.dateEnd   = dateEnd;

      Azahar *myDb = new Azahar;
      myDb->setDatabase(db);
      if ( !myDb->createOffer(offerInfo) ) {
          qDebug()<<myDb->lastError();
          notifierPanel->setSize(350,150);
          notifierPanel->setOnBottom(false);
          notifierPanel->showNotification(myDb->lastError(), 6000);
      }
      delete myDb;
      offersModel->select();
    }
    delete promoEditorDlg;
  }
}

void squeezeView::createProduct()
{
 if (db.isOpen()) {
  ProductEditor *prodEditorDlg = new ProductEditor(this, true);
  prodEditorDlg->setModel(productsModel);
  prodEditorDlg->setDb(db);
  prodEditorDlg->enableCode();
  prodEditorDlg->setStockQtyReadOnly(false);
  prodEditorDlg->setAutoCode(true);
  qulonglong newcode = 0;

  if (prodEditorDlg->exec()) {
    int resultado = prodEditorDlg->result();

    newcode = prodEditorDlg->getCode();
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    ProductInfo info;

    //This switch is for theprodEditorDlg->getPrice() new feature: When adding a new product, if entered code exists, it will be edited. to save time...
    switch (resultado) {
      case QDialog::Accepted:
      case statusNormal:
        if (prodEditorDlg->isGroup()) {
          info.stockqty = prodEditorDlg->getGRoupStockMax(); //FIXME!!!! returns 1
          info.groupElementsStr = prodEditorDlg->getGroupElementsStr();
          info.groupPriceDrop = prodEditorDlg->getGroupPriceDrop();
        }
        else {
          info.stockqty = prodEditorDlg->getStockQty();
          info.groupElementsStr = "";
          info.groupPriceDrop = 0;
        }
        info.code = newcode;
        info.alphaCode = prodEditorDlg->getAlphacode();
        info.vendorCode = prodEditorDlg->getVendorcode();
        info.desc    = prodEditorDlg->getDescription();
        info.price   = prodEditorDlg->getPrice();
        info.cost    = prodEditorDlg->getCost();
        info.purchaseQty = info.stockqty;
        info.units   = prodEditorDlg->getMeasureId();
        info.tax     = prodEditorDlg->getTax1();
        info.extratax= prodEditorDlg->getTax2();
        info.photo   = Misc::pixmap2ByteArray(new QPixmap(prodEditorDlg->getPhoto()));
        info.department= prodEditorDlg->getDepartmentId();
        info.category= prodEditorDlg->getCategoryId();
        info.subcategory= prodEditorDlg->getSubCategoryId();
        info.points  = prodEditorDlg->getPoints();
        //FIXME: NEXT line is temporal remove on 0.8 version
        info.lastProviderId = 1;
        //Next lines are for groups
        info.isAGroup         = prodEditorDlg->isGroup();
        info.isARawProduct    = prodEditorDlg->isRaw();

        info.hasUnlimitedStock = prodEditorDlg->hasUnlimitedStock();
        info.isNotDiscountable = prodEditorDlg->isNotDiscountable();
        
        if (!myDb->insertProduct(info))
            qDebug()<<"ERROR:"<<myDb->lastError();
        else {
            //register the stock purchase!
            createPurchase(info);
        }
        productsModel->select();
      break;
      case statusMod: //Here is not allowed to modify a product... just create new ones...
      break;
      case QDialog::Rejected:
      default:
      break;
    }
   delete myDb;
  }
 }
 setProductsFilter();
}

TransactionInfo squeezeView::createPurchase(ProductInfo info)
{
    TransactionInfo tInfo;
    if (db.isOpen()) {
        Azahar *myDb = new Azahar;
        myDb->setDatabase(db);
        
        qDebug()<<"Creating Purchase...";
        QDate date = QDate::currentDate();
        QTime time = QTime::currentTime();
        tInfo.type    = tBuy;
        tInfo.amount  = info.cost*info.stockqty; //as new product the only stock will be the new created.
        tInfo.date    = date;
        tInfo.time    = time;
        tInfo.paywith = 0.0;
        tInfo.changegiven = 0.0;
        tInfo.paymethod   = pCash;
        tInfo.state   = tCompleted;
        tInfo.userid  = 1;
        tInfo.clientid= 1;
        tInfo.cardnumber  = "-NA-";
        tInfo.cardauthnum = "-NA-";
        tInfo.itemcount   = info.stockqty;
        tInfo.itemlist    = QString("%1/%2").arg(info.code).arg(info.stockqty);
        tInfo.utility     = 0; //FIXME: utility is calculated until products are sold, not before.
        tInfo.terminalnum = 0; //NOTE: Not really a terminal... from admin computer.
        tInfo.providerid  = 1; //FIXME!
        tInfo.specialOrders = "";
        tInfo.balanceId = 0;
        //taxes
        double cWOTax = 0;
        if (myDb->getConfigTaxIsIncludedInPrice())
            cWOTax= (info.cost)/(1+((info.tax+info.extratax)/100));
        else
            cWOTax = info.cost;
        double tax = cWOTax*info.purchaseQty*(info.tax/100);
        double tax2= cWOTax*info.purchaseQty*(info.extratax/100);
        tInfo.totalTax  = tax + tax2;
        //insert into database, getting the tr. number.
        qulonglong trnum = myDb->insertTransaction(tInfo);
        tInfo.id = trnum;
        if ( trnum <= 0 ) qDebug()<<"ERROR: Could not create a Purchase Transaction ::createPurchase()";
        else {
          //log
          log(loggedUserId, date, time, i18n("Purchase #%4 - %1 x %2 (%3)", info.stockqty, info.desc, info.code, trnum) );
        }
        delete myDb;
    }

    return tInfo;
}

void squeezeView::createMeasure()
{
 if (db.isOpen()) {
//     int row = ui_mainview.tableMeasures->currentIndex().row();
//     if (row==-1) row=0;
//     if (ui_mainview.stackedWidget->currentIndex() != pBrowseMeasures)
//       ui_mainview.stackedWidget->setCurrentIndex(pBrowseMeasures);
//     if (measuresModel->tableName().isEmpty()) setupMeasuresModel();
//
//     measuresModel->insertRow(row);
  bool ok=false;
  QString meas = QInputDialog::getText(this, i18n("New Weight or Measure"), i18n("Enter the new weight or measure to insert:"),
                                     QLineEdit::Normal, "", &ok );
  if (ok && !meas.isEmpty()) {
    Azahar *myDb = new Azahar;
    if (!db.isOpen()) openDB();
    myDb->setDatabase(db);
    if (!myDb->insertMeasure(meas)) qDebug()<<"Error:"<<myDb->lastError();
    measuresModel->select();
    delete myDb;
  }
 }
}

void squeezeView::createDepartment()
{
    //Launch Edit dialog
    SubcategoryEditor *scEditor = new SubcategoryEditor(this);
    //get categories list and populate the dialog with them.
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    QStringList catList;
    catList << myDb->getCategoriesList();
    scEditor->populateList( catList );
    scEditor->setCatList(catList);
    scEditor->setScatList(myDb->getSubCategoriesList());
    scEditor->setLabelForName(i18n("New Department:"));
    scEditor->setLabelForList(i18n("Select the child categories for this department:"));
    scEditor->setDialogType(1); //department = 1
    
    if ( scEditor->exec() ) {
        QString depText = scEditor->getName();
        QStringList children = scEditor->getChildren();
        qDebug()<<" CHILDREN:"<<children;
        //Create the department
        if (!myDb->insertDepartment(depText)) {
            qDebug()<<"Error:"<<myDb->lastError();
            delete myDb;
            return;
        }
        qulonglong depId = myDb->getDepartmentId(depText);
        //create the m2m  relations for the new department/categories.

        foreach(QString cat, children) {
            //get category id
            qulonglong cId = myDb->getCategoryId(cat);
            //create the link [department] --> [category]
            myDb->insertM2MDepartmentCategory(depId, cId);
        }
    }
    
    departmentsModel->select();
    categoriesModel->select();
    subcategoriesModel->select();
    updateDepartmentsCombo();
    
    delete myDb;
}

void squeezeView::createCategory()
{
    //Launch Edit dialog
    SubcategoryEditor *scEditor = new SubcategoryEditor(this);
    //get categories list and populate the dialog with them.
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    QStringList catList;
    catList << myDb->getSubCategoriesList();
    scEditor->populateList( catList );
    scEditor->setCatList(myDb->getCategoriesList());
    scEditor->setScatList(catList);
    scEditor->setLabelForName(i18n("New Category:"));
    scEditor->setLabelForList(i18n("Select the child subcategories for this category:"));
    scEditor->setDialogType(2); //category = 2
    
    if ( scEditor->exec() ) {
        QString text = scEditor->getName();
        QStringList children = scEditor->getChildren();
        qDebug()<<" CHILDREN:"<<children;
        //Create the department
        if (!myDb->insertCategory(text)) {
            qDebug()<<"Error:"<<myDb->lastError();
            delete myDb;
            return;
        }
        qulonglong cId = myDb->getCategoryId(text);
        //create the m2m  relations for the new department/categories.
        
        foreach(QString cat, children) {
            //get category id
            qulonglong scId = myDb->getSubCategoryId(cat);
            //create the link [category] --> [subcategory]
            myDb->insertM2MCategorySubcategory(cId, scId);
        }
    }
    
    departmentsModel->select();
    categoriesModel->select();
    subcategoriesModel->select();
    updateCategoriesCombo();
    
    delete myDb;
}


void squeezeView::updateDepartmentsCombo()
{
  populateDepartmentsHash();
  ui_mainview.comboProductsFilterByDepartment->clear();
  QHashIterator<QString, int> item(departmentsHash);
  while (item.hasNext()) {
    item.next();
    ui_mainview.comboProductsFilterByDepartment->addItem(item.key());
  }
}

void squeezeView::updateCategoriesCombo()
{
  populateCategoriesHash();
  ui_mainview.comboProductsFilterByCategory->clear();
  QHashIterator<QString, int> item(categoriesHash);
  while (item.hasNext()) {
    item.next();
    ui_mainview.comboProductsFilterByCategory->addItem(item.key());
  }
}

void squeezeView::updateCardTypesCombo()
{
    populateCardTypesHash();
    ui_mainview.comboCardTypes->clear();
    QHashIterator<QString, int> item(cardTypesHash);
    while (item.hasNext()) {
        item.next();
        ui_mainview.comboCardTypes->addItem(item.key());
    }
}

void squeezeView::updateSubCategoriesCombo()
{
    populateSubCategoriesHash();
    ui_mainview.comboProductsFilterBySubCategory->clear();
    QHashIterator<QString, int> item(subcategoriesHash);
    while (item.hasNext()) {
        item.next();
        ui_mainview.comboProductsFilterBySubCategory->addItem(item.key());
    }
}

void squeezeView::createSubCategory()
{
    bool ok=false;
    QString c = QInputDialog::getText(this, i18n("New Subcategory"), i18n("Enter the new subcategory:"),
    QLineEdit::Normal, "", &ok );
    if (ok && !c.isEmpty()) {
        Azahar *myDb = new Azahar;
        if (!db.isOpen()) openDB();
        myDb->setDatabase(db);
        if (!myDb->insertSubCategory(c)) qDebug()<<"Error:"<<myDb->lastError();
        delete myDb;
    }
    subcategoriesModel->select();
    updateSubCategoriesCombo();
}

void squeezeView::createClient()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);

  if (db.isOpen()) {
    ClientEditor *clientEditorDlg = new ClientEditor(this);
    ClientInfo info;
    QPixmap photo;

    if (clientEditorDlg->exec() ) {
      info.code     = clientEditorDlg->getCode();
      info.name     = clientEditorDlg->getName();
      info.address  = clientEditorDlg->getAddress();
      info.phone    = clientEditorDlg->getPhone();
      info.cell     = clientEditorDlg->getCell();
      photo    = clientEditorDlg->getPhoto();
      info.points   = clientEditorDlg->getPoints();
      info.discount = clientEditorDlg->getDiscount();
      info.since    = QDate::currentDate();

      info.photo = Misc::pixmap2ByteArray(new QPixmap(photo));
      if (!db.isOpen()) openDB();
      if (!myDb->insertClient(info)) qDebug()<<myDb->lastError();

      clientsModel->select();
    }
    delete clientEditorDlg;
  }
  delete myDb;
}

void squeezeView::deleteSelectedClient()
{
  if (db.isOpen()) {
    QModelIndex index = ui_mainview.clientsView->currentIndex();
    if (clientsModel->tableName().isEmpty()) setupClientsModel();
    if (index == clientsModel->index(-1,-1) ) {
      KMessageBox::information(this, i18n("Please select a client to delete, then press the delete button again."), i18n("Cannot delete"));
    }
    else  {
      QString uname = clientsModel->record(index.row()).value("name").toString();
      qulonglong clientId = clientsModel->record(index.row()).value("id").toULongLong();
      if (clientId > 1) {
        int answer = KMessageBox::questionYesNo(this, i18n("Do you really want to delete the client named %1?",uname),
                                              i18n("Delete"));
        if (answer == KMessageBox::Yes) {
          Azahar *myDb = new Azahar;
          myDb->setDatabase(db);
          if (!clientsModel->removeRow(index.row(), index)) {
            // weird:  since some time, removeRow does not work... it worked fine on versions < 0.9 ..
            bool d = myDb->deleteClient(clientId); qDebug()<<"Deleteing client ("<<clientId<<") manually...";
            if (d) qDebug()<<"Deletion succed...";
          }
          clientsModel->submitAll();
          clientsModel->select();
          delete myDb;
        }
    } else KMessageBox::information(this, i18n("Default client cannot be deleted."), i18n("Cannot delete"));
   }
 }
}

void squeezeView::deleteSelectedUser()
{
  if (db.isOpen()) {
    QModelIndex index = ui_mainview.usersView->currentIndex();
    if (usersModel->tableName().isEmpty()) setupUsersModel();
    if (index == usersModel->index(-1,-1) ) {
      KMessageBox::information(this, i18n("Please select a user to delete, then press the delete button again."), i18n("Cannot delete"));
      //TODO: Present a dialog to select which user to delete...
    }
    else  {
      QString uname = usersModel->record(index.row()).value("name").toString();
      QString usr = usersModel->record(index.row()).value("username").toString();
      if (usr != "admin")
      {
        int answer = KMessageBox::questionYesNo(this, i18n("Do you really want to delete the user named %1?",uname),
                                              i18n("Delete"));
        if (answer == KMessageBox::Yes) {
          Azahar *myDb = new Azahar;
          myDb->setDatabase(db);
          qulonglong  iD = usersModel->record(index.row()).value("id").toULongLong();
          if (!usersModel->removeRow(index.row(), index)) {
            // weird:  since some time, removeRow does not work... it worked fine on versions < 0.9 ..
            bool d = myDb->deleteUser(iD); qDebug()<<"Deleteing user ("<<iD<<") manually...";
            if (d) qDebug()<<"Deletion succed...";
          }
          usersModel->submitAll();
          usersModel->select();
          delete myDb;
        }
      } else KMessageBox::information(this, i18n("Admin user cannot be deleted."), i18n("Cannot delete"));
   }
 }
}

void squeezeView::deleteSelectedOffer()
{
  if (db.isOpen()) {
    QModelIndex index = ui_mainview.tableBrowseOffers->currentIndex();
    if (offersModel->tableName().isEmpty()) setupOffersModel();
    if (index == offersModel->index(-1,-1) ) {
      //NOTE: Hey, I think the word "offer" does not mean what i mean...
      KMessageBox::information(this, i18n("Please select an offer to delete, then press the delete button again."), i18n("Cannot delete"));
      //NOTE: Present a dialog to select which user to delete?...
    }
    else  {
      int answer = KMessageBox::questionYesNo(this, i18n("Do you really want to delete the selected discount?"),
                                              i18n("Delete"));
      if (answer == KMessageBox::Yes) {
        //same weird error when deleting offers that the products! :S
        Azahar *myDb = new Azahar;
        myDb->setDatabase(db);
        qulonglong  code = offersModel->record(index.row()).value("id").toULongLong();
        if (!offersModel->removeRow(index.row(), index)) myDb->deleteOffer(code);
        offersModel->submitAll();
        offersModel->select();
      }
    }
  }
}

void squeezeView::deleteSelectedProduct()
{
  if (db.isOpen()) {
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    QModelIndex index;
    if (ui_mainview.productsView->isHidden()) {
      index = ui_mainview.productsViewAlt->currentIndex();
    } else {
      index = ui_mainview.productsView->currentIndex();
    }
    
    if (productsModel->tableName().isEmpty()) setupProductsModel();
    if (index == productsModel->index(-1,-1) ) {
      KMessageBox::information(this, i18n("Please select a product to delete, then press the delete button."), i18n("Cannot delete"));
    }
    else  {
      int answer = KMessageBox::questionYesNo(this, i18n("Do you really want to delete the selected product?"),
                                              i18n("Delete"));
      if (answer == KMessageBox::Yes) {
        //first we obtain the product code to be deleted.
        qulonglong  iD = productsModel->record(index.row()).value("code").toULongLong();
        if (!productsModel->removeRow(index.row(), index)) {
          // weird:  since some time, removeRow does not work... it worked fine on versions < 0.9 ..
          bool d = myDb->deleteProduct(iD); qDebug()<<"Deleteing product ("<<iD<<") manually...";
          if (d) qDebug()<<"Deletion succed...";
          //on deleteProduct the offers are also deleted.
        }
        productsModel->submitAll();
        productsModel->select();
      }
    }
    delete myDb;
  }
}

void squeezeView::deleteSelectedMeasure()
{
  if (db.isOpen()) {
    QModelIndex index = ui_mainview.tableMeasures->currentIndex();
    if (measuresModel->tableName().isEmpty()) setupMeasuresModel();
    if (index == measuresModel->index(-1,-1) ) {
      KMessageBox::information(this, i18n("Please select a row to delete, then press the delete button again."), i18n("Cannot delete"));
    }
    else  {
      QString measureText = measuresModel->record(index.row()).value("text").toString();
      Azahar *myDb = new Azahar;
      myDb->setDatabase(db);
      qulonglong measureId = myDb->getMeasureId(measureText);
      if (measureId > 1) {
        int answer = KMessageBox::questionYesNo(this, i18n("Do you really want to delete the measure '%1'?", measureText),
                                                i18n("Delete"));
        if (answer == KMessageBox::Yes) {
          qulonglong  iD = measuresModel->record(index.row()).value("id").toULongLong();
          if (!measuresModel->removeRow(index.row(), index)) {
            // weird:  since some time, removeRow does not work... it worked fine on versions < 0.9 ..
            bool d = myDb->deleteMeasure(iD); qDebug()<<"Deleteing Measure ("<<iD<<") manually...";
            if (d) qDebug()<<"Deletion succed...";
          }
          measuresModel->submitAll();
          measuresModel->select();
        }
      } else KMessageBox::information(this, i18n("Default measure cannot be deleted."), i18n("Cannot delete"));
      delete myDb;
    }
  }
}

void squeezeView::deleteSelectedDepartment()
{
    if (db.isOpen()) {
        QModelIndex index = ui_mainview.tableDepartments->currentIndex();
        if (departmentsModel->tableName().isEmpty()) setupDepartmentsModel();
        if (index == departmentsModel->index(-1,-1) ) {
            KMessageBox::information(this, i18n("Please select a department to delete, then press the delete button again."), i18n("Cannot delete"));
        }
        else  {
            QString text = departmentsModel->record(index.row()).value("text").toString();
            Azahar *myDb = new Azahar;
            myDb->setDatabase(db);
            qulonglong dId = myDb->getDepartmentId(text);
            if (dId >0) {
                int answer = KMessageBox::questionYesNo(this, i18n("Do you really want to delete the department '%1'?", text),
                i18n("Delete"));
                if (answer == KMessageBox::Yes) {
                    qulonglong  iD = departmentsModel->record(index.row()).value("id").toULongLong();
                    if (!departmentsModel->removeRow(index.row(), index)) {
                        // weird:  since some time, removeRow does not work... it worked fine on versions < 0.9 ..
                        bool d = myDb->deleteDepartment(iD); qDebug()<<"Deleteing Department ("<<iD<<") manually...";
                        if (d) qDebug()<<"Deletion succed...";
                    }
                    departmentsModel->submitAll();
                    departmentsModel->select();
                    updateDepartmentsCombo();
                }
            } else KMessageBox::information(this, i18n("Default department cannot be deleted."), i18n("Cannot delete"));
                    delete myDb;
        }
    }
}

void squeezeView::deleteSelectedCategory()
{
  if (db.isOpen()) {
    QModelIndex index = ui_mainview.tableCategories->currentIndex();
    if (categoriesModel->tableName().isEmpty()) setupCategoriesModel();
    if (index == categoriesModel->index(-1,-1) ) {
      KMessageBox::information(this, i18n("Please select a category to delete, then press the delete button again."), i18n("Cannot delete"));
    }
    else  {
      QString catText = categoriesModel->record(index.row()).value("text").toString();
      Azahar *myDb = new Azahar;
      myDb->setDatabase(db);
      qulonglong catId = myDb->getCategoryId(catText);
      if (catId >0) {
        int answer = KMessageBox::questionYesNo(this, i18n("Do you really want to delete the category '%1'?", catText),
                                                i18n("Delete"));
        if (answer == KMessageBox::Yes) {
          qulonglong  iD = categoriesModel->record(index.row()).value("catid").toULongLong();
          if (!categoriesModel->removeRow(index.row(), index)) {
            // weird:  since some time, removeRow does not work... it worked fine on versions < 0.9 ..
            bool d = myDb->deleteCategory(iD); qDebug()<<"Deleteing Category ("<<iD<<") manually...";
            if (d) qDebug()<<"Deletion succed...";
          }
          categoriesModel->submitAll();
          categoriesModel->select();
          updateCategoriesCombo();
        }
      } else KMessageBox::information(this, i18n("Default category cannot be deleted."), i18n("Cannot delete"));
      delete myDb;
    }
  }
}

void squeezeView::deleteSelectedSubCategory()
{
    if (db.isOpen()) {
        QModelIndex index = ui_mainview.tableSubCategories->currentIndex();
        if (subcategoriesModel->tableName().isEmpty()) setupSubCategoriesModel();
        if (index == subcategoriesModel->index(-1,-1) ) {
            KMessageBox::information(this, i18n("Please select a subcategory to delete, then press the delete button again."), i18n("Cannot delete"));
        }
        else  {
            QString catText = subcategoriesModel->record(index.row()).value("text").toString();
            Azahar *myDb = new Azahar;
            myDb->setDatabase(db);
            qulonglong catId = myDb->getSubCategoryId(catText);
            if (catId >0) {
                int answer = KMessageBox::questionYesNo(this, i18n("Do you really want to delete the subcategory '%1'?", catText),
                i18n("Delete"));
                if (answer == KMessageBox::Yes) {
                    qulonglong  iD = subcategoriesModel->record(index.row()).value("id").toULongLong();
                    if (!subcategoriesModel->removeRow(index.row(), index)) {
                        // weird:  since some time, removeRow does not work... it worked fine on versions < 0.9 ..
                        bool d = myDb->deleteSubCategory(iD); qDebug()<<"Deleteing SubCategory ("<<iD<<") manually...";
                        if (d) qDebug()<<"Deletion succed...";
                    }
                    subcategoriesModel->submitAll();
                    subcategoriesModel->select();
		    updateSubCategoriesCombo();
                }
            } else KMessageBox::information(this, i18n("Default subcategory cannot be deleted."), i18n("Cannot delete"));
                    delete myDb;
        }
    }
}


//CASH OUTS
void squeezeView::setupCashFlowModel()
{
  openDB();
  qDebug()<<"setupcashflow.. after openDB";
  if (db.isOpen()) {
    cashflowModel->setTable("cashflow");
    
    cashflowIdIndex = cashflowModel->fieldIndex("id");
    cashflowTypeIndex = cashflowModel->fieldIndex("type");
    cashflowDateIndex = cashflowModel->fieldIndex("date");
    cashflowTimeIndex= cashflowModel->fieldIndex("time");
    cashflowUseridIndex= cashflowModel->fieldIndex("userid");
    cashflowReasonIndex = cashflowModel->fieldIndex("reason");
    cashflowAmountIndex= cashflowModel->fieldIndex("amount");
    cashflowTerminalNumIndex= cashflowModel->fieldIndex("terminalnum");
    
    
    ui_mainview.cashFlowTable->setModel(cashflowModel);
    ui_mainview.cashFlowTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    cashflowModel->setHeaderData(cashflowIdIndex, Qt::Horizontal, i18n("Id"));
    cashflowModel->setHeaderData(cashflowTypeIndex, Qt::Horizontal, i18n("Type"));
    cashflowModel->setHeaderData(cashflowDateIndex, Qt::Horizontal, i18n("Date"));
    cashflowModel->setHeaderData(cashflowUseridIndex, Qt::Horizontal, i18n("Vendor") );
    cashflowModel->setHeaderData(cashflowTimeIndex, Qt::Horizontal, i18n("Time") );
    cashflowModel->setHeaderData(cashflowReasonIndex, Qt::Horizontal, i18n("Reason") );
    cashflowModel->setHeaderData(cashflowAmountIndex, Qt::Horizontal, i18n("Amount") );
    cashflowModel->setHeaderData(cashflowTerminalNumIndex, Qt::Horizontal, i18n("Terminal Num.") );
    
    cashflowModel->setRelation(cashflowUseridIndex, QSqlRelation("users", "id", "username"));
    cashflowModel->setRelation(cashflowTypeIndex, QSqlRelation("cashflowtypes", "typeid", "text"));
    
    ui_mainview.cashFlowTable->setSelectionMode(QAbstractItemView::SingleSelection);
    
    cashflowModel->select();
  }
  qDebug()<<"setupCashFlow.. done, "<<cashflowModel->lastError();
}

void squeezeView::exportTable()
{
  if (ui_mainview.stackedWidget->currentIndex() == 10) {
    switch(ui_mainview.stackedWidget2->currentIndex()){
      case 0: exportQTableView(ui_mainview.cashFlowTable);break;
      case 1: exportQTableView(ui_mainview.transactionsTable);break;
      case 2: exportQTableView(ui_mainview.balancesTable);break;
      case 3: exportQTableView(ui_mainview.tableSO);break;
      default:break;
    }
  } else {
    switch(ui_mainview.stackedWidget->currentIndex()){
    case pBrowseProduct: exportQTableView(ui_mainview.productsViewAlt);break;
    case pBrowseOffers: exportQTableView(ui_mainview.tableBrowseOffers);break;
    case pBrowseUsers: exportQTableView(ui_mainview.usersView);break;
    case pBrowseMeasures: exportQTableView(ui_mainview.tableMeasures);break;
    case pBrowseCategories: exportQTableView(ui_mainview.tableCategories);break;
    case pBrowseSubCategories: exportQTableView(ui_mainview.tableSubCategories);break;
    case pBrowseClients: exportQTableView(ui_mainview.clientsView);break;
    //case pBrowseTransactions: exportQTableView(ui_mainview.transactionsTable);break;
    //case pBrowseBalances: exportQTableView(ui_mainview.balancesTable);break;
    //case pBrowseCashFlow: exportQTableView(ui_mainview.cashFlowTable);break;
    //case pCustomReports: exportQTableView(ui_mainview.customReportsView);break;
    default:break;
    }
  }
}

void squeezeView::exportQTableView(QAbstractItemView *tableview)
{
  if (tableview->model()){
    const QAbstractItemModel *model = tableview->model();
    QString fileName = QFileDialog::getSaveFileName(this, i18n("Save As"),"",i18n("CSV files (*.csv)"));
    if (fileName != ""){
      QFile file(fileName);
      if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
          return;
      QTextStream out(&file);

      // Headers
      for (int j=0;j<model->columnCount();j++){
         out << "\"" << model->headerData(j, Qt::Horizontal, Qt::DisplayRole).toString() << "\";";
      }
      out << "\n";

      // Data
      QProgressDialog progress(i18n("Exporting data..."), i18n("Abort"), 0, model->rowCount(), this);
      progress.setWindowModality(Qt::WindowModal);
      // If there're more than 1 row selected, then export only this rows
      QModelIndexList selected = tableview->selectionModel()->selectedRows();
      if (selected.count()>1){
        for (int i=0;i<selected.count();i++){
          for (int j=0;j<model->columnCount();j++){
            out << "\"" << model->data(model->index(selected.at(i).row(), j)).toString() << "\";";
          }
          out <<"\n";
        }
      }else{
        // export everything in the model
        for (int i=0;i<model->rowCount();i++){
          progress.setValue(i);
          if (progress.wasCanceled())
              break;
          for (int j=0;j<model->columnCount();j++){
              out << "\"" << model->data(model->index(i, j)).toString() << "\";";
          }
          out <<"\n";
        }
      }
      file.close();
      progress.setValue(model->rowCount());
      //if (KMessageBox::questionYesNo(this, i18n("Data exported succesfully to %1.\n\n Would you like to open it?").arg(fileName), i18n("Finished")) == KMessageBox::Yes ){
      //  system(QString("oocalc \""+fileName+ "\"").toLatin1());
      }
    }
}


// Report printing...

void squeezeView::reportActivated(QListWidgetItem *item)
{
  if ( item == itmEndOfMonth ) {
    printEndOfMonth(); // this is for the end of the month, all terminals.
  } else if ( item == itmGralEndOfDay ) {
    printGralEndOfDay(); // this is for  end of day of all terminals.
  } else if ( item == itmEndOfDay ) {
    printEndOfDay();
  } else if ( item == itmPrintSoldOutProducts ) {
    printSoldOutProducts();
  } else if ( item == itmPrintLowStockProducts ) {
    printLowStockProducts();
  } else if ( item == itmPrintStock ) {
    printStock();
  }
//   } else if ( item == itmPrintBalance ) {
//     printBalance();
//   }
}

void squeezeView::printGralEndOfDay()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  
  // Get every transaction from all day, calculate sales, profit, and profit margin (%).
  AmountAndProfitInfo amountProfit;
  PrintEndOfDayInfo pdInfo;
  QList<TransactionInfo> transactionsList;
  
  amountProfit     = myDb->getDaySalesAndProfit();
  transactionsList = myDb->getDayTransactions(); //all terminals
  
  pdInfo.storeName = myDb->getConfigStoreName();
  pdInfo.storeAddr = myDb->getConfigStoreAddress();
  pdInfo.storeLogo = myDb->getConfigStoreLogo();
  pdInfo.thTitle   = i18n("End of day report");
  pdInfo.thTicket  = i18n("Id");
  pdInfo.salesPerson = "";
  pdInfo.terminal  = i18n("All Terminals");
  pdInfo.thDate    = KGlobal::locale()->formatDateTime(QDateTime::currentDateTime(), KLocale::LongDate);
  pdInfo.thTime    = i18n("Time");
  pdInfo.thAmount  = i18n("Amount");
  pdInfo.thProfit  = i18n("Profit");
  pdInfo.thPayMethod = i18n("Method");
  pdInfo.thTotalTaxes= i18n("Total taxes collected today: ");
  pdInfo.logoOnTop = myDb->getConfigLogoOnTop();
  pdInfo.thTotalSales  = KGlobal::locale()->formatMoney(amountProfit.amount, QString(), 2);
  pdInfo.thTotalProfit = KGlobal::locale()->formatMoney(amountProfit.profit, QString(), 2);

  QStringList lines; //for dotmatrix printers on /dev ports
  lines.append(pdInfo.thTitle);
  lines.append(pdInfo.thDate);
  lines.append(pdInfo.terminal);
  lines.append(pdInfo.thTicket+"    "+pdInfo.thTime+ pdInfo.thAmount+"   "+pdInfo.thProfit+"   "+pdInfo.thPayMethod);
  
  //each transaction...
  double tTaxes = 0;
  for (int i = 0; i < transactionsList.size(); ++i)
  {
    QLocale localeForPrinting; // needed to convert double to a string better
    TransactionInfo info = transactionsList.at(i);
    qDebug()<<" transactions on end of day: i="<<i<<" ID:"<<info.id;
    QString tid      = QString::number(info.id);
    QString hour     = info.time.toString("hh:mm");
    QString amount   =  localeForPrinting.toString(info.amount,'f',2);
    QString profit   =  localeForPrinting.toString(info.utility, 'f', 2);
    QString payMethod;
    payMethod        = myDb->getPayTypeStr(info.paymethod);//using payType methods
    
    QString line     = tid +"|"+ hour +"|"+ amount +"|"+ profit +"|"+ payMethod;
    pdInfo.trLines.append(line);
    lines.append(tid+"  "+hour+"  "+ amount+"  "+profit+"  "+payMethod);
    tTaxes += info.totalTax;
    qDebug()<<"total sale:"<<info.amount<<" taxes this sale:"<<info.totalTax<<" accumulated taxes:"<<tTaxes;
  } //for each item
  
  lines.append(i18n("Total Sales : %1",pdInfo.thTotalSales));
  lines.append(i18n("Total Profit: %1",pdInfo.thTotalProfit));

  //add taxes amount
  pdInfo.thTotalTaxes += KGlobal::locale()->formatMoney(tTaxes, QString(), 2);
  
  if (Settings::smallTicketDotMatrix()) { // dot matrix printer
    QString printerFile=Settings::printerDevice();
    if (printerFile.length() == 0) printerFile="/dev/lp0";
    QString printerCodec=Settings::printerCodec();
    qDebug()<<"[Printing report on "<<printerFile<<"]";
    qDebug()<<lines.join("\n");
    PrintDEV::printSmallBalance(printerFile, printerCodec, lines.join("\n"));
  } else if (Settings::smallTicketCUPS()) {
    qDebug()<<"[Printing report on CUPS small size]";
    QPrinter printer;
    printer.setFullPage( true );
    QPrintDialog printDialog( &printer );
    printDialog.setWindowTitle(i18n("Print end of day report"));
    if ( printDialog.exec() ) {
      PrintCUPS::printSmallEndOfDay(pdInfo, printer);
    } else {
        //NOTE: This is a proposition:
        //      If the dialog is accepted (ok), then we print what the user choosed. Else, we print to a file (PDF).
        //      The user can press ENTER when dialog appearing if the desired printer is the default (or the only).
        qDebug()<<"User cancelled printer dialog. We export ticket to a file.";
        QString fn = QString("%1/lemon-printing/").arg(QDir::homePath());
        QDir dir;
        if (!dir.exists(fn))
            dir.mkdir(fn);
        fn = fn+QString("GeneralEndOfDay__%1.pdf").arg(QDateTime::currentDateTime().toString("dd-MMM-yy"));
        qDebug()<<fn;
        
        printer.setOutputFileName(fn);
        printer.setPageMargins(0,0,0,0,QPrinter::Millimeter);
        printer.setPaperSize(QSizeF(72,200), QPrinter::Millimeter); //setting small ticket paper size. 72mm x 200mm
        
        PrintCUPS::printSmallEndOfDay(pdInfo, printer);
    }
  } else { //big printer
    qDebug()<<"[Printing report on CUPS big size]";
    QPrinter printer;
    printer.setFullPage( true );
    QPrintDialog printDialog( &printer );
    printDialog.setWindowTitle(i18n("Print end of day report"));
    if ( printDialog.exec() ) {
      PrintCUPS::printBigEndOfDay(pdInfo, printer);
    }
  }
  delete myDb;
}

void squeezeView::printEndOfDay()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);

  //first get the terminal number for the end of day
  InputDialog *dlg = new InputDialog(this, true, dialogTerminalNum, i18n("Enter the Terminal number for the end of day, then press <ENTER> to accept, <ESC> to cancel"));
  bool ok = false;
  qulonglong terminalNum = 0;
  //NOTE: InputDialog has an int validator for a qulonglong variable. Check if there is a QULONGLONGVALIDATOR FIXME at inputdialog.cpp:121
  if (dlg->exec())
  {
    terminalNum = dlg->iValue;
    ok = true;
  }

  if (ok) {
    // Get every transaction from all day, calculate sales, profit, and profit margin (%).
    AmountAndProfitInfo amountProfit;
    PrintEndOfDayInfo pdInfo;
    QList<TransactionInfo> transactionsList;
    
    amountProfit     = myDb->getDaySalesAndProfit();
    transactionsList = myDb->getDayTransactions(terminalNum);

    if (transactionsList.count() < 1) {
      //hey, if there are no transactions, why print it?
      qDebug()<<"Nothing to print!";
      KNotification *notify = new KNotification(i18n("No transactions to print!"), this);
      notify->setText(i18n("No transactions for  terminal #%1 for today.", terminalNum));
      QPixmap pixmap = DesktopIcon("dialog-warning",32);
      notify->setPixmap(pixmap);
      notify->sendEvent();
      return; //just to quit.
    }
    
    pdInfo.storeName = myDb->getConfigStoreName();
    pdInfo.storeAddr = myDb->getConfigStoreAddress();
    pdInfo.storeLogo = myDb->getConfigStoreLogo();
    pdInfo.thTitle   = i18n("End of day report");
    pdInfo.thTicket  = i18n("Id");
    pdInfo.salesPerson = myDb->getUserName(transactionsList.at(0).userid);
    pdInfo.terminal  = i18n("terminal # %1 ", terminalNum);
    pdInfo.thDate    = KGlobal::locale()->formatDateTime(QDateTime::currentDateTime(), KLocale::LongDate);
    pdInfo.thTime    = i18n("Time");
    pdInfo.thAmount  = i18n("Amount");
    pdInfo.thProfit  = i18n("Profit");
    pdInfo.thPayMethod = i18n("Method");
    pdInfo.thTotalTaxes= i18n("Total taxes collected for this terminal: ");
    pdInfo.logoOnTop = myDb->getConfigLogoOnTop();
    pdInfo.thTotalSales  = KGlobal::locale()->formatMoney(amountProfit.amount, QString(), 2);
    pdInfo.thTotalProfit = KGlobal::locale()->formatMoney(amountProfit.profit, QString(), 2);

    QStringList lines; //for dotmatrix printers on /dev ports
    lines.append(pdInfo.thTitle);
    lines.append(pdInfo.thDate);
    lines.append(pdInfo.salesPerson +" / "+ pdInfo.terminal);
    lines.append(pdInfo.thTicket+"    "+pdInfo.thTime+ pdInfo.thAmount+"   "+pdInfo.thProfit+"   "+pdInfo.thPayMethod);
    
    //each transaction...
    double tTaxes = 0;
    for (int i = 0; i < transactionsList.size(); ++i)
    {
      QLocale localeForPrinting; // needed to convert double to a string better
      TransactionInfo info = transactionsList.at(i);
      //qDebug()<<" transactions on end of day: i="<<i<<" ID:"<<info.id;
      QString tid      = QString::number(info.id);
      QString hour     = info.time.toString("hh:mm");
      QString amount   =  localeForPrinting.toString(info.amount,'f',2);
      QString profit   =  localeForPrinting.toString(info.utility, 'f', 2);
      QString payMethod;
      payMethod        = myDb->getPayTypeStr(info.paymethod);//using payType methods
      
      QString line     = tid +"|"+ hour +"|"+ amount +"|"+ profit +"|"+ payMethod;
      pdInfo.trLines.append(line);
      lines.append(tid+"  "+hour+"  "+ amount+"  "+profit+"  "+payMethod);
      tTaxes += info.totalTax;
      qDebug()<<"total sale:"<<info.amount<<" taxes this sale:"<<info.totalTax<<" accumulated taxes:"<<tTaxes;
    } //for each item
    
    lines.append(i18n("Total Sales : %1",pdInfo.thTotalSales));
    lines.append(i18n("Total Profit: %1",pdInfo.thTotalProfit));

    //add taxes amount
    pdInfo.thTotalTaxes += KGlobal::locale()->formatMoney(tTaxes, QString(), 2);
    
    if (Settings::smallTicketDotMatrix()) {
      QString printerFile=Settings::printerDevice();
      if (printerFile.length() == 0) printerFile="/dev/lp0";
      QString printerCodec=Settings::printerCodec();
      qDebug()<<"[Printing report on "<<printerFile<<"]";
      qDebug()<<lines.join("\n");
      PrintDEV::printSmallBalance(printerFile, printerCodec, lines.join("\n"));
    } else if (Settings::smallTicketCUPS()) {
      qDebug()<<"[Printing report on CUPS small size]";
      QPrinter printer;
      printer.setFullPage( true );
      QPrintDialog printDialog( &printer );
      printDialog.setWindowTitle(i18n("Print end of day report"));
      if ( printDialog.exec() ) {
      PrintCUPS::printSmallEndOfDay(pdInfo, printer);
      } else {
          //NOTE: This is a proposition:
          //      If the dialog is accepted (ok), then we print what the user choosed. Else, we print to a file (PDF).
          //      The user can press ENTER when dialog appearing if the desired printer is the default (or the only).
          qDebug()<<"User cancelled printer dialog. We export ticket to a file.";
          QString fn = QString("%1/lemon-printing/").arg(QDir::homePath());
          QDir dir;
          if (!dir.exists(fn))
              dir.mkdir(fn);
          fn = fn+QString("endOfDay__%1.pdf").arg(QDateTime::currentDateTime().toString("dd-MMM-yy"));
          qDebug()<<fn;
          
          printer.setOutputFileName(fn);
          printer.setPageMargins(0,0,0,0,QPrinter::Millimeter);
          printer.setPaperSize(QSizeF(72,200), QPrinter::Millimeter); //setting small ticket paper size. 72mm x 200mm
          
          PrintCUPS::printSmallEndOfDay(pdInfo, printer);
      }
    } else { //big printer
      qDebug()<<"[Printing report on CUPS big size]";
      QPrinter printer;
      printer.setFullPage( true );
      QPrintDialog printDialog( &printer );
      printDialog.setWindowTitle(i18n("Print end of day report"));
      if ( printDialog.exec() ) {
	PrintCUPS::printBigEndOfDay(pdInfo, printer);
      }
    }
  }
  delete myDb;
}

void squeezeView::printEndOfMonth()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  
  // Get every transaction from all month, calculate sales, profit, and profit margin (%).
  AmountAndProfitInfo amountProfit;
  PrintEndOfDayInfo pdInfo;
  QList<TransactionInfo> transactionsList;
  
  amountProfit     = myDb->getMonthSalesAndProfit();
  transactionsList = myDb->getMonthTransactions(); //all terminals
  
  pdInfo.storeName = myDb->getConfigStoreName();
  pdInfo.storeAddr = myDb->getConfigStoreAddress();
  pdInfo.storeLogo = myDb->getConfigStoreLogo();
  pdInfo.thTitle   = i18n("End of Month report");
  pdInfo.thTicket  = i18n("Id");
  pdInfo.salesPerson = "";
  pdInfo.terminal  = i18n("All Terminals");
  pdInfo.thDate    = KGlobal::locale()->formatDateTime(QDateTime::currentDateTime(), KLocale::LongDate);
  pdInfo.thTime    = i18n("Time");
  pdInfo.thAmount  = i18n("Amount");
  pdInfo.thProfit  = i18n("Profit");
  pdInfo.thPayMethod = i18n("Date");
  pdInfo.thTotalTaxes= i18n("Total taxes collected for the month: ");
  pdInfo.logoOnTop = myDb->getConfigLogoOnTop();
  pdInfo.thTotalSales  = KGlobal::locale()->formatMoney(amountProfit.amount, QString(), 2);
  pdInfo.thTotalProfit = KGlobal::locale()->formatMoney(amountProfit.profit, QString(), 2);

  QStringList lines;
  lines.append(pdInfo.thTitle);
  lines.append(pdInfo.thDate);
  lines.append(pdInfo.terminal);
  lines.append(pdInfo.thTicket+"    "+pdInfo.thTime+ pdInfo.thAmount+"   "+pdInfo.thProfit+"   "+pdInfo.thPayMethod);
  
  //each transaction...
  double tTaxes = 0;
  for (int i = 0; i < transactionsList.size(); ++i)
  {
    QLocale localeForPrinting; // needed to convert double to a string better
    TransactionInfo info = transactionsList.at(i);
    qDebug()<<" transactions of the Month: i="<<i<<" ID:"<<info.id;
    QString tid      = QString::number(info.id);
    QString hour     = info.time.toString("hh:mm");
    QString amount   = localeForPrinting.toString(info.amount,'f',2);
    QString profit   = localeForPrinting.toString(info.utility, 'f', 2);
    QString payMethod=  info.date.toString("MMM d"); //KGlobal::locale()->formatDate(info.date, KLocale::ShortDate); //date instead of paymethod
    
    QString line     = tid +"|"+ hour +"|"+ amount +"|"+ profit +"|"+ payMethod;
    pdInfo.trLines.append(line);
    lines.append(tid+"  "+hour+"  "+ amount+"  "+profit+"  "+payMethod);
    tTaxes += info.totalTax;
    qDebug()<<"total sale:"<<info.amount<<" taxes this sale:"<<info.totalTax<<" accumulated taxes:"<<tTaxes;
  } //for each item
  
  lines.append(i18n("Total Sales : %1",pdInfo.thTotalSales));
  lines.append(i18n("Total Profit: %1",pdInfo.thTotalProfit));

  //add taxes amount
  pdInfo.thTotalTaxes += KGlobal::locale()->formatMoney(tTaxes, QString(), 2);
  
  if (Settings::smallTicketDotMatrix()) {
    QString printerFile=Settings::printerDevice();
    if (printerFile.length() == 0) printerFile="/dev/lp0";
    QString printerCodec=Settings::printerCodec();
    qDebug()<<"[Printing report on "<<printerFile<<"]";
    qDebug()<<lines.join("\n");
    PrintDEV::printSmallBalance(printerFile, printerCodec, lines.join("\n"));
  } else if (Settings::smallTicketCUPS()) {
    qDebug()<<"[Printing report on CUPS small size]";
    QPrinter printer;
    printer.setFullPage( true );
    QPrintDialog printDialog( &printer );
    printDialog.setWindowTitle(i18n("Print end of Month report"));
    if ( printDialog.exec() ) {
      PrintCUPS::printSmallEndOfDay(pdInfo, printer); //uses the same method for end of month 
    } else {
        //NOTE: This is a proposition:
        //      If the dialog is accepted (ok), then we print what the user choosed. Else, we print to a file (PDF).
        //      The user can press ENTER when dialog appearing if the desired printer is the default (or the only).
        qDebug()<<"User cancelled printer dialog. We export ticket to a file.";
        QString fn = QString("%1/lemon-printing/").arg(QDir::homePath());
        QDir dir;
        if (!dir.exists(fn))
            dir.mkdir(fn);
        fn = fn+QString("endOfMonth__%1.pdf").arg(QDateTime::currentDateTime().toString("dd-MMM-yy"));
        qDebug()<<fn;
        
        printer.setOutputFileName(fn);
        printer.setPageMargins(0,0,0,0,QPrinter::Millimeter);
        printer.setPaperSize(QSizeF(72,200), QPrinter::Millimeter); //setting small ticket paper size. 72mm x 200mm
        
        PrintCUPS::printSmallEndOfDay(pdInfo, printer);
    }
  } else { //big printer
    qDebug()<<"[Printing report on CUPS big size]";
    QPrinter printer;
    printer.setFullPage( true );
    QPrintDialog printDialog( &printer );
    printDialog.setWindowTitle(i18n("Print end of Month report"));
    if ( printDialog.exec() ) {
      PrintCUPS::printBigEndOfDay(pdInfo, printer); //uses the same method for end of month
    }
  }
  delete myDb;
}


void squeezeView::printLowStockProducts()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);

  QList<ProductInfo> products = myDb->getLowStockProducts(Settings::mostSoldMaxValue()); // stockqty < maxLimit
  
  //Header Information
  PrintLowStockInfo plInfo;
  plInfo.storeName = myDb->getConfigStoreName();
  plInfo.storeAddr = myDb->getConfigStoreAddress();
  plInfo.storeLogo = myDb->getConfigStoreLogo();
  plInfo.logoOnTop = myDb->getConfigLogoOnTop();
  plInfo.hTitle    = i18n("Low Stock Products (< %1)", Settings::mostSoldMaxValue());
  plInfo.hDate     = KGlobal::locale()->formatDateTime(QDateTime::currentDateTime(), KLocale::LongDate);
  plInfo.hCode     = i18n("Code");
  plInfo.hDesc     = i18n("Description");
  plInfo.hQty      = i18n("Stock Qty.");
  plInfo.hSoldU    = i18n("Sold");
  plInfo.hUnitStr  = i18n("Units");

  //each product
  for (int i = 0; i < products.size(); ++i)
  { 
    QLocale localeForPrinting;
    ProductInfo info = products.at(i);
    QString code  = QString::number(info.code);
    QString stock = localeForPrinting.toString(info.stockqty,'f',2);
    QString soldU = localeForPrinting.toString(info.soldUnits,'f',2); 
    
    QString line  = code +"|"+ info.desc +"|"+ stock +"|"+ info.unitStr +"|"+ soldU;
    plInfo.pLines.append(line);
  }

  if (Settings::smallTicketDotMatrix()) {
    //     QString printerFile=Settings::printerDevice();
    //     if (printerFile.length() == 0) printerFile="/dev/lp0";
    //     QString printerCodec=Settings::printerCodec();
    //     qDebug()<<"[Printing report on "<<printerFile<<"]";
    //     qDebug()<<lines.join("\n");
    //     PrintDEV::printSmallBalance(printerFile, printerCodec, lines.join("\n"));
  } else if (Settings::smallTicketCUPS()) {
    qDebug()<<"[Printing report on CUPS small size]";
    QPrinter printer;
    printer.setFullPage( true );
    QPrintDialog printDialog( &printer );
    printDialog.setWindowTitle(i18n("Print Low Stock Report"));
    if ( printDialog.exec() ) {
      PrintCUPS::printSmallLowStockReport(plInfo, printer);
    } else {
        //NOTE: This is a proposition:
        //      If the dialog is accepted (ok), then we print what the user choosed. Else, we print to a file (PDF).
        //      The user can press ENTER when dialog appearing if the desired printer is the default (or the only).
        qDebug()<<"User cancelled printer dialog. We export ticket to a file.  :: printLowStockProducts";
        QString fn = QString("%1/lemon-printing/").arg(QDir::homePath());
        QDir dir;
        if (!dir.exists(fn))
            dir.mkdir(fn);
        fn = fn+QString("LowStockReport__%1.pdf").arg(QDateTime::currentDateTime().toString("dd-MMM-yy"));
        qDebug()<<fn;
        
        printer.setOutputFileName(fn);
        printer.setPageMargins(0,0,0,0,QPrinter::Millimeter);
        printer.setPaperSize(QSizeF(72,200), QPrinter::Millimeter); //setting small ticket paper size. 72mm x 200mm
        
        PrintCUPS::printSmallLowStockReport(plInfo, printer);
    }
  } else { //big printer
    qDebug()<<"[Printing report on CUPS big size]";
    QPrinter printer;
    printer.setFullPage( true );
    QPrintDialog printDialog( &printer );
    printDialog.setWindowTitle(i18n("Print Low Stock Report"));
    if ( printDialog.exec() ) {
      PrintCUPS::printBigLowStockReport(plInfo, printer);
    }
  }
  delete myDb;
}

//NOTE: The unlimited stock producs will show 99999.
void squeezeView::printStock()
{
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    
    QList<ProductInfo> products = myDb->getAllProducts(); // does not return grouped products!
    
    //Header Information
    PrintLowStockInfo plInfo;
    plInfo.storeName = myDb->getConfigStoreName();
    plInfo.storeAddr = myDb->getConfigStoreAddress();
    plInfo.storeLogo = myDb->getConfigStoreLogo();
    plInfo.logoOnTop = myDb->getConfigLogoOnTop();
    plInfo.hTitle    = i18n("Product Stock (excluding groups)");
    plInfo.hDate     = KGlobal::locale()->formatDateTime(QDateTime::currentDateTime(), KLocale::LongDate);
    plInfo.hCode     = i18n("Code");
    plInfo.hDesc     = i18n("Description");
    plInfo.hQty      = i18n("Stock Qty.");
    plInfo.hSoldU    = i18n("Sold");
    plInfo.hUnitStr  = i18n("Units");
    
    //each product
    for (int i = 0; i < products.size(); ++i)
    {
        QLocale localeForPrinting;
        ProductInfo info = products.at(i);
        QString code  = QString::number(info.code);
        QString stock = localeForPrinting.toString(info.stockqty,'f',2);
        QString soldU = localeForPrinting.toString(info.soldUnits,'f',2);
        
        QString line  = code +"|"+ info.desc +"|"+ stock +"|"+ info.unitStr +"|"+ soldU;
        plInfo.pLines.append(line);
    }
    
    if (Settings::smallTicketDotMatrix()) {
        //     QString printerFile=Settings::printerDevice();
        //     if (printerFile.length() == 0) printerFile="/dev/lp0";
        //     QString printerCodec=Settings::printerCodec();
        //     qDebug()<<"[Printing report on "<<printerFile<<"]";
        //     qDebug()<<lines.join("\n");
        //     PrintDEV::printSmallBalance(printerFile, printerCodec, lines.join("\n"));
    } else if (Settings::smallTicketCUPS()) {
        qDebug()<<"[Printing report on CUPS small size]";
        QPrinter printer;
        printer.setFullPage( true );
        QPrintDialog printDialog( &printer );
        printDialog.setWindowTitle(i18n("Print Low Stock Report"));
        if ( printDialog.exec() ) {
            PrintCUPS::printSmallLowStockReport(plInfo, printer);
        } else {
            //NOTE: This is a proposition:
            //      If the dialog is accepted (ok), then we print what the user choosed. Else, we print to a file (PDF).
            //      The user can press ENTER when dialog appearing if the desired printer is the default (or the only).
            qDebug()<<"User cancelled printer dialog. We export ticket to a file.  ::PrintStock()";
            QString fn = QString("%1/lemon-printing/").arg(QDir::homePath());
            QDir dir;
            if (!dir.exists(fn))
                dir.mkdir(fn);
            fn = fn+QString("StockReport__%1.pdf").arg(QDateTime::currentDateTime().toString("dd-MMM-yy"));
            qDebug()<<fn;
            
            printer.setOutputFileName(fn);
            printer.setPageMargins(0,0,0,0,QPrinter::Millimeter);
            printer.setPaperSize(QSizeF(72,200), QPrinter::Millimeter); //setting small ticket paper size. 72mm x 200mm
            
            PrintCUPS::printSmallLowStockReport(plInfo, printer);
        }
    } else { //big printer
    qDebug()<<"[Printing report on CUPS big size]";
    QPrinter printer;
    printer.setFullPage( true );
    QPrintDialog printDialog( &printer );
    printDialog.setWindowTitle(i18n("Print Low Stock Report"));
    if ( printDialog.exec() ) {
        PrintCUPS::printBigLowStockReport(plInfo, printer);
    }
}
delete myDb;
}

void squeezeView::printSoldOutProducts()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);

  QList<ProductInfo> products = myDb->getSoldOutProducts();
  
  //Header Information
  PrintLowStockInfo plInfo;
  plInfo.storeName = myDb->getConfigStoreName();
  plInfo.storeAddr = myDb->getConfigStoreAddress();
  plInfo.storeLogo = myDb->getConfigStoreLogo();
  plInfo.logoOnTop = myDb->getConfigLogoOnTop();
  plInfo.hTitle    = i18n("Sold Out Products");
  plInfo.hCode     = i18n("Code");
  plInfo.hDesc     = i18n("Description");
  plInfo.hQty      = i18n("Stock Qty");
  plInfo.hSoldU    = i18n("Sold Units");
  plInfo.hUnitStr  = i18n("Units");
  plInfo.hDate     = KGlobal::locale()->formatDateTime(QDateTime::currentDateTime(), KLocale::LongDate);

  //each product
  for (int i = 0; i < products.size(); ++i)
  { 
    QLocale localeForPrinting;
    ProductInfo info = products.at(i);
    QString code  = QString::number(info.code);
    QString stock = localeForPrinting.toString(info.stockqty,'f',2);
    QString soldU = localeForPrinting.toString(info.soldUnits,'f',2); 
    
    QString line  = code +"|"+ info.desc +"|"+ stock +"|"+ info.unitStr +"|"+ soldU;
    plInfo.pLines.append(line);
  }

  if (Settings::smallTicketDotMatrix()) {
    //     QString printerFile=Settings::printerDevice();
    //     if (printerFile.length() == 0) printerFile="/dev/lp0";
    //     QString printerCodec=Settings::printerCodec();
    //     qDebug()<<"[Printing report on "<<printerFile<<"]";
    //     qDebug()<<lines.join("\n");
    //     PrintDEV::printSmallBalance(printerFile, printerCodec, lines.join("\n"));
  } else if (Settings::smallTicketCUPS()) {
    qDebug()<<"[Printing report on CUPS small size]";
    QPrinter printer;
    printer.setFullPage( true );
    QPrintDialog printDialog( &printer );
    printDialog.setWindowTitle(i18n("Print Sold Out Products"));
    if ( printDialog.exec() ) {
      PrintCUPS::printSmallLowStockReport(plInfo, printer);
    } else {
        //NOTE: This is a proposition:
        //      If the dialog is accepted (ok), then we print what the user choosed. Else, we print to a file (PDF).
        //      The user can press ENTER when dialog appearing if the desired printer is the default (or the only).
        qDebug()<<"User cancelled printer dialog. We export ticket to a file. :: soldOutProducts()";
        QString fn = QString("%1/lemon-printing/").arg(QDir::homePath());
        QDir dir;
        if (!dir.exists(fn))
            dir.mkdir(fn);
        fn = fn+QString("SoldOutReport__%1.pdf").arg(QDateTime::currentDateTime().toString("dd-MMM-yy"));
        qDebug()<<fn;
        
        printer.setOutputFileName(fn);
        printer.setPageMargins(0,0,0,0,QPrinter::Millimeter);
        printer.setPaperSize(QSizeF(72,200), QPrinter::Millimeter); //setting small ticket paper size. 72mm x 200mm
        
        PrintCUPS::printSmallLowStockReport(plInfo, printer);
    }
  } else { //big printer
    qDebug()<<"[Printing report on CUPS big size]";
    QPrinter printer;
    printer.setFullPage( true );
    QPrintDialog printDialog( &printer );
    printDialog.setWindowTitle(i18n("Print Sold Out Products"));
    if ( printDialog.exec() ) {
      PrintCUPS::printBigLowStockReport(plInfo, printer);
    }
  }
  delete myDb;
}

void squeezeView::printSelectedBalance()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  
  qDebug()<<"Print Selected Balance";
  if (db.isOpen()) {
    QModelIndex index = ui_mainview.balancesTable->currentIndex();
    if (balancesModel->tableName().isEmpty()) setupBalancesModel();
    if (index == balancesModel->index(-1,-1) ) {
      KMessageBox::information(this, i18n("Please select a balance to print, then press the print button again."), i18n("Cannot print"));
    }
    else  {
      qulonglong bid = balancesModel->record(index.row()).value("id").toULongLong();
      //get from database all info.
      BalanceInfo info = myDb->getBalanceInfo(bid);
      qDebug()<<"Printing balance id:"<<bid;
      //print...
      PrintBalanceInfo pbInfo;
      pbInfo.thBalanceId = i18n("Balance Id:%1",info.id);
      pbInfo.storeName = myDb->getConfigStoreName();
      pbInfo.storeAddr = myDb->getConfigStoreAddress();
      pbInfo.storeLogo = myDb->getConfigStoreLogo();
      pbInfo.thTitle     = i18n("%1 at Terminal # %2", info.username, info.terminal);
      pbInfo.thDeposit   = i18n("Deposit");
      pbInfo.thIn        = i18n("In");
      pbInfo.thOut       = i18n("Out");
      pbInfo.thInDrawer  = i18n("In Drawer");
      pbInfo.thTitleDetails = i18n("Transactions Details");
      pbInfo.thTrId      = i18n("Id");
      pbInfo.thTrTime    = i18n("Time");
      pbInfo.thTrAmount  = i18n("Amount");
      pbInfo.thTrPaidW    = i18n("Paid");
      pbInfo.thTrPayMethod=i18n("Method");
      pbInfo.startDate   = i18n("Start: %1",KGlobal::locale()->formatDateTime(info.dateTimeStart, KLocale::LongDate));
      pbInfo.endDate     = i18n("End  : %1",KGlobal::locale()->formatDateTime(info.dateTimeEnd, KLocale::LongDate));
      //Qty's
      pbInfo.initAmount = KGlobal::locale()->formatMoney(info.initamount, QString(), 2);
      pbInfo.inAmount   = KGlobal::locale()->formatMoney(info.in, QString(), 2);
      pbInfo.outAmount  = KGlobal::locale()->formatMoney(info.out, QString(), 2);
      pbInfo.cashAvailable=KGlobal::locale()->formatMoney(info.cash, QString(), 2);
      pbInfo.logoOnTop = myDb->getConfigLogoOnTop();
      pbInfo.thTitleCFDetails = i18n("Cash flow Details");
      pbInfo.thCFType    = i18n("Type");
      pbInfo.thCFReason  = i18n("Reason");
      pbInfo.thCFDate    = i18n("Time");
      
      //TXT for dot-matrix printer
      QStringList lines;
      QString line;
      lines.append(i18n("%1 at Terminal # %2", info.username, info.terminal));
      line = QString(KGlobal::locale()->formatDateTime(info.dateTimeEnd, KLocale::LongDate));
      lines.append(line);
      lines.append("----------------------------------------");
      line = QString("%1 %2").arg(i18n("Initial Amount deposited:")).arg(KGlobal::locale()->formatMoney(info.initamount, QString(), 2));
      lines.append(line);
      line = QString("%1 :%2, %3 :%4")
      .arg(i18n("In"))
      .arg(KGlobal::locale()->formatMoney(info.in, QString(), 2))
      .arg(i18n("Out"))
      .arg(KGlobal::locale()->formatMoney(info.out, QString(), 2));
      lines.append(line);
      line = QString(" %1 %2").arg(KGlobal::locale()->formatMoney(info.cash, QString(), 2)).arg(i18n("In Drawer"));
      lines.append(line);
      line = QString("----------%1----------").arg(i18n("Transactions Details"));
      lines.append(line);
      line = QString("%1           %2      %3").arg(i18n("Id")).arg(i18n("Amount")).arg(i18n("Paid"));
      lines.append(line);
      lines.append("----------  ----------  ----------");
      QStringList transactionsByUser = info.transactions.split(",");
      QStringList trList;
      
      QString dId;
      QString dAmount;
      QString dHour;
      QString dMinute;
      QString dPaidWith;
      QString dPayMethod;

      for (int i = 0; i < transactionsByUser.size(); ++i) {
        qulonglong idNum = transactionsByUser.at(i).toULongLong();
        TransactionInfo info;
        info = myDb->getTransactionInfo(idNum);
        
        dId       = QString::number(info.id);
        dAmount   = QString::number(info.amount);
        dHour     = info.time.toString("hh");
        dMinute   = info.time.toString("mm");
        dPaidWith = QString::number(info.paywith);
        
        QString tmp = QString("%1|%2|%3|%4")
        .arg(dId)
        .arg(dHour+":"+dMinute)
        .arg(KGlobal::locale()->formatMoney(info.amount, QString(), 2))
        .arg(KGlobal::locale()->formatMoney(info.paywith, QString(), 2));
        
        while (dId.length()<10) dId = dId.insert(dId.length(), ' ');
        while (dAmount.length()<14) dAmount = dAmount.insert(dAmount.length(), ' ');
        while ((dHour+dMinute).length()<6) dMinute = dMinute.insert(dMinute.length(), ' ');
        while (dPaidWith.length()<10) dPaidWith = dPaidWith.insert(dPaidWith.length(), ' ');

        dPayMethod = myDb->getPayTypeStr(info.paymethod);//using payType methods
        line = QString("%1 %2 %3")
        .arg(dId)
        .arg(dAmount)
        .arg(dPayMethod);
        lines.append(line);
        
        tmp += "|"+dPayMethod;
        trList.append( tmp );
      } //for
      pbInfo.trList = trList;

      //TODO: FIXME to save and retrieve from db the cashflow info for user work lapse.
      //            We can obtain it from cashflow table using a data BETWEEN select
      //get CashOut list and its info...
      QStringList cfList;
      cfList.clear();
      QList<CashFlowInfo> cashflowInfoList = myDb->getCashFlowInfoList(info.dateTimeStart, info.dateTimeEnd);
      foreach(CashFlowInfo cfInfo, cashflowInfoList) {
        QString amountF = KGlobal::locale()->formatMoney(cfInfo.amount);
        QString dateF   = KGlobal::locale()->formatTime(cfInfo.time);
        QString data = QString::number(cfInfo.id) + "|" + cfInfo.typeStr + "|" + cfInfo.reason + "|" + amountF + "|" + dateF;
        cfList.append(data);
        qDebug()<<"cashflow:"<<data;
      }
      pbInfo.cfList = cfList;

      if (Settings::smallTicketDotMatrix()) {
        //print it on the /dev/lpXX...   send lines to print
        if (Settings::printBalances()) {
          QString printerFile=Settings::printerDevice();
          if (printerFile.length() == 0) printerFile="/dev/lp0";
          QString printerCodec=Settings::printerCodec();
          qDebug()<<"[Printing balance on "<<printerFile<<"]";
          PrintDEV::printSmallBalance(printerFile, printerCodec, lines.join("\n"));
        }
      } else if (Settings::printBalances()) {
        //print it on cups... send pbInfo instead
        QPrinter printer;
        printer.setFullPage( true );
        QPrintDialog printDialog( &printer );
        printDialog.setWindowTitle(i18n("Print Balance"));
        if ( printDialog.exec() ) {
          PrintCUPS::printSmallBalance(pbInfo, printer);
        } else {
            //NOTE: This is a proposition:
            //      If the dialog is accepted (ok), then we print what the user choosed. Else, we print to a file (PDF).
            //      The user can press ENTER when dialog appearing if the desired printer is the default (or the only).
            qDebug()<<"User cancelled printer dialog. We export ticket to a file.";
            QString fn = QString("%1/lemon-printing/").arg(QDir::homePath());
            QDir dir;
            if (!dir.exists(fn))
                dir.mkdir(fn);
            fn = fn+QString("balance-%1__%2.pdf").arg(info.id).arg(info.dateTimeStart.date().toString("dd-MMM-yy"));
            qDebug()<<fn;
            
            printer.setOutputFileName(fn);
            printer.setPageMargins(0,0,0,0,QPrinter::Millimeter);
            printer.setPaperSize(QSizeF(72,200), QPrinter::Millimeter); //setting small ticket paper size. 72mm x 200mm
            
            PrintCUPS::printSmallBalance(pbInfo, printer);
        }
      }
      //end print
    }
  }
  delete myDb;
}

//LOGS
void squeezeView::log(const qulonglong &uid, const QDate &date, const QTime &time, const QString &text)
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  myDb->insertLog(uid, date, time, "[SQUEEZE] "+text);
  logsModel->select();
  delete myDb;
}

void squeezeView::showLogs()
{
  ui_mainview.stackedWidget->setCurrentIndex(pBrowseLogs);
  if (logsModel->tableName().isEmpty()) setupLogsModel();
  ui_mainview.headerLabel->setText(i18n("Events Log"));
  ui_mainview.headerImg->setPixmap((DesktopIcon("view-pim-tasks-pending",48)));
}

void squeezeView::setupLogsModel()
{
  openDB();
  qDebug()<<"setup logs msgs model.. after openDB";
  if (db.isOpen()) {
    logsModel->setTable("logs");

    int logIdIndex      = logsModel->fieldIndex("id");
    int logUserIndex    = logsModel->fieldIndex("userid");
    int logActionIndex  = logsModel->fieldIndex("action");
    int logDateIndex    = logsModel->fieldIndex("date");
    int logTimeIndex    = logsModel->fieldIndex("time");

    ui_mainview.logTable->setModel(logsModel);

    logsModel->setHeaderData(logUserIndex,   Qt::Horizontal, i18n("User"));
    logsModel->setHeaderData(logDateIndex,   Qt::Horizontal, i18n("Date"));
    logsModel->setHeaderData(logTimeIndex,   Qt::Horizontal, i18n("Time"));
    logsModel->setHeaderData(logActionIndex, Qt::Horizontal, i18n("Event"));

    ui_mainview.logTable->setColumnHidden(logIdIndex, true);
    logsModel->setRelation(logUserIndex, QSqlRelation("users", "id", "name"));

    ui_mainview.logTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui_mainview.logTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    logsModel->select();
  }
  ui_mainview.logTable->resizeColumnsToContents();

  qDebug()<<"setup Logs.. done, "<<logsModel->lastError();
}

//Random Messages
void squeezeView::setupRandomMsgModel()
{
  openDB();
  qDebug()<<"setup random msgs model.. after openDB";
  if (db.isOpen()) {
    randomMsgModel->setTable("random_msgs");

    int randomMsgIdIndex      = randomMsgModel->fieldIndex("id");
    int randomMsgMessageIndex = randomMsgModel->fieldIndex("message");
    int randomMsgSeasonIndex  = randomMsgModel->fieldIndex("season");
    int randomMsgCountIndex   = randomMsgModel->fieldIndex("count");

    ui_mainview.randomMsgTable->setModel(randomMsgModel);

    randomMsgModel->setHeaderData(randomMsgMessageIndex, Qt::Horizontal, i18n("Message"));
    randomMsgModel->setHeaderData(randomMsgSeasonIndex, Qt::Horizontal, i18n("Month"));

    ui_mainview.randomMsgTable->setColumnHidden(randomMsgIdIndex, true);
    ui_mainview.randomMsgTable->setColumnHidden(randomMsgCountIndex, true);

    ui_mainview.randomMsgTable->setSelectionMode(QAbstractItemView::SingleSelection);

    randomMsgModel->select();


    //TODO:validator for months
    //ui_mainview.randomMsgTable->setItemDelegate( );
    
  }
  ui_mainview.randomMsgTable->resizeColumnsToContents();

  //qDebug()<<"setup RandomMsg.. done, "<<randomMsgModel->lastError();
}

void squeezeView::createRandomMsg()
{
 if (db.isOpen()) {
  InputDialog *dlg = new InputDialog(this, true, dialogTicketMsg, i18n("Enter the new ticket message."), 1, 12);

  if (dlg->exec()) {
    Azahar *myDb = new Azahar;
    if (!db.isOpen()) openDB();
    myDb->setDatabase(db);
    if (!myDb->insertRandomMessage(dlg->reason, dlg->iValue)) qDebug()<<"Error:"<<myDb->lastError();
    randomMsgModel->select();
    delete myDb;
  }
 }
}

void squeezeView::createCurrency()
{
    if (db.isOpen()) {
        InputDialog *dlg = new InputDialog(this, false, dialogCurrency, i18n("Enter the new currency"));
        
        if (dlg->exec()) {
            Azahar *myDb = new Azahar;
            if (!db.isOpen()) openDB();
            myDb->setDatabase(db);
            if (!myDb->insertCurrency(dlg->reason, dlg->dValue)) qDebug()<<"Error:"<<myDb->lastError();
            currenciesModel->select();
            delete myDb;
        }
    }  
}

void squeezeView::deleteSelectedCurrency()
{
    if (db.isOpen()) {
        QModelIndex index = ui_mainview.tableCurrencies->currentIndex();
        if (currenciesModel->tableName().isEmpty()) setupCurrenciesModel();
        if (index == currenciesModel->index(-1,-1) ) {
            KMessageBox::information(this, i18n("Please select a row to delete, then press the delete button again."), i18n("Cannot delete"));
        }
        else  {
            QString text = currenciesModel->record(index.row()).value("name").toString();
            Azahar *myDb = new Azahar;
            myDb->setDatabase(db);
            qulonglong cId = myDb->getCurrency(text).id;
            if (cId > 1) {
                int answer = KMessageBox::questionYesNo(this, i18n("Do you really want to delete the currency '%1'?", text),
                i18n("Delete"));
                if (answer == KMessageBox::Yes) {
                    qulonglong  iD = currenciesModel->record(index.row()).value("id").toULongLong();
                    if (!currenciesModel->removeRow(index.row(), index)) {
                        bool d = myDb->deleteCurrency(iD); qDebug()<<"Deleteing currency ("<<iD<<") manually...";
                        if (d) qDebug()<<"Deletion succed...";
                    }
                    currenciesModel->submitAll();
                    currenciesModel->select();
                }
            } else KMessageBox::information(this, i18n("Default currencies cannot be deleted."), i18n("Cannot delete"));
                    delete myDb;
        }
    }
}

void squeezeView::reSelectModels()
{
  qDebug()<<"Updating Models from database...";
  if ( modelsAreCreated() ) {
    productsModel->select();
    measuresModel->select();
    clientsModel->select();
    usersModel->select();
    transactionsModel->select();
    categoriesModel->select();
    offersModel->select();
    balancesModel->select();
    cashflowModel->select();
    specialOrdersModel->select();
    randomMsgModel->select();
    logsModel->select();
    currenciesModel->select();
  }
}


//FACTURACION MX
void squeezeView::agregarSerieFolios()
{
    qDebug()<<"Agregando serie de folios CBB...";
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    DialogSerieFolios *dlgF = new DialogSerieFolios(this);

    if (dlgF->exec()) {
        //get data
        FoliosPool pool;
        pool.fechaAprobacion = dlgF->getFechaAprobacion();
        pool.numAprobacion   = dlgF->getNumeroAprobacion();
        pool.folioInicial    = dlgF->getFolioInicial();
        pool.folioFinal      = dlgF->getFolioFinal();
        pool.cbb             = Misc::pixmap2ByteArray(new QPixmap(dlgF->getCBB()), false); //do not scale
        pool.cantidadFolios  = dlgF->getCantidadFolios();
        bool inserted = myDb->insertSerieFolios(pool);

        if (inserted) {
            //inform how many folios where added.
            QMessageBox::information(this, i18n("Serie de folios"),i18n("Se agregaron %1 folios.", pool.cantidadFolios), QMessageBox::Ok);
        } else {
            //inform about errors.
            QMessageBox::critical(this, i18n("No se pudo agregar folios"),myDb->lastError(), QMessageBox::Ok);
        }
    }

    delete myDb;
    delete dlgF;
}


void squeezeView::cancelarFactura()
{
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);

    bool ok;
    QString folio = QInputDialog::getText(this, i18n("Cancelar Factura"), i18n("Folio de la Factura:"), QLineEdit::Normal, "", &ok);
    if (ok && !folio.isEmpty()) {
        //get invoice data.
        FacturaCBB factura = myDb->getFacturaInfo(folio);
        qDebug()<<"Cancelando Factura:"<<factura.folio;
        if (factura.folio == folio && factura.valida) {
            bool r = myDb->cancelFactura( folio ); //this cancels the invoice as well as the folio itself.
            if (r)
                QMessageBox::information(this, i18n("Cancelación de factura"),i18n("Se cancelo la factura con folio %1.",folio), QMessageBox::Ok);
            else
                QMessageBox::information(this, i18n("Cancelación de factura"),i18n("No se pudo cancelar la factura con folio %1.\n Detalle:",folio, myDb->lastError()), QMessageBox::Ok);
            qDebug()<<"Factura Cancelada:"<<r;
        } else {
            if (factura.folio == folio && !factura.valida)
                QMessageBox::critical(this, i18n("Cancelación de factura"),i18n("La factura %1 ya estaba cancelada", folio), QMessageBox::Ok);
            else if ( factura.folio.isEmpty() || factura.folio == " " )
                QMessageBox::critical(this, i18n("Cancelación de factura"),i18n("La factura %1 no existe.", folio), QMessageBox::Ok);
            else
                qDebug()<<"Factura invalida, inexistente o ya cancelada...";
        }
    }
    delete myDb;
}

void squeezeView::departmentsOnSelected(const QModelIndex &index)
{
    if (db.isOpen()) {
        //getting data from model...
        const QAbstractItemModel *model = index.model();
        int row = index.row();
        QModelIndex indx = model->index(row, departmentsModel->fieldIndex("id"));
        qulonglong depId = model->data(indx, Qt::DisplayRole).toULongLong();
        indx = model->index(row, departmentsModel->fieldIndex("text"));
        QString name = model->data(indx, Qt::DisplayRole).toString();

        QStringList children;
        Azahar *myDb = new Azahar;
        myDb->setDatabase(db);
        //get child categories
        children = myDb->getCategoriesList(depId);//get the categories whose parent is depId.
        qDebug()<<"DEPARTMENT "<<name<<" ["<<depId<<"]"<<" CHILDREN:"<<children;

        //launch the editor.
        SubcategoryEditor *scEditor = new SubcategoryEditor(this);
        scEditor->setDb(db);
        scEditor->setCatList( children );
        scEditor->setScatList( myDb->getSubCategoriesList() );
        scEditor->populateList( myDb->getCategoriesList(), children );
        scEditor->setDialogType(1); //department = 1
        scEditor->setLabelForName(i18n("Department:"));
        scEditor->setLabelForList(i18n("Child categories for this department:"));
        scEditor->setName(name);

        //check for any changes...
        if ( scEditor->exec() ) {
            QString newName = scEditor->getName();
            QStringList newChildren = scEditor->getChildren();
            qDebug()<<"NEW NAME:"<<newName<<" CHILDREN:"<<newChildren;
            //first see if the name changed.
            if (name != newName) {
                //rename the department
                myDb->updateDepartment(depId, newName);
            }
            //then see if any category has been added or any removed
            if ( children != newChildren ){
                qDebug()<<"children != newChildren ...";
                //condicinoes a checar:  Es nueva, No esta pero estaba,
                foreach(QString e, newChildren) {
                    //check if the child is in the old children.
                    if (children.contains(e)){
                        ///old list contains 'e', it means it already was on the list, we do not need to do anything.
                    } else {
                        ///old list does not contains 'e', this means that 'e' is a new child.
                        //get its ID to make m2m connections.
                        qulonglong catId = myDb->getCategoryId(e);
                        qDebug()<<"NEW ELEMENT: "<<e<<" ["<<catId<<"]";
                        myDb->insertM2MDepartmentCategory(depId, catId);
                    }
                }
                //until here, we examined newChildren, but we need to know if any of the children was REMOVED (not present in newChildren)
                //this is not a efficient way, we are duplicating the comparisons.
                foreach(QString e, children){
                    if ( !newChildren.contains(e) ){
                        // 'e' is NOT in the newChildren then remove the m2m connection.
                        qulonglong catId = myDb->getCategoryId(e);
                        if (!myDb->m2mDepartmentCategoryRemove(depId, catId)){
                            qDebug()<<"m2m Department -> Category could not be removed. "<<name<<"->"<<e<<" |"<<myDb->lastError();
                        }
                    }
                }//for each children
            }//if children != newChildren
        }//if scEditor->exec
        departmentsModel->select();
        delete myDb;
    }
}


void squeezeView::categoriesOnSelected(const QModelIndex &index)
{
    if (db.isOpen()) {
        //getting data from model...
        const QAbstractItemModel *model = index.model();
        int row = index.row();
        QModelIndex indx = model->index(row, categoriesModel->fieldIndex("catid"));
        qulonglong catId = model->data(indx, Qt::DisplayRole).toULongLong();
        indx = model->index(row, categoriesModel->fieldIndex("text"));
        QString name = model->data(indx, Qt::DisplayRole).toString();
        
        QStringList children;
        Azahar *myDb = new Azahar;
        myDb->setDatabase(db);
        //get child categories
        children = myDb->getSubCategoriesList(catId);//get the categories whose parent is depId.
        qDebug()<<"CATEGORY "<<name<<" ["<<catId<<"]"<<" CHILDREN:"<<children;
        
        //launch the editor.
        QStringList subcat = myDb->getSubCategoriesList();
        SubcategoryEditor *scEditor = new SubcategoryEditor(this);
        scEditor->setDb(db);
        scEditor->setCatList( myDb->getCategoriesList() );
        scEditor->setScatList( subcat );
        scEditor->populateList( subcat, children );
        scEditor->setDialogType(1); //department = 1
        scEditor->setLabelForName(i18n("Category:"));
        scEditor->setLabelForList(i18n("Child subcategories for this category:"));
        scEditor->setName(name);
        
        //check for any changes...
        if ( scEditor->exec() ) {
            QString newName = scEditor->getName();
            QStringList newChildren = scEditor->getChildren();
            qDebug()<<"NEW NAME:"<<newName<<" CHILDREN:"<<newChildren;
            //first see if the name changed.
            if (name != newName) {
                //rename the department
                myDb->updateCategory(catId, newName);
            }
            //then see if any category has been added or any removed
            if ( children != newChildren ){
                qDebug()<<"children != newChildren ...";
                //condicinoes a checar:  Es nueva, No esta pero estaba,
                foreach(QString e, newChildren) {
                    //check if the child is in the old children.
                    if (children.contains(e)){
                        ///old list contains 'e', it means it already was on the list, we do not need to do anything.
                    } else {
                        ///old list does not contains 'e', this means that 'e' is a new child.
                        //get its ID to make m2m connections.
                        qulonglong scatId = myDb->getSubCategoryId(e);
                        qDebug()<<"NEW ELEMENT: "<<e<<" ["<<scatId<<"]";
                        myDb->insertM2MCategorySubcategory(catId, scatId);
                    }
                }
                //until here, we examined newChildren, but we need to know if any of the children was REMOVED (not present in newChildren)
                //this is not a efficient way, we are duplicating the comparisons.
                foreach(QString e, children){
                    if ( !newChildren.contains(e) ){
                        // 'e' is NOT in the newChildren then remove the m2m connection.
                        qulonglong scatId = myDb->getSubCategoryId(e);
                        if (!myDb->m2mCategorySubcategoryRemove(catId, scatId)){
                            qDebug()<<"m2m Category -> SubCategory could not be removed. "<<name<<"->"<<e<<" |"<<myDb->lastError();
                        }
                    }
                }//for each children
            }//if children != newChildren
        }//if scEditor->exec
        categoriesModel->select();
        delete myDb;
    }
}

#include "squeezeview.moc"
