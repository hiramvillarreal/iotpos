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

#include "inputdialog.h"
#include "settings.h"

#include <QtGui>
#include <kiconloader.h>
#include <klocale.h>
#include <QPixmap>
#include <kstandarddirs.h>

InputDialog::InputDialog(QWidget *parent, bool integer, DialogType type, QString msg, double min, double max)
{
  dialogType = type;
  _max = max;
  _min = min;
  setParent(parent);
  setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
  setWindowModality(Qt::ApplicationModal);
  setModal(true);

  vLayout       = new QVBoxLayout(this);
  titleLayout   = new QHBoxLayout();
  gridLayout    = new QGridLayout();
  lPixmap       = new QLabel(this);

  // Icons for each type
  if (type == dialogMeasures) lPixmap->setPixmap(DesktopIcon("kruler", 48));
  else if (type == dialogMoney) lPixmap->setPixmap(DesktopIcon("lemon-money", 48));
  else if (type==dialogCashOut) lPixmap->setPixmap(DesktopIcon("lemon-cashout", 48));
  else if (type == dialogTicket) lPixmap->setPixmap(DesktopIcon("lemon-ticket-cancel", 48));
  else if (type == dialogSpecialOrder) lPixmap->setPixmap(DesktopIcon("lemon-ticket", 48));
  else if (type == dialogStockCorrection) lPixmap->setPixmap(DesktopIcon("squeeze-stock-correction", 48));
  else if (type == dialogTerminalNum) lPixmap->setPixmap(DesktopIcon("lemon-money", 48)); //FIXME: add an icon
  else if (type == dialogTicketMsg)   lPixmap->setPixmap(DesktopIcon("lemon-ticket", 48));
  else if (type == dialogCurrency) lPixmap->setPixmap(DesktopIcon("lemon-money", 48));


  //labels
  titleLayout->addWidget(lPixmap);
  label = new QLabel(msg, this);
  label->setWordWrap(true);
  titleLayout->addWidget(label);
  QSpacerItem *spacerItem2 = new QSpacerItem(50, 50, QSizePolicy::Minimum, QSizePolicy::Maximum);
  vLayout->addLayout(titleLayout);
  vLayout->addItem(spacerItem2);
  productCodeEdit = new KLineEdit(this);
  reasonEdit = new KLineEdit(this);
  lineEdit = new KLineEdit(this);
  productCodeLabel = new QLabel(i18n("Product Code:"), this);

  ///TODO: fix this mess! the if for the dialogtype to assign labels
  
  //switch (type) {
  //    case dialogTicketMsg:
  //        break;
  //    case dialogStockCorrection:
  //        break;
  //    case 
  //}
  
  if (type == dialogTicketMsg) qLabel = new QLabel(i18n("Month or Season:"));
  else if (type == dialogStockCorrection) qLabel = new QLabel(i18n("New Stock Qty:"));
  else if (type == dialogCurrency) qLabel = new QLabel(i18n("New currency factor:"));
  else qLabel = new QLabel(i18n("Amount:"));

  if (type == dialogTicketMsg) reasonLabel = new QLabel(i18n("New Message:"), this);
  else if (type == dialogCurrency) reasonLabel = new QLabel(i18n("New Currency Name:"), this);
  else reasonLabel = new QLabel(i18n("Reason:"), this);

  if (type == dialogTicket || type == dialogSpecialOrder) qLabel->setText(i18n("Ticket #:"));


  //layout
  gridLayout->addWidget(productCodeLabel, 0,0,0);//1,1);
  gridLayout->addWidget(productCodeEdit, 0,1,0);//1,1);
  gridLayout->addWidget(reasonLabel, 1,0,0);//1,1);
  gridLayout->addWidget(reasonEdit, 1,1,0);//1,1);
  gridLayout->addWidget(qLabel, 2,0,0);//1,1);
  gridLayout->addWidget(lineEdit, 2,1,0);//1,1);
  vLayout->addLayout(gridLayout);

 if (type == dialogCashOut) {
    lineEdit->setClickMessage(i18n("valid amount between %1 and %2", min,max));
    reasonLabel->show();
    reasonEdit->show();
    productCodeEdit->hide();
    productCodeLabel->hide();
  }
  else if (type == dialogStockCorrection ) {
    productCodeEdit->setClickMessage(i18n("Enter the product code here..."));
    lineEdit->setClickMessage(i18n("Enter the new stock quantity here..."));
    productCodeEdit->show();
    productCodeLabel->show();
    reasonLabel->show();
    reasonEdit->show();
  }
  else if (type == dialogTerminalNum) {
   qLabel->setText(i18n("Terminal Number:"));
   lineEdit->setClickMessage(i18n("Enter the terminal number here..."));
   productCodeEdit->hide();
   productCodeLabel->hide();
   reasonLabel->hide();
   reasonEdit->hide();
  }
  else if (type == dialogTicketMsg) {
   lineEdit->setClickMessage(i18n("Enter the number of the month or season here..."));
   qDebug()<<"Setting month validator: min:"<<min<<" Max:"<<max;
   productCodeEdit->hide();
   productCodeLabel->hide();
  }
  else if (type == dialogCurrency ) {
      reasonEdit->setClickMessage(i18n("Enter the new currency name..."));
      lineEdit->setClickMessage(i18n("Enter the new currency factor..."));
      productCodeEdit->hide();
      productCodeLabel->hide();
      reasonLabel->show();
      reasonEdit->show();
  }
  else {
    reasonLabel->hide();
    reasonEdit->hide();
    productCodeEdit->hide();
    productCodeLabel->hide();
  }

  //qDebug()<<"Min:"<<min<<"Max:"<<max;
  if (integer) {
    int imin=min; int imax=0;
    if (max>2147483640) imax=2147483647; else imax=max; //max positive value for INT
    //qulonglong imax=max;
    //qDebug()<<"Min:"<<imin<<"Max:"<<imax;
    //FIXME: El valor pasado a max es un DOUBLE, y es mas chico que qulonglong. en mi compu ambos son de 8 bytes.
    //qDebug()<<"Size of qulonglong is "<<sizeof(qulonglong);
    //qDebug()<<"Size of a double is   "<<sizeof(double);
    //NOTE: Nov 21 2009. Returned value is a qulonglong, so integer validator is not good!
    QIntValidator *validator = new QIntValidator(imin, imax,this);
    lineEdit->setValidator(validator);
    //qintvalidator range is in int (not qlonglong)
    // I NEED TO MAKE VALIDATION WITH REGULAR EXPRESSIONS TO SUPPORT LARGE NUMBERS if we need to do so.. ticket numbers larger
    // than 2,147,483,647. For now, its ok, its at the order of billions (thousand millions).
  } else {
    //Some people complained about decimal places in numbers accepted by lemon. They wanted more decimal places!!!
    QDoubleValidator *validator;
    if (dialogType == dialogStockCorrection) {
        validator = new QDoubleValidator(-99999999.9, max, 5,this);
        qDebug()<<" Validator:"<<validator;
    } else {
        validator = new QDoubleValidator(min, max, 5,this);
    }
    lineEdit->setValidator(validator);
  }
  //NOTE: We remove the xX from the regexp for use as the separator between qtys and code. Only * can be used now, for Alphacode support
  QRegExp regexpC("[1-9]+[0-9]*[//.]{0,1}[0-9]{0,2}[*]{0,1}[0-9]{0,13}");
  QRegExpValidator * validatorEAN13 = new QRegExpValidator(regexpC, this);
  productCodeEdit->setValidator(validatorEAN13);

  
  buttonsLayout = new QHBoxLayout();
  buttonAccept = new QPushButton(this);
  buttonAccept->setText(i18n("Ok"));
  buttonAccept->setDefault( true );
  buttonCancel = new QPushButton(this);
  buttonCancel->setText(i18n("Cancel"));
  buttonCancel->setShortcut(Qt::Key_Escape);
  buttonsLayout->addWidget(buttonCancel);
  buttonsLayout->addWidget(buttonAccept);
  if (type == dialogStockCorrection ) {
    buttonAccept->hide();
    buttonCancel->hide();
  }

  //QSpacerItem *spacerItem3 = new QSpacerItem(70, 70, QSizePolicy::Minimum, QSizePolicy::Maximum);
  //buttonsLayout->addItem(spacerItem3);
  vLayout->addLayout(buttonsLayout);

  buttonAccept->setMaximumSize(QSize(130, 27));
  buttonCancel->setMaximumSize(QSize(130, 27));
  lineEdit->setMaximumSize(QSize(260, 27));
  reasonEdit->setMaximumSize(QSize(260, 27));
  productCodeEdit->setMaximumSize(QSize(260, 27));
  
  iValue = 0;
  dValue = 0.0;
  reason = "";

  label->setObjectName("titleLabelInputDialog");

  //style
  //QRect geom = geometry();
  //qDebug()<<"Geometry before resize:"<<geom;
  resize(362,158);
  //geom = geometry();
  //qDebug()<<"Geometry after resize:"<<geom;
  QString path = KStandardDirs::locate("appdata", "styles/");
  QPixmap pixm = QPixmap(path + Settings::styleName() + "/dialog.png");
  setMask( pixm.mask() );
  
  connect(lineEdit, SIGNAL(returnPressed()), this, SLOT(acceptIt()));
  connect(reasonEdit, SIGNAL(returnPressed()), this, SLOT(acceptIt()));
  connect(buttonAccept, SIGNAL(clicked()), this, SLOT(acceptIt()));
  connect(buttonCancel, SIGNAL(clicked()), this, SLOT(reject()));
  connect(productCodeEdit, SIGNAL(returnPressed()), this, SLOT(acceptIt()));
}

