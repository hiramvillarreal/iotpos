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

#include "producteditor.h"
#include "subcategoryeditor.h"
#include "../../dataAccess/azahar.h"
#include "../../src/inputdialog.h"
#include "../../mibitWidgets/mibittip.h"
#include "../../mibitWidgets/mibitfloatpanel.h"


ProductEditorUI::ProductEditorUI( QWidget *parent )
: QFrame( parent )
{
    setupUi( this );
}

ProductEditor::ProductEditor( QWidget *parent, bool newProduct )
: KDialog( parent )
{
    oldStockQty = 0;
    correctingStockOk = false;
    m_modelAssigned = false;
    
    groupInfo.isAvailable = true;
    groupInfo.cost  = 0;
    groupInfo.price = 0;
    groupInfo.name  = "";
    groupInfo.tax = 0;
    groupInfo.taxMoney = 0;
    
    ui = new ProductEditorUI( this );
    setMainWidget( ui );
    setCaption( i18n("Product Editor") );
    setButtons( KDialog::Ok|KDialog::Cancel );
    
    QString path = KStandardDirs::locate("appdata", "styles/");
    path = path+"tip.svg";
    errorPanel = new MibitTip(this, ui->editCode, path, DesktopIcon("dialog-warning", 32));
    errorPanel->setMaxHeight(65);

    errorAlphacode = new MibitTip(this, ui->editAlphacode, path, DesktopIcon("dialog-warning", 32));
    errorAlphacode->setMaxHeight(65);
    errorVendorcode = new MibitTip(this, ui->editVendorcode, path, DesktopIcon("dialog-warning", 32));
    errorVendorcode->setMaxHeight(65);
    
    path = KStandardDirs::locate("appdata", "styles/");
    path = path+"floating_bottom.svg";
    groupPanel = new MibitFloatPanel(this, path, Bottom);
    groupPanel->setSize(550,250);
    groupPanel->addWidget(ui->groupsPanel);
    groupPanel->setMode(pmManual);
    groupPanel->setHiddenTotally(true);
    ui->btnShowGroup->setDisabled(true);

    ui->btnChangeCode->setIcon(QIcon(DesktopIcon("edit-clear", 32)));

    //Set Validators for input boxes
    QRegExp regexpC("[0-9]{1,13}"); //(EAN-13 y EAN-8) .. y productos sin codigo de barras?
    QRegExpValidator * validatorEAN13 = new QRegExpValidator(regexpC, this);
    ui->editCode->setValidator(validatorEAN13);
    ui->editUtility->setValidator(new QDoubleValidator(0.00, 999999999999.99, 3,ui->editUtility));
    ui->editTax->setValidator(new QDoubleValidator(0.00, 999999999999.99, 3,ui->editTax));
    ui->editExtraTaxes->setValidator(new QDoubleValidator(0.00, 999999999999.99, 3,ui->editExtraTaxes));
    ui->editCost->setValidator(new QDoubleValidator(0.00, 999999999999.99, 3, ui->editCost));
    ui->editStockQty->setValidator(new QDoubleValidator(0.00,999999999999.99, 3, ui->editStockQty));
    ui->editPoints->setValidator(new QIntValidator(0,999999999, ui->editPoints));
    ui->editFinalPrice->setValidator(new QDoubleValidator(0.00,999999999999.99, 3, ui->editFinalPrice));
    QRegExp regexpAC("[0-9]*[//.]{0,1}[0-9]{0,2}[//*]{0,1}[0-9]*[A-Za-z_0-9\\\\/\\-]{0,30}"); // Instead of {0,13} fro EAN13, open for up to 30 chars.
    QRegExpValidator * validatorAC = new QRegExpValidator(regexpAC, this);
    ui->editAlphacode->setValidator(validatorAC);
    ui->editVendorcode->setValidator(validatorAC); //the same validator as alphacode.

    connect( ui->btnPhoto          , SIGNAL( clicked() ), this, SLOT( changePhoto() ) );
    connect( ui->btnCalculatePrice , SIGNAL( clicked() ), this, SLOT( calculatePrice() ) );
    connect( ui->btnChangeCode,      SIGNAL( clicked() ), this, SLOT( changeCode() ) );
    connect( ui->editCode, SIGNAL(textEdited(const QString &)), SLOT(checkIfCodeExists()));
    connect( ui->editCode, SIGNAL(editingFinished()), this, SLOT(checkFieldsState()));
    connect( ui->editCode, SIGNAL(returnPressed()), this, SLOT(checkFieldsState()));
    connect( ui->btnStockCorrect,      SIGNAL( clicked() ), this, SLOT( modifyStock() ));

    connect( ui->editDesc, SIGNAL(editingFinished()), this, SLOT(checkFieldsState()));
    connect( ui->editStockQty, SIGNAL(editingFinished()), this, SLOT(checkFieldsState()));
    connect( ui->editPoints, SIGNAL(editingFinished()), this, SLOT(checkFieldsState()));
    connect( ui->editCost, SIGNAL(editingFinished()), this, SLOT(checkFieldsState()));
    connect( ui->editTax, SIGNAL(editingFinished()), this, SLOT(checkFieldsState()));
    connect( ui->editExtraTaxes, SIGNAL(editingFinished()), this, SLOT(checkFieldsState()));
    connect( ui->editFinalPrice, SIGNAL(textChanged(const QString &)), SLOT(checkFieldsState()));

    connect( ui->chIsAGroup, SIGNAL(clicked(bool)), SLOT(toggleGroup(bool)) );
    connect( ui->chIsARaw, SIGNAL(clicked(bool)), SLOT(toggleRaw(bool)) );
    connect( ui->btnCloseGroup, SIGNAL(clicked()), groupPanel, SLOT(hidePanel()) );
    connect( ui->btnCloseGroup, SIGNAL(clicked()), this, SLOT(checkFieldsState()) );
    connect( ui->btnShowGroup, SIGNAL(clicked()),  groupPanel, SLOT(showPanel()) );
    connect( ui->editFilter, SIGNAL(textEdited ( const QString &)), SLOT(applyFilter(const QString &)) );
    connect( ui->btnAdd,    SIGNAL(clicked()), SLOT(addItem()) );
    connect( ui->btnRemove, SIGNAL(clicked()), SLOT(removeItem()) );
    connect( ui->groupView, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), SLOT(itemDoubleClicked(QTableWidgetItem*)) );

    connect( ui->editGroupPriceDrop, SIGNAL(valueChanged(double)), SLOT(updatePriceDrop(double)) );
    connect( ui->editFinalPrice, SIGNAL(textChanged(QString) ), SLOT(calculateProfit(QString)) );

    connect( ui->chUnlimitedStock, SIGNAL(clicked(bool)), SLOT(setUnlimitedStock(bool)) );

    connect( ui->editAlphacode,  SIGNAL(textEdited(const QString &)), this, SLOT(verifyAlphacodeDuplicates()) );
    connect( ui->editVendorcode,  SIGNAL(textEdited(const QString &)), this, SLOT(verifyVendorcodeDuplicates()) );

    connect( ui->departmentsCombo, SIGNAL(currentIndexChanged( int )), SLOT(modifyDepartment()) );
    connect( ui->categoriesCombo, SIGNAL(currentIndexChanged( int )), SLOT(modifyCategory()) );
    connect( ui->btnCreateCategory, SIGNAL(clicked()), SLOT(createNewCategory()) );
    connect( ui->btnCreateSubcategory, SIGNAL(clicked()), SLOT(createNewSubcategory()) );
    connect( ui->btnCreateDepartment, SIGNAL(clicked()), SLOT(createNewDepartment()) );
    connect( ui->btnCreateMeasure, SIGNAL(clicked()), SLOT(createNewMeasure()) );

    status = statusNormal;
    modifyCode = false;
    autoCode = newProduct;

    if (newProduct) {
      ui->labelStockQty->setText(i18n("Purchase Qty:"));
      disableStockCorrection();
      qDebug()<<"Adding new product, autocalulate code:"<<autoCode;
      if (autoCode) {
          qulonglong c = getNextCode();
          ui->editCode->setText(QString::number(c));
          qDebug()<<"Got next code:"<<c;
          ui->editAlphacode->setFocus();
      }
    } else ui->labelStockQty->setText(i18n("Stock Qty:"));

    QTimer::singleShot(350, this, SLOT(checkIfCodeExists()));
    QTimer::singleShot(450, this, SLOT(applyFilter()));

    ui->editStockQty->setText("0.0");
    ui->editPoints->setText("0.0");
    ui->editExtraTaxes->setText("0.0");
    
    autoCode = false;
}

