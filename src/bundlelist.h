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

#ifndef BUNDLELIST_H
#define BUNDLELIST_H

#include <QMultiHash>
#include <QtSql>
#include "structs.h"

/**
 * This class is for store bundles at runtime.
 *
 * @short BundleList Class
 * @author Miguel Chavez Gamboa <miguel@lemonpos.org>
 * @version 0.1
 */
class BundleList :  public QObject
{
    Q_OBJECT
    
public:
    BundleList();
    void addItem(const BundleInfo &bundle, const int &maxItems); //adds an item to a bundle slot or creates a new bundle if needed. maxItems is the maximum slots for the item type.
    bool contains(const qulonglong &itemCode);
    void clear() { bundles.clear(); };
    void debugAll();

    void    setDb(QSqlDatabase database);

private:
    QMultiHash<qulonglong,BundleInfo> bundles;
    QSqlDatabase db;

    void insertNewBundle(const BundleInfo &bndl, const int max);
    
//private slots:

    //TODO: Create signals for emiting when completing a task. To redraw the item in the tableWidget.
    //TODO: Create slots for doing a task when the UI code has to do something: EXAMPLE: Remove/Decrement a product in the tableWidget/productsHash.
};

#endif
