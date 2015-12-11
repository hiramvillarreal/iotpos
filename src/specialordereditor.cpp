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
#include <KLocale>

#include <QByteArray>
#include <QRegExpValidator>
#include <QRegExp>
#include <QtSql>
#include <QDateTime>

#include "specialordereditor.h"
#include "../../dataAccess/azahar.h"
#include "../../src/inputdialog.h"
#include "../../mibitWidgets/mibittip.h"
#include "../../mibitWidgets/mibitfloatpanel.h"


SpecialOrderUI::SpecialOrderUI( QWidget *parent )
: QFrame( parent )
{
    setupUi( this );
}

SpecialOrderEditor::SpecialOrderEditor( QWidget *parent, bool newOne )
: KDialog( parent )
{
    m_modelAssigned = false;
    priceEach   = 0;
    paymentEach = 0;
    
    groupInfo.isAvailable = true;
    groupInfo.cost  = 0;
    groupInfo.price = 0;
    groupInfo.count = 0;
    groupInfo.name  = "";

    ui = new SpecialOrderUI( this );
    setMainWidget( ui );
    setCaption( i18n("Special Orders") );
    setButtons( KDialog::Ok|KDialog::Cancel );

    //Set Validators for input boxes
    ui->editAddQty->setValidator(new QDoubleValidator(0.00, 999999999999.99, 3, ui->editAddQty));

    ui->editQty->setValue(1);
    ui->editAddQty->setText("1.00");

    connect( ui->editQty, SIGNAL(editingFinished()), this, SLOT(calculateCost()));
    connect( ui->editQty, SIGNAL(valueChanged(int)), this, SLOT(calculateCost()));

    connect( ui->editQty, SIGNAL(editingFinished()), this, SLOT(checkFieldsState()));
    connect( ui->editPayment, SIGNAL(valueChanged(double)), this, SLOT(checkFieldsState()));
    

    connect( ui->editFilter, SIGNAL(textEdited ( const QString &)), SLOT(applyFilter(const QString &)) );
    connect( ui->btnAdd,    SIGNAL(clicked()), SLOT(addItem()) );
    connect( ui->editAddQty,    SIGNAL(returnPressed()), SLOT(addItem()) );
    connect( ui->btnRemove, SIGNAL(clicked()), SLOT(removeItem()) );
    connect( ui->groupView, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), SLOT(itemDoubleClicked(QTableWidgetItem*)) );

    connect( ui->deliveryDT, SIGNAL(valueChanged(QDateTime)), this, SLOT(checkDate(QDateTime)) );

    connect( ui->editNotes, SIGNAL(textChanged()), SLOT(updateNoteLength()) );

    //for now, when creating a s.o. the status cannot be modified. It can be when edited.
    if (newOne) {
      dateTime         = QDateTime::currentDateTime();
      ui->deliveryDT->setDateTime(QDateTime::currentDateTime().addDays(1));
    }

    //tip
    QString path = KStandardDirs::locate("appdata", "styles/");
    path = path+"tip.svg";
    qtyTip   = new MibitTip(this, ui->editQty, path, DesktopIcon("dialog-warning",32) );
    path = KStandardDirs::locate("appdata", "styles/")+"rotated_tip.svg";
    groupTip = new MibitTip(this, ui->groupView, path, DesktopIcon("dialog-warning",32), tpAbove );

    path = KStandardDirs::locate("appdata", "styles/");
    path = path+"floating_bottom.svg";
    newClientPanel = new MibitFloatPanel(this, path, Top);
    newClientPanel->setSize(550,250);
    newClientPanel->addWidget(ui->frameClient);
    newClientPanel->setMode(pmManual);
    newClientPanel->setHiddenTotally(true);
    ui->editClientName->setEmptyMessage(i18n("Enter client name here..."));
    ui->editClientPhone->setEmptyMessage(i18n("Enter client phone here..."));
    ui->editClientCell->setEmptyMessage(i18n("Enter client cell phone here..."));

    connect( ui->btnNewClient, SIGNAL(clicked()), newClientPanel, SLOT(showPanel() ));
    connect( ui->btnNewClient, SIGNAL(clicked()), this, SLOT(enableCreateClient() ));
    connect( ui->btnClientCancel, SIGNAL(clicked()), newClientPanel, SLOT(hidePanel()));
    connect( ui->btnClientAdd, SIGNAL(clicked()), this, SLOT(createClient()));
    connect( ui->editClientName, SIGNAL(textEdited(const QString &)), this, SLOT(checkValidInfo()) );
    connect( ui->editClientAddress, SIGNAL(textChanged()), this, SLOT(checkValidInfo()) );
    connect( ui->editClientPhone, SIGNAL(textEdited(const QString &)), this, SLOT(checkValidInfo()) );
    connect( ui->editClientCell, SIGNAL(textEdited(const QString &)), this, SLOT(checkValidInfo()) );

    setDefaultButton(KDialog::None);
    ui->btnFilter->setDefault(true);
    ui->btnFilter->hide(); //hack to dont have a default OK or Cancel button

    ui->clientsCombo->setFocus();
    enableButtonOk(false);
}