ProductEditor::~ProductEditor()
{
    //remove products filter
    m_model->setFilter("");
    m_model->select();

    
    delete ui;
}

void ProductEditor::applyFilter(const QString &text)
{
  QRegExp regexp = QRegExp(text);
  if (!regexp.isValid())  ui->editFilter->setText("");
  if (ui->chIsAGroup->isChecked()) {
    if (text == "*" || text == "") m_model->setFilter("products.isAGroup=0 AND products.isARawProduct=0");
    else  m_model->setFilter(QString("products.name REGEXP '%1' AND products.isAGroup=0 AND products.isARawProduct=0").arg(text));
  } else {
    m_model->setFilter("");
  }

  m_model->select();
}

void ProductEditor::applyFilter()
{
  if (ui->chIsAGroup->isChecked()) {
     m_model->setFilter("products.isAGroup=0 AND products.isARawProduct=0");
  } else {
    m_model->setFilter("");
  }
  
  m_model->select();
}

void ProductEditor::setDb(QSqlDatabase database)
{
  db = database;
  if (!db.isOpen()) db.open();
  populateDepartmentsCombo();
  //populateCategoriesCombo(); categories and subcategories is called by the above.
  populateMeasuresCombo();
}

void ProductEditor::populateDepartmentsCombo()
{
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    ui->departmentsCombo->clear();
    ui->departmentsCombo->addItems(myDb->getDepartmentsList());
    populateCategoriesCombo(); //call populateCategoriesCombo also!
    delete myDb;
}

void ProductEditor::populateCategoriesCombo()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  ui->categoriesCombo->clear();
  ui->categoriesCombo->addItems(myDb->getCategoriesList());
  populateSubCategoriesCombo(); //call populateSubcategoriesCombo also!
  delete myDb;
}

void ProductEditor::populateSubCategoriesCombo()
{
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    ui->subcategoriesCombo->clear();
    ui->subcategoriesCombo->addItems(myDb->getSubCategoriesList());
    delete myDb;
}

void ProductEditor::populateMeasuresCombo()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  ui->measuresCombo->clear();
  ui->measuresCombo->addItems(myDb->getMeasuresList());
  delete myDb;
}


int ProductEditor::getDepartmentId()
{
    int code=-1;
    QString currentText = ui->departmentsCombo->currentText();
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    code = myDb->getDepartmentId(currentText);
    delete myDb;
    return code;
}

int ProductEditor::getCategoryId()
{
  int code=-1;
  QString currentText = ui->categoriesCombo->currentText();
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  code = myDb->getCategoryId(currentText);
  delete myDb;
  return code;
}

int ProductEditor::getSubCategoryId()
{
    int code=-1;
    QString currentText = ui->subcategoriesCombo->currentText();
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    code = myDb->getSubCategoryId(currentText);
    delete myDb;
    return code;
}

