#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'prefs_base.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFS_BASE_H
#define UI_PREFS_BASE_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "kcolorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_prefs_base
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *kcfg_styleName;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *kcfg_mostSoldMinValue;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *kcfg_mostSoldMaxValue;
    QCheckBox *kcfg_lowSecurityMode;
    QCheckBox *kcfg_isProductsGridDefault;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *prefs_base)
    {
        if (prefs_base->objectName().isEmpty())
            prefs_base->setObjectName(QString::fromUtf8("prefs_base"));
        prefs_base->resize(364, 305);
        verticalLayout_3 = new QVBoxLayout(prefs_base);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(prefs_base);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        kcfg_styleName = new QLineEdit(prefs_base);
        kcfg_styleName->setObjectName(QString::fromUtf8("kcfg_styleName"));
        kcfg_styleName->setReadOnly(true);

        horizontalLayout->addWidget(kcfg_styleName);


        verticalLayout_3->addLayout(horizontalLayout);

        groupBox = new QGroupBox(prefs_base);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        kcfg_mostSoldMinValue = new QSpinBox(groupBox);
        kcfg_mostSoldMinValue->setObjectName(QString::fromUtf8("kcfg_mostSoldMinValue"));
        kcfg_mostSoldMinValue->setMinimum(0);
        kcfg_mostSoldMinValue->setMaximum(9999);
        kcfg_mostSoldMinValue->setSingleStep(1);
        kcfg_mostSoldMinValue->setValue(0);

        horizontalLayout_2->addWidget(kcfg_mostSoldMinValue);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        kcfg_mostSoldMaxValue = new QSpinBox(groupBox);
        kcfg_mostSoldMaxValue->setObjectName(QString::fromUtf8("kcfg_mostSoldMaxValue"));
        kcfg_mostSoldMaxValue->setMinimum(1);
        kcfg_mostSoldMaxValue->setMaximum(9999);
        kcfg_mostSoldMaxValue->setValue(10);

        horizontalLayout_3->addWidget(kcfg_mostSoldMaxValue);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(groupBox);

        kcfg_lowSecurityMode = new QCheckBox(prefs_base);
        kcfg_lowSecurityMode->setObjectName(QString::fromUtf8("kcfg_lowSecurityMode"));

        verticalLayout_3->addWidget(kcfg_lowSecurityMode);

        kcfg_isProductsGridDefault = new QCheckBox(prefs_base);
        kcfg_isProductsGridDefault->setObjectName(QString::fromUtf8("kcfg_isProductsGridDefault"));

        verticalLayout_3->addWidget(kcfg_isProductsGridDefault);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(prefs_base);

        QMetaObject::connectSlotsByName(prefs_base);
    } // setupUi

    void retranslateUi(QWidget *prefs_base)
    {
        label->setText(tr2i18n("Style:", 0));
        kcfg_styleName->setText(tr2i18n("simple", 0));
        groupBox->setTitle(tr2i18n("Most Sold Products, Alert Range", 0));
        label_3->setText(tr2i18n("Min Value:", 0));
        label_2->setText(tr2i18n("Max Value:", 0));
        kcfg_lowSecurityMode->setText(tr2i18n("Low security mode", 0));
        kcfg_isProductsGridDefault->setText(tr2i18n("Grid is the default view for products", 0));
        Q_UNUSED(prefs_base);
    } // retranslateUi

};

namespace Ui {
    class prefs_base: public Ui_prefs_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PREFS_BASE_H

