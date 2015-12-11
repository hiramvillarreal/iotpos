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

#include "squeeze.h"
#include "squeezeview.h"
#include "settings.h"

#include <qapplication.h>
#include <qpainter.h>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QPrinter>
#include <QTimer>
#include <QDesktopWidget>

#include <kdeversion.h>
#include <kglobal.h>
#include <kiconloader.h>
#include <kmenubar.h>
#include <kstatusbar.h>
#include <kconfigdialog.h>
//#include <kio/netaccess.h>
// #include <kfiledialog.h>
#include <kactioncollection.h>
#include <kaction.h>
#include <KLocale>
#include <kled.h>
#include <kstandarddirs.h>

squeeze::squeeze()
    : KXmlGuiWindow( ),
      m_view(new squeezeView(this)),
      m_printer(0)
{
    setObjectName(QLatin1String("squeeze"));
    // accept dnd
    setAcceptDrops(false);

    // tell the KXmlGuiWindow that this is indeed the main widget
    setCentralWidget(m_view);

    // then, setup our actions
    setupActions();
    //Add some widgets to status bar
    led = new KLed;
    led->off();
    statusBar()->addWidget(led); //FIXME: Que cuando se escriba algo en la barra de status, quede el LED ahi tambien.
    // add a status bar
    statusBar()->show();

    // Add typical actions and save size/toolbars/statusbar
    setupGUI();
    disableUI();
    // allow the view to change the statusbar and caption
    connect(m_view, SIGNAL(signalChangeStatusbar(const QString&)),
            this,   SLOT(changeStatusbar(const QString&)));
    connect(m_view, SIGNAL(signalChangeCaption(const QString&)),
            this,   SLOT(changeCaption(const QString&)));

    connect(m_view, SIGNAL(signalDisconnected()), this, SLOT(setDisconnected()));
    connect(m_view, SIGNAL(signalConnected()), this, SLOT(setConnected()));

    connect(m_view, SIGNAL(signalShowPrefs()), SLOT(optionsPreferences()) );

    connect(m_view, SIGNAL(signalSalir() ), SLOT(salir() ));

    connect(m_view, SIGNAL(signalShowDbConfig()), this, SLOT(showDBConfigDialog()));


    connect(m_view, SIGNAL(signalAdminLoggedOn()), this, SLOT(enableUI()));
    connect(m_view, SIGNAL(signalAdminLoggedOff()), this, SLOT(disableUI()));
    connect(m_view, SIGNAL(signalSupervisorLoggedOn()), this, SLOT(enableUI()));


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(fixGeom()));
    timer->setInterval(5000);
    //timer->start();
    

    loadStyle();
}

squeeze::~squeeze()
{
    delete m_printer;
}

//NOTE: There is a problem with taskbar panel applets on the desktop (plasma widgets), the 145 pixels is a simple qty that works for me.
void squeeze::fixGeom()
{
  //qDebug()<<"Window Size:"<<geometry()<<"desktop size:"<<QApplication::desktop()->screenGeometry(this);
  if (geometry().height() > (QApplication::desktop()->screenGeometry(this).height()-115)) {
    QRect geom = geometry();
    geom.setHeight(QApplication::desktop()->screenGeometry(this).height()-145);
    geom.setWidth(QApplication::desktop()->screenGeometry(this).width()-5);
    m_view->setMaximumSize(geom.width(),geom.height());
    //setMaximumSize(geom.width()+5,geom.height()+10);
  }
}

void squeeze::loadStyle()
{
  qDebug()<<"Loading Stylesheet...";

    //Load a simple style...
    QString fileName; QString path;
    path = KStandardDirs::locate("appdata", "styles/");
    fileName = path + Settings::styleName() + "/simple.qss";
    qDebug()<<"Style file:"<<fileName;
    QFile file(fileName);
    bool op = file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    //replace fakepath to the real path..
    QString finalStyle = styleSheet.replace("[STYLE_PATH]", path + Settings::styleName() + "/");
    qApp->setStyleSheet(finalStyle);
    if (op) file.close();
}

