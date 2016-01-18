/***************************************************************************
 *   Copyright (C) 2007-2007-2009 by Miguel Chavez Gamboa                       *
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
#define QT_GUI_LIB

#include <QtGui>
#include <QDate>
#include <QSqlRelationalDelegate>
#include "offersdelegate.h"

OffersDelegate::OffersDelegate(QObject *parent) : QSqlRelationalDelegate(parent)
{
}

void OffersDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  QStyleOptionViewItemV3 opt = option;
  if (index.column() == 1) { //Alineamos al centro el descuento...
    opt.displayAlignment = Qt::AlignCenter; //modificamos las opciones... de alieado.
    const QAbstractItemModel *model = index.model();
    QPalette::ColorGroup cg = opt.state & QStyle::State_Enabled ? QPalette::Normal : QPalette::Disabled;
    if (opt.state & QStyle::State_Selected)
      painter->fillRect(opt.rect, opt.palette.color(cg, QPalette::Highlight));
    double amount = model->data(index, Qt::DisplayRole).toDouble();
    int boxH = opt.rect.height() -10;
    int boxW = opt.rect.width() -5;
    int boxX = opt.rect.x();
    int boxY = opt.rect.y();
    int apintar = amount*(boxW/100); //porcentaje del cuadro a pintar que le corresponde al descuento.
    painter->setBrush(Qt::lightGray);
    painter->setPen(Qt::darkGray);
    painter->drawRect(boxX+15,boxY+5,apintar,boxH);
    if (opt.state & QStyle::State_Selected) painter->setPen(Qt::white);
    else painter->setPen(Qt::black);
    painter->setFont(QFont("Times", 9, QFont::Bold));
    painter->drawText(boxX-8+boxW/2,boxY+19,QString("%1 %").arg(amount));
  } else
  QSqlRelationalDelegate::paint(painter, opt, index);
}

QWidget *OffersDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  if (index.column() == 4 ) return QSqlRelationalDelegate::createEditor(parent, option, index);
  else {
    QWidget *editor = NULL;
    QDoubleSpinBox *dSpinbox = new QDoubleSpinBox(parent);
    QDateEdit      *dateEdit = new QDateEdit(parent);
    switch(index.column())
    {
      case 1: //discount
        editor = dSpinbox;
        dSpinbox->setMinimum(0);
        dSpinbox->setMaximum(99.99);
        dSpinbox->setSuffix(" %");
        break;
      case 2: //date
        editor  = dateEdit;
        break;
      case 3: //date
        editor  = dateEdit;
        break;
      default : //Never must be here...
        break;
    }
    return editor;
  }
}

#include "offersdelegate.moc"
