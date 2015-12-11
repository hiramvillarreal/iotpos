/***************************************************************************
*   Copyright (C) 2009 by Miguel Chavez Gamboa                  *
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

#ifndef TICKETPOPUP_H
#define TICKETPOPUP_H

#include <QtGui>
#include <QString>
#include <QPainter>
class QGridLayout;
class QTextEdit;
class QTimer;
class QKeyEvent;

class TicketPopup : public QDialog
{
  Q_OBJECT
  private:
    QGridLayout *gridLayout;
    QLabel *imagelabel;
    QTextEdit *editText;
    QTimer *timer;

  protected:
    void paintEvent(QPaintEvent *e);

  public:
    TicketPopup(QString text="", QPixmap pixmap=0, int timeToClose=1000);
    void setPixmap(QPixmap pixmap) { imagelabel->setPixmap(pixmap); }
    void popup();
    virtual void paint(QPainter *) {}
    virtual void keyPressEvent( QKeyEvent * event);
    signals:
    void onTicketPopupClose();
  private slots:
    void closeIt();
};

#endif
