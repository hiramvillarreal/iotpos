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

#include "lemon.h"
#include "lemonview.h"
#include "settings.h"
#include "enums.h"

#include <kapplication.h> 
// #include <qpainter.h>

#include <kdeversion.h>
#include <kglobal.h>
#include <kiconloader.h>
#include <kmenubar.h>
#include <kstatusbar.h>
#include <kconfigdialog.h>
#include <kfiledialog.h>
#include <kactioncollection.h>
#include <kaction.h>
#include <kstandardaction.h>
#include <KLocale>
#include <kstandarddirs.h>
#include <KNotification>

#include <ktoolbar.h>


#include <QListWidgetItem>
#include <QPushButton>
#include <QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <QTimer>
#include <QIcon>
#include <QDateTime>
#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>


//For a frameless window: KMainWindow(0, Qt::FramelessWindowHint)
lemon::lemon()
  : KXmlGuiWindow(0,Qt::FramelessWindowHint),
      m_view(new lemonView())
{
    setObjectName(QLatin1String("lemon"));
    setAcceptDrops(false);
    // tell the KMainWindow that this is indeed the main widget
    setCentralWidget(m_view);
    // then, setup our actions
    setupActions();
    // Add typical actions and save size/toolbars/statusbar
    statusBar()->show();
    //add some info labels to status bar
    labelUserInfo = new QLabel("::user::");
    labelDate = new QLabel(" ::Date:: ");
    labelTime = new QLabel(" ::Time:: ");
    labelTransaction = new QLabel("");
    QLabel *imageUser = new QLabel("user");
    QLabel *imageDate = new QLabel("date");
    QLabel *imageTime = new QLabel("time");
    QLabel *imageTransaction = new QLabel("trans");
    imageUser->setPixmap(DesktopIcon("user-identity", 16));
    imageDate->setPixmap(DesktopIcon("view-pim-calendar", 16));
    imageTime->setPixmap(DesktopIcon("chronometer", 16));
    imageTransaction->setPixmap(DesktopIcon("wallet-open", 16));
    updateDate();
    statusBar()->addWidget(imageUser);
    statusBar()->addWidget(labelUserInfo);
    statusBar()->addWidget(imageDate);
    statusBar()->addWidget(labelDate);
    statusBar()->addWidget(imageTime);
    statusBar()->addWidget(labelTime);
    statusBar()->addWidget(imageTransaction);
    statusBar()->addWidget(labelTransaction);
    connect(m_view, SIGNAL(signalLoggedUser()), SLOT(updateUserName()) );
    connect(m_view, SIGNAL(signalNoLoggedUser()), SLOT(updateUserName())  );
    connect(m_view, SIGNAL(signalUpdateClock() ), SLOT(updateClock()) );
    QTimer::singleShot(500, this,  SLOT(hideMenuBar()));

    // apply the saved mainwindow settings, if any, and ask the mainwindow
    // to automatically save settings if changed: window size, toolbar
    // position, icon size, etc.
    setAutoSaveSettings();

    connect(m_view,SIGNAL(signalChangeStatusbar(const QString&)),this,SLOT(changeStatusbar(const QString&)));
    connect(m_view,SIGNAL(signalChangeCaption(const QString&)),this, SLOT(changeCaption(const QString&)));
    connect(m_view, SIGNAL(signalAdminLoggedOn()), this, SLOT(enableConfig()));
    connect(m_view, SIGNAL(signalAdminLoggedOff()), this, SLOT(disableConfig()));
    connect(m_view, SIGNAL(signalSupervisorLoggedOn()), this, SLOT(enableConfig())); //new
    connect(m_view, SIGNAL(signalSupervisorLoggedOff()), this, SLOT(disableConfig())); //new
    connect(m_view, SIGNAL(signalNoLoggedUser()), this, SLOT(disableUi()));
    connect(m_view, SIGNAL(signalLoggedUser()), this, SLOT(reactOnLogOn()));
    connect(m_view, SIGNAL(signalStartedOperation()), this, SLOT(reactOnStartedOp()) );
    connect(m_view, SIGNAL(signalUpdateTransactionInfo()), this, SLOT(updateTransaction()));
    connect(m_view, SIGNAL(signalShowProdGrid()), this, SLOT(triggerGridAction()));
    connect(m_view, SIGNAL(signalShowDbConfig()), this, SLOT(showDBConfigDialog()));

    connect(m_view, SIGNAL(signalEnableUI()), this, SLOT(enableUi()) );
    connect(m_view, SIGNAL(signalDisableUI()), this, SLOT(disableUi()) );

    connect(m_view, SIGNAL(signalDisableLogin()), this, SLOT(disableLogin()) );
    connect(m_view, SIGNAL(signalEnableLogin()), this, SLOT(enableLogin()) );
    

    connect(m_view, SIGNAL(signalEnableStartOperationAction()), this, SLOT(enableStartOp()) );
    connect(m_view, SIGNAL(signalDisableStartOperationAction()), this, SLOT(disableStartOp()) );

    loadStyle();
    disableConfig();
    disableUi();

}

void lemon::triggerGridAction()
{
  QAction *accion = actionCollection()->action("showProductsGrid");
  accion->trigger();
  qDebug()<<"trigger grid action done...";
}

lemon::~lemon()
{
//     delete m_printer;
}


void lemon::setupActions()
{
  KStandardAction::quit(this, SLOT(salir()), actionCollection());
  //KStandardAction::quit(qApp, SLOT(quit()), actionCollection());

  KStandardAction::preferences(this, SLOT(optionsPreferences()), actionCollection());

    //Our actions
  QAction* loginAction =  actionCollection()->addAction( "login" );
  loginAction->setText(i18n("Login"));
  loginAction->setIcon(KIcon("office-address-book")); //identity
  loginAction->setShortcut(Qt::CTRL+Qt::Key_L);
  connect(loginAction, SIGNAL(triggered(bool)),m_view, SLOT(login()));

  QAction *corteCajaAction = actionCollection()->addAction("balance");
  corteCajaAction->setText(i18nc("Account balance", "Balance"));
  corteCajaAction->setIcon(KIcon("lemon-balance"));
  corteCajaAction->setShortcut(Qt::CTRL+Qt::Key_B);
  connect(corteCajaAction, SIGNAL(triggered(bool)), m_view, SLOT(doCorteDeCaja()));

  QAction* enterCodeAction = actionCollection()->addAction( "enterCode" );
  enterCodeAction->setText(i18n("Enter Code"));
  enterCodeAction->setIcon(KIcon("lemon-tag"));
  enterCodeAction->setShortcut(Qt::Key_F2);
  connect(enterCodeAction, SIGNAL(triggered(bool)),m_view, SLOT(showEnterCodeWidget()));

  QAction* searchItemAction = actionCollection()->addAction( "searchItem" );
  searchItemAction->setText(i18n("Search Item"));
  searchItemAction->setIcon(KIcon("edit-find"));
  searchItemAction->setShortcut(Qt::Key_F3);
  connect(searchItemAction, SIGNAL(triggered(bool)),m_view, SLOT(showSearchItemWidget()));

  QAction* delSelectedItemAction = actionCollection()->addAction( "deleteSelectedItem" );
  delSelectedItemAction->setText(i18n("Delete Selected Item"));
  delSelectedItemAction->setIcon(KIcon("lemon-boxcancel"));
  delSelectedItemAction->setShortcut(QKeySequence::ZoomOut); //Qt::Key_Delete  Qt::Key_Control+Qt::Key_Delete  QKeySequence::Cut QKeySequence::ZoomOut
  connect(delSelectedItemAction, SIGNAL(triggered(bool)),m_view, SLOT(deleteSelectedItem()));
  // ERROR: I dont know why, in my computer, instead of CTRL-Delete, the key assigned is Shift-(
  // The same for other non-working shortcuts.
  // Some problem related to different keyboard layout :
  qDebug()<<"shortcut:"<<delSelectedItemAction->shortcuts();

  QAction* finishTransactionAction = actionCollection()->addAction( "finishTransaction" );
  finishTransactionAction->setText(i18n("Finish transaction"));
  finishTransactionAction->setIcon(KIcon("lemon-transaction-accept"));
  finishTransactionAction->setShortcut(Qt::Key_F12);
  connect(finishTransactionAction, SIGNAL(triggered(bool)),m_view, SLOT(finishCurrentTransaction()));

  QAction* cancelTransactionAction = actionCollection()->addAction( "cancelTransaction" );
  cancelTransactionAction->setText(i18n("Cancel transaction"));
  cancelTransactionAction->setIcon(KIcon("lemon-transaction-cancel"));
  cancelTransactionAction->setShortcut(Qt::Key_F10);
  connect(cancelTransactionAction, SIGNAL(triggered(bool)),m_view, SLOT(preCancelCurrentTransaction()));

  QAction* cancelSellAction = actionCollection()->addAction("cancelTicket");
  cancelSellAction->setText(i18n("Cancel a ticket"));
  cancelSellAction->setIcon(KIcon("lemon-ticket-cancel") );
  cancelSellAction->setShortcut(Qt::Key_F11);
  connect(cancelSellAction, SIGNAL(triggered(bool)),m_view, SLOT(askForIdToCancel()));

      //NOTE: This action is for setting how much money is on the drawer...
  QAction* startOperationAction = actionCollection()->addAction( "startOperation" );
  startOperationAction->setText(i18n("Start Operation"));
  startOperationAction->setIcon(KIcon("window-new"));
  startOperationAction->setShortcut(QKeySequence::New); // New Qt::Key_Control+Qt::Key_N
  connect(startOperationAction, SIGNAL(triggered(bool)),m_view, SLOT(_slotDoStartOperation()));

  QAction *payFocusAction = actionCollection()->addAction("payFocus");
  payFocusAction->setText(i18n("Pay focus"));
  payFocusAction->setIcon(KIcon("lemon-payfocus"));
  payFocusAction->setShortcut(Qt::Key_F4); //Qt::Key_Alt + Qt::Key_End
  connect(payFocusAction, SIGNAL(triggered(bool)),m_view, SLOT(focusPayInput()));

  QAction *showProdGridAction = actionCollection()->addAction("showProductsGrid");
  showProdGridAction->setCheckable(true);
  showProdGridAction->setText(i18n("Show/Hide Products Grid"));
  showProdGridAction->setIcon(KIcon("view-split-top-bottom"));
  showProdGridAction->setShortcut(QKeySequence::Print);
  connect(showProdGridAction, SIGNAL(toggled(bool)), m_view, SLOT(showProductsGrid(bool)));
  qDebug()<<"Show Grid shortcut:"<<showProdGridAction->shortcuts();

  QAction *showPriceCheckerAction = actionCollection()->addAction("showPriceChecker");
  showPriceCheckerAction->setText(i18n("Show Price Checker"));
  showPriceCheckerAction->setIcon(KIcon("lemon-price-checker"));
  showPriceCheckerAction->setShortcut(Qt::Key_F9);
  connect(showPriceCheckerAction, SIGNAL(triggered(bool)), m_view, SLOT(showPriceChecker()));

  QAction *reprintTicketAction = actionCollection()->addAction("reprintTicket");
  reprintTicketAction->setText(i18n("Reprint ticket"));
  reprintTicketAction->setIcon(KIcon("lemon-print-ticket"));
  reprintTicketAction->setShortcut(Qt::Key_F5);
  connect(reprintTicketAction, SIGNAL(triggered(bool)), m_view, SLOT(showReprintTicket()));

  QAction *cashOutAction = actionCollection()->addAction("cashOut");
  cashOutAction->setText(i18n("Cash Out"));
  cashOutAction->setIcon(KIcon("lemon-cashout"));
  cashOutAction->setShortcut(Qt::Key_F7); //F7
  connect(cashOutAction, SIGNAL(triggered(bool)), m_view, SLOT(cashOut()));

  QAction *cashAvailableAction = actionCollection()->addAction("cashAvailable");
  cashAvailableAction->setText(i18n("Cash in drawer"));
  cashAvailableAction->setIcon(KIcon("lemon-money"));
  cashAvailableAction->setShortcut(Qt::Key_F6);
  connect(cashAvailableAction, SIGNAL(triggered(bool)), m_view, SLOT(cashAvailable()));

  QAction *cashInAction = actionCollection()->addAction("cashIn");
  cashInAction->setText(i18n("Cash In"));
  cashInAction->setIcon(KIcon("lemon-cashin"));
  cashInAction->setShortcut(Qt::Key_F8); //F8
  connect(cashInAction, SIGNAL(triggered(bool)), m_view, SLOT(cashIn()));

  QAction *endOfDayAction = actionCollection()->addAction("endOfDay");
  endOfDayAction->setText(i18n("End of day report"));
  endOfDayAction->setIcon(KIcon("go-jump-today"));
  endOfDayAction->setShortcut(QKeySequence::Close);
  connect(endOfDayAction, SIGNAL(triggered(bool)), m_view, SLOT(endOfDay()));
  qDebug()<<"End of day shortcut:"<<endOfDayAction->shortcuts();

  QAction *soAction = actionCollection()->addAction("specialOrder");
  soAction->setText(i18n("Add Special Order"));
  soAction->setIcon(KIcon("lemon-box"));
  soAction->setShortcut(Qt::Key_PageUp);
  connect(soAction, SIGNAL(triggered(bool)), m_view, SLOT(addSpecialOrder()));
  qDebug()<<"SpecialOrder shortcut:"<<soAction->shortcuts();


  QAction *socAction = actionCollection()->addAction("specialOrderComplete");
  socAction->setText(i18n("Complete Special Order"));
  socAction->setIcon(KIcon("lemon-box"));
  socAction->setShortcut(Qt::Key_PageDown);
  connect(socAction, SIGNAL(triggered(bool)), m_view, SLOT(specialOrderComplete()));
  qDebug()<<"SpecialOrder Complete shortcut:"<<socAction->shortcuts();

  QAction *lockAction = actionCollection()->addAction("lockScreen");
  lockAction->setText(i18n("Lock Screen"));
  lockAction->setIcon(KIcon("lemon-box")); //TODO:CREATE ICON!
  lockAction->setShortcut(Qt::CTRL+Qt::Key_Space);
  connect(lockAction, SIGNAL(triggered(bool)), m_view, SLOT(lockScreen()));
  qDebug()<<"LockScreen shortcut:"<<lockAction->shortcuts();

  QAction *suspendSaleAction = actionCollection()->addAction("suspendSale");
  suspendSaleAction->setText(i18n("Suspend Sale"));
  suspendSaleAction->setIcon(KIcon("lemon-suspend"));
  suspendSaleAction->setShortcut(Qt::CTRL+Qt::Key_Backspace);
  connect(suspendSaleAction, SIGNAL(triggered(bool)), m_view, SLOT( suspendSale() ));
  qDebug()<<"Suspend Sale shortcut:"<<suspendSaleAction->shortcuts();

  QAction *soStatusAction = actionCollection()->addAction("soStatus");
  soStatusAction->setText(i18n("Change Special Order Status"));
  soStatusAction->setIcon(KIcon("lemon-box")); //TODO:CREATE ICON!
  soStatusAction->setShortcut(Qt::CTRL+Qt::Key_PageUp);
  connect(soStatusAction, SIGNAL(triggered(bool)), m_view, SLOT( changeSOStatus() ));
  qDebug()<<"soStatus shortcut:"<<soStatusAction->shortcuts();

  QAction *oDiscAction = actionCollection()->addAction("occasionalDiscount");
  oDiscAction->setText(i18n("Change Special Order Status"));
  oDiscAction->setIcon(KIcon("lemon-money")); //TODO:CREATE ICON!
  oDiscAction->setShortcut(Qt::CTRL+Qt::Key_D);
  connect(oDiscAction, SIGNAL(triggered(bool)), m_view, SLOT( occasionalDiscount() ));
  qDebug()<<"occasionalDiscount shortcut:"<<oDiscAction->shortcuts();

  QAction *resumeAction = actionCollection()->addAction("resumeSale");
  resumeAction->setText(i18n("Resume Sale"));
  resumeAction->setIcon(KIcon("lemon-resume"));
  resumeAction->setShortcut(Qt::CTRL+Qt::Key_R);
  connect(resumeAction, SIGNAL(triggered(bool)), m_view, SLOT( resumeSale() ));
  qDebug()<<"resumeSale shortcut:"<<resumeAction->shortcuts();

  QAction *makeReservationA = actionCollection()->addAction("makeReservation");
  makeReservationA->setText(i18n("Reserve Items"));
  makeReservationA->setIcon(KIcon("lemon-reservation"));
  makeReservationA->setShortcut(Qt::ALT + Qt::Key_R); // Qt::ALT is the left ALT key ( not the Alt Gr )
  connect(makeReservationA, SIGNAL(triggered(bool)), m_view, SLOT( reserveItems() ));
  qDebug()<<"makeReservation shortcut:"<<makeReservationA->shortcuts();

  QAction *resumeRAction = actionCollection()->addAction("resumeReservation");
  resumeRAction->setText(i18n("Reservations"));
  resumeRAction->setIcon(KIcon("lemon-reservation-view"));
  resumeRAction->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_R);
  connect(resumeRAction, SIGNAL(triggered(bool)), m_view, SLOT( resumeReservation() ));
  qDebug()<<"Reservations shortcut:"<<resumeRAction->shortcuts();

  QAction *showCreditsAction = actionCollection()->addAction("showCredits");
  showCreditsAction->setText(i18n("Show Credits"));
  showCreditsAction->setIcon(KIcon("lemon-credits"));
  showCreditsAction->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_C);
  connect(showCreditsAction, SIGNAL(triggered(bool)), m_view, SLOT( showCredits() ));
  qDebug()<<"ShowCredits shortcut:"<<showCreditsAction->shortcuts();

  QAction *addResPaymentAction = actionCollection()->addAction("addReservationPayment");
  addResPaymentAction->setText(i18n("Add Reservation Payment"));
  addResPaymentAction->setIcon(KIcon("lemon-reservation-payment"));
  addResPaymentAction->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_P);
  connect(addResPaymentAction, SIGNAL(triggered(bool)), m_view, SLOT( addReservationPayment() ));
  qDebug()<<"ReservationPayment shortcut:"<<addResPaymentAction->shortcuts();

  QAction *action = actionCollection()->addAction( "emitirFactura" );
  action->setText(i18n("Emitir una factura"));
  action->setIcon(KIcon("lemon-ticket"));
  action->setShortcut(Qt::CTRL+Qt::Key_F);
  connect(action, SIGNAL(triggered(bool)),m_view, SLOT(emitirFactura()));
  
  action = actionCollection()->addAction( "cancelarFactura" );
  action->setText(i18n("Cancelar una factura"));
  action->setIcon(KIcon("lemon-ticket-cancel"));
  action->setShortcut(Qt::CTRL+Qt::ALT+Qt::Key_F);
  connect(action, SIGNAL(triggered(bool)),m_view, SLOT(cancelarFactura()));

  action = actionCollection()->addAction( "reprintFactura" );
  action->setText(i18n("Reimprimir una factura"));
  action->setIcon(KIcon("lemon-ticket-cancel"));
  action->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_F);
  connect(action, SIGNAL(triggered(bool)),m_view, SLOT(reprintFactura()));
  
  action = actionCollection()->addAction( "freeFacturas" );
  action->setText(i18n("Número de facturas disponibles"));
  action->setIcon(KIcon("lemon-ticket-cancel"));
  action->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_L);
  connect(action, SIGNAL(triggered(bool)),m_view, SLOT(facturasLibres()));

  //NOTE: There is a weird bug: When the lemon-reservation-* icon is used at 22x22 pixels (default/medium size) it is not found, instead used lemon app icon.
  
  setupGUI();

  //FIXME: SCREEN SIZE
  setWindowState( windowState() | Qt::WindowFullScreen ); // set
  //setGeometry(QApplication::desktop()->screenGeometry(this));
  if (!Settings::splitterSizes().isEmpty()) m_view->setTheSplitterSizes(Settings::splitterSizes());
  if (!Settings::gridSplitterSizes().isEmpty()) m_view->setTheGridSplitterSizes(Settings::gridSplitterSizes());
}

void lemon::loadStyle()
{
//   QString defaultStyle = QApplication::style()->metaObject()->className();
//   qDebug()<<"Default Style:"<<defaultStyle;
//   qDebug()<<"QStyles Available:"<<QStyleFactory::keys();
//     //qApp->setStyle("Plastik");
//   defaultStyle = QApplication::style()->metaObject()->className();
//   qDebug()<<"Style used:"<<defaultStyle;

  qDebug()<<"Loading Stylesheet...";
  if (Settings::useStyle()) {
    QString fileName; QString path;
    path = KStandardDirs::locate("appdata", "styles/");
    fileName = path + Settings::styleName() + "/" + Settings::styleName() + ".qss";
    QFile file(fileName);
    bool op = file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    //replace fakepath to the real path..
    QString finalStyle = styleSheet.replace("[STYLE_PATH]", path + Settings::styleName() + "/");
    qApp->setStyleSheet(finalStyle);
    if (op) file.close();
  }
  else {
    //Load a simple style...
    QString fileName; QString path;
    path = KStandardDirs::locate("appdata", "styles/");
    fileName = path + Settings::styleName() + "/simple.qss";
    QFile file(fileName);
    bool op = file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    //replace fakepath to the real path..
    QString finalStyle = styleSheet.replace("[STYLE_PATH]", path + Settings::styleName() + "/");
    qApp->setStyleSheet(finalStyle);
    if (op) file.close();
  }
  showToolBars();
}


/**This is used to get Database user,password,server to set initial config, in case the db server is remote.
   So we show the config dialog, and when saved login again. It is called from main_view.login()
**/
void lemon::showDBConfigDialog()
{
  //avoid to have 2 dialogs shown
  if ( KConfigDialog::showDialog( "settings" ) )  {
    return;
  }
  KConfigDialog *dialog = new KConfigDialog(this, "settings", Settings::self());

  QWidget *dbSettingsDlg = new QWidget;
  ui_prefs_db.setupUi(dbSettingsDlg);
  dialog->addPage(dbSettingsDlg, i18n("Database"), "kexi"); // book
  connect(dialog, SIGNAL(settingsChanged(QString)), m_view, SLOT(settingsChangedOnInitConfig()));
  dialog->setAttribute( Qt::WA_DeleteOnClose );
  dialog->show();

  qDebug()<<"CONFIG DIALOG SHOWN... - showDBConfigDialog()";
}

void lemon::optionsPreferences()
{
    //avoid to have 2 dialogs shown
    if ( KConfigDialog::showDialog( "settings" ) )  {
        return;
    }
    KConfigDialog *dialog = new KConfigDialog(this, "settings", Settings::self());

    QWidget *generalSettingsDlg = new QWidget;
    ui_prefs_base.setupUi(generalSettingsDlg);
    dialog->addPage(generalSettingsDlg, i18n("General"), "configure");

    QWidget *storeDataSettingsDlg = new QWidget;
    ui_store_data.setupUi(storeDataSettingsDlg);
   //NOTE: What icon to use for this??
    dialog->addPage(storeDataSettingsDlg, i18n("Store"), "go-home");
    
    QWidget *facturasSettingsDlg = new QWidget;
    ui_facturas_data.setupUi(facturasSettingsDlg);
    //NOTE: What icon to use for this??
    dialog->addPage(facturasSettingsDlg, i18n("Facturas"), "go-home");

    QWidget *dbSettingsDlg = new QWidget;
    ui_prefs_db.setupUi(dbSettingsDlg);
    dialog->addPage(dbSettingsDlg, i18n("Database"), "kexi"); // book

    QWidget *styleSettingsDlg = new QWidget;
    ui_pref_style.setupUi(styleSettingsDlg);
    dialog->addPage(styleSettingsDlg, i18n("Appearence"), "draw-brush");
    lemon::populateStyleList();
    connect(ui_pref_style.styleList, SIGNAL(itemClicked(QListWidgetItem *)), SLOT(sLitemActivated(QListWidgetItem *)) );
    connect(ui_pref_style.styleList, SIGNAL(itemActivated(QListWidgetItem *)), SLOT(sLitemActivated(QListWidgetItem *)) );

    QWidget *securitySettingsDlg = new QWidget;
    ui_pref_security.setupUi(securitySettingsDlg);
    dialog->addPage(securitySettingsDlg, i18n("Security"), "dialog-password");

    QWidget *printersSettingDlg = new QWidget;
    ui_pref_printers.setupUi(printersSettingDlg);
    dialog->addPage(printersSettingDlg, i18n("Printer"), "lemon-printer");

    connect(dialog, SIGNAL(settingsChanged(QString)), m_view, SLOT(settingsChanged()));
    connect(dialog, SIGNAL(settingsChanged(const QString &)), this, SLOT(loadStyle()));
    //free mem by deleting the dialog on close without waiting for deletingit when the application quits
    dialog->setAttribute( Qt::WA_DeleteOnClose );
    dialog->show();
}


void lemon::hideToolBars()
{
  QList<KToolBar*> tb  = toolBars();
  for (int i=0; i < tb.count(); i++)
    tb.at(i)->hide();
}

void lemon::showToolBars()
{
  QList<KToolBar*> tb  = toolBars();
  for (int i=0; i < tb.count(); i++)
    tb.at(i)->show();
}

void lemon::hideMenuBar()
{
  if (!menuBar()->isHidden()) {
    menuBar()->hide();
  }
}

void lemon::reactOnStartedOp()
{
  if (m_view->canStartSelling()) {
    enableUi();
    //disableStartOp();
  }
  else {
    disableUi();
    //enableStartOp();
  }
}

void lemon::enableStartOp()
{
  qDebug()<<"enabling start op action, logged user:"<<m_view->getLoggedUser();
  if (!m_view->canStartSelling() && !m_view->getLoggedUser().isEmpty()) {
    QAction *action = actionCollection()->action("startOperation");
    action->setEnabled(true);
  }
}

void lemon::disableStartOp()
{
  qDebug()<<"disabling start op action, logged user:"<<m_view->getLoggedUser();
  QAction *action = actionCollection()->action("startOperation");
  action->setDisabled(true);
}

void lemon::reactOnLogOn()
{
  if (m_view->canStartSelling())
    enableUi();
  else {
    disableUi();
    QString msg = i18n("Administrator or Supervisor needs to start operation before you can start selling...");
    //Show a dialog saying that operations need to be started by admin ???
    if (m_view->getLoggedUserRole() == roleBasic ) {
      KNotification *notify = new KNotification("information", this);
      notify->setText(msg);
      QPixmap pixmap = DesktopIcon("dialog-information",48);
      notify->setPixmap(pixmap);
      notify->sendEvent();
    }
  }
}

