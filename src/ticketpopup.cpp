/***************************************************************************
*   Copyright (C) 2009 by Miguel Chavez Gamboa                            *
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

#include "ticketpopup.h"

#include <QtGui>
#include <QTimer>

#include <kstandarddirs.h>

TicketPopup::TicketPopup(QString text, QPixmap pixmap, int timeToClose)
{
  setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
  setWindowModality(Qt::ApplicationModal);
  setObjectName("main");

  gridLayout = new QGridLayout(this);
  imagelabel = new QLabel(this);
  imagelabel->setPixmap(pixmap);
  imagelabel->setAlignment(Qt::AlignCenter);
  gridLayout->addWidget(imagelabel, 0, 0);
  editText = new QTextEdit(this);
  editText->setHtml(text);
  editText->setReadOnly(true);
  gridLayout->addWidget(editText, 1, 0);
  gridLayout->setMargin(17);

  timer = new QTimer(this);
  timer->setInterval(timeToClose);
  connect(timer, SIGNAL(timeout()), this, SLOT(closeIt()));
  

  QString path = KStandardDirs::locate("appdata", "images/");
  QString filen = path + "/imgPrint.png";
  QPixmap pix(filen);
  setMask(pix.mask());
  QString st;
  st = QString("main { background-image: url(%1);}").arg(filen);
  setStyleSheet(st);
}

void TicketPopup::popup()
{
  //NOTE: Why before show() the frameGeometry is bigger, and after showing it, it resizes itself?
  move(2000,2000);
  show();
  int x = (QApplication::desktop()->width()/2 )-(frameGeometry().width()/2);
  int y = (QApplication::desktop()->height()/2)-(frameGeometry().height()/2);
  setGeometry(x,y,335,340);
  timer->start();
}

void TicketPopup::keyPressEvent( QKeyEvent * event)
{
  if ( event->key() == Qt::Key_Escape ) {
    emit onTicketPopupClose();
    timer->stop();
    close();
  } else QDialog::keyPressEvent(event);
}

void TicketPopup::paintEvent(QPaintEvent *e)
{
  QPainter painter;
  painter.begin(this);
  painter.setClipRect(e->rect());
  painter.setRenderHint(QPainter::Antialiasing);

  paint(&painter);
  painter.restore();
  painter.save();
  int level = 180;
  painter.setPen(QPen(QColor(level, level, level), 6));
  painter.setBrush(Qt::NoBrush);
  painter.drawRect(rect());
}

void TicketPopup::closeIt()
{
  timer->stop();
  emit onTicketPopupClose(); //to let squeezeview unfreeze the widgets
  close();
}

#include "ticketpopup.moc"
