#ifndef SALEQTYDELEGATE_H
#define SALEQTYDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QSize>
#include <QSpinBox>
#include <QSqlDatabase>

class SaleQtyDelegate : public QItemDelegate
{
    Q_OBJECT
    
public:
    SaleQtyDelegate(QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setDb(QSqlDatabase database);

private:
    QSqlDatabase db;
};

#endif