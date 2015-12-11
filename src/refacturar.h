/***************************************************************************
 *   Copyright (C) 2012 by Miguel Chavez Gamboa                            *
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
#ifndef REFACTURAR_H
#define REFACTURAR_H

#include <KDialog>
#include <QtGui>
#include <QPixmap>
#include <QtSql>

#include "ui_refacturar.h"
#include "../../src/structs.h"

class MibitTip;
class QDateTime;
class QTime;
class QDate;

class RefacturarDialogUI : public QFrame, public Ui::refacturarDialog
{
  Q_OBJECT
  public:
    RefacturarDialogUI( QWidget *parent=0);
};

class RefacturarDialog : public KDialog
{
  Q_OBJECT
  public:
    RefacturarDialog( QWidget *parent=0 );
    ~RefacturarDialog();

    void        setDb(QSqlDatabase database);
    QString     getSelectedInvoice() { return inNumber; }

  private slots:
    void    itemClicked(const QModelIndex &index);
    void    item_Clicked(const QModelIndex &index, const QModelIndex &indexp);
    void    setupModel();
    void    selectItem();
  protected slots:
    virtual void slotButtonClicked(int button);
  private:
    RefacturarDialogUI *ui;
    QSqlDatabase db;
    bool m_modelAssigned;
    QSqlTableModel *inModel;
    QString inNumber;
};

#endif
