/***************************************************************************
 *   Copyright (C) 2007-2009 by Miguel Chavez Gamboa                  *
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

#include <QtGui>
#include <QtSql>
#include <QMouseEvent>
#include <QPaintEvent>
#include <klocale.h>
#include <kstandarddirs.h>
#include <kiconloader.h>

#include "productdelegate.h"

void ProductDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    //painting background when selected...
    //QPalette::ColorGroup cg = option.state & QStyle::State_Enabled
    //    ? QPalette::Normal : QPalette::Disabled;

    //Painting frame
    painter->setRenderHint(QPainter::Antialiasing);
    QString pixName;
    if (option.state & QStyle::State_Selected) 
      pixName = KStandardDirs::locate("appdata", "images/itemBox_selected.png");
    else
      pixName = KStandardDirs::locate("appdata", "images/itemBox.png");
    
    painter->drawPixmap(option.rect.x()+5,option.rect.y()+5, QPixmap(pixName));

    //get item data
    const QAbstractItemModel *model = index.model();
    int row = index.row();
    QModelIndex nameIndex = model->index(row, 1);
    QString name = model->data(nameIndex, Qt::DisplayRole).toString();
    QByteArray pixData = model->data(index, Qt::DisplayRole).toByteArray();
    nameIndex = model->index(row, 3); //model->fieldIndex("stockqty")
    double stockqty = model->data(nameIndex, Qt::DisplayRole).toDouble();
    nameIndex = model->index(row, 0);
    QString strCode = "# " + model->data(nameIndex, Qt::DisplayRole).toString();
    //TODO: Add alphacode too
    nameIndex = model->index(row, 19);
    bool isGroup = model->data(nameIndex, Qt::DisplayRole).toBool();
    nameIndex  = model->index(row, 18);
    bool isRaw = model->data(nameIndex, Qt::DisplayRole).toBool();
    nameIndex  = model->index(row, 23);
    bool hasUnlimitedStock = model->data(nameIndex, Qt::DisplayRole).toBool();
    nameIndex  = model->index(row, 24);
    bool nonDiscountItem = model->data(nameIndex, Qt::DisplayRole).toBool();

    //preparing photo to paint it...
    QPixmap pix;
    if (!pixData.isEmpty() or !pixData.isNull()) {
      pix.loadFromData(pixData);
    }
    else {
      pix = QPixmap(DesktopIcon("lemon-box", 64));
    }
    int max = 128;
    if ((pix.height() > max) || (pix.width() > max) ) {
      if (pix.height() == pix.width()) {
        pix = pix.scaled(QSize(max, max));
      }
      else if (pix.height() > pix.width() ) {
        pix = pix.scaledToHeight(max);
      }
      else  {
        pix = pix.scaledToWidth(max);
      }
    }
    int x = option.rect.x() + (option.rect.width()/2) - (pix.width()/2);
    int y = option.rect.y() + (option.rect.height()/2) - (pix.height()/2) - 10;
    //painting photo
    if (!pix.isNull()) painter->drawPixmap(x,y, pix);

    //Painting name
    QFont font = QFont("Trebuchet MS", 10);
    font.setBold(true);
    //getting name size in pixels...
    QFontMetrics fm(font);
    int strSize = fm.width(name);
    int aproxPerChar = fm.width("A");
    QString nameToDisplay = name;
    int boxSize = option.rect.width()-15; //minus margin and frame-lines
    if (strSize > boxSize) {
      int excess = strSize-boxSize;
      int charEx = (excess/aproxPerChar)+4;
      nameToDisplay = name.left(name.length()-charEx-7) +"...";
      //qDebug()<<"Text does not fit, strSize="<<strSize<<" boxSize:"
      //<<boxSize<<" excess="<<excess<<" charEx="<<charEx<<"nameToDisplay="<<nameToDisplay;
    }
    painter->setFont(font);
    if (option.state & QStyle::State_Selected) {
      painter->setPen(Qt::yellow);
      painter->drawText(option.rect.x()+10,option.rect.y()+138, 150,20,  Qt::AlignCenter, nameToDisplay);
    }
    else {
      painter->setPen(Qt::white);
      painter->drawText(option.rect.x()+10,option.rect.y()+138, 150,20,  Qt::AlignCenter, nameToDisplay);
    }

    //painting stock Availability
    if (stockqty <= 0 || hasUnlimitedStock) {
      QString naStr;
      if (hasUnlimitedStock)
        naStr = i18n("Unlimited Stock");
      else
        naStr = i18n(" Out of stock ");
      font = QFont("Trebuchet MS", 12);
      font.setBold(true);
      font.setItalic(true);
      painter->setFont(font);
      painter->setBackgroundMode(Qt::OpaqueMode);
      painter->setPen(Qt::red);
      painter->setBackground(QColor(255,180,0,160));
      painter->drawText(option.rect.x()+10,
                      option.rect.y()+(option.rect.height()/2)-10,
                      150, 20, Qt::AlignCenter, naStr);
      painter->setBackgroundMode(Qt::TransparentMode);
    }
    
    //painting code number
    font = QFont("Trebuchet MS", 9);
    font.setBold(false);
    font.setItalic(true);
    painter->setFont(font);
    painter->setBackgroundMode(Qt::TransparentMode);
    painter->setPen(Qt::darkGray);
    painter->setBackground(QColor(255,225,0,160));
    painter->drawText(option.rect.x()+10,
                      option.rect.y()+10,
                      150, 20, Qt::AlignCenter, strCode);
    painter->setBackgroundMode(Qt::TransparentMode);

    //painting things like isARawProduct and isAGroup
    //TODO: Paint an icon instead of text!
    if (isRaw) {
      font = QFont("Trebuchet MS", 9);
      font.setBold(true);
      font.setItalic(false);
      painter->setFont(font);
      painter->setBackgroundMode(Qt::OpaqueMode);
      painter->setPen(Qt::blue);
      painter->setBackground(QColor(255,180,0,160));
      QString naStr = i18n(" Raw Product ");
      painter->drawText(option.rect.x()+10,
                        option.rect.y()+22,
                        150, 20, Qt::AlignCenter, naStr);
                        painter->setBackgroundMode(Qt::TransparentMode);
    } 
    if (isGroup) {
      //load pixmap
      pix = QPixmap(DesktopIcon("lemon-groups", 32));
      painter->drawPixmap(option.rect.x()+10,
                        option.rect.y()+20,
                        /*150, 20, */ pix /*Qt::AlignCenter, naStr*/);
                        painter->setBackgroundMode(Qt::TransparentMode);
    }
    if (nonDiscountItem) {
      //load pixmap
      pix = QPixmap(DesktopIcon("lemon-nondiscount", 32));
      painter->drawPixmap(option.rect.x()+10,
                        option.rect.y()+20,
                        /*150, 20, */ pix /*Qt::AlignCenter, naStr*/);
                        painter->setBackgroundMode(Qt::TransparentMode);
    }
}


QSize ProductDelegate::sizeHint(const QStyleOptionViewItem &optionUnused,
                             const QModelIndex &indexUnused) const
{
  return QSize(170,170);
}

#include "productdelegate.moc"
