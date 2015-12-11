/***************************************************************************
 *   Copyright (C) 2009-2010 by Miguel Chavez Gamboa                       *
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
#ifndef SOSELECTOR_H
#define SOSELECTOR_H

#include <KDialog>
#include <QDate>
#include <QtGui>
#include <QPixmap>
#include <QtSql>

#include "ui_soselector.h"
#include "../../src/structs.h"

class MibitTip;
class QDateTime;

class SOSelectorUI : public QFrame, public Ui::soSelector
{
  Q_OBJECT
  public:
    SOSelectorUI( QWidget *parent=0);
};

class SOSelector : public KDialog
{
  Q_OBJECT
  public:
    SOSelector( QWidget *parent=0 );
    ~SOSelector();

    void              setDb(QSqlDatabase database);
    qulonglong  getSelectedTicket() { return ticketNumber; }

  private slots:
    void    applyFilter();
    void    itemClicked(const QModelIndex &index);
    void    setupModel();
    void    selectItem();
  protected slots:
    virtual void slotButtonClicked(int button);
  private:
    SOSelectorUI *ui;
    QSqlDatabase db;
    bool m_modelAssigned;
    QSqlRelationalTableModel *soModel;
    //SpecialOrderInfo selectedSO;
    qulonglong ticketNumber;
};

#endif
