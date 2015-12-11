/**************************************************************************
 *   Copyright © 2007-2012 by Miguel Chavez Gamboa                         *
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

#include <QWidget>
#include <QByteArray>
#include "azahar.h"
#include <klocale.h>

Azahar::Azahar(QWidget * parent): QObject(parent)
{
  errorStr = "";
  m_mainClient = "undefined";
}

Azahar::~Azahar()
{
  //qDebug()<<"*** AZAHAR DESTROYED ***";
}

void Azahar::initDatabase(QString user, QString server, QString password, QString dbname)
{
  QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
  db = QSqlDatabase::addDatabase("QMYSQL");
  db.setHostName(server);
  db.setDatabaseName(dbname);
  db.setUserName(user);
  db.setPassword(password);

  if (!db.isOpen()) db.open();
  if (!db.isOpen()) db.open();
}

void Azahar::setDatabase(const QSqlDatabase& database)
{
  db = database;
  if (!db.isOpen()) db.open();
}

bool Azahar::isConnected()
{
  return db.isOpen();
}

void Azahar::setError(QString err)
{
  errorStr = err;
}

QString Azahar::lastError()
{
  return errorStr;
}

bool  Azahar::correctStock(qulonglong pcode, double oldStockQty, double newStockQty, const QString &reason )
{ //each correction is an insert to the table.
  bool result1, result2;
  result1 = result2 = false;
  if (!db.isOpen()) db.open();

  //Check if the desired product is a a group. Or hasUnlimitedStock
  ProductInfo p = getProductInfo(QString::number(pcode));
  if ( p.isAGroup || p.hasUnlimitedStock ) return false;

  QSqlQuery query(db);
  QDate date = QDate::currentDate();
  QTime time = QTime::currentTime();
  query.prepare("INSERT INTO stock_corrections (product_id, new_stock_qty, old_stock_qty, reason, date, time) VALUES(:pcode, :newstock, :oldstock, :reason, :date, :time); ");
  query.bindValue(":pcode", pcode);
  query.bindValue(":newstock", newStockQty);
  query.bindValue(":oldstock", oldStockQty);
  query.bindValue(":reason", reason);
  query.bindValue(":date", date.toString("yyyy-MM-dd"));
  query.bindValue(":time", time.toString("hh:mm"));
  if (!query.exec()) setError(query.lastError().text()); else result1=true;

  //modify stock
  QSqlQuery query2(db);
  query2.prepare("UPDATE products set stockqty=:newstock where code=:pcode;");
  query2.bindValue(":pcode", pcode);
  query2.bindValue(":newstock", newStockQty);
  if (!query2.exec()) setError(query2.lastError().text()); else result2=true;
  return (result1 && result2);
}

double Azahar::getProductStockQty(qulonglong code)
{
  double result=0.0;
  if (db.isOpen()) {
    QString qry = QString("SELECT stockqty from products WHERE code=%1").arg(code);
    QSqlQuery query(db);
    if (!query.exec(qry)) {
      int errNum = query.lastError().number();
      QSqlError::ErrorType errType = query.lastError().type();
      QString error = query.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),error);
    }
    if (query.size() <= 0)
      setError(i18n("Error serching product id %1, Rows affected: %2", code,query.size()));
    else {
      while (query.next()) {
        int fieldStock = query.record().indexOf("stockqty");
        int fieldIsUnlimited = query.record().indexOf("hasUnlimitedStock");
        result = query.value(fieldStock).toDouble(); //return stock
        if ( query.value(fieldIsUnlimited).toBool() )
            result = 999999; //just make sure we do not return 0 for unlimited stock items.
      }
    }
  }
  return result;
}

qulonglong Azahar::getProductOfferCode(qulonglong code)
{
  qulonglong result=0;
  if (db.isOpen()) {
    QString qry = QString("SELECT id,product_id from offers WHERE product_id=%1").arg(code);
    QSqlQuery query(db);
    if (!query.exec(qry)) {
      int errNum = query.lastError().number();
      QSqlError::ErrorType errType = query.lastError().type();
      QString error = query.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),error);
    }
    if (query.size() <= 0)
      setError(i18n("Error serching offer id %1, Rows affected: %2", code,query.size()));
    else {
      while (query.next()) {
        int fieldId = query.record().indexOf("id");
        result = query.value(fieldId).toULongLong(); //return offer id
      }
    }
  }
  return result;
}


qulonglong Azahar::getNextProductCode()
{
    qulonglong r = 0;
    
    if (!db.isOpen()) db.open();
    QSqlQuery myQuery(db);
    QString qry("SELECT * FROM products ORDER BY code DESC LIMIT 1;");
    if (myQuery.exec(qry) ) {
        while (myQuery.next()) {
            int numId      = myQuery.record().indexOf("code");
            r = myQuery.value(numId).toULongLong();
        }
    }
    
    return r;
}

ProductInfo Azahar::getProductInfo(const QString &code, const bool &notConsiderDiscounts)
{
  ProductInfo info;
  info.code=0;
  info.desc="Ninguno";
  info.price=0;
  info.disc=0;
  info.cost=0;
  info.lastProviderId = 0;
  info.department=0;
  info.category=0;
  info.subcategory=0;
  info.taxmodelid=0; //for future use! MCH DEC 28 2010
  info.units=0;
  info.points=0;
  info.row=-1;info.qtyOnList=-1;info.purchaseQty=-1;
  info.discpercentage=0;
  info.validDiscount=false;
  info.alphaCode = "-NA-";
  info.vendorCode = "-NA-";
  info.lastProviderId = 0;
  info.isAGroup = false;
  info.isARawProduct = false;
  info.groupPriceDrop = 0;
  info.hasUnlimitedStock = false;
  info.isNotDiscountable = false;
  info.subcategory = 0;
  QString rawCondition;

  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QString qry = QString("SELECT  P.code as CODE, \
    P.alphacode as ALPHACODE, \
    P.vendorcode as VENDORCODE, \
    P.name as NAME ,\
    P.price as PRICE, \
    P.cost as COST ,\
    P.stockqty as STOCKQTY, \
    P.units as UNITS, \
    P.points as POINTS, \
    P.photo as PHOTO, \
    P.department as DEPARTMENTID, \
    P.category as CATID, \
    P.subcategory as SUBCATID, \
    P.lastproviderid as PROVIDERID, \
    P.taxpercentage as TAX1, \
    P.extrataxes as TAX2, \
    P.taxmodel as TAXMODELID, \
    P.isARawProduct as ISRAW, \
    P.isAGroup as ISGROUP, \
    P.groupElements as GE, \
    P.groupPriceDrop as GPRICEDROP,\
    P.soldunits as SOLDUNITS, \
    P.isNotDiscountable as NONDISCOUNT, \
    P.hasUnlimitedStock as UNLIMITEDSTOCK, \
    U.text as UNITSDESC, \
    C.text as CATEGORY, \
    PR.name as LASTPROVIDER ,\
    T.tname as TAXNAME, \
    T.elementsid as TAXELEM \
    FROM products AS P, taxmodels as T, providers as PR, categories as C, measures as U \
    WHERE PR.id=P.lastproviderid AND T.modelid=P.taxmodel \
    AND C.catid=P.category AND U.id=P.units\
    AND (CODE='%1' or ALPHACODE='%1');").arg(code);
    
    QSqlQuery query(db);
    if (!query.exec(qry)) {
      int errNum = query.lastError().number();
      QSqlError::ErrorType errType = query.lastError().type();
      QString error = query.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),error);
      setError(i18n("Error getting product information for code %1, Rows affected: %2", code,query.size()));
    }
    else {
      while (query.next()) {
        int fieldTax1= query.record().indexOf("TAX1");
        int fieldTax2= query.record().indexOf("TAX2");
        int fieldGroupPD = query.record().indexOf("GPRICEDROP");
        int fieldCODE = query.record().indexOf("CODE");
        int fieldDesc = query.record().indexOf("NAME");
        int fieldPrice= query.record().indexOf("PRICE");
        int fieldPhoto= query.record().indexOf("PHOTO");
        int fieldCost= query.record().indexOf("COST");
        int fieldUnits= query.record().indexOf("UNITS");
        int fieldUnitsDESC= query.record().indexOf("UNITSDESC");
        //int fieldTaxName= query.record().indexOf("TAXNAME");
        int fieldTaxModelId= query.record().indexOf("TAXMODELID");
        //int fieldCategoryName= query.record().indexOf("CATEGORY");
        int fieldDepartmentId= query.record().indexOf("DEPARTMENTID");
        int fieldCategoryId= query.record().indexOf("CATID");
        int fieldSubCategoryId= query.record().indexOf("SUBCATID");
        int fieldPoints= query.record().indexOf("POINTS");
        //int fieldLastProviderName = query.record().indexOf("LASTPROVIDER");
        int fieldLastProviderId = query.record().indexOf("PROVIDERID");
        int fieldAlphaCode = query.record().indexOf("ALPHACODE");
        int fieldVendorCode = query.record().indexOf("VENDORCODE");
        int fieldTaxElem = query.record().indexOf("TAXELEM");
        int fieldStock= query.record().indexOf("STOCKQTY");
        int fieldIsGroup = query.record().indexOf("ISGROUP");
        int fieldIsRaw = query.record().indexOf("ISRAW");
        int fieldGE = query.record().indexOf("GE");
        int fieldSoldU = query.record().indexOf("SOLDUNITS");
        int fieldUnlimited = query.record().indexOf("UNLIMITEDSTOCK");
        int fieldNonDiscount = query.record().indexOf("NONDISCOUNT");

        info.code     = query.value(fieldCODE).toULongLong();
        info.alphaCode = query.value(fieldAlphaCode).toString();
        info.vendorCode = query.value(fieldVendorCode).toString();
        info.desc     = query.value(fieldDesc).toString();
        info.price    = query.value(fieldPrice).toDouble();
        info.photo    = query.value(fieldPhoto).toByteArray();
        info.stockqty = query.value(fieldStock).toDouble();
        info.cost     = query.value(fieldCost).toDouble();
        info.tax      = query.value(fieldTax1).toDouble(); ///TO be removed later, when taxmodel is coded.
        info.extratax = query.value(fieldTax2).toDouble(); ///TO be removed later, when taxmodel is coded.
        info.units    = query.value(fieldUnits).toInt();
        info.unitStr  = query.value(fieldUnitsDESC).toString();
        info.department = query.value(fieldDepartmentId).toInt();
        info.category = query.value(fieldCategoryId).toInt();
        info.subcategory = query.value(fieldSubCategoryId).toInt();
        info.utility  = info.price - info.cost;
        info.row      = -1;
        info.points   = query.value(fieldPoints).toInt();
        info.qtyOnList = -1;
        info.purchaseQty = -1;
        info.lastProviderId = query.value(fieldLastProviderId).toULongLong();
        info.soldUnits = query.value(fieldSoldU).toDouble();
        info.isARawProduct = query.value(fieldIsRaw).toBool();
        info.isAGroup = query.value(fieldIsGroup).toBool();
        info.groupPriceDrop = query.value(fieldGroupPD).toDouble();
        info.taxmodelid = query.value(fieldTaxModelId).toULongLong();
        info.taxElements = query.value(fieldTaxElem).toString();
        info.groupElementsStr = query.value(fieldGE).toString();
        info.hasUnlimitedStock = query.value(fieldUnlimited).toBool();
        info.isNotDiscountable = query.value(fieldNonDiscount).toBool();

        qDebug()<<info.desc<<" DEP:"<<info.department<<" CAT:"<<info.category<<" SUBCAT:"<<info.subcategory;
      }

      if ( info.hasUnlimitedStock )
            info.stockqty = 999999; //just make sure we do not return 0 for unlimited stock items.
      ///NOTE:negative stock will be reported as is (negative), lemon must verify at settings if allowing negative stock with an alert.
      
      /** @TODO: for future releases where taxmodel is included in code
      //get missing stuff - tax,offers for the requested product
      if (info.isAGroup) //If its a group, the taxmodel is ignored, the tax will be its elements taxes
        info.tax = getGroupAverageTax(info.code); ///NOTE: This may be deprecated.. see the getGroupPriceAndTax() method
      else
          info.tax = getTotalTaxPercent(info.taxElements);
      if (getConfigTaxIsIncludedInPrice()) {
          ///tax is included in price... mexico style.
          double pWOtax = info.price/(1+((info.tax)/100));
          info.totaltax = pWOtax*((info.tax)/100); // in money...
      } else {
          ///tax is not included in price... usa style.
          info.totaltax = info.price*(1+(info.tax/100)); //tax in money
      }
      **/
      
      ///NOTE FOR DISCOUNTS:  TODO: ADD THIS TO THE USER MANUAL
      //     If a group contains product with discounts THOSE ARE NOT TAKEN INTO CONSIDERATION,
      //     The only DISCOUNT for a GROUP is the DISCOUNT created for the GROUP PRODUCT -not for its contents-.
      //     The discounts for GROUPS are PERPETUAL.
      //     Another way to assign a "discount" for a group is reducing the price in the product editor
      //     this is not considered a discount but a lower price, and both can coexist so
      ///    be CAREFUL with this!
      
     //get discount info... if have one.
     QSqlQuery query2(db);
     //if ( !info.isNotDiscountable ) { //get discounts if !isNotDiscountable...
        if (query2.exec(QString("Select * from offers where product_id=%1").arg(info.code) )) {
        QList<double> descuentos; descuentos.clear();
        while (query2.next()) // return the valid discount only (and the greater one if many).
            {
            int fieldDisc = query2.record().indexOf("discount");
            int fieldDateStart = query2.record().indexOf("datestart");
            int fieldDateEnd   = query2.record().indexOf("dateend");
            double descP= query2.value(fieldDisc).toDouble();
            QDate dateStart = query2.value(fieldDateStart).toDate();
            QDate dateEnd   = query2.value(fieldDateEnd).toDate();
            QDate now = QDate::currentDate();
            //See if the offer is in a valid range...
            if (info.isAGroup) { /// if produc is a group, the discount has NO DATE LIMITS!!! its valid forever.
                descuentos.append(descP);
            }
            else if ((dateStart<dateEnd) && (dateStart<=now) && (dateEnd>=now)  ) {
                //save all discounts here and decide later to return the bigger valid discount.
                descuentos.append(descP);
            }
            }
            //now which is the bigger valid discount?
            qSort(descuentos.begin(), descuentos.end(), qGreater<int>());
            //qDebug()<<"DESCUENTOS ORDENADOS DE MAYOR A MENOR:"<<descuentos;
            if (!descuentos.isEmpty()) {
            //get the first item, which is the greater one.
            info.validDiscount = true;
            info.discpercentage = descuentos.first();
            info.disc =       (info.discpercentage/100) * (info.price); //round((info.discpercentage/100) * (info.price*100))/100; //FIXME:This is not necesary VALID.
            } else {info.disc = 0; info.validDiscount =false;}
        }
     //} else {info.disc = 0; info.validDiscount = false;} // if !nondiscountable
     /// If its a group, calculate the right price first.  @note: this will be removed when taxmodels are coded.
     if (info.isAGroup) {
      //get each content price and tax percentage.
      GroupInfo gInfo = getGroupPriceAndTax(info);
      info.price = gInfo.price; //it includes price drop!
      info.tax   = gInfo.tax;
      info.extratax = 0; //accumulated in tax...
      //qDebug()<<"=================== GROUP Price:"<<info.price<<" Tax:"<<info.tax<<"======================";
     }
     ///tax calculation - it depends on discounts... @note: this will be removed when taxmodels are coded.
     double pWOtax = 0;
     if (getConfigTaxIsIncludedInPrice()) //added on jan 28 2010. 
       pWOtax= info.price/(1+((info.tax+info.extratax)/100));
     else
       pWOtax = info.price;
     //take into account the discount.
     if (info.validDiscount) {
       double iDisc=0;
       iDisc = (notConsiderDiscounts) ? 0 : (info.discpercentage/100)*pWOtax;
       //if (notConsiderDiscounts) qDebug()<<" ================= WARNING: NOT CONSIDERING DISCOUNT FOR TAX CALCULATION! ======================= ";
       pWOtax = pWOtax - iDisc;
     }
     //finally we have on pWOtax the price without tax and discount for 1 item
     ///NOTE: Aug 17 2011: this tax does not take into account the ocassional discounts or price changes. It may be false.
     double tax1m = (info.tax/100)*pWOtax;
     double tax2m = (info.extratax/100)*pWOtax;
     info.totaltax = tax1m + tax2m;
     //qDebug()<<"  getProductInfo() :: Total tax for product "<<info.desc<<info.tax+info.extratax<< " $:"<<info.totaltax;
     ///end of tax calculation
    }
  }
  return info;
}

// QList<ProductInfo> Azahar::getTransactionGroupsList(qulonglong tid)
// {
//   QList<ProductInfo> list;
//   QStringList groupsList = getTransactionInfo(tid).groups.split(",");
//   foreach(QString ea, groupsList) {
//     qulonglong c = ea.section('/',0,0).toULongLong();
//     double     q = ea.section('/',1,1).toDouble();
//     ProductInfo pi = getProductInfo(c);
//     pi.qtyOnList = q;
//     list.append(pi);
//   }
//   return list;
// }

qulonglong Azahar::getProductCode(QString text)
{
  QSqlQuery query(db);
  qulonglong code=0;
  if (query.exec(QString("select code from products where name='%1';").arg(text))) {
    while (query.next()) { 
      int fieldId   = query.record().indexOf("code");
      code = query.value(fieldId).toULongLong();
    }
  }
  else {
    //qDebug()<<"ERROR: "<<query.lastError();
    setError(query.lastError().text());
  }
  return code;
}

qulonglong Azahar::getProductCodeFromAlphacode(QString text)
{
    QSqlQuery query(db);
    qulonglong code=0;
    if (query.exec(QString("select code from products where alphacode='%1';").arg(text))) {
        while (query.next()) {
            int fieldId   = query.record().indexOf("code");
            code = query.value(fieldId).toULongLong();
        }
    }
    else {
        //qDebug()<<"ERROR: "<<query.lastError();
        setError(query.lastError().text());
    }
    return code;
}

qulonglong Azahar::getProductCodeFromVendorcode(QString text)
{
    QSqlQuery query(db);
    qulonglong code=0;
    if (query.exec(QString("select code from products where vendorcode='%1';").arg(text))) {
        while (query.next()) {
            int fieldId   = query.record().indexOf("code");
            code = query.value(fieldId).toULongLong();
        }
    }
    else {
        //qDebug()<<"ERROR: "<<query.lastError();
        setError(query.lastError().text());
    }
    return code;
}

/// UPDATED: This searches products by description and alphacode.   -Dec 28 2011-
QList<qulonglong> Azahar::getProductsCode(QString regExpName)
{
  QList<qulonglong> result;
  result.clear();
  QSqlQuery query(db);
  QString qry;
  QString tmpQry;
  if (regExpName == "*") qry = "SELECT code from products;";
  else {
      if ( regExpName.contains(' ') ) {
          ///  bujia' 'platino' 'honda
          //Podria ser ..WHERE name REGEXP 'bujia|platino|honda'. Pero como es un OR tambien nos regresaria los que contengan al menos uno de ellos.
          QString tmpS = regExpName;
          tmpS.replace(' ', "' '");
          tmpS = QString("'%1'").arg(tmpS);
          QStringList list = tmpS.split(' ', QString::SkipEmptyParts, Qt::CaseInsensitive);
          tmpQry = list.join(" AND `name` REGEXP ");
          QString tmpQry2 = tmpQry;
          tmpQry2 = tmpQry2.replace("name", "alphacode");
          qry = QString("select code,name,alphacode from products WHERE (`name` REGEXP %1) OR  (`alphacode` REGEXP %2) ").arg(tmpQry).arg(tmpQry2);
      }
      else
          qry = QString("select code,name,alphacode from products WHERE `name` REGEXP '%1' OR  `alphacode` REGEXP '%1'").arg(regExpName);
  }
  qDebug()<<"QUERY:"<<qry;
  //TODO: When user searches text like "white collar" and there are products like "white and red collar" or "white and brilliant collar" then the products are not found.
  //The key is to separate words with an OR: ..WHERE name REGEXP 'white' OR name REGEXP 'collar'
  //see if the regExpName contains spaces
  if (query.exec(qry)) {
    while (query.next()) {
      int fieldId   = query.record().indexOf("code");
      qulonglong id = query.value(fieldId).toULongLong();
      result.append(id);
      //qDebug()<<"APPENDING TO PRODUCTS LIST:"<<id;
    }
  }
  else {
    setError(query.lastError().text());
  }
  return result;
}

QStringList Azahar::getProductsList()
{
  QStringList result; result.clear();
  QSqlQuery query(db);
  if (query.exec("select name from products;")) {
    while (query.next()) {
      int fieldText = query.record().indexOf("name");
      QString text = query.value(fieldText).toString();
      result.append(text);
    }
  }
  else {
    setError(query.lastError().text());
  }
  return result;
}


bool Azahar::insertProduct(ProductInfo info)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);

  //some buggy info can cause troubles.
  bool groupValueOK = false;
  bool rawValueOK = false;
  if (info.isAGroup == 0 || info.isAGroup == 1) groupValueOK=true;
  if (info.isARawProduct == 0 || info.isARawProduct == 1) rawValueOK=true;
  if (!groupValueOK) info.isAGroup = 0;
  if (!rawValueOK) info.isARawProduct = 0;

  info.taxmodelid = 1; ///FIXME: Delete this code when taxmodels are added, for now, insert default one.

  if (info.hasUnlimitedStock)
      info.stockqty = 1; //for not showing "Not Available" in the product delegate.
  
  query.prepare("INSERT INTO products (code, name, price, stockqty, cost, soldunits, datelastsold, units, taxpercentage, extrataxes, photo, department, category, subcategory, points, alphacode, vendorcode, lastproviderid, isARawProduct,isAGroup, groupElements, groupPriceDrop, taxmodel, hasUnlimitedStock, isNotDiscountable ) VALUES (:code, :name, :price, :stock, :cost, :soldunits, :lastgetld, :units, :tax1, :tax2, :photo, :department, :category, :subcategory, :points, :alphacode, :vendorcode, :lastproviderid, :isARaw, :isAGroup, :groupE, :groupPriceDrop, :taxmodel, :unlimitedStock, :NonDiscountable);");
  query.bindValue(":code", info.code);
  query.bindValue(":name", info.desc);
  query.bindValue(":price", info.price);
  query.bindValue(":stock", info.stockqty);
  query.bindValue(":cost", info.cost);
  query.bindValue(":soldunits", 0);
  query.bindValue(":lastsold", "0000-00-00");
  query.bindValue(":units", info.units);
  query.bindValue(":tax1", info.tax);
  query.bindValue(":tax2", info.extratax);
  query.bindValue(":photo", info.photo);
  query.bindValue(":department", info.department);
  query.bindValue(":category", info.category);
  query.bindValue(":subcategory", info.subcategory);
  query.bindValue(":points", info.points);
  query.bindValue(":alphacode", info.alphaCode);
  query.bindValue(":vendorcode", info.vendorCode);
  query.bindValue(":lastproviderid", info.lastProviderId);
  query.bindValue(":isAGroup", info.isAGroup);
  query.bindValue(":isARaw", info.isARawProduct);
  query.bindValue(":groupE", info.groupElementsStr);
  query.bindValue(":groupPriceDrop", info.groupPriceDrop);
  query.bindValue(":taxmodel", info.taxmodelid); //for later use
  query.bindValue(":unlimitedStock", info.hasUnlimitedStock);
  query.bindValue(":NonDiscountable", info.isNotDiscountable);

  if (!query.exec()) setError(query.lastError().text()); else result=true;

  /** @note & TODO: Document this for the user.
   *                If the new product's code is reused, and a discount exists in the offers table, it will be deleted.
   **/
  
  QSqlQuery queryX(db);
  if (queryX.exec(QString("Select id from offers where product_id=%1").arg(info.code) )) {
    while (queryX.next()) {
      int fieldId    = queryX.record().indexOf("id");
      qulonglong oId = queryX.value(fieldId).toULongLong();
      deleteOffer(oId);
      qDebug()<<" **WARNING** Deleting Existing Offer for the new Product";
    }
  }
  
  return result;
}