void squeeze::setConnected()
{
  //a workaround.. just to dont modify the code in squeezeview
  setConnection(true);
}

void squeeze::setDisconnected()
{
  //a workaround.. just to dont modify the code in squeezeview
  setConnection(false);
}

void squeeze::setConnection(bool yes)
{
  if ( yes ) {
    led->on();
    enableUI();
  } else {
    led->off();
    disableUI();
  }
}

void squeeze::enableUI()
{
  qDebug()<<"Enabling Actions..";
  QAction *action = actionCollection()->action("login");
  action->setEnabled(true);
  if (m_view->isAdminUser()) {
    qDebug()<<"Enabling for admin";
    action = actionCollection()->action("productsBrowse");
    action->setEnabled(true);
    action = actionCollection()->action("offersBrowse");
    action->setEnabled(true);
    action = actionCollection()->action("measuresBrowse");
    action->setEnabled(true);
    action = actionCollection()->action("departmentsBrowse");
    action->setEnabled(true);
    action = actionCollection()->action("categoriesBrowse");
    action->setEnabled(true);
    action = actionCollection()->action("subcategoriesBrowse");
    action->setEnabled(true);
    action = actionCollection()->action("balancesBrowse");
    action->setEnabled(true);
    action = actionCollection()->action("transactionsBrowse");
    action->setEnabled(true);
    action = actionCollection()->action("doPurchase");
    action->setEnabled(true);
    action = actionCollection()->action(KStandardAction::name(KStandardAction::Preferences));
    action->setEnabled(true);
    //action = actionCollection()->action("checkOut");
    //action->setEnabled(true);
    action = actionCollection()->action("reports");
    action->setEnabled(true);
    action = actionCollection()->action("quickViewPlots");
    action->setEnabled(true);
    action = actionCollection()->action("cashFlowBrowse");
    action->setEnabled(true);
    action = actionCollection()->action("stockCorrection");
    action->setEnabled(true);
    action = actionCollection()->action("viewLog");
    action->setEnabled(true);
    action = actionCollection()->action("randomMsgsBrowse");
    action->setEnabled(true);
    action = actionCollection()->action("showSpecialOrders");
    action->setEnabled(true);
    action = actionCollection()->action("printSoldOut");
    action->setEnabled(true);
    action = actionCollection()->action("printLowStock");
    action->setEnabled(true);
    action = actionCollection()->action("printEndOfMonth");
    action->setEnabled(true);
    action = actionCollection()->action("printEndOfDayGral");
    action->setEnabled(true);
    action = actionCollection()->action("printEndOfDay");
    action->setEnabled(true);
    action = actionCollection()->action("currenciesBrowse");
    action->setEnabled(true);
    action = actionCollection()->action("reservationsBrowse");
    action->setEnabled(true);
    action = actionCollection()->action("cancelarFactura");
    action->setEnabled(true);
  }
  qDebug()<<"Enabling others..";
  action = actionCollection()->action("usersBrowse");
  action->setEnabled(true);
  action = actionCollection()->action("clientsBrowse");
  action->setEnabled(true);
}

