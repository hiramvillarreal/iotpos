#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'sostatus.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOSTATUS_H
#define UI_SOSTATUS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "kdatewidget.h"

QT_BEGIN_NAMESPACE

class Ui_soStatus
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QRadioButton *rbAll;
    QRadioButton *rbSaleId;
    QLineEdit *editSaleId;
    QRadioButton *rbName;
    QLineEdit *editName;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbDate;
    KDateWidget *datePicker;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblNewStatus;
    QComboBox *statusCombo;

    void setupUi(QWidget *soStatus)
    {
        if (soStatus->objectName().isEmpty())
            soStatus->setObjectName(QString::fromUtf8("soStatus"));
        soStatus->resize(320, 350);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(soStatus->sizePolicy().hasHeightForWidth());
        soStatus->setSizePolicy(sizePolicy);
        soStatus->setMinimumSize(QSize(320, 350));
        soStatus->setMaximumSize(QSize(1700000, 1700000));
        verticalLayout = new QVBoxLayout(soStatus);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        rbAll = new QRadioButton(soStatus);
        rbAll->setObjectName(QString::fromUtf8("rbAll"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rbAll->sizePolicy().hasHeightForWidth());
        rbAll->setSizePolicy(sizePolicy1);
        rbAll->setChecked(false);

        gridLayout->addWidget(rbAll, 0, 0, 1, 1);

        rbSaleId = new QRadioButton(soStatus);
        rbSaleId->setObjectName(QString::fromUtf8("rbSaleId"));
        sizePolicy1.setHeightForWidth(rbSaleId->sizePolicy().hasHeightForWidth());
        rbSaleId->setSizePolicy(sizePolicy1);
        rbSaleId->setMinimumSize(QSize(110, 0));
        rbSaleId->setMaximumSize(QSize(200, 16777215));
        rbSaleId->setChecked(true);

        gridLayout->addWidget(rbSaleId, 1, 0, 1, 1);

        editSaleId = new QLineEdit(soStatus);
        editSaleId->setObjectName(QString::fromUtf8("editSaleId"));
        sizePolicy1.setHeightForWidth(editSaleId->sizePolicy().hasHeightForWidth());
        editSaleId->setSizePolicy(sizePolicy1);
        editSaleId->setMinimumSize(QSize(150, 0));
        editSaleId->setMaximumSize(QSize(175, 16777215));

        gridLayout->addWidget(editSaleId, 1, 1, 1, 1);

        rbName = new QRadioButton(soStatus);
        rbName->setObjectName(QString::fromUtf8("rbName"));
        sizePolicy1.setHeightForWidth(rbName->sizePolicy().hasHeightForWidth());
        rbName->setSizePolicy(sizePolicy1);
        rbName->setMinimumSize(QSize(110, 0));
        rbName->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(rbName, 2, 0, 1, 1);

        editName = new QLineEdit(soStatus);
        editName->setObjectName(QString::fromUtf8("editName"));
        sizePolicy1.setHeightForWidth(editName->sizePolicy().hasHeightForWidth());
        editName->setSizePolicy(sizePolicy1);
        editName->setMinimumSize(QSize(150, 0));
        editName->setMaximumSize(QSize(175, 16777215));

        gridLayout->addWidget(editName, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rbDate = new QRadioButton(soStatus);
        rbDate->setObjectName(QString::fromUtf8("rbDate"));
        rbDate->setMaximumSize(QSize(25, 16777215));

        horizontalLayout->addWidget(rbDate);

        datePicker = new KDateWidget(soStatus);
        datePicker->setObjectName(QString::fromUtf8("datePicker"));

        horizontalLayout->addWidget(datePicker);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);

        tabWidget = new QTabWidget(soStatus);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget = new QTableView(tab);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(280, 0));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);
        tableWidget->setCornerButtonEnabled(false);

        verticalLayout_2->addWidget(tableWidget);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lblNewStatus = new QLabel(soStatus);
        lblNewStatus->setObjectName(QString::fromUtf8("lblNewStatus"));

        horizontalLayout_2->addWidget(lblNewStatus);

        statusCombo = new QComboBox(soStatus);
        statusCombo->setObjectName(QString::fromUtf8("statusCombo"));
        statusCombo->setMinimumSize(QSize(160, 0));

        horizontalLayout_2->addWidget(statusCombo);


        verticalLayout->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(editSaleId, rbAll);
        QWidget::setTabOrder(rbAll, rbSaleId);
        QWidget::setTabOrder(rbSaleId, rbName);
        QWidget::setTabOrder(rbName, editName);
        QWidget::setTabOrder(editName, rbDate);
        QWidget::setTabOrder(rbDate, tabWidget);
        QWidget::setTabOrder(tabWidget, tableWidget);

        retranslateUi(soStatus);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(soStatus);
    } // setupUi

    void retranslateUi(QWidget *soStatus)
    {
        soStatus->setWindowTitle(tr2i18n("Special Order", 0));
        rbAll->setText(tr2i18n("Show All", 0));
        rbSaleId->setText(tr2i18n("filter by ticket #:", 0));
        rbName->setText(tr2i18n("filter by name:", 0));
        rbDate->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), tr2i18n("Special Orders", 0));
        lblNewStatus->setText(tr2i18n("New Status:", 0));
    } // retranslateUi

};

namespace Ui {
    class soStatus: public Ui_soStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SOSTATUS_H

