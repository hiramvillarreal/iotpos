/***************************************************************************
 *   Copyright (C) 2007-2009 by Miguel Chavez Gamboa                  *
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

#ifndef HASH_H
#define HASH_H

class QString;
class QByteArray;

  /**
   * This class is for hashing a password using SHA1 and returning as a QString.
   * Based on KWallet code.
   *
   * @author Miguel Chavez Gamboa <miguel.chavez.gamboa@gmail.com>
   * @version 0.1
   */
  class Hash
  {
    public:
      static QByteArray  getCheapSalt();  
      static QByteArray  getSalt();
      static QString     password2hash(const QByteArray& password);
  };

#endif