bool Azahar::updateProduct(ProductInfo info, qulonglong oldcode)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  
  //some buggy info can cause troubles.
  bool groupValueOK = false;
  bool rawValueOK = false;
  if (info.isAGroup == 0 || info.isAGroup == 1) groupValueOK=true;
  if (info.isARawProduct == 0 || info.isARawProduct == 1) rawValueOK=true;
  if (!groupValueOK) info.isAGroup = 0;
  if (!rawValueOK) info.isARawProduct = 0;

  /// TODO FIXME: Remove the next line when taxmodels are implemented
  info.taxmodelid = 1;

  if (info.hasUnlimitedStock)
      info.stockqty = 1; //for not showing "Not Available" in the product delegate.
  
  //query.prepare("UPDATE products SET code=:newcode, photo=:photo, name=:name, price=:price, stockqty=:stock, cost=:cost, units=:measure, taxpercentage=:tax1, extrataxes=:tax2, category=:category, points=:points, alphacode=:alphacode, lastproviderid=:lastproviderid , isARawProduct=:isRaw, isAGroup=:isGroup, groupElements=:ge, groupPriceDrop=:groupPriceDrop WHERE code=:id");
  ///TODO: remove the taxpercentage and extrataxes when taxmodel is implemented
  query.prepare("UPDATE products SET \
  code=:newcode, \
  name=:name, \
  price=:price, \
  cost=:cost, \
  stockqty=:stock, \
  units=:measure, \
  taxpercentage=:tax1,\
  extrataxes=:tax2,\
  taxmodel=:taxmodel, \
  photo=:photo, \
  category=:category, \
  department=:department, \
  subcategory=:subcategory, \
  points=:points, \
  alphacode=:alphacode, \
  vendorcode=:vendorcode, \
  lastproviderid=:lastproviderid, \
  isARawProduct=:isRaw, \
  isAGroup=:isGroup, \
  groupElements=:ge, \
  groupPriceDrop=:groupPriceDrop, \
  isNotDiscountable=:NonDiscountable, \
  hasUnlimitedStock=:unlimitedStock \
  WHERE code=:id;");
  
  query.bindValue(":newcode", info.code);
  query.bindValue(":name", info.desc);
  query.bindValue(":price", info.price);
  query.bindValue(":stock", info.stockqty);
  query.bindValue(":cost", info.cost);
  query.bindValue(":measure", info.units);
  query.bindValue(":tax1", info.tax);
  query.bindValue(":tax2", info.extratax);
  query.bindValue(":photo", info.photo);
  query.bindValue(":department", info.department);
  query.bindValue(":category", info.category);
  query.bindValue(":subcategory", info.subcategory);
  query.bindValue(":points", info.points);
  query.bindValue(":id", oldcode);
  query.bindValue(":alphacode", info.alphaCode);
  query.bindValue(":vendorcode", info.vendorCode);
  query.bindValue(":lastproviderid", info.lastProviderId);
  query.bindValue(":isGroup", info.isAGroup);
  query.bindValue(":isRaw", info.isARawProduct);
  query.bindValue(":ge", info.groupElementsStr);
  query.bindValue(":groupPriceDrop", info.groupPriceDrop);
  query.bindValue(":taxmodel", info.taxmodelid);
  query.bindValue(":unlimitedStock", info.hasUnlimitedStock);
  query.bindValue(":NonDiscountable", info.isNotDiscountable);

  if (!query.exec()) setError(query.lastError().text()); else result=true;
  return result;
}

bool Azahar::decrementProductStock(qulonglong code, double qty, QDate date)
{
  bool result = false;
  double qtys=qty;
  double nqty = 0;
  if (!db.isOpen()) db.open();

  ProductInfo p = getProductInfo( QString::number(code) );
  if ( p.hasUnlimitedStock )
      nqty = 0; //not let unlimitedStock products to be decremented.
  else
      nqty = qty;
  // nqty is the qty to ADD or DEC, qtys is the qty to ADD_TO_SOLD_UNITS only.
   
  QSqlQuery query(db);
  query.prepare("UPDATE products SET datelastsold=:dateSold , stockqty=stockqty-:qty , soldunits=soldunits+:qtys WHERE code=:id");
  query.bindValue(":id", code);
  query.bindValue(":qty", nqty);
  query.bindValue(":qtys", qtys);
  query.bindValue(":dateSold", date.toString("yyyy-MM-dd"));
  if (!query.exec()) setError(query.lastError().text()); else result=true;
  //qDebug()<<"DECREMENT Product Stock  -- Rows Affected:"<<query.numRowsAffected();
  return result;
}

bool Azahar::decrementGroupStock(qulonglong code, double qty, QDate date)
{
  bool result = true;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);

  ProductInfo info = getProductInfo(QString::number(code));
  QStringList lelem = info.groupElementsStr.split(",");
  foreach(QString ea, lelem) {
    qulonglong c = ea.section('/',0,0).toULongLong();
    double     q = ea.section('/',1,1).toDouble();
    //ProductInfo pi = getProductInfo(QString::number(c));
    //FOR EACH ELEMENT, DECREMENT PRODUCT STOCK
    result = result && decrementProductStock(c, q*qty, date);
  }
  
  return result;
}

/// WARNING: This method is DECREMENTING soldunits... not used in lemonview.cpp nor squeezeview.cpp !!!!!
///          Do not use when doing PURCHASES in squeeze!
bool Azahar::incrementProductStock(qulonglong code, double qty)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  double qtys=qty;
  double nqty=0;

  ProductInfo p = getProductInfo( QString::number(code) );
  if ( p.hasUnlimitedStock )
      nqty = 0; //not let unlimitedStock products to be decremented.
  else
      nqty = qty;
  // nqty is the qty to ADD or DEC, qtys is the qty to ADD_TO_SOLD_UNITS only.

  query.prepare("UPDATE products SET stockqty=stockqty+:qty , soldunits=soldunits-:qtys WHERE code=:id");
  query.bindValue(":id", code);
  query.bindValue(":qty", nqty);
  query.bindValue(":qtys", qtys);
  if (!query.exec()) setError(query.lastError().text()); else result=true;
  //qDebug()<<"Increment Stock - Rows:"<<query.numRowsAffected();
  return result;
}

/// WARNING: This method is DECREMENTING soldunits... not used in lemonview.cpp nor squeezeview.cpp !!!!!
///          Do not use when doing PURCHASES in squeeze!
bool Azahar::incrementGroupStock(qulonglong code, double qty)
{
  bool result = true;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  
  ProductInfo info = getProductInfo(QString::number(code));
  QStringList lelem = info.groupElementsStr.split(",");
  foreach(QString ea, lelem) {
    qulonglong c = ea.section('/',0,0).toULongLong();
    double     q = ea.section('/',1,1).toDouble();
    //ProductInfo pi = getProductInfo(c);
    //FOR EACH ELEMENT, DECREMENT PRODUCT STOCK
    result = result && incrementProductStock(c, q*qty);
  }
  
  return result;
}


bool Azahar::deleteProduct(qulonglong code)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query = QString("DELETE FROM products WHERE code=%1").arg(code);
  if (!query.exec()) setError(query.lastError().text()); else result=true;

  /** @note & TODO: Document this for the user.
   *                If a discount exists in the offers table for the deleted product, the offer will be deleted also.
   **/
  
  QSqlQuery queryX(db);
  if (queryX.exec(QString("Select id from offers where product_id=%1").arg(code) )) {
    while (queryX.next()) {
      int fieldId    = queryX.record().indexOf("id");
      qulonglong oId = queryX.value(fieldId).toULongLong();
      deleteOffer(oId);
      qDebug()<<" **NOTE** Deleting Existing Offer for the deleted Product";
    }
  }
  
  return result;
}

double Azahar::getProductDiscount(qulonglong code, bool isGroup)
{
  double result = 0.0;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery query2(db);
    
    ProductInfo p = getProductInfo( QString::number(code) );
    if ( p.isNotDiscountable )
        return 0.0;
            
    QString qry = QString("SELECT * FROM offers WHERE product_id=%1").arg(code);
    if (!query2.exec(qry)) { setError(query2.lastError().text()); }
    else {
      QList<double> descuentos; descuentos.clear();
      while (query2.next())
      {
        int fieldDisc = query2.record().indexOf("discount");
        int fieldDateStart = query2.record().indexOf("datestart");
        int fieldDateEnd   = query2.record().indexOf("dateend");
        double descP= query2.value(fieldDisc).toDouble();
        QDate dateStart = query2.value(fieldDateStart).toDate();
        QDate dateEnd   = query2.value(fieldDateEnd).toDate();
        QDate now = QDate::currentDate();
        //See if the offer is in a valid range...
        if (isGroup) descuentos.append(descP);
        else if ((dateStart<dateEnd) && (dateStart<=now) && (dateEnd>=now)  ) {
          //save all discounts here and decide later to return the bigger valid discount.
          descuentos.append(descP);
        }
      }
      //now which is the bigger valid discount?
      qSort(descuentos.begin(), descuentos.end(), qGreater<int>());
      if (!descuentos.isEmpty()) {
        //get the first item, which is the greater one.
        result = descuentos.first(); ///returns the discount percentage!
      } else result = 0;
    }
  } else { setError(db.lastError().text()); }
  return result;
}

QList<pieProdInfo> Azahar::getTop5SoldProducts()
{
  QList<pieProdInfo> products; products.clear();
  pieProdInfo info;
  QSqlQuery query(db);
  if (query.exec("SELECT name,soldunits,units,code FROM products WHERE (soldunits>0 AND isARawProduct=false) ORDER BY soldunits DESC LIMIT 5")) {
    while (query.next()) {
      int fieldName  = query.record().indexOf("name");
      int fieldUnits = query.record().indexOf("units");
      int fieldSoldU = query.record().indexOf("soldunits");
      int fieldCode  = query.record().indexOf("code");
      int unit       = query.value(fieldUnits).toInt();
      info.name    = query.value(fieldName).toString();
      info.count   = query.value(fieldSoldU).toDouble();
      info.unitStr = getMeasureStr(unit);
      info.code    = query.value(fieldCode).toULongLong();
      products.append(info);
    }
  }
  else {
    setError(query.lastError().text());
  }
  return products;
}

double Azahar::getTopFiveMaximum()
{
  double result = 0;
  QSqlQuery query(db);
  if (query.exec("SELECT soldunits FROM products WHERE (soldunits>0 AND isARawProduct=false) ORDER BY soldunits DESC LIMIT 5")) {
    if (query.first()) {
      int fieldSoldU = query.record().indexOf("soldunits");
      result   = query.value(fieldSoldU).toDouble();
    }
  }
  else {
    setError(query.lastError().text());
  }
  return result;
}

double Azahar::getAlmostSoldOutMaximum(int max)
{
double result = 0;
  QSqlQuery query(db);
  if (query.exec(QString("SELECT stockqty FROM products WHERE (isARawProduct=false  AND isAGroup=false AND stockqty<=%1) ORDER BY stockqty DESC LIMIT 5").arg(max))) {
    if (query.first()) {
      int fieldSoldU = query.record().indexOf("stockqty");
      result   = query.value(fieldSoldU).toDouble();
    }
  }
  else {
    setError(query.lastError().text());
  }
  return result;
}

QList<pieProdInfo> Azahar::getAlmostSoldOutProducts(int max)
{
  QList<pieProdInfo> products; products.clear();
  pieProdInfo info;
  QSqlQuery query(db);
  //NOTE: Check lower limit for the soldunits range...
  query.prepare("SELECT name,stockqty,units,code FROM products WHERE (isARawProduct=false AND isAGroup=false AND stockqty<=:maxV) ORDER BY stockqty ASC LIMIT 5");
  query.bindValue(":maxV", max);
//   query.bindValue(":minV", min);
  if (query.exec()) {
    while (query.next()) {
      int fieldName  = query.record().indexOf("name");
      int fieldUnits = query.record().indexOf("units");
      int fieldStock = query.record().indexOf("stockqty");
      int fieldCode  = query.record().indexOf("code");
      int unit       = query.value(fieldUnits).toInt();
      info.name    = query.value(fieldName).toString();
      info.count   = query.value(fieldStock).toDouble();
      info.code    = query.value(fieldCode).toULongLong();
      info.unitStr = getMeasureStr(unit);
      products.append(info);
    }
  }
  else {
    setError(query.lastError().text());
    qDebug()<<lastError();
  }
  return products;
}

//returns soldout products only if the product is NOT a group.
QList<ProductInfo> Azahar::getSoldOutProducts()
{
  QList<ProductInfo> products; products.clear();
  ProductInfo info;
  QSqlQuery query(db);
  query.prepare("SELECT code FROM products WHERE stockqty=0 and isAgroup=false ORDER BY code ASC;");
  if (query.exec()) {
    while (query.next()) {
      int fieldCode  = query.record().indexOf("code");
      info = getProductInfo(query.value(fieldCode).toString());
      products.append(info);
    }
  }
  else {
    setError(query.lastError().text());
    qDebug()<<lastError();
  }
  return products;
}

//also discard group products. and unlimited stock ones...
QList<ProductInfo> Azahar::getLowStockProducts(double min)
{
  QList<ProductInfo> products; products.clear();
  ProductInfo info;
  QSqlQuery query(db);
  query.prepare("SELECT code FROM products WHERE (stockqty<=:minV and stockqty>1 and isAGroup=false and hasUnlimitedStock=false) ORDER BY code,stockqty ASC;");
  query.bindValue(":minV", min);
  if (query.exec()) {
    while (query.next()) {
      int fieldCode  = query.record().indexOf("code");
      info = getProductInfo(query.value(fieldCode).toString());
      products.append(info);
    }
  }
  else {
    setError(query.lastError().text());
    qDebug()<<lastError();
  }
  return products;
}

//The list will not include groups or packages
QList<ProductInfo> Azahar::getAllProducts()
{
    QList<ProductInfo> products; products.clear();
    ProductInfo info;
    QSqlQuery query(db);
    query.prepare("SELECT code,stockqty FROM products WHERE isAGroup=false ORDER BY code,stockqty ASC;");
    if (query.exec()) {
        while (query.next()) {
            int fieldCode  = query.record().indexOf("code");
            info = getProductInfo(query.value(fieldCode).toString());
            products.append(info);
        }
    }
    else {
        setError(query.lastError().text());
        qDebug()<<lastError();
    }
    return products;
}

qulonglong Azahar::getLastProviderId(qulonglong code)
{
  qulonglong result = 0;
  QSqlQuery query(db);
  query.prepare("SELECT lastproviderid FROM products WHERE code=:code");
  query.bindValue(":code", code);
  if (query.exec()) {
    while (query.next()) {
      int fieldProv  = query.record().indexOf("lastproviderid");
      result         = query.value(fieldProv).toULongLong();
    }
  }
  else {
    setError(query.lastError().text());
    qDebug()<<lastError();
  }
  return result;
}

bool Azahar::updateProductLastProviderId(qulonglong code, qulonglong provId)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query.prepare("UPDATE products SET lastproviderid=:provid WHERE code=:id");
  query.bindValue(":id", code);
  query.bindValue(":provid", provId);
  if (!query.exec()) setError(query.lastError().text()); else result=true;
  qDebug()<<"Rows Affected:"<<query.numRowsAffected();
  return result;
}

QList<ProductInfo> Azahar::getGroupProductsList(qulonglong id, bool notConsiderDiscounts)
{
  //qDebug()<<"getGroupProductsList...";
  QList<ProductInfo> pList;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QString ge = getProductGroupElementsStr(id); //DONOT USE getProductInfo... this will cause an infinite loop because at that method this method is called trough getGroupAverageTax
    //qDebug()<<"elements:"<<ge;
    if (ge.isEmpty()) return pList;
    QStringList pq = ge.split(",");
    foreach(QString str, pq) {
      qulonglong c = str.section('/',0,0).toULongLong();
      double     q = str.section('/',1,1).toDouble();
      //get info
      ProductInfo pi = getProductInfo(QString::number(c), notConsiderDiscounts);
      pi.qtyOnList = q;
      pList.append(pi);
      //qDebug()<<" code:"<<c<<" qty:"<<q;
    }
  }
  return pList;
}

//NOTE: This method just get the average tax, it does not make any other calculation.
//      When all the products in the group has a same tax rate, the average tax is the same and
//      tax in money for the group is fine (not unbalanced), but when is not the same and the difference is much
//      then the average tax would have an impact, For example:
//      A group with TWO products :
//         product 1: Price: 10, tax:15%
//         product 2: Price  100, tax 1%
//     The average tax is 8%, its equally for the two products but the second one has a lower tax.
//     The tax charged to the group with the average tax is $8.8
//     The tax charged to the group with each product tax is $2.15
//     So the tax is not fine in this case. This means this method is not accurate for all cases.
// DEPRECATED
/*
double Azahar::getGroupAverageTax(qulonglong id)
{
  qDebug()<<"Getting averate tax for id:"<<id;
  double result = 0;
  double sum = 0;
  QList<ProductInfo> pList = getGroupProductsList(id);
  foreach( ProductInfo info, pList) {
    sum += info.tax + info.extratax;
    ///sum += getTotalTaxPercent(info.taxElements);  FOR when taxmodels are implemented
  }
  
  result = sum/pList.count();
  qDebug()<<"Group average tax: "<<result <<" sum:"<<sum<<" count:"<<pList.count();
  
  return result;
}
*/

/*DEPRECATED double Azahar::getGroupTotalTax(qulonglong id)
{
  qDebug()<<"Getting total tax for id:"<<id;
  double result = 0;
  double sum = 0;
  QList<ProductInfo> pList = getGroupProductsList(id);
  foreach( ProductInfo info, pList) {
    sum += info.tax + info.extratax;
  }
  
  result = sum;
  qDebug()<<" TOTAL tax:"<<sum;
  
  return result;
}*/

//This method replaces the two above deprecated methods.
///NOTE: Aug 17 2011: this tax does not take into account the ocassional discounts or price changes. It may be false.
GroupInfo Azahar::getGroupPriceAndTax(ProductInfo pi)
{
  GroupInfo gInfo;
  gInfo.price = 0;
  gInfo.taxMoney = 0;
  gInfo.tax = 0;
  gInfo.cost = 0;
  gInfo.count = 0;
  gInfo.priceDrop = pi.groupPriceDrop;
  gInfo.name = pi.desc;
  
  if ( pi.code <= 0 ) return gInfo;

  QList<ProductInfo> plist = getGroupProductsList(pi.code, true); //for getting products with taxes not including discounts.
  foreach(ProductInfo info, plist) {
    info.price      = (info.price -info.price*(pi.groupPriceDrop/100));
    info.totaltax   = info.price * info.qtyOnList *  (info.tax/100) + info.price * info.qtyOnList *  (info.extratax/100);
    
    gInfo.price    += info.price * info.qtyOnList;
    gInfo.cost     += info.cost  * info.qtyOnList;
    gInfo.taxMoney += info.totaltax*info.qtyOnList;
    gInfo.count    += info.qtyOnList;
    bool yes = false;
    if (info.stockqty >= info.qtyOnList ) yes = true;
    gInfo.isAvailable = (gInfo.isAvailable && yes );
    qDebug()<<" < GROUP - EACH ONE > Product: "<<info.desc<<" Price with p-drop: "<<info.price<<" taxMoney: "<<info.totaltax*info.qtyOnList<<" info.tax:"<<info.tax<<" info.extataxes:"<<info.extratax;
    gInfo.productsList.insert( info.code, info );
  }

  foreach(ProductInfo info, gInfo.productsList) {
    gInfo.tax += (info.totaltax*info.qtyOnList/gInfo.price)*100;
    qDebug()<<" < GROUP TAX >  qtyOnList:"<<info.qtyOnList<<" tax money for product: "<<info.totaltax<<" group price:"<<gInfo.price<<" taxMoney for group:"<<gInfo.taxMoney<<" tax % for group:"<< gInfo.tax<<" Group cost:"<<gInfo.cost;
  }

  return gInfo;
}

QString Azahar::getProductGroupElementsStr(qulonglong id)
{
  QString result;
  if (db.isOpen()) {
    QString qry = QString("SELECT groupElements from products WHERE code=%1").arg(id);
    QSqlQuery query(db);
    if (!query.exec(qry)) {
      int errNum = query.lastError().number();
      QSqlError::ErrorType errType = query.lastError().type();
      QString error = query.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),error);
    }
    if (query.size() <= 0)
      setError(i18n("Error serching product id %1, Rows affected: %2", id,query.size()));
    else {
      while (query.next()) {
        int field = query.record().indexOf("groupElements");
        result    = query.value(field).toString();
      }
    }
  }
  return result;
}

void Azahar::updateGroupPriceDrop(qulonglong code, double pd)
{
  if (db.isOpen()) {
    QSqlQuery query(db);
    query.prepare("UPDATE products SET groupPriceDrop=:pdrop WHERE code=:id");
    query.bindValue(":id", code);
    query.bindValue(":pdrop", pd);
    if (!query.exec()) setError(query.lastError().text());
    qDebug()<<"<*> updateGroupPriceDrop  | Rows Affected:"<<query.numRowsAffected();
  }
}

void Azahar::updateGroupElements(qulonglong code, QString elementsStr)
{
  if (db.isOpen()) {
    QSqlQuery query(db);
    query.prepare("UPDATE products SET groupElements=:elements WHERE code=:id");
    query.bindValue(":id", code);
    query.bindValue(":elements", elementsStr);
    if (!query.exec()) setError(query.lastError().text());
    qDebug()<<"<*> updateGroupElements  | Rows Affected:"<<query.numRowsAffected();
  }
}


//Bundles
QList<BundleInfo> Azahar::getBundleInfo(qulonglong productId)
{
    QList<BundleInfo> list;
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
        QSqlQuery query(db);
        query.prepare("SELECT * from bundle_same WHERE product_id=:pid");
        query.bindValue(":pid", productId);
        if (!query.exec()) {setError(query.lastError().text()); qDebug()<<"<*> ERROR: "<<query.lastError();}
        else {
            while (query.next()) {
                int fieldQty  = query.record().indexOf("qty");
                int fieldPrice= query.record().indexOf("price");
                BundleInfo info;
                info.product_id = productId;
                info.price      = query.value(fieldPrice).toDouble();
                info.qty        = query.value(fieldQty).toDouble();
                list << info;
            }
        }
        
    }
    return list;
}

BundleInfo Azahar::getMaxBundledForProduct(qulonglong pId)
{
    BundleInfo result;
    result.product_id = pId;
    result.qty = 0;
    result.price = 0;
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
        QSqlQuery query(db);
        query.prepare("SELECT * from bundle_same WHERE product_id=:pid ORDER BY qty DESC LIMIT 1");
        query.bindValue(":pid", pId);
        if (!query.exec()) {setError(query.lastError().text()); qDebug()<<"<*> ERROR: "<<query.lastError();}
        else {
            while (query.next()) {
                int fieldQty  = query.record().indexOf("qty");
                int fieldPrice= query.record().indexOf("price");
                result.price      = query.value(fieldPrice).toDouble();
                result.qty        = query.value(fieldQty).toDouble();
            }
        }
        
    }
    return result;
}

double Azahar::getBundlePriceFor(qulonglong pId)
{
    double result = 0;
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
        QSqlQuery query(db);
        query.prepare("SELECT price from bundle_same WHERE product_id=:pid");
        query.bindValue(":pid", pId);
        if (!query.exec()) {setError(query.lastError().text()); qDebug()<<"<*> ERROR: "<<query.lastError();}
        else {
            while (query.next()) {
                int fieldPrice= query.record().indexOf("price");
                result        = query.value(fieldPrice).toDouble();
            }
        }
        
    }
    return result;
}

//DEPARTMENTS
bool Azahar::insertDepartment(QString text)
{
    bool result=false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("INSERT INTO departments (text) VALUES (:text);");
    query.bindValue(":text", text);
    if (!query.exec())
        setError(query.lastError().text());
    else
        result = true;
    
    return result;
}

bool Azahar::updateDepartment(qulonglong id, QString t)
{
    bool result=false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("UPDATE departments set text=:text WHERE id=:id;");
    query.bindValue(":text", t);
    query.bindValue(":id", id);
    if (!query.exec()) {
        setError(query.lastError().text());
        qDebug()<<"ERROR:"<<query.lastError().text();
    }
        
    else
        result = true;
    
    return result;
}

QHash<QString, int> Azahar::getDepartmentsHash()
{
    QHash<QString, int> result;
    result.clear();
    if (!db.isOpen()) db.open();
    //if (db.isOpen()) {
        QSqlQuery myQuery(db);
        if (myQuery.exec("select * from departments;")) {
            while (myQuery.next()) {
                int fieldId   = myQuery.record().indexOf("id");
                int fieldText = myQuery.record().indexOf("text");
                int id = myQuery.value(fieldId).toInt();
                QString text = myQuery.value(fieldText).toString();
                result.insert(text, id);
            }
        }
        else {
            qDebug()<<"ERROR: "<<myQuery.lastError();
        }
    //}
    return result;
}

QStringList Azahar::getDepartmentsList()
{
    QStringList result;
    result.clear();
    if (!db.isOpen()) db.open();
    //if (db.isOpen()) {
        QSqlQuery myQuery(db);
        if (myQuery.exec("select text from departments;")) {
            while (myQuery.next()) {
                int fieldText = myQuery.record().indexOf("text");
                QString text = myQuery.value(fieldText).toString();
                result.append(text);
            }
        }
        else {
            qDebug()<<"ERROR: "<<myQuery.lastError();
        }
    //}
    return result;
}

qulonglong Azahar::getDepartmentId(QString texto)
{
    qulonglong result=0;
    if (!db.isOpen()) db.open();
    //if (db.isOpen()) {
        QSqlQuery myQuery(db);
        QString qryStr = QString("SELECT departments.id FROM departments WHERE text='%1';").arg(texto);
        if (myQuery.exec(qryStr) ) {
            while (myQuery.next()) {
                int fieldId   = myQuery.record().indexOf("id");
                qulonglong id= myQuery.value(fieldId).toULongLong();
                result = id;
            }
        }
        else {
            setError(myQuery.lastError().text());
        }
    //}
    return result;
}

QString Azahar::getDepartmentStr(qulonglong id)
{
    QString result;
    QSqlQuery query(db);
    QString qstr = QString("select text from departments where id=%1;").arg(id);
    if (query.exec(qstr)) {
        while (query.next()) {
            int fieldText = query.record().indexOf("text");
            result = query.value(fieldText).toString();
        }
    }
    else {
        setError(query.lastError().text());
    }
    return result;
}

bool Azahar::deleteDepartment(qulonglong id)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query = QString("DELETE FROM departments WHERE departments.id=%1").arg(id);
    if (!query.exec()) setError(query.lastError().text()); else result=true;
    qDebug()<<"DEPARTMENT "<<id<<" DELETED:"<<result;
    
    //Now, delete any m2m relation for the category...

    //NOTE: What to do here, delete relations or leave it as they are and let responsibility to the administrator to fix incoherences?
    //qDebug()<<"IF THE DELETED DEPARTMENT HAS CHILD CATEGORIES, THEN YOU MUST FIX MANUALLY THE INCONSISTENCE. WE ARE GOING TO LEAVE ORPHAN CATEGORIES, INSTEAD OF DELETE THEM.";
    //NOTE: Or delete the links? I think doing this is not dangerous because we are not deleting the categories itself, only the links between dep->cat.
    //      if the categories had only this links then the categories will be orphans.
    
    QSqlQuery queryX(db);
    queryX.prepare("DELETE FROM m2m_department_category WHERE department=:id");
    queryX.bindValue(":id", id);
    bool m2mOK = queryX.exec();
    result = (result && m2mOK);
    if (!m2mOK) setError(query.lastError().text());
    qDebug()<<" --> M2M Relation for department_category DELETED:"<<m2mOK;
    
    return result;
}

bool Azahar::m2mDepartmentCategoryExists(qulonglong d, qulonglong c)
{
    bool result = false;
    QSqlQuery query(db);
    QString qstr = QString("select * from m2m_department_category where department=%1 and category=%2;").arg(d).arg(c);
    if (query.exec(qstr)) {
        while (query.next()) {
            int fieldD = query.record().indexOf("department");
            int fieldC = query.record().indexOf("category");
            if ( query.value(fieldD).toULongLong() == d && query.value(fieldC).toULongLong() == c )
                return true;
        }
    }
    else {
        setError(query.lastError().text());
    }
    return result;
}

bool Azahar::m2mDepartmentCategoryRemove(qulonglong d, qulonglong c)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery queryX(db);
    queryX.prepare("DELETE FROM m2m_department_category WHERE department=:dep AND category=:cat;");
    queryX.bindValue(":dep", d);
    queryX.bindValue(":cat", c);
    result = queryX.exec();
    if (!result) {
        qDebug()<<"ERROR REMOVING CONNECTION BETWEEN DEP->CAT:"<<d<<"->"<<c<<" |"<<queryX.lastError().text();
        setError(queryX.lastError().text());
    }
    return result;
}

bool Azahar::insertM2MDepartmentCategory(qulonglong depId, qulonglong catId)
{
    bool result=false;
    if (!db.isOpen()) db.open();
    //first, check if the department->category already exists.
    if ( m2mDepartmentCategoryExists(depId, catId) ) {
        qDebug()<<"m2m Department -> Category Already exists!";
        return false;
    }
    //ok it does not exists, create the connection.    
    QSqlQuery query(db);
    query.prepare("INSERT INTO m2m_department_category (department, category) VALUES (:dep, :cat);");
    query.bindValue(":dep", depId);
    query.bindValue(":cat", catId);
    if (!query.exec()) {
        setError(query.lastError().text());
        qDebug()<<"Error inserting m2m_department_category: "<<query.lastError().text();
        result = false;
    }
    else 
        result = true;
   return result;
}

//CATEGORIES
bool Azahar::insertCategory(QString text)
{
  bool result=false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query.prepare("INSERT INTO categories (text) VALUES (:text);");
  query.bindValue(":text", text);
  if (!query.exec()) 
    setError(query.lastError().text());
  else
    result = true;
//   else {
//       //get the newly created category id.
//       qulonglong cId = getCategoryId(text);
//       QSqlQuery queryB(db);
//       //Now, insert the m2m relation, indicated by parent.
//       queryB.prepare("INSERT INTO m2m_department_category (department, category) VALUES(:dep, :cat);");
//       queryB.bindValue(":dep", parent);
//       queryB.bindValue(":cat", cId);
//       
//       result = queryB.exec();
//       qDebug()<<"INSERTED CATEGORY OK, INSERTING m2m_department_category:"<<result;
//   }
  
  return result;
}

bool Azahar::updateCategory(qulonglong id, QString t)
{
    bool result=false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("UPDATE categories set text=:text WHERE catid=:id;");
    query.bindValue(":text", t);
    query.bindValue(":id", id);
    if (!query.exec()) {
        setError(query.lastError().text());
        qDebug()<<"ERROR:"<<query.lastError().text();
    }
    
    else
        result = true;
    
    return result;
}

QHash<QString, int> Azahar::getCategoriesHash()
{
  QHash<QString, int> result;
  result.clear();
  if (!db.isOpen()) db.open();
  //if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec("select * from categories;")) {
      while (myQuery.next()) {
        int fieldId   = myQuery.record().indexOf("catid");
        int fieldText = myQuery.record().indexOf("text");
        int id = myQuery.value(fieldId).toInt();
        QString text = myQuery.value(fieldText).toString();
        result.insert(text, id);
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  //}
  return result;
}

QStringList Azahar::getCategoriesList()
{
  QStringList result;
  result.clear();
  if (!db.isOpen()) db.open();
  //if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec("select text from categories;")) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("text");
        QString text = myQuery.value(fieldText).toString();
        result.append(text);
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  //}
  return result;
}

qulonglong Azahar::getCategoryId(QString texto)
{
  qulonglong result=0;
  if (!db.isOpen()) db.open();
  //if (db.isOpen()) {
    QSqlQuery myQuery(db);
    QString qryStr = QString("SELECT categories.catid FROM categories WHERE text='%1';").arg(texto);
    if (myQuery.exec(qryStr) ) {
      while (myQuery.next()) {
        int fieldId   = myQuery.record().indexOf("catid");
        qulonglong id= myQuery.value(fieldId).toULongLong();
        result = id;
      }
    }
    else {
      setError(myQuery.lastError().text());
    }
  //}
  return result;
}

QString Azahar::getCategoryStr(qulonglong id)
{
  QString result;
  QSqlQuery query(db);
  QString qstr = QString("select text from categories where catid=%1;").arg(id);
  if (query.exec(qstr)) {
    while (query.next()) {
      int fieldText = query.record().indexOf("text");
      result = query.value(fieldText).toString();
    }
  }
  else {
    setError(query.lastError().text());
  }
  return result;
}

bool Azahar::deleteCategory(qulonglong id)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query = QString("DELETE FROM categories WHERE catid=%1").arg(id);
  if (!query.exec()) setError(query.lastError().text()); else result=true;
  qDebug()<<"CATEGORY "<<id<<" DELETED:"<<result;
  
  //Now, delete any m2m relation for the subcategory...
  QSqlQuery queryX(db);
  queryX.prepare("DELETE FROM m2m_department_category WHERE category=:id");
  queryX.bindValue(":id", id);
  bool m2mOK = queryX.exec();
  result = (result && m2mOK);
  if (!m2mOK) setError(query.lastError().text());
  qDebug()<<" --> M2M Relation for department_category DELETED:"<<m2mOK;
  
  return result;
}

bool Azahar::m2mCategorySubcategoryExists(qulonglong c, qulonglong s)
{
    bool result = false;
    QSqlQuery query(db);
    QString qstr = QString("select * from m2m_category_subcategory where category=%1 and subcategory=%2;").arg(c).arg(s);
    if (query.exec(qstr)) {
        while (query.next()) {
            int fieldC = query.record().indexOf("category");
            int fieldS = query.record().indexOf("subcategory");
            if ( query.value(fieldC).toULongLong() == c && query.value(fieldS).toULongLong() == s )
                return true;
        }
    }
    else {
        setError(query.lastError().text());
    }
    return result;
}

bool Azahar::insertM2MCategorySubcategory(qulonglong catId, qulonglong subcatId)
{
    bool result=false;
    if (!db.isOpen()) db.open();
    //first, check if the category->subcategory already exists.
    if ( m2mCategorySubcategoryExists(catId, subcatId) ) {
        qDebug()<<"m2m Category -> subCategory Already exists!";
        return false;
    }
    //ok it does not exists, create the connection.
    QSqlQuery query(db);
    query.prepare("INSERT INTO m2m_category_subcategory (category, subcategory) VALUES (:cat, :subcat);");
    query.bindValue(":cat", catId);
    query.bindValue(":subcat", subcatId);
    if (!query.exec()) {
        setError(query.lastError().text());
        qDebug()<<"Error inserting m2m_category_subcategory: "<<query.lastError().text();
        result = false;
    }
    else
        result = true;
    return result;
}

bool Azahar::m2mCategorySubcategoryRemove(qulonglong c, qulonglong sc)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery queryX(db);
    queryX.prepare("DELETE FROM m2m_category_subcategory WHERE category=:cat AND subcategory=:scat;");
    queryX.bindValue(":cat", c);
    queryX.bindValue(":scat", sc);
    result = queryX.exec();
    if (!result) {
        qDebug()<<"ERROR REMOVING CONNECTION BETWEEN CAT->SUBCAT:"<<c<<"->"<<sc<<" |"<<queryX.lastError().text();
        setError(queryX.lastError().text());
    }
    return result;
}

//SUBCATEGORIES
QHash<QString, int> Azahar::getSubCategoriesHash()
{
    QHash<QString, int> result;
    result.clear();
    if (!db.isOpen()) db.open();
    //if (db.isOpen()) {
        QSqlQuery myQuery(db);
        if (myQuery.exec("select * from subcategories;")) {
            while (myQuery.next()) {
                int fieldId   = myQuery.record().indexOf("id");
                int fieldText = myQuery.record().indexOf("text");
                int id = myQuery.value(fieldId).toInt();
                QString text = myQuery.value(fieldText).toString();
                result.insert(text, id);
            }
        }
        else {
            qDebug()<<"ERROR: "<<myQuery.lastError();
        }
    //}
    return result;
}

QStringList Azahar::getSubCategoriesList()
{
    QStringList result;
    result.clear();
    //result.append(" --- ");
    if (!db.isOpen()) db.open();
    //if (db.isOpen()) { ///NOTE: I dont know why this is not working! it says is not open, but without this check it works. It fails when doing some cycling, like a subcategoryEditor inside a subcategoryEditor. The first work, the second does not...
        qDebug()<<"Getting subcategories list... db is ok";
        QSqlQuery myQuery(db);
        if (myQuery.exec("select * from subcategories;")) {
            while (myQuery.next()) {
                int fieldText = myQuery.record().indexOf("text");
                QString text = myQuery.value(fieldText).toString();
                result.append(text);
            }
        }
        else {
            qDebug()<<"ERROR: "<<myQuery.lastError();
        }
    //}
    return result;
}

QStringList Azahar::getCategoriesList(const qulonglong parent)
{
    QStringList result;
    result.clear();
    //result.append(" --- ");
    if (!db.isOpen()) db.open();
        QSqlQuery myQuery(db);
        QString queryTxt;
        if (parent == 0)
            queryTxt = QString("SELECT text FROM categories;"); //get all categories...
        else
            queryTxt = QString("SELECT \
            M2M.category AS M2M_CAT, C.text AS text \
            FROM categories AS C, m2m_department_category as M2M \
            WHERE M2M.department=%1 AND C.catid=M2M.category;").arg(parent);
        
        if (myQuery.exec(queryTxt)) {
            while (myQuery.next()) {
                int fieldText = myQuery.record().indexOf("text");
                QString text = myQuery.value(fieldText).toString();
                result.append(text);
            }
        }
        else {
            qDebug()<<"ERROR: "<<myQuery.lastError();
        }
        return result;
}

//This method gets the subcategories list for a parent category. If parent=0, returns all subcategories.
//NOTE & WARNING: when parent=0 also this could mean only return root categories. But we are not doing this here.
QStringList Azahar::getSubCategoriesList(qulonglong parent)
{
    QStringList result;
    result.clear();
    //result.append(" --- ");
    if (!db.isOpen()) db.open();
    //if (db.isOpen()) {
        QSqlQuery myQuery(db);
        QString queryTxt;
        if (parent == 0)
            queryTxt = QString("SELECT text FROM subcategories;"); //get all subcategories...
        else
            //queryTxt = QString("SELECT text FROM subcategories WHERE parent=%1;").arg(parent);
            queryTxt = QString("SELECT \
            M2M.subcategory AS M2M_SUBCAT, S.text AS text \
            FROM subcategories as S, m2m_category_subcategory as M2M \
            WHERE M2M.category=%1 AND S.id=M2M.subcategory;").arg(parent);
        
        if (myQuery.exec(queryTxt)) {
            while (myQuery.next()) {
                int fieldText = myQuery.record().indexOf("text");
                QString text = myQuery.value(fieldText).toString();
                result.append(text);
            }
        }
        else {
            qDebug()<<"ERROR: "<<myQuery.lastError();
        }
    //}
    return result;
}

bool Azahar::insertSubCategory(QString text)
{
    bool result=false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    //First, insert the category itself.
    query.prepare("INSERT INTO subcategories (text) VALUES (:text);");
    query.bindValue(":text", text);
    if (!query.exec()) 
        setError(query.lastError().text());
    else
        result = true;
//     else {
//         //get the newly created subcategory id.
//         qulonglong scId = getSubCategoryId(text);
//         QSqlQuery queryB(db);
//         //Now, insert the m2m relation, indicated by parent.
//         queryB.prepare("INSERT INTO m2m_category_subcategory (category, subcategory) VALUES(:cat, :sub);");
//         queryB.bindValue(":sub", scId);
//         queryB.bindValue(":cat", parent);
//         
//         result = queryB.exec();
//         qDebug()<<"INSERTED SUBCATEGORY OK, INSERTING m2m_category_subcategory:"<<result;
//     }
    
    return result;
}

qulonglong Azahar::getSubCategoryId(QString texto)
{
    qulonglong result=0;
    if (!db.isOpen()) db.open();
    //if (db.isOpen()) {
        QSqlQuery myQuery(db);
        QString qryStr = QString("SELECT subcategories.id FROM subcategories WHERE text='%1';").arg(texto);
        if (myQuery.exec(qryStr) ) {
            while (myQuery.next()) {
                int fieldId   = myQuery.record().indexOf("id");
                qulonglong id= myQuery.value(fieldId).toULongLong();
                result = id;
            }
        }
        else {
            setError(myQuery.lastError().text());
        }
    //}
    return result;
}

QString Azahar::getSubCategoryStr(qulonglong id)
{
    QString result = "";
    QSqlQuery query(db);
    QString qstr = QString("select text from subcategories where subcategories.id=%1;").arg(id);
    if (query.exec(qstr)) {
        while (query.next()) {
            int fieldText = query.record().indexOf("text");
            result = query.value(fieldText).toString();
        }
    }
    else {
        setError(query.lastError().text());
    }
    return result;
}

bool Azahar::deleteSubCategory(qulonglong id)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query = QString("DELETE FROM subcategories WHERE subcategories.id=%1").arg(id);
    if (!query.exec()) setError(query.lastError().text()); else result=true;
    qDebug()<<"SUBCATEGORY "<<id<<" DELETED:"<<result;

    //Now, delete any m2m relation for the subcategory...
    QSqlQuery queryX(db);
    queryX.prepare("DELETE FROM m2m_category_subcategory WHERE subcategory=:id");
    queryX.bindValue(":id", id);
    bool m2mOK = queryX.exec();
    result = (result && m2mOK);
    if (!m2mOK) setError(query.lastError().text());
    qDebug()<<" --> M2M Relation for category_subcategory DELETED:"<<m2mOK;
    
    return result;
}

//MEASURES
bool Azahar::insertMeasure(QString text)
{
  bool result=false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query.prepare("INSERT INTO measures (text) VALUES (:text);");
  query.bindValue(":text", text);
  if (!query.exec()) {
    setError(query.lastError().text());
  }
  else result=true;
  
  return result;
}

qulonglong Azahar::getMeasureId(QString texto)
{
  qulonglong result=0;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    QString qryStr = QString("select measures.id from measures where text='%1';").arg(texto);
    if (myQuery.exec(qryStr) ) {
      while (myQuery.next()) {
        int fieldId   = myQuery.record().indexOf("id");
        qulonglong id = myQuery.value(fieldId).toULongLong();
        result = id;
      }
    }
    else {
      setError(myQuery.lastError().text());
    }
  }
  return result;
}

QString Azahar::getMeasureStr(qulonglong id)
{
  QString result;
  QSqlQuery query(db);
  QString qstr = QString("select text from measures where measures.id=%1;").arg(id);
  if (query.exec(qstr)) {
    while (query.next()) {
      int fieldText = query.record().indexOf("text");
      result = query.value(fieldText).toString();
    }
  }
  else {
    setError(query.lastError().text());
  }
  return result;
}

QStringList Azahar::getMeasuresList()
{
  QStringList result;
  result.clear();
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec("select text from measures;")) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("text");
        QString text = myQuery.value(fieldText).toString();
        result.append(text);
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

bool Azahar::deleteMeasure(qulonglong id)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query = QString("DELETE FROM measures WHERE id=%1").arg(id);
  if (!query.exec()) setError(query.lastError().text()); else result=true;
  return result;
}

//OFFERS
bool Azahar::createOffer(OfferInfo info)
{
  bool result=false;
  QString qryStr;
  QSqlQuery query(db);
  if (!db.isOpen()) db.open();

  ProductInfo p = getProductInfo( QString::number(info.productCode) );
  if ( p.isNotDiscountable ) {
      setError(i18n("Unable to set an offer/discount for the selected produc because it is NOT DISCOUNTABLE"));
      return false;
  }
      
  
  //The product has no offer yet.
  //NOTE: Now multiple offers supported (to save offers history)
  qryStr = "INSERT INTO offers (discount, datestart, dateend, product_id) VALUES(:discount, :datestart, :dateend, :code)";
  query.prepare(qryStr);
  query.bindValue(":discount", info.discount );
  query.bindValue(":datestart", info.dateStart.toString("yyyy-MM-dd"));
  query.bindValue(":dateend", info.dateEnd.toString("yyyy-MM-dd"));
  query.bindValue(":code", info.productCode);
  if (query.exec()) result = true; else setError(query.lastError().text());

  return result;
}

bool Azahar::deleteOffer(qlonglong id)
{
  bool result=false;
  if (db.isOpen()) {
    QString qry = QString("DELETE from offers WHERE offers.id=%1").arg(id);
    QSqlQuery query(db);
    if (!query.exec(qry)) {
      int errNum = query.lastError().number();
      QSqlError::ErrorType errType = query.lastError().type();
      QString error = query.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),error);
    }
    if (query.numRowsAffected() == 1) result = true;
    else setError(i18n("Error deleting offer id %1, Rows affected: %2", id,query.numRowsAffected()));
  }
  return result;
}


QString Azahar::getOffersFilterWithText(QString text)
{
  QStringList codes;
  QString result="";
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery qry(db);
    QString qryStr= QString("SELECT P.code, P.name, O.product_id FROM offers AS O, products AS P WHERE P.code = O.product_id and P.name REGEXP '%1' ").arg(text);
    if (!qry.exec(qryStr)) setError(qry.lastError().text());
    else {
      codes.clear();
      while (qry.next()) {
        int fieldId   = qry.record().indexOf("code");
        qulonglong c = qry.value(fieldId).toULongLong();
        codes.append(QString("offers.product_id=%1 ").arg(c));
      }
      result = codes.join(" OR ");
    }
  }
  return result;
}

bool Azahar::moveOffer(qulonglong oldp, qulonglong newp)
{
  bool result=false;
  if (!db.isOpen()) db.open();
  QSqlQuery q(db);
  QString qs = QString("UPDATE offers SET product_id=%1 WHERE product_id=%2;").arg(newp).arg(oldp);
  if (!q.exec( qs )) setError(q.lastError().text()); else result = true;
  return result;
}


//USERS
bool Azahar::insertUser(UserInfo info)
{
  bool result=false;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO users (username, password, salt, name, address, phone, phone_movil, role, photo) VALUES(:uname, :pass, :salt, :name, :address, :phone, :cell, :rol, :photo)");
    query.bindValue(":photo", info.photo);
    query.bindValue(":uname", info.username);
    query.bindValue(":name", info.name);
    query.bindValue(":address", info.address);
    query.bindValue(":phone", info.phone);
    query.bindValue(":cell", info.cell);
    query.bindValue(":pass", info.password);
    query.bindValue(":salt", info.salt);
    query.bindValue(":rol", info.role);
    if (!query.exec()) setError(query.lastError().text()); else result = true;
    qDebug()<<"USER insert:"<<query.lastError();
    //FIXME: We must see error types, which ones are for duplicate KEYS (codes) to advertise the user.
  }//db open
  return result;
}

QHash<QString,UserInfo> Azahar::getUsersHash()
{
  QHash<QString,UserInfo> result;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery query(db);
    QString qry = "SELECT * FROM users;";
    if (query.exec(qry)) {
      while (query.next()) {
        int fielduId       = query.record().indexOf("id");
        int fieldUsername  = query.record().indexOf("username");
        int fieldPassword  = query.record().indexOf("password");
        int fieldSalt      = query.record().indexOf("salt");
        int fieldName      = query.record().indexOf("name");
        int fieldRole      = query.record().indexOf("role"); // see role numbers at enums.h
        int fieldPhoto     = query.record().indexOf("photo");
        //more fields, now im not interested in that...
        UserInfo info;
        info.id       = query.value(fielduId).toInt();
        info.username = query.value(fieldUsername).toString();
        info.password = query.value(fieldPassword).toString();
        info.salt     = query.value(fieldSalt).toString();
        info.name     = query.value(fieldName).toString();
        info.photo    = query.value(fieldPhoto).toByteArray();
        info.role     = query.value(fieldRole).toInt();
        result.insert(info.username, info);
        //qDebug()<<"got user:"<<info.username;
      }
    }
    else {
      qDebug()<<"**Error** :"<<query.lastError();
    }
  }
 return result;
}

UserInfo Azahar::getUserInfo(const qulonglong &userid)
{
  UserInfo info;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery query(db);
    QString qry = QString("SELECT * FROM users where id=%1;").arg(userid);
    if (query.exec(qry)) {
      while (query.next()) {
        int fielduId       = query.record().indexOf("id");
        int fieldUsername  = query.record().indexOf("username");
        int fieldPassword  = query.record().indexOf("password");
        int fieldSalt      = query.record().indexOf("salt");
        int fieldName      = query.record().indexOf("name");
        int fieldRole      = query.record().indexOf("role"); // see role numbers at enums.h
        int fieldPhoto     = query.record().indexOf("photo");
        //more fields, now im not interested in that...
        info.id       = query.value(fielduId).toInt();
        info.username = query.value(fieldUsername).toString();
        info.password = query.value(fieldPassword).toString();
        info.salt     = query.value(fieldSalt).toString();
        info.name     = query.value(fieldName).toString();
        info.photo    = query.value(fieldPhoto).toByteArray();
        info.role     = query.value(fieldRole).toInt();
        //qDebug()<<"got user:"<<info.username;
      }
    }
    else {
      qDebug()<<"**Error** :"<<query.lastError();
    }
  }
  return info; 
}

bool Azahar::updateUser(UserInfo info)
{
  bool result=false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query.prepare("UPDATE users SET photo=:photo, username=:uname, name=:name, address=:address, phone=:phone, phone_movil=:cell, salt=:salt, password=:pass, role=:rol  WHERE id=:code;");
  query.bindValue(":code", info.id);
  query.bindValue(":photo", info.photo);
  query.bindValue(":uname", info.username);
  query.bindValue(":name", info.name);
  query.bindValue(":address", info.address);
  query.bindValue(":phone", info.phone);
  query.bindValue(":cell", info.cell);
  query.bindValue(":pass", info.password);
  query.bindValue(":salt", info.salt);
  query.bindValue(":rol", info.role);
  if (!query.exec()) setError(query.lastError().text()); else result=true;
  return result;
}

QString Azahar::getUserName(QString username)
{
  QString name = "";
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery queryUname(db);
    QString qry = QString("SELECT name FROM users WHERE username='%1'").arg(username);
    if (!queryUname.exec(qry)) { setError(queryUname.lastError().text()); }
    else {
      if (queryUname.isActive() && queryUname.isSelect()) { //qDebug()<<"queryUname select && active.";
        if (queryUname.first()) { //qDebug()<<"queryUname.first()=true";
          name = queryUname.value(0).toString();
        }
      }
    }
  } else { setError(db.lastError().text()); }
  return name;
}

QString Azahar::getUserName(qulonglong id)
{
  QString name = "";
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery queryUname(db);
    QString qry = QString("SELECT name FROM users WHERE users.id=%1").arg(id);
    if (!queryUname.exec(qry)) { setError(queryUname.lastError().text()); }
    else {
      if (queryUname.isActive() && queryUname.isSelect()) { //qDebug()<<"queryUname select && active.";
        if (queryUname.first()) { //qDebug()<<"queryUname.first()=true";
          name = queryUname.value(0).toString();
        }
      }
    }
  } else { setError(db.lastError().text()); }
  return name;
}

QStringList Azahar::getUsersList()
{
  QStringList result;
  result.clear();
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec("select name from users;")) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("name");
        QString text = myQuery.value(fieldText).toString();
        result.append(text);
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

unsigned int Azahar::getUserId(QString uname)
{
  unsigned int iD = 0;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery queryId(db);
    QString qry = QString("SELECT id FROM users WHERE username='%1'").arg(uname);
    if (!queryId.exec(qry)) { setError(queryId.lastError().text()); }
    else {
      if (queryId.isActive() && queryId.isSelect()) { //qDebug()<<"queryId select && active.";
        if (queryId.first()) { //qDebug()<<"queryId.first()=true";
        iD = queryId.value(0).toUInt();
        }
      }
    }
  } else { setError(db.lastError().text()); }
  return iD;
}

unsigned int Azahar::getUserIdFromName(QString uname)
{
  unsigned int iD = 0;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery queryId(db);
    QString qry = QString("SELECT id FROM users WHERE name='%1'").arg(uname);
    if (!queryId.exec(qry)) { setError(queryId.lastError().text()); }
    else {
      if (queryId.isActive() && queryId.isSelect()) { //qDebug()<<"queryId select && active.";
      if (queryId.first()) { //qDebug()<<"queryId.first()=true";
      iD = queryId.value(0).toUInt();
      }
      }
    }
  } else { setError(db.lastError().text()); }
  return iD;
}

int Azahar::getUserRole(const qulonglong &userid)
{
  int role = 0;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery queryId(db);
    QString qry = QString("SELECT role FROM users WHERE id=%1").arg(userid);
    if (!queryId.exec(qry)) { setError(queryId.lastError().text()); }
    else {
      if (queryId.isActive() && queryId.isSelect()) { //qDebug()<<"queryId select && active.";
        if (queryId.first()) { //qDebug()<<"queryId.first()=true";
        role = queryId.value(0).toInt();
        }
      }
    }
  } else { setError(db.lastError().text()); }
  return role;
}

bool Azahar::deleteUser(qulonglong id)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query = QString("DELETE FROM users WHERE id=%1").arg(id);
  if (!query.exec()) setError(query.lastError().text()); else result=true;
  return result;
}

//CLIENTS
bool Azahar::insertClient(ClientInfo info)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO clients (name, address, phone, phone_movil, points, discount, photo, since, code) VALUES(:name, :address, :phone, :cell,:points, :discount, :photo, :since, :code)");
    query.bindValue(":photo", info.photo);
    query.bindValue(":points", info.points);
    query.bindValue(":discount", info.discount);
    query.bindValue(":name", info.name);
    query.bindValue(":code", info.code);
    query.bindValue(":address", info.address);
    query.bindValue(":phone", info.phone);
    query.bindValue(":cell", info.cell);
    query.bindValue(":since", info.since);
    if (!query.exec()) setError(query.lastError().text()); else result = true;
  }
  return result;
}

bool Azahar::updateClient(ClientInfo info)
{
  bool result=false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query.prepare("UPDATE clients SET photo=:photo, name=:name, code=:code, address=:address, phone=:phone, phone_movil=:cell, points=:points, discount=:disc, since=:since  WHERE id=:id;");
  query.bindValue(":id", info.id);
  query.bindValue(":photo", info.photo);
  query.bindValue(":points", info.points);
  query.bindValue(":disc", info.discount);
  query.bindValue(":name", info.name);
  query.bindValue(":code", info.code);
  query.bindValue(":address", info.address);
  query.bindValue(":phone", info.phone);
  query.bindValue(":cell", info.cell);
  query.bindValue(":since", info.since);
  if (!query.exec()) setError(query.lastError().text()); else result = true;

  return result;
}

bool Azahar::incrementClientPoints(qulonglong id, qulonglong points)
{
  bool result=false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query.prepare("UPDATE clients SET points=points+:points WHERE id=:code;");
  query.bindValue(":code", id);
  query.bindValue(":points", points);
  if (!query.exec()) setError(query.lastError().text()); else result = true;
  return result;
}

bool Azahar::decrementClientPoints(qulonglong id, qulonglong points)
{
  bool result=false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query.prepare("UPDATE clients SET points=points-:points WHERE id=:code;");
  query.bindValue(":code", id);
  query.bindValue(":points", points);
  if (!query.exec()) setError(query.lastError().text()); else result = true;
  return result;
}

ClientInfo Azahar::getClientInfo(qulonglong clientId)
{
  ClientInfo info;
  info.name = "";
  info.id = 0;//to recognize errors.
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
      QSqlQuery qC(db);
      if (qC.exec(QString("select * from clients where id=%1;").arg(clientId))) {
        while (qC.next()) {
          int fieldId     = qC.record().indexOf("id");
          int fieldCode   = qC.record().indexOf("code");
          int fieldName   = qC.record().indexOf("name");
          int fieldPoints = qC.record().indexOf("points");
          int fieldPhoto  = qC.record().indexOf("photo");
          int fieldDisc   = qC.record().indexOf("discount");
          int fieldSince  = qC.record().indexOf("since");
          int fieldPhone  = qC.record().indexOf("phone");
          int fieldCell   = qC.record().indexOf("phone_movil");
          int fieldAdd    = qC.record().indexOf("address");
          //Should be only one
          info.id         = qC.value(fieldId).toUInt();
          info.code       = qC.value(fieldCode).toString();
          info.name       = qC.value(fieldName).toString();
          info.points     = qC.value(fieldPoints).toULongLong();
          info.discount   = qC.value(fieldDisc).toDouble();
          info.photo      = qC.value(fieldPhoto).toByteArray();
          info.since      = qC.value(fieldSince).toDate();
          info.phone      = qC.value(fieldPhone).toString();
          info.cell       = qC.value(fieldCell).toString();
          info.address    = qC.value(fieldAdd).toString();
        }
      }
      else {
        qDebug()<<"ERROR: "<<qC.lastError();
      }
    }
 return info;
}

ClientInfo Azahar::getClientInfo(QString clientCode)
{
    ClientInfo info;
    info.name = "";
    info.id = 0;//to recognize errors.
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
        QSqlQuery qC(db);
        if (qC.exec(QString("select * from clients WHERE code='%1';").arg(clientCode))) {
            while (qC.next()) {
                int fieldId     = qC.record().indexOf("id");
                int fieldCode   = qC.record().indexOf("code");
                int fieldName   = qC.record().indexOf("name");
                int fieldPoints = qC.record().indexOf("points");
                int fieldPhoto  = qC.record().indexOf("photo");
                int fieldDisc   = qC.record().indexOf("discount");
                int fieldSince  = qC.record().indexOf("since");
                int fieldPhone  = qC.record().indexOf("phone");
                int fieldCell   = qC.record().indexOf("phone_movil");
                int fieldAdd    = qC.record().indexOf("address");
                info.id         = qC.value(fieldId).toUInt();
                info.code       = qC.value(fieldCode).toString();
                info.name       = qC.value(fieldName).toString();
                info.points     = qC.value(fieldPoints).toULongLong();
                info.discount   = qC.value(fieldDisc).toDouble();
                info.photo      = qC.value(fieldPhoto).toByteArray();
                info.since      = qC.value(fieldSince).toDate();
                info.phone      = qC.value(fieldPhone).toString();
                info.cell       = qC.value(fieldCell).toString();
                info.address    = qC.value(fieldAdd).toString();
            }
        }
        else {
            qDebug()<<"ERROR: "<<qC.lastError();
        }
    }
    return info;
}

QString Azahar::getMainClient()
{
 QString result;
 ClientInfo info;
  if (m_mainClient == "undefined") {
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
      QSqlQuery qC(db);
      if (qC.exec("select * from clients where id=1;")) {
        while (qC.next()) {
          int fieldName   = qC.record().indexOf("name");
          info.name       = qC.value(fieldName).toString();
          m_mainClient = info.name;
          result = info.name;
        }
      }
      else {
        qDebug()<<"ERROR: "<<qC.lastError();
      }
    }
  } else result = m_mainClient;
return result;
}

QHash<QString, ClientInfo> Azahar::getClientsHash()
{
 QHash<QString, ClientInfo> result;
 ClientInfo info;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery qC(db);
    if (qC.exec("select * from clients;")) {
      while (qC.next()) {
        int fieldId     = qC.record().indexOf("id");
        int fieldName   = qC.record().indexOf("name");
        int fieldPoints = qC.record().indexOf("points");
        int fieldPhoto  = qC.record().indexOf("photo");
        int fieldDisc   = qC.record().indexOf("discount");
        int fieldSince  = qC.record().indexOf("since");
        int fieldCode   = qC.record().indexOf("code");
        int fieldAddr   = qC.record().indexOf("address");
        info.id = qC.value(fieldId).toUInt();
        info.name       = qC.value(fieldName).toString();
        info.points     = qC.value(fieldPoints).toULongLong();
        info.discount   = qC.value(fieldDisc).toDouble();
        info.photo      = qC.value(fieldPhoto).toByteArray();
        info.since      = qC.value(fieldSince).toDate();
        info.code       = qC.value(fieldCode).toString();
        info.address    = qC.value(fieldAddr).toString();
        result.insert(info.name, info);
        if (info.id == 1) m_mainClient = info.name;
      }
    }
    else {
      qDebug()<<"ERROR: "<<qC.lastError();
    }
  }
  return result;
}

QStringList Azahar::getClientsList()
{
  QStringList result;
  result.clear();
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec("select name from clients;")) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("name");
        QString text = myQuery.value(fieldText).toString();
        result.append(text);
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

unsigned int Azahar::getClientId(QString uname)
{
  unsigned int iD = 0;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery queryId(db);
    QString qry = QString("SELECT clients.id FROM clients WHERE clients.name='%1'").arg(uname);
    if (!queryId.exec(qry)) { setError(queryId.lastError().text()); }
    else {
      if (queryId.isActive() && queryId.isSelect()) { //qDebug()<<"queryId select && active.";
       if (queryId.first()) { //qDebug()<<"queryId.first()=true";
        iD = queryId.value(0).toUInt();
       }
      }
    }
  } else { setError(db.lastError().text()); }
  return iD;
}

bool Azahar::deleteClient(qulonglong id)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query = QString("DELETE FROM clients WHERE id=%1").arg(id);
  if (!query.exec()) setError(query.lastError().text()); else result=true;
  return result;
}


//TRANSACTIONS

TransactionInfo Azahar::getTransactionInfo(qulonglong id)
{
  TransactionInfo info;
  info.id = 0;
  QString qry = QString("SELECT * FROM transactions WHERE id=%1").arg(id);
  QSqlQuery query;
  if (!query.exec(qry)) { qDebug()<<query.lastError(); }
  else {
    while (query.next()) {
      int fieldId = query.record().indexOf("id");
      int fieldAmount = query.record().indexOf("amount");
      int fieldDate   = query.record().indexOf("date");
      int fieldTime   = query.record().indexOf("time");
      int fieldPaidWith = query.record().indexOf("paidwith");
      int fieldPayMethod = query.record().indexOf("paymethod");
      int fieldType      = query.record().indexOf("type");
      int fieldChange    = query.record().indexOf("changegiven");
      int fieldState     = query.record().indexOf("state");
      int fieldUserId    = query.record().indexOf("userid");
      int fieldClientId  = query.record().indexOf("clientid");
      int fieldCardNum   = query.record().indexOf("cardnumber");
      int fieldCardAuth  = query.record().indexOf("cardauthnumber");
      int fieldItemCount = query.record().indexOf("itemcount");
      int fieldItemsList = query.record().indexOf("itemsList");
      int fieldDiscount  = query.record().indexOf("disc");
      int fieldDiscMoney = query.record().indexOf("discmoney");
      int fieldPoints    = query.record().indexOf("points");
      int fieldUtility   = query.record().indexOf("utility");
      int fieldTerminal  = query.record().indexOf("terminalnum");
      int fieldTax       = query.record().indexOf("totalTax");
      int fieldSpecialOrders = query.record().indexOf("specialOrders");
      int fieldCardTypeId = query.record().indexOf("cardtype");
      
      info.id     = query.value(fieldId).toULongLong();
      info.amount = query.value(fieldAmount).toDouble();
      info.date   = query.value(fieldDate).toDate();
      info.time   = query.value(fieldTime).toTime();
      info.paywith= query.value(fieldPaidWith).toDouble();
      info.paymethod = query.value(fieldPayMethod).toInt();
      info.type      = query.value(fieldType).toInt();
      info.changegiven = query.value(fieldChange).toDouble();
      info.state     = query.value(fieldState).toInt();
      info.userid    = query.value(fieldUserId).toULongLong();
      info.clientid  = query.value(fieldClientId).toULongLong();
      info.cardnumber= query.value(fieldCardNum).toString();//.replace(0,15,"***************"); //FIXED: Only save last 4 digits;
      info.cardauthnum=query.value(fieldCardAuth).toString();
      info.itemcount = query.value(fieldItemCount).toInt();
      info.itemlist  = query.value(fieldItemsList).toString();
      info.disc      = query.value(fieldDiscount).toDouble();
      info.discmoney = query.value(fieldDiscMoney).toDouble();
      info.points    = query.value(fieldPoints).toULongLong();
      info.utility   = query.value(fieldUtility).toDouble();
      info.terminalnum=query.value(fieldTerminal).toInt();
      info.totalTax   = query.value(fieldTax).toDouble();
      info.specialOrders = query.value(fieldSpecialOrders).toString();
      info.cardType   =query.value(fieldCardTypeId).toInt();
      info.cardTypeStr= getCardTypeStr(info.cardType);
    }
  }
  return info;
}

ProfitRange Azahar::getMonthProfitRange()
{
  QList<TransactionInfo> monthTrans = getMonthTransactionsForPie();
  ProfitRange range;
  QList<double> profitList;
  TransactionInfo info;
  for (int i = 0; i < monthTrans.size(); ++i) {
    info = monthTrans.at(i);
    profitList.append(info.utility);
  }

  if (!profitList.isEmpty()) {
   qSort(profitList.begin(),profitList.end()); //sorting in ascending order (1,2,3..)
   range.min = profitList.first();
   range.max = profitList.last();
  } else {range.min=0.0; range.max=0.0;}

  return range;
}

ProfitRange Azahar::getMonthSalesRange()
{
  QList<TransactionInfo> monthTrans = getMonthTransactionsForPie();
  ProfitRange range;
  QList<double> salesList;
  TransactionInfo info;
  for (int i = 0; i < monthTrans.size(); ++i) {
    info = monthTrans.at(i);
    salesList.append(info.amount);
  }
  
  if (!salesList.isEmpty()) {
    qSort(salesList.begin(),salesList.end()); //sorting in ascending order (1,2,3..)
    range.min = salesList.first();
    range.max = salesList.last();
  } else {range.min=0.0; range.max=0.0;}

  return range;
}

QList<TransactionInfo> Azahar::getMonthTransactionsForPie()
{
  ///just return the amount and the profit.
  QList<TransactionInfo> result;
  TransactionInfo info;
  QSqlQuery qryTrans(db);
  QDate today = QDate::currentDate();
  QDate startDate = QDate(today.year(), today.month(), 1); //get the 1st of the month.
  //NOTE: in the next query, the state and type are hardcoded (not using the enums) because problems when preparing query.
  qryTrans.prepare("SELECT date,SUM(amount),SUM(utility) from transactions where (date BETWEEN :dateSTART AND :dateEND ) AND (type=1) AND (state=2 OR state=8 OR state=9) GROUP BY date ASC;");
  qryTrans.bindValue("dateSTART", startDate.toString("yyyy-MM-dd"));
  qryTrans.bindValue("dateEND", today.toString("yyyy-MM-dd"));
  //tCompleted=2, tSell=1. With a placeholder, the value is inserted as a string, and cause the query to fail.
  if (!qryTrans.exec() ) {
    int errNum = qryTrans.lastError().number();
    QSqlError::ErrorType errType = qryTrans.lastError().type();
    QString errStr = qryTrans.lastError().text();
    QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
    setError(details);
  } else {
    while (qryTrans.next()) {
      int fieldAmount = qryTrans.record().indexOf("SUM(amount)");
      int fieldProfit = qryTrans.record().indexOf("SUM(utility)");
      int fieldDate = qryTrans.record().indexOf("date");
      info.amount = qryTrans.value(fieldAmount).toDouble();
      info.utility = qryTrans.value(fieldProfit).toDouble();
      info.date = qryTrans.value(fieldDate).toDate();
      result.append(info);
      //qDebug()<<"APPENDING:"<<info.date<< " Sales:"<<info.amount<<" Profit:"<<info.utility;
    }
    //qDebug()<<"executed query:"<<qryTrans.executedQuery();
    //qDebug()<<"Qry size:"<<qryTrans.size();
    
  }
  return result;
}

QList<TransactionInfo> Azahar::getMonthTransactions()
{
  QList<TransactionInfo> result;
  TransactionInfo info;
  QSqlQuery qryTrans(db);
  QDate today = QDate::currentDate();
  QDate startDate = QDate(today.year(), today.month(), 1); //get the 1st of the month.
  //NOTE: in the next query, the state and type are hardcoded (not using the enums) because problems when preparing query.
  qryTrans.prepare("SELECT id,date from transactions where (date BETWEEN :dateSTART AND :dateEND ) AND (type=1) AND (state=2 OR state=8 OR state=9) ORDER BY date,id ASC;");
  qryTrans.bindValue("dateSTART", startDate.toString("yyyy-MM-dd"));
  qryTrans.bindValue("dateEND", today.toString("yyyy-MM-dd"));
  //tCompleted=2, tSell=1. With a placeholder, the value is inserted as a string, and cause the query to fail.
  if (!qryTrans.exec() ) {
    int errNum = qryTrans.lastError().number();
    QSqlError::ErrorType errType = qryTrans.lastError().type();
    QString errStr = qryTrans.lastError().text();
    QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
    setError(details);
  } else {
    while (qryTrans.next()) {
      int fieldId = qryTrans.record().indexOf("id");
      info = getTransactionInfo(qryTrans.value(fieldId).toULongLong());
      result.append(info);
      //qDebug()<<"APPENDING: id:"<<info.id<<" "<<info.date;
    }
    //qDebug()<<"executed query:"<<qryTrans.executedQuery();
    //qDebug()<<"Qry size:"<<qryTrans.size();
    
  }
  return result;
}


QList<TransactionInfo> Azahar::getDayTransactions(int terminal)
{
    QList<TransactionInfo> result;
    TransactionInfo info;
    QSqlQuery qryTrans(db);
    QDate today = QDate::currentDate();
    //NOTE: in the next query, the state and type are hardcoded (not using the enums) because problems when preparing query. State 8 = OwnCreditCompletedPaymentPending
    qryTrans.prepare("SELECT id,time,paidwith,paymethod,amount,utility,totalTax from transactions where (date = :today) AND (terminalnum=:terminal) AND (type=1) AND (state=2 OR state=8 OR state=9) ORDER BY id ASC;");
    qryTrans.bindValue("today", today.toString("yyyy-MM-dd"));
    qryTrans.bindValue(":terminal", terminal);
    //tCompleted=2, tSell=1. With a placeholder, the value is inserted as a string, and cause the query to fail.
    if (!qryTrans.exec() ) {
      int errNum = qryTrans.lastError().number();
      QSqlError::ErrorType errType = qryTrans.lastError().type();
      QString errStr = qryTrans.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
      setError(details);
    } else {
      while (qryTrans.next()) {
        int fieldAmount = qryTrans.record().indexOf("amount");
        int fieldProfit = qryTrans.record().indexOf("utility");
        info.id = qryTrans.value(qryTrans.record().indexOf("id")).toULongLong();
        info.amount = qryTrans.value(fieldAmount).toDouble();
        info.utility = qryTrans.value(fieldProfit).toDouble();
        info.paymethod = qryTrans.value(qryTrans.record().indexOf("paymethod")).toInt();
        info.paywith = qryTrans.value(qryTrans.record().indexOf("paidwith")).toDouble();
        info.time = qryTrans.value(qryTrans.record().indexOf("time")).toTime();
        info.totalTax = qryTrans.value(qryTrans.record().indexOf("totalTax")).toDouble();
        result.append(info);
        //qDebug()<<"APPENDING:"<<info.id<< " Sales:"<<info.amount<<" Profit:"<<info.utility;
      }
      //qDebug()<<"executed query:"<<qryTrans.executedQuery();
      //qDebug()<<"Qry size:"<<qryTrans.size();

    }
    return result;
}

QList<TransactionInfo> Azahar::getDayTransactions()
{
  QList<TransactionInfo> result;
  TransactionInfo info;
  QSqlQuery qryTrans(db);
  QDate today = QDate::currentDate();
  //NOTE: in the next query, the state and type are hardcoded (not using the enums) because problems when preparing query.
  qryTrans.prepare("SELECT id,time,paidwith,paymethod,amount,utility,totalTax from transactions where (date = :today) AND (type=1) AND (state=2 OR state=8 OR state=9) ORDER BY id ASC;");
  qryTrans.bindValue("today", today.toString("yyyy-MM-dd"));
  //tCompleted=2, tSell=1. With a placeholder, the value is inserted as a string, and cause the query to fail.
  if (!qryTrans.exec() ) {
    int errNum = qryTrans.lastError().number();
    QSqlError::ErrorType errType = qryTrans.lastError().type();
    QString errStr = qryTrans.lastError().text();
    QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
    setError(details);
  } else {
    while (qryTrans.next()) {
      int fieldAmount = qryTrans.record().indexOf("amount");
      int fieldProfit = qryTrans.record().indexOf("utility");
      info.id = qryTrans.value(qryTrans.record().indexOf("id")).toULongLong();
      info.amount = qryTrans.value(fieldAmount).toDouble();
      info.utility = qryTrans.value(fieldProfit).toDouble();
      info.paymethod = qryTrans.value(qryTrans.record().indexOf("paymethod")).toInt();
      info.paywith = qryTrans.value(qryTrans.record().indexOf("paidwith")).toDouble();
      info.time = qryTrans.value(qryTrans.record().indexOf("time")).toTime();
      info.totalTax = qryTrans.value(qryTrans.record().indexOf("totalTax")).toDouble();
      result.append(info);
      //qDebug()<<"APPENDING:"<<info.id<< " Sales:"<<info.amount<<" Profit:"<<info.utility;
    }
    //qDebug()<<"executed query:"<<qryTrans.executedQuery();
    //qDebug()<<"Qry size:"<<qryTrans.size();
    
  }
  return result;
}

AmountAndProfitInfo  Azahar::getDaySalesAndProfit(int terminal)
{
    AmountAndProfitInfo result;
    QSqlQuery qryTrans(db);
    QDate today = QDate::currentDate();
    //NOTE: in the next query, the state and type are hardcoded (not using the enums) because problems when preparing query.
    qryTrans.prepare("SELECT SUM(amount),SUM(utility) from transactions where (date = :today) AND (terminalnum=:terminal) AND (type=1) AND (state=2 OR state=8 OR state=9) GROUP BY date ASC;");
    qryTrans.bindValue("today", today.toString("yyyy-MM-dd"));
    qryTrans.bindValue(":terminal", terminal);
    //tCompleted=2, tSell=1. With a placeholder, the value is inserted as a string, and cause the query to fail.
    if (!qryTrans.exec() ) {
      int errNum = qryTrans.lastError().number();
      QSqlError::ErrorType errType = qryTrans.lastError().type();
      QString errStr = qryTrans.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
      setError(details);
    } else {
      while (qryTrans.next()) {
        int fieldAmount = qryTrans.record().indexOf("SUM(amount)");
        int fieldProfit = qryTrans.record().indexOf("SUM(utility)");
        result.amount = qryTrans.value(fieldAmount).toDouble();
        result.profit = qryTrans.value(fieldProfit).toDouble();
        //qDebug()<<"APPENDING:"<<info.date<< " Sales:"<<info.amount<<" Profit:"<<info.utility;
      }
      //qDebug()<<"executed query:"<<qryTrans.executedQuery();
      //qDebug()<<"Qry size:"<<qryTrans.size();

    }
    return result;
}

AmountAndProfitInfo  Azahar::getDaySalesAndProfit()
{
  AmountAndProfitInfo result;
  QSqlQuery qryTrans(db);
  QDate today = QDate::currentDate();
  //NOTE: in the next query, the state and type are hardcoded (not using the enums) because problems when preparing query.
  qryTrans.prepare("SELECT SUM(amount),SUM(utility) from transactions where (date = :today) AND (type=1) AND (state=2 OR state=8 OR state=9) GROUP BY date ASC;");
  qryTrans.bindValue("today", today.toString("yyyy-MM-dd"));
  //tCompleted=2, tSell=1. With a placeholder, the value is inserted as a string, and cause the query to fail.
  if (!qryTrans.exec() ) {
    int errNum = qryTrans.lastError().number();
    QSqlError::ErrorType errType = qryTrans.lastError().type();
    QString errStr = qryTrans.lastError().text();
    QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
    setError(details);
  } else {
    while (qryTrans.next()) {
      int fieldAmount = qryTrans.record().indexOf("SUM(amount)");
      int fieldProfit = qryTrans.record().indexOf("SUM(utility)");
      result.amount = qryTrans.value(fieldAmount).toDouble();
      result.profit = qryTrans.value(fieldProfit).toDouble();
      //qDebug()<<"APPENDING:"<<info.date<< " Sales:"<<info.amount<<" Profit:"<<info.utility;
    }
    //qDebug()<<"executed query:"<<qryTrans.executedQuery();
    //qDebug()<<"Qry size:"<<qryTrans.size();
    
  }
  return result;
}
  
//this returns the sales and profit from the 1st day of the month until today
AmountAndProfitInfo  Azahar::getMonthSalesAndProfit()
{
  AmountAndProfitInfo result;
  QSqlQuery qryTrans(db);
  QDate today = QDate::currentDate();
  QDate startDate = QDate(today.year(), today.month(), 1); //get the 1st of the month.
  //NOTE: in the next query, the state and type are hardcoded (not using the enums) because problems when preparing query.
  qryTrans.prepare("SELECT date,SUM(amount),SUM(utility) from transactions where (date BETWEEN :dateSTART AND :dateEND) AND (type=1) AND (state=2 OR state=8 OR state=9) GROUP BY type ASC;"); //group by type is to get the sum of all trans
  qryTrans.bindValue("dateSTART", startDate.toString("yyyy-MM-dd"));
  qryTrans.bindValue("dateEND", today.toString("yyyy-MM-dd"));
  //tCompleted=2, tSell=1. With a placeholder, the value is inserted as a string, and cause the query to fail.
  if (!qryTrans.exec() ) {
    int errNum = qryTrans.lastError().number();
    QSqlError::ErrorType errType = qryTrans.lastError().type();
    QString errStr = qryTrans.lastError().text();
    QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
    setError(details);
  } else {
    while (qryTrans.next()) {
      int fieldAmount = qryTrans.record().indexOf("SUM(amount)");
      int fieldProfit = qryTrans.record().indexOf("SUM(utility)");
      result.amount = qryTrans.value(fieldAmount).toDouble();
      result.profit = qryTrans.value(fieldProfit).toDouble();
      //qDebug()<<"APPENDING --  Sales:"<<result.amount<<" Profit:"<<result.profit;
    }
    //qDebug()<<"executed query:"<<qryTrans.executedQuery();
    //qDebug()<<"Qry size:"<<qryTrans.size();
    
  }
  return result;
}

//TRANSACTIONS
qulonglong Azahar::insertTransaction(TransactionInfo info)
{
  qulonglong result=0;
  //NOTE:The next commented code was deprecated because it will cause to overwrite transactions
  //    When two or more terminals were getting an empty transacion at the same time, getting the same one.
  //first look for an empty transaction.
  //qulonglong availableId = getEmptyTransactionId();
  //if (availableId > 0 ) {
  //  qDebug()<<"The empty transaction # "<<availableId <<" is available to reuse.";
  //  info.id = availableId;
  //  if (updateTransaction(info)) result = availableId;
  //}
  //else {
    // insert a new one.
    QSqlQuery query2(db);
    query2.prepare("INSERT INTO transactions (clientid, type, amount, date,  time, paidwith, changegiven, paymethod, state, userid, cardnumber, itemcount, itemslist, cardauthnumber, utility, terminalnum, providerid, specialOrders, balanceId, totalTax, cardtype) VALUES (:clientid, :type, :amount, :date, :time, :paidwith, :changegiven, :paymethod, :state, :userid, :cardnumber, :itemcount, :itemslist, :cardauthnumber, :utility, :terminalnum, :providerid, :specialOrders, :balance, :tax, :cardType)"); //removed groups 29DIC09

    /** Remember to improve queries readability:
     * query2.prepare("INSERT INTO transactions ( \
    clientid, userid, type, amount, date,  time, \
    paidwith,  paymethod, changegiven, state,    \
    cardnumber, itemcount, itemslist, points, \
    discmoney, disc, discmoney, cardauthnumber, profit,  \
    terminalnum, providerid, specialOrders, balanceId, totalTax) \
    VALUES ( \
    :clientid, :userid, :type, :amount, :date, :time, \
    :paidwith, :paymethod, :changegiven, :state,  \
    :cardnumber, :itemcount, :itemslist, :points, \
    :discmoney, :disc, :discm, :cardauthnumber, :utility, \
    :terminalnum, :providerid, :specialOrders, :balanceId, :totalTax)");
    **/
    
    query2.bindValue(":type", info.type);
    query2.bindValue(":amount", info.amount);
    query2.bindValue(":date", info.date.toString("yyyy-MM-dd"));
    query2.bindValue(":time", info.time.toString("hh:mm"));
    query2.bindValue(":paidwith", info.paywith );
    query2.bindValue(":changegiven", info.changegiven);
    query2.bindValue(":paymethod", info.paymethod);
    query2.bindValue(":state", info.state);
    query2.bindValue(":userid", info.userid);
    query2.bindValue(":clientid", info.clientid);
    query2.bindValue(":cardnumber", info.cardnumber); //.replace(0,15,"***************")); //FIXED: Only save last 4 digits
    query2.bindValue(":itemcount", info.itemcount);
    query2.bindValue(":itemslist", info.itemlist);
    query2.bindValue(":cardauthnumber", info.cardauthnum);
    query2.bindValue(":utility", info.utility);
    query2.bindValue(":terminalnum", info.terminalnum);
    query2.bindValue(":providerid", info.providerid);
    query2.bindValue(":tax", info.totalTax);
    query2.bindValue(":specialOrders", info.specialOrders);
    query2.bindValue(":balance", info.balanceId);
    query2.bindValue(":cardType", info.cardType);
    if (!query2.exec() ) {
      int errNum = query2.lastError().number();
      QSqlError::ErrorType errType = query2.lastError().type();
      QString errStr = query2.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
      setError(details);
    } else result=query2.lastInsertId().toULongLong();
  //}

  return result;
}

bool Azahar::updateTransaction(TransactionInfo info)
{
  bool result=false;
  QSqlQuery query2(db);
  query2.prepare("UPDATE transactions SET disc=:disc, discmoney=:discMoney, amount=:amount, date=:date,  time=:time, paidwith=:paidw, changegiven=:change, paymethod=:paymethod, cardtype=:cardType, state=:state, cardnumber=:cardnumber, itemcount=:itemcount, itemslist=:itemlist, cardauthnumber=:cardauthnumber, utility=:utility, terminalnum=:terminalnum, points=:points, clientid=:clientid, specialOrders=:sorders, balanceId=:balance, totalTax=:tax WHERE id=:code");
  query2.bindValue(":disc", info.disc);
  query2.bindValue(":discMoney", info.discmoney);
  query2.bindValue(":code", info.id);
  query2.bindValue(":amount", info.amount);
  query2.bindValue(":date", info.date.toString("yyyy-MM-dd"));
  query2.bindValue(":time", info.time.toString("hh:mm"));
  query2.bindValue(":paidw", info.paywith );
  query2.bindValue(":change", info.changegiven);
  query2.bindValue(":paymethod", info.paymethod);
  query2.bindValue(":state", info.state);
  query2.bindValue(":cardnumber", info.cardnumber);//.replace(0,15,"***************")); //FIXED: Only save last 4 digits
  query2.bindValue(":itemcount", info.itemcount);
  query2.bindValue(":itemlist", info.itemlist);
  query2.bindValue(":cardauthnumber", info.cardauthnum);
  query2.bindValue(":utility", info.utility);
  query2.bindValue(":terminalnum", info.terminalnum);
  query2.bindValue(":points", info.points);
  query2.bindValue(":clientid", info.clientid);
  query2.bindValue(":tax", info.totalTax);
  query2.bindValue(":sorders", info.specialOrders);
  query2.bindValue(":balance", info.balanceId);
  query2.bindValue(":cardType", info.cardType);
  qDebug()<<"Transaction ID:"<<info.id;
  if (!query2.exec() ) {
    int errNum = query2.lastError().number();
    QSqlError::ErrorType errType = query2.lastError().type();
    QString errStr = query2.lastError().text();
    QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
    setError(details);
    qDebug()<<"DETALLES DEL ERROR:"<<details;
  } else result=true;
  
  return result;
}

bool Azahar::deleteTransaction(qulonglong id)
{
  bool result=false;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery query(db);
    QString qry = QString("DELETE FROM transactions WHERE id=%1").arg(id);
    if (!query.exec(qry)) {
      result = false;
      int errNum = query.lastError().number();
      QSqlError::ErrorType errType = query.lastError().type();
      QString errStr = query.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
      setError(details);
    } else {
      result = true;
    }
  }
  return result;
}


//NOTE: Is it convenient to reuse empty transactions or simply delete them?
bool Azahar::deleteEmptyTransactions()
{
   bool result = false;
   if (!db.isOpen()) db.open();
   if (db.isOpen()) {
     QSqlQuery query(db);
     QString qry = QString("DELETE FROM transactions WHERE itemcount<=0 and amount<=0");
     if (!query.exec(qry)) {
       int errNum = query.lastError().number();
       QSqlError::ErrorType errType = query.lastError().type();
       QString errStr = query.lastError().text();
       QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
       setError(details);
     } else {
       result = true;
     }
   }
   return result;
}

qulonglong Azahar::getEmptyTransactionId()
{
    qulonglong result = 0;
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
     QSqlQuery query(db);
     QString qry = QString("SELECT id from transactions WHERE itemcount<=0 and amount<=0");
     if (!query.exec(qry)) {
       int errNum = query.lastError().number();
       QSqlError::ErrorType errType = query.lastError().type();
       QString errStr = query.lastError().text();
       QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
       setError(details);
     } else {
        while (query.next()) {
          int fieldId = query.record().indexOf("id");
          result      = query.value(fieldId).toULongLong();
          return result;
        }
       }
     }
     return result;
}

bool Azahar::cancelTransaction(qulonglong id, bool inProgress)
{
  bool result=false;
  if (!db.isOpen()) db.open();
  bool ok = db.isOpen();
  
  TransactionInfo tinfo = getTransactionInfo(id);
  bool transCompleted = false;
  bool alreadyCancelled = false;
  bool transExists = false;
  if (tinfo.id    >  0)          transExists      = true;
  if (tinfo.state == tCompleted && transExists) transCompleted   = true;
  if (tinfo.state == tCancelled && transExists) alreadyCancelled = true;

  ///TODO & FIXME: What about card payments? Return money or what to do?
  
  
  if (ok) {
    QSqlQuery query(db);
    QString qry;
    
    if (!inProgress && !alreadyCancelled && transExists) {
      qry = QString("UPDATE transactions SET  state=%1 WHERE id=%2")
      .arg(tCancelled)
      .arg(id);
      if (!query.exec(qry)) {
        int errNum = query.lastError().number();
        QSqlError::ErrorType errType = query.lastError().type();
        QString errStr = query.lastError().text();
        QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
        setError(details);
      } else { //Cancelled...
        result = true;
        qDebug()<<"Marked as Cancelled!";
      }
      ///not in progress, it means stockqty,points... are affected.
      if (transCompleted) {
        if (tinfo.points >0) decrementClientPoints(tinfo.clientid,tinfo.points);
        //TODO: when cancelling a transacion, take into account the groups sold to be returned. new feature
        QStringList soProducts;
        ///if there is any special order (product)
        if ( !tinfo.specialOrders.isEmpty() ) {
          //get each special order
          QStringList pSoList = tinfo.specialOrders.split(",");
          for (int i = 0; i < pSoList.size(); ++i) {
            QStringList l = pSoList.at(i).split("/");
            if ( l.count()==2 ) { //==2 means its complete, having product and qty
              qulonglong soid = l.at(0).toULongLong();
              //set as cancelled
              specialOrderSetStatus(soid, 4); //4 == cancelled
              //get each product of the special order to increment its stock later
              soProducts.append( getSpecialOrderProductsStr(soid) ); //are normal products (raw or not)
            } //if count
          } //for
        }//if there are special orders
        QString soProductsStr = soProducts.join(",");
        ///increment stock for each product. including special orders and groups
        QStringList plist = (tinfo.itemlist.split(",") + soProductsStr.split(","));
        qDebug()<<"[*****] plist: "<< plist;
        for (int i = 0; i < plist.size(); ++i) {
          QStringList l = plist.at(i).split("/");
          if ( l.count()==2 ) { //==2 means its complete, having product and qty
            //check if the product is a group
            //NOTE: rawProducts ? affect stock when cancelling = YES but only if affected when sold one of its parents (specialOrders) and stockqty is set. But they would not be here, if not at specialOrders List
            ProductInfo pi = getProductInfo(l.at(0));
            if ( pi.isAGroup ) 
              incrementGroupStock(l.at(0).toULongLong(), l.at(1).toDouble()); //code at 0, qty at 1
            else //there is a normal product
              incrementProductStock(l.at(0).toULongLong(), l.at(1).toDouble()); //code at 0, qty at 1
          }
        }//for each product
        ///save cashout for the money return
        qDebug()<<"Saving cashout-cancel";
        CashFlowInfo cinfo;
        cinfo.userid = tinfo.userid;
        cinfo.amount = tinfo.amount;
        cinfo.date   = QDate::currentDate();
        cinfo.time   = QTime::currentTime();
        cinfo.terminalNum = tinfo.terminalnum;
        cinfo.type   = ctCashOutMoneyReturnOnCancel;
        cinfo.reason = i18n("Money return on cancelling ticket #%1 ", id);
        insertCashFlow(cinfo);
      }//transCompleted
    } //not in progress
  }
  if ( alreadyCancelled ) {
    //The transaction was already canceled
    setError(i18n("Ticket #%1 was already canceled.", id));
    result = false;
    qDebug()<<"Transaction already cancelled...";
  }
  return result;
}



QList<TransactionInfo> Azahar::getLastTransactions(int pageNumber,int numItems,QDate beforeDate)
{
  QList<TransactionInfo> result;
  result.clear();
  QSqlQuery query(db);
  QString qry;
  qry = QString("SELECT * from transactions where type=1 and  date <= STR_TO_DATE('%1', '%d/%m/%Y') order by date desc, id desc LIMIT %2,%3").arg(beforeDate.toString("dd/MM/yyyy")).arg((pageNumber-1)*numItems+1).arg(numItems);
  if (query.exec(qry)) {
    while (query.next()) {
      TransactionInfo info;
      int fieldId = query.record().indexOf("id");
      int fieldAmount = query.record().indexOf("amount");
      int fieldDate   = query.record().indexOf("date");
      int fieldTime   = query.record().indexOf("time");
      int fieldPaidWith = query.record().indexOf("paidwith");
      int fieldPayMethod = query.record().indexOf("paymethod");
      int fieldType      = query.record().indexOf("type");
      int fieldChange    = query.record().indexOf("changegiven");
      int fieldState     = query.record().indexOf("state");
      int fieldUserId    = query.record().indexOf("userid");
      int fieldClientId  = query.record().indexOf("clientid");
      int fieldCardNum   = query.record().indexOf("cardnumber");
      int fieldCardAuth  = query.record().indexOf("cardauthnumber");
      int fieldItemCount = query.record().indexOf("itemcount");
      int fieldItemsList = query.record().indexOf("itemsList");
      int fieldDiscount  = query.record().indexOf("disc");
      int fieldDiscMoney = query.record().indexOf("discmoney");
      int fieldPoints    = query.record().indexOf("points");
      int fieldUtility   = query.record().indexOf("utility");
      int fieldTerminal  = query.record().indexOf("terminalnum");
      int fieldTax    = query.record().indexOf("totalTax");
      int fieldSOrd      = query.record().indexOf("specialOrders");
      int fieldBalance   = query.record().indexOf("balanceId");
      int fieldCardType  = query.record().indexOf("cardtype");
      info.id     = query.value(fieldId).toULongLong();
      info.amount = query.value(fieldAmount).toDouble();
      info.date   = query.value(fieldDate).toDate();
      info.time   = query.value(fieldTime).toTime();
      info.paywith= query.value(fieldPaidWith).toDouble();
      info.paymethod = query.value(fieldPayMethod).toInt();
      info.type      = query.value(fieldType).toInt();
      info.changegiven = query.value(fieldChange).toDouble();
      info.state     = query.value(fieldState).toInt();
      info.userid    = query.value(fieldUserId).toULongLong();
      info.clientid  = query.value(fieldClientId).toULongLong();
      info.cardnumber= query.value(fieldCardNum).toString();//.replace(0,15,"***************"); //FIXED: Only save last 4 digits;
      info.cardauthnum=query.value(fieldCardAuth).toString();
      info.itemcount = query.value(fieldItemCount).toInt();
      info.itemlist  = query.value(fieldItemsList).toString();
      info.disc      = query.value(fieldDiscount).toDouble();
      info.discmoney = query.value(fieldDiscMoney).toDouble();
      info.points    = query.value(fieldPoints).toULongLong();
      info.utility   = query.value(fieldUtility).toDouble();
      info.terminalnum=query.value(fieldTerminal).toInt();
      info.totalTax  = query.value(fieldTax).toDouble();
      info.specialOrders  = query.value(fieldSOrd).toString();
      info.balanceId = query.value(fieldBalance).toULongLong();
      info.cardType = query.value(fieldCardType).toInt();
      info.cardTypeStr = getCardTypeStr(info.cardType);
      result.append(info);
    }
  }
  else {
    setError(query.lastError().text());
  }
  return result;
}

//NOTE: The next method is not used... Also, for what pourpose? is it missing the STATE condition?
QList<TransactionInfo> Azahar::getTransactionsPerDay(int pageNumber,int numItems, QDate beforeDate)
{
  QList<TransactionInfo> result;
  result.clear();
  QSqlQuery query(db);
  QString qry;
  qry = QString("SELECT date, count(1) as transactions, sum(itemcount) as itemcount, sum(amount) as amount FROM transactions WHERE TYPE =1 AND date <= STR_TO_DATE('%1', '%d/%m/%Y') GROUP BY date(DATE) ORDER BY date DESC LIMIT %2,%3").arg(beforeDate.toString("dd/MM/yyyy")).arg((pageNumber-1)*numItems+1).arg(numItems);
  if (query.exec(qry)) {
    while (query.next()) {
      TransactionInfo info;
      int fieldTransactions = query.record().indexOf("transactions");
      int fieldAmount = query.record().indexOf("amount");
      int fieldDate   = query.record().indexOf("date");
      int fieldItemCount   = query.record().indexOf("itemcount");
      info.amount = query.value(fieldAmount).toDouble();
      info.date   = query.value(fieldDate).toDate();
      info.state     = query.value(fieldTransactions).toInt();
      info.itemcount = query.value(fieldItemCount).toInt();
      result.append(info);
    }
  }
  else {
    setError(query.lastError().text());
  }
  return result;
}

double Azahar::getTransactionDiscMoney(qulonglong id)
{
  double result = 0;
  QSqlQuery query(db);
  QString qry;
  qry = QString("SELECT discMoney FROM transactions WHERE id=%1").arg(id);
  if (query.exec(qry)) {
    while (query.next()) {
      int fieldAmount = query.record().indexOf("discMoney");
      result = query.value(fieldAmount).toDouble();
    }
  }
  else {
    setError(query.lastError().text());
  }
  return result;
}


bool Azahar::setTransactionStatus(qulonglong trId, TransactionState state)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    if (db.isOpen())
    {
        QSqlQuery query(db);
        if (state == tReserved)
            query.prepare("UPDATE transactions SET transactions.state=:state, transactions.totalTax=0 WHERE transactions.id=:trid");
        else
            query.prepare("UPDATE transactions SET transactions.state=:state WHERE transactions.id=:trid");
        query.bindValue(":trid", trId);
        query.bindValue(":state", state);

        qDebug()<< __FUNCTION__ << "Tr Id:"<<trId<<" State:"<<state;
        
        if (!query.exec() ) {
            int errNum = query.lastError().number();
            QSqlError::ErrorType errType = query.lastError().type();
            QString errStr = query.lastError().text();
            QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
            setError(details);
        } else result = true;
    }
    return result;
}


// TRANSACTIONITEMS
bool Azahar::insertTransactionItem(TransactionItemInfo info)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO transactionitems (transaction_id, position, product_id, qty, points, unitstr, cost, price, disc, total, name, payment, completePayment, soId, isGroup, deliveryDateTime, tax) VALUES(:transactionid, :position, :productCode, :qty, :points, :unitStr, :cost, :price, :disc, :total, :name, :payment, :completeP, :soid, :isGroup, :deliveryDT, :tax)");
    query.bindValue(":transactionid", info.transactionid);
    query.bindValue(":position", info.position);
    query.bindValue(":productCode", info.productCode);
    query.bindValue(":qty", info.qty);
    query.bindValue(":points", info.points);
    query.bindValue(":unitStr", info.unitStr);
    query.bindValue(":cost", info.cost);
    query.bindValue(":price", info.price);
    query.bindValue(":disc", info.disc);
    query.bindValue(":total", info.total);
    query.bindValue(":name", info.name);
    query.bindValue(":payment", info.payment);
    query.bindValue(":completeP", info.completePayment);
    query.bindValue(":soid", info.soId);
    query.bindValue(":isGroup", info.isGroup);
    query.bindValue(":deliveryDT", info.deliveryDateTime);
    query.bindValue(":tax", info.tax);
    if (!query.exec()) {
      setError(query.lastError().text());
      qDebug()<<"Insert TransactionItems error:"<<query.lastError().text();
    } else result = true;
  }
  return result;
}

bool Azahar::deleteAllTransactionItem(qulonglong id)
{
  bool result=false;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery query(db);
    QString qry = QString("DELETE FROM transactionitems WHERE transaction_id=%1").arg(id);
    if (!query.exec(qry)) {
      result = false;
      int errNum = query.lastError().number();
      QSqlError::ErrorType errType = query.lastError().type();
      QString errStr = query.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
      setError(details);
    } else {
      result = true;
    }
  }
  return result;
}