void InputDialog::paint(QPainter *)
{}

/* This is a workaround for the login/password dialog background.
* Simply draw the pixmap, instead the style painting.
*/
void InputDialog::paintEvent(QPaintEvent *e)
{
  QDialog::paintEvent(e);
  QPainter painter(this);
  painter.setClipRegion(e->region());
  
  QString path = KStandardDirs::locate("appdata", "styles/");
  QPixmap bg = QPixmap(path + Settings::styleName() + "/dialog.png");
  painter.drawPixmap(QPoint(0,0), bg);
}

void InputDialog::acceptIt()
{
  //set values even if not accepted...
  dValue = lineEdit->text().toDouble();
  iValue = lineEdit->text().toULongLong();
  reason = reasonEdit->text();

  ///Check dialog type for cases to valid

  if (dialogType == dialogStockCorrection) { //needs 3 fields
    if (lineEdit->hasAcceptableInput() && !reasonEdit->text().isEmpty() && !productCodeEdit->text().isEmpty() )
      QDialog::accept();
  }
  else if (dialogType == dialogCashOut) { //needs 2 fields : amount & reason
    if (lineEdit->hasAcceptableInput() && !reasonEdit->text().isEmpty()) {
      QDialog::accept();
    }
    else {
      //Not accepted by some of the two reasons
      if (!lineEdit->text().isEmpty() || lineEdit->hasAcceptableInput()) { //it contains something invalid
        if (lineEdit->text().toDouble() >= _max) {
          lineEdit->setText(QString::number(_max));
          lineEdit->selectAll();
        }
      }
    }
  }
  else if (dialogType == dialogTicketMsg) {
    if (lineEdit->hasAcceptableInput() && !reasonEdit->text().isEmpty()) {
      //The user is responsible for the correct month/season number... depending on what is based.
      QDialog::accept();
    }
  }
  else { //Money-Measures-Ticket-TerminalNum needs only the amount/terminalNum...
    if (lineEdit->hasAcceptableInput())
      QDialog::accept();
  }
}

void InputDialog::setProductCode(qulonglong theCode)
{
  productCodeEdit->setText(QString::number(theCode));
}

void InputDialog::setAmount(double damnt)
{
  lineEdit->setText(QString::number(damnt));
}

void InputDialog::setAmount(int iamnt)
{
  lineEdit->setText(QString::number(iamnt));
}

void InputDialog::setProductCodeReadOnly()
{
  productCodeEdit->setReadOnly(true);
  reasonEdit->setFocus();
}

#include "inputdialog.moc"

