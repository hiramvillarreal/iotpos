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

#include <QByteArray>
#include <QPixmap>

#include <kstandarddirs.h>
#include "settings.h"

#include "pricechecker.h"
#include "structs.h"
#include "../dataAccess/azahar.h"

PriceCheckerUI::PriceCheckerUI( QWidget *parent )
: QFrame( parent )
{
  setupUi( this );
}


PriceChecker::PriceChecker( QWidget *parent )
: KDialog( parent )
{
  setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
  ui = new PriceCheckerUI( this );
  setMainWidget( ui );
  setCaption( i18n("Price Checker") );
  setButtons( KDialog::NoDefault );
  ui->titleTop->setText(i18nc("Price-Checker dialog", "Price")); //FIXME: translation problems!!!!!!
  ui->titleBottom->setText(i18nc("Price-Checker dialog", "Checker")); //FIXME: translation problems!!!!!!
  ui->labelPCCode->setText(i18n("&Code:"));
  ui->labelPCClose->setText(i18n("Press ESC to Close"));
  ui->labelPClPrice->setText(i18n("Regular price:"));
  ui->labelPClTotal->setText(i18n("Final price:"));
  ui->labelPClDiscount->setText(i18n("Discount:"));
  QString path = KStandardDirs::locate("appdata", "styles/");
  QPixmap pix = QPixmap(path + Settings::styleName() + "/priceCheckerBack.png");
  resize(517,309);
  setMask( pix.mask() );
  pix = QPixmap(path + Settings::styleName() + "/pricechecker.png");
  ui->titleImg->setPixmap(pix);

  //connect( ui->editCode, SIGNAL(textEdited(const QString &)),this, SLOT(checkIt()) );
  //NOTE: There are some issues when having the 'textEdited' signal connected to ckeckIt(),
  //      When you want to use the barcode reader, it sends an enter and then the code is ready to be searched.
  //      Then if you want to read another code to search, the edit line is not cleared. it makes difficult to use it.
  //      So we need to execute the query when the 'enter' event is rised and clean the code input line to let it ready for another search.
  //      With textEdited the code is searched every single number is entered (when not using barcode reader)
  //      causing many database queries to be executed.
  connect( ui->editCode, SIGNAL(returnPressed()),this, SLOT(checkIt()) );
  
  QRegExp regexpC("[0-9]{1,13}");
  QRegExpValidator * validator = new QRegExpValidator(regexpC, this);
  ui->editCode->setValidator(validator);

  ui->editCode->setFocus();

  myDb = new Azahar;
}

void PriceChecker::paintEvent(QPaintEvent* event){
  QDialog::paintEvent(event);
  QPainter painter(this);
  painter.setClipRegion(event->region());
  QString path = KStandardDirs::locate("appdata", "styles/");
  QPixmap bg = QPixmap(path + Settings::styleName() + "/priceCheckerBack.png");
  painter.drawPixmap(QPoint(0,0), bg);
}

PriceChecker::~PriceChecker()
{
  delete myDb;
}

void PriceChecker::checkIt()
{
  ProductInfo info = myDb->getProductInfo(ui->editCode->text());
  ui->labelPCName->setText(info.desc);
  ui->labelPCPrice->setText(KGlobal::locale()->formatMoney(info.price));
  if (info.validDiscount) ui->labelPCDiscount->setText(KGlobal::locale()->formatMoney(-info.disc));
  else ui->labelPCDiscount->setText(KGlobal::locale()->formatMoney(0.0));
  double total = info.price;
  if (info.validDiscount) total = info.price - info.disc;
  ui->labelPCTotal->setText(KGlobal::locale()->formatMoney(total));
  QPixmap pix;
  pix.loadFromData(info.photo);
  ui->labelPhoto->setPixmap(pix);

  //clear the code at the editline.
  ui->editCode->clear();
}

void PriceChecker::setDb(QSqlDatabase database)
{
  myDb->setDatabase(database);
}


#include "pricechecker.moc"