QList<TransactionItemInfo> Azahar::getTransactionItems(qulonglong id)
{
  QList<TransactionItemInfo> result;
  result.clear();
  QSqlQuery query(db);
  QString qry = QString("SELECT * FROM transactionitems WHERE transaction_id=%1 ORDER BY POSITION").arg(id);
  if (query.exec(qry)) {
    while (query.next()) {
      TransactionItemInfo info;
      int fieldPosition = query.record().indexOf("position");
      int fieldProductCode   = query.record().indexOf("product_id");
      int fieldQty     = query.record().indexOf("qty");
      int fieldPoints  = query.record().indexOf("points");
      int fieldCost    = query.record().indexOf("cost");
      int fieldPrice   = query.record().indexOf("price");
      int fieldDisc    = query.record().indexOf("disc");
      int fieldTotal   = query.record().indexOf("total");
      int fieldName    = query.record().indexOf("name");
      int fieldUStr    = query.record().indexOf("unitstr");
      int fieldPayment = query.record().indexOf("payment");
      int fieldCPayment = query.record().indexOf("completePayment");
      int fieldSoid = query.record().indexOf("soId");
      int fieldIsG = query.record().indexOf("isGroup");
      int fieldDDT = query.record().indexOf("deliveryDateTime");
      int fieldTax = query.record().indexOf("tax");
      
      info.transactionid     = id;
      info.position      = query.value(fieldPosition).toInt();
      info.productCode   = query.value(fieldProductCode).toULongLong();
      info.qty           = query.value(fieldQty).toDouble();
      info.points        = query.value(fieldPoints).toDouble();
      info.unitStr       = query.value(fieldUStr).toString();
      info.cost          = query.value(fieldCost).toDouble();
      info.price         = query.value(fieldPrice).toDouble();
      info.disc          = query.value(fieldDisc).toDouble();
      info.total         = query.value(fieldTotal).toDouble();
      info.name          = query.value(fieldName).toString();
      info.payment       = query.value(fieldPayment).toDouble();
      info.completePayment  = query.value(fieldCPayment).toBool();
      info.soId          = query.value(fieldSoid).toString();
      info.isGroup       = query.value(fieldIsG).toBool();
      info.deliveryDateTime=query.value(fieldDDT).toDateTime();
      info.tax           = query.value(fieldTax).toDouble();
      result.append(info);
    }
  }
  else {
    setError(query.lastError().text());
    qDebug()<<"Get TransactionItems error:"<<query.lastError().text();
  }
  return result;
}

//BALANCES

qulonglong Azahar::insertBalance(BalanceInfo info)
{
  qulonglong result =0;
  if (!db.isOpen()) db.open();
  if (db.isOpen())
  {
    QSqlQuery queryBalance(db);
    queryBalance.prepare("INSERT INTO balances (balances.datetime_start, balances.datetime_end, balances.userid, balances.usern, balances.initamount, balances.in, balances.out, balances.cash, balances.card, balances.transactions, balances.terminalnum, balances.cashflows, balances.done) VALUES (:date_start, :date_end, :userid, :user, :initA, :in, :out, :cash, :card, :transactions, :terminalNum, :cashflows, :isDone)");
    queryBalance.bindValue(":date_start", info.dateTimeStart.toString("yyyy-MM-dd hh:mm:ss"));
    queryBalance.bindValue(":date_end", info.dateTimeEnd.toString("yyyy-MM-dd hh:mm:ss"));
    queryBalance.bindValue(":userid", info.userid);
    queryBalance.bindValue(":user", info.username);
    queryBalance.bindValue(":initA", info.initamount);
    queryBalance.bindValue(":in", info.in);
    queryBalance.bindValue(":out", info.out);
    queryBalance.bindValue(":cash", info.cash);
    queryBalance.bindValue(":card", info.card);
    queryBalance.bindValue(":transactions", info.transactions);
    queryBalance.bindValue(":terminalNum", info.terminal);
    queryBalance.bindValue(":cashflows", info.cashflows);
    queryBalance.bindValue(":isDone", info.done);

    if (!queryBalance.exec() ) {
      int errNum = queryBalance.lastError().number();
      QSqlError::ErrorType errType = queryBalance.lastError().type();
      QString errStr = queryBalance.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
      setError(details);
    } else result = queryBalance.lastInsertId().toULongLong();
  }
  return result;
}

BalanceInfo Azahar::getBalanceInfo(qulonglong id)
{
  BalanceInfo info;
  info.id = 0;
  QString qry = QString("SELECT * FROM balances WHERE id=%1").arg(id);
  QSqlQuery query;
  if (!query.exec(qry)) { qDebug()<<query.lastError(); }
  else {
    while (query.next()) {
      int fieldId = query.record().indexOf("id");
      int fieldDtStart = query.record().indexOf("datetime_start");
      int fieldDtEnd   = query.record().indexOf("datetime_end");
      int fieldUserId  = query.record().indexOf("userid");
      int fieldUsername= query.record().indexOf("usern");
      int fieldInitAmount = query.record().indexOf("initamount");
      int fieldIn      = query.record().indexOf("in");
      int fieldOut     = query.record().indexOf("out");
      int fieldCash    = query.record().indexOf("cash");
      int fieldTransactions    = query.record().indexOf("transactions");
      int fieldCard    = query.record().indexOf("card");
      int fieldTerminalNum   = query.record().indexOf("terminalnum");
      int fieldCashFlows     = query.record().indexOf("cashflows");
      int fieldDone    = query.record().indexOf("done");
      info.id     = query.value(fieldId).toULongLong();
      info.dateTimeStart = query.value(fieldDtStart).toDateTime();
      info.dateTimeEnd   = query.value(fieldDtEnd).toDateTime();
      info.userid   = query.value(fieldUserId).toULongLong();
      info.username= query.value(fieldUsername).toString();
      info.initamount = query.value(fieldInitAmount).toDouble();
      info.in      = query.value(fieldIn).toDouble();
      info.out = query.value(fieldOut).toDouble();
      info.cash   = query.value(fieldCash).toDouble();
      info.card   = query.value(fieldCard).toDouble();
      info.transactions= query.value(fieldTransactions).toString();
      info.terminal = query.value(fieldTerminalNum).toInt();
      info.cashflows= query.value(fieldCashFlows).toString();
      info.done = query.value(fieldDone).toBool();
    }
  }
  return info;
}

bool Azahar::updateBalance(BalanceInfo info)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  if (db.isOpen())
  {
    QSqlQuery queryBalance(db);
    queryBalance.prepare("UPDATE balances SET balances.datetime_start=:date_start, balances.datetime_end=:date_end, balances.userid=:userid, balances.usern=:user, balances.initamount=:initA, balances.in=:in, balances.out=:out, balances.cash=:cash, balances.card=:card, balances.transactions=:transactions, balances.terminalnum=:terminalNum, cashflows=:cashflows, done=:isDone WHERE balances.id=:bid");
    queryBalance.bindValue(":date_start", info.dateTimeStart.toString("yyyy-MM-dd hh:mm:ss"));
    queryBalance.bindValue(":date_end", info.dateTimeEnd.toString("yyyy-MM-dd hh:mm:ss"));
    queryBalance.bindValue(":userid", info.userid);
    queryBalance.bindValue(":user", info.username);
    queryBalance.bindValue(":initA", info.initamount);
    queryBalance.bindValue(":in", info.in);
    queryBalance.bindValue(":out", info.out);
    queryBalance.bindValue(":cash", info.cash);
    queryBalance.bindValue(":card", info.card);
    queryBalance.bindValue(":transactions", info.transactions);
    queryBalance.bindValue(":terminalNum", info.terminal);
    queryBalance.bindValue(":cashflows", info.cashflows);
    queryBalance.bindValue(":bid", info.id);
    queryBalance.bindValue(":isDone", info.done);
    
    if (!queryBalance.exec() ) {
      int errNum = queryBalance.lastError().number();
      QSqlError::ErrorType errType = queryBalance.lastError().type();
      QString errStr = queryBalance.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
      setError(details);
    } else result = true;
  }
  return result;
}

qulonglong Azahar::insertCashFlow(CashFlowInfo info)
{
  qulonglong result =0;
  if (!db.isOpen()) db.open();
  if (db.isOpen())
  {
    QSqlQuery query(db);
    query.prepare("INSERT INTO cashflow ( cashflow.userid, cashflow.type, cashflow.reason, cashflow.amount, cashflow.date, cashflow.time, cashflow.terminalnum) VALUES (:userid, :type, :reason, :amount, :date, :time,  :terminalNum)");
    query.bindValue(":date", info.date.toString("yyyy-MM-dd"));
    query.bindValue(":time", info.time.toString("hh:mm:ss"));
    query.bindValue(":userid", info.userid);
    query.bindValue(":terminalNum", info.terminalNum);
    query.bindValue(":reason", info.reason);
    query.bindValue(":amount", info.amount);
    query.bindValue(":type", info.type);
    
    if (!query.exec() ) {
      int errNum = query.lastError().number();
      QSqlError::ErrorType errType = query.lastError().type();
      QString errStr = query.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),errStr);
      setError(details);
    } else result = query.lastInsertId().toULongLong();
  }
  return result;
}

QList<CashFlowInfo> Azahar::getCashFlowInfoList(const QList<qulonglong> &idList)
{
  QList<CashFlowInfo> result;
  result.clear();
  if (idList.count() == 0) return result;
  QSqlQuery query(db);

  foreach(qulonglong currId, idList) {
    QString qry = QString(" \
    SELECT CF.id as id, \
    CF.type as type, \
    CF.userid as userid, \
    CF.amount as amount, \
    CF.reason as reason, \
    CF.date as date, \
    CF.time as time, \
    CF.terminalNum as terminalNum, \
    CFT.text as typeStr \
    FROM cashflow AS CF, cashflowtypes AS CFT \
    WHERE id=%1 AND (CFT.typeid = CF.type) ORDER BY CF.id;").arg(currId);
    if (query.exec(qry)) {
      while (query.next()) {
        CashFlowInfo info;
        int fieldId      = query.record().indexOf("id");
        int fieldType    = query.record().indexOf("type");
        int fieldUserId  = query.record().indexOf("userid");
        int fieldAmount  = query.record().indexOf("amount");
        int fieldReason  = query.record().indexOf("reason");
        int fieldDate    = query.record().indexOf("date");
        int fieldTime    = query.record().indexOf("time");
        int fieldTermNum = query.record().indexOf("terminalNum");
        int fieldTStr    = query.record().indexOf("typeStr");

        info.id          = query.value(fieldId).toULongLong();
        info.type        = query.value(fieldType).toULongLong();
        info.userid      = query.value(fieldUserId).toULongLong();
        info.amount      = query.value(fieldAmount).toDouble();
        info.reason      = query.value(fieldReason).toString();
        info.typeStr     = query.value(fieldTStr).toString();
        info.date        = query.value(fieldDate).toDate();
        info.time        = query.value(fieldTime).toTime();
        info.terminalNum = query.value(fieldTermNum).toULongLong();
        result.append(info);
        qDebug()<<__FUNCTION__<<" Cash Flow:"<<info.id<<" type:"<<info.type<<" reason:"<<info.reason;
      }
    }
    else {
      setError(query.lastError().text());
    }
  } //foreach
  return result;
}

QList<CashFlowInfo> Azahar::getCashFlowInfoList(const QDateTime &start, const QDateTime &end)
{
  QList<CashFlowInfo> result;
  result.clear();
  QSqlQuery query(db);

  query.prepare(" \
  SELECT CF.id as id, \
  CF.type as type, \
  CF.userid as userid, \
  CF.amount as amount, \
  CF.reason as reason, \
  CF.date as date, \
  CF.time as time, \
  CF.terminalNum as terminalNum, \
  CFT.text as typeStr \
  FROM cashflow AS CF, cashflowtypes AS CFT \
  WHERE (date BETWEEN :dateSTART AND :dateEND) AND (CFT.typeid = CF.type) ORDER BY CF.id");
  query.bindValue(":dateSTART", start.date());
  query.bindValue(":dateEND", end.date());
  if (query.exec()) {
    while (query.next()) {
      QTime ttime = query.value(query.record().indexOf("time")).toTime();
      if ( (ttime >= start.time()) &&  (ttime <= end.time()) ) {
        //its inside the requested time period.
        CashFlowInfo info;
        int fieldId      = query.record().indexOf("id");
        int fieldType    = query.record().indexOf("type");
        int fieldUserId  = query.record().indexOf("userid");
        int fieldAmount  = query.record().indexOf("amount");
        int fieldReason  = query.record().indexOf("reason");
        int fieldDate    = query.record().indexOf("date");
        int fieldTime    = query.record().indexOf("time");
        int fieldTermNum = query.record().indexOf("terminalNum");
        int fieldTStr    = query.record().indexOf("typeStr");
        
        info.id          = query.value(fieldId).toULongLong();
        info.type        = query.value(fieldType).toULongLong();
        info.userid      = query.value(fieldUserId).toULongLong();
        info.amount      = query.value(fieldAmount).toDouble();
        info.reason      = query.value(fieldReason).toString();
        info.typeStr     = query.value(fieldTStr).toString();
        info.date        = query.value(fieldDate).toDate();
        info.time        = query.value(fieldTime).toTime();
        info.terminalNum = query.value(fieldTermNum).toULongLong();
        result.append(info);
      } //if time...
    } //while
  }// if query
  else {
    setError(query.lastError().text());
  }
  return result;
}

//Card Types
QHash<QString, int> Azahar::getCardTypesHash()
{
    QHash<QString, int> result;
    result.clear();
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
        QSqlQuery myQuery(db);
        if (myQuery.exec("select * from cardtypes;")) {
            while (myQuery.next()) {
                int fieldId   = myQuery.record().indexOf("typeid");
                int fieldText = myQuery.record().indexOf("text");
                int id = myQuery.value(fieldId).toInt();
                QString text = myQuery.value(fieldText).toString();
                result.insert(text, id);
            }
        }
        else {
            qDebug()<<"ERROR: "<<myQuery.lastError();
        }
    }
    return result;
}

QStringList Azahar::getCardTypes()
{
    QStringList result;
    QSqlQuery query(db);
    QString qstr = QString("select text from cardtypes;");
    if (query.exec(qstr)) {
        while (query.next()) {
            int fieldText = query.record().indexOf("text");
            result.append(query.value(fieldText).toString());
        }
    }
    else {
        setError(query.lastError().text());
    }
    return result;
}

QString  Azahar::getCardTypeStr(qulonglong type)
{
    QString result;
    QSqlQuery query(db);
    QString qstr = QString("select text from cardtypes where cardtypes.typeid=%1;").arg(type);
    if (query.exec(qstr)) {
        while (query.next()) {
            int fieldText = query.record().indexOf("text");
            result = query.value(fieldText).toString();
        }
    }
    else {
        setError(query.lastError().text());
    }
    return result;
}

qulonglong  Azahar::getCardTypeId(QString type)
{
    qulonglong result=0;
    QSqlQuery query(db);
    QString qstr = QString("select typeid from cardtypes where cardtypes.text='%1';").arg(type);
    if (query.exec(qstr)) {
        while (query.next()) {
            int fieldText = query.record().indexOf("typeid");
            result = query.value(fieldText).toULongLong();
        }
    }
    else {
        setError(query.lastError().text());
    }
    return result;
}

//TransactionTypes
QString  Azahar::getPayTypeStr(qulonglong type)
{
  QString result;
  QSqlQuery query(db);
  QString qstr = QString("select text from paytypes where paytypes.typeid=%1;").arg(type);
  if (query.exec(qstr)) {
    while (query.next()) {
      int fieldText = query.record().indexOf("text");
      result = query.value(fieldText).toString();
    }
  }
  else {
    setError(query.lastError().text());
  }
  return result;
}

qulonglong  Azahar::getPayTypeId(QString type)
{
  qulonglong result=0;
  QSqlQuery query(db);
  QString qstr = QString("select typeid from paytypes where paytypes.text='%1';").arg(type);
  if (query.exec(qstr)) {
    while (query.next()) {
      int fieldText = query.record().indexOf("typeid");
      result = query.value(fieldText).toULongLong();
    }
  }
  else {
    setError(query.lastError().text());
  }
  return result;
}


//LOGS

bool Azahar::insertLog(const qulonglong &userid, const QDate &date, const QTime &time, const QString actionStr)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO logs (userid, date, time, action) VALUES(:userid, :date, :time, :action);");
    query.bindValue(":userid", userid);
    query.bindValue(":date", date.toString("yyyy-MM-dd"));
    query.bindValue(":time", time.toString("hh:mm"));
    query.bindValue(":action", actionStr);
    if (!query.exec()) {
      setError(query.lastError().text());
      qDebug()<<"ERROR ON SAVING LOG:"<<query.lastError().text();
    } else result = true;
  }
  return result;
}

bool Azahar::getConfigFirstRun()
{
  bool result = false;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("select firstrun from config;"))) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("firstrun");
        QString value = myQuery.value(fieldText).toString();
        qDebug()<<"firstRun VALUE="<<value;
        if (value == "yes, it is February 6 1978")
          result = true;
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

bool Azahar::getConfigTaxIsIncludedInPrice()
{
  bool result = false;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("select taxIsIncludedInPrice from config;"))) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("taxIsIncludedInPrice");
        result = myQuery.value(fieldText).toBool();
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

void Azahar::cleanConfigFirstRun()
{
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("update config set firstrun='yes, i like the rainy days';"))) {
      qDebug()<<"Change config firstRun...";
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
}

void Azahar::setConfigTaxIsIncludedInPrice(bool option)
{
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("update config set taxIsIncludedInPrice=%1;").arg(option))) {
      qDebug()<<"Change config taxIsIncludedInPrice...";
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
}

QPixmap  Azahar::getConfigStoreLogo()
{
  QPixmap result;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("select storeLogo from config;"))) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("storeLogo");
        result.loadFromData(myQuery.value(fieldText).toByteArray());
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

QString  Azahar::getConfigStoreName()
{
  QString result;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("select storeName from config;"))) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("storeName");
        result = myQuery.value(fieldText).toString();
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

QString  Azahar::getConfigStoreAddress()
{
  QString result;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("select storeAddress from config;"))) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("storeAddress");
        result = myQuery.value(fieldText).toString();
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

QString  Azahar::getConfigStorePhone()
{
  QString result;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("select storePhone from config;"))) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("storePhone");
        result = myQuery.value(fieldText).toString();
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

bool     Azahar::getConfigSmallPrint()
{
  bool result = false;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("select smallPrint from config;"))) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("smallPrint");
        result = myQuery.value(fieldText).toBool();
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

bool     Azahar::getConfigLogoOnTop()
{
  bool result = false;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("select logoOnTop from config;"))) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("logoOnTop");
        result = myQuery.value(fieldText).toBool();
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

bool     Azahar::getConfigUseCUPS()
{
  bool result = false;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("select useCUPS from config;"))) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("useCUPS");
        result = myQuery.value(fieldText).toBool();
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

QString     Azahar::getConfigDbVersion()
{
    QString result = "";
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
        QSqlQuery myQuery(db);
        if (myQuery.exec(QString("select db_version from config;"))) {
            while (myQuery.next()) {
                int fieldText = myQuery.record().indexOf("db_version");
                result = myQuery.value(fieldText).toString();
            }
        }
        else {
            qDebug()<<"ERROR: "<<myQuery.lastError();
        }
    }
    return result;
}


void   Azahar::setConfigStoreLogo(const QByteArray &baPhoto)
{
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    myQuery.prepare("update config set storeLogo=:logo;");
    myQuery.bindValue(":logo", baPhoto);
    if (myQuery.exec()) {
      qDebug()<<"Change config store logo...";
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
}

void   Azahar::setConfigStoreName(const QString &str)
{
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("update config set storeName='%1';").arg(str))) {
      qDebug()<<"Change config storeName...";
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
}

void   Azahar::setConfigStoreAddress(const QString &str)
{
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("update config set storeAddress='%1';").arg(str))) {
      qDebug()<<"Change config storeAddress...";
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
}

void   Azahar::setConfigStorePhone(const QString &str)
{
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("update config set storePhone='%1';").arg(str))) {
      qDebug()<<"Change config taxIsIncludedInPrice...";
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
}

void   Azahar::setConfigSmallPrint(bool yes)
{
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("update config set smallPrint=%1;").arg(yes))) {
      qDebug()<<"Change config SmallPrint...";
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
}

void   Azahar::setConfigUseCUPS(bool yes)
{
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("update config set useCUPS=%1;").arg(yes))) {
      qDebug()<<"Change config useCUPS...";
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
}

void   Azahar::setConfigLogoOnTop(bool yes)
{
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("update config set logoOnTop=%1;").arg(yes))) {
      qDebug()<<"Change config logoOnTop...";
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
}


//SPECIAL ORDERS
QList<SpecialOrderInfo> Azahar::getAllSOforSale(qulonglong saleId)
{
  QList<SpecialOrderInfo> list;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QString qry = QString("SELECT orderid,saleid from special_orders where saleid=%1").arg(saleId);
    QSqlQuery query(db);
    if (!query.exec(qry)) {
      int errNum = query.lastError().number();
      QSqlError::ErrorType errType = query.lastError().type();
      QString error = query.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),error);
      setError(i18n("Error getting special Order information, id: %1, Rows affected: %2", saleId,query.size()));
    }
    else {
      while (query.next()) {
        int fieldId  = query.record().indexOf("orderid");
        qulonglong num = query.value(fieldId).toULongLong();
        SpecialOrderInfo soInfo = getSpecialOrderInfo(num);
        list.append(soInfo);
      }
    }
  }
  return list;
}

//NOTE: Here the question is, what status to take into account? pending,inprogress,ready...
//      We will return all with status < 3 .
QList<SpecialOrderInfo> Azahar::getAllReadySOforSale(qulonglong saleId)
{
  QList<SpecialOrderInfo> list;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QString qry = QString("SELECT orderid,saleid from special_orders where saleid=%1 and status<3").arg(saleId);
    QSqlQuery query(db);
    if (!query.exec(qry)) {
      int errNum = query.lastError().number();
      QSqlError::ErrorType errType = query.lastError().type();
      QString error = query.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),error);
      setError(i18n("Error getting special Order information, id: %1, Rows affected: %2", saleId,query.size()));
    }
    else {
      while (query.next()) {
        int fieldId  = query.record().indexOf("orderid");
        qulonglong num = query.value(fieldId).toULongLong();
        SpecialOrderInfo soInfo = getSpecialOrderInfo(num);
        list.append(soInfo);
      }
    }
  }
  return list;
}

int  Azahar::getReadySOCountforSale(qulonglong saleId)
{
  int count=0;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QString qry = QString("SELECT orderid from special_orders where saleid=%1 and status<3").arg(saleId);
    QSqlQuery query(db);
    if (!query.exec(qry)) {
      int errNum = query.lastError().number();
      QSqlError::ErrorType errType = query.lastError().type();
      QString error = query.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),error);
      setError(i18n("Error getting special Order information, id: %1, Rows affected: %2", saleId,query.size()));
    }
    else {
//       while (query.next()) {
//         count++;
//       }
    count = query.size();
    }
  }
  return count;
}

void Azahar::specialOrderSetStatus(qulonglong id, int status)
{
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("update special_orders set status=%1 where orderid=%2;").arg(status).arg(id))) {
      qDebug()<<"Status Order updated";
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
}

void Azahar::soTicketSetStatus(qulonglong ticketId, int status)
{
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("update special_orders set status=%1 where saleid=%2;").arg(status).arg(ticketId))) {
      qDebug()<<"Status Order updated";
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
}

QString Azahar::getSpecialOrderProductsStr(qulonglong id)
{
  QString result = "";
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("select groupElements from special_orders where orderid=%1;").arg(id))) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("groupElements");
        result = myQuery.value(fieldText).toString();
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

QList<ProductInfo> Azahar::getSpecialOrderProductsList(qulonglong id)
{
  QList<ProductInfo> pList;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QString ge = getSpecialOrderProductsStr(id);
    QStringList pq = ge.split(",");
    foreach(QString str, pq) {
      qulonglong c = str.section('/',0,0).toULongLong();
      double     q = str.section('/',1,1).toDouble();
      //get info
      ProductInfo pi = getProductInfo(QString::number(c));
      pi.qtyOnList = q;
      pList.append(pi);
    }
  }
  return pList;
}

QString  Azahar::getSONotes(qulonglong id)
{
  QString result = "";
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("select notes from special_orders where orderid=%1;").arg(id))) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("notes");
        result = myQuery.value(fieldText).toString();
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

