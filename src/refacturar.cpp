/***************************************************************************
 *   Copyright (C) 2012 by Miguel Chavez Gamboa                            *
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

#include "refacturar.h"
#include "../../dataAccess/azahar.h"

RefacturarDialogUI::RefacturarDialogUI( QWidget *parent )
: QFrame( parent )
{
    setupUi( this );
}

RefacturarDialog::RefacturarDialog( QWidget *parent )
: KDialog( parent )
{
    m_modelAssigned = false;
    inNumber = "";

    ui = new RefacturarDialogUI( this );
    setMainWidget( ui );
    setCaption( i18n("Reimprimir Factura") );
    setButtons( KDialog::Ok|KDialog::Cancel );
    enableButtonOk(false);

    connect(ui->tableWidget, SIGNAL(clicked(const QModelIndex &)), SLOT(itemClicked(const QModelIndex &)));
    setDefaultButton(KDialog::Ok);
}


void RefacturarDialog::selectItem()
{
  enableButtonOk(false);
  QModelIndex index = ui->tableWidget->currentIndex();
  if (index == inModel->index(-1,-1) ) {
    if (inModel->rowCount() == 1) {
      ui->tableWidget->selectRow(0);
      index = ui->tableWidget->currentIndex();
      enableButtonOk(true);
    } else {
      enableButtonOk(false);
      //let the user select the appropiate.
    }
  }
  inNumber = inModel->record(index.row()).value("folio").toString();

 qDebug()<<"Selected Invoice # "<<inNumber;
}

void RefacturarDialog::itemClicked(const QModelIndex &index)
{
  enableButtonOk(false);

  inNumber       = inModel->record(index.row()).value("folio").toString();
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);

  if ( !inNumber.isEmpty() ) enableButtonOk(true);
  delete myDb;
}

void RefacturarDialog::item_Clicked(const QModelIndex &index, const QModelIndex &indexp)
{
    itemClicked(index);
}


void RefacturarDialog::setupModel()
{
  inModel = new QSqlRelationalTableModel();
  inModel->setTable("facturas_cbb");

  int folioIndex = inModel->fieldIndex("folio");
  int fechaIndex = inModel->fieldIndex("fecha");
  int trIndex = inModel->fieldIndex("transaction_id");
  int clienteIndex= inModel->fieldIndex("nombre_cliente");
  int rfcIndex= inModel->fieldIndex("rfc_cliente");
  int addrIndex= inModel->fieldIndex("direccion_cliente");
  int totalIndex = inModel->fieldIndex("total");
  int numAutIndex = inModel->fieldIndex("folio_num_autorizacion");
  int fechaAutIndex = inModel->fieldIndex("folio_fecha_autorizacion");
  int validaIndex = inModel->fieldIndex("valida");
  int subtotalIndex = inModel->fieldIndex("subtotal");
  int ivaIndex = inModel->fieldIndex("impuestos");
  int ivaTasaIndex = inModel->fieldIndex("impuestos_tasa");
  int descuentoIndex = inModel->fieldIndex("descuentos");
  

  inModel->setHeaderData(folioIndex, Qt::Horizontal, i18n("Factura"));
  inModel->setHeaderData(fechaIndex, Qt::Horizontal, i18n("Fecha"));
  inModel->setHeaderData(trIndex, Qt::Horizontal, i18n("Ticket #") );
  inModel->setHeaderData(clienteIndex, Qt::Horizontal, i18n("Nombre del Cliente"));
  inModel->setHeaderData(rfcIndex, Qt::Horizontal, i18n("RFC del Cliente"));
  inModel->setHeaderData(totalIndex, Qt::Horizontal, i18n("Total"));


  ui->tableWidget->setModel(inModel);

  ui->tableWidget->setColumnHidden(numAutIndex, true);
  ui->tableWidget->setColumnHidden(fechaAutIndex, true);
  ui->tableWidget->setColumnHidden(validaIndex, true);
  ui->tableWidget->setColumnHidden(subtotalIndex, true);
  ui->tableWidget->setColumnHidden(ivaIndex, true);
  ui->tableWidget->setColumnHidden(ivaTasaIndex, true);
  ui->tableWidget->setColumnHidden(descuentoIndex, true);
  ui->tableWidget->setColumnHidden(addrIndex, true);

  ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

  m_modelAssigned = true;

  inModel->setFilter(QString("valida=1"));
  inModel->setSort(fechaIndex, Qt::DescendingOrder);
  inModel->select();

  ui->tableWidget->resizeRowsToContents();
  ui->tableWidget->resizeColumnsToContents();

  QItemSelectionModel *selModel = ui->tableWidget->selectionModel();
    connect(selModel,
            SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
            SLOT(item_Clicked(const QModelIndex &, const QModelIndex &)));

}

void RefacturarDialog::setDb(QSqlDatabase database)
{
  db = database;
  if (!db.isOpen()) db.open();

  //wait and create model
  QTimer::singleShot(300, this, SLOT(setupModel()));
}

RefacturarDialog::~RefacturarDialog()
{
  delete ui;
}

void RefacturarDialog::slotButtonClicked(int button)
{
  if (button == KDialog::Ok) {
    QDialog::accept();
  }
  else QDialog::reject();
}


// void RefacturarDialog::filterClient()
// {
//     QString str = ui->editSearch->text();
//     //analize string, if it is a number, then search by id, if alphanum then by name.
//     if (str.isEmpty() || str == " "){ //clean filter
//         inModel->setFilter("");
//         inModel->setSort(0, Qt::DescendingOrder);
//         inModel->select();
//     } else {
//         //search by client code (alphanum, 0000001 and not 1)
//         //int trDateIndex = inModel->fieldIndex("date");
//         inModel->setFilter(QString("code = '%1'").arg(str)); //userid = %1 .arg(userId)
//         inModel->setSort(/*trDateIndex*/0, Qt::DescendingOrder); //it can be sorted only by one field.
//         inModel->select();
//         //clean edit after filtering? This can be faster to make search one after another if needed.
//         ui->editSearch->clear();
//     }
// }