SpecialOrderEditor::~SpecialOrderEditor()
{
    //remove products filter
    m_model->setFilter("");
    m_model->select();

    delete ui;
}

void SpecialOrderEditor::applyFilter(const QString &text)
{
  QRegExp regexp = QRegExp(text);
  if (!regexp.isValid())  ui->editFilter->setText("");
  if (text == "*" || text == "") m_model->setFilter("products.isARawProduct=true and products.isAGroup=false ");
  else  m_model->setFilter(QString("products.isARawProduct=true and products.isAGroup=false and products.name REGEXP '%1'").arg(text));

  m_model->select();
}

void SpecialOrderEditor::setDb(QSqlDatabase database)
{
  db = database;
  if (!db.isOpen()) db.open();
  populateUsersCombo();
  populateClientsCombo();
}


// void SpecialOrderEditor::checkMeasureQty()
// {
//   qDebug()<<"Currindex:"<<ui->measuresCombo->currentIndex()<<"curr text:"<<ui->measuresCombo->currentText();
//   Azahar *myDb = new Azahar;
//   myDb->setDatabase(db);
//   //check qty and combo consistency
//   int selMeasureId = myDb->getMeasureId(ui->measuresCombo->currentText());
//   if (selMeasureId == 1) {
//     //This is a piece measured item
//     if ( ui->editQty->text().contains(".") || ui->editQty->text().contains(",") ) {
//       qDebug()<<"Contains . or , -- its a double!";
//       QString reason = i18n("The selected measure is a piece, but the qty is not an integer.");
//       qtyTip->showTip(reason, 6000);
//       enableButtonOk(false);
//     } else checkFieldsState();
//   }
// }


void SpecialOrderEditor::calculateCost()
{
 priceEach = groupInfo.price;
 paymentEach = priceEach*(.50);
 double qty = 0;
 qty = ui->editQty->value();
 ui->lblPrice->setText(KGlobal::locale()->formatMoney(priceEach*qty, QString(), 2));//TOTAL!
 ui->editPayment->setValue(paymentEach*qty);
}

void SpecialOrderEditor::checkFieldsState()
{
  bool ready = false;
  if (groupInfo.count > 0 && ui->editPayment->value() > 0) ready = true;
  
  enableButtonOk(ready);
}

void SpecialOrderEditor::slotButtonClicked(int button)
{
  if (button == KDialog::Ok) {
    QDialog::accept();
  }
  else QDialog::reject();
}

void SpecialOrderEditor::setModel(QSqlTableModel *model)
{
  ui->sourcePView->setModel(model);
  ui->sourcePView->setModelColumn(1);
  m_model = model;
  m_modelAssigned = true;

  //filter to only raw products
  m_model->setFilter("products.isARawProduct=true AND products.isAGroup=false");
  m_model->select();
}

