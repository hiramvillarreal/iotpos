#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'facturas_data.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACTURAS_DATA_H
#define UI_FACTURAS_DATA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_facturas_data
{
public:
    QGridLayout *gridLayout;
    QLabel *lbl_storeCity;
    QLineEdit *kcfg_storeRFC;
    QLineEdit *kcfg_storeCity;
    QLabel *label_6;
    QSpacerItem *verticalSpacer;
    QLineEdit *kcfg_storeRegimen;
    QLabel *label;

    void setupUi(QWidget *facturas_data)
    {
        if (facturas_data->objectName().isEmpty())
            facturas_data->setObjectName(QString::fromUtf8("facturas_data"));
        facturas_data->resize(456, 300);
        gridLayout = new QGridLayout(facturas_data);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lbl_storeCity = new QLabel(facturas_data);
        lbl_storeCity->setObjectName(QString::fromUtf8("lbl_storeCity"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbl_storeCity->sizePolicy().hasHeightForWidth());
        lbl_storeCity->setSizePolicy(sizePolicy);
        lbl_storeCity->setMinimumSize(QSize(0, 0));
        lbl_storeCity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lbl_storeCity, 0, 0, 1, 1);

        kcfg_storeRFC = new QLineEdit(facturas_data);
        kcfg_storeRFC->setObjectName(QString::fromUtf8("kcfg_storeRFC"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(kcfg_storeRFC->sizePolicy().hasHeightForWidth());
        kcfg_storeRFC->setSizePolicy(sizePolicy1);
        kcfg_storeRFC->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(kcfg_storeRFC, 1, 1, 1, 1);

        kcfg_storeCity = new QLineEdit(facturas_data);
        kcfg_storeCity->setObjectName(QString::fromUtf8("kcfg_storeCity"));
        sizePolicy1.setHeightForWidth(kcfg_storeCity->sizePolicy().hasHeightForWidth());
        kcfg_storeCity->setSizePolicy(sizePolicy1);
        kcfg_storeCity->setMinimumSize(QSize(300, 0));
        kcfg_storeCity->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(kcfg_storeCity, 0, 1, 1, 1);

        label_6 = new QLabel(facturas_data);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        kcfg_storeRegimen = new QLineEdit(facturas_data);
        kcfg_storeRegimen->setObjectName(QString::fromUtf8("kcfg_storeRegimen"));
        sizePolicy1.setHeightForWidth(kcfg_storeRegimen->sizePolicy().hasHeightForWidth());
        kcfg_storeRegimen->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(kcfg_storeRegimen, 2, 1, 1, 1);

        label = new QLabel(facturas_data);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 2, 0, 1, 1);

#ifndef UI_QT_NO_SHORTCUT
        lbl_storeCity->setBuddy(kcfg_storeCity);
        label_6->setBuddy(kcfg_storeRFC);
        label->setBuddy(kcfg_storeRegimen);
#endif // QT_NO_SHORTCUT

        retranslateUi(facturas_data);

        QMetaObject::connectSlotsByName(facturas_data);
    } // setupUi

    void retranslateUi(QWidget *facturas_data)
    {
        facturas_data->setWindowTitle(QString());
        lbl_storeCity->setText(tr2i18n("&Lugar de emisi\303\263n:", 0));
        label_6->setText(tr2i18n("RFC:", 0));
        label->setText(tr2i18n("R\303\251gimen Tributario:", 0));
    } // retranslateUi

};

namespace Ui {
    class facturas_data: public Ui_facturas_data {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FACTURAS_DATA_H

