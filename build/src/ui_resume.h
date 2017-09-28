#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'resume.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESUME_H
#define UI_RESUME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_resumeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblTitle;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *editSearch;
    QTableView *tableWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *contentTable;

    void setupUi(QWidget *resumeDialog)
    {
        if (resumeDialog->objectName().isEmpty())
            resumeDialog->setObjectName(QString::fromUtf8("resumeDialog"));
        resumeDialog->resize(440, 280);
        resumeDialog->setMinimumSize(QSize(440, 280));
        verticalLayout = new QVBoxLayout(resumeDialog);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        lblTitle = new QLabel(resumeDialog);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        lblTitle->setWordWrap(true);

        verticalLayout->addWidget(lblTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(resumeDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        editSearch = new QLineEdit(resumeDialog);
        editSearch->setObjectName(QString::fromUtf8("editSearch"));

        horizontalLayout->addWidget(editSearch);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableView(resumeDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(280, 0));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);
        tableWidget->setCornerButtonEnabled(false);

        verticalLayout->addWidget(tableWidget);

        groupBox = new QGroupBox(resumeDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 100));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        contentTable = new QTableWidget(groupBox);
        if (contentTable->columnCount() < 2)
            contentTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        contentTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        contentTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        contentTable->setObjectName(QString::fromUtf8("contentTable"));

        verticalLayout_2->addWidget(contentTable);


        verticalLayout->addWidget(groupBox);

        QWidget::setTabOrder(editSearch, tableWidget);
        QWidget::setTabOrder(tableWidget, contentTable);

        retranslateUi(resumeDialog);

        QMetaObject::connectSlotsByName(resumeDialog);
    } // setupUi

    void retranslateUi(QWidget *resumeDialog)
    {
        resumeDialog->setWindowTitle(tr2i18n("Resume Sale", 0));
        lblTitle->setText(tr2i18n("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The next sales are suspended. Please <span style=\" font-weight:600;\">select one to resume</span> and press the <span style=\" font-weight:600; font-style:italic;\">Ok</span> button; or press the <span style=\" font-weight:600; font-style:italic;\">cancel</span>  button to <span style=\" font-weight:600;\">start a new one</span>.</p></body></html>", 0));
        label->setText(tr2i18n("Search by Client:", 0));
        groupBox->setTitle(tr2i18n("Items", 0));
        QTableWidgetItem *___qtablewidgetitem = contentTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(tr2i18n("Qty", 0));
        QTableWidgetItem *___qtablewidgetitem1 = contentTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(tr2i18n("Description", 0));
    } // retranslateUi

};

namespace Ui {
    class resumeDialog: public Ui_resumeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // RESUME_H