void SpecialOrderEditor::addItem()
{
  double dqty = 1; //if not any value, default is ONE
  QStringList msgP;
  QStringList msgU;
  int incTime = 0;
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  
  if (!ui->editAddQty->text().isEmpty()) {
    dqty = ui->editAddQty->text().toDouble();
  }
  //get selected items from source view
  QItemSelectionModel *selectionModel = ui->sourcePView->selectionModel();
  QModelIndexList indexList = selectionModel->selectedRows(); // pasar el indice que quiera (0=code, 1=name)
  foreach(QModelIndex index, indexList) {
    qulonglong code    = index.data().toULongLong();
    QString    codeStr = index.data().toString();
    bool exists = false;
    ProductInfo pInfo;
    //get product info from hash or db
    if (groupInfo.productsList.contains(code)) {
      pInfo = groupInfo.productsList.take(code);
      //check measures for the product
      if (pInfo.units == 1 ) { //by pieces
        QString tmpStr = ui->editAddQty->text();
        if (tmpStr.endsWith(".00")) tmpStr.chop(3); //discard .00's
        if (tmpStr.endsWith(".0")) tmpStr.chop(2);//discard .00's
        if (tmpStr.contains(".") || tmpStr.contains(",")) {
          int tmp = dqty;
          dqty = tmp; //pass to integer instead of double
          msgP.append(i18n("<i>%1</i> rounded to %2",pInfo.desc,tmp));
          incTime += 1000;
        }
      }
      if (pInfo.stockqty >= pInfo.qtyOnList+dqty)
        pInfo.qtyOnList += dqty; //increment it
      else {
        incTime += 1000;
        msgU.append(i18n("<i>%1</i> <b>requested %2, on stock %3</b><br>", pInfo.desc,dqty,pInfo.stockqty));
      }
      //if not enough, its not incremented.
      exists = true;
    } else {
      pInfo = myDb->getProductInfo(codeStr);
      //check measures for the product
      if (pInfo.units == 1) { //by pieces
        QString tmpStr = ui->editAddQty->text();
        if (tmpStr.endsWith(".00")) tmpStr.chop(3);//discard .00's
        if (tmpStr.endsWith(".0")) tmpStr.chop(2);//discard .00's
        if (tmpStr.contains(".") || tmpStr.contains(",")) {
          int tmp = dqty;
          dqty = tmp; //pass to integer instead of double
          msgP.append(i18n("<i>%1</i> rounded to %2",pInfo.desc,tmp));
          incTime += 1000;
        }
      }
      pInfo.qtyOnList = 0;
      if (pInfo.stockqty >= dqty)
        pInfo.qtyOnList = dqty;
      else {
        incTime += 1000;
        msgU.append(i18n("<i>%1</i> <b>requested %2, on stock %3</b><br>", pInfo.desc,dqty,pInfo.stockqty));
      }
    }

    // Insert/Update GroupView
    if (!exists) {
      //check if it is available.
      if (pInfo.qtyOnList <= 0 ) {
        //NO, its not available.
        continue;
        qDebug()<<"Continue...";
      }
      // Insert into the groupView
      int rowCount = ui->groupView->rowCount();
      ui->groupView->insertRow(rowCount);
      ui->groupView->setItem(rowCount, 0, new QTableWidgetItem(QString::number(dqty)));
      ui->groupView->setItem(rowCount, 1, new QTableWidgetItem(pInfo.desc));
    } else {
      if (pInfo.qtyOnList <= 0 ) {
        //NO, its not available.
        continue;
        qDebug()<<"Continue...";
      }
      //simply update the groupView with the new qty
      for (int ri=0; ri<ui->groupView->rowCount(); ++ri)
      {
        QTableWidgetItem * item = ui->groupView->item(ri, 1);
        QString name = item->data(Qt::DisplayRole).toString();
        if (name == pInfo.desc) {
          //update
          QTableWidgetItem *itemQ = ui->groupView->item(ri, 0);//item qty
          itemQ->setData(Qt::EditRole, QVariant(pInfo.qtyOnList));
          continue;
        }
      }
    }
    // update info of the group
    groupInfo.count = groupInfo.count+dqty;
    groupInfo.cost  += pInfo.cost*dqty;  //pInfo.qtyOnList;
    groupInfo.price += pInfo.price*dqty; //pInfo.qtyOnList;
    //NOTE:group price is not affected by any product discount, it takes normal price.
    //     Discounts are taken into consideration after adding to the purchase list, when calculating taxes and price for the SO.
    bool yes = false;
    if (pInfo.stockqty >= dqty )
      yes = true;
    groupInfo.isAvailable = (groupInfo.isAvailable && yes );
    // Insert product to the group hash
    groupInfo.productsList.insert(code, pInfo);
    if (!yes) {
      //Just warning!... the insert into the view is above...
      qDebug()<<"Product is not available!";
    }
  }

  //tip
  if (!msgP.isEmpty() || !msgU.isEmpty()) {
    QString msg = "<html>";
    //first unavailable items
    if (!msgU.isEmpty()) msg = msgU.join("\n");
    //then invalid qty double/integer
    if (!msgP.isEmpty()) msg = msg + "\n" + i18n("<b>Product sold by pieces</b>, qty must be an integer value: \n%1",msgP.join("\n"));
    msg = msg+"</html>";
    groupTip->showTip(msg,7000 + incTime);
  }

  ui->groupView->resizeRowsToContents();
  ui->groupView->resizeColumnsToContents();
  ui->groupView->clearSelection();
  ui->sourcePView->clearSelection();

  //update cost and price on the form, based on group costs
  //NOTE: Base the cost on components cost
  calculateCost();
  checkFieldsState();

  qDebug()<<"There are "<<groupInfo.count<<" items in group. The cost is:"<<groupInfo.cost<<", The price is:"<<groupInfo.price<<" And is available="<<groupInfo.isAvailable;
  delete myDb;
}

