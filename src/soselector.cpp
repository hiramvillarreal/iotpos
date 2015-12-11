/***************************************************************************
 *   Copyright (C) 2007-2009 by Miguel Chavez Gamboa                       *
 *   miguel.chavez.gamboa@gmail.com                                        *
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

#include "soselector.h"
#include "../../dataAccess/azahar.h"

SOSelectorUI::SOSelectorUI( QWidget *parent )
: QFrame( parent )
{
    setupUi( this );
}

SOSelector::SOSelector( QWidget *parent )
: KDialog( parent )
{
    m_modelAssigned = false;
    ticketNumber = 0;

    ui = new SOSelectorUI( this );
    setMainWidget( ui );
    setCaption( i18n("Special Orders") );
    setButtons( KDialog::Ok|KDialog::Cancel );
    enableButtonOk(false);

    QRegExp regexpC("[0-9]{0,13}");
    QRegExpValidator * validatorEAN13 = new QRegExpValidator(regexpC, this);
    ui->editSaleId->setValidator(validatorEAN13);

    connect( ui->editName, SIGNAL(textEdited( const QString &)), SLOT(applyFilter()) );
    connect( ui->editSaleId, SIGNAL(textEdited( const QString &)), SLOT(applyFilter()) );
    connect( ui->editSaleId, SIGNAL(returnPressed()), SLOT(selectItem()) );
    connect( ui->rbAll, SIGNAL(toggled(bool)), SLOT(applyFilter()) );
    connect( ui->rbDate, SIGNAL(toggled(bool)), SLOT(applyFilter()) );
    connect( ui->rbName, SIGNAL(toggled(bool)), SLOT(applyFilter()) );
    connect( ui->rbSaleId, SIGNAL(toggled(bool)), SLOT(applyFilter()) );
    
    //connect( ui->tableWidget, SIGNAL(activated(const QModelIndex &)), SLOT(itemClicked(const QModelIndex &)) );
    connect( ui->tableWidget, SIGNAL(clicked(const QModelIndex &)), SLOT(itemClicked(const QModelIndex &)) );

    setDefaultButton(KDialog::Ok);

    ui->datePicker->setDate(QDate::currentDate());
}


void SOSelector::selectItem()
{
  enableButtonOk(false);
  QModelIndex index = ui->tableWidget->currentIndex();
  if (index == soModel->index(-1,-1) ) {
    if (soModel->rowCount() == 1) {
      ui->tableWidget->selectRow(0);
      index = ui->tableWidget->currentIndex();
      enableButtonOk(true);
      //qDebug()<<"only one row, selecting:"<<soModel->record(index.row()).value("saleid").toULongLong();
    } else {
      //Que hacer? seleccionar la primera, no seleccionar nada?
      enableButtonOk(false);
      //let the user select the appropiate.
    }
  }
  ticketNumber = soModel->record(index.row()).value("saleid").toULongLong();

 //qDebug()<<"Selected ticket# "<<ticketNumber;
}

void SOSelector::itemClicked(const QModelIndex &index)
{
  enableButtonOk(false);
  ticketNumber       = soModel->record(index.row()).value("saleid").toULongLong();
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  int count = myDb->getReadySOCountforSale(ticketNumber);
  if (count > 0) {
    //ok, the tr. contains at least one so not-delivered and not cancelled.
    enableButtonOk(true);
  }
  //qDebug()<<"Clicked on ticket# "<<ticketNumber<<"    #"<<count;
  delete myDb;
}

void SOSelector::applyFilter()
{
  if (ui->rbName->isChecked()) {
    //by name
    QString text = ui->editName->text();
    QRegExp regexp = QRegExp(text);
    if ( !regexp.isValid() )  { ui->editName->setText(""); text="";}
    if (text == "*" || text == "")
      soModel->setFilter("status > 0 and status < 3");
    else
      soModel->setFilter(QString("status > 0 and status < 3 and name REGEXP '%1'").arg(text));
  } else if (ui->rbDate->isChecked()){
    // by date
    QDate d = ui->datePicker->date();
    QDateTime dt = QDateTime(d);
    QString dtStr = dt.toString("yyyy-MM-dd hh:mm:ss");
    QString dtStr2= d.toString("yyyy-MM-dd")+" 23:59:59";
    soModel->setFilter(QString("dateTime>='%1' and dateTime<='%2' AND status > 0 and status < 3").arg(dtStr).arg(dtStr2));
  } else if (ui->rbSaleId->isChecked()){
    //by ticket number
    if (ui->editSaleId->text().isEmpty())
      soModel->setFilter("status > 0 and status < 3");
    else {
      QString num = ui->editSaleId->text();
      soModel->setFilter(QString("saleid=%1 AND status > 0 and status < 3").arg(num));
    }
  } else {
    //All
    soModel->setFilter("status > 0 and status < 3"); //saleid in (select id from transactions where state=2)
  }

  ///NOTE: Due to limitations on QSQLTableModel, we cannot use the GROUP BY statement on the model.
  ///      This only can be used on non-relational models, so we can consider to not use the relational one.
  //       GROUP BY special_orders.saleid DESC
  ///NOTE: I can bypass this by setting a '1=1 GROUP BY...' and not setting the 'setRelation'.. but the
  ///      Value for STATUS will be numbers. I found a way - a hack - of accomplish this perfectly:
  ///      Simply creating a VIEW on the Database, grouped by saleid, so i dont need the 'GROUP BY..' clause
  ///      here in the model.
  
  soModel->setSort(8, Qt::DescendingOrder);
  soModel->select();
  //qDebug()<<"Query:"<<soModel->query().lastQuery();
}

void SOSelector::setupModel()
{
  soModel = new QSqlRelationalTableModel();
  soModel->setTable("v_groupedSO");
  
  int soIdIndex = soModel->fieldIndex("orderid");
  int soDateIndex = soModel->fieldIndex("dateTime");
  int soNameIndex= soModel->fieldIndex("name");
  int soStatusIndex = soModel->fieldIndex("status");
  int soSaleIdIndex= soModel->fieldIndex("saleid");
  int soGroupElemIndex= soModel->fieldIndex("groupElements");
  int soQtyIndex = soModel->fieldIndex("qty");
  int soPriceIndex= soModel->fieldIndex("price");
  int soCostIndex= soModel->fieldIndex("cost");
  int soUnitsIndex= soModel->fieldIndex("units");
  int soNotesIndex=soModel->fieldIndex("notes");
  int soPaymentIndex=soModel->fieldIndex("payment");
  int soCompletePaymentIndex=soModel->fieldIndex("completePayment");
  
  soModel->setHeaderData(soIdIndex, Qt::Horizontal, i18n("Order #"));
  soModel->setHeaderData(soNameIndex, Qt::Horizontal, i18n("Name"));
  soModel->setHeaderData(soDateIndex, Qt::Horizontal, i18n("Date") );
  soModel->setHeaderData(soStatusIndex, Qt::Horizontal, i18n("Status") );
  soModel->setHeaderData(soSaleIdIndex, Qt::Horizontal, i18n("Tr. Id") );

  soModel->setRelation(soStatusIndex, QSqlRelation("so_status", "id", "text"));

  ui->tableWidget->setModel(soModel);
  
  ui->tableWidget->setColumnHidden(soGroupElemIndex, true);
  ui->tableWidget->setColumnHidden(soQtyIndex, true);
  ui->tableWidget->setColumnHidden(soPriceIndex, true);
  ui->tableWidget->setColumnHidden(soCostIndex, true);
  ui->tableWidget->setColumnHidden(soUnitsIndex, true);
  ui->tableWidget->setColumnHidden(soNotesIndex, true);
  ui->tableWidget->setColumnHidden(soPaymentIndex, true);
  ui->tableWidget->setColumnHidden(soCompletePaymentIndex, true);
  ui->tableWidget->setColumnHidden(soDateIndex, true);
  ui->tableWidget->setColumnHidden(soIdIndex, true);

  ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
  
  m_modelAssigned = true;

  //Show only ready for completion orders (status >0 and <3)
  soModel->setFilter("status > 0 and status < 3");
  soModel->setSort(8, Qt::DescendingOrder);
  soModel->select();

  ui->tableWidget->resizeRowsToContents();
  ui->tableWidget->resizeColumnsToContents();

  //changed here because when assigning the date to the datePicker this signal was causing to apply the filter which caused a crash due to that at such time the model was not set up.
  connect( ui->datePicker, SIGNAL(changed(QDate)), SLOT(applyFilter()) );
}

void SOSelector::setDb(QSqlDatabase database)
{
  db = database;
  if (!db.isOpen()) db.open();

  //wait and create model
  QTimer::singleShot(200, this, SLOT(setupModel()));
}

SOSelector::~SOSelector()
{
  delete ui;
}

void SOSelector::slotButtonClicked(int button)
{
  if (button == KDialog::Ok) {
    QDialog::accept();
  }
  else QDialog::reject();
}