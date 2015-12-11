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

#include <QByteArray>

#include "promoeditor.h"
#include "../../dataAccess/azahar.h"

PromoEditorUI::PromoEditorUI( QWidget *parent )
: QFrame( parent )
{
    setupUi( this );
}

PromoEditor::PromoEditor( QWidget *parent )
: KDialog( parent )
{
    ui = new PromoEditorUI( this );
    setMainWidget( ui );
    setCaption( i18n("Discounts Editor") );
    setButtons( KDialog::Ok|KDialog::Cancel );

    // BFB: New spinboxPrice: I've created new slots to control when discount, price or product are changed
    connect( ui->spinboxDiscount, SIGNAL(valueChanged(double)),this, SLOT(discountChanged()) );
    connect( ui->spinboxPrice, SIGNAL(/*editingFinished*/valueChanged(double)),this, SLOT(priceChanged()) );
    connect(ui->offersDatepickerStart, SIGNAL(dateChanged(const QDate & )), this, SLOT(checkValid()));
    connect(ui->offersDatepickerEnd, SIGNAL(dateChanged(const QDate & )), this, SLOT(checkValid()));
    connect(ui->productsList, SIGNAL(clicked(const QModelIndex &)), this, SLOT(productChanged()));
    connect(ui->productsList, SIGNAL(activated(const QModelIndex &)), this, SLOT(productChanged()));
    connect(ui->productsList, SIGNAL(entered(const QModelIndex &)), this, SLOT(productChanged()));

    enableButtonOk(false);
    QTimer::singleShot(750, this, SLOT(checkValid()));
}

PromoEditor::~PromoEditor()
{
    delete ui;
}

void PromoEditor::setDb(QSqlDatabase database)
{
  db = database;
  if (!db.isOpen()) db.open();
  populateCategoriesCombo();
  //create the model
  model = new QSqlRelationalTableModel();
  setupModel();
  ui->productsList->setCurrentIndex(model->index(-1, -1));

  connect( ui->chByName, SIGNAL(toggled(bool)), SLOT(setFilter()));
  connect( ui->chByCat, SIGNAL(toggled(bool)), SLOT(setFilter()));
  connect( ui->editName, SIGNAL(textEdited(const QString &)), SLOT(setFilter()));
  connect( ui->comboCategory, SIGNAL(currentIndexChanged( int ) ), SLOT(setFilter()));
}

void PromoEditor::populateCategoriesCombo()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  ui->comboCategory->addItems(myDb->getCategoriesList());
}


//FIXME: How to detect when a product does not exists? code=-1, but here codes are unsigned, to allow a broader range.
qulonglong PromoEditor::getSelectedProductCode()
{
  qulonglong code=0;
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);

  QModelIndex index = ui->productsList->currentIndex();
  if (index.isValid()) {
    QString data = model->data(index, Qt::DisplayRole).toString();
    code = myDb->getProductCode(data);
  }

  return code;
}


// BFB: New spinboxPrice. We need to obtain product price, and then calculate offer price
void PromoEditor::productChanged()
{
  qulonglong code = getSelectedProductCode();
  if (code != 0){
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    ProductInfo info = myDb->getProductInfo(QString::number(code));
    ui->spinboxPrice->setValue(info.price*(100.0-ui->spinboxDiscount->value())/100);
  }
  checkValid();
}

// BFB: New spinboxPrice. Calculate offer product price from percentage
void PromoEditor::discountChanged()
{
  if (isProductSelected()){
    qulonglong code = getSelectedProductCode();
    if (code != 0){
      Azahar *myDb = new Azahar;
      myDb->setDatabase(db);
      ProductInfo info = myDb->getProductInfo(QString::number(code));
      ui->spinboxPrice->setValue(info.price*(100.0-ui->spinboxDiscount->value())/100);
    }
  }
  checkValid();
}

// BFB: New spinboxPrice. Calculate offer percentage from offer price
void PromoEditor::priceChanged()
{
  if (isProductSelected()){
    qulonglong code = getSelectedProductCode();
    if (code != 0){
      Azahar *myDb = new Azahar;
      myDb->setDatabase(db);
      ProductInfo info = myDb->getProductInfo(QString::number(code));
      ui->spinboxDiscount->setValue(100.0-(ui->spinboxPrice->value()*100/info.price));
    }
  }
  checkValid();
}

void PromoEditor::checkValid()
{
  bool validAmount = ui->spinboxDiscount->value() > 0.0 ? true : false;
  bool validDate   = ((getDateStart() < getDateEnd()) && (getDateEnd() > QDate::currentDate())) ? true : false;
  bool valid = isProductSelected() && validAmount && validDate;

  qDebug()<<"Valid Amount:"<<validAmount<<" Valid Date:"<<validDate<<" finally is valid="<<valid;
  
  enableButtonOk(valid);
    
}

bool PromoEditor::isProductSelected()
{
   QModelIndex index = ui->productsList->currentIndex();
   if (index.isValid()) return true; else return false;
}

void PromoEditor::setFilter()
{
  QRegExp regexp = QRegExp(ui->editName->text());
  if (ui->chByName->isChecked()) {
    //1st if: Filter by DESC.
    if (!regexp.isValid() || ui->editName->text().isEmpty() || (ui->editName->text()=="*") )  model->setFilter("");
    else  model->setFilter(QString("products.name REGEXP '%1'").arg(ui->editName->text()));
  }
  else { // filter by category...
    int catId=-1;
    QString catText = ui->comboCategory->currentText();
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    catId = myDb->getCategoryId(catText);
    //qDebug()<<"Category:"<<catText<<" Id:"<<catId;
    model->setFilter(QString("products.category=%1").arg(catId));
  }
}

void PromoEditor::setupModel()
{
  if (db.isOpen()) {
    model->setTable("products");

    ui->productsList->setModel(model);
    ui->productsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->productsList->setModelColumn(model->fieldIndex("name"));
    ui->productsList->setSelectionMode(QAbstractItemView::SingleSelection);

    model->setFilter("");
    model->select();
  }
}


#include "promoeditor.moc"