void SpecialOrderEditor::removeItem()
{
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
    double qty = pInfo.qtyOnList; //from hash | must be the same on groupView
    if (qty>1) {
      qty--;
      item = ui->groupView->item(row, 0);
      item->setData(Qt::EditRole, QVariant(qty));
      pInfo.qtyOnList = qty;
      groupInfo.productsList.insert(code, pInfo);
    } else {
      //delete it from groupView, already removed from hash
      ui->groupView->removeRow(row);
    }
    // update info of the group
    if (ui->groupView->rowCount() == 0) {
      groupInfo.count = 0;
      groupInfo.cost  = 0;
      groupInfo.price = 0;
    } else {
      groupInfo.count -= 1;
      groupInfo.cost  -= pInfo.cost;
      groupInfo.price -= pInfo.price;
    }

    bool yes = false;
    if (pInfo.stockqty >= qty )
      yes = true;
    groupInfo.isAvailable = (groupInfo.isAvailable && yes );
    delete myDb;
  } //there is something selected

  //update cost and price on the form
  calculateCost();
  checkFieldsState();

  qDebug()<<"There are "<<groupInfo.count<<" items in group. The cost is:"<<groupInfo.cost<<", The price is:"<<groupInfo.price<<" And is available="<<groupInfo.isAvailable;
}

