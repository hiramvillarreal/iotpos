#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'purchaseeditor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURCHASEEDITOR_H
#define UI_PURCHASEEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_purchaseEditor
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_5;
    QLineEdit *editCode;
    QWidget *widgetPurchase;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QLineEdit *editQty;
    QLabel *label_9;
    QLineEdit *editCost;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_10;
    QLineEdit *editTax;
    QLabel *label_14;
    QLineEdit *editExtraTaxes;
    QLabel *label_13;
    QLineEdit *editFinalPrice;
    QLabel *label_11;
    QLineEdit *editUtility;
    QToolButton *btnCalculatePrice;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *chIsAGroup;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label_8;
    QComboBox *categoriesCombo;
    QToolButton *btnCreateCategory;
    QLabel *label_17;
    QComboBox *measuresCombo;
    QToolButton *btnCreateMeasure;
    QLabel *label_15;
    QLineEdit *editPoints;
    QVBoxLayout *_7;
    QLabel *labelPhoto;
    QPushButton *btnPhoto;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_16;
    QLineEdit *editDesc;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_3;
    QComboBox *departmentsCombo;
    QHBoxLayout *horizontalLayout_10;
    QLabel *lblAlpha;
    QLineEdit *editAlphacode;
    QLabel *lblVendor;
    QLineEdit *editVendorcode;
    QToolButton *btnCreateDepartment;
    QWidget *page_3;
    QLabel *label;
    QWidget *page_2;
    QToolButton *btnCreateSubcategory;
    QComboBox *subcategoriesCombo;
    QLabel *label_2;
    QWidget *page_4;
    QGroupBox *groupBoxedItem;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QLineEdit *editPricePerBox;
    QLabel *label_4;
    QLineEdit *editItemsPerBox;
    QWidget *page_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnAddItem;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableView;
    QPushButton *btnRemoveItem;

    void setupUi(QWidget *purchaseEditor)
    {
        if (purchaseEditor->objectName().isEmpty())
            purchaseEditor->setObjectName(QString::fromUtf8("purchaseEditor"));
        purchaseEditor->resize(768, 350);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(purchaseEditor->sizePolicy().hasHeightForWidth());
        purchaseEditor->setSizePolicy(sizePolicy);
        purchaseEditor->setMinimumSize(QSize(768, 0));
        purchaseEditor->setMaximumSize(QSize(800, 16777215));
        purchaseEditor->setBaseSize(QSize(0, 0));
        gridLayout = new QGridLayout(purchaseEditor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_5 = new QLabel(purchaseEditor);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(60, 0));
        label_5->setMaximumSize(QSize(65, 16777215));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_5);

        editCode = new QLineEdit(purchaseEditor);
        editCode->setObjectName(QString::fromUtf8("editCode"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(editCode->sizePolicy().hasHeightForWidth());
        editCode->setSizePolicy(sizePolicy2);
        editCode->setMinimumSize(QSize(160, 0));
        editCode->setMaximumSize(QSize(160, 16777215));

        horizontalLayout_3->addWidget(editCode);

        widgetPurchase = new QWidget(purchaseEditor);
        widgetPurchase->setObjectName(QString::fromUtf8("widgetPurchase"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widgetPurchase->sizePolicy().hasHeightForWidth());
        widgetPurchase->setSizePolicy(sizePolicy3);
        widgetPurchase->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_9 = new QHBoxLayout(widgetPurchase);
        horizontalLayout_9->setSpacing(4);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(10, 1, 1, 1);
        label_12 = new QLabel(widgetPurchase);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_12);

        editQty = new QLineEdit(widgetPurchase);
        editQty->setObjectName(QString::fromUtf8("editQty"));
        sizePolicy2.setHeightForWidth(editQty->sizePolicy().hasHeightForWidth());
        editQty->setSizePolicy(sizePolicy2);
        editQty->setMinimumSize(QSize(80, 0));
        editQty->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_9->addWidget(editQty);

        label_9 = new QLabel(widgetPurchase);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(60, 0));
        label_9->setMaximumSize(QSize(95, 16777215));
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_9);

        editCost = new QLineEdit(widgetPurchase);
        editCost->setObjectName(QString::fromUtf8("editCost"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(editCost->sizePolicy().hasHeightForWidth());
        editCost->setSizePolicy(sizePolicy4);
        editCost->setMinimumSize(QSize(80, 0));
        editCost->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_9->addWidget(editCost);


        horizontalLayout_3->addWidget(widgetPurchase);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        label_10 = new QLabel(purchaseEditor);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMaximumSize(QSize(16777215, 16777215));
        label_10->setLayoutDirection(Qt::LeftToRight);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_10);

        editTax = new QLineEdit(purchaseEditor);
        editTax->setObjectName(QString::fromUtf8("editTax"));
        sizePolicy4.setHeightForWidth(editTax->sizePolicy().hasHeightForWidth());
        editTax->setSizePolicy(sizePolicy4);
        editTax->setMinimumSize(QSize(20, 0));
        editTax->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_5->addWidget(editTax);

        label_14 = new QLabel(purchaseEditor);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setMaximumSize(QSize(30, 16777215));
        label_14->setLayoutDirection(Qt::LeftToRight);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_14);

        editExtraTaxes = new QLineEdit(purchaseEditor);
        editExtraTaxes->setObjectName(QString::fromUtf8("editExtraTaxes"));
        sizePolicy4.setHeightForWidth(editExtraTaxes->sizePolicy().hasHeightForWidth());
        editExtraTaxes->setSizePolicy(sizePolicy4);
        editExtraTaxes->setMinimumSize(QSize(20, 0));
        editExtraTaxes->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_5->addWidget(editExtraTaxes);

        label_13 = new QLabel(purchaseEditor);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy5);
        label_13->setMaximumSize(QSize(16777215, 16777215));
        label_13->setLayoutDirection(Qt::LeftToRight);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_13);

        editFinalPrice = new QLineEdit(purchaseEditor);
        editFinalPrice->setObjectName(QString::fromUtf8("editFinalPrice"));
        sizePolicy4.setHeightForWidth(editFinalPrice->sizePolicy().hasHeightForWidth());
        editFinalPrice->setSizePolicy(sizePolicy4);
        editFinalPrice->setMinimumSize(QSize(40, 0));
        editFinalPrice->setMaximumSize(QSize(80, 16777215));
        editFinalPrice->setReadOnly(false);

        horizontalLayout_5->addWidget(editFinalPrice);

        label_11 = new QLabel(purchaseEditor);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMinimumSize(QSize(80, 0));
        label_11->setMaximumSize(QSize(95, 16777215));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_11);

        editUtility = new QLineEdit(purchaseEditor);
        editUtility->setObjectName(QString::fromUtf8("editUtility"));
        sizePolicy4.setHeightForWidth(editUtility->sizePolicy().hasHeightForWidth());
        editUtility->setSizePolicy(sizePolicy4);
        editUtility->setMinimumSize(QSize(40, 0));
        editUtility->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_5->addWidget(editUtility);

        btnCalculatePrice = new QToolButton(purchaseEditor);
        btnCalculatePrice->setObjectName(QString::fromUtf8("btnCalculatePrice"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 182, 93, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 240, 221, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 211, 157, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 91, 46, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 121, 62, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(255, 218, 174, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        btnCalculatePrice->setPalette(palette);

        horizontalLayout_5->addWidget(btnCalculatePrice);


        gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        chIsAGroup = new QCheckBox(purchaseEditor);
        chIsAGroup->setObjectName(QString::fromUtf8("chIsAGroup"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(chIsAGroup->sizePolicy().hasHeightForWidth());
        chIsAGroup->setSizePolicy(sizePolicy6);

        horizontalLayout_8->addWidget(chIsAGroup);


        gridLayout->addLayout(horizontalLayout_8, 4, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        label_8 = new QLabel(purchaseEditor);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(80, 0));
        label_8->setMaximumSize(QSize(95, 16777215));
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_8);

        categoriesCombo = new QComboBox(purchaseEditor);
        categoriesCombo->setObjectName(QString::fromUtf8("categoriesCombo"));
        QSizePolicy sizePolicy7(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(categoriesCombo->sizePolicy().hasHeightForWidth());
        categoriesCombo->setSizePolicy(sizePolicy7);

        horizontalLayout_6->addWidget(categoriesCombo);

        btnCreateCategory = new QToolButton(purchaseEditor);
        btnCreateCategory->setObjectName(QString::fromUtf8("btnCreateCategory"));

        horizontalLayout_6->addWidget(btnCreateCategory);

        label_17 = new QLabel(purchaseEditor);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);
        label_17->setMinimumSize(QSize(80, 0));
        label_17->setMaximumSize(QSize(95, 16777215));
        label_17->setLayoutDirection(Qt::LeftToRight);
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_17);

        measuresCombo = new QComboBox(purchaseEditor);
        measuresCombo->setObjectName(QString::fromUtf8("measuresCombo"));
        sizePolicy7.setHeightForWidth(measuresCombo->sizePolicy().hasHeightForWidth());
        measuresCombo->setSizePolicy(sizePolicy7);
        measuresCombo->setMinimumSize(QSize(60, 0));
        measuresCombo->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_6->addWidget(measuresCombo);

        btnCreateMeasure = new QToolButton(purchaseEditor);
        btnCreateMeasure->setObjectName(QString::fromUtf8("btnCreateMeasure"));

        horizontalLayout_6->addWidget(btnCreateMeasure);

        label_15 = new QLabel(purchaseEditor);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setLayoutDirection(Qt::LeftToRight);
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_15);

        editPoints = new QLineEdit(purchaseEditor);
        editPoints->setObjectName(QString::fromUtf8("editPoints"));
        sizePolicy7.setHeightForWidth(editPoints->sizePolicy().hasHeightForWidth());
        editPoints->setSizePolicy(sizePolicy7);
        editPoints->setMinimumSize(QSize(20, 0));
        editPoints->setMaximumSize(QSize(50, 16777215));
        editPoints->setReadOnly(false);

        horizontalLayout_6->addWidget(editPoints);


        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        _7 = new QVBoxLayout();
        _7->setSpacing(2);
        _7->setObjectName(QString::fromUtf8("_7"));
        labelPhoto = new QLabel(purchaseEditor);
        labelPhoto->setObjectName(QString::fromUtf8("labelPhoto"));
        sizePolicy6.setHeightForWidth(labelPhoto->sizePolicy().hasHeightForWidth());
        labelPhoto->setSizePolicy(sizePolicy6);
        labelPhoto->setMinimumSize(QSize(150, 150));
        labelPhoto->setMaximumSize(QSize(150, 150));
        labelPhoto->setFrameShape(QFrame::StyledPanel);
        labelPhoto->setFrameShadow(QFrame::Sunken);
        labelPhoto->setAlignment(Qt::AlignCenter);

        _7->addWidget(labelPhoto);

        btnPhoto = new QPushButton(purchaseEditor);
        btnPhoto->setObjectName(QString::fromUtf8("btnPhoto"));
        sizePolicy2.setHeightForWidth(btnPhoto->sizePolicy().hasHeightForWidth());
        btnPhoto->setSizePolicy(sizePolicy2);

        _7->addWidget(btnPhoto);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        _7->addItem(verticalSpacer);


        gridLayout->addLayout(_7, 0, 1, 8, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_16 = new QLabel(purchaseEditor);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);
        label_16->setMinimumSize(QSize(80, 0));
        label_16->setMaximumSize(QSize(95, 16777215));
        label_16->setLayoutDirection(Qt::LeftToRight);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_16);

        editDesc = new QLineEdit(purchaseEditor);
        editDesc->setObjectName(QString::fromUtf8("editDesc"));
        sizePolicy7.setHeightForWidth(editDesc->sizePolicy().hasHeightForWidth());
        editDesc->setSizePolicy(sizePolicy7);

        horizontalLayout_7->addWidget(editDesc);


        gridLayout->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        stackedWidget = new QStackedWidget(purchaseEditor);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMaximumSize(QSize(40, 40));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(-360, -10, 520, 31));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy8(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy8);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(label_3);

        departmentsCombo = new QComboBox(layoutWidget);
        departmentsCombo->setObjectName(QString::fromUtf8("departmentsCombo"));

        horizontalLayout_11->addWidget(departmentsCombo);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        lblAlpha = new QLabel(layoutWidget);
        lblAlpha->setObjectName(QString::fromUtf8("lblAlpha"));

        horizontalLayout_10->addWidget(lblAlpha);

        editAlphacode = new QLineEdit(layoutWidget);
        editAlphacode->setObjectName(QString::fromUtf8("editAlphacode"));

        horizontalLayout_10->addWidget(editAlphacode);

        lblVendor = new QLabel(layoutWidget);
        lblVendor->setObjectName(QString::fromUtf8("lblVendor"));

        horizontalLayout_10->addWidget(lblVendor);

        editVendorcode = new QLineEdit(layoutWidget);
        editVendorcode->setObjectName(QString::fromUtf8("editVendorcode"));

        horizontalLayout_10->addWidget(editVendorcode);


        horizontalLayout_11->addLayout(horizontalLayout_10);

        btnCreateDepartment = new QToolButton(layoutWidget);
        btnCreateDepartment->setObjectName(QString::fromUtf8("btnCreateDepartment"));

        horizontalLayout_11->addWidget(btnCreateDepartment);

        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label = new QLabel(page_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-330, 0, 672, 35));
        QSizePolicy sizePolicy9(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy9);
        label->setMinimumSize(QSize(0, 1));
        label->setMaximumSize(QSize(16777215, 35));
        label->setBaseSize(QSize(0, 0));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);
        label->setIndent(0);
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        btnCreateSubcategory = new QToolButton(page_2);
        btnCreateSubcategory->setObjectName(QString::fromUtf8("btnCreateSubcategory"));
        btnCreateSubcategory->setGeometry(QRect(120, 0, 21, 25));
        subcategoriesCombo = new QComboBox(page_2);
        subcategoriesCombo->setObjectName(QString::fromUtf8("subcategoriesCombo"));
        subcategoriesCombo->setGeometry(QRect(29, -1, 85, 27));
        sizePolicy2.setHeightForWidth(subcategoriesCombo->sizePolicy().hasHeightForWidth());
        subcategoriesCombo->setSizePolicy(sizePolicy2);
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-67, -4, 90, 33));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        groupBoxedItem = new QGroupBox(page_4);
        groupBoxedItem->setObjectName(QString::fromUtf8("groupBoxedItem"));
        groupBoxedItem->setGeometry(QRect(-30, 0, 140, 85));
        sizePolicy1.setHeightForWidth(groupBoxedItem->sizePolicy().hasHeightForWidth());
        groupBoxedItem->setSizePolicy(sizePolicy1);
        groupBoxedItem->setMinimumSize(QSize(130, 75));
        groupBoxedItem->setMaximumSize(QSize(140, 85));
        groupBoxedItem->setCheckable(true);
        groupBoxedItem->setChecked(false);
        gridLayout_2 = new QGridLayout(groupBoxedItem);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_7 = new QLabel(groupBoxedItem);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy5.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy5);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        editPricePerBox = new QLineEdit(groupBoxedItem);
        editPricePerBox->setObjectName(QString::fromUtf8("editPricePerBox"));
        sizePolicy2.setHeightForWidth(editPricePerBox->sizePolicy().hasHeightForWidth());
        editPricePerBox->setSizePolicy(sizePolicy2);
        editPricePerBox->setMinimumSize(QSize(50, 22));

        gridLayout_2->addWidget(editPricePerBox, 1, 1, 1, 1);

        label_4 = new QLabel(groupBoxedItem);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy5.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy5);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        editItemsPerBox = new QLineEdit(groupBoxedItem);
        editItemsPerBox->setObjectName(QString::fromUtf8("editItemsPerBox"));
        sizePolicy4.setHeightForWidth(editItemsPerBox->sizePolicy().hasHeightForWidth());
        editItemsPerBox->setSizePolicy(sizePolicy4);
        editItemsPerBox->setMinimumSize(QSize(50, 22));

        gridLayout_2->addWidget(editItemsPerBox, 0, 1, 1, 1);

        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        stackedWidget->addWidget(page_5);

        horizontalLayout->addWidget(stackedWidget);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btnAddItem = new QPushButton(purchaseEditor);
        btnAddItem->setObjectName(QString::fromUtf8("btnAddItem"));
        sizePolicy3.setHeightForWidth(btnAddItem->sizePolicy().hasHeightForWidth());
        btnAddItem->setSizePolicy(sizePolicy3);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush8(QColor(239, 220, 10, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush8);
        QBrush brush9(QColor(255, 244, 114, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush9);
        QBrush brush10(QColor(247, 232, 62, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        QBrush brush11(QColor(119, 110, 5, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush11);
        QBrush brush12(QColor(159, 147, 6, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush13(QColor(247, 237, 132, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        btnAddItem->setPalette(palette1);

        horizontalLayout->addWidget(btnAddItem);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 0, 1, 1);

        groupBox = new QGroupBox(purchaseEditor);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy10(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy10);
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 6, 0, 0);
        tableView = new QTableWidget(groupBox);
        if (tableView->columnCount() < 4)
            tableView->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableView->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableView->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableView->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableView->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        sizePolicy10.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy10);
        tableView->setMaximumSize(QSize(16777215, 16777215));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setCornerButtonEnabled(true);

        verticalLayout->addWidget(tableView);

        btnRemoveItem = new QPushButton(groupBox);
        btnRemoveItem->setObjectName(QString::fromUtf8("btnRemoveItem"));
        sizePolicy9.setHeightForWidth(btnRemoveItem->sizePolicy().hasHeightForWidth());
        btnRemoveItem->setSizePolicy(sizePolicy9);
        btnRemoveItem->setMinimumSize(QSize(169, 0));
        btnRemoveItem->setMaximumSize(QSize(190, 16777215));

        verticalLayout->addWidget(btnRemoveItem);


        gridLayout->addWidget(groupBox, 7, 0, 3, 2);

        groupBox->raise();
#ifndef UI_QT_NO_SHORTCUT
        label_5->setBuddy(editCode);
        label_12->setBuddy(editQty);
        label_9->setBuddy(editCost);
        label_10->setBuddy(editTax);
        label_14->setBuddy(editExtraTaxes);
        label_13->setBuddy(editFinalPrice);
        label_11->setBuddy(editUtility);
        label_8->setBuddy(categoriesCombo);
        label_17->setBuddy(measuresCombo);
        label_15->setBuddy(editPoints);
        label_16->setBuddy(editDesc);
        lblAlpha->setBuddy(editAlphacode);
        lblVendor->setBuddy(editVendorcode);
        label_2->setBuddy(subcategoriesCombo);
        label_7->setBuddy(editPricePerBox);
        label_4->setBuddy(editItemsPerBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(editQty, editAlphacode);
        QWidget::setTabOrder(editAlphacode, editVendorcode);
        QWidget::setTabOrder(editVendorcode, editDesc);
        QWidget::setTabOrder(editDesc, categoriesCombo);
        QWidget::setTabOrder(categoriesCombo, editTax);
        QWidget::setTabOrder(editTax, editExtraTaxes);
        QWidget::setTabOrder(editExtraTaxes, btnPhoto);
        QWidget::setTabOrder(btnPhoto, editItemsPerBox);
        QWidget::setTabOrder(editItemsPerBox, editPricePerBox);
        QWidget::setTabOrder(editPricePerBox, editCode);

        retranslateUi(purchaseEditor);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(purchaseEditor);
    } // setupUi

    void retranslateUi(QWidget *purchaseEditor)
    {
        purchaseEditor->setWindowTitle(tr2i18n("Purchase", 0));
        label_5->setText(tr2i18n("&Code:", 0));
        label_12->setText(tr2i18n("Pu&rchase Qty:", 0));
        label_9->setText(tr2i18n("C&ost:", 0));
        label_10->setText(tr2i18n("&Taxes 1).-", 0));
#ifndef UI_QT_NO_STATUSTIP
        editTax->setStatusTip(tr2i18n("This is the tax in percentage.", 0));
#endif // QT_NO_STATUSTIP
#ifndef UI_QT_NO_STATUSTIP
        label_14->setStatusTip(tr2i18n("Special Tax", 0));
#endif // QT_NO_STATUSTIP
        label_14->setText(tr2i18n("2).-", 0));
#ifndef UI_QT_NO_STATUSTIP
        editExtraTaxes->setStatusTip(tr2i18n("This is the extra tax in percentage.", 0));
#endif // QT_NO_STATUSTIP
        label_13->setText(tr2i18n("&Public price:", 0));
#ifndef UI_QT_NO_STATUSTIP
        editFinalPrice->setStatusTip(tr2i18n("Can be calculated with de + button", 0));
#endif // QT_NO_STATUSTIP
        editFinalPrice->setStyleSheet(tr2i18n("background: wheat;", 0));
        label_11->setText(tr2i18n("Pro&fit (%):", 0));
#ifndef UI_QT_NO_TOOLTIP
        editUtility->setToolTip(tr2i18n("For price auto-calculation only", 0));
#endif // QT_NO_TOOLTIP
#ifndef UI_QT_NO_TOOLTIP
        btnCalculatePrice->setToolTip(tr2i18n("Calculate price based on utility", 0));
#endif // QT_NO_TOOLTIP
#ifndef UI_QT_NO_STATUSTIP
        btnCalculatePrice->setStatusTip(tr2i18n("Calculate price automatically", 0));
#endif // QT_NO_STATUSTIP
        btnCalculatePrice->setText(tr2i18n("$", 0));
        chIsAGroup->setText(tr2i18n("Group. There will be added all its grouped products to the purchase.", 0));
        label_8->setText(tr2i18n("C&ategory:", 0));
#ifndef UI_QT_NO_TOOLTIP
        btnCreateCategory->setToolTip(tr2i18n("Create new category", 0));
#endif // QT_NO_TOOLTIP
        btnCreateCategory->setText(tr2i18n("+", 0));
        label_17->setText(tr2i18n("So&ld by:", 0));
#ifndef UI_QT_NO_TOOLTIP
        btnCreateMeasure->setToolTip(tr2i18n("Create New Measure", 0));
#endif // QT_NO_TOOLTIP
        btnCreateMeasure->setText(tr2i18n("+", 0));
        label_15->setText(tr2i18n("&Points:", 0));
        labelPhoto->setText(QString());
        btnPhoto->setText(tr2i18n("Change photo", 0));
        label_16->setText(tr2i18n("&Description:", 0));
        label_3->setText(tr2i18n("Department:", 0));
        lblAlpha->setText(tr2i18n("Alphacode:", 0));
        lblVendor->setText(tr2i18n("Vendor Code:", 0));
#ifndef UI_QT_NO_TOOLTIP
        btnCreateDepartment->setToolTip(tr2i18n("Create New Department", 0));
#endif // QT_NO_TOOLTIP
        btnCreateDepartment->setText(tr2i18n("+", 0));
        label->setText(tr2i18n("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Fill data for each product you purchased and click <span style=\" font-weight:600;\">add item</span> to continue with another product. Note that if a product exists on database, it will be updated. <span style=\" font-weight:600;\">When finish, click \"Ok\" button</span>.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0));
#ifndef UI_QT_NO_TOOLTIP
        btnCreateSubcategory->setToolTip(tr2i18n("Create new subcategory", 0));
#endif // QT_NO_TOOLTIP
        btnCreateSubcategory->setText(tr2i18n("+", 0));
        label_2->setText(tr2i18n("Subcategory:", 0));
        groupBoxedItem->setTitle(tr2i18n("Boxed products", 0));
        label_7->setText(tr2i18n("P&rice :", 0));
#ifndef UI_QT_NO_TOOLTIP
        editPricePerBox->setToolTip(tr2i18n("Price per box", 0));
#endif // QT_NO_TOOLTIP
        label_4->setText(tr2i18n("&Qty:", 0));
#ifndef UI_QT_NO_TOOLTIP
        editItemsPerBox->setToolTip(tr2i18n("Items per box", 0));
#endif // QT_NO_TOOLTIP
        btnAddItem->setText(tr2i18n("add this product", 0));
        groupBox->setTitle(tr2i18n("Items in this purchase", 0));
        QTableWidgetItem *___qtablewidgetitem = tableView->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(tr2i18n("Code", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableView->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(tr2i18n("Description", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableView->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(tr2i18n("Purchased Qty", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableView->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(tr2i18n("Total Qty", 0));
        btnRemoveItem->setText(tr2i18n("Remove Item from list", 0));
    } // retranslateUi

};

namespace Ui {
    class purchaseEditor: public Ui_purchaseEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PURCHASEEDITOR_H

