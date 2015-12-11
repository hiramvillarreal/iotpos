/**************************************************************************
*   Copyright (C) 2007-2009 by Miguel Chavez Gamboa                       *
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
#ifndef PRINT_DEV_H
#define PRINT_DEV_H

/**
* This class is for printing on printers supporting the ports /dev/XXX 
* Accessing them trough qfile.
*
* @author Miguel Chavez Gamboa <miguel@lemonpos.org>
* @version 0.1
*/

class QString;

class PrintDEV {
  public:
    static bool printSmallBalance(const QString &dev, const QString &codec, const QString &lines);
    static bool printSmallTicket(const QString &dev, const QString &codec, const QString &lines);
};

#endif