void SpecialOrderEditor::itemDoubleClicked(QTableWidgetItem* item)
{
  int row = item->row();
  QTableWidgetItem *itm = ui->groupView->item(row, 1);
  QString name = itm->data(Qt::DisplayRole).toString();
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  //get code from db
  qulonglong code = myDb->getProductCode(name);
  ProductInfo pInfo = groupInfo.productsList.take(code); //insert it later...
  double qty = pInfo.qtyOnList+1; //from hash | must be the same on groupView

  //modify pInfo
  pInfo.qtyOnList = qty; //increment it one by one
  //reinsert it to the hash
  groupInfo.productsList.insert(code, pInfo);
  //modify groupView
  itm = ui->groupView->item(row, 0);
  itm->setData(Qt::EditRole, QVariant(qty));
  // update info of the group
  groupInfo.count += 1;
  groupInfo.cost  += pInfo.cost;
  groupInfo.price += pInfo.price;
  bool yes = false;
  if (pInfo.stockqty > 0 ) //TODO:Falta checar la cantidad que se desea en elgrupo de cada producto
    yes = true;
  groupInfo.isAvailable = (groupInfo.isAvailable && yes );

  //update cost and price on the form
  calculateCost();
  checkFieldsState();

  qDebug()<<"There are "<<groupInfo.count<<" items in group. The cost is:"<<groupInfo.cost<<", The price is:"<<groupInfo.price<<" And is available="<<groupInfo.isAvailable;
  delete myDb;
}

QString SpecialOrderEditor::getGroupElementsStr()
{
  QStringList list;
  foreach(ProductInfo info, groupInfo.productsList) {
    list.append(QString::number(info.code)+"/"+QString::number(info.qtyOnList));
  }
  return list.join(",");
}

//this method is not needed because we decided not to use this as a so editor.
void SpecialOrderEditor::setGroupElements(QString e)
{
  QStringList list = e.split(",");
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  ProductInfo pInfo;
  for (int i=0; i<list.count(); ++i) {
    QStringList tmp = list.at(i).split("/");
    if (tmp.count() == 2) { //ok 2 fields
      qulonglong  code    = tmp.at(0).toULongLong();
      QString     codeStr = tmp.at(0);
      double      qty     = tmp.at(1).toDouble();
      pInfo = myDb->getProductInfo(codeStr);
      pInfo.qtyOnList = qty;

      //Insert it to the hash
      groupInfo.productsList.insert(code, pInfo);
      //update groupInfo
      groupInfo.count += qty;
      groupInfo.cost  += pInfo.cost;
      groupInfo.price += pInfo.price;
      bool yes = false;
      if (pInfo.stockqty >= qty ) yes = true;
      groupInfo.isAvailable = (groupInfo.isAvailable && yes );
      //insert it to the groupView
      int rowCount = ui->groupView->rowCount();
      ui->groupView->insertRow(rowCount);
      ui->groupView->setItem(rowCount, 0, new QTableWidgetItem(QString::number(qty)));
      ui->groupView->setItem(rowCount, 1, new QTableWidgetItem(pInfo.desc));
    }
  }
  ui->groupView->resizeRowsToContents();
  ui->groupView->resizeColumnsToContents();
  calculateCost();
  delete myDb;
}

QString SpecialOrderEditor::getContentNames()
{
  QStringList list;
  foreach(ProductInfo info, groupInfo.productsList) {
    QString unitStr;
    if (info.units == 1 ) unitStr=""; else unitStr = info.unitStr;
    list.append("  "+QString::number(info.qtyOnList)+" "+unitStr+" "+ info.desc);
  }
  //append NOTES for the SO.
  list.append("\n"+i18n("Notes: %1", getNotes()+" \n"));
  return list.join("\n");
}

void SpecialOrderEditor::checkDate(QDateTime dt)
{
  if (dt.date() </*=*/ QDate::currentDate()) { //allow also deliver for today. Requested by Jnivar. TODO: We could use a config option for this.
    ui->deliveryDT->setDateTime(QDateTime::currentDateTime()/*.addDays(1)*/);
    ui->deliveryDT->hide();
    ui->lblDateError->setText(i18n("<html><font color=red><b>The delivery date is in the past.</b></font></html>"));
    ui->lblDateError->show();
    QTimer::singleShot(3000,this, SLOT(hideError()));
  }
}

void SpecialOrderEditor::hideError()
{
  ui->deliveryDT->show();
  ui->lblDateError->setText("");
  ui->lblDateError->hide();
}

