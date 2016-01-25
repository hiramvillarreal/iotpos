/***************************************************************************
 *   Copyright (C) 2013-2015 by Hiram R. Villarreal                      *
 *   hiramvillarreal.ap@gmail.com                                          *
 *   Modified by Daniel A. Cervantes dcchivela@gmail.com                   *
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
#ifndef PRODUCTEDITOR_H
#define PRODUCTEDITOR_H

#include <KDialog>
#include <QDate>
#include <QtGui>
#include <QPixmap>
#include <QtSql>

#include "ui_producteditor.h"

class MibitFloatPanel;
class MibitTip;
#include "../../src/structs.h"

enum returnType {statusNormal=998, statusMod=999};

class ProductEditorUI : public QFrame, public Ui::productEditor
{
  Q_OBJECT
  public:
    ProductEditorUI( QWidget *parent=0);
};

class ProductEditor : public KDialog
{
  Q_OBJECT
  public:
    ProductEditor( QWidget *parent=0, bool newProduct = false  );
    ~ProductEditor();

    qulonglong getCode()     { return ui->editCode->text().toULongLong(); };
    QString getAlphacode()   { return ui->editAlphacode->text(); };
    QString getVendorcode()   { return ui->editVendorcode->text(); };
    QString getDescription() { return ui->editDesc->text(); };
    double  getStockQty()    { return ui->editStockQty->text().toDouble(); };
    int     getDepartmentId();
    int     getCategoryId();
    int     getSubCategoryId();
    int     getSubCategoryParent();
    int     getMeasureId();
    QString getDepartmentStr(int c);
    QString getCategoryStr(int c);
    QString getSubCategoryStr(int c);
    QString getMeasureStr(int c);
    double  getCost()        { return ui->editCost->text().toDouble(); };
    double  getTax1()        { return ui->editTax->text().toDouble(); };
    double  getTax2()        { return ui->editExtraTaxes->text().toDouble(); };
    double  getPrice()       { return ui->editFinalPrice->text().toDouble(); };
    qulonglong getPoints()   { return ui->editPoints->text().toULongLong(); };
    QPixmap getPhoto()       { qDebug()<<"pixmap Size:"<<pix.size(); return pix; };
    QString getReason()      { return reason; };
    bool    isCorrectingStock() {return correctingStockOk;};
    double  getOldStock()    { return oldStockQty; };
    double  getGRoupStockMax();
    double  getGroupPriceDrop() { return groupInfo.priceDrop; };
    void    setStockQtyReadOnly(bool enabled) { ui->editStockQty->setReadOnly(enabled); };
    void    setAutoCode(bool yes) { autoCode = yes;};

    

    void    populateDepartmentsCombo();
    void    populateCategoriesCombo();
    void    populateSubCategoriesCombo();
    void    populateMeasuresCombo();
    void    calculateGroupValues();

    void    setDb(QSqlDatabase database);
    void    setCode(qulonglong c)      {ui->editCode->setText(QString::number(c)); };
    void    setAlphacode(QString c)    { ui->editAlphacode->setText(c); };
    void    setVendorcode(QString c)    { ui->editVendorcode->setText(c); };
    void    setDescription(QString d)  {ui->editDesc->setText(d); };
    void    setStockQty(double q)      {ui->editStockQty->setText(QString::number(q)); };
    

    void    setDepartment(QString str);
    void    setDepartment(int i);
    void    setCategory(QString str);
    void    setCategory(int i);
    void    setSubCategory(int i);
    void    setSubCategory(QString str);
    void    setSubCategoryParent(int parentId);
    void    setMeasure(QString str);
    void    setMeasure(int i);
    void    setCost(double c)          {ui->editCost->setText(QString::number(c)); };
    void    setTax1(double t)          {ui->editTax->setText(QString::number(t)); };
    void    setTax2(double t)          {ui->editExtraTaxes->setText(QString::number(t)); };
    void    setPrice(double p)         {ui->editFinalPrice->setText(QString::number(p)); };
    void    setPoints(qulonglong p)    {ui->editPoints->setText(QString::number(p)); };
    void    setPhoto(QPixmap p);
    void    setIsAGroup(bool value);
    void    setIsARaw(bool value);
    void    setGroupElements(ProductInfo pi);
    
    void    disableCode()              { ui->editCode->setReadOnly(true); modifyCode=false; };
    void    enableCode()               { ui->editCode->setReadOnly(false); modifyCode=true;};
    void    disableStockCorrection()   { ui->btnStockCorrect->hide(); }

    void    setModel(QSqlRelationalTableModel *model);
    GroupInfo getGroupHash();
    QString getGroupElementsStr();
    bool    isGroup();
    bool    isRaw();
    bool    isNotDiscountable();
    bool    hasUnlimitedStock();
    
private slots:
    void    changePhoto();
    void    changeCode();
    void    modifyStock();
    void    calculatePrice();
    void    calculateProfit(QString amountStr);
    void    checkIfCodeExists();
    void    checkFieldsState();
    void    toggleGroup(bool checked);
    void    toggleRaw(bool checked);
    void    applyFilter(const QString &text);
    void    applyFilter();
    void    addItem();
    void    removeItem();
    void    itemDoubleClicked(QTableWidgetItem* item);
    void    updatePriceDrop(double value);
    void    setNotDiscountable(bool value);
    void    setUnlimitedStock(bool value);
    qulonglong getNextCode();
    void    verifyVendorcodeDuplicates();
    void    verifyAlphacodeDuplicates();
    void    modifyDepartment();
    void    modifyCategory();
    void    createNewSubcategory();
    void    createNewCategory();
    void    createNewDepartment();
    void    createNewMeasure();
    void    printBarcode();
    
protected slots:
    virtual void slotButtonClicked(int button);
  private:
    ProductEditorUI *ui;
    QSqlDatabase db;
    QPixmap pix;
    returnType status;
    bool modifyCode;
    bool autoCode;
    double oldStockQty;
    QString reason;
    bool correctingStockOk;
    GroupInfo groupInfo;
    bool m_modelAssigned;
    QSqlRelationalTableModel *m_model;

    MibitFloatPanel *groupPanel;
    MibitTip        *errorPanel;
    MibitTip        *errorAlphacode;
    MibitTip        *errorVendorcode;
};

#endif