void squeeze::disableUI()
{   qDebug()<<"Disabling Actions..";
  QAction *action = actionCollection()->action("productsBrowse");
  action->setDisabled(true);
  action = actionCollection()->action("offersBrowse");
  action->setDisabled(true);
  action = actionCollection()->action("measuresBrowse");
  action->setDisabled(true);
  action = actionCollection()->action("departmentsBrowse");
  action->setDisabled(true);
  action = actionCollection()->action("categoriesBrowse");
  action->setDisabled(true);
  action = actionCollection()->action("subcategoriesBrowse");
  action->setDisabled(true);
  action = actionCollection()->action("balancesBrowse");
  action->setDisabled(true);
  action = actionCollection()->action("transactionsBrowse");
  action->setDisabled(true);
  action = actionCollection()->action("doPurchase");
  action->setDisabled(true);
  action = actionCollection()->action(KStandardAction::name(KStandardAction::Preferences));
  action->setDisabled(true);
  action = actionCollection()->action("clientsBrowse");
  action->setDisabled(true);
  action = actionCollection()->action("usersBrowse");
  action->setDisabled(true);
  action = actionCollection()->action("checkOut");
  action->setDisabled(true);
  action = actionCollection()->action("reports");
  action->setDisabled(true);
  action = actionCollection()->action("quickViewPlots");
  action->setDisabled(true);
  action = actionCollection()->action("cashFlowBrowse");
  action->setDisabled(true);
  action = actionCollection()->action("stockCorrection");
  action->setDisabled(true);
  action = actionCollection()->action("viewLog");
  action->setDisabled(true);
  action = actionCollection()->action("randomMsgsBrowse");
  action->setDisabled(true);
  action = actionCollection()->action("showSpecialOrders");
  action->setDisabled(true);
  action = actionCollection()->action("printSoldOut");
  action->setDisabled(true);
  action = actionCollection()->action("printLowStock");
  action->setDisabled(true);
  action = actionCollection()->action("printEndOfMonth");
  action->setDisabled(true);
  action = actionCollection()->action("printEndOfDayGral");
  action->setDisabled(true);
  action = actionCollection()->action("printEndOfDay");
  action->setDisabled(true);
  action = actionCollection()->action("currenciesBrowse");
  action->setDisabled(true);
  action = actionCollection()->action("reservationsBrowse");
  action->setDisabled(true);
  action = actionCollection()->action("cancelarFactura");
  action->setDisabled(true);
  
}