qulonglong Azahar::insertSpecialOrder(SpecialOrderInfo info)
{
  qulonglong result = 0;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query.prepare("INSERT INTO special_orders (name, price, qty, cost, units, groupElements, status, saleid, notes, payment, completePayment, dateTime, deliveryDateTime,clientId,userId) VALUES (:name, :price, :qty, :cost, :units,  :groupE, :status, :saleId, :notes, :payment, :completeP, :dateTime, :deliveryDT, :client, :user);");
  query.bindValue(":name", info.name);
  query.bindValue(":price", info.price);
  query.bindValue(":qty", info.qty);
  query.bindValue(":cost", info.cost);
  query.bindValue(":status", info.status);
  query.bindValue(":units", info.units);
  query.bindValue(":groupE", info.groupElements);
  query.bindValue(":saleId", info.saleid);
  query.bindValue(":notes", info.notes);
  query.bindValue(":payment", info.payment);
  query.bindValue(":completeP", info.completePayment);
  query.bindValue(":dateTime", info.dateTime);
  query.bindValue(":deliveryDT", info.deliveryDateTime);
  query.bindValue(":user", info.userId);
  query.bindValue(":client", info.clientId);
  
  if (!query.exec()) setError(query.lastError().text()); else {
    result=query.lastInsertId().toULongLong();
  }
  
  return result;
}

//saleid, dateTime/userid/clientid are not updated.
bool Azahar::updateSpecialOrder(SpecialOrderInfo info)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query.prepare("UPDATE special_orders SET  name=:name, price=:price, qty=:qty, cost=:cost, units=:units,  groupElements=:groupE, status=:status, notes=:notes, payment=:payment, completePayment=:completeP, deliveryDateTime=:deliveryDT WHERE orderid=:code;");
  query.bindValue(":code", info.orderid);
  query.bindValue(":name", info.name);
  query.bindValue(":price", info.price);
  query.bindValue(":qty", info.qty);
  query.bindValue(":cost", info.cost);
  query.bindValue(":status", info.status);
  query.bindValue(":units", info.units);
  query.bindValue(":groupE", info.groupElements);
  query.bindValue(":notes", info.notes);
  query.bindValue(":payment", info.payment);
  query.bindValue(":completeP", info.completePayment);
  query.bindValue(":deliveryDT", info.deliveryDateTime);
  
  if (!query.exec()) setError(query.lastError().text()); else result=true;
  return result;
}

bool Azahar::decrementSOStock(qulonglong id, double qty, QDate date)
{
  bool result = true;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);

  QList<QString> lelem = getSpecialOrderProductsStr(id).split(",");
  foreach(QString ea, lelem) {
    qulonglong c = ea.section('/',0,0).toULongLong();
    double     q = ea.section('/',1,1).toDouble();
    //FOR EACH ELEMENT, DECREMENT PRODUCT STOCK
    result = result && decrementProductStock(c, q*qty, date);
  }
  
  return result;
}

bool Azahar::deleteSpecialOrder(qulonglong id)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query = QString("DELETE FROM special_orders WHERE orderid=%1").arg(id);
  if (!query.exec()) setError(query.lastError().text()); else result=true;
  return result;
}

SpecialOrderInfo Azahar::getSpecialOrderInfo(qulonglong id)
{
  SpecialOrderInfo info;
  info.orderid=0;
  info.name="Ninguno";
  info.price=0;

  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QString qry = QString("SELECT * from special_orders where orderid=%1").arg(id);
    QSqlQuery query(db);
    if (!query.exec(qry)) {
      int errNum = query.lastError().number();
      QSqlError::ErrorType errType = query.lastError().type();
      QString error = query.lastError().text();
      QString details = i18n("Error #%1, Type:%2\n'%3'",QString::number(errNum), QString::number(errType),error);
      setError(i18n("Error getting special Order information, id: %1, Rows affected: %2", id,query.size()));
    }
    else {
      while (query.next()) {
        int fieldDesc = query.record().indexOf("name");
        int fieldPrice= query.record().indexOf("price");
        int fieldQty= query.record().indexOf("qty");
        int fieldCost= query.record().indexOf("cost");
        int fieldUnits= query.record().indexOf("units");
        int fieldStatus= query.record().indexOf("status");
        int fieldSaleId= query.record().indexOf("saleid");
        int fieldGroupE = query.record().indexOf("groupElements");
        int fieldPayment = query.record().indexOf("payment");
        int fieldCPayment = query.record().indexOf("completePayment");
        int fieldDateT   = query.record().indexOf("dateTime");
        int fieldDDT     = query.record().indexOf("deliveryDateTime");
        int fieldNotes   = query.record().indexOf("notes");
        int fieldClientId = query.record().indexOf("clientId");
        int fieldUserId = query.record().indexOf("userId");
        
        info.orderid=id;
        info.name      = query.value(fieldDesc).toString();
        info.price    = query.value(fieldPrice).toDouble();
        info.qty      = query.value(fieldQty).toDouble();
        info.cost     = query.value(fieldCost).toDouble();
        info.units    = query.value(fieldUnits).toInt();
        info.status   = query.value(fieldStatus).toInt();
        info.saleid   = query.value(fieldSaleId).toULongLong();
        info.groupElements = query.value(fieldGroupE).toString();
        info.payment  = query.value(fieldPayment).toDouble();
        info.completePayment  = query.value(fieldCPayment).toBool();
        info.dateTime = query.value(fieldDateT).toDateTime();
        info.deliveryDateTime = query.value(fieldDDT).toDateTime();
        info.notes = query.value(fieldNotes).toString();
        info.clientId = query.value(fieldClientId).toULongLong();
        info.userId = query.value(fieldUserId).toULongLong();
        //get specialOrder Discounts
        info.disc = getSpecialOrderAverageDiscount(info.orderid)/100; //in percentage.
      }
      //get units descriptions
      qry = QString("SELECT * from measures WHERE id=%1").arg(info.units);
      QSqlQuery query3(db);
      if (query3.exec(qry)) {
        while (query3.next()) {
          int fieldUD = query3.record().indexOf("text");
          info.unitStr=query3.value(fieldUD).toString();
        }//query3 - get descritptions
      }
    }
  }
  return info;
}

// NOTE: This returns the compound tax that effectively apply to the amount for the specialOrder,
//       regardless of the equitative tax for each product. It means that the tax returned is the
//       EFFECTIVE tax for the total amount, instead of an average tax (total/numberOfProducts)..
//       The average tax is not accurate if there are different products with very different taxes.
//       For example:
//              A SO with TWO products :
//                      product 1: Price: 10, tax:15%
//                      product 2: Price  100, tax 1%
//              The average tax is 8%, its equally for the two products but the second one has a lower tax.
//              The tax charged to the group with the average tax is $8.8
//              The tax charged to the group with each product tax is $2.15
//              This means the average tax is not accurate for all cases.
//       Thats why this 'effective' tax average is returned.
double Azahar::getSpecialOrderAverageTax(qulonglong id, AzaharRTypes returnType)
{
  double price = 0;
  double taxMoney = 0;
  double tax = 0;

  if ( id <= 0 ) return 0;
  
  QList<ProductInfo> pList = getSpecialOrderProductsList(id);
  foreach( ProductInfo info, pList) {
    double discount = 0; double pWOtax= 0;
    if (info.validDiscount) discount = info.price*info.qtyOnList*(info.discpercentage/100);

    if ( !getConfigTaxIsIncludedInPrice() )
      pWOtax = info.price;
    else
      pWOtax= info.price/(1+((info.tax+info.extratax)/100));

    price += (pWOtax*info.qtyOnList)-discount;
    taxMoney += (info.tax/100)*((info.qtyOnList*pWOtax)-discount); //info.totaltax*info.qtyOnList;
    //qDebug()<<" < EACH ONE > price: "<<(pWOtax*info.qtyOnList)-discount<<" taxMoney: "<<(info.tax/100)*((pWOtax*info.qtyOnList)-discount)
    //<<" Discount:"<<discount<<" pWOTax:"<<pWOtax;
  }

  foreach(ProductInfo info, pList) {
    tax += (info.totaltax*info.qtyOnList/price)*100;
  }

  qDebug()<<"\n <<<<<<< GetSpecialOrderAverageTax    :%"<<tax<<" $"<<taxMoney<<" Based Price:"<<price<<">>>>>>>>\n";

  if (returnType == rtMoney) 
    return taxMoney;
  else
    return tax;
}

///This gets discounts on a special order based on its raw products discount, returned in %.
double Azahar::getSpecialOrderAverageDiscount(qulonglong id)
{
  double price = 0;
  double discMoney = 0;
  double disc = 0;

  if ( id <= 0 ) return 0;
  
  QList<ProductInfo> pList = getSpecialOrderProductsList(id);
  foreach( ProductInfo info, pList) {
    price += info.price*info.qtyOnList;
    if (info.validDiscount  && !info.isNotDiscountable)
      discMoney += (info.discpercentage/100)*info.price*info.qtyOnList;
    //qDebug()<<" < EACH ONE > price: "<<info.price*info.qtyOnList<<" discMoney: "<<(info.discpercentage/100)*info.price*info.qtyOnList;
  }
  
  foreach(ProductInfo info, pList) {
      if (info.validDiscount  && !info.isNotDiscountable)
        disc += ( ((info.discpercentage/100)*info.price*info.qtyOnList)/price )*100;
    //qDebug()<<" < SO DISCOUNT >  qtyOnList:"<<info.qtyOnList<<" discMoney for product: "<<(info.discpercentage/100)*info.price*info.qtyOnList<<" SO price:"<<price<<" discMoney for group:"<<discMoney<<" DISCOUNT % for group:"<< disc;
  }

  qDebug()<<"\n <<<<<<< GetSpecialOrderAverageDiscount    :%"<<disc<<" $"<<discMoney<<" Based Price:"<<price<<">>>>>>>>\n";
  return disc;
}

int Azahar::getSpecialOrderNonDiscountables(qulonglong id)
{
    int count = 0;
    if ( id <= 0 ) return 0;
    
    QList<ProductInfo> pList = getSpecialOrderProductsList(id);
    foreach(ProductInfo info, pList) {
        if (info.isNotDiscountable)
            count++;
    }
    
    return count;
}


QStringList Azahar::getStatusList()
{
  QStringList result;
  result.clear();
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec("select text from so_status;")) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("text");
        QString text = myQuery.value(fieldText).toString();
        result.append(text);
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

QStringList Azahar::getStatusListExceptDelivered()
{
  QStringList result;
  result.clear();
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("select text from so_status where id!=%1;").arg(stDelivered))) {
      while (myQuery.next()) {
        int fieldText = myQuery.record().indexOf("text");
        QString text = myQuery.value(fieldText).toString();
        result.append(text);
      }
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
  return result;
}

int Azahar::getStatusId(QString texto)
{
  qulonglong result=0;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    QString qryStr = QString("SELECT so_status.id FROM so_status WHERE text='%1';").arg(texto);
    if (myQuery.exec(qryStr) ) {
      while (myQuery.next()) {
        int fieldId   = myQuery.record().indexOf("id");
        qulonglong id= myQuery.value(fieldId).toULongLong();
        result = id;
      }
    }
    else {
      setError(myQuery.lastError().text());
    }
  }
  return result;
}

QString Azahar::getRandomMessage(QList<qulonglong> &excluded, const int &season)
{
  QString result;
  QString firstMsg;
  qulonglong firstId = 0;
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    QString qryStr = QString("SELECT message,id FROM random_msgs WHERE season=%1 order by count ASC;").arg(season);
    if (myQuery.exec(qryStr) ) {
      while (myQuery.next()) {
        int fieldId      = myQuery.record().indexOf("id");
        int fieldMsg     = myQuery.record().indexOf("message");
        qulonglong id    = myQuery.value(fieldId).toULongLong();
        if ( firstMsg.isEmpty() ) {
          firstMsg = myQuery.value(fieldMsg).toString(); //get the first msg.
          firstId  = myQuery.value(fieldId).toULongLong();
        }
        qDebug()<<"Examining msg Id: "<<id;
        //check if its not on the excluded list.
        if ( !excluded.contains(id) ) {
          //ok, return the msg, increment count.
          result = myQuery.value(fieldMsg).toString();
          randomMsgIncrementCount(id);
          //modify the excluded list, insert this one.
          excluded.append(id);
          //we exit from the while loop.
          qDebug()<<" We got msg:"<<result;
          break;
        }
      }
    }
    else {
      setError(myQuery.lastError().text());
    }
  }
  if (result.isEmpty() && firstId > 0) {
    result = firstMsg;
    randomMsgIncrementCount(firstId);
    excluded << firstId;
    qDebug()<<"Returning the fist message!";
  }
  return result;
}

void Azahar::randomMsgIncrementCount(qulonglong id)
{
  if (!db.isOpen()) db.open();
  if (db.isOpen()) {
    QSqlQuery myQuery(db);
    if (myQuery.exec(QString("update random_msgs set count=count+1 where id=%1;").arg(id))) {
      qDebug()<<"Random Messages Count updated";
    }
    else {
      qDebug()<<"ERROR: "<<myQuery.lastError();
    }
  }
}

bool Azahar::insertRandomMessage(const QString &msg, const int &season)
{
  bool result = false;
  if (!db.isOpen()) db.open();
  QSqlQuery query(db);
  query.prepare("INSERT INTO random_msgs (message, season, count) VALUES (:message, :season, :count);");
  query.bindValue(":msg", msg);
  query.bindValue(":season", season);
  query.bindValue(":count", 0);
  if (!query.exec()) {
    setError(query.lastError().text());
  }
  else result=true;
  return result;
}


CurrencyInfo Azahar::getCurrency(const qulonglong &id)
{
    CurrencyInfo result;
    result.id = 0;
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
        QSqlQuery myQuery(db);
        if (myQuery.exec(QString("select * from currencies where id=%1;").arg(id))) {
            while (myQuery.next()) {
                int fieldName   = myQuery.record().indexOf("name");
                int fieldFactor = myQuery.record().indexOf("factor");
                result.name   = myQuery.value(fieldName).toString();
                result.factor = myQuery.value(fieldFactor).toDouble();
                result.id     = id;
            }
        }
        else {
            qDebug()<<"ERROR: "<<myQuery.lastError();
        }
    }
    return result;
}

CurrencyInfo Azahar::getCurrency(const QString &name)
{
    CurrencyInfo result;
    result.id = 0;
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
        QSqlQuery myQuery(db);
        if (myQuery.exec(QString("select * from currencies where name='%1';").arg(name))) {
            while (myQuery.next()) {
                int fieldName   = myQuery.record().indexOf("name");
                int fieldFactor = myQuery.record().indexOf("factor");
                int fieldId     = myQuery.record().indexOf("id");
                result.name   = myQuery.value(fieldName).toString();
                result.factor = myQuery.value(fieldFactor).toDouble();
                result.id     = myQuery.value(fieldId).toULongLong();
            }
        }
        else {
            qDebug()<<"ERROR: "<<myQuery.lastError();
        }
    }
    return result;
}

QList<CurrencyInfo> Azahar::getCurrencyList()
{
    QList<CurrencyInfo> result;
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
        QSqlQuery myQuery(db);
        if (myQuery.exec(QString("select * from currencies;"))) {
            while (myQuery.next()) {
                CurrencyInfo info;
                int fieldName   = myQuery.record().indexOf("name");
                int fieldFactor = myQuery.record().indexOf("factor");
                int fieldId     = myQuery.record().indexOf("id");
                info.name   = myQuery.value(fieldName).toString();
                info.factor = myQuery.value(fieldFactor).toDouble();
                info.id     = myQuery.value(fieldId).toULongLong();
                result.append(info);
            }
        }
        else {
            qDebug()<<"ERROR: "<<myQuery.lastError();
        }
    }
    return result;
}

bool Azahar::insertCurrency(const QString name, const double &factor)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("INSERT INTO currencies (name,factor) VALUES (:name, :factor);");
    query.bindValue(":name", name);
    query.bindValue(":factor", factor);
    if (!query.exec()) {
        setError(query.lastError().text());
    }
    else result=true;
    return result;
}

bool Azahar::deleteCurrency(const qulonglong &cid)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query = QString("DELETE FROM currencies WHERE id=%1").arg(cid);
    if (!query.exec()) setError(query.lastError().text()); else result=true;
    return result;
}

// Reservations

qulonglong Azahar::insertReservation(ReservationInfo info)
{
    qulonglong result = 0;
    
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("INSERT INTO reservations (transaction_id, client_id, date, status, payment, total, totaltaxes, discount, item_discounts, profit) VALUES (:transaction, :client, :date, :status, :payment, :total, :totaltaxes, :discount, :item_discounts, :profit);");
    query.bindValue(":transaction", info.transaction_id);
    query.bindValue(":client", info.client_id);
    query.bindValue(":payment", info.payment);
    query.bindValue(":date", info.date);
    query.bindValue(":status", info.status);
    query.bindValue(":total", info.total);
    query.bindValue(":totaltaxes", info.totalTaxes);
    query.bindValue(":discount", info.discount);
    query.bindValue(":item_discounts", info.item_discounts);
    query.bindValue(":profit", info.profit);
    
    if (!query.exec()) {
        setError(query.lastError().text());
        qDebug()<< __FUNCTION__ << query.lastError().text();
    }
    else result = query.lastInsertId().toULongLong();
    
    return result;
}

bool Azahar::setReservationStatus(qulonglong id, reservationState state)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("UPDATE reservations SET status=:state WHERE id=:id;");
    query.bindValue(":id", id);
    query.bindValue(":state", state);
    
    if (!query.exec()) setError(query.lastError().text()); else result=true;
    return result;
}

bool Azahar::setTransactionReservationStatus(const qulonglong &trId)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("UPDATE transactions SET state=:status WHERE id=:id;");
    query.bindValue(":id", trId);
    query.bindValue(":status", tReserved);
    
    if (!query.exec()) setError(query.lastError().text()); else result=true;
    return result;
}

double Azahar::getReservationTotalAmount(qulonglong id)
{
    double result=0;
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
        QSqlQuery myQuery(db);
        myQuery.prepare("SELECT total FROM reservations WHERE id=:id;");
        myQuery.bindValue(":id", id);
        if (myQuery.exec() ) {
            while (myQuery.next()) {
                int fieldTotal   = myQuery.record().indexOf("total");
                result = myQuery.value(fieldTotal).toDouble();
            }
        }
        else {
            setError(myQuery.lastError().text());
        }
    }
    return result;
}

//FIXME: On dec 15 2011, i added payments for more than one payment
double Azahar::getReservationPayment(qulonglong id)
{
    double result=0;
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
        QSqlQuery myQuery(db);
        myQuery.prepare("SELECT payment FROM reservations WHERE id=:id;");
        myQuery.bindValue(":id", id);
        if (myQuery.exec() ) {
            while (myQuery.next()) {
                int fieldTotal   = myQuery.record().indexOf("payment");
                result = myQuery.value(fieldTotal).toDouble();
            }
        }
        else {
            setError(myQuery.lastError().text());
        }
    }
    return result;
}

ReservationInfo Azahar::getReservationInfo(const qulonglong &id)
{
    ReservationInfo result;
    result.id=0;
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
        QSqlQuery myQuery(db);
        myQuery.prepare("SELECT * FROM reservations WHERE id=:id;");
        myQuery.bindValue(":id", id);
        if (myQuery.exec() ) {
            while (myQuery.next()) {
                int fieldPayment = myQuery.record().indexOf("payment");
                int fieldClient  = myQuery.record().indexOf("client_id");
                int fieldTr      = myQuery.record().indexOf("transaction_id");
                int fieldDate    = myQuery.record().indexOf("date");
                int fieldStatus  = myQuery.record().indexOf("status");
                int fieldTotal   = myQuery.record().indexOf("total");
                int fieldTaxes   = myQuery.record().indexOf("totaltaxes");
                int fieldDisc    = myQuery.record().indexOf("discount");
                int fielditemD   = myQuery.record().indexOf("item_discounts");
                int fieldProfit  = myQuery.record().indexOf("profit");
                
                result.id = id;
                result.client_id = myQuery.value(fieldClient).toULongLong();
                result.transaction_id = myQuery.value(fieldTr).toULongLong();
                result.total     = myQuery.value(fieldTotal).toDouble();
                result.payment   = myQuery.value(fieldPayment).toDouble();
                result.date      = myQuery.value(fieldDate).toDate();
                result.status    = myQuery.value(fieldStatus).toInt();
                result.totalTaxes= myQuery.value(fieldTaxes).toDouble();
                result.discount  = myQuery.value(fieldDisc).toDouble();
                result.item_discounts = myQuery.value(fielditemD).toString();
                result.profit    = myQuery.value(fieldProfit).toDouble();
            }
        }
        else {
            setError(myQuery.lastError().text());
        }
    }
    return result;
}

ReservationInfo  Azahar::getReservationInfoFromTr(const qulonglong &trId)
{
    ReservationInfo result;
    result.id=0;
    result.transaction_id = 0;
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
        QSqlQuery myQuery(db);
        myQuery.prepare("SELECT * FROM reservations WHERE transaction_id=:id;");
        myQuery.bindValue(":id", trId);
        if (myQuery.exec() ) {
            while (myQuery.next()) {
                int fieldId      = myQuery.record().indexOf("id");
                int fieldPayment = myQuery.record().indexOf("payment");
                int fieldClient  = myQuery.record().indexOf("client_id");
                int fieldTr      = myQuery.record().indexOf("transaction_id");
                int fieldDate    = myQuery.record().indexOf("date");
                int fieldStatus  = myQuery.record().indexOf("status");
                int fieldTotal   = myQuery.record().indexOf("total");
                int fieldTaxes   = myQuery.record().indexOf("totaltaxes");
                int fieldDisc    = myQuery.record().indexOf("discount");
                int fielditemD   = myQuery.record().indexOf("item_discounts");
                int fieldProfit  = myQuery.record().indexOf("profit");
                
                result.id =        myQuery.value(fieldId).toULongLong();
                result.client_id = myQuery.value(fieldClient).toULongLong();
                result.transaction_id = myQuery.value(fieldTr).toULongLong();
                result.total     = myQuery.value(fieldTotal).toDouble();
                result.payment   = myQuery.value(fieldPayment).toDouble();
                result.date      = myQuery.value(fieldDate).toDate();
                result.status    = myQuery.value(fieldStatus).toInt();
                result.totalTaxes= myQuery.value(fieldTaxes).toDouble();
                result.discount  = myQuery.value(fieldDisc).toDouble();
                result.item_discounts = myQuery.value(fielditemD).toString();
                result.profit    = myQuery.value(fieldProfit).toDouble();
            }
        }
        else {
            setError(myQuery.lastError().text());
        }
    }
    return result;
}


bool Azahar::addReservationPayment(const qulonglong &rId, const double &amount  )
{
    bool result = false;
    QDate today = QDate::currentDate();
    
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("INSERT INTO reservation_payments (reservation_id, date, amount) VALUES (:reservation, :date, :amount);");
    query.bindValue(":reservation", rId);
    query.bindValue(":date", today);
    query.bindValue(":amount", amount);
    
    if (!query.exec()) {
        setError(query.lastError().text());
        qDebug()<< __FUNCTION__ << query.lastError().text();
    }
    else result = true;
    
    return result;
}

QList<ReservationPayment> Azahar::getReservationPayments( const qulonglong &rId )
{
    QList<ReservationPayment> list;

    if (!db.isOpen()) db.open();
    QSqlQuery myQuery(db);
    myQuery.prepare("SELECT * FROM reservation_payments WHERE reservation_id=:id;");
    myQuery.bindValue(":id", rId);
    if (myQuery.exec() ) {
        while (myQuery.next()) {
            int fieldR       = myQuery.record().indexOf("reservation_id");
            int fieldId      = myQuery.record().indexOf("id");
            int fieldDate    = myQuery.record().indexOf("date");
            int fieldAmount  = myQuery.record().indexOf("amount");

            ReservationPayment result;
            result.id        = myQuery.value(fieldId).toULongLong();;
            result.reservation_id = myQuery.value(fieldR).toULongLong();
            result.amount     = myQuery.value(fieldAmount).toDouble();
            result.date      = myQuery.value(fieldDate).toDate();
            list.append(result);
        }
    }
    else {
        setError(myQuery.lastError().text());
    }

    return list;
}

bool Azahar::setReservationPayment(const qulonglong &id, const double &amount)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("UPDATE reservations SET payment=:amount WHERE id=:id;");
    query.bindValue(":id", id);
    query.bindValue(":amount", amount);
    
    if (!query.exec()) setError(query.lastError().text()); else result=true;
    return result;
}

