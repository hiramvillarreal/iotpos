#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'refacturar.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFACTURAR_H
#define UI_REFACTURAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_refacturarDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblTitle;
    QTableView *tableWidget;

    void setupUi(QWidget *refacturarDialog)
    {
        if (refacturarDialog->objectName().isEmpty())
            refacturarDialog->setObjectName(QString::fromUtf8("refacturarDialog"));
        refacturarDialog->resize(600, 250);
        refacturarDialog->setMinimumSize(QSize(600, 250));
        verticalLayout = new QVBoxLayout(refacturarDialog);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblTitle = new QLabel(refacturarDialog);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        lblTitle->setWordWrap(true);

        verticalLayout->addWidget(lblTitle);

        tableWidget = new QTableView(refacturarDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(280, 0));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);
        tableWidget->setCornerButtonEnabled(false);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(refacturarDialog);

        QMetaObject::connectSlotsByName(refacturarDialog);
    } // setupUi

    void retranslateUi(QWidget *refacturarDialog)
    {
        refacturarDialog->setWindowTitle(tr2i18n("Reimprimir Factura", 0));
        lblTitle->setText(tr2i18n("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Lucida Grande'; font-size:8pt;\">Para reimprimir la factura </span><span style=\" font-family:'Lucida Grande'; font-size:8pt; font-weight:600;\">seleccione una factura de la lista</span><span style=\" font-family:'Lucida Grande'; font-size:8pt;\"> y presione </span><span style=\" font-family:'Lucida Grande'; font-size:8pt; font-weight:600; font-style:italic;\">Aceptar</span><span style=\" font-family:'Lucida Grande'; font-size:8pt;\"> .</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class refacturarDialog: public Ui_refacturarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // REFACTURAR_H