void lemon::disableUi()
{
  m_view->frame->setDisabled(true);
  m_view->frameLeft->setDisabled(true);
  QAction *action = actionCollection()->action("enterCode");
  action->setDisabled(true);
  if (m_view->canStartSelling()) {
    action = actionCollection()->action("startOperation");
    action->setDisabled(true);
  }
  action = actionCollection()->action("searchItem");
  action->setDisabled(true);
  action = actionCollection()->action("deleteSelectedItem");
  action->setDisabled(true);
  action = actionCollection()->action("finishTransaction");
  action->setDisabled(true);
  action = actionCollection()->action("cancelTransaction");
  action->setDisabled(true);
  action = actionCollection()->action("balance");
  action->setDisabled(true);
  action = actionCollection()->action("payFocus");
  action->setDisabled(true);
  action = actionCollection()->action("cancelTicket");
  action->setDisabled(true);
  action = actionCollection()->action("showProductsGrid");
  action->setDisabled(true);
  action = actionCollection()->action("cashIn");
  action->setDisabled(true);
  action = actionCollection()->action("cashOut");
  action->setDisabled(true);
  action = actionCollection()->action("cashAvailable");
  action->setDisabled(true);
  action = actionCollection()->action("reprintTicket");
  action->setDisabled(true);
  action = actionCollection()->action("showPriceChecker");
  action->setDisabled(true);
  action = actionCollection()->action("endOfDay");
  action->setDisabled(true);
  action = actionCollection()->action("specialOrder");
  action->setDisabled(true);
  action = actionCollection()->action("specialOrderComplete");
  action->setDisabled(true);
  action = actionCollection()->action("occasionalDiscount");
  action->setDisabled(true);
  
  action = actionCollection()->action("suspendSale");
  action->setDisabled(true);
  action = actionCollection()->action("resumeSale");
  action->setDisabled(true);

  action = actionCollection()->action("makeReservation");
  action->setDisabled(true);

  action = actionCollection()->action("resumeReservation");
  action->setDisabled(true);

  action = actionCollection()->action("showCredits");
  action->setDisabled(true);

  action = actionCollection()->action("addReservationPayment");
  action->setDisabled(true);

  action = actionCollection()->action("login");
  action->setEnabled(true); //enable login!

  action = actionCollection()->action("emitirFactura");
  action->setDisabled(true);

  action = actionCollection()->action("cancelarFactura");
  action->setDisabled(true);

  action = actionCollection()->action("reprintFactura");
  action->setDisabled(true);
  
  disableConfig();
}

