/**************************************************************************
 *   Copyright © 2007-2010 by Miguel Chavez Gamboa                         *
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
#ifndef PRINT_CUPS_H
#define PRINT_CUPS_H

#include "../src/structs.h"

/**
* This class is for printing on printers with cups driver installed
* Accessing them trough cups.
*
* @author Miguel Chavez Gamboa <miguel@lemonpos.org>
* @version 0.2
*/

class QString;

class PrintCUPS {
  public:
    static bool printSmallBalance(const PrintBalanceInfo &pbInfo, QPrinter &printer); //NOTE Apr 14 2011: Fixed page/font size.
    static bool printSmallTicket(const PrintTicketInfo &ptInfo, QPrinter &printer);//NOTE Apr 14 2011: Fixed page/font size.
    static bool printBigTicket(const PrintTicketInfo &ptInfo, QPrinter &printer);
    static bool printSmallEndOfDay(const PrintEndOfDayInfo &pdInfo, QPrinter &printer);//NOTE Apr 14 2011: Fixed page/font size.
    static bool printBigEndOfDay(const PrintEndOfDayInfo &pdInfo, QPrinter &printer);

    static bool printSmallLowStockReport(const PrintLowStockInfo &plInfo, QPrinter &printer);
    static bool printBigLowStockReport(const PrintLowStockInfo &plInfo, QPrinter &printer);

    static bool printSmallSOTicket(const PrintTicketInfo &ptInfo, QPrinter &printer); //NOTE Apr 14 2011: Fixed page/font size.

    //static bool printSmallReservationTicket(const PrintTicketInfo &ptInfo, QPrinter &printer); //NOTE:WHAT ABOUT THIS!


    //FacturasMX
    static void printFooter(const FacturaCBB &factura, QPrinter &printer, QPainter &painter, int columnPrice, const bool &isCopy);
    static void printFactura(const FacturaCBB &factura, QPrinter &printer, const QString &fDate, const bool &isCopy);
    
};

#endif
