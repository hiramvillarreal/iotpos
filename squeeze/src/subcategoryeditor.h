/***************************************************************************
 *   Copyright (C) 2012 by Miguel Chavez Gamboa                            *
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
#ifndef SUBCATEGORYEDITOR_H
#define SUBCATEGORYEDITOR_H

#include <KDialog>
#include <QDate>
#include <QtGui>
#include <QtSql>
#include "ui_subcategoryeditor.h"

class SubcategoryEditorUI : public QFrame, public Ui::subcategoryEditor
{
  Q_OBJECT
  public:
    SubcategoryEditorUI( QWidget *parent=0 );
};

class SubcategoryEditor : public KDialog
{
  Q_OBJECT
  public:
    SubcategoryEditor( QWidget *parent=0 );
    ~SubcategoryEditor();

    void    setLabelForName(QString text) { ui->lblName->setText(text); };
    void    setLabelForList(QString text) { ui->lblChildText->setText(text); };
    void    setName(QString n)            { ui->editName->setText(n); };
    void    disableAddButton(bool y)      { ui->btnAdd->setDisabled(y); };
    void    setDb(QSqlDatabase d);
    void    setDialogType(int t);
    void    setCatList(QStringList c)     { catList = c; };
    void    setScatList(QStringList s)    { scatList = s; };
    
    QStringList getChildren();
    QString getName()    { return ui->editName->text(); };
    
    void    populateList(QStringList list, QStringList checkedList=QStringList() );
    void    hideListView() { ui->listView->hide(); ui->lblChildText->hide(); ui->btnAdd->hide(); };

  private slots:
    void    checkValid();
    void    addNewChild(); //for adding a new category or subcategory, depending on the dialog use.

  private:
    SubcategoryEditorUI *ui;
    QSqlDatabase db;
    int dialogType;
    QStringList catList;
    QStringList scatList;
};

#endif