void lemon::disableLogin()
{
  QAction *action = actionCollection()->action("login");
  action->setDisabled(true);
}

void lemon::enableLogin()
{
  QAction *action = actionCollection()->action("login");
  action->setEnabled(true);
}

void lemon::enableUi()
{
  m_view->setEnabled(true);
  m_view->frame->setEnabled(true);
  m_view->frameLeft->setEnabled(true);
  QAction *action = actionCollection()->action("enterCode");
  action->setEnabled(true);
  action = actionCollection()->action("startOperation");
  action->setDisabled(true);
  action = actionCollection()->action("searchItem");
  action->setEnabled(true);
  action = actionCollection()->action("deleteSelectedItem");
  action->setEnabled(true);
  action = actionCollection()->action("finishTransaction");
  action->setEnabled(true);
  action = actionCollection()->action("cancelTransaction");
  action->setEnabled(true);
  action = actionCollection()->action("balance");
  action->setEnabled(true);
  action = actionCollection()->action("payFocus");
  action->setEnabled(true);
  action = actionCollection()->action("cancelTicket");
  action->setEnabled(true);
  action = actionCollection()->action("showProductsGrid");
  action->setEnabled(true);
  action = actionCollection()->action("cashIn");
  action->setEnabled(true);
  action = actionCollection()->action("cashOut");
  action->setEnabled(true);
  action = actionCollection()->action("cashAvailable");
  action->setEnabled(true);
  action = actionCollection()->action("reprintTicket");
  action->setEnabled(true);
  action = actionCollection()->action("showPriceChecker");
  action->setEnabled(true);
  action = actionCollection()->action("endOfDay");
  action->setEnabled(true);
  action = actionCollection()->action("specialOrder");
  action->setEnabled(true);
  action = actionCollection()->action("specialOrderComplete");
  action->setEnabled(true);
  action = actionCollection()->action("occasionalDiscount");
  action->setEnabled(true);

  action = actionCollection()->action("suspendSale");
  action->setEnabled(true);
  action = actionCollection()->action("resumeSale");
  action->setEnabled(true);

  action = actionCollection()->action("resumeReservation");
  action->setEnabled(true);

  action = actionCollection()->action("makeReservation");
  action->setEnabled(true);

  action = actionCollection()->action("addReservationPayment");
  action->setEnabled(true);

  action = actionCollection()->action("showCredits");
  action->setEnabled(true);

  action = actionCollection()->action("emitirFactura");
  action->setEnabled(true);
  
  action = actionCollection()->action("cancelarFactura");
  action->setEnabled(true);

  action = actionCollection()->action("reprintFactura");
  action->setEnabled(true);
  
  if (m_view->canStartSelling()) {
//     action = actionCollection()->action("suspendSale");
//     action->setEnabled(true);
  }
}

void lemon::disableConfig()
{
  QAction *actPref = actionCollection()->action(KStandardAction::stdName(KStandardAction::Preferences));
  actPref->setDisabled(true);
  QAction *actQuit = actionCollection()->action(KStandardAction::stdName(KStandardAction::Quit));
  //FIXME: esto no es muy bueno en produccion..
  if (!Settings::allowAnyUserToQuit()) actQuit->setDisabled(true);
}

void lemon::enableConfig()
{
  QAction *actPref = actionCollection()->action(KStandardAction::stdName(KStandardAction::Preferences));
  actPref->setEnabled(true);
  QAction *actQuit = actionCollection()->action(KStandardAction::stdName(KStandardAction::Quit));
  actQuit->setEnabled(true);

  QAction *actSop = actionCollection()->action("startOperation");
  actSop->setEnabled(true);
}