//returns the parent category id of a subcategory.
int ProductEditor::getSubCategoryParent()
{
    int code=-1;
    QString currentText = ui->categoriesCombo->currentText(); //get category
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    code = myDb->getCategoryId(currentText);
    delete myDb;
    return code;
}

int ProductEditor::getMeasureId()
{
  int code=-1;
  QString currentText = ui->measuresCombo->currentText();
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  code = myDb->getMeasureId(currentText);
  delete myDb;
  return code;
}

void ProductEditor::setDepartment(QString str)
{
    int idx = ui->departmentsCombo->findText(str,Qt::MatchCaseSensitive);
    if (idx > -1) ui->departmentsCombo->setCurrentIndex(idx);
    else {
        qDebug()<<"Department not found:"<<str;
    }
}

void ProductEditor::setCategory(QString str)
{
 int idx = ui->categoriesCombo->findText(str,Qt::MatchCaseSensitive);
 if (idx > -1) ui->categoriesCombo->setCurrentIndex(idx);
 else {
  qDebug()<<"Category not found:"<<str;
  }
}

void ProductEditor::setSubCategory(QString str)
{
    if (str == "") {ui->subcategoriesCombo->setCurrentIndex(0); return;}
    
    int idx = ui->subcategoriesCombo->findText(str,Qt::MatchCaseSensitive);
    if (idx > -1) ui->subcategoriesCombo->setCurrentIndex(idx);
    else {
        qDebug()<<"SubCategory not found:"<<str;
    }
}

void ProductEditor::setDepartment(int i)
{
    QString text = getDepartmentStr(i);
    setDepartment(text);
    qDebug()<<"SET DEPARTMENT INT :: Department Id:"<<i<<" Name:"<<text;
}

void ProductEditor::setCategory(int i)
{
 QString text = getCategoryStr(i);
 setCategory(text);
 qDebug()<<"SET CATEGORY INT :: Category Id:"<<i<<" Name:"<<text;
}

void ProductEditor::setSubCategory(int i)
{
    QString text = getSubCategoryStr(i);
    setSubCategory(text);
    qDebug()<<"SET SUBCATEGORY INT :: Category Id:"<<i<<" Name:"<<text;
}


//NOTE:This maybe is duplicated, because the ProducInfo already contains a category. Parent in subcategory is a pointer to the category. Both must be the same.
void ProductEditor::setSubCategoryParent(int parentId)
{
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    QString text = myDb->getCategoryStr(parentId);
    setSubCategory(text);
    qDebug()<<"SET SUBCATEGORY PARENT INT :: Category Id:"<<parentId<<" Parent Name:"<<text;
    delete myDb;
}

void ProductEditor::setMeasure(int i)
{
 QString text = getMeasureStr(i);
 setMeasure(text);
}

void ProductEditor::setMeasure(QString str)
{
int idx = ui->measuresCombo->findText(str,Qt::MatchCaseSensitive);
 if (idx > -1) ui->measuresCombo->setCurrentIndex(idx);
 else {
  qDebug()<<"Measure not found:"<<str;
  }
}

QString ProductEditor::getDepartmentStr(int c)
{
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    QString str = myDb->getDepartmentStr(c);
    delete myDb;
    return str;
}

QString ProductEditor::getCategoryStr(int c)
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  QString str = myDb->getCategoryStr(c);
  delete myDb;
  return str;
}

QString ProductEditor::getSubCategoryStr(int c)
{
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    QString str = myDb->getSubCategoryStr(c);
    qDebug()<<"Getting subcategory #"<<c<<" -- "<<str;
    delete myDb;
    return str;
}

QString ProductEditor::getMeasureStr(int c)
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  QString str = myDb->getMeasureStr(c);
  delete myDb;
  return str;
}

void ProductEditor::changePhoto()
{
 QString fname = KFileDialog::getOpenFileName();
  if (!fname.isEmpty()) {
    QPixmap p = QPixmap(fname);
    setPhoto(p);
  }
}

void ProductEditor::calculatePrice()
{
 double finalPrice=0.0;
 if (ui->editCost->text().isEmpty()) {
   ui->editCost->setFocus();
 }
 else if (ui->editUtility->text().isEmpty()) {
   ui->editUtility->setFocus();
 }
 else if (ui->editTax->text().isEmpty()) {
   ui->editTax->setText("0.0");
   ui->editTax->setFocus();
   ui->editTax->selectAll();
 }
 else {
  if (ui->editExtraTaxes->text().isEmpty()) {
   ui->editExtraTaxes->setText("0.0");
   ui->editExtraTaxes->setFocus();
   ui->editExtraTaxes->selectAll();
  }
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  bool taxIncluded = myDb->getConfigTaxIsIncludedInPrice();
  delete myDb;
  double cost    = ui->editCost->text().toDouble();
  double profit  = ui->editUtility->text().toDouble();
  double tax     = ui->editTax->text().toDouble();
  double tax2    = ui->editExtraTaxes->text().toDouble();
  //Profit is calculated before taxes... 
  profit = ((profit/100)*cost);
  double cu = cost + profit;
  //FIXME: Taxes include profit... is it ok?
  tax     = ((tax/100)*cu);
  tax2    = ((tax2/100)*cu);

  /** @note: taxIncludedInPrice means that the product.price has embedded the tax already, and it is not necessary to add it at the time we are selling.
   *         So, here (editing product price) when using autocalculate price, when taxIncluded=true we need to embed the tax in the price.
   *         It is just the opposite way we do in lemon when selling (taxIncluded=true --> DO NOT add taxes).
   **/
  
  if (taxIncluded) 
    finalPrice = cost + profit + tax + tax2; 
  else
    finalPrice = cost + profit;
    
  qDebug()<<"Profit:"<<profit<<" Cost + profit:"<<cu<<" Taxes:"<<tax+tax2<<" Final Price: $"<<finalPrice;
  
  // BFB: avoid more than 2 decimal digits in finalPrice. Round.
  ui->editFinalPrice->setText(QString::number(finalPrice,'f',2));
  ui->editFinalPrice->selectAll();
  ui->editFinalPrice->setFocus();
  }
}