CreditInfo Azahar::getCreditInfoForClient(const qulonglong &clientId, const bool &create)
{
    CreditInfo result;
    result.id=0;
    result.clientId = 0;
    result.total = 0;
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
        QSqlQuery myQuery(db);
        myQuery.prepare("SELECT * FROM credits WHERE customerid=:id;");
        myQuery.bindValue(":id", clientId);
        if (myQuery.exec() ) {
            while (myQuery.next()) {
                int fieldId     = myQuery.record().indexOf("id");
                int fieldTotal  = myQuery.record().indexOf("total");
                result.clientId = clientId;
                result.id       = myQuery.value(fieldId).toULongLong();
                result.total    = myQuery.value(fieldTotal).toDouble();
                qDebug()<<__FUNCTION__<<" ----> Got credit:"<<result.id<<" for $"<<result.total;
            }
            qDebug()<<__FUNCTION__<<" Getting CREDIT INFO FOR CLIENT ID:"<<clientId<<" .. create="<<create<<" query size:"<<myQuery.size();
            if (myQuery.size() <= 0 && create) {
                //NO RECORD FOUND, CREATE A NEW ONE.
                if ( getClientInfo(clientId).id > 0 ) {
                    qDebug()<<__FUNCTION__<<" Creating new credit for client ID:"<<clientId;
                    result.clientId = clientId;
                    result.total = 0;
                    qulonglong newId = insertCredit(result);
                    result.id = newId; //now we can return result with the new credit.
                } else { //NOTE: INVALID CLIENT ID. INVALID CREDIT ALSO!
                    result.clientId = 0;
                    result.total = 0;
                    qDebug()<<__FUNCTION__<<" CREDIT NOT FOUND AND NOT CREATED BECAUSE NO CLIENT FOUND WITH ID:"<<clientId;
                }

            }
        }
        else {
            setError(myQuery.lastError().text());
        }
    }
    return result;
}


qulonglong  Azahar::insertCredit(const CreditInfo &info)
{
    qulonglong result = 0;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("INSERT INTO credits (customerid, total) VALUES (:client, :total);");
    query.bindValue(":client", info.clientId);
    query.bindValue(":total", info.total);
    
    if (!query.exec()) {
        setError(query.lastError().text());
        qDebug()<< __FUNCTION__ << query.lastError().text();
    }
    else result = query.lastInsertId().toULongLong();
    return result;
}

bool Azahar::updateCredit(const CreditInfo &info)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("UPDATE credits SET customerid=:client, total=:total WHERE id=:id;");
    query.bindValue(":client", info.clientId);
    query.bindValue(":total", info.total);
    query.bindValue(":id", info.id);
    
    if (!query.exec()) {
        setError(query.lastError().text());
        qDebug()<< __FUNCTION__ << query.lastError().text();
    }
    else result = query.lastInsertId().toULongLong();
    return result;
}


QList<CreditHistoryInfo> Azahar:: getCreditHistoryForClient(const qulonglong &clientId, const int &lastDays)
{
    QList<CreditHistoryInfo> result;
    if (!db.isOpen()) db.open();
    if (db.isOpen()) {
        QDate today = QDate::currentDate();
        QDate limitDate;
        if (lastDays > 0) 
            limitDate = today.addDays(-lastDays);
        else
            limitDate = today.addDays(-30);//default is one month ago.
        QSqlQuery myQuery(db);
        myQuery.prepare("SELECT * FROM credit_history WHERE customerid=:clientId AND date >= :lDate ;");
        myQuery.bindValue(":clientId", clientId);
        myQuery.bindValue(":lDate", limitDate);
        if (myQuery.exec()) {
            while (myQuery.next()) {
                int fieldId     = myQuery.record().indexOf("id");
                int fieldSaleId = myQuery.record().indexOf("saleid");
                int fieldTotal  = myQuery.record().indexOf("amount");
                int fieldDate   = myQuery.record().indexOf("date");
                int fieldTime   = myQuery.record().indexOf("time");
                CreditHistoryInfo info;
                info.id = myQuery.value(fieldId).toULongLong();
                info.customerId = clientId;
                info.saleId   = myQuery.value(fieldSaleId).toULongLong();
                info.amount   = myQuery.value(fieldTotal).toDouble();
                info.date     = myQuery.value(fieldDate).toDate();
                info.time     = myQuery.value(fieldTime).toTime();
                result.append(info);
                qDebug()<<__FUNCTION__<<" Got history for "<<info.customerId<<" SaleID:"<<info.saleId<<" Amount:"<<info.amount;
            }
        }
        else {
            qDebug()<<"ERROR: "<<myQuery.lastError();
        }
    }
    return result;
}

qulonglong  Azahar::insertCreditHistory(const CreditHistoryInfo &info)
{
    qulonglong result = 0;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("INSERT INTO credit_history (customerid, saleid, amount, date, time) VALUES (:clientId, :saleId, :amount, :date, :time);");
    query.bindValue(":clientId", info.customerId);
    query.bindValue(":date", info.date);
    query.bindValue(":time", info.time);
    query.bindValue(":amount", info.amount);
    query.bindValue(":saleId", info.saleId);
    
    if (!query.exec()) {
        setError(query.lastError().text());
        qDebug()<< __FUNCTION__ << query.lastError().text();
    }
    else result = query.lastInsertId().toULongLong();
    return result;
}




//Facturas MX
int Azahar::getFoliosLibres()
{
    /**
     * Devuelve la cantidad de folios libres para uso.
     *
     **/
    
    int result = 0;
    if (!db.isOpen()) db.open();
    QSqlQuery myQuery(db);
    QString qry("SELECT count(numero) as cuenta FROM folios_cbb WHERE valido=true and usado=false;");
    if (myQuery.exec(qry) ) {
        while (myQuery.next()) {
            int cuentaId      = myQuery.record().indexOf("cuenta");
            result = myQuery.value(cuentaId).toULongLong();
        }
    }
    else {
        setError(myQuery.lastError().text());
    }
    return result;
}

QByteArray Azahar::getCbbForSerie( const QString &pool )
{
    QByteArray result;
    if (!db.isOpen()) db.open();
    QSqlQuery myQuery(db);
    myQuery.prepare("SELECT cbb FROM folios_pool WHERE num_aprobacion=:poolId;");
    myQuery.bindValue("poolId", pool);
    if (myQuery.exec() ) {
        while (myQuery.next()) {
            int cbbId      = myQuery.record().indexOf("cbb");
            result = myQuery.value(cbbId).toByteArray();
        }
    }
    else {
        setError(myQuery.lastError().text());
    }
    return result;
}

FolioInfo Azahar::getSiguienteFolio()
{
    /**
     * Aqui hay un posible problema (race conditions):
     * Si dos terminales piden "al mismo tiempo" un folio libre para usarse, estarian compitiendo por el siguiente que esta libre.
     * Entonces, podrian obtener el mismo, o en el mejor de los casos obtener uno cada uno, sin embargo no utilizarlo y dejarlo libre segundos despues
     * con el problema de que el siguiente libre para otra terminal (o la misma) podria no ser consecutivo.
     *
     * Ejemplo:
     *
     * Caja1 y Caja2 piden un folio, Caja uno obtiene el 21, y caja dos obtiene el 22.
     * Caja1 cancela, y vuelve a poner en disponible el folio 21, caja dos usa el folio y esta NO disponible, asignado a una factura.
     * Luego CajaX pide el siguiente folio libre, y obtiene el folio 21 "un dia despues", y lo usa en una factura.
     *
     * El problema esta en que el folio 21 tiene una fecha posterior a la del folio 22, cosa que no deberia de ser. Esto podria generar problemas
     * ante el SAT.
     *
     * La opcion, seria cancelar la factura, esto implica generar la factura y cancelarla.
     *
     * NOTE: No tengo una base para decir que sea un problema ante el SAT (documentacion que asi lo marque).
     * NOTE: Se asume que al llamar este metodo, el folio sera usado en una factura. No se permite cancelar el proceso, solo se puede cancelando la factura.
     *
     **/
    
    FolioInfo result;
    result.numero = "INVALIDO";
    result.valido = false;
    result.usado  = false;
    if (!db.isOpen()) db.open();
    QSqlQuery myQuery(db);
    QString qry("SELECT * FROM folios_cbb WHERE valido=true and usado=false ORDER BY id,numero ASC LIMIT 1;");
    if (myQuery.exec(qry) ) {
        while (myQuery.next()) {
            int numId      = myQuery.record().indexOf("numero");
            int usadoId    = myQuery.record().indexOf("usado");
            int validoId   = myQuery.record().indexOf("valido");
            int poolId     = myQuery.record().indexOf("pool_id");
            result.numero = myQuery.value(numId).toString();
            result.valido = myQuery.value(validoId).toBool();
            result.usado  = myQuery.value(usadoId).toBool();
            result.poolId = myQuery.value(poolId).toString();
        }
    }
    //TODO: Obtener el CBB del pool.
    else {
        setError(myQuery.lastError().text());
    }

    if (result.valido) {
        ///TODO: Hay que marcar el folio como usado. Para que otra terminal no lo tome mientras se esta procesando la factura.
        //       Podria tambien ponerse en lock la tabla para que no se modifique mientras tanto. Los demas queries deberian esperar su turno.
        //       tendra que ser un lock para read and write, no solo para write. Y solamente a esta tabla.
        if (markUsedFolio( result.numero )) {
            //suficientemente rapido para que otro no lo obtenga antes?
            result.usado = true;
            result.cbb = getCbbForSerie( result.poolId ); //the cbb bytearray.
            return result;
        }
        else {
            /// Si no se marco como usado en el metodo markUsedFolio() ?? Hubo un error en el proceso.
            qDebug()<<"El folio no pudo ser usado!, obteniendo otro...";
            //pedir otro ?? llamandose este metodo se ciclaria en caso de no estar marcando como usado dicho folio.
            result = getSiguienteFolio();
        }
    }
    return result;
}

bool Azahar::updateCantidadSerieFolios( const QString &numAprobacion, const int &cant)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("UPDATE folios_pool SET cantidad=:cantidad WHERE num_aprobacion=:numaprob;");
    query.bindValue(":cantidad", cant);
    query.bindValue(":numaprob", numAprobacion);
    if (!query.exec()) {
        setError(query.lastError().text());
        qDebug()<< __FUNCTION__ << query.lastError().text();
        result = false;
    } else {
        result = true;
    }

    return result;
}

bool Azahar::markUsedFolio(const QString &folio)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("UPDATE folios_cbb SET usado=:usado WHERE numero=:folio;");
    query.bindValue(":folio", folio);
    query.bindValue(":usado", true);
    if (!query.exec()) {
        setError(query.lastError().text());
        qDebug()<< __FUNCTION__ << query.lastError().text();
        result = false;
    } else {
        result = true;
    }
    
    return result;
}

bool Azahar::cancelFolio(const QString &folio)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("UPDATE folios_cbb SET valido=:valido WHERE numero=:folio;");
    query.bindValue(":folio", folio);
    query.bindValue(":valido", false);
    if (!query.exec()) {
        setError(query.lastError().text());
        qDebug()<< __FUNCTION__ << query.lastError().text();
        result = false;
    } else {
        result = true;
    }
    
    return result;
}

bool Azahar::cancelFactura(const QString &folio)
{
    /**
     * Nota:
     *      Cuando una factura se cancela, la venta asociada a dicha factura, puede volver a facturarse, con un nuevo folio (y factura).
     *      La factura y el folio cancelado seran inutilizables de nuevo.
     */
    
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery query(db);
    query.prepare("UPDATE facturas_cbb SET valida=:valida WHERE folio=:folio;");
    query.bindValue(":folio", folio);
    query.bindValue(":valida", false);
    if (!query.exec()) {
        setError(query.lastError().text());
        qDebug()<< __FUNCTION__ << query.lastError().text();
        result = false;
    } else {
        qDebug()<<"Factura cancelada, invalidando folio "<<folio;
        result = cancelFolio(folio);
    }
    
    return result;
}

bool Azahar::insertSerieFolios(const FoliosPool &pool)
{
    bool result = false;
    QString poolId = ""; //Como id manejaremos el num_aprobacion.
    if (!db.isOpen()) db.open();
    //We need to insert the pool registry, and all the folios in the pool.
    ///NOTE: Duplicate entries are not allowed, the primary key is the num_aprobacion field.
    QSqlQuery query(db);
    query.prepare("INSERT INTO folios_pool (fecha_aprobacion, num_aprobacion, folio_inicial, folio_final, cbb, cantidad) VALUES (:fecha, :numaprob, :inicial, :final, :cbb, :cantidad);");
    query.bindValue(":fecha", pool.fechaAprobacion);
    query.bindValue(":numaprob", pool.numAprobacion);
    query.bindValue(":inicial", pool.folioInicial);
    query.bindValue(":final", pool.folioFinal);
    query.bindValue(":cantidad", pool.cantidadFolios);
    query.bindValue(":cbb", pool.cbb);
    
    if (!query.exec()) {
        //TODO: How to know if the error is due to a duplicate key?
        setError(i18n("Could not add the serie. Process Aborted!.\n%1",query.lastError().text()));
        qDebug()<< __FUNCTION__ << query.lastError().text();
        return false; //return here, we could not insert the pool, we are not going to continue...
    }
    else {
        poolId = pool.numAprobacion;
        result = true;
        qDebug()<<"poolID="<<poolId;
    }

    //Obtener el numero de folio inicial, sin letras. Ej. A101 -> 101.
    QString completo;
    QString serie;
    qulonglong folio = 0;
    //Aqui, asumimos que la serie se indica al inicio del folio (SERIE NUMERO) => A101
    ///  ^[A-Za-z]*\d+$            ((^[A-Za-z]*)(\d+)$)  -> captura 1: todo, 2: la serie, 3 el numero.
    QRegExp expr("((^[A-Za-z]*)(\\d+)$)", Qt::CaseInsensitive, QRegExp::RegExp);
    if (expr.indexIn(pool.folioInicial) != -1  ) {
        completo  = expr.cap(1);
        serie = expr.cap(2);
        folio = expr.cap(3).toULongLong();
        qDebug()<<"SERIE:"<<expr.cap(2)<<" FOLIO:"<<expr.cap(3);
        if (folio == 0)
            folio++; //no puede ser cero.
    }
    qDebug()<<"  Se extrajo la SERIE "<<serie<<" y FOLIO INICIAL"<<folio<<" Se procesan "<<pool.cantidadFolios<<" folios totales";
    //NOTE: El dialogo  dialogseriefolios valida la entrada de datos (incluyendo limites de folios inferior y superior.)
    //now insert each folio. Start always from 1, cannot be folio A000.
    QStringList errors;
    for(int i=0; i<pool.cantidadFolios; i++){
        QSqlQuery query2(db);
        qulonglong num = folio+i;
        //TODO: Llenar con ceros iniciales? Ej: en lugar de A1 ==> A00001
        QString elFolio = QString("%1%2").arg(serie).arg(num);
        query2.prepare("INSERT INTO folios_cbb (pool_id, numero, usado, valido ) VALUES (:poolId, :numero, :usado, :valido);");
        query2.bindValue(":poolId", poolId);
        query2.bindValue(":numero", elFolio);
        query2.bindValue(":usado", false);
        query2.bindValue(":valido", true);
        if ( !query2.exec() ) {
            ///TODO: Ver si el error es por duplicado del numero.
            qDebug()<< __FUNCTION__ << query2.lastError().text();
            result = (result && false);
            errors.append(query2.lastError().text());
        } else result = (result && true);
    }
    
    if (!errors.isEmpty()) {
        if (errors.count() == pool.cantidadFolios ) {
            //Hey, no se inserto ningun folio correctamente. Borrar la serie.
            qDebug()<<"No se inserto ningun folio debido a errores. La serie es invalida y sera borrada.";
            setError(i18n("No se inserto ningún folio debido a que estaban duplicados.\n %1", errors.join(",\n")) );
            deleteSerieFolios(pool.numAprobacion);
        } else {
            qDebug()<<"Algunos folios estaban duplicados!";
            //Necesitamos actualizar el num de folios insertados en el pool.
            updateCantidadSerieFolios(poolId, pool.cantidadFolios-errors.count());
            setError(i18n("Se insertan %1 folios. Algunos folios estaban duplicados y se ignoran:\n %2", pool.cantidadFolios-errors.count(), errors.join(",\n") ));
        }
    }
    return result;
}

bool Azahar::deleteSerieFolios(const QString &numAprobacion)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery myQuery(db);
    QString qry = QString("DELETE FROM folios_pool WHERE num_aprobacion='%1';").arg(numAprobacion);
    if (!myQuery.exec(qry) )
        setError(myQuery.lastError().text());
    else
        result = true;
    return result;
}


bool Azahar::insertFactura( const FacturaCBB &factura )
{
    bool result = false;
    QSqlQuery query2(db);
    
    query2.prepare("INSERT INTO facturas_cbb ( fecha, folio, folio_num_autorizacion, \
                                               folio_fecha_autorizacion, valida, \
                                               nombre_cliente, rfc_cliente, transaction_id,\
                                               subtotal, impuestos, impuestos_tasa, descuentos, total \
                                             ) VALUES \
                                             ( :fecha, :folio, :folioAut, :folio_fechaAut, \
                                               :valida, :cliente, :rfc, :ticket, :subtotal, \
                                               :impuestos, :impuestosTasa, :descuentos, :total \
                                             ); ");
    query2.bindValue(":fecha", factura.fecha);
    query2.bindValue(":folio", factura.folio);
    query2.bindValue(":folioAut", factura.authFolios);
    query2.bindValue(":folio_fechaAut", factura.fechaAutFolios);
    query2.bindValue(":valida", factura.valida);
    query2.bindValue(":cliente", factura.nombreCliente);
    query2.bindValue(":rfc", factura.RFCCliente);
    query2.bindValue(":ticket", factura.trId);
    query2.bindValue(":subtotal", factura.subTotal);
    query2.bindValue(":impuestos", factura.impuestos);
    query2.bindValue(":impuestosTasa", factura.impuestosTasa);
    query2.bindValue(":total", factura.total);
    query2.bindValue(":descuentos", factura.descuentos);
    
    if ( !query2.exec() ) {
        qDebug()<< __FUNCTION__ << query2.lastError().text();
        result = false;
        setError( query2.lastError().text() );
    } else result = true;
    
    return result;
}


FoliosPool Azahar::getFolioPool(const QString &pool)
{
    FoliosPool result;
    result.numAprobacion = "INVALIDO";result.cantidadFolios = 0;
    if (!db.isOpen()) db.open();
    QSqlQuery myQuery(db);
    myQuery.prepare("SELECT * FROM folios_pool WHERE num_aprobacion=:poolId;");
    myQuery.bindValue("poolId", pool);
    if (myQuery.exec() ) {
        while (myQuery.next()) {
            int cbbId      = myQuery.record().indexOf("cbb");
            int fechaAprobId      = myQuery.record().indexOf("fecha_aprobacion");
            int folioFinalId      = myQuery.record().indexOf("folio_final");
            int folioInicialId    = myQuery.record().indexOf("folio_inicial");
            int cantidadId        = myQuery.record().indexOf("cantidad");
            
            result.cbb             = myQuery.value(cbbId).toByteArray();
            result.numAprobacion   = pool;
            result.fechaAprobacion = myQuery.value(fechaAprobId).toDate();
            result.folioInicial    = myQuery.value(folioInicialId).toString();
            result.folioFinal      = myQuery.value(folioFinalId).toString();
            result.cantidadFolios  = myQuery.value(cantidadId).toInt();
        }
    }
    else {
        setError(myQuery.lastError().text());
    }
    return result;
}

QString Azahar::getFolioFactura(const qulonglong &trId)
{

    /**
     * Puede haber varios folios por VENTA. Alguno puede ser valido y otros cancelados.
     * Este metodo devuelve el ultimo folio.
     **/
    
    QString result = "";
    if (!db.isOpen()) db.open();
    QSqlQuery myQuery(db);
    myQuery.prepare("SELECT folio,transaction_id FROM facturas_cbb WHERE transaction_id=:trId;");
    myQuery.bindValue(":trId", trId);
    if (myQuery.exec()) {
        while (myQuery.next()) {
            int folioId = myQuery.record().indexOf("folio");
            result = myQuery.value(folioId).toString();
        }
    }
    else {
        setError(myQuery.lastError().text());
    }
    return result;
}

bool Azahar::ventaFacturada(const qulonglong &trId)
{
    /**
     * Puede haber 0,1 o mas facturas por ticket, cada una con un folio diferente.
     * 0 : no se ha facturado.
     * 1 : se facturo, es valida o invalida
     * 2 o mas :  Se facturo, puede haber facturas canceladas y una valida (o solo puras canceladas), mas solo puede haber UNA factura valida.
     * 
     */
    
    bool result = false;
    int  validas = 0;
    if (!db.isOpen()) db.open();
    QSqlQuery myQuery(db);
    myQuery.prepare("SELECT folio,transaction_id,valida FROM facturas_cbb WHERE transaction_id=:trId;");
    myQuery.bindValue(":trId", trId);
    if (myQuery.exec()) {
        while (myQuery.next()) {
            int folioId = myQuery.record().indexOf("valida");
            result = myQuery.value(folioId).toBool();
            if (result)
                validas++;
        }
    }
    else {
        setError(myQuery.lastError().text());
    }
    //how many valid/invalid?
    qDebug()<<"Hay "<<validas<<" facturas validas para el folio.";
    if (validas >= 1)
        return true; //solo una factura valida. mas de una valida, eso ESTA MAL. Pero devolvemos true, para indicar que no se debe facturar nuevamente.
    else 
        return false;
}


bool Azahar::facturaValida(const qulonglong &folio)
{
    bool result = false;
    if (!db.isOpen()) db.open();
    QSqlQuery myQuery(db);
    myQuery.prepare("SELECT folio,transaction_id,valida FROM facturas_cbb WHERE folio=:folio;");
    myQuery.bindValue(":folio", folio);
    if (myQuery.exec()) {
        while (myQuery.next()) {
            int folioId = myQuery.record().indexOf("valida");
            result = myQuery.value(folioId).toBool();
        }
    }
    else {
        setError(myQuery.lastError().text());
    }
    return result;
}


FacturaCBB Azahar::getFacturaInfo(const QString &folio)
{
    ///This method is not used yet, and not complete.
    
    FacturaCBB result;
    if (!db.isOpen()) db.open();
    QSqlQuery myQuery(db);
    myQuery.prepare("SELECT * FROM facturas_cbb WHERE folio=:folio;");
    myQuery.bindValue(":folio", folio);
    if (myQuery.exec()) {
        while (myQuery.next()) {
            int folioId = myQuery.record().indexOf("folio");
            int fechaId = myQuery.record().indexOf("fecha");
            int authFoliosId = myQuery.record().indexOf("folio_num_autorizacion");
            int fechaAuthId = myQuery.record().indexOf("folio_fecha_autorizacion");
            int validaId = myQuery.record().indexOf("valida");
            int clienteId = myQuery.record().indexOf("nombre_cliente");
            int rfcId = myQuery.record().indexOf("rfc_cliente");
            int addrId = myQuery.record().indexOf("direccion_cliente");
            int trId = myQuery.record().indexOf("transaction_id");
            int subtotalId = myQuery.record().indexOf("subtotal");
            int descuentosId = myQuery.record().indexOf("descuentos");
            int impuestosId = myQuery.record().indexOf("impuestos");
            int impuestosTasaId = myQuery.record().indexOf("impuestos_tasa");
            int totalId = myQuery.record().indexOf("total");

            result.folio = myQuery.value(folioId).toString();
            result.fecha = myQuery.value(fechaId).toDate();
            result.authFolios = myQuery.value(authFoliosId).toString();
            result.fechaAutFolios = myQuery.value(fechaAuthId).toDate();
            result.cbb =  getCbbForSerie( result.authFolios );
            result.valida = myQuery.value(validaId).toBool();
            result.nombreCliente = myQuery.value(clienteId).toString();
            result.RFCCliente = myQuery.value(rfcId).toString();
            result.direccionCliente = myQuery.value(addrId).toString();
            ///result.lineas = FIXME: The same as the lines on tickets.
            result.trId = myQuery.value(trId).toULongLong();
            result.subTotal = myQuery.value(subtotalId).toDouble();
            result.descuentos = myQuery.value(descuentosId).toDouble();
            result.impuestos = myQuery.value(impuestosId).toDouble();
            result.impuestosTasa = myQuery.value(impuestosTasaId).toDouble();
            result.total = myQuery.value(totalId).toDouble();
        }
    }
    else {
        setError(myQuery.lastError().text());
    }
    return result;
}


#include "azahar.moc"
