/**************************************************************************
 *   Copyright © 2007-2011 by Miguel Chavez Gamboa                         *
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
#ifndef _InputDialog_H_
#define _InputDialog_H_

#include <QtGui>
#include <klineedit.h>

enum DialogType       {dialogMoney=0, dialogMeasures=1, dialogTicket=3, dialogCashOut=4, dialogStockCorrection=5, dialogTerminalNum=6, dialogSpecialOrder=7, dialogTicketMsg=8, dialogCurrency=9 };

class InputDialog : public QDialog
{
  Q_OBJECT
  private:
    QHBoxLayout *titleLayout;
    QGridLayout *gridLayout;
    QVBoxLayout *vLayout;
    QHBoxLayout *buttonsLayout;
    KLineEdit   *lineEdit, *reasonEdit, *productCodeEdit;
    QLabel      *label, *qLabel, *reasonLabel, *productCodeLabel;
    QLabel      *lPixmap;
    QPushButton *buttonAccept;
    QPushButton *buttonCancel;
    DialogType  dialogType;
    double _max, _min;

  public:
    //NOTE: in my computer, double is 8 bytes long (2^64 -1 = 1.844e^19)
    InputDialog(QWidget *parent=0L, bool integer=true, DialogType type=dialogMoney, QString msg="", double min=0.0, double max=18440000000000000000.0);//1.8x10^19
    virtual void paint(QPainter *);
    double dValue;
    qulonglong iValue;
    QString reason;
    qulonglong getPCode() { return productCodeEdit->text().toULongLong(); } ;
  public slots:
    void setProductCode(qulonglong theCode);
    void setAmount(double damnt);
    void setAmount(int iamnt);
    void setProductCodeReadOnly();
  protected slots:
    void acceptIt();
  private slots:
    virtual void paintEvent(QPaintEvent *);
};

#endif