void ProductEditor::calculateProfit(QString amountStr)
{
    double amount = amountStr.toDouble();
    if (amount >0) {
        double profit = 0;
        double profitMoney = 0;
        double cost = 0;
        double pWOtax = 0;
        Azahar *myDb = new Azahar;
        myDb->setDatabase(db);
        bool taxIsIncluded = myDb->getConfigTaxIsIncludedInPrice();
        cost = ui->editCost->text().toDouble();
        if ( taxIsIncluded ) 
          pWOtax= ui->editFinalPrice->text().toDouble()/(1+((ui->editTax->text().toDouble()+ui->editExtraTaxes->text().toDouble())/100));
        else
          pWOtax = ui->editFinalPrice->text().toDouble();
        //TODO:use the pWOtax

        profitMoney = ( pWOtax - cost );
        profit      = ( profitMoney / cost );
        
        //qDebug()<<" calculateProfit()  Profit % "<<profit<<" Profit $ "<<profitMoney<<" Price Without Taxes:"<<pWOtax<<" Cost + profit:"<<cost+profitMoney;
        ui->lblProfit->setText(i18n("Gross Profit: %1% (%2)", QString::number(profit*100, 'f', 2) ,  KGlobal::locale()->formatMoney(profitMoney, QString(), 2) ));
    } else {
        ui->lblProfit->clear();
    }
}

void ProductEditor::changeCode()
{
  //this enables the code editing... to prevent unwanted code changes...
  enableCode();
  ui->editCode->setFocus();
  ui->editCode->selectAll();
}


void ProductEditor::modifyStock()
{
  if ( isGroup() || hasUnlimitedStock() ) {
    //simply dont allow or show a message?
    return;
  }
  double newStockQty=0;
  oldStockQty = ui->editStockQty->text().toDouble();
  bool ok = false;
  InputDialog *dlg = new InputDialog(this, true, dialogStockCorrection, i18n("Enter the quantity and reason for the change, then press <ENTER> to accept, <ESC> to cancel"));
  dlg->setProductCode(ui->editCode->text().toULongLong());
  dlg->setAmount(ui->editStockQty->text().toDouble());
  dlg->setProductCodeReadOnly();
  if (dlg->exec())
  {
    newStockQty = dlg->dValue;
    reason = dlg->reason;
    ok = true;
  }
  if (ok) { //send data to database...
    ui->editStockQty->setText( QString::number(newStockQty) ); //update this info on producteditor
    correctingStockOk = ok;
  }
}

void ProductEditor::checkIfCodeExists()
{
  enableButtonOk( false );
  QString codeStr = ui->editCode->text();
  if (codeStr.isEmpty()) {
    codeStr="-1";
  }

  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  ProductInfo pInfo = myDb->getProductInfo(codeStr);
  if (pInfo.isAGroup) {
    // get it again with the appropiate tax and price.
    pInfo = myDb->getProductInfo(codeStr, true); //the 2nd parameter is to get the taxes for the group (not considering discounts)
  }

  if (pInfo.code > 0) {
    //code exists...
    status = statusMod;
    if (!modifyCode){
      //Prepopulate dialog...
      ui->editAlphacode->setText( pInfo.alphaCode );
      ui->editVendorcode->setText( pInfo.vendorCode );
      ui->editDesc->setText(pInfo.desc);
      ui->editStockQty->setText(QString::number(pInfo.stockqty));
      setDepartment(pInfo.department);
      setCategory(pInfo.category);
      setSubCategory(pInfo.subcategory);
      setMeasure(pInfo.units);
      ui->editCost->setText(QString::number(pInfo.cost));
      ui->editTax->setText(QString::number(pInfo.tax));
      ui->editExtraTaxes->setText(QString::number(pInfo.extratax));
      ui->editFinalPrice->setText(QString::number(pInfo.price));
      ui->editPoints->setText(QString::number(pInfo.points));
      ui->btnShowGroup->setEnabled(pInfo.isAGroup);
      ui->btnStockCorrect->setDisabled(pInfo.isAGroup); //dont allow grouped products to make stock correction
      ui->chIsARaw->setChecked(pInfo.isARawProduct);
      
      setUnlimitedStock(pInfo.hasUnlimitedStock);
      setNotDiscountable(pInfo.isNotDiscountable);
      
      if (pInfo.isAGroup) {
        setIsAGroup(pInfo.isAGroup);
        setGroupElements(pInfo);
      }
      if (!pInfo.photo.isEmpty()) {
        QPixmap photo;
        photo.loadFromData(pInfo.photo);
        setPhoto(photo);
      }
    }//if !modifyCode
    else {
      errorPanel->showTip(i18n("Code %1 already exists.", codeStr),3000);
      enableButtonOk( false );
    }
  }
  else { //code does not exists... its a new product
    status = statusNormal;
    if (!modifyCode) {
      //clear all used edits
      ui->editAlphacode->clear();
      ui->editVendorcode->clear();
      ui->editDesc->clear();
      ui->editStockQty->clear();
      setDepartment(1);
      setCategory(1);
      setSubCategory(1);
      setMeasure(1);
      ui->editCost->clear();
      ui->editTax->clear();
      ui->editExtraTaxes->clear();
      ui->editFinalPrice->clear();
      ui->editPoints->clear();
      ui->editUtility->clear();
      ui->editFinalPrice->clear();
      ui->labelPhoto->setText("No Photo");
    }
    //qDebug()<< "no product found with code "<<codeStr<<" .query.size()=="<<query.size();
  }
  delete myDb;
}


