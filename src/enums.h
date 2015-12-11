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

#ifndef MYENUMS_H
#define MYENUMS_H

enum TransactionType  {tSell=1, tBuy=2, tChange=3, tReturn=4, tPayment=5, tOutOther=6};
enum PaymentType      {pUnknown=99, pCash=1, pCard=2, pOwnCredit=3 };
enum cashFlowType     {ctCashOut=1, ctCashOutMoneyReturnOnCancel=2, ctCashOutMoneyReturnOnProductReturn=3, ctCashIn=4, ctCashInReservation=5, ctCashOutReservation=6, ctCashInCreditPayment=7, ctCashInDebit=8};
enum TransactionState {tNotCompleted=1, tCompleted=2, tCancelled=3, tPOPending=4, tPOCompleted=5, tPOIncomplete=6, tReserved=7, tCompletedOwnCreditPending=8 /*8->Really not pending*/ , tCompletedOwnCreditPaid=9 /*9->Not used*/ };
enum SellUnits        {uPiece=1, uWeightKg=2, uLengthMts=3, uVolumeLitre=4, uVolumeCubicMts=5}; //not needed anymore stored on database
enum                  {colCode=0, colDesc=1, colPrice=2, colQty=3, colUnits=4, colDisc=5, colDue=6}; //column names and numbers..
enum                  {pageMain=0, pageSearch=1, pageReprintTicket=2, pageRerturnProducts=3, pageAdds=4};

enum userRoles        {roleBasic=1, roleAdmin=2, roleSupervisor=3 };

enum soStatus         {stPending=0, stInProgress=1, stReady=2, stDelivered=3, stCancelled=4};

enum reservationState {rPending=1, rCompleted=2, rCancelled=3};


static const char db_version[] = "0950";
static const char db_hash[] = ""; //here the idea is to hash the db file to compare the installed one with released versions.

#endif
