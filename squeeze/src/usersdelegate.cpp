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

#include <QtGui>
#include <QtSql>
#include <QMouseEvent>
#include <QPaintEvent>
#include <klocale.h>
#include <kstandarddirs.h>
#include <kiconloader.h>

#include "usersdelegate.h"

void UsersDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
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

    //preparing photo to paint it...
    QPixmap pix;
    if (!pixData.isEmpty() or !pixData.isNull()) {
      pix.loadFromData(pixData);
    }
    else {
      //null pixmap, draw a default one...
     pix = QPixmap(DesktopIcon("lemon-user", 128));
    }
    //Draw pixmap
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
      int charEx = (excess/aproxPerChar)+2;
      nameToDisplay = name.left(name.length()-charEx-5) +"...";
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

}


QSize UsersDelegate::sizeHint(const QStyleOptionViewItem &optionUnused,
                             const QModelIndex &indexUnused) const
{
  return QSize(170,170);
}

#include "usersdelegate.moc"
