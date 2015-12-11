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

#include "misc.h"
#include <QByteArray>
#include <QBuffer>
#include <QIODevice>
#include <QPixmap>
#include <QSize>
#include <QFontMetrics>
#include <QStringList>
#include <QString>

QByteArray Misc::pixmap2ByteArray(QPixmap *pix, bool scale)
{
  QByteArray bytes;
  QBuffer buffer(&bytes);
  buffer.open(QIODevice::WriteOnly);
  int max = 150;

  if (((pix->height() > max) || (pix->width() > max)) && scale ) {
    QPixmap newPix;
    if (pix->height() == pix->width()) {
      newPix = pix->scaled(QSize(max, max));
    }
    else if (pix->height() > pix->width() ) {
      newPix = pix->scaledToHeight(max);
    }
    else  {
      newPix = pix->scaledToWidth(max);
    }
    if (newPix.hasAlpha()) { newPix.save(&buffer, "PNG"); }
    else newPix.save(&buffer, "JPG");
  }
  else {
    //NO scaling needed...
    if (pix->hasAlpha()) { pix->save(&buffer, "PNG"); }
    else pix->save(&buffer, "JPG");
  }

  return bytes;
}

QByteArray Misc::pixmap2ByteArray(QPixmap *pix, int maxW, int maxH)
{
  QByteArray bytes;
  QBuffer buffer(&bytes);
  buffer.open(QIODevice::WriteOnly);

  if ((pix->height() > maxH) || (pix->width() > maxW) ) {
    QPixmap newPix;
    if (pix->height() == pix->width()) {
      newPix = pix->scaled(QSize(maxW, maxH));
    }
    else if (pix->height() > pix->width() ) {
      newPix = pix->scaledToHeight(maxH);
    }
    else  {
      newPix = pix->scaledToWidth(maxW);
    }
    if (newPix.hasAlpha()) { newPix.save(&buffer, "PNG"); }
    else newPix.save(&buffer, "JPG");
  }
  else {
    //NO scaling needed...
    if (pix->hasAlpha()) { pix->save(&buffer, "PNG"); }
    else pix->save(&buffer, "JPG");
  }

  return bytes;
}

QStringList Misc::stringToParagraph(const QString &str, const QFontMetrics &fm, const double &maxL)
{
    QStringList strList;
    QString strCopy = str;
    double strW = fm.size(Qt::TextExpandTabs | Qt::TextDontClip, str).width();
    double realTrozos = strW / maxL;
    int trozos   = realTrozos;
    double diff = (realTrozos - trozos);
    if (diff > 0.25 && trozos > 0) trozos += 1;
    int tamTrozo = 0;
    if (trozos > 0) {
        tamTrozo = (str.length()/trozos);
    } else {
        tamTrozo = str.length();
    }
    
    QStringList otherList;
    for (int x = 1; x <= trozos; x++) {
        //we repeat for each trozo
        if (x*(tamTrozo-1) < strCopy.length())
            strCopy.insert(x*(tamTrozo-1), "|  "); //create a section
    }
    otherList = strCopy.split("|");//NOTE: Sacar esta linea del for?
    if (!otherList.isEmpty()) strList << otherList;
    if (trozos < 1) strList << str;
    //qDebug()<<"rm : Trozos:"<<trozos<<" tamTrozo:"<<tamTrozo<<" realTrozos:"<<QString::number(realTrozos,'f', 2)<<" maxL:"<<maxL<<" str.width in pixels:"<<fm.size(Qt::TextExpandTabs | Qt::TextDontClip, str).width()<<" diff:"<<diff;
    
    return strList;
}

QStringList Misc::stringToParagraph(const QString &str, const int &maxChars)
{
    QStringList strList;
    QString strCopy = str;
    double strLen = str.length();
    double realTrozos = strLen / maxChars;
    int trozos   = realTrozos;
    double diff = (realTrozos - trozos);
    if (diff > 0 && trozos > 0) trozos += 1;
    int tamTrozo = 0;
    if (trozos > 0) {
        tamTrozo = (str.length()/trozos);
    } else {
        tamTrozo = str.length();
    }
    
    QStringList otherList;
    for (int x = 1; x <= trozos; x++) {
        //we repeat for each trozo
        if (x*(tamTrozo-1) < strCopy.length())
            strCopy.insert(x*(tamTrozo-1), "|"); //create a section
    }
    otherList = strCopy.split("|"); //NOTE: Sacar esta linea del for?
    if (!otherList.isEmpty()) strList << otherList;
    if (trozos < 1) strList << str;
    //qDebug()<<"rm : Trozos:"<<trozos<<" tamTrozo:"<<tamTrozo<<" realTrozos:"<<QString::number(realTrozos,'f', 2)<<"Str Length: "<<str.length()<<" maxChars:"<<maxChars<<" diff:"<<diff;
    
    return strList;
}