void squeeze::setupActions()
{
    KStandardAction::quit(qApp, SLOT(quit()), actionCollection());
    KStandardAction::preferences(this, SLOT(optionsPreferences()), actionCollection());

    //My actions
    QAction* loginAction =  actionCollection()->addAction( "login" );
    loginAction->setText(i18n("Login"));
    loginAction->setIcon(KIcon("office-address-book"));
    loginAction->setShortcut(Qt::CTRL+Qt::Key_L);
    connect(loginAction, SIGNAL(triggered(bool)),m_view, SLOT(login()));

    QAction* usersBrowseAction =  actionCollection()->addAction( "usersBrowse" );
    usersBrowseAction->setText(i18n("Users"));
    usersBrowseAction->setIcon(KIcon("lemon-user"));
    usersBrowseAction->setShortcut(Qt::CTRL+Qt::Key_U);
    connect(usersBrowseAction, SIGNAL(triggered(bool)),m_view, SLOT(showUsersPage()));

    QAction* clientsBrowseAction =  actionCollection()->addAction( "clientsBrowse" );
    clientsBrowseAction->setText(i18n("Clients"));
    clientsBrowseAction->setIcon(KIcon("lemon-user"));//TODO:Create an icon for this...
    clientsBrowseAction->setShortcut(Qt::CTRL+Qt::Key_I);
    connect(clientsBrowseAction, SIGNAL(triggered(bool)),m_view, SLOT(showClientsPage()));

    QAction* prodBrowseAction =  actionCollection()->addAction( "productsBrowse" );
    prodBrowseAction->setText(i18n("Products"));
    prodBrowseAction->setIcon(KIcon("lemon-box"));
    prodBrowseAction->setShortcut(Qt::CTRL+Qt::Key_P);
    connect(prodBrowseAction, SIGNAL(triggered(bool)),m_view, SLOT(showProductsPage()));
    
    QAction* measuresBrowseAction =  actionCollection()->addAction( "measuresBrowse" );
    measuresBrowseAction->setText(i18n("Measures"));
    measuresBrowseAction->setIcon(KIcon("lemon-ruler"));
    measuresBrowseAction->setShortcut(Qt::CTRL+Qt::Key_M);
    connect(measuresBrowseAction, SIGNAL(triggered(bool)),m_view, SLOT(showMeasuresPage()));

    QAction* departmentsBrowseAction =  actionCollection()->addAction( "departmentsBrowse" );
    departmentsBrowseAction->setText(i18n("Departments"));
    departmentsBrowseAction->setIcon(KIcon("lemon-categories"));
    departmentsBrowseAction->setShortcut(Qt::CTRL+Qt::Key_C);
    connect(departmentsBrowseAction, SIGNAL(triggered(bool)),m_view, SLOT(showDepartmentsPage()));

    QAction* categoriesBrowseAction =  actionCollection()->addAction( "categoriesBrowse" );
    categoriesBrowseAction->setText(i18n("Categories"));
    categoriesBrowseAction->setIcon(KIcon("lemon-categories"));
    categoriesBrowseAction->setShortcut(Qt::CTRL+Qt::Key_C);
    connect(categoriesBrowseAction, SIGNAL(triggered(bool)),m_view, SLOT(showCategoriesPage()));

    QAction* subcategoriesBrowseAction =  actionCollection()->addAction( "subcategoriesBrowse" );
    subcategoriesBrowseAction->setText(i18n("Subcategories"));
    subcategoriesBrowseAction->setIcon(KIcon("lemon-categories"));
    subcategoriesBrowseAction->setShortcut(Qt::CTRL+Qt::Key_S); //see if it not causes troubles... CTRL-S
    connect(subcategoriesBrowseAction, SIGNAL(triggered(bool)),m_view, SLOT(showSubCategoriesPage()));

    QAction* offersBrowseAction =  actionCollection()->addAction( "offersBrowse" );
    offersBrowseAction->setText(i18n("Offers"));
    offersBrowseAction->setIcon(KIcon("lemon-offers"));
    offersBrowseAction->setShortcut(Qt::CTRL+Qt::Key_O);
    connect(offersBrowseAction, SIGNAL(triggered(bool)),m_view, SLOT(showOffersPage()));

    QAction* balancesBrowseAction =  actionCollection()->addAction( "balancesBrowse" );
    balancesBrowseAction->setText(i18n("Balances"));
    balancesBrowseAction->setIcon(KIcon("lemonbalance"));
    balancesBrowseAction->setShortcut(Qt::CTRL+Qt::Key_B);
    connect(balancesBrowseAction, SIGNAL(triggered(bool)),m_view, SLOT(showBalancesPage()));

    QAction* cashFlowBrowseAction =  actionCollection()->addAction( "cashFlowBrowse" );
    cashFlowBrowseAction->setText(i18n("Cash Flow"));
    cashFlowBrowseAction->setIcon(KIcon("lemon-cashout"));
    cashFlowBrowseAction->setShortcut(Qt::CTRL+Qt::Key_F);
    connect(cashFlowBrowseAction, SIGNAL(triggered(bool)),m_view, SLOT(showCashFlowPage()));

    QAction* transactionsBrowseAction =  actionCollection()->addAction( "transactionsBrowse" );
    transactionsBrowseAction->setText(i18n("Transactions"));
    transactionsBrowseAction->setIcon(KIcon("wallet-open"));
    transactionsBrowseAction->setShortcut(Qt::CTRL+Qt::Key_T);
    connect(transactionsBrowseAction, SIGNAL(triggered(bool)),m_view, SLOT(showTransactionsPage()));

    QAction* quickViewPlotsAction =  actionCollection()->addAction( "quickViewPlots" );
    quickViewPlotsAction->setText(i18n("Quick Plots"));
    quickViewPlotsAction->setIcon(KIcon("view-statistics"));
    quickViewPlotsAction->setShortcut(Qt::CTRL+Qt::Key_W);
    connect(quickViewPlotsAction, SIGNAL(triggered(bool)),m_view, SLOT(showWelcomeGraphs()));

    QAction* purchaseAction =  actionCollection()->addAction( "doPurchase" ); //Alias Check IN
    purchaseAction->setText(i18n("Purchase"));
    purchaseAction->setIcon(KIcon("lemon-box"));
    purchaseAction->setShortcut(Qt::Key_F2);
    connect(purchaseAction, SIGNAL(triggered(bool)),m_view, SLOT(doPurchase()));

    QAction* checkOutAction =  actionCollection()->addAction( "checkOut" );
    checkOutAction->setText(i18n("Check Out"));
    checkOutAction->setIcon(KIcon("lemon-money"));//TODO:Create an icon for this...
    checkOutAction->setShortcut(Qt::Key_F3);
    connect(checkOutAction, SIGNAL(triggered(bool)),m_view, SLOT(doCheckOut()));

    QAction* stockCorrectionAction =  actionCollection()->addAction( "stockCorrection" );
    stockCorrectionAction->setText(i18n("Stock Correction"));
    stockCorrectionAction->setIcon(KIcon("lemon-box"));//TODO:Create an icon for this...
    stockCorrectionAction->setShortcut(Qt::Key_F4);
    connect(stockCorrectionAction, SIGNAL(triggered(bool)),m_view, SLOT(stockCorrection()));

    QAction* reportsAction =  actionCollection()->addAction( "reports" );
    reportsAction->setText(i18n("Reports"));
    reportsAction->setIcon(KIcon("lemon-reports"));
    reportsAction->setShortcut(Qt::Key_F5);
    connect(reportsAction, SIGNAL(triggered(bool)),m_view, SLOT(showReports()));

    QAction *action = actionCollection()->addAction( "printEndOfDay" );
    action->setText(i18n("Print End of day report"));
    action->setIcon(KIcon("lemon-reports"));
    action->setShortcut(Qt::Key_F6);
    connect(action, SIGNAL(triggered(bool)),m_view, SLOT(printEndOfDay()));
    
    action = actionCollection()->addAction( "printEndOfDayGral" );
    action->setText(i18n("Print General end of day report"));
    action->setIcon(KIcon("lemon-reports"));
    action->setShortcut(Qt::Key_F7);
    connect(action, SIGNAL(triggered(bool)),m_view, SLOT(printGralEndOfDay()));

    action = actionCollection()->addAction( "printEndOfMonth" );
    action->setText(i18n("Print End of month report"));
    action->setIcon(KIcon("lemon-reports"));
    action->setShortcut(Qt::Key_F8);
    connect(action, SIGNAL(triggered(bool)),m_view, SLOT(printEndOfMonth()));

    action = actionCollection()->addAction( "printLowStock" );
    action->setText(i18n("Print Low stock products"));
    action->setIcon(KIcon("lemon-reports"));
    action->setShortcut(Qt::Key_F9);
    connect(action, SIGNAL(triggered(bool)),m_view, SLOT(printLowStockProducts()));

    action = actionCollection()->addAction( "printSoldOut" );
    action->setText(i18n("Print Sold out products"));
    action->setIcon(KIcon("lemon-reports"));
    action->setShortcut(Qt::Key_F10);
    connect(action, SIGNAL(triggered(bool)),m_view, SLOT(printSoldOutProducts()));

    action = actionCollection()->addAction( "showSpecialOrders" );
    action->setText(i18n("Show Special Orders"));
    action->setIcon(KIcon("lemon-box")); //FIXME: Create an ICON
    action->setShortcut(Qt::Key_Insert);
    connect(action, SIGNAL(triggered(bool)),m_view, SLOT(showSpecialOrders()));

    action = actionCollection()->addAction( "randomMsgsBrowse" );
    action->setText(i18n("Ticket Messages"));
    action->setIcon(KIcon("lemon-ticket"));
    action->setShortcut(Qt::CTRL+Qt::Key_M);
    connect(action, SIGNAL(triggered(bool)),m_view, SLOT(showRandomMsgs()));

    action = actionCollection()->addAction( "viewLog" );
    action->setText(i18n("View Events Log"));
    action->setIcon(KIcon("view-pim-tasks-pending"));
    action->setShortcut(Qt::CTRL+Qt::Key_G);
    connect(action, SIGNAL(triggered(bool)),m_view, SLOT(showLogs()));

    action = actionCollection()->addAction( "currenciesBrowse" );
    action->setText(i18n("View Currencies"));
    action->setIcon(KIcon("lemon-money"));
    action->setShortcut(Qt::ALT+Qt::Key_C);
    connect(action, SIGNAL(triggered(bool)),m_view, SLOT(showCurrencies()));

    action = actionCollection()->addAction( "reservationsBrowse" );
    action->setText(i18n("View Reservations"));
    action->setIcon(KIcon("lemon-box"));
    action->setShortcut(Qt::ALT+Qt::Key_R);
    connect(action, SIGNAL(triggered(bool)),m_view, SLOT(showReservations()));

    action = actionCollection()->addAction( "agregarSerieFolios" );
    action->setText(i18n("Agregar Serie de Folios"));
    action->setIcon(KIcon("lemon-ticket"));
    action->setShortcut(Qt::ALT+Qt::Key_F);
    connect(action, SIGNAL(triggered(bool)),m_view, SLOT(agregarSerieFolios()));

    action = actionCollection()->addAction( "cancelarFactura" );
    action->setText(i18n("Cancelar una factura"));
    action->setIcon(KIcon("lemon-ticket-cancel"));
    action->setShortcut(Qt::CTRL+Qt::ALT+Qt::Key_F);
    connect(action, SIGNAL(triggered(bool)),m_view, SLOT(cancelarFactura()));

}

