#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'prefs_base.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
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
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "kcolorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_prefs_base
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *hboxLayout;
    QLabel *label_3;
    QLineEdit *kcfg_editTerminalNumber;
    QGroupBox *kcfg_groupUserIdAsCode;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *kcfg_rb6Digits;
    QRadioButton *kcfg_rb12DigitsCustom;
    QGroupBox *groupBoxOb;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *kcfg_showDialogOnPrinting;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QSpinBox *kcfg_ticketTime;
    QCheckBox *kcfg_requiereDelAuth;
    QGroupBox *groupMatrix;
    QVBoxLayout *vboxLayout;
    QCheckBox *kcfg_showGrid;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QSpinBox *kcfg_stockAlertValue;
    QCheckBox *kcfg_allowNegativeStock;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *kcfg_displayWarningOnLowCash;
    QDoubleSpinBox *kcfg_cashMinLevel;
    QCheckBox *kcfg_firstDiscountOnly;
    QCheckBox *kcfg_addTax;
    QCheckBox *kcfg_roundToUSStandard;

    void setupUi(QWidget *prefs_base)
    {
        if (prefs_base->objectName().isEmpty())
            prefs_base->setObjectName(QString::fromUtf8("prefs_base"));
        prefs_base->resize(535, 679);
        prefs_base->setMinimumSize(QSize(0, 525));
        verticalLayout_2 = new QVBoxLayout(prefs_base);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        label_3 = new QLabel(prefs_base);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        hboxLayout->addWidget(label_3);

        kcfg_editTerminalNumber = new QLineEdit(prefs_base);
        kcfg_editTerminalNumber->setObjectName(QString::fromUtf8("kcfg_editTerminalNumber"));

        hboxLayout->addWidget(kcfg_editTerminalNumber);


        verticalLayout_2->addLayout(hboxLayout);

        kcfg_groupUserIdAsCode = new QGroupBox(prefs_base);
        kcfg_groupUserIdAsCode->setObjectName(QString::fromUtf8("kcfg_groupUserIdAsCode"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(kcfg_groupUserIdAsCode->sizePolicy().hasHeightForWidth());
        kcfg_groupUserIdAsCode->setSizePolicy(sizePolicy);
        kcfg_groupUserIdAsCode->setCheckable(true);
        kcfg_groupUserIdAsCode->setChecked(false);
        verticalLayout_5 = new QVBoxLayout(kcfg_groupUserIdAsCode);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        kcfg_rb6Digits = new QRadioButton(kcfg_groupUserIdAsCode);
        kcfg_rb6Digits->setObjectName(QString::fromUtf8("kcfg_rb6Digits"));

        verticalLayout_5->addWidget(kcfg_rb6Digits);

        kcfg_rb12DigitsCustom = new QRadioButton(kcfg_groupUserIdAsCode);
        kcfg_rb12DigitsCustom->setObjectName(QString::fromUtf8("kcfg_rb12DigitsCustom"));

        verticalLayout_5->addWidget(kcfg_rb12DigitsCustom);


        verticalLayout_2->addWidget(kcfg_groupUserIdAsCode);

        groupBoxOb = new QGroupBox(prefs_base);
        groupBoxOb->setObjectName(QString::fromUtf8("groupBoxOb"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBoxOb->sizePolicy().hasHeightForWidth());
        groupBoxOb->setSizePolicy(sizePolicy1);
        groupBoxOb->setMinimumSize(QSize(0, 0));
        groupBoxOb->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        verticalLayout_3 = new QVBoxLayout(groupBoxOb);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        kcfg_showDialogOnPrinting = new QCheckBox(groupBoxOb);
        kcfg_showDialogOnPrinting->setObjectName(QString::fromUtf8("kcfg_showDialogOnPrinting"));

        verticalLayout_3->addWidget(kcfg_showDialogOnPrinting);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_2->setContentsMargins(1, 1, 1, 1);
        label_5 = new QLabel(groupBoxOb);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setIndent(30);

        horizontalLayout_2->addWidget(label_5);

        kcfg_ticketTime = new QSpinBox(groupBoxOb);
        kcfg_ticketTime->setObjectName(QString::fromUtf8("kcfg_ticketTime"));
        kcfg_ticketTime->setMinimumSize(QSize(0, 22));

        horizontalLayout_2->addWidget(kcfg_ticketTime);


        verticalLayout_3->addLayout(horizontalLayout_2);

        kcfg_requiereDelAuth = new QCheckBox(groupBoxOb);
        kcfg_requiereDelAuth->setObjectName(QString::fromUtf8("kcfg_requiereDelAuth"));

        verticalLayout_3->addWidget(kcfg_requiereDelAuth);


        verticalLayout_2->addWidget(groupBoxOb);

        groupMatrix = new QGroupBox(prefs_base);
        groupMatrix->setObjectName(QString::fromUtf8("groupMatrix"));
        groupMatrix->setEnabled(true);
        sizePolicy.setHeightForWidth(groupMatrix->sizePolicy().hasHeightForWidth());
        groupMatrix->setSizePolicy(sizePolicy);
        groupMatrix->setAutoFillBackground(false);
        groupMatrix->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        vboxLayout = new QVBoxLayout(groupMatrix);
        vboxLayout->setSpacing(2);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(2, 2, 2, 2);
        kcfg_showGrid = new QCheckBox(groupMatrix);
        kcfg_showGrid->setObjectName(QString::fromUtf8("kcfg_showGrid"));

        vboxLayout->addWidget(kcfg_showGrid);


        verticalLayout_2->addWidget(groupMatrix);

        groupBox_2 = new QGroupBox(prefs_base);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        kcfg_stockAlertValue = new QSpinBox(groupBox_2);
        kcfg_stockAlertValue->setObjectName(QString::fromUtf8("kcfg_stockAlertValue"));
        kcfg_stockAlertValue->setMinimum(1);
        kcfg_stockAlertValue->setMaximum(9999);
        kcfg_stockAlertValue->setValue(10);

        horizontalLayout->addWidget(kcfg_stockAlertValue);


        verticalLayout->addLayout(horizontalLayout);

        kcfg_allowNegativeStock = new QCheckBox(groupBox_2);
        kcfg_allowNegativeStock->setObjectName(QString::fromUtf8("kcfg_allowNegativeStock"));
        kcfg_allowNegativeStock->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(kcfg_allowNegativeStock);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(prefs_base);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMinimumSize(QSize(0, 80));
        groupBox_3->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        kcfg_displayWarningOnLowCash = new QCheckBox(groupBox_3);
        kcfg_displayWarningOnLowCash->setObjectName(QString::fromUtf8("kcfg_displayWarningOnLowCash"));
        kcfg_displayWarningOnLowCash->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_3->addWidget(kcfg_displayWarningOnLowCash);

        kcfg_cashMinLevel = new QDoubleSpinBox(groupBox_3);
        kcfg_cashMinLevel->setObjectName(QString::fromUtf8("kcfg_cashMinLevel"));
        kcfg_cashMinLevel->setMaximum(1e+06);

        horizontalLayout_3->addWidget(kcfg_cashMinLevel);


        verticalLayout_2->addWidget(groupBox_3);

        kcfg_firstDiscountOnly = new QCheckBox(prefs_base);
        kcfg_firstDiscountOnly->setObjectName(QString::fromUtf8("kcfg_firstDiscountOnly"));

        verticalLayout_2->addWidget(kcfg_firstDiscountOnly);

        kcfg_addTax = new QCheckBox(prefs_base);
        kcfg_addTax->setObjectName(QString::fromUtf8("kcfg_addTax"));

        verticalLayout_2->addWidget(kcfg_addTax);

        kcfg_roundToUSStandard = new QCheckBox(prefs_base);
        kcfg_roundToUSStandard->setObjectName(QString::fromUtf8("kcfg_roundToUSStandard"));

        verticalLayout_2->addWidget(kcfg_roundToUSStandard);

#ifndef UI_QT_NO_SHORTCUT
        label_3->setBuddy(kcfg_editTerminalNumber);
#endif // QT_NO_SHORTCUT

        retranslateUi(prefs_base);

        QMetaObject::connectSlotsByName(prefs_base);
    } // setupUi

    void retranslateUi(QWidget *prefs_base)
    {
        label_3->setText(tr2i18n("This is the &Terminal Number:", 0));
        kcfg_editTerminalNumber->setInputMask(tr2i18n("0000", 0));
#ifndef UI_QT_NO_TOOLTIP
        kcfg_groupUserIdAsCode->setToolTip(tr2i18n("Use this to enter Customer IDs at the product code input box. This can improve usability (speed up customer selection) in an environment with many customers.\n"
"\n"
"This would make some products (if any, depending on the mode selected) to be bypassed in favor of customer IDs.", 0));
#endif // QT_NO_TOOLTIP
        kcfg_groupUserIdAsCode->setTitle(tr2i18n("Use Product Code Input to Identify Customers", 0));
#ifndef UI_QT_NO_TOOLTIP
        kcfg_rb6Digits->setToolTip(tr2i18n("Use 6 digits to identify customers. Any product with 6 digits (UPC-E) will be discarded and only clients will be searched.", 0));
#endif // QT_NO_TOOLTIP
        kcfg_rb6Digits->setText(tr2i18n("As 6 digits code (exactly 6). Discard products with 6 digits code.", 0));
#ifndef UI_QT_NO_TOOLTIP
        kcfg_rb12DigitsCustom->setToolTip(tr2i18n("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Any barcode starting with &quot;4&quot; will be interpreted as a customer id and will not search for a product. For more information about this standard, see <a href=\"http://en.wikipedia.org/wiki/Universal_Product_Code#Prefixes\"><span style=\" text-decoration: underline; color:#0000ff;\">http://en.wikipedia.org/wiki/Universal_Product_Code#Prefixes</span></a></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        kcfg_rb12DigitsCustom->setText(tr2i18n("As 12/13 Digits Starting with digit \"4\". As described in UPC Standard.", 0));
        groupBoxOb->setTitle(tr2i18n("Dialogs and Authorizations", 0));
        kcfg_showDialogOnPrinting->setText(tr2i18n("Show a dialog when printing ticket", 0));
        label_5->setText(tr2i18n("Time showing the dialog:", 0));
        kcfg_ticketTime->setSuffix(tr2i18n(" seconds", 0));
        kcfg_requiereDelAuth->setText(tr2i18n("Requiere authorisation to delete items from shopping list", 0));
        groupMatrix->setTitle(tr2i18n("Products Grid", 0));
        kcfg_showGrid->setText(tr2i18n("Show products grid", 0));
        groupBox_2->setTitle(tr2i18n("Low Stock", 0));
        label_4->setText(tr2i18n("Minimum value for alert", 0));
        kcfg_allowNegativeStock->setText(tr2i18n("Allow negative stock, but alert the user.", 0));
        groupBox_3->setTitle(tr2i18n("Drawer Cash Level", 0));
        kcfg_displayWarningOnLowCash->setText(tr2i18n("Display warning message when level is lower than", 0));
        kcfg_cashMinLevel->setPrefix(tr2i18n("$", 0));
        kcfg_firstDiscountOnly->setText(tr2i18n("Apply only first discount", 0));
        kcfg_addTax->setText(tr2i18n("Add taxes to sale (not included in price)", 0));
#ifndef UI_QT_NO_TOOLTIP
        kcfg_roundToUSStandard->setToolTip(tr2i18n("0.001-0.004 round down to 0.00 and 0.005 - 0.009 round up to 0.01", 0));
#endif // QT_NO_TOOLTIP
        kcfg_roundToUSStandard->setText(tr2i18n("Round  using US Standard 5/4.", 0));
        Q_UNUSED(prefs_base);
    } // retranslateUi

};

namespace Ui {
    class prefs_base: public Ui_prefs_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PREFS_BASE_H