void SpecialOrderEditor::populateUsersCombo()
{
  QSqlQuery query(db);
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  ui->usersCombo->clear();
  ui->usersCombo->addItems(myDb->getUsersList());
  delete myDb;
}

void SpecialOrderEditor::populateClientsCombo()
{
  QSqlQuery query(db);
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  ui->clientsCombo->clear();
  ui->clientsCombo->addItems(myDb->getClientsList());
  delete myDb;
}

qulonglong SpecialOrderEditor::getClientId()
{
  QSqlQuery query(db);
  int code=-1;
  QString currentText = ui->clientsCombo->currentText();
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  code = myDb->getClientId(currentText);
  delete myDb;
  return code;
}

qulonglong SpecialOrderEditor::getUserId()
{
  QSqlQuery query(db);
  int code=-1;
  QString currentText = ui->usersCombo->currentText();
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  code = myDb->getUserIdFromName(currentText);
  delete myDb;
  return code;
}

QString SpecialOrderEditor::getDescription()
{
  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  
  ClientInfo info = myDb->getClientInfo(getClientId());
  QStringList phones; phones << info.phone << info.cell;
  delete myDb;
  return ui->clientsCombo->currentText() + "  [ " +phones.join(", ")+" ]";
}

void SpecialOrderEditor::createClient()
{
  //check fields first...
  bool ready = false;
  if ( !ui->editClientName->text().isEmpty()     &&
       !ui->editClientAddress->toPlainText().isEmpty()
     ) ready = true;
  if (ui->editClientPhone->text().isEmpty() && ui->editClientCell->text().isEmpty())
    ready = ready && false; //only one can be empty..
  else
    ready = ready && true;

  if (ready) {
    ClientInfo info;
    info.name    = ui->editClientName->text();
    info.address = ui->editClientAddress->toPlainText();
    info.phone   = ui->editClientPhone->text();
    info.cell    = ui->editClientCell->text();
    info.points  = 0;
    info.discount= 0;
    info.since   = QDate::currentDate();
    info.photo   = "";

    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);
    myDb->insertClient(info);
    populateClientsCombo();
    int index = ui->clientsCombo->findText(info.name,Qt::MatchCaseSensitive);
    if (index > -1)
      ui->clientsCombo->setCurrentIndex(index);

    newClientPanel->hidePanel();
    delete myDb;
  }
}

void SpecialOrderEditor::checkValidInfo()
{
  bool ready = false;
  if ( !ui->editClientName->text().isEmpty()     &&
    !ui->editClientAddress->toPlainText().isEmpty()
    ) ready = true;
  if (ui->editClientPhone->text().isEmpty() && ui->editClientCell->text().isEmpty())
    ready = ready && false; //only one can be empty..
    else
      ready = ready && true;

  ui->btnClientAdd->setEnabled(ready);
}

void SpecialOrderEditor::enableCreateClient()
{
  ui->btnClientAdd->setEnabled(false);
}

void SpecialOrderEditor::setUsername(QString username)
{
  int index = ui->usersCombo->findText(username,Qt::MatchCaseSensitive);
  if (index > -1)
    ui->usersCombo->setCurrentIndex(index);
  
}

///Use this function after assign the DB!
void SpecialOrderEditor::setClientName(QString name)
{
  if (ui->clientsCombo->count() < 1) populateClientsCombo(); //just in case!
  int index = ui->clientsCombo->findText(name,Qt::MatchCaseSensitive);
  if (index > -1)
    ui->clientsCombo->setCurrentIndex(index);
  else qDebug()<<"CLIENT:"<<name<< "not found.";
}


//NOTE:this seems to be SLOW!
void SpecialOrderEditor::updateNoteLength()
{
  int i = ui->editNotes->toPlainText().length();
  ui->lblNoteL->setText(i18n("%1 chars of %2 allowed.", i, 800));
  if (i > 800) {
    ui->editNotes->setText(ui->editNotes->toPlainText().left(800));
    ui->editNotes->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
  }
}

#include "specialordereditor.moc"