void lemon::populateStyleList()
{
  QString path = KStandardDirs::locate("appdata", "styles/");
  QDir dir(path);
  dir.setFilter(QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot);
  dir.setSorting(QDir::Name | QDir::LocaleAware);
  QFileInfoList list = dir.entryInfoList();
  for (int i = 0; i < list.size(); ++i) {
    QFileInfo fileInfo = list.at(i);
    ui_pref_style.styleList->addItem(fileInfo.fileName());
  }
  //Select the style used...
  QList<QListWidgetItem *> itemLfound = ui_pref_style.styleList->findItems(Settings::styleName(), Qt::MatchExactly);
  if (itemLfound.count() == 1) {
    QListWidgetItem *item = itemLfound.first();
    ui_pref_style.styleList->setCurrentItem(item);
  }
}

void lemon::sLitemActivated(QListWidgetItem * item)
{
  ui_pref_style.kcfg_styleName->setText(item->text());
}


void lemon::updateClock()
{
  QTime time = QTime::currentTime();
  QString text = time.toString("hh:mm");
  if ((time.second() % 2) == 0)
    text[2] = '.';
  labelTime->setText(text);
  if ((time.hour()==0) && (time.minute()==0) && (time.second()==0) ) updateDate();

  ///On kde 4.3 some bug resizes the window and the taskbar over mainview. I dont want taskbar, it means full screen is deactivated. How can we set fullScreen MODE?
  if (geometry() != QApplication::desktop()->screenGeometry(this)) {
    //qDebug()<<"FIXING WINDOW SIZE from:"<<geometry();
    //setGeometry(QApplication::desktop()->screenGeometry(this));
    //Doing this the size is fixed but the taskbar is show over mainview
  }
}

void lemon::updateDate()
{
  QDate dt = QDate::currentDate();
  labelDate->setText(KGlobal::locale()->formatDate(dt));
}

void lemon::updateUserName()
{
  if (m_view->getLoggedUserRole() == roleBasic)
    labelUserInfo->setText(m_view->getLoggedUser());
  else if (m_view->getLoggedUserRole() == roleSupervisor)
    labelUserInfo->setText(QString("<html><font color=orange><b>%1</font></b>").arg(m_view->getLoggedUser()));
  else
    labelUserInfo->setText(QString("<html><font color=red><b>%1</font></b>").arg(m_view->getLoggedUser()));
}

void lemon::updateTransaction()
{
  QString tn = m_view->getCurrentTransactionString();
  labelTransaction->setText(i18n("Transaction #%1", tn));
}



void lemon::changeStatusbar(const QString& text)
{
    // display the text on the statusbar
  statusBar()->showMessage(text, 1500);
}

void lemon::changeCaption(const QString& text)
{
    // display the text on the caption
  setCaption(text);
}

bool lemon::queryClose()
{
  int ss1 = m_view->getTheSplitterSizes().at(0); //The main splitter height
  int ss2 = m_view->getTheGridSplitterSizes().at(0); //The gridView spliiter height
  qDebug()<<" LeftPanel splitter size:"<<ss1;
  qDebug()<<" GridView  splitter size:"<<ss2;
  //Check if the gridview is hidden, to do not save its 0 size values.
  if ( ss1 >= 50) Settings::setSplitterSizes(m_view->getTheSplitterSizes());
  if ( ss2 >= 50) Settings::setGridSplitterSizes(m_view->getTheGridSplitterSizes());
  //FIXED Settings::writeConfig();
  Settings::self()->writeConfig();
  //Close only by admin user. or ask for password??
  if (Settings::allowAnyUserToQuit())
  {
    bool reallyQuit=false;
    if (m_view->getLoggedUser() == "admin") reallyQuit=true;  else reallyQuit = m_view->validAdminUser();
    //cancel current transaction
    if (m_view->isTransactionInProgress()){  m_view->cancelByExit(); }
    //save balance
    //m_view->saveBalance();
    //When saving balance on quit, do we need to print the balance???
    m_view->corteDeCaja();
    return reallyQuit;
  }
  else if ( m_view->getLoggedUser() == "admin" ) {
    //cancel current transaction
    if (m_view->isTransactionInProgress()){  m_view->cancelByExit(); }
    //save balance
    //m_view->saveBalance();
    //When saving balance on quit, do we need to print the balance???
    m_view->corteDeCaja();
    return true;
  } else return false;
}

void lemon::salir()
{
  if (queryClose()) {
    qDebug()<<"===EXIT LEMON AT "<<QDateTime::currentDateTime().toString();
    kapp->quit();
  }
}

#include "lemon.moc"
