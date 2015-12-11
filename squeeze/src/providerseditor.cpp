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
#include <KLocale>
#include <KMessageBox>
#include <KFileDialog>
#include <KStandardDirs>

#include <QByteArray>
#include <QRegExpValidator>
#include <QRegExp>
#include <QtSql>

#include "providerseditor.h"
#include "../../dataAccess/azahar.h"
#include "../../src/inputdialog.h"
#include "../../mibitWidgets/mibittip.h"
#include "../../mibitWidgets/mibitfloatpanel.h"
#include "../../src/misc.h"


ProvidersEditorUI::ProvidersEditorUI( QWidget *parent )
: QFrame( parent )
{
    setupUi( this );
}

ProvidersEditor::ProvidersEditor( QWidget *parent, bool newProvider, const QSqlDatabase& database )
: KDialog( parent )
{
    modelCreated = false;
    db = database;
    enableButtonOk(false);
    
    ui = new ProvidersEditorUI( this );
    setMainWidget( ui );
    setCaption( i18n("Product Editor") );
    setButtons( KDialog::Ok|KDialog::Cancel );
    
    connect( ui->btnRemove, SIGNAL(clicked()), SLOT( removeItem()) );
    connect( ui->btnAttach, SIGNAL(clicked()), SLOT( addItem()) );
    connect( ui->editName, SIGNAL(editingFinished()), this, SLOT(checkFieldsState()));
    connect( ui->editAddress, SIGNAL(textChanged()), this, SLOT(checkFieldsState()));
    connect( ui->editPhone, SIGNAL(editingFinished()), this, SLOT(checkFieldsState()));
    connect( ui->editCell, SIGNAL(textChanged(const QString &)), this, SLOT(checkFieldsState()));

    QString path = KStandardDirs::locate("appdata", "styles/");
    path = path+"floating_bottom.svg";
    panel = new MibitFloatPanel(this, path, Bottom);
    panel->setSize(350,200);
    panel->setMode(pmManual);
    panel->setHiddenTotally(true);
    panel->addWidget(ui->attachment);

    connect( ui->btnAdd,    SIGNAL(clicked()), panel, SLOT( showPanel() ) );
    connect( ui->btnAttach, SIGNAL(clicked()), panel, SLOT( hidePanel() ) );
    connect( ui->btnCancelAttach, SIGNAL(clicked()), panel, SLOT( hidePanel()) );

    m_pInfo.id = 0;
    m_pInfo.name = "";
    m_pInfo.address = "";
    m_pInfo.phone = "";
    m_pInfo.cell = "";
}

ProvidersEditor::~ProvidersEditor()
{
    //remove products filter
    m_model->setFilter("");
    m_model->select();
    m_model2->setFilter("");
    m_model2->select();
    delete m_model;
    delete m_model2;
    delete ui;
}

void ProvidersEditor::setDb(QSqlDatabase database)
{
  db = database;
  if (!db.isOpen()) db.open();

  setupModel();
}

void ProvidersEditor::checkFieldsState()
{
  bool ready = false;
  if ( !ui->editName->text().isEmpty()    &&
    !ui->editAddress->toPlainText().isEmpty()    &&
    !ui->editPhone->text().isEmpty()      &&
    !ui->editCell->text().isEmpty()         )  {
      ready = true;
  }
  enableButtonOk(ready);

  if (!ready) {
    //ui->editName->setFocus();
  }
}

void ProvidersEditor::slotButtonClicked(int button)
{
  //update all information...
  m_pInfo.name = ui->editName->text();
  m_pInfo.address = ui->editAddress->toPlainText();
  m_pInfo.phone = ui->editPhone->text();
  m_pInfo.cell = ui->editCell->text();
  
  if (button == KDialog::Ok)
     QDialog::accept();
  else
    QDialog::reject();
}

void ProvidersEditor::setupModel()
{
  if (!modelCreated) {
    m_model  = new QSqlRelationalTableModel();
    m_model2 = new QSqlRelationalTableModel();
    modelCreated = true;
  }

  m_model->setTable("products_providers");
  int pprovIdIndex   = m_model->fieldIndex("id");
  int pprovProdIdIndex = m_model->fieldIndex("product_id");
  int pprovProvIdIndex  = m_model->fieldIndex("provider_id");
  int pprovPriceIndex= m_model->fieldIndex("price");
  
  m_model->setHeaderData(pprovProdIdIndex, Qt::Horizontal, i18n("Product Name"));
  m_model->setHeaderData(pprovPriceIndex, Qt::Horizontal, i18n("Last Price"));
  m_model->setRelation(pprovProdIdIndex, QSqlRelation("products", "code", "name"));
  
  ui->prodTable->setModel(m_model);
  ui->prodTable->setSelectionMode(QAbstractItemView::SingleSelection);
  ui->prodTable->setColumnHidden(pprovIdIndex, true);
  ui->prodTable->setColumnHidden(pprovProvIdIndex, true);
  ui->prodTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
  
  ui->prodTable->setCurrentIndex(m_model->index(0, 0));
  m_model->select();
  ui->prodTable->resizeColumnsToContents();

  //set filter according to the provider
  m_model->setFilter(QString("provider_id=%1").arg(m_pInfo.id));
  m_model->select();

  //Setup Products model...
  m_model2->setTable("products");
  ui->productsList->setModel(m_model2);
  ui->productsList->setModelColumn(1); //name
  ui->productsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
  
  m_model2->setFilter("");
  m_model2->select();
}

void ProvidersEditor::addItem()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);

  //get selected items from list
  QItemSelectionModel *selectionModel = ui->productsList->selectionModel();
  QModelIndexList indexList = selectionModel->selectedRows(); // pasar el indice que quiera (0=code, 1=name)
  foreach(QModelIndex index, indexList) {
    qulonglong code = index.data().toULongLong(); // product CODE
    ProductInfo pInfo;
    //get product info from db
    pInfo = myDb->getProductInfo(QString::number(code));
    
    //check if the product to be added is not already there
    if (!myDb->providerHasProduct(m_pInfo.id, code)) {
      qDebug()<<"The product "<<code<<" is not provided by the porvider yet";
      //insert into the db.
      ProductProviderInfo info;
      info.prodId = code;
      info.provId = m_pInfo.id;
      info.price  = pInfo.price;
      myDb->addProductToProvider(info);
    }
  }
  m_model->select();
  enableButtonOk(true);
  delete myDb;
}

void ProvidersEditor::removeItem()
{
  QModelIndex index = ui->prodTable->currentIndex();
  if (index != m_model->index(-1,-1)) {
    //get selected item from table
    qulonglong  pID = m_model->record(index.row()).value("id").toULongLong();
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    myDb->deleteProductProvider(pID);
    m_model->select();
    delete myDb;
    enableButtonOk(true);
  } //there is something selected
}

void ProvidersEditor::setProviderId(qulonglong id)
{
  //get Info...
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  m_pInfo = myDb->getProviderInfo(id);
  //update form
  ui->editName->setText(m_pInfo.name);
  ui->editAddress->setText(m_pInfo.address);
  ui->editPhone->setText(m_pInfo.phone);
  ui->editCell->setText(m_pInfo.cell);
  //re filter products
  m_model->setFilter(QString("provider_id=%1").arg(m_pInfo.id));
  m_model->select();
}

#include "providerseditor.moc"