void ProductEditor::checkFieldsState()
{
  bool ready = false;
  if ( !ui->editCode->text().isEmpty()    &&
    !ui->editDesc->text().isEmpty()       &&
    //!ui->editStockQty->text().isEmpty()   &&   Comment: This requirement was removed in order to use check-in/check-out procedures.
    !ui->editPoints->text().isEmpty()     && 
    !ui->editCost->text().isEmpty()       &&
    !ui->editTax->text().isEmpty()        &&
    !ui->editExtraTaxes->text().isEmpty() &&
    !ui->editFinalPrice->text().isEmpty() &&
    ui->editTax->text().toDouble() >= 0     /// See Ticket #74. Allow ZERO tax for some products.
    )  {
    ready = true;
  }
  enableButtonOk(ready);
  
  if (!ready  && ui->editCode->hasFocus() && ui->editCode->isReadOnly() ) {
    ui->editDesc->setFocus();
  }
}

void ProductEditor::setPhoto(QPixmap p)
{
  int max = 150;
  QPixmap newPix;
  if ((p.height() > max) || (p.width() > max) ) {
    if (p.height() == p.width()) {
      newPix = p.scaled(QSize(max, max));
    }
    else if (p.height() > p.width() ) {
      newPix = p.scaledToHeight(max);
    }
    else  {
      newPix = p.scaledToWidth(max);
    }
  } else newPix=p;
  ui->labelPhoto->setPixmap(newPix);
  pix=newPix;
}

void ProductEditor::slotButtonClicked(int button)
{
  if (button == KDialog::Ok) {
    if (status == statusNormal) QDialog::accept();
    else {
      qDebug()<< "Button = OK, status == statusMOD";
      done(statusMod);
    }
  }
  else QDialog::reject();
}

void ProductEditor::setModel(QSqlRelationalTableModel *model)
{
  ui->sourcePView->setModel(model);
  ui->sourcePView->setModelColumn(1);
  m_model = model;
  m_modelAssigned = true;

  //clear any filter
  m_model->setFilter("");
  m_model->setFilter("products.isAGroup=0 AND products.isARawProduct=0");
  m_model->select();
}

void ProductEditor::addItem()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  groupInfo.count = 0;
  groupInfo.cost = 0;
  groupInfo.price = 0;
  groupInfo.tax = 0;
  groupInfo.taxMoney = 0;

  double addQty = 0;
  addQty = ui->editGroupQty->value();

  //get selected items from source view
  QItemSelectionModel *selectionModel = ui->sourcePView->selectionModel();
  QModelIndexList indexList = selectionModel->selectedRows(); // pasar el indice que quiera (0=code, 1=name)
  foreach(QModelIndex index, indexList) {
    qulonglong code    = index.data().toULongLong();
    QString    codeStr = index.data().toString();

    ProductInfo pInfo;
    //get product info from hash or db
    if (groupInfo.productsList.contains(code)) {
      pInfo = groupInfo.productsList.take(code);
      if ( pInfo.units == 1 )
          pInfo.qtyOnList += int(addQty); //increment it  (PIECES)
      else
          pInfo.qtyOnList += addQty;      //increment it  (OTHER MEASURES)
    } else {
      pInfo = myDb->getProductInfo(codeStr, true); //the 2nd parameter is to get the taxes for the group (not considering discounts)
      if ( pInfo.units == 1 )
          pInfo.qtyOnList = int(addQty); //increment it  (PIECES)
      else
          pInfo.qtyOnList = addQty;      //increment it  (OTHER MEASURES)
    }
    //check if the product to be added is not the same of the pack product
    if (pInfo.code == ui->editCode->text().toULongLong()) continue;
      
    // Insert product to the group hash
    groupInfo.productsList.insert(code, pInfo);
  }
  //reload groupView
  updatePriceDrop(ui->editGroupPriceDrop->value());//calculateGroupValues();
  calculateProfit( ui->editFinalPrice->text() );

  //qDebug()<<"There are "<<groupInfo.count<<" items in group. The cost is:"<<groupInfo.cost<<", The price is:"<<groupInfo.price<<" And is available="<<groupInfo.isAvailable;

  delete myDb;
}

void ProductEditor::removeItem()
{
  groupInfo.count = 0;
  groupInfo.cost = 0;
  groupInfo.price = 0;
  groupInfo.tax = 0;
  groupInfo.taxMoney = 0;
  
  if (ui->groupView->currentRow() != -1 ){
    //get selected item from group view
    int row = ui->groupView->currentRow();
    QTableWidgetItem *item = ui->groupView->item(row, 1);
    QString name = item->data(Qt::DisplayRole).toString();
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    //get code from db
    qulonglong code = myDb->getProductCode(name);
    ProductInfo pInfo = groupInfo.productsList.take(code); //insert it later...
    double qty = 0;
    qty = pInfo.qtyOnList; //from hash | must be the same on groupView
    if (qty>1) {
      //qty--;
      if ( pInfo.units == 1 )
          qty -= int(ui->editGroupQty->value());   //increment it  (PIECES)
      else
          qty -= ui->editGroupQty->value();        //increment it  (OTHER MEASURES)

      pInfo.qtyOnList = qty;
      //reinsert it again
      groupInfo.productsList.insert(code, pInfo);
    }
    delete myDb;
  } //there is something selected

  //reload groupView
  updatePriceDrop(ui->editGroupPriceDrop->value());//calculateGroupValues();
  calculateProfit( ui->editFinalPrice->text() );
  
  //qDebug()<<"There are "<<groupInfo.count<<" items in group. The cost is:"<<groupInfo.cost<<", The price is:"<<groupInfo.price<<" And is available="<<groupInfo.isAvailable;
}


