/***************************************************************************
 *   Copyright (C) 2010 by Miguel Chavez Gamboa                            *
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
#include <KLocale>
#include <KMessageBox>
#include <KStandardDirs>
#include <KNotification>

#include <QByteArray>
#include <QRegExpValidator>
#include <QRegExp>
#include <QtSql>
#include <QDate>
#include <QTime>
#include <QTimer>


#include "settings.h"
#include "reservations.h"
#include "../../dataAccess/azahar.h"
#include "../../mibitWidgets/mibitfloatpanel.h"

ReservationsDialogUI::ReservationsDialogUI( QWidget *parent )
: QFrame( parent )
{
    setupUi( this );
}

ReservationsDialog::ReservationsDialog( QWidget *parent, Gaveta *theDrawer, int userid )
: KDialog( parent )
{
    drawer = theDrawer;
    userId = userid;
    m_modelAssigned = false;
    trNumber = 0;
    rNumber = 0;
    rPayment = 0;
    rProfit = 0;
    item_discounts = "";

    ui = new ReservationsDialogUI( this );
    setMainWidget( ui );
    setCaption( i18n("Reservations") );
    setButtons( KDialog::Ok|KDialog::Cancel );
    enableButtonOk(false);

    QString path = KStandardDirs::locate("appdata", "styles/");
    path = path+"floating_bottom.svg";
    panel = new MibitFloatPanel(this, path, Top);
    panel->setSize(250,150);
    panel->addWidget(ui->confirmFrame);
    panel->setMode(pmManual);
    panel->setHiddenTotally(true);
    panel->hide();
    connect(ui->btnYes, SIGNAL(clicked()), SLOT(cancelReservation() ));
    connect(ui->btnNo, SIGNAL(clicked()), panel, SLOT(hidePanel() ));
    connect(ui->btnCancelReservation, SIGNAL(clicked()), panel, SLOT(showPanel() ));

    connect(ui->tableWidget, SIGNAL(clicked(const QModelIndex &)), SLOT(itemClicked(const QModelIndex &)));
    setDefaultButton(KDialog::Ok);

    //disable the cancel button
    ui->btnCancelReservation->setDisabled(true);
}


void ReservationsDialog::selectItem()
{
  enableButtonOk(false);
  QModelIndex index = ui->tableWidget->currentIndex();
  if (index == trModel->index(-1,-1) ) {
    if (trModel->rowCount() == 1) {
      ui->tableWidget->selectRow(0);
      index = ui->tableWidget->currentIndex();
      enableButtonOk(true);
      ui->btnCancelReservation->setEnabled(true);
    } else {
      enableButtonOk(false);
      ui->btnCancelReservation->setDisabled(true);
      //let the user select the appropiate.
    }
  }
  //trNumber = trModel->record(index.row()).value("id").toULongLong();
  rNumber = trModel->record(index.row()).value("id").toULongLong();

 qDebug()<<"Selected Reservation # "<<rNumber;
}

///TODO: Create a Reservation CANCEL action.

void ReservationsDialog::itemClicked(const QModelIndex &index)
{
  enableButtonOk(false);
  ui->contentTable->clearContents();
  ui->contentTable->setRowCount(0);
  pList.clear();

  rNumber       = trModel->record(index.row()).value("id").toULongLong();
  trNumber      = trModel->record(index.row()).value("transaction_id").toULongLong();
  rPayment      = trModel->record(index.row()).value("payment").toDouble();
  rProfit       = trModel->record(index.row()).value("profit").toDouble();
  item_discounts= trModel->record(index.row()).value("item_discounts").toString();
  qDebug()<<"==> Selected Reservation number:"<<rNumber<<" Transaction #"<< trNumber;
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  TransactionInfo tInfo = myDb->getTransactionInfo(trNumber);
  clientId = tInfo.clientid;
  trDate   = tInfo.date;
  QStringList _pList = tInfo.itemlist.split(",");
  int count = 0;
  //Iterate each product/group
  foreach(QString str, _pList) {
    qulonglong code = str.section('/',0,0).toULongLong();
    double     qty  = str.section('/',1,1).toDouble();
    if (code <= 0 ) break;
    count++;
    ProductInfo pInfo = myDb->getProductInfo(QString::number(code));
    pInfo.qtyOnList = qty;
    pList << pInfo;
    //insert to the cntent table
    int rowCount = ui->contentTable->rowCount();
    ui->contentTable->insertRow(rowCount);
    ui->contentTable->setItem(rowCount, 0, new QTableWidgetItem(QString::number(qty)));
    ui->contentTable->setItem(rowCount, 1, new QTableWidgetItem(pInfo.desc));
  }
  qDebug()<<"Clicked on tr# "<<trNumber<<" items count:"<<count;

  if ( trNumber > 0 && count > 0 ) {
     enableButtonOk(true);
     ui->btnCancelReservation->setEnabled(true);
  }
  delete myDb;
  ui->contentTable->resizeRowsToContents();
  ui->contentTable->resizeColumnsToContents();
}

void ReservationsDialog::item_Clicked(const QModelIndex &index, const QModelIndex &indexp)
{
    itemClicked(index);
}


void ReservationsDialog::setupModel()
{
  trModel = new QSqlRelationalTableModel();
  trModel->setTable("reservations");

  int trIdIndex = trModel->fieldIndex("id");
  int trDateIndex = trModel->fieldIndex("date");
  int trClientIndex= trModel->fieldIndex("client_id");
  int trTransIdIndex= trModel->fieldIndex("transaction_id");
  int trStatusIndex= trModel->fieldIndex("status");
  int trTotalIndex= trModel->fieldIndex("total");
  int trTaxesIndex= trModel->fieldIndex("totaltaxes");

  trModel->setHeaderData(trTransIdIndex, Qt::Horizontal, i18n("Tr. #"));
  trModel->setHeaderData(trDateIndex, Qt::Horizontal, i18n("Date") );
  trModel->setHeaderData(trClientIndex, Qt::Horizontal, i18n("Client"));

  trModel->setRelation(trClientIndex, QSqlRelation("clients", "id", "name"));

  ui->tableWidget->setModel(trModel);

  ui->tableWidget->setColumnHidden(trStatusIndex, true);
  ui->tableWidget->setColumnHidden(trIdIndex, true);
  ui->tableWidget->setColumnHidden(trTotalIndex, true);
  ui->tableWidget->setColumnHidden(trTaxesIndex, true);

  ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

  m_modelAssigned = true;

  trModel->setFilter(QString("status = %1").arg(rPending));
  trModel->setSort(0, Qt::DescendingOrder);
  trModel->select();

  ui->tableWidget->resizeRowsToContents();
  ui->tableWidget->resizeColumnsToContents();
  qDebug()<<"SetupModel done...";

  //connecting the signal for updating the transaction items.
  QItemSelectionModel *selModel = ui->tableWidget->selectionModel();
    connect(selModel,
            SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
            SLOT(item_Clicked(const QModelIndex &, const QModelIndex &)));

}

void ReservationsDialog::cancelReservation()
{
    bool closePanel = false;
    bool doIt = false;
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);

    //The reservation payment is reimbursed?
    //   1.- for client/store reasons  ---> this can be agreed, or store TERMS or CONDITIONS.
    //   2.- for client abandon.       ---> this must cause a no reimbursement.
    
    if (ui->chReimbursement->isChecked()) {
        //get reservation payment.
        double payment = myDb->getReservationPayment(rNumber);
        //is enough cash in drawer?
        double cashInDrawer = drawer->getAvailableInCash();
        if (cashInDrawer >= payment) {
            closePanel = true;
            drawer->substractCash(payment);
            //make a cashout
            CashFlowInfo info;
            info.amount = payment;
            info.reason = i18n("Reimbursement for CANCELLED Reservation #%1 [tr. %2]", rNumber, trNumber);
            info.date = QDate::currentDate();
            info.time = QTime::currentTime();
            info.terminalNum = Settings::editTerminalNumber();
            info.userid = userId;
            info.type   = ctCashOut; // NOTE: use ctCashOutReservations ???
            qulonglong cfId = myDb->insertCashFlow(info);
            drawer->insertCashflow(cfId);
            QString paymentStr = KGlobal::locale()->formatMoney(payment, QString(), 2);
            KNotification *notify = new KNotification("information", this);
            notify->setText(i18n("The reimbursement for the reservation is %1. Get it from the drawer.", paymentStr));
            QPixmap pixmap = DesktopIcon("dialog-information",32);
            notify->setPixmap(pixmap);
            notify->sendEvent();
            if (Settings::openDrawer() && Settings::smallTicketDotMatrix() && Settings::printTicket())
                drawer->open();
            doIt = true;
        } else {
            //NOT ENOUGH CASH!
            KNotification *notify = new KNotification("information", this);
            notify->setText(i18n("There is not enough cash available in the drawer."));
            QPixmap pixmap = DesktopIcon("dialog-information",32);
            notify->setPixmap(pixmap);
            notify->sendEvent();
            doIt = false;
        }
    } else {
        closePanel = true;
        doIt = true;
    }
    
    if (closePanel) panel->hidePanel();

    if (doIt) {
        myDb->setReservationStatus(rNumber,  rCancelled);
        myDb->setTransactionStatus(trNumber, tCancelled);
        QTimer::singleShot(500, this, SLOT(close()));
    }
    
    delete myDb;
}

void ReservationsDialog::setDb(QSqlDatabase database)
{
  db = database;
  if (!db.isOpen()) db.open();

  //wait and create model
  QTimer::singleShot(300, this, SLOT(setupModel()));
}

ReservationsDialog::~ReservationsDialog()
{
  delete ui;
}

void ReservationsDialog::slotButtonClicked(int button)
{
  if (button == KDialog::Ok) {
    QDialog::accept();
  }
  else QDialog::reject();
}

