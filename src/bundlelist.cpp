/***************************************************************************
 *   Copyright © 2012 by Miguel Chavez Gamboa                              *
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
#include <QMultiHash>
#include <QDebug>
#include <QtSql>


#include "bundlelist.h"
#include "../../dataAccess/azahar.h"

BundleList::BundleList()
{
    bundles.clear();
}

bool BundleList::contains(const qulonglong &itemCode)
{
    return bundles.contains(itemCode); //it is just a wrapper function
}

void BundleList::addItem(const BundleInfo &bundle, const int &maxItems)
{
    //We start our search for a free slot and bundle.
    if ( bundles.isEmpty() ) {
        //As there are no bundles, then we add a new one.
        qDebug()<<"Empty bundles... inserting new one";
        insertNewBundle(bundle, maxItems);
    } else {
        //BEGIN: No empty bundles list. Search starts here.
        int inserted = 0;
        qDebug()<<"Going to search  "<<bundle.product_id<<"x"<<bundle.qty<<" @"<<bundle.price;
        QMultiHash<qulonglong, BundleInfo>::iterator i = bundles.find(bundle.product_id); //if no bundle for the product, then the next while loop will not be executed
        while (i != bundles.end() && i.key() == bundle.product_id) {
            qDebug()<<"Examining Bundle | Qty:"<<i.value().qty<<" Price:"<<i.value().price<<" Product:"<<i.value().product_id<<" | "<<" Required Qty:"<< bundle.qty<<" Required Product:"<<bundle.product_id;
            BundleInfo current = i.value(); // for working with current instead of i.value()...
            qDebug()<<current.qty<<" @ "<<current.price;
            if ( current.qty < maxItems ) {
                // Has some free slots... how many free?
                int freeSlots = maxItems - current.qty;
                qDebug()<<"Free Slots:"<<freeSlots<<" Filled Slots:"<<current.qty;
                if ( freeSlots > 0 ){
                    //so, there are free slots, but how many do we need?
                    double needed = bundle.qty;
                    qDebug()<<"Needed Slots:"<<needed;
                    //We occupy the free slots NEEDED ( and allowed for the bundle )
                    if ( needed <= freeSlots ) {
                        current.qty += needed;
                        //current.price = //FIXME!
                        inserted += needed;
                        i.value() = current;
                    }
                    else {
                        current.qty += freeSlots;
                        //current.price = //FIXME!
                        inserted += freeSlots;
                        i.value() = current;
                    }
                    //qDebug()<<"Inserted "<<inserted<<" | NOW current.qty:"<<current.qty;
                } // freeSlots > 0
            } else { /*it is full, so next..  FIXME: this block can be removed! */ }
            //check if this i is the last bundle in the loop.
            ++i; //advance iterator, then we can check if it was the end.
            qDebug()<<"Inserted "<<inserted<<" | NOW current.qty:"<<current.qty<<" BUNDLE QTY (Required):"<<bundle.qty;
            if ( i == bundles.end() && inserted < bundle.qty ) {
                //still need to insert more slots... at new bundles.
                qDebug()<<"Last bundle in the list, and need to insert more...";
                BundleInfo b;
                int required = bundle.qty - inserted;
                b.product_id = bundle.product_id;
                b.qty = required;
                b.price = bundle.price; //FIXME: CHECK THE PRICE.
                insertNewBundle(b, maxItems);
                inserted += required;
            }// still need to insert more slots!
        }
        //We still need to check if any was inserted. If the iteration was empty (no bundle with such pruduct code) then add the items.
        if (inserted <= 0)
            insertNewBundle(bundle, maxItems);
        //END: search
    }
}


void BundleList::insertNewBundle(const BundleInfo &bndl, const int max)
{
    //First we check the max allowed slots and the requested ones to create the appropiate bundles.
    if ( bndl.qty > max ) {
        double needed = bndl.qty / max; //needed Bundles
        int iNeed = needed; //remove decimal part
        int excess = bndl.qty - (iNeed*max); //the missing slots.
        qDebug()<<"\n Needed:"<<needed<<" iNeed:"<<iNeed<<" excess:"<<excess<<" | MAX:"<<max<<" bndl.qty:"<<bndl.qty;
        if ( (needed - iNeed) > 0 )
            iNeed++;//we need another one, that will contain free slots.
            for (int i=0; i<iNeed; i++) {
                BundleInfo b;
                b.product_id = bndl.product_id;
                b.price = bndl.price;
                if ( i == (iNeed-1) ) //last one and will contain free slots..
                    b.qty = excess;
                else
                    b.qty = max;
                bundles.insert(bndl.product_id, b);
                qDebug()<<" <new> Inserting bundle. Product Code"<<b.product_id<<" Price:"<<b.price<<" Qty:"<<b.qty;
            } //for creating bundles...
    } else {
        //only one bundle needed.
        qDebug()<<"NEW Bundle to insert:"<<bndl.product_id<<"x"<<bndl.qty<<" @ "<<bndl.price;
        bundles.insert(bndl.product_id, bndl);
    }
}


void BundleList::debugAll()
{
    qDebug()<<"\n\n";
    foreach(BundleInfo b, bundles) {
        qDebug()<<"Bundle | Item:"<<b.product_id<<b.qty<<"x"<<b.price<<"";
    }
    qDebug()<<"\n\n";
}


void BundleList::setDb(QSqlDatabase database)
{
    db = database;
    if (!db.isOpen()) db.open();
}





// if ( bundle.qty > maxItems ) {
//     double needed = bundle.qty / maxItems;
//     int iNeed = needed; //remove decimal part
//     int excess = bundle.qty - iNeed;
//     if ( (needed - iNeed) > 0 )
//         needed++;//we need another one, that will contain free slots.
//         for (i=0; i<needed; i++) {
//             BundleInfo b;
//             b.product_id = bundle.product_id;
//             b.price = bundle.price;
//             if ( i == (needed-1) ) //last one and will contain free slots..
//                     b.qty = excess;
//             else
//                 b.qty = maxItems;
//             bundles.insert(bundle.product_id, b);
//             qDebug()<<" <> Inserting bundle. Product Code"<<b.product_id<<" Price:"<<b.price<<" Qty:"b.qty;
//         } //for creating bundles...
// } else {
//     //only one bundle needed.
//     bundles.insert(bundle.product_id, bundle);
// }
