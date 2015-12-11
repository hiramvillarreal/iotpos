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
#include <KLocale>
#include <KMessageBox>
#include <KFileDialog>

#include <QByteArray>

#include "subcategoryeditor.h"
#include "../../dataAccess/azahar.h"

SubcategoryEditorUI::SubcategoryEditorUI( QWidget *parent )
: QFrame( parent )
{
    setupUi( this );
}

SubcategoryEditor::SubcategoryEditor( QWidget *parent )
: KDialog( parent )
{
    ui = new SubcategoryEditorUI( this );
    setMainWidget( ui );
    //setCaption( i18n("Subcategory Editor") );
    setButtons( KDialog::Ok|KDialog::Cancel );

    enableButtonOk(false);
    connect(ui->editName, SIGNAL(textEdited(const QString &)), SLOT(checkValid()) );
    connect(ui->btnAdd, SIGNAL(clicked()), SLOT(addNewChild()));

    QTimer::singleShot(1000, this, SLOT(checkValid()));
}

SubcategoryEditor::~SubcategoryEditor()
{
    delete ui;
}

void SubcategoryEditor::setDb(QSqlDatabase d)
{
    db = d;
    if (!db.isOpen()) {db.open();}
}

//this needs to be called after creating the dialog.
void SubcategoryEditor::populateList(QStringList list, QStringList checkedList)
{
  ui->listView->clear();
  ui->listView->addItems( list );

  for(int i=0;i<ui->listView->count();i++) {
    ui->listView->item(i)->setFlags(ui->listView->item(i)->flags() |Qt::ItemIsUserCheckable);

    if ( checkedList.contains(ui->listView->item(i)->text() ) )
        ui->listView->item(i)->setCheckState(Qt::Checked);
    else
        ui->listView->item(i)->setCheckState(Qt::Unchecked);
  }
}

QStringList SubcategoryEditor::getChildren() {
    //returns a list of checked children.
    QStringList result;

    for(int i=0;i<ui->listView->count();i++){
        if (ui->listView->item(i)->checkState())
            result.append( ui->listView->item(i)->text() );
    }

    return result;
}


void SubcategoryEditor::checkValid()
{
    bool validText = !ui->editName->text().isEmpty();
    enableButtonOk(validText);
}

void SubcategoryEditor::setDialogType(int t)
{
    //Types: 0:unset, 1:AddDepartment, 2:AddCategory, 3:AddSubcategory.
    dialogType = t;
    if (t == 1)
        setCaption( i18n("Department Editor") );
    else if (t == 2)
        setCaption( i18n("Category Editor") );
    else if (t == 3)
        setCaption( i18n("Subcategory Editor") );
    else
        setCaption( i18n("") );
}

void SubcategoryEditor::addNewChild()
{
    //launch dialog to ask for the new child. Using this same dialog.
    SubcategoryEditor *scEditor = new SubcategoryEditor(this);
    scEditor->setDb(db);
    Azahar *myDb = new Azahar;
    myDb->setDatabase(db);

    scEditor->setCatList( catList );
    scEditor->setScatList( scatList );
    scEditor->setDialogType(dialogType+1);//incrementing because this dialog is a child dialog (parentType+1)

    if (dialogType == 1) {
        //From "Add Department" dialog, creating a category.
        scEditor->setLabelForName(i18n("New category:"));
        scEditor->setLabelForList(i18n("Select the child subcategories for this category:"));
        scEditor->populateList( myDb->getSubCategoriesList() );
    } else if (dialogType == 2) {
        //From "Add Category" dialog, creating a subcategory. No child allowed.
        scEditor->setLabelForName(i18n("New subcategory:"));
        scEditor->setLabelForList(i18n(""));
        scEditor->hideListView(); //subcategories does not have children.
    }
        
    if ( scEditor->exec() ) {
        QString text = scEditor->getName();
        QStringList children = scEditor->getChildren();
        qDebug()<<text<<" CHILDREN:"<<children;

        if (dialogType == 1) { //The dialog is launched from the "Add Department" dialog. So we are going to create a category.
            //Create the category
            if (!myDb->insertCategory(text)) {
                qDebug()<<"Error:"<<myDb->lastError();
                delete myDb;
                return;
            }
            //insert new category to the box
            catList << text;
            ui->listView->addItem(text);
            //mark item as checkable
            ui->listView->item(ui->listView->count()-1)->setFlags(ui->listView->item(ui->listView->count()-1)->flags() |Qt::ItemIsUserCheckable);
            ui->listView->item(ui->listView->count()-1)->setCheckState(Qt::Checked); //mark as checked.
            qulonglong cId = myDb->getCategoryId(text);
            //create the m2m  relations for the new category->subcategory.
            foreach(QString cat, children) {
                //get subcategory id
                qulonglong scId = myDb->getSubCategoryId(cat);
                //create the link [category] --> [subcategory]
                myDb->insertM2MCategorySubcategory(cId, scId);
            }
        } else if (dialogType == 2) { //The dialog is launched from the "Add Category" dialog. So we are going to create a subcategory which does have a child.
            //Create the subcategory only... no m2m relation
            if (!myDb->insertSubCategory(text)) {
                qDebug()<<"Error:"<<myDb->lastError();
                delete myDb;
                return;
            }
            //insert new subcategory to the box
            scatList << text;
            ui->listView->addItem(text);
            //mark item as checkable
            ui->listView->item(ui->listView->count()-1)->setFlags(ui->listView->item(ui->listView->count()-1)->flags() |Qt::ItemIsUserCheckable);
            ui->listView->item(ui->listView->count()-1)->setCheckState(Qt::Checked); //mark as checked.
        }// dialogType == 2
    }
}

#include "subcategoryeditor.moc"
