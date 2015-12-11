#include <QtGui>

#include "saleqtydelegate.h"
#include "structs.h"
#include "../../dataAccess/azahar.h"

SaleQtyDelegate::SaleQtyDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}

QWidget *SaleQtyDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex & index) const
{
    if (index.column() == 3) {
        QSpinBox *editor = new QSpinBox(parent);
        ///We need to get the maximum, with stock level. Take into account the unlimited stock products.
        //get item data from db.
        Azahar *myDb = new Azahar;
        myDb->setDatabase(db);
        QModelIndex sibling = index.sibling( index.row(), 0 ); // colCode=0
        qulonglong code = sibling.data(Qt::DisplayRole).toULongLong();
        int stock = myDb->getProductStockQty( code );
        //the  spinbox only support integers. We need a config option to turn ON/OFF this feature.
        editor->setMinimum(1);
        editor->setMaximum(stock); //as the editor contains the actual data/0, and will change, then we set max to stockqty.
        delete myDb;
        return editor;
    } else {
        //I dont want to create editors on other fields. What/How to do this? editor=null?
        QLineEdit *editor = new QLineEdit(parent);
        editor->setReadOnly(true);
        return editor;
    }
}

void SaleQtyDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const
{
    editor->setGeometry(option.rect);
}

void SaleQtyDelegate::setDb(QSqlDatabase database)
{
    db = database;
    if (!db.isOpen()) db.open();
}

