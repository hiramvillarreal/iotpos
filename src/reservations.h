/***************************************************************************
 *   Copyright (C) 2010 by Miguel Chavez Gamboa                            *
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
#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include <KDialog>
#include <QDate>
#include <QtGui>
#include <QPixmap>
#include <QtSql>

#include "ui_reservations.h"
#include "../../src/structs.h"
#include "../../src/enums.h"
#include "gaveta.h"

class QDateTime;
class QTime;
class QDate;
class MibitFloatPanel;

class ReservationsDialogUI : public QFrame, public Ui::reservationsDialog
{
  Q_OBJECT
  public:
    ReservationsDialogUI( QWidget *parent=0);
};

class ReservationsDialog : public KDialog
{
  Q_OBJECT
  public:
    ReservationsDialog( QWidget *parent=0 , Gaveta *theDrawer=0, int userid=0);
    ~ReservationsDialog();

    void        setDb(QSqlDatabase database);
    qulonglong  getSelectedTransaction() { return trNumber; }
    qulonglong  getSelectedReservation() { return rNumber;  }
    qulonglong  getSelectedClient()      { return clientId; }
    QDate       getTrDate()              { return trDate;   }
    double      getReservationPayment()  { return rPayment; }
    double      getReservationProfit()   { return rProfit; }
    QList<ProductInfo> getProductsList() { return pList;    }
    QString     getItemDiscounts()       { return item_discounts; }

  private slots:
    void    itemClicked(const QModelIndex &index);
    void    item_Clicked(const QModelIndex &index, const QModelIndex &indexp);
    void    setupModel();
    void    selectItem();
    void    cancelReservation();
  protected slots:
    virtual void slotButtonClicked(int button);
  private:
    ReservationsDialogUI *ui;
    QSqlDatabase db;
    bool m_modelAssigned;
    QSqlRelationalTableModel *trModel;
    qulonglong trNumber;
    qulonglong rNumber;
    qulonglong clientId;
    double     rPayment;
    QDate      trDate;
    QTime      trTime;
    QList<ProductInfo> pList;
    MibitFloatPanel *panel;
    Gaveta *drawer;
    int userId;
    QString item_discounts;
    double rProfit;
};

#endif