void ProductEditor::itemDoubleClicked(QTableWidgetItem* item)
{
  groupInfo.count = 0;
  groupInfo.cost = 0;
  groupInfo.price = 0;
  groupInfo.tax = 0;
  groupInfo.taxMoney = 0;
  int row = item->row();
  QTableWidgetItem *itm = ui->groupView->item(row, 1);
  QString name = itm->data(Qt::DisplayRole).toString();
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  //get code from db
  qulonglong code = myDb->getProductCode(name);
  ProductInfo pInfo = groupInfo.productsList.take(code); //insert it later...
  double qty = 0;
  qty = pInfo.qtyOnList+1; //from hash | must be the same on groupView

  //modify pInfo
  pInfo.qtyOnList = qty; //increment it one by one
  //reinsert it to the hash
  groupInfo.productsList.insert(code, pInfo);
  
  //reload groupView
  updatePriceDrop(ui->editGroupPriceDrop->value()); //calculateGroupValues();
  calculateProfit( ui->editFinalPrice->text() );
  delete myDb;
}

QString ProductEditor::getGroupElementsStr()
{
  QStringList list;
  foreach(ProductInfo info, groupInfo.productsList) {
    list.append(QString::number(info.code)+"/"+QString::number(info.qtyOnList));
  }
  return list.join(",");
}

bool ProductEditor::isGroup()
{
  bool result=false;
  if (groupInfo.count>0 && ui->chIsAGroup->isChecked())
    result = true;
  return result;
}

bool ProductEditor::isRaw()
{
  return ui->chIsARaw->isChecked();
}

bool ProductEditor::isNotDiscountable()
{
    return ui->chNotDiscountable->isChecked();
}

bool ProductEditor::hasUnlimitedStock()
{
    return ui->chUnlimitedStock->isChecked();
}


GroupInfo ProductEditor::getGroupHash()
{
  return groupInfo;
}

void ProductEditor::toggleGroup(bool checked)
{
  if (checked) {
    groupPanel->showPanel();
    ui->btnStockCorrect->setDisabled(true);
    ui->chIsARaw->setDisabled(true);
    ui->chIsARaw->setChecked(false);
    ui->btnShowGroup->setEnabled(true);
    m_model->setFilter("products.isAGroup=0 AND products.isARawProduct=0");
    m_model->select();
    if (ui->editGroupPriceDrop->value() <= 0) {
      ui->editGroupPriceDrop->setValue(10);
      groupInfo.priceDrop = 10;
    }
  } else {
    groupPanel->hidePanel();
    ui->btnStockCorrect->setEnabled(true);
    ui->btnShowGroup->setDisabled(true);
    ui->chIsARaw->setEnabled(true);
    m_model->setFilter("");
    m_model->select();
  }

  ui->editTax->setReadOnly(checked);
  ui->editExtraTaxes->setReadOnly(checked);
  ui->editCost->setReadOnly(checked);
  ui->editFinalPrice->setReadOnly(checked);
  ui->groupBox->setDisabled(checked);
}

void ProductEditor::toggleRaw(bool checked)
{
  if (checked){
    ui->chIsAGroup->setDisabled(true);
    ui->chIsAGroup->setChecked(false);
    ui->btnShowGroup->setDisabled(true);
  } else {
    ui->chIsAGroup->setEnabled(true);
  }
}

void ProductEditor::setIsAGroup(bool value)
{
  ui->chIsAGroup->setChecked(value);
  ui->btnShowGroup->setEnabled(value);
  ui->btnStockCorrect->setDisabled(value); //dont allow grouped products to make stock correction
  ui->editTax->setReadOnly(value);
  ui->editExtraTaxes->setReadOnly(value);
  ui->editCost->setReadOnly(value);
  ui->editFinalPrice->setReadOnly(value);
  ui->groupBox->setDisabled(value);
}

void ProductEditor::setIsARaw(bool value)
{
  ui->chIsARaw->setChecked(value);
}

void ProductEditor::setUnlimitedStock(bool value)
{
  ui->chUnlimitedStock->setChecked(value);
  //disable/enable stock correct button
  ui->btnStockCorrect->setEnabled(!value);
  qDebug()<<"setUnlimitedStock:"<<value;
}

void ProductEditor::setNotDiscountable(bool value)
{
    ui->chNotDiscountable->setChecked(value);
    qDebug()<<"setNotDiscountable:"<<value;
}

void ProductEditor::setGroupElements(ProductInfo pi)
{
  if (!ui->chIsAGroup->isChecked()) return;
  
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  groupInfo = myDb->getGroupPriceAndTax(pi);
  foreach(ProductInfo info, groupInfo.productsList) {
    //insert it to the groupView
    int rowCount = ui->groupView->rowCount();
    ui->groupView->insertRow(rowCount);
    ui->groupView->setItem(rowCount, 0, new QTableWidgetItem(QString::number(info.qtyOnList)));
    ui->groupView->setItem(rowCount, 1, new QTableWidgetItem(info.desc));
  }
  ui->groupView->resizeRowsToContents();
  ui->groupView->resizeColumnsToContents();
  delete myDb;

  ui->editTax->setText(QString::number(groupInfo.tax));
  ui->editCost->setText(QString::number(groupInfo.cost));
  ui->editFinalPrice->setText(QString::number(groupInfo.price));
  ui->editExtraTaxes->setText("0.0");
  ui->lblGPrice->setText(KGlobal::locale()->formatMoney(groupInfo.price, QString(), 2));
  ui->editGroupPriceDrop->setValue(groupInfo.priceDrop);
}

