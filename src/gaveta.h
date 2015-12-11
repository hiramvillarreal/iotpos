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

#ifndef _Gaveta_H_
#define _Gaveta_H_

#include <QList>
class QDateTime;


/**
 * This class is for store money control.
 *
 * @short Gaveta Class
 * @author Miguel Chavez Gamboa <miguel.chavez.gamboa@gmail.com>
 * @version 0.1
 */
class Gaveta
{
 public:
   Gaveta();
   ~Gaveta();
   /** Used only at the beggining. each time is empty or filled. **/
   void      setPrinterDevice(QString file);
   void      setAvailableInCash(double amount);
   void      setAvailableInCard(double amount);
   void      setStartDateTime(QDateTime datetime);
   void      setInitialAmount(double qty);
   /** Used each time a transaction is completed: Out **/
   void      substractCash(double amount);
   void      substractCard(double amount);
   /** Used each time a transaction is completed : In **/
   void      addCash(double amount);
   void      addCard(double amount); //MCH 22sept07
   void      incCardTransactions();
   void      incCashTransactions();
   double    getAvailableInCash();
   double    getAvailableInCard();
   double    getInitialAmount();
   double    getInAmount();
   double    getOutAmount();
   QDateTime   getStartDateTime();
   QList<qulonglong> getTransactionIds();
   int       getTransactionsCount();
   int       getCashTransactionsCount();
   int       getCardTransactionsCount();
   void      insertTransactionId(qulonglong id);
   bool      isUnused();
   void      open();
   QList<qulonglong> getCashflowIds();
   void      insertCashflow(qulonglong id);
   void      reset();
   

  private:
    void      addLog(double qty);
    void      clearLog();
    double    availableInCash;
    double    availableInCard;
    double    in; //Not considered the initialAmount deposited by admin.
    double    out;
    double    initialAmount;
    int       cashTransactions;
    int       cardTransactions;
    int       totalTransactions;
    bool      unused;
    QList<qulonglong> tIds;
    QList<double> log;
    QList<qulonglong> cashflowIds;
    QDateTime startDateTime;
    QString   printerDevice;
};

#endif