/**This is used to get Database user,password,server to set initial config, in case the db server is remote.
So we show the config dialog, and when saved login again. It is called from main_view.login()
**/
void squeeze::showDBConfigDialog()
{
  //avoid to have 2 dialogs shown
  if ( KConfigDialog::showDialog( "settings" ) )  {
    return;
  }
  KConfigDialog *dialog = new KConfigDialog(this, "settings", Settings::self());
  
  QWidget *dbSettingsDlg = new QWidget;
  ui_prefs_db.setupUi(dbSettingsDlg);
  dialog->addPage(dbSettingsDlg, i18n("Database"), "vcs_diff"); //kexi
  
  connect(dialog, SIGNAL(settingsChanged(QString)), m_view, SLOT(settingsChangedOnInitConfig()));
  dialog->setAttribute( Qt::WA_DeleteOnClose );
  dialog->show();
  
  
}

void squeeze::optionsPreferences()
{
    //avoid to have 2 dialogs shown
    if ( KConfigDialog::showDialog( "settings" ) )  {
        return;
    }
    KConfigDialog *dialog = new KConfigDialog(this, "settings", Settings::self());

    //general
    QWidget *generalSettingsDlg = new QWidget;
    ui_prefs_base.setupUi(generalSettingsDlg);
    dialog->addPage(generalSettingsDlg, i18n("General"), "configure");
    //Database
    QWidget *dbSettingsDlg = new QWidget;
    ui_prefs_db.setupUi(dbSettingsDlg);
    dialog->addPage(dbSettingsDlg, i18n("Database"), "kexi");
    //Printers
    QWidget *printerSettingsDlg = new QWidget;
    ui_pref_printers.setupUi(printerSettingsDlg);
    dialog->addPage(printerSettingsDlg, i18n("Printers"), "lemon-printer");
    

    connect(dialog, SIGNAL(settingsChanged(QString)), m_view, SLOT(settingsChanged()));
    //free mem by deleting the dialog on close without waiting for deletingit when the application quits
    dialog->setAttribute( Qt::WA_DeleteOnClose );

    dialog->show();
}


void squeeze::changeStatusbar(const QString& text)
{
    // display the text on the statusbar
    statusBar()->showMessage(text);
}

void squeeze::changeCaption(const QString& text)
{
    // display the text on the caption
    setCaption(text);
}

bool squeeze::queryClose()
{
  m_view->closeDB();
  return true;
}

void squeeze::salir()
{
  qApp->quit();
}

#include "squeeze.moc"