void ProductEditor::updatePriceDrop(double value)
{
  //NOTE: When changing the pricedrop and cancelling the product editor (not saving product changes) the pricedrop IS CHANGED ANYWAY
  //      This is because we are updating price drop on change and not until the product is saved (dialog OK) for re-calculateGroupValues
  //      So, the cancel button on the product will not prevent or UNDO these changes.
  //      TODO: Add this note to the manuals.
  ///     TODO: Make a backup of the priceDrop, and if cancelled, restore the backup to the db from the caller (outside this class)
  
  //first save on db... 
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  myDb->updateGroupPriceDrop(getCode(), value);
  myDb->updateGroupElements(getCode(), getGroupElementsStr());
  ProductInfo info = myDb->getProductInfo( QString::number( getCode() ) ); /// NOTE: this info is for the method below..
  GroupInfo giTemp = myDb->getGroupPriceAndTax(info);
  delete myDb;
  //if there is a new product, it will not be updated because it does not exists on db yet... so fix the groupPrice drop
  if (info.code == 0 ) {
    groupInfo.priceDrop = ui->editGroupPriceDrop->value();
    calculateGroupValues();
  } else {
    //then update prices on UI
    groupInfo = giTemp;
    ui->editCost->setText(QString::number(groupInfo.cost));
    ui->editFinalPrice->setText(QString::number(groupInfo.price));
    ui->editExtraTaxes->setText("0.0");
    ui->editTax->setText(QString::number(groupInfo.tax));
    ui->lblGPrice->setText(KGlobal::locale()->formatMoney(groupInfo.price, QString(), 2));
    //update listview
    while (ui->groupView->rowCount() > 0) ui->groupView->removeRow(0);
    foreach(ProductInfo info, groupInfo.productsList) {
      int rowCount = ui->groupView->rowCount();
      ui->groupView->insertRow(rowCount);
      ui->groupView->setItem(rowCount, 0, new QTableWidgetItem(QString::number(info.qtyOnList)));
      ui->groupView->setItem(rowCount, 1, new QTableWidgetItem(info.desc));
    }
    ui->groupView->resizeRowsToContents();
    ui->groupView->resizeColumnsToContents();
  }
}

void ProductEditor::calculateGroupValues()
{
  groupInfo.count = 0;
  groupInfo.cost = 0;
  groupInfo.price = 0;
  groupInfo.tax = 0;
  groupInfo.taxMoney = 0;

  while (ui->groupView->rowCount() > 0) ui->groupView->removeRow(0);
  foreach(ProductInfo info, groupInfo.productsList) {
    //update groupInfo
    groupInfo.count += info.qtyOnList;
    groupInfo.cost  += info.cost*info.qtyOnList;
    groupInfo.price += (info.price -info.price*(groupInfo.priceDrop/100)) * info.qtyOnList; //info.price*info.qtyOnList;
    groupInfo.taxMoney += info.totaltax*info.qtyOnList;
    bool yes = false;
    if (info.stockqty >= info.qtyOnList ) yes = true;
    groupInfo.isAvailable = (groupInfo.isAvailable && yes );
    //insert it to the groupView
    int rowCount = ui->groupView->rowCount();
    ui->groupView->insertRow(rowCount);
    ui->groupView->setItem(rowCount, 0, new QTableWidgetItem(QString::number(info.qtyOnList)));
    ui->groupView->setItem(rowCount, 1, new QTableWidgetItem(info.desc));
  }
  ui->groupView->resizeRowsToContents();
  ui->groupView->resizeColumnsToContents();
  
  //update cost and price on the form
  ui->editCost->setText(QString::number(groupInfo.cost));
  ui->editFinalPrice->setText(QString::number(groupInfo.price));
  ui->editExtraTaxes->setText("0.0");
  
  //calculate compound tax for the group.
  groupInfo.tax = 0;
  foreach(ProductInfo info, groupInfo.productsList) {
    groupInfo.tax += (info.totaltax*info.qtyOnList/groupInfo.price)*100; // totalTaxMoney = price*(taxPercentage/100)
    qDebug()<<" <Calculating Values>  qtyOnList:"<<info.qtyOnList<<" tax money for product: "<<info.totaltax<<" group price:"<<groupInfo.price<<" taxMoney for group:"<<groupInfo.taxMoney<<" tax % for group:"<< groupInfo.tax;
  }
  ui->editTax->setText(QString::number(groupInfo.tax));
  ui->lblGPrice->setText(KGlobal::locale()->formatMoney(groupInfo.price, QString(), 2));
}

double ProductEditor::getGRoupStockMax()
{
  return 1; // stockqty on grouped products will not be stored, only check for contents availability
}


qulonglong ProductEditor::getNextCode()
{
    qulonglong r=0;
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    r = myDb->getNextProductCode() + 1;
    qDebug()<<__FUNCTION__<<" next code:"<<r;
    return r;
}


void ProductEditor::verifyAlphacodeDuplicates()
{
    QString strAc = ui->editAlphacode->text();
    if (strAc.isEmpty()) strAc="-1";

    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    qulonglong rcode = myDb->getProductCodeFromAlphacode(strAc);

    if (rcode > 0) {
        errorAlphacode->showTip(i18n("Alpha Code %1 already exists.", strAc),3000);
        enableButtonOk( false );
        qDebug()<<"Duplicate alphacode!";
    } else {
        enableButtonOk( true );
    }
    
    delete myDb;
}

void ProductEditor::verifyVendorcodeDuplicates()
{
    QString strVc = ui->editVendorcode->text();
    if (strVc.isEmpty()) strVc="-1";
    
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    qulonglong rcode = myDb->getProductCodeFromVendorcode(strVc);
    
    if (rcode > 0) {
        errorVendorcode->showTip(i18n("Vendor Code %1 already exists.", strVc),3000);
        enableButtonOk( false );
        qDebug()<<"Duplicate vendor code!";
    } else {
        enableButtonOk( true );
    }
    
    delete myDb;
}

