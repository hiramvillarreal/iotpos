/***************************************************************************
 *   Copyright (C) 2007-2009 by Miguel Chavez Gamboa                       *
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

#include <QByteArray>
#include <QRegExpValidator>
#include <QRegExp>
#include <QtSql>

#include "resume.h"
#include "../../dataAccess/azahar.h"

ResumeDialogUI::ResumeDialogUI( QWidget *parent )
: QFrame( parent )
{
    setupUi( this );
}

ResumeDialog::ResumeDialog( QWidget *parent )
: KDialog( parent )
{
    m_modelAssigned = false;
    trNumber = 0;
    userId = 0;

    ui = new ResumeDialogUI( this );
    setMainWidget( ui );
    setCaption( i18n("Resume Sale") );
    setButtons( KDialog::Ok|KDialog::Cancel );
    enableButtonOk(false);

    connect(ui->tableWidget, SIGNAL(clicked(const QModelIndex &)), SLOT(itemClicked(const QModelIndex &)));
    connect( ui->editSearch, SIGNAL(returnPressed()), SLOT(filterClient()) );
    setDefaultButton(KDialog::Ok);
}


void ResumeDialog::selectItem()
{
  enableButtonOk(false);
  QModelIndex index = ui->tableWidget->currentIndex();
  if (index == trModel->index(-1,-1) ) {
    if (trModel->rowCount() == 1) {
      ui->tableWidget->selectRow(0);
      index = ui->tableWidget->currentIndex();
      enableButtonOk(true);
    } else {
      enableButtonOk(false);
      //let the user select the appropiate.
    }
  }
  trNumber = trModel->record(index.row()).value("id").toULongLong();

 qDebug()<<"Selected tr # "<<trNumber;
}

void ResumeDialog::itemClicked(const QModelIndex &index)
{
  enableButtonOk(false);
  ui->contentTable->clearContents();
  ui->contentTable->setRowCount(0);
  pList.clear();
  soList.clear();

  trNumber       = trModel->record(index.row()).value("id").toULongLong();
  qDebug()<<"==> selected ticket number:"<<trNumber;
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  TransactionInfo tInfo = myDb->getTransactionInfo(trNumber);
  clientId = tInfo.clientid;
  trDate   = tInfo.date;
  trTime   = tInfo.time;
  QStringList _pList = tInfo.itemlist.split(",");
  QStringList _soList= tInfo.specialOrders.split(",");
  int count = 0;
  //first iterate each product/group
  foreach(QString str, _pList) {
    qulonglong code = str.section('/',0,0).toULongLong();
    double     qty  = str.section('/',1,1).toDouble();
    if (code <= 0 ) break;
    count++;
    ProductInfo pInfo = myDb->getProductInfo(QString::number(code));
    pInfo.qtyOnList = qty;
    pList << pInfo;
    //NOTE:Check for product Availability ??
    //insert to the cntent table
    int rowCount = ui->contentTable->rowCount();
    ui->contentTable->insertRow(rowCount);
    ui->contentTable->setItem(rowCount, 0, new QTableWidgetItem(QString::number(qty)));
    ui->contentTable->setItem(rowCount, 1, new QTableWidgetItem(pInfo.desc));
  }
  //now iterate each special order
  foreach(QString str, _soList) {
    qulonglong code = str.section('/',0,0).toULongLong();
    double     qty  = str.section('/',1,1).toDouble();
    if (code <= 0 ) break;
    count++;
    SpecialOrderInfo soInfo = myDb->getSpecialOrderInfo(code);
    soList << soInfo;
    //NOTE:Check for product Availability ??
    //insert to the content table
    int rowCount = ui->contentTable->rowCount();
    ui->contentTable->insertRow(rowCount);
    ui->contentTable->setItem(rowCount, 0, new QTableWidgetItem(QString::number(qty)));
    ui->contentTable->setItem(rowCount, 1, new QTableWidgetItem(soInfo.name));
  }
  qDebug()<<"Clicked on tr# "<<trNumber<<" items count:"<<count;

  if ( trNumber > 0 && count > 0 ) enableButtonOk(true);
  delete myDb;
  ui->contentTable->resizeRowsToContents();
  ui->contentTable->resizeColumnsToContents();
}

void ResumeDialog::item_Clicked(const QModelIndex &index, const QModelIndex &indexp)
{
    itemClicked(index);
}


void ResumeDialog::setupModel()
{
  trModel = new QSqlRelationalTableModel();
  trModel->setTable("v_transS");

  int trIdIndex = trModel->fieldIndex("id");
  int trDateIndex = trModel->fieldIndex("date");
  int trTimeIndex= trModel->fieldIndex("time");
  int trStateIndex = trModel->fieldIndex("state");
  int trUserIndex= trModel->fieldIndex("userid");
  int trClientIndex= trModel->fieldIndex("clientid");
  int trItemsIndex = trModel->fieldIndex("itemslist");
  int trTerminalNumIndex= trModel->fieldIndex("terminalnum");
  int trItemCountIndex= trModel->fieldIndex("itemcount");

  trModel->setHeaderData(trIdIndex, Qt::Horizontal, i18n("Tr. #"));
  trModel->setHeaderData(trTimeIndex, Qt::Horizontal, i18n("Time"));
  trModel->setHeaderData(trDateIndex, Qt::Horizontal, i18n("Date") );
  trModel->setHeaderData(trTerminalNumIndex, Qt::Horizontal, i18n("Terminal"));
  trModel->setHeaderData(trClientIndex, Qt::Horizontal, i18n("Client"));

  trModel->setRelation(trClientIndex, QSqlRelation("clients", "id", "name"));

  ui->tableWidget->setModel(trModel);

  ui->tableWidget->setColumnHidden(trStateIndex, true);
  ui->tableWidget->setColumnHidden(trUserIndex, true);
  ui->tableWidget->setColumnHidden(trItemsIndex, true);
  ui->tableWidget->setColumnHidden(trItemCountIndex, true);

  ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

  m_modelAssigned = true;

  //NOTE: we need to know the userid before this method! So setUserId() method must be called before setDb()
  trModel->setFilter(QString("userid = %1").arg(userId));
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

void ResumeDialog::setDb(QSqlDatabase database)
{
  db = database;
  if (!db.isOpen()) db.open();

  //wait and create model
  QTimer::singleShot(300, this, SLOT(setupModel()));
}

ResumeDialog::~ResumeDialog()
{
  delete ui;
}

void ResumeDialog::slotButtonClicked(int button)
{
  if (button == KDialog::Ok) {
    QDialog::accept();
  }
  else QDialog::reject();
}


void ResumeDialog::filterClient()
{
    QString str = ui->editSearch->text();
    //analize string, if it is a number, then search by id, if alphanum then by name.
    if (str.isEmpty() || str == " "){ //clean filter
        trModel->setFilter("");
        trModel->setSort(0, Qt::DescendingOrder);
        trModel->select();
    } else {
        //search by client code (alphanum, 0000001 and not 1)
        //int trDateIndex = trModel->fieldIndex("date");
        trModel->setFilter(QString("code = '%1'").arg(str)); //userid = %1 .arg(userId)
        trModel->setSort(/*trDateIndex*/0, Qt::DescendingOrder); //it can be sorted only by one field.
        trModel->select();
        //clean edit after filtering? This can be faster to make search one after another if needed.
        ui->editSearch->clear();
    }
}
