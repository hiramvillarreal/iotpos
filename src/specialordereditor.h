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
#ifndef SPECIALORDEREDITOR_H
#define SPECIALORDEREDITOR_H

#include <KDialog>
#include <QDate>
#include <QtGui>
#include <QPixmap>
#include <QtSql>

#include "ui_special_order.h"
#include "../../src/structs.h"

class MibitTip;
class MibitFloatPanel;
class QDateTime;

class SpecialOrderUI : public QFrame, public Ui::specialOrderEditor
{
  Q_OBJECT
  public:
    SpecialOrderUI( QWidget *parent=0);
};

class SpecialOrderEditor : public KDialog
{
  Q_OBJECT
  public:
    SpecialOrderEditor( QWidget *parent=0, bool newOne=true );
    ~SpecialOrderEditor();
    
    //qulonglong getOrderId()     { return ui->lbl->text().toULongLong(); };
    QString getDescription();
    double  getCost()        { return groupInfo.cost; }
    double  getPrice()       { return priceEach; }
    double  getQty()         { return ui->editQty->text().toDouble(); }
    QString getNotes()      { return  ui->editNotes->toPlainText(); }
    qulonglong getTransId() { return m_transId; }
    double  getPayment()    { return ui->editPayment->value()/ui->editQty->value();} ///we divide the total payment by the qty of items ordered, to report them to lemonview... lemonview expects the payment to be the price for the item to be inserted (so) in order to calculate the total sale.
    GroupInfo getGroupHash();
    QString getGroupElementsStr();
    int     getStatus();
    QString getContentNames();
    QDateTime getDateTime() { return dateTime; }
    QDateTime getDeliveryDateTime() { return ui->deliveryDT->dateTime(); }
    qulonglong getUserId();
    qulonglong getClientId();
    
    void    setDb(QSqlDatabase database);
    void    setCost(double c)          { groupInfo.cost = c;  } //NOTE:undesireable
    void    setPrice(double p)         { priceEach = p; }
    void    setQty(double q)           {ui->editQty->setValue(q); }
    void    setGroupElements(QString e);
    void    setModel(QSqlTableModel *model);
    void    setTransId(qulonglong id)  {m_transId = id; ui->lblTransId->setText(QString::number(id)); }
    void    setPayment(double d)       { ui->editPayment->setValue(d); }
    void    setDateTime(QDateTime dt)  { dateTime = dt; }
    void    setDeliveryDateTime(QDateTime dt)  { ui->deliveryDT->setDateTime(dt); dateTime = dt; }
    void    setDeliveryDateTimeEnabled(bool value) { ui->deliveryDT->setEnabled(value); }
    void    setUsername(QString name);
    void    setClientsComboEnabled(bool val) { ui->clientsCombo->setEnabled(val); }
    void    setClientName(QString name);

    
  private slots:
    void    calculateCost();
    void    checkFieldsState();
    void    applyFilter(const QString &text);
    void    addItem();
    void    removeItem();
    void    itemDoubleClicked(QTableWidgetItem* item);
    void    populateUsersCombo();
    void    populateClientsCombo();
    void    checkDate(QDateTime dt);
    void    checkValidInfo();
    void    hideError();
    void    createClient();
    void    enableCreateClient();
    void    updateNoteLength();
  protected slots:
    virtual void slotButtonClicked(int button);
  private:
    SpecialOrderUI *ui;
    QSqlDatabase db;
    GroupInfo groupInfo;
    bool m_modelAssigned;
    QSqlTableModel *m_model;
    qulonglong m_transId;
    double priceEach;
    double paymentEach;
    QDateTime dateTime;
    MibitTip *qtyTip;
    MibitTip *groupTip;
    MibitFloatPanel * newClientPanel;
};

#endif