void ProductEditor::modifyDepartment()
{
    //When a department is changed, we must filter categories according.
    QString depText = ui->departmentsCombo->currentText();
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    //get categories..
    qulonglong parentId = myDb->getDepartmentId( depText );
    QStringList catList = myDb->getCategoriesList( parentId );
    ui->categoriesCombo->clear();
    ui->categoriesCombo->addItems( catList );
    qDebug()<<"CAT LIST for "<<depText<<" :"<<catList;
    delete myDb;
}

void ProductEditor::modifyCategory()
{
    //When a category is changed, we must filter subcategories according.
    QString catText = ui->categoriesCombo->currentText();
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    //get subcategories' children
    qulonglong parentId = myDb->getCategoryId( catText );
    QStringList subcatList = myDb->getSubCategoriesList( parentId );
    ui->subcategoriesCombo->clear();
    ui->subcategoriesCombo->addItems( subcatList );
    qDebug()<<"SUBCAT LIST for ("<<parentId<<") "<<catText<<" :"<<subcatList;
    delete myDb;
}

void ProductEditor::createNewSubcategory()
{
    bool ok=false;
    QString cat = QInputDialog::getText(this, i18n("New subcategory"), i18n("Enter the new subcategory:"),
                                        QLineEdit::Normal, "", &ok );
    if (ok && !cat.isEmpty()) {
        Azahar *myDb = new Azahar;
        myDb->setDatabase(db);
        if (!myDb->insertSubCategory(cat)) qDebug()<<"Error:"<<myDb->lastError();
        
        //modifyCategory(); //BUG:It is weird that this does not appends the new item; it should do it.
        ui->subcategoriesCombo->addItems( QStringList(cat) ); //WORK AROUND
        setSubCategory(cat);
        //NOTE: Hey, the subcategory here belongs to a category.. so we must insert the m2m relation!
        qulonglong scId = myDb->getSubCategoryId(cat);
        qulonglong cId  = myDb->getCategoryId( ui->categoriesCombo->currentText() );
        qDebug()<<cId<<"-->"<<scId<<" | "<<cat<<"-->"<<ui->categoriesCombo->currentText();
        if (!myDb->insertM2MCategorySubcategory(cId, scId)) qDebug()<<"ERROR:"<<myDb->lastError();
        delete myDb;
    }
}

void ProductEditor::createNewCategory()
{
    //launch dialog to ask for the new child. Using this same dialog.
    SubcategoryEditor *scEditor = new SubcategoryEditor(this);
    scEditor->setDb(db);
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);

    QStringList list = myDb->getSubCategoriesList();
    scEditor->setCatList( myDb->getCategoriesList() );
    scEditor->setScatList( list );
    scEditor->populateList( list );
    scEditor->setDialogType(2); //category = 2
    scEditor->setLabelForName(i18n("New category:"));
    scEditor->setLabelForList(i18n("Select the child subcategories for this category:"));

    if ( scEditor->exec() ) {
        QString text = scEditor->getName();
        QStringList children = scEditor->getChildren();
        qDebug()<<text<<" CHILDREN:"<<children;

        //Create the category
        if (!myDb->insertCategory(text)) {
            qDebug()<<"Error:"<<myDb->lastError();
            delete myDb;
            return;
        }
        qulonglong cId = myDb->getCategoryId(text);
        //create the m2m  relations for the new category->subcategory.
        foreach(QString cat, children) {
            //get subcategory id
            qulonglong scId = myDb->getSubCategoryId(cat);
            //create the link [category] --> [subcategory]
            myDb->insertM2MCategorySubcategory(cId, scId);
        }
        //reload categories combo
        //modifyDepartment();//BUG:It is weird that this does not appends the new item; it should do it.
        ui->categoriesCombo->addItems( QStringList(text) ); //WORK AROUND
        setCategory(text); //set the newly created category...
    }
}

void ProductEditor::createNewDepartment()
{
    //launch dialog to ask for the new child. Using this same dialog.
    SubcategoryEditor *scEditor = new SubcategoryEditor(this);
    scEditor->setDb(db);
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    
    QStringList list = myDb->getCategoriesList();
    scEditor->setCatList( list );
    scEditor->setScatList( myDb->getSubCategoriesList() );
    scEditor->populateList( list );
    scEditor->setDialogType(1); //department = 1
    scEditor->setLabelForName(i18n("New department:"));
    scEditor->setLabelForList(i18n("Select the child categories for this department:"));
    
    if ( scEditor->exec() ) {
        QString text = scEditor->getName();
        QStringList children = scEditor->getChildren();
        qDebug()<<text<<" CHILDREN:"<<children;
        
        //Create the department
        if (!myDb->insertDepartment(text)) {
            qDebug()<<"Error:"<<myDb->lastError();
            delete myDb;
            return;
        }
        qulonglong depId = myDb->getDepartmentId(text);
        //create the m2m  relations for the new department->category.
        foreach(QString cat, children) {
            //get category id
            qulonglong cId = myDb->getCategoryId(cat);
            //create the link [category] --> [subcategory]
            myDb->insertM2MDepartmentCategory(depId, cId);
        }
        //reload departments combo
        populateDepartmentsCombo();
        //ui->DepartmentsCombo->addItems( QStringList(text) ); //WORK AROUND
        setDepartment(text); //set the newly created category...
    }
}

void ProductEditor::createNewMeasure()
{
    bool ok=false;
    QString meas = QInputDialog::getText(this, i18n("New Weight or Measure"), i18n("Enter the new weight or measure to insert:"),
    QLineEdit::Normal, "", &ok );
    if (ok && !meas.isEmpty()) {
        Azahar *myDb = new Azahar;
        if (!db.isOpen()) db.open();
        myDb->setDatabase(db);
        if (!myDb->insertMeasure(meas)) qDebug()<<"Error:"<<myDb->lastError();
        
        populateMeasuresCombo();
        setMeasure(meas);
        delete myDb;
    }
}

#include "producteditor.moc"
