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
#ifndef RESUME_H
#define RESUME_H

#include <KDialog>
#include <QDate>
#include <QtGui>
#include <QPixmap>
#include <QtSql>

#include "ui_resume.h"
#include "../../src/structs.h"

class MibitTip;
class QDateTime;
class QTime;
class QDate;

class ResumeDialogUI : public QFrame, public Ui::resumeDialog
{
  Q_OBJECT
  public:
    ResumeDialogUI( QWidget *parent=0);
};

class ResumeDialog : public KDialog
{
  Q_OBJECT
  public:
    ResumeDialog( QWidget *parent=0 );
    ~ResumeDialog();

    void        setDb(QSqlDatabase database);
    void        setUserId(qulonglong id) { userId = id;  }
    qulonglong  getSelectedTransaction() { return trNumber; }
    qulonglong  getSelectedClient()      { return clientId; }
    QDate       getTrDate()              { return trDate; }
    QTime       getTrTime()              { return trTime; }
    QList<ProductInfo> getProductsList() { return pList;  }
    QList<SpecialOrderInfo> getSOList()  { return soList; }

  private slots:
    void    itemClicked(const QModelIndex &index);
    void    item_Clicked(const QModelIndex &index, const QModelIndex &indexp);
    void    setupModel();
    void    selectItem();
    void    filterClient();
  protected slots:
    virtual void slotButtonClicked(int button);
  private:
    ResumeDialogUI *ui;
    QSqlDatabase db;
    bool m_modelAssigned;
    QSqlRelationalTableModel *trModel;
    qulonglong trNumber;
    qulonglong userId;
    qulonglong clientId;
    QDate      trDate;
    QTime      trTime;
    QList<ProductInfo> pList;
    QList<SpecialOrderInfo> soList;
};

#endif
