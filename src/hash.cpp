/***************************************************************************
 *   Copyright (C) 2007-2009 by Miguel Chavez Gamboa                       *
 *   miguel.chavez.gamboa@gmail.com                                        *
 *   SHA code from kde kwallet                                             *
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
#include "hash.h"

#include "sha1.h"
#include <assert.h>

#include <stdlib.h>

#include <QString>
#include <QByteArray>
#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include <QTime> 

//#include <iostream>

QByteArray Hash::getCheapSalt()
{
    QString result="";
    srand( QTime::currentTime().toString("hhmmsszzz").toUInt() );
    
    QRegExp rx("([\\w+]|[\\s*&*%*\\$*#*!*=*¡*\\(*\\)*\\?*\\¿*\\[*\\]*\\{*\\}*\\/*])");
    int cont=0;
    rx.setCaseSensitivity(Qt::CaseInsensitive);

    while (cont<5) {
      QString data( rand() );
      //if ( rx.indexIn(data) !=-1 )
      if (data.contains(rx)) {
          result+=data;
          cont++;
        }
      }

        result.resize(5);
        return result.toLocal8Bit();
}

QByteArray Hash::getSalt()
{
    QString result="";
    QFile file("/dev/urandom");
    //NOTE: At some point of kernel 2.6.32, /dev/random stop working!  :(
    //      /dev/urandom is blocking if not enough entropy... so moving mouse or keyboard is needed. But
    //      now with this issue (random failing), urandom seems to work fine and in my tests it has not been blocking.
  
//     if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//         // In case /dev/random is a dead fish.
//         if( !file.waitForReadyRead(100))  file.close();
//     }
// 
//     if (!file.isOpen()) file.setFileName("/dev/urandom");
//     if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//         // In case /dev/random is a dead fish.
//         if( !file.waitForReadyRead(100))
//             file.close();
//     }
// 
//     if (!file.isOpen()) {
//         // FIXME: There should be some warning that cheap salt is being used.
//         qDebug() << "/dev/urandom not responding...  Using rand() to get the salt...";
//         return getCheapSalt();
//     }

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    
    QRegExp rx("[A-Za-z_0-9@#%&\\!\\$\\~\\^\\*]*"); 
    int cont=0;
    //rx.setCaseSensitivity(Qt::CaseInsensitive);
      
    QTextStream in(&file);
    while (cont<5) {
        QString data = in.readLine(1);
        if (!data.isNull() && data.contains(rx) && rx.matchedLength() > 0) {
            int pos = rx.indexIn(data);
            if (pos > -1) {
                result+=data.at(pos);
                cont++;
            }
        }
    }
    file.close();

    result.resize(5);
    return result.toLocal8Bit();
}


//from Kwalletbackend.
// this should be SHA-512 for release probably
QString Hash::password2hash(const QByteArray& password) {
  SHA1 sha;
  QByteArray hash;
  hash.resize(20);
  hash.fill(0);
  int shasz = sha.size() / 8;

  assert(shasz >= 20);

  QByteArray block1(shasz, 0);

  sha.process(password.data(), qMin(password.size(), 16));

  // To make brute force take longer
  for (int i = 0; i < 2000; i++) {
    memcpy(block1.data(), sha.hash(), shasz);
    sha.reset();
    sha.process(block1.data(), shasz);
  }

  sha.reset();

  if (password.size() > 16) {
    sha.process(password.data() + 16, qMin(password.size() - 16, 16));
    QByteArray block2(shasz, 0);
    // To make brute force take longer
    for (int i = 0; i < 2000; i++) {
      memcpy(block2.data(), sha.hash(), shasz);
      sha.reset();
      sha.process(block2.data(), shasz);
    }

    sha.reset();

    if (password.size() > 32) {
      sha.process(password.data() + 32, qMin(password.size() - 32, 16));

      QByteArray block3(shasz, 0);
      // To make brute force take longer
      for (int i = 0; i < 2000; i++) {
        memcpy(block3.data(), sha.hash(), shasz);
        sha.reset();
        sha.process(block3.data(), shasz);
      }

      sha.reset();

      if (password.size() > 48) {
        sha.process(password.data() + 48, password.size() - 48);

        QByteArray block4(shasz, 0);
        // To make brute force take longer
        for (int i = 0; i < 2000; i++) {
          memcpy(block4.data(), sha.hash(), shasz);
          sha.reset();
          sha.process(block4.data(), shasz);
        }

        sha.reset();
        // split 14/14/14/14
        hash.resize(56);
        memcpy(hash.data(),      block1.data(), 14);
        memcpy(hash.data() + 14, block2.data(), 14);
        memcpy(hash.data() + 28, block3.data(), 14);
        memcpy(hash.data() + 42, block4.data(), 14);
        block4.fill(0);
      } else {
        // split 20/20/16
        hash.resize(56);
        memcpy(hash.data(),      block1.data(), 20);
        memcpy(hash.data() + 20, block2.data(), 20);
        memcpy(hash.data() + 40, block3.data(), 16);
      }
      block3.fill(0);
    } else {
      // split 20/20
      hash.resize(40);
      memcpy(hash.data(),      block1.data(), 20);
      memcpy(hash.data() + 20, block2.data(), 20);
    }
    block2.fill(0);
  } else {
    // entirely block1
    hash.resize(20);
    memcpy(hash.data(), block1.data(), 20);
  }

  block1.fill(0);
  //MCH: to store hash as a String...
  QString output, tmp;
  unsigned char *digest;
  digest = (unsigned char*) hash.data();
  for (int i = 0; i < 20; ++i)
    output += tmp.sprintf("%02x", digest[i]);
  output = output.toUpper();

  return output;
}
