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
#ifndef PROMOEDITOR_H
#define PROMOEDITOR_H

#include <KDialog>
#include <QDate>
#include <QtGui>
#include <QtSql>
#include "ui_editpromo_widget.h"

class PromoEditorUI : public QFrame, public Ui::promoEditor
{
  Q_OBJECT
  public:
    PromoEditorUI( QWidget *parent=0 );
};

class PromoEditor : public KDialog
{
  Q_OBJECT
  public:
    PromoEditor( QWidget *parent=0 );
    ~PromoEditor();

    QDate   getDateStart()   { return ui->offersDatepickerStart->date(); };
    QDate   getDateEnd()     { return ui->offersDatepickerEnd->date(); };
    double  getDiscount()    { return ui->spinboxDiscount->value(); };
    void    setDb(QSqlDatabase database);
    void    populateCategoriesCombo();
    void    setupModel();
    bool    isProductSelected();
    qulonglong getSelectedProductCode();

  private slots:
    void    checkValid();
    void    setFilter();
    void    productChanged();
    void    discountChanged();
    void    priceChanged();

  private:
    PromoEditorUI *ui;
    QSqlDatabase db;
    QSqlRelationalTableModel *model;
};

#endif
