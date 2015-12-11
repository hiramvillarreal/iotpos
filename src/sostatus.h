/***************************************************************************
 *   Copyright (C) 2009-2010 by Miguel Chavez Gamboa                       *
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
#ifndef SOSTATUS_H
#define SOSTATUS_H

#include <KDialog>
#include <QDate>
#include <QtGui>
#include <QPixmap>
#include <QtSql>

#include "ui_sostatus.h"
#include "../../src/structs.h"

class MibitTip;
class QDateTime;

class SOStatusUI : public QFrame, public Ui::soStatus
{
  Q_OBJECT
  public:
    SOStatusUI( QWidget *parent=0);
};

class SOStatus : public KDialog
{
  Q_OBJECT
  public:
    SOStatus( QWidget *parent=0 );
    ~SOStatus();

    void        setDb(QSqlDatabase database);
    qulonglong  getSelectedTicket() { return ticketNumber; }
    int         getStatusId();

  private slots:
    void    applyFilter();
    void    itemClicked(const QModelIndex &index);
    void    setupModel();
    void    selectItem();
    void    populateStatusCombo();
  protected slots:
    virtual void slotButtonClicked(int button);
  private:
    SOStatusUI *ui;
    QSqlDatabase db;
    bool m_modelAssigned;
    QSqlRelationalTableModel *soModel;
    qulonglong ticketNumber;
};

#endif
