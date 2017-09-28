#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'mainview.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEW_H
#define UI_MAINVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStackedWidget>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "../../mibitWidgets/mibitlineedit.h"
#include "kplotwidget.h"

QT_BEGIN_NAMESPACE

class Ui_mainview
{
public:
    QHBoxLayout *hboxLayout;
    QSplitter *splitter;
    QFrame *frameLeft;
    QVBoxLayout *vboxLayout;
    QStackedWidget *groupWidgets;
    QWidget *pageIntro;
    QVBoxLayout *vboxLayout1;
    QWidget *pageEnterCode;
    QWidget *pageSearchItem;
    QVBoxLayout *vboxLayout2;
    KPlotWidget *plotSales;
    QRadioButton *rbFilterByPopularity;
    QCheckBox *rbFilterBySubCategory;
    QComboBox *comboFilterBySubCategory;
    QLineEdit *editFilterByDesc;
    QPushButton *btnCurrency;
    QGroupBox *groupDetails;
    QVBoxLayout *_2;
    QLabel *labelDetailDesc;
    QLabel *labelDetailPrice;
    QLabel *labelDetailDiscount;
    QLabel *labelDetailPoints;
    QLabel *labelDetailUnits;
    QLabel *labelDetailTotalTaxes;
    QLabel *lblSubtotalPre;
    QLabel *lblSubtotal;
    QLabel *labelDetailTax1;
    QLabel *lblSaleTaxesPre;
    QLabel *lblSaleTaxes;
    QGroupBox *groupPayment;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupClient;
    QVBoxLayout *verticalLayout_11;
    QLabel *labelDetailTax2;
    QLabel *labelTotalDiscountpre;
    QLabel *labelTotalDiscount;
    QGroupBox *groupSaleDate;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupTotals;
    QGridLayout *gridLayout;
    QPushButton *buttonSearchDone_2;
    QComboBox *comboCardType;
    QLabel *labelDetailPhoto;
    QPushButton *buttonSearchDone_3;
    QStackedWidget *stackedWidget_2;
    QWidget *page;
    QLabel *labelBanner;
    QWidget *page_2;
    QWidget *page_5;
    QStackedWidget *mainPanel;
    QWidget *page_Main;
    QHBoxLayout *hboxLayout1;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QSplitter *splitterGrid;
    QFrame *frameGridView;
    QGridLayout *gridLayout1;
    QRadioButton *rbFilterByCategory;
    MibitLineEdit *editItemCode;
    QRadioButton *rbFilterByDesc;
    QComboBox *comboFilterByCategory;
    QListView *listView;
    QTableWidget *tableWidget;
    QStackedWidget *stackedWidget_3;
    QWidget *page_10;
    QLabel *labelTotalpre;
    QLabel *labelTotal;
    QWidget *page_11;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    MibitLineEdit *editClient;
    QToolButton *btnAddClient;
    QLabel *lblClientDetails;
    QWidget *page_7;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *checkCash;
    QLabel *labelCashAmount;
    QLineEdit *editAmount;
    QRadioButton *checkCard;
    QRadioButton *checkOwnCredit;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnChangeSaleDate;
    QDateTimeEdit *editTransactionDate;
    QWidget *page_4;
    QVBoxLayout *vboxLayout3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelCardNumber;
    QLineEdit *editCardNumber;
    QLabel *labelAuthNumber;
    QLineEdit *editCardAuthNumber;
    QWidget *page_6;
    QLabel *labelChangepre;
    QLabel *labelChange;
    QWidget *page_Search;
    QGridLayout *gridLayout2;
    QLabel *label_5;
    QLabel *labelImageSearch;
    QPushButton *buttonSearchDone;
    QLineEdit *editItemDescSearch;
    QTableWidget *tableSearch;
    QLabel *labelSearchMsg;
    QWidget *pageTickets;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *lblTicketDatePicker;
    QDateEdit *editTicketDatePicker;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnTicketPrint;
    QPushButton *btnTicketDone;
    QTableView *ticketView;
    QWidget *pageReturnProduct;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QGridLayout *gridLayout3;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_8;
    QLabel *label_11;
    QSpacerItem *verticalSpacer_2;
    QFrame *line;
    QLabel *label_3;
    QTableWidget *tableReturnProducts;
    QGroupBox *groupBox;
    QLabel *lblReturnProdQty;
    QWidget *page_Adds;
    QFrame *frameCurrency;
    QGridLayout *gridLayout_3;
    QLabel *label_15;
    QComboBox *comboCurrency;
    QLabel *label_12;
    QLineEdit *editConvFactor;
    QLabel *label_13;
    QLineEdit *editConvQty;
    QLabel *label_14;
    QLineEdit *editConvResult;
    QPushButton *btnConvCancel;
    QPushButton *btnConvOk;
    QWidget *discountWidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *lbl_discounts;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *rbPriceChange;
    QRadioButton *rbPercentage;
    QHBoxLayout *horizontalLayout_3;
    MibitLineEdit *editDiscount;
    QPushButton *btnApplyDiscount;
    QPushButton *btnCancelDiscount;
    QRadioButton *rbCoupon;
    QRadioButton *rbMoney;
    QWidget *resumeWidget;
    QVBoxLayout *verticalLayout_7;
    QLabel *lblTitle;
    QTableView *tableSuspendedSales;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *contentTable;
    QWidget *creditWidget;
    QGridLayout *gridLayout_4;
    QTextEdit *creditContent;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_16;
    QLineEdit *editClientIdForCredit;
    QWidget *creditPaymentWidget;
    QVBoxLayout *verticalLayout_8;
    QGridLayout *gridLayout_5;
    QLabel *label_18;
    MibitLineEdit *editCreditTendered;
    QLabel *label_19;
    QLabel *lblCreditChange;
    QCheckBox *chKeepDebit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnPayCredit;
    QPushButton *btnPrintCreditReport;
    QPushButton *btnCancelCreditPayment;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *mainview)
    {
        if (mainview->objectName().isEmpty())
            mainview->setObjectName(QString::fromUtf8("mainview"));
        mainview->resize(435, 346);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainview->sizePolicy().hasHeightForWidth());
        mainview->setSizePolicy(sizePolicy);
        mainview->setMinimumSize(QSize(320, 240));
        mainview->setMaximumSize(QSize(16777215, 16777215));
        hboxLayout = new QHBoxLayout(mainview);
        hboxLayout->setSpacing(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(mainview);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setMinimumSize(QSize(0, 0));
        splitter->setMaximumSize(QSize(16777215, 16777215));
        splitter->setOrientation(Qt::Horizontal);
        frameLeft = new QFrame(splitter);
        frameLeft->setObjectName(QString::fromUtf8("frameLeft"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frameLeft->sizePolicy().hasHeightForWidth());
        frameLeft->setSizePolicy(sizePolicy1);
        frameLeft->setMinimumSize(QSize(0, 0));
        frameLeft->setMaximumSize(QSize(0, 16777215));
        frameLeft->setFrameShape(QFrame::StyledPanel);
        frameLeft->setFrameShadow(QFrame::Plain);
        vboxLayout = new QVBoxLayout(frameLeft);
        vboxLayout->setSpacing(0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        groupWidgets = new QStackedWidget(frameLeft);
        groupWidgets->setObjectName(QString::fromUtf8("groupWidgets"));
        sizePolicy1.setHeightForWidth(groupWidgets->sizePolicy().hasHeightForWidth());
        groupWidgets->setSizePolicy(sizePolicy1);
        pageIntro = new QWidget();
        pageIntro->setObjectName(QString::fromUtf8("pageIntro"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pageIntro->sizePolicy().hasHeightForWidth());
        pageIntro->setSizePolicy(sizePolicy2);
        vboxLayout1 = new QVBoxLayout(pageIntro);
        vboxLayout1->setSpacing(2);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        vboxLayout1->setContentsMargins(2, 2, 2, 2);
        groupWidgets->addWidget(pageIntro);
        pageEnterCode = new QWidget();
        pageEnterCode->setObjectName(QString::fromUtf8("pageEnterCode"));
        pageEnterCode->setAcceptDrops(true);
        groupWidgets->addWidget(pageEnterCode);
        pageSearchItem = new QWidget();
        pageSearchItem->setObjectName(QString::fromUtf8("pageSearchItem"));
        vboxLayout2 = new QVBoxLayout(pageSearchItem);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        vboxLayout2->setContentsMargins(2, 2, 2, 2);
        groupWidgets->addWidget(pageSearchItem);

        vboxLayout->addWidget(groupWidgets);

        plotSales = new KPlotWidget(frameLeft);
        plotSales->setObjectName(QString::fromUtf8("plotSales"));
        plotSales->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(plotSales->sizePolicy().hasHeightForWidth());
        plotSales->setSizePolicy(sizePolicy3);
        plotSales->setMinimumSize(QSize(80, 160));
        plotSales->setMaximumSize(QSize(360, 80));
        plotSales->setLayoutDirection(Qt::RightToLeft);
        plotSales->setLineWidth(0);
        plotSales->setProperty("backgroundColor", QVariant(QColor(0, 51, 153)));
        rbFilterByPopularity = new QRadioButton(plotSales);
        rbFilterByPopularity->setObjectName(QString::fromUtf8("rbFilterByPopularity"));
        rbFilterByPopularity->setGeometry(QRect(-10, 110, 109, 22));
        rbFilterBySubCategory = new QCheckBox(plotSales);
        rbFilterBySubCategory->setObjectName(QString::fromUtf8("rbFilterBySubCategory"));
        rbFilterBySubCategory->setGeometry(QRect(-20, 90, 56, 22));
        comboFilterBySubCategory = new QComboBox(plotSales);
        comboFilterBySubCategory->setObjectName(QString::fromUtf8("comboFilterBySubCategory"));
        comboFilterBySubCategory->setGeometry(QRect(-40, 60, 85, 27));
        comboFilterBySubCategory->setMaximumSize(QSize(160, 16777215));

        vboxLayout->addWidget(plotSales);

        editFilterByDesc = new QLineEdit(frameLeft);
        editFilterByDesc->setObjectName(QString::fromUtf8("editFilterByDesc"));

        vboxLayout->addWidget(editFilterByDesc);

        btnCurrency = new QPushButton(frameLeft);
        btnCurrency->setObjectName(QString::fromUtf8("btnCurrency"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(24);
        sizePolicy4.setVerticalStretch(24);
        sizePolicy4.setHeightForWidth(btnCurrency->sizePolicy().hasHeightForWidth());
        btnCurrency->setSizePolicy(sizePolicy4);
        btnCurrency->setMinimumSize(QSize(24, 24));
        btnCurrency->setMaximumSize(QSize(24, 24));

        vboxLayout->addWidget(btnCurrency);

        groupDetails = new QGroupBox(frameLeft);
        groupDetails->setObjectName(QString::fromUtf8("groupDetails"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupDetails->sizePolicy().hasHeightForWidth());
        groupDetails->setSizePolicy(sizePolicy5);
        groupDetails->setMinimumSize(QSize(0, 0));
        groupDetails->setMaximumSize(QSize(220, 160));
        groupDetails->setLayoutDirection(Qt::LeftToRight);
        groupDetails->setStyleSheet(QString::fromUtf8(""));
        groupDetails->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        _2 = new QVBoxLayout(groupDetails);
        _2->setSpacing(0);
        _2->setObjectName(QString::fromUtf8("_2"));
        _2->setContentsMargins(0, 0, 0, 0);
        labelDetailDesc = new QLabel(groupDetails);
        labelDetailDesc->setObjectName(QString::fromUtf8("labelDetailDesc"));
        sizePolicy2.setHeightForWidth(labelDetailDesc->sizePolicy().hasHeightForWidth());
        labelDetailDesc->setSizePolicy(sizePolicy2);
        labelDetailDesc->setMaximumSize(QSize(16777215, 16777215));
        labelDetailDesc->setStyleSheet(QString::fromUtf8(""));
        labelDetailDesc->setFrameShape(QFrame::StyledPanel);
        labelDetailDesc->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelDetailDesc->setWordWrap(true);
        labelDetailDesc->setIndent(4);

        _2->addWidget(labelDetailDesc);

        labelDetailPrice = new QLabel(groupDetails);
        labelDetailPrice->setObjectName(QString::fromUtf8("labelDetailPrice"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(labelDetailPrice->sizePolicy().hasHeightForWidth());
        labelDetailPrice->setSizePolicy(sizePolicy6);
        QFont font;
        font.setPointSize(16);
        labelDetailPrice->setFont(font);
        labelDetailPrice->setStyleSheet(QString::fromUtf8(""));
        labelDetailPrice->setFrameShape(QFrame::NoFrame);
        labelDetailPrice->setIndent(8);

        _2->addWidget(labelDetailPrice);

        labelDetailDiscount = new QLabel(groupDetails);
        labelDetailDiscount->setObjectName(QString::fromUtf8("labelDetailDiscount"));
        sizePolicy6.setHeightForWidth(labelDetailDiscount->sizePolicy().hasHeightForWidth());
        labelDetailDiscount->setSizePolicy(sizePolicy6);
        labelDetailDiscount->setStyleSheet(QString::fromUtf8(""));
        labelDetailDiscount->setFrameShape(QFrame::NoFrame);
        labelDetailDiscount->setIndent(12);

        _2->addWidget(labelDetailDiscount);

        labelDetailPoints = new QLabel(groupDetails);
        labelDetailPoints->setObjectName(QString::fromUtf8("labelDetailPoints"));
        sizePolicy2.setHeightForWidth(labelDetailPoints->sizePolicy().hasHeightForWidth());
        labelDetailPoints->setSizePolicy(sizePolicy2);
        labelDetailPoints->setIndent(12);

        _2->addWidget(labelDetailPoints);

        labelDetailUnits = new QLabel(groupDetails);
        labelDetailUnits->setObjectName(QString::fromUtf8("labelDetailUnits"));
        sizePolicy6.setHeightForWidth(labelDetailUnits->sizePolicy().hasHeightForWidth());
        labelDetailUnits->setSizePolicy(sizePolicy6);
        labelDetailUnits->setStyleSheet(QString::fromUtf8(""));
        labelDetailUnits->setFrameShape(QFrame::NoFrame);
        labelDetailUnits->setIndent(12);

        _2->addWidget(labelDetailUnits);

        labelDetailTotalTaxes = new QLabel(groupDetails);
        labelDetailTotalTaxes->setObjectName(QString::fromUtf8("labelDetailTotalTaxes"));
        sizePolicy2.setHeightForWidth(labelDetailTotalTaxes->sizePolicy().hasHeightForWidth());
        labelDetailTotalTaxes->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(11);
        labelDetailTotalTaxes->setFont(font1);
        labelDetailTotalTaxes->setStyleSheet(QString::fromUtf8(""));
        labelDetailTotalTaxes->setFrameShape(QFrame::NoFrame);
        labelDetailTotalTaxes->setIndent(12);

        _2->addWidget(labelDetailTotalTaxes);

        lblSubtotalPre = new QLabel(groupDetails);
        lblSubtotalPre->setObjectName(QString::fromUtf8("lblSubtotalPre"));
        lblSubtotalPre->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        _2->addWidget(lblSubtotalPre);

        lblSubtotal = new QLabel(groupDetails);
        lblSubtotal->setObjectName(QString::fromUtf8("lblSubtotal"));
        sizePolicy3.setHeightForWidth(lblSubtotal->sizePolicy().hasHeightForWidth());
        lblSubtotal->setSizePolicy(sizePolicy3);
        lblSubtotal->setMaximumSize(QSize(200, 16777215));
        lblSubtotal->setTextFormat(Qt::AutoText);
        lblSubtotal->setScaledContents(false);
        lblSubtotal->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        _2->addWidget(lblSubtotal);

        labelDetailTax1 = new QLabel(groupDetails);
        labelDetailTax1->setObjectName(QString::fromUtf8("labelDetailTax1"));
        sizePolicy6.setHeightForWidth(labelDetailTax1->sizePolicy().hasHeightForWidth());
        labelDetailTax1->setSizePolicy(sizePolicy6);
        QFont font2;
        font2.setPointSize(9);
        labelDetailTax1->setFont(font2);
        labelDetailTax1->setStyleSheet(QString::fromUtf8(""));
        labelDetailTax1->setFrameShape(QFrame::NoFrame);
        labelDetailTax1->setIndent(18);

        _2->addWidget(labelDetailTax1);

        lblSaleTaxesPre = new QLabel(groupDetails);
        lblSaleTaxesPre->setObjectName(QString::fromUtf8("lblSaleTaxesPre"));
        lblSaleTaxesPre->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        _2->addWidget(lblSaleTaxesPre);

        lblSaleTaxes = new QLabel(groupDetails);
        lblSaleTaxes->setObjectName(QString::fromUtf8("lblSaleTaxes"));
        sizePolicy3.setHeightForWidth(lblSaleTaxes->sizePolicy().hasHeightForWidth());
        lblSaleTaxes->setSizePolicy(sizePolicy3);
        lblSaleTaxes->setMaximumSize(QSize(200, 16777215));
        lblSaleTaxes->setScaledContents(false);
        lblSaleTaxes->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        _2->addWidget(lblSaleTaxes);

        groupPayment = new QGroupBox(groupDetails);
        groupPayment->setObjectName(QString::fromUtf8("groupPayment"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(groupPayment->sizePolicy().hasHeightForWidth());
        groupPayment->setSizePolicy(sizePolicy7);
        groupPayment->setMinimumSize(QSize(380, 0));
        groupPayment->setMaximumSize(QSize(16777215, 115));
        groupPayment->setAutoFillBackground(false);
        groupPayment->setStyleSheet(QString::fromUtf8(""));
        groupPayment->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout_10 = new QVBoxLayout(groupPayment);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        groupClient = new QGroupBox(groupPayment);
        groupClient->setObjectName(QString::fromUtf8("groupClient"));
        sizePolicy1.setHeightForWidth(groupClient->sizePolicy().hasHeightForWidth());
        groupClient->setSizePolicy(sizePolicy1);
        groupClient->setMinimumSize(QSize(381, 0));
        groupClient->setMaximumSize(QSize(16777215, 80));
        groupClient->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout_11 = new QVBoxLayout(groupClient);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(9, 0, 9, 0);

        verticalLayout_10->addWidget(groupClient);


        _2->addWidget(groupPayment);

        labelDetailTax2 = new QLabel(groupDetails);
        labelDetailTax2->setObjectName(QString::fromUtf8("labelDetailTax2"));
        sizePolicy6.setHeightForWidth(labelDetailTax2->sizePolicy().hasHeightForWidth());
        labelDetailTax2->setSizePolicy(sizePolicy6);
        labelDetailTax2->setFont(font2);
        labelDetailTax2->setStyleSheet(QString::fromUtf8(""));
        labelDetailTax2->setFrameShape(QFrame::NoFrame);
        labelDetailTax2->setIndent(18);

        _2->addWidget(labelDetailTax2);

        labelTotalDiscountpre = new QLabel(groupDetails);
        labelTotalDiscountpre->setObjectName(QString::fromUtf8("labelTotalDiscountpre"));
        labelTotalDiscountpre->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        _2->addWidget(labelTotalDiscountpre);

        labelTotalDiscount = new QLabel(groupDetails);
        labelTotalDiscount->setObjectName(QString::fromUtf8("labelTotalDiscount"));
        sizePolicy3.setHeightForWidth(labelTotalDiscount->sizePolicy().hasHeightForWidth());
        labelTotalDiscount->setSizePolicy(sizePolicy3);
        labelTotalDiscount->setMaximumSize(QSize(200, 16777215));
        labelTotalDiscount->setScaledContents(true);
        labelTotalDiscount->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        _2->addWidget(labelTotalDiscount);


        vboxLayout->addWidget(groupDetails);

        groupSaleDate = new QGroupBox(frameLeft);
        groupSaleDate->setObjectName(QString::fromUtf8("groupSaleDate"));
        sizePolicy1.setHeightForWidth(groupSaleDate->sizePolicy().hasHeightForWidth());
        groupSaleDate->setSizePolicy(sizePolicy1);
        groupSaleDate->setMinimumSize(QSize(0, 60));
        verticalLayout = new QVBoxLayout(groupSaleDate);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupTotals = new QGroupBox(groupSaleDate);
        groupTotals->setObjectName(QString::fromUtf8("groupTotals"));
        QSizePolicy sizePolicy8(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(groupTotals->sizePolicy().hasHeightForWidth());
        groupTotals->setSizePolicy(sizePolicy8);
        groupTotals->setMinimumSize(QSize(0, 85));
        groupTotals->setMaximumSize(QSize(380, 65));
        groupTotals->setStyleSheet(QString::fromUtf8(""));
        groupTotals->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupTotals->setFlat(false);
        gridLayout = new QGridLayout(groupTotals);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 12, 0);

        verticalLayout->addWidget(groupTotals);

        buttonSearchDone_2 = new QPushButton(groupSaleDate);
        buttonSearchDone_2->setObjectName(QString::fromUtf8("buttonSearchDone_2"));

        verticalLayout->addWidget(buttonSearchDone_2);

        comboCardType = new QComboBox(groupSaleDate);
        comboCardType->setObjectName(QString::fromUtf8("comboCardType"));

        verticalLayout->addWidget(comboCardType);

        labelDetailPhoto = new QLabel(groupSaleDate);
        labelDetailPhoto->setObjectName(QString::fromUtf8("labelDetailPhoto"));
        QSizePolicy sizePolicy9(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(labelDetailPhoto->sizePolicy().hasHeightForWidth());
        labelDetailPhoto->setSizePolicy(sizePolicy9);
        labelDetailPhoto->setMinimumSize(QSize(150, 150));
        labelDetailPhoto->setMaximumSize(QSize(150, 150));
        QFont font3;
        font3.setPointSize(8);
        labelDetailPhoto->setFont(font3);
        labelDetailPhoto->setStyleSheet(QString::fromUtf8(""));
        labelDetailPhoto->setFrameShape(QFrame::NoFrame);
        labelDetailPhoto->setFrameShadow(QFrame::Plain);
        labelDetailPhoto->setLineWidth(1);
        labelDetailPhoto->setScaledContents(false);
        labelDetailPhoto->setAlignment(Qt::AlignCenter);
        labelDetailPhoto->setIndent(0);

        verticalLayout->addWidget(labelDetailPhoto);

        buttonSearchDone_3 = new QPushButton(groupSaleDate);
        buttonSearchDone_3->setObjectName(QString::fromUtf8("buttonSearchDone_3"));

        verticalLayout->addWidget(buttonSearchDone_3);

        stackedWidget_2 = new QStackedWidget(groupSaleDate);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        sizePolicy5.setHeightForWidth(stackedWidget_2->sizePolicy().hasHeightForWidth());
        stackedWidget_2->setSizePolicy(sizePolicy5);
        stackedWidget_2->setMinimumSize(QSize(380, 160));
        stackedWidget_2->setMaximumSize(QSize(16777215, 160));
        stackedWidget_2->setFrameShape(QFrame::NoFrame);
        stackedWidget_2->setFrameShadow(QFrame::Raised);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        labelBanner = new QLabel(page);
        labelBanner->setObjectName(QString::fromUtf8("labelBanner"));
        labelBanner->setGeometry(QRect(0, 0, 360, 160));
        sizePolicy3.setHeightForWidth(labelBanner->sizePolicy().hasHeightForWidth());
        labelBanner->setSizePolicy(sizePolicy3);
        labelBanner->setMinimumSize(QSize(360, 160));
        labelBanner->setMaximumSize(QSize(16777215, 160));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(254, 254, 254, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush3(QColor(127, 127, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(169, 169, 169, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush5(QColor(255, 255, 220, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        labelBanner->setPalette(palette);
        labelBanner->setLayoutDirection(Qt::LeftToRight);
        labelBanner->setAutoFillBackground(true);
        labelBanner->setLineWidth(0);
        labelBanner->setScaledContents(true);
        labelBanner->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        stackedWidget_2->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget_2->addWidget(page_2);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        stackedWidget_2->addWidget(page_5);

        verticalLayout->addWidget(stackedWidget_2);


        vboxLayout->addWidget(groupSaleDate);

        splitter->addWidget(frameLeft);
        mainPanel = new QStackedWidget(splitter);
        mainPanel->setObjectName(QString::fromUtf8("mainPanel"));
        sizePolicy.setHeightForWidth(mainPanel->sizePolicy().hasHeightForWidth());
        mainPanel->setSizePolicy(sizePolicy);
        page_Main = new QWidget();
        page_Main->setObjectName(QString::fromUtf8("page_Main"));
        sizePolicy.setHeightForWidth(page_Main->sizePolicy().hasHeightForWidth());
        page_Main->setSizePolicy(sizePolicy);
        hboxLayout1 = new QHBoxLayout(page_Main);
        hboxLayout1->setSpacing(0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        hboxLayout1->setSizeConstraint(QLayout::SetNoConstraint);
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(page_Main);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        splitterGrid = new QSplitter(frame);
        splitterGrid->setObjectName(QString::fromUtf8("splitterGrid"));
        QSizePolicy sizePolicy10(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(splitterGrid->sizePolicy().hasHeightForWidth());
        splitterGrid->setSizePolicy(sizePolicy10);
        splitterGrid->setMinimumSize(QSize(0, 224));
        splitterGrid->setMaximumSize(QSize(16777215, 16777215));
        splitterGrid->setOrientation(Qt::Vertical);
        splitterGrid->setHandleWidth(2);
        frameGridView = new QFrame(splitterGrid);
        frameGridView->setObjectName(QString::fromUtf8("frameGridView"));
        sizePolicy.setHeightForWidth(frameGridView->sizePolicy().hasHeightForWidth());
        frameGridView->setSizePolicy(sizePolicy);
        frameGridView->setMinimumSize(QSize(0, 155));
        frameGridView->setFrameShape(QFrame::StyledPanel);
        frameGridView->setFrameShadow(QFrame::Raised);
        gridLayout1 = new QGridLayout(frameGridView);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        gridLayout1->setHorizontalSpacing(2);
        gridLayout1->setVerticalSpacing(0);
        gridLayout1->setContentsMargins(2, 2, 2, 2);
        rbFilterByCategory = new QRadioButton(frameGridView);
        rbFilterByCategory->setObjectName(QString::fromUtf8("rbFilterByCategory"));

        gridLayout1->addWidget(rbFilterByCategory, 0, 5, 1, 1);

        editItemCode = new MibitLineEdit(frameGridView);
        editItemCode->setObjectName(QString::fromUtf8("editItemCode"));
        QSizePolicy sizePolicy11(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(editItemCode->sizePolicy().hasHeightForWidth());
        editItemCode->setSizePolicy(sizePolicy11);
        editItemCode->setMinimumSize(QSize(0, 0));
        editItemCode->setMaximumSize(QSize(16777215, 16777215));
        editItemCode->setFrame(true);

        gridLayout1->addWidget(editItemCode, 0, 2, 1, 1);

        rbFilterByDesc = new QRadioButton(frameGridView);
        rbFilterByDesc->setObjectName(QString::fromUtf8("rbFilterByDesc"));

        gridLayout1->addWidget(rbFilterByDesc, 0, 1, 1, 1);

        comboFilterByCategory = new QComboBox(frameGridView);
        comboFilterByCategory->setObjectName(QString::fromUtf8("comboFilterByCategory"));
        comboFilterByCategory->setMaximumSize(QSize(160, 16777215));

        gridLayout1->addWidget(comboFilterByCategory, 0, 6, 1, 1);

        listView = new QListView(frameGridView);
        listView->setObjectName(QString::fromUtf8("listView"));
        sizePolicy.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy);
        listView->setMinimumSize(QSize(0, 126));
        listView->setMaximumSize(QSize(16777215, 16777215));
        listView->setLayoutDirection(Qt::LeftToRight);
        listView->setAutoScrollMargin(16);

        gridLayout1->addWidget(listView, 5, 0, 1, 8);

        splitterGrid->addWidget(frameGridView);
        tableWidget = new QTableWidget(splitterGrid);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setWeight(50);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font4);
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(0, 60));
        tableWidget->setMaximumSize(QSize(16777215, 16777215));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        tableWidget->setFont(font5);
        tableWidget->setFocusPolicy(Qt::NoFocus);
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        tableWidget->setFrameShape(QFrame::StyledPanel);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setAutoScroll(true);
        tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
        tableWidget->setTabKeyNavigation(false);
        tableWidget->setProperty("showDropIndicator", QVariant(false));
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setCornerButtonEnabled(false);
        splitterGrid->addWidget(tableWidget);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget->verticalHeader()->setVisible(false);

        gridLayout_2->addWidget(splitterGrid, 0, 0, 1, 2);

        stackedWidget_3 = new QStackedWidget(frame);
        stackedWidget_3->setObjectName(QString::fromUtf8("stackedWidget_3"));
        QSizePolicy sizePolicy12(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(stackedWidget_3->sizePolicy().hasHeightForWidth());
        stackedWidget_3->setSizePolicy(sizePolicy12);
        stackedWidget_3->setMinimumSize(QSize(0, 66));
        stackedWidget_3->setMaximumSize(QSize(16777215, 66));
        stackedWidget_3->setLayoutDirection(Qt::LeftToRight);
        stackedWidget_3->setFrameShape(QFrame::NoFrame);
        stackedWidget_3->setFrameShadow(QFrame::Raised);
        stackedWidget_3->setLineWidth(0);
        page_10 = new QWidget();
        page_10->setObjectName(QString::fromUtf8("page_10"));
        labelTotalpre = new QLabel(page_10);
        labelTotalpre->setObjectName(QString::fromUtf8("labelTotalpre"));
        labelTotalpre->setGeometry(QRect(0, 20, 160, 41));
        QSizePolicy sizePolicy13(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy13.setHorizontalStretch(0);
        sizePolicy13.setVerticalStretch(0);
        sizePolicy13.setHeightForWidth(labelTotalpre->sizePolicy().hasHeightForWidth());
        labelTotalpre->setSizePolicy(sizePolicy13);
        labelTotalpre->setMinimumSize(QSize(0, 0));
        labelTotalpre->setMaximumSize(QSize(16777215, 16777215));
        QFont font6;
        font6.setPointSize(28);
        labelTotalpre->setFont(font6);
        labelTotalpre->setLayoutDirection(Qt::LeftToRight);
        labelTotalpre->setFrameShape(QFrame::NoFrame);
        labelTotalpre->setScaledContents(true);
        labelTotalpre->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        labelTotalpre->setIndent(0);
        labelTotal = new QLabel(page_10);
        labelTotal->setObjectName(QString::fromUtf8("labelTotal"));
        labelTotal->setGeometry(QRect(160, 20, 200, 41));
        sizePolicy3.setHeightForWidth(labelTotal->sizePolicy().hasHeightForWidth());
        labelTotal->setSizePolicy(sizePolicy3);
        labelTotal->setMinimumSize(QSize(0, 0));
        labelTotal->setMaximumSize(QSize(200, 16777215));
        labelTotal->setFont(font6);
        labelTotal->setLayoutDirection(Qt::LeftToRight);
        labelTotal->setFrameShape(QFrame::NoFrame);
        labelTotal->setScaledContents(true);
        labelTotal->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        stackedWidget_3->addWidget(page_10);
        page_11 = new QWidget();
        page_11->setObjectName(QString::fromUtf8("page_11"));
        layoutWidget = new QWidget(page_11);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 461, 66));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_6->setContentsMargins(0, 0, 35, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(65, 16777215));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label);

        editClient = new MibitLineEdit(layoutWidget);
        editClient->setObjectName(QString::fromUtf8("editClient"));
        sizePolicy11.setHeightForWidth(editClient->sizePolicy().hasHeightForWidth());
        editClient->setSizePolicy(sizePolicy11);
        editClient->setMinimumSize(QSize(0, 0));
        editClient->setMaximumSize(QSize(16777215, 16777215));
        editClient->setFont(font4);
        editClient->setAutoFillBackground(false);

        horizontalLayout_6->addWidget(editClient);

        btnAddClient = new QToolButton(layoutWidget);
        btnAddClient->setObjectName(QString::fromUtf8("btnAddClient"));
        sizePolicy13.setHeightForWidth(btnAddClient->sizePolicy().hasHeightForWidth());
        btnAddClient->setSizePolicy(sizePolicy13);
        btnAddClient->setMaximumSize(QSize(21, 21));
        QFont font7;
        font7.setPointSize(12);
        btnAddClient->setFont(font7);

        horizontalLayout_6->addWidget(btnAddClient);

        lblClientDetails = new QLabel(layoutWidget);
        lblClientDetails->setObjectName(QString::fromUtf8("lblClientDetails"));
        sizePolicy.setHeightForWidth(lblClientDetails->sizePolicy().hasHeightForWidth());
        lblClientDetails->setSizePolicy(sizePolicy);
        lblClientDetails->setMinimumSize(QSize(0, 0));
        lblClientDetails->setMaximumSize(QSize(16777215, 16777215));
        QFont font8;
        font8.setPointSize(9);
        font8.setItalic(true);
        lblClientDetails->setFont(font8);
        lblClientDetails->setStyleSheet(QString::fromUtf8("background:white;\n"
"border: 1px solid gray;\n"
"border-radius: 4px;\n"
"padding: 2px;\n"
"font-weight:normal;\n"
"color:black;"));
        lblClientDetails->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(lblClientDetails);

        stackedWidget_3->addWidget(page_11);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        layoutWidget1 = new QWidget(page_7);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 1, 421, 34));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        checkCash = new QRadioButton(layoutWidget1);
        checkCash->setObjectName(QString::fromUtf8("checkCash"));
        sizePolicy6.setHeightForWidth(checkCash->sizePolicy().hasHeightForWidth());
        checkCash->setSizePolicy(sizePolicy6);
        checkCash->setMaximumSize(QSize(140, 16777215));
        checkCash->setChecked(true);

        horizontalLayout_4->addWidget(checkCash);

        labelCashAmount = new QLabel(layoutWidget1);
        labelCashAmount->setObjectName(QString::fromUtf8("labelCashAmount"));
        QSizePolicy sizePolicy14(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy14.setHorizontalStretch(0);
        sizePolicy14.setVerticalStretch(0);
        sizePolicy14.setHeightForWidth(labelCashAmount->sizePolicy().hasHeightForWidth());
        labelCashAmount->setSizePolicy(sizePolicy14);
        labelCashAmount->setMaximumSize(QSize(500, 30));

        horizontalLayout_4->addWidget(labelCashAmount);

        editAmount = new QLineEdit(layoutWidget1);
        editAmount->setObjectName(QString::fromUtf8("editAmount"));
        sizePolicy11.setHeightForWidth(editAmount->sizePolicy().hasHeightForWidth());
        editAmount->setSizePolicy(sizePolicy11);
        editAmount->setMinimumSize(QSize(50, 0));
        editAmount->setMaximumSize(QSize(16777215, 16777215));
        QFont font9;
        font9.setPointSize(14);
        font9.setBold(true);
        font9.setWeight(75);
        editAmount->setFont(font9);
        editAmount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(editAmount);

        checkCard = new QRadioButton(layoutWidget1);
        checkCard->setObjectName(QString::fromUtf8("checkCard"));
        sizePolicy6.setHeightForWidth(checkCard->sizePolicy().hasHeightForWidth());
        checkCard->setSizePolicy(sizePolicy6);
        checkCard->setMinimumSize(QSize(0, 0));
        checkCard->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(checkCard);

        checkOwnCredit = new QRadioButton(layoutWidget1);
        checkOwnCredit->setObjectName(QString::fromUtf8("checkOwnCredit"));
        QSizePolicy sizePolicy15(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy15.setHorizontalStretch(0);
        sizePolicy15.setVerticalStretch(0);
        sizePolicy15.setHeightForWidth(checkOwnCredit->sizePolicy().hasHeightForWidth());
        checkOwnCredit->setSizePolicy(sizePolicy15);
        checkOwnCredit->setMaximumSize(QSize(160, 16777215));

        horizontalLayout_4->addWidget(checkOwnCredit);

        stackedWidget = new QStackedWidget(page_7);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 30, 441, 45));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setMinimumSize(QSize(0, 0));
        stackedWidget->setMaximumSize(QSize(16777215, 110));
        stackedWidget->setBaseSize(QSize(0, 0));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        stackedWidget->setLineWidth(0);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_4 = new QVBoxLayout(page_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 10, -1);
        btnChangeSaleDate = new QPushButton(page_3);
        btnChangeSaleDate->setObjectName(QString::fromUtf8("btnChangeSaleDate"));

        horizontalLayout_2->addWidget(btnChangeSaleDate);

        editTransactionDate = new QDateTimeEdit(page_3);
        editTransactionDate->setObjectName(QString::fromUtf8("editTransactionDate"));
        editTransactionDate->setMaximumSize(QSize(138, 16777215));
        editTransactionDate->setCalendarPopup(true);

        horizontalLayout_2->addWidget(editTransactionDate);


        verticalLayout_4->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        vboxLayout3 = new QVBoxLayout(page_4);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        vboxLayout3->setContentsMargins(4, 4, 4, 4);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, -1, 18, -1);
        labelCardNumber = new QLabel(page_4);
        labelCardNumber->setObjectName(QString::fromUtf8("labelCardNumber"));
        sizePolicy3.setHeightForWidth(labelCardNumber->sizePolicy().hasHeightForWidth());
        labelCardNumber->setSizePolicy(sizePolicy3);

        horizontalLayout_7->addWidget(labelCardNumber);

        editCardNumber = new QLineEdit(page_4);
        editCardNumber->setObjectName(QString::fromUtf8("editCardNumber"));
        sizePolicy11.setHeightForWidth(editCardNumber->sizePolicy().hasHeightForWidth());
        editCardNumber->setSizePolicy(sizePolicy11);
        editCardNumber->setMinimumSize(QSize(160, 0));
        editCardNumber->setMaximumSize(QSize(180, 16777215));
        editCardNumber->setCursorPosition(19);

        horizontalLayout_7->addWidget(editCardNumber);

        labelAuthNumber = new QLabel(page_4);
        labelAuthNumber->setObjectName(QString::fromUtf8("labelAuthNumber"));

        horizontalLayout_7->addWidget(labelAuthNumber);

        editCardAuthNumber = new QLineEdit(page_4);
        editCardAuthNumber->setObjectName(QString::fromUtf8("editCardAuthNumber"));

        horizontalLayout_7->addWidget(editCardAuthNumber);


        vboxLayout3->addLayout(horizontalLayout_7);

        stackedWidget->addWidget(page_4);
        stackedWidget_3->addWidget(page_7);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        labelChangepre = new QLabel(page_6);
        labelChangepre->setObjectName(QString::fromUtf8("labelChangepre"));
        labelChangepre->setGeometry(QRect(0, 0, 171, 61));
        sizePolicy13.setHeightForWidth(labelChangepre->sizePolicy().hasHeightForWidth());
        labelChangepre->setSizePolicy(sizePolicy13);
        labelChangepre->setMinimumSize(QSize(0, 0));
        labelChangepre->setMaximumSize(QSize(16777215, 16777215));
        labelChangepre->setFont(font6);
        labelChangepre->setLayoutDirection(Qt::LeftToRight);
        labelChangepre->setFrameShape(QFrame::NoFrame);
        labelChangepre->setLineWidth(1);
        labelChangepre->setScaledContents(true);
        labelChangepre->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        labelChangepre->setMargin(0);
        labelChangepre->setIndent(0);
        labelChange = new QLabel(page_6);
        labelChange->setObjectName(QString::fromUtf8("labelChange"));
        labelChange->setGeometry(QRect(180, 20, 181, 41));
        sizePolicy3.setHeightForWidth(labelChange->sizePolicy().hasHeightForWidth());
        labelChange->setSizePolicy(sizePolicy3);
        labelChange->setMinimumSize(QSize(0, 0));
        labelChange->setMaximumSize(QSize(200, 16777215));
        labelChange->setFont(font6);
        labelChange->setLayoutDirection(Qt::LeftToRight);
        labelChange->setFrameShape(QFrame::NoFrame);
        labelChange->setScaledContents(true);
        labelChange->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        stackedWidget_3->addWidget(page_6);

        gridLayout_2->addWidget(stackedWidget_3, 1, 0, 1, 1);


        hboxLayout1->addWidget(frame);

        mainPanel->addWidget(page_Main);
        page_Search = new QWidget();
        page_Search->setObjectName(QString::fromUtf8("page_Search"));
        gridLayout2 = new QGridLayout(page_Search);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        label_5 = new QLabel(page_Search);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy6.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy6);

        gridLayout2->addWidget(label_5, 0, 2, 1, 1);

        labelImageSearch = new QLabel(page_Search);
        labelImageSearch->setObjectName(QString::fromUtf8("labelImageSearch"));
        sizePolicy14.setHeightForWidth(labelImageSearch->sizePolicy().hasHeightForWidth());
        labelImageSearch->setSizePolicy(sizePolicy14);
        labelImageSearch->setAlignment(Qt::AlignCenter);

        gridLayout2->addWidget(labelImageSearch, 0, 1, 1, 1);

        buttonSearchDone = new QPushButton(page_Search);
        buttonSearchDone->setObjectName(QString::fromUtf8("buttonSearchDone"));
        buttonSearchDone->setEnabled(true);

        gridLayout2->addWidget(buttonSearchDone, 0, 5, 1, 1);

        editItemDescSearch = new QLineEdit(page_Search);
        editItemDescSearch->setObjectName(QString::fromUtf8("editItemDescSearch"));
        sizePolicy11.setHeightForWidth(editItemDescSearch->sizePolicy().hasHeightForWidth());
        editItemDescSearch->setSizePolicy(sizePolicy11);

        gridLayout2->addWidget(editItemDescSearch, 0, 3, 1, 1);

        tableSearch = new QTableWidget(page_Search);
        if (tableSearch->columnCount() < 6)
            tableSearch->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableSearch->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableSearch->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableSearch->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableSearch->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableSearch->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableSearch->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        tableSearch->setObjectName(QString::fromUtf8("tableSearch"));
        tableSearch->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableSearch->setAlternatingRowColors(false);
        tableSearch->setSelectionMode(QAbstractItemView::SingleSelection);
        tableSearch->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout2->addWidget(tableSearch, 5, 0, 2, 6);

        labelSearchMsg = new QLabel(page_Search);
        labelSearchMsg->setObjectName(QString::fromUtf8("labelSearchMsg"));
        labelSearchMsg->setWordWrap(true);

        gridLayout2->addWidget(labelSearchMsg, 0, 4, 1, 1);

        mainPanel->addWidget(page_Search);
        pageTickets = new QWidget();
        pageTickets->setObjectName(QString::fromUtf8("pageTickets"));
        verticalLayout_2 = new QVBoxLayout(pageTickets);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(pageTickets);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lblTicketDatePicker = new QLabel(pageTickets);
        lblTicketDatePicker->setObjectName(QString::fromUtf8("lblTicketDatePicker"));

        horizontalLayout->addWidget(lblTicketDatePicker);

        editTicketDatePicker = new QDateEdit(pageTickets);
        editTicketDatePicker->setObjectName(QString::fromUtf8("editTicketDatePicker"));
        editTicketDatePicker->setCalendarPopup(true);

        horizontalLayout->addWidget(editTicketDatePicker);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnTicketPrint = new QPushButton(pageTickets);
        btnTicketPrint->setObjectName(QString::fromUtf8("btnTicketPrint"));

        horizontalLayout->addWidget(btnTicketPrint);

        btnTicketDone = new QPushButton(pageTickets);
        btnTicketDone->setObjectName(QString::fromUtf8("btnTicketDone"));

        horizontalLayout->addWidget(btnTicketDone);


        verticalLayout_2->addLayout(horizontalLayout);

        ticketView = new QTableView(pageTickets);
        ticketView->setObjectName(QString::fromUtf8("ticketView"));

        verticalLayout_2->addWidget(ticketView);

        mainPanel->addWidget(pageTickets);
        pageReturnProduct = new QWidget();
        pageReturnProduct->setObjectName(QString::fromUtf8("pageReturnProduct"));
        verticalLayout_3 = new QVBoxLayout(pageReturnProduct);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(pageReturnProduct);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        gridLayout3 = new QGridLayout();
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        gridLayout3->setHorizontalSpacing(4);
        gridLayout3->setVerticalSpacing(6);
        label_6 = new QLabel(pageReturnProduct);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(125, 0));
        label_6->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 255), stop:0 rgba(255, 255, 255, 0));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 9pt \"Lucida Grande\";"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout3->addWidget(label_6, 0, 0, 1, 1);

        label_9 = new QLabel(pageReturnProduct);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy16(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy16.setHorizontalStretch(0);
        sizePolicy16.setVerticalStretch(0);
        sizePolicy16.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy16);

        gridLayout3->addWidget(label_9, 0, 1, 1, 1);

        label_7 = new QLabel(pageReturnProduct);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(125, 0));
        label_7->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 255), stop:0 rgba(255, 255, 255, 0));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 9pt \"Lucida Grande\";"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout3->addWidget(label_7, 1, 0, 1, 1);

        label_10 = new QLabel(pageReturnProduct);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy16.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy16);

        gridLayout3->addWidget(label_10, 1, 1, 1, 1);

        label_8 = new QLabel(pageReturnProduct);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(125, 0));
        label_8->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 255), stop:0 rgba(255, 255, 255, 0));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 9pt \"Lucida Grande\";"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout3->addWidget(label_8, 2, 0, 1, 1);

        label_11 = new QLabel(pageReturnProduct);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QSizePolicy sizePolicy17(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy17.setHorizontalStretch(0);
        sizePolicy17.setVerticalStretch(0);
        sizePolicy17.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy17);

        gridLayout3->addWidget(label_11, 2, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout3);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_2);

        line = new QFrame(pageReturnProduct);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        label_3 = new QLabel(pageReturnProduct);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        tableReturnProducts = new QTableWidget(pageReturnProduct);
        if (tableReturnProducts->columnCount() < 5)
            tableReturnProducts->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableReturnProducts->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableReturnProducts->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableReturnProducts->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableReturnProducts->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableReturnProducts->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        tableReturnProducts->setObjectName(QString::fromUtf8("tableReturnProducts"));

        verticalLayout_3->addWidget(tableReturnProducts);

        groupBox = new QGroupBox(pageReturnProduct);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 200));
        lblReturnProdQty = new QLabel(groupBox);
        lblReturnProdQty->setObjectName(QString::fromUtf8("lblReturnProdQty"));
        lblReturnProdQty->setGeometry(QRect(20, 30, 57, 17));
        lblReturnProdQty->setFrameShape(QFrame::NoFrame);

        verticalLayout_3->addWidget(groupBox);

        mainPanel->addWidget(pageReturnProduct);
        page_Adds = new QWidget();
        page_Adds->setObjectName(QString::fromUtf8("page_Adds"));
        frameCurrency = new QFrame(page_Adds);
        frameCurrency->setObjectName(QString::fromUtf8("frameCurrency"));
        frameCurrency->setGeometry(QRect(30, 10, 211, 200));
        frameCurrency->setFrameShape(QFrame::NoFrame);
        frameCurrency->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frameCurrency);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_15 = new QLabel(frameCurrency);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_15, 0, 0, 1, 2);

        comboCurrency = new QComboBox(frameCurrency);
        comboCurrency->setObjectName(QString::fromUtf8("comboCurrency"));

        gridLayout_3->addWidget(comboCurrency, 1, 0, 1, 2);

        label_12 = new QLabel(frameCurrency);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_3->addWidget(label_12, 2, 0, 1, 1);

        editConvFactor = new QLineEdit(frameCurrency);
        editConvFactor->setObjectName(QString::fromUtf8("editConvFactor"));
        editConvFactor->setReadOnly(true);

        gridLayout_3->addWidget(editConvFactor, 2, 1, 1, 1);

        label_13 = new QLabel(frameCurrency);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 3, 0, 1, 1);

        editConvQty = new QLineEdit(frameCurrency);
        editConvQty->setObjectName(QString::fromUtf8("editConvQty"));

        gridLayout_3->addWidget(editConvQty, 3, 1, 1, 1);

        label_14 = new QLabel(frameCurrency);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 4, 0, 1, 1);

        editConvResult = new QLineEdit(frameCurrency);
        editConvResult->setObjectName(QString::fromUtf8("editConvResult"));
        editConvResult->setReadOnly(true);

        gridLayout_3->addWidget(editConvResult, 4, 1, 1, 1);

        btnConvCancel = new QPushButton(frameCurrency);
        btnConvCancel->setObjectName(QString::fromUtf8("btnConvCancel"));

        gridLayout_3->addWidget(btnConvCancel, 5, 0, 1, 1);

        btnConvOk = new QPushButton(frameCurrency);
        btnConvOk->setObjectName(QString::fromUtf8("btnConvOk"));

        gridLayout_3->addWidget(btnConvOk, 5, 1, 1, 1);

        discountWidget = new QWidget(page_Adds);
        discountWidget->setObjectName(QString::fromUtf8("discountWidget"));
        discountWidget->setGeometry(QRect(260, 10, 257, 171));
        sizePolicy8.setHeightForWidth(discountWidget->sizePolicy().hasHeightForWidth());
        discountWidget->setSizePolicy(sizePolicy8);
        verticalLayout_5 = new QVBoxLayout(discountWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lbl_discounts = new QLabel(discountWidget);
        lbl_discounts->setObjectName(QString::fromUtf8("lbl_discounts"));
        lbl_discounts->setWordWrap(true);

        verticalLayout_5->addWidget(lbl_discounts);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        rbPriceChange = new QRadioButton(discountWidget);
        rbPriceChange->setObjectName(QString::fromUtf8("rbPriceChange"));

        horizontalLayout_8->addWidget(rbPriceChange);

        rbPercentage = new QRadioButton(discountWidget);
        rbPercentage->setObjectName(QString::fromUtf8("rbPercentage"));
        rbPercentage->setChecked(true);

        horizontalLayout_8->addWidget(rbPercentage);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        editDiscount = new MibitLineEdit(discountWidget);
        editDiscount->setObjectName(QString::fromUtf8("editDiscount"));

        horizontalLayout_3->addWidget(editDiscount);

        btnApplyDiscount = new QPushButton(discountWidget);
        btnApplyDiscount->setObjectName(QString::fromUtf8("btnApplyDiscount"));

        horizontalLayout_3->addWidget(btnApplyDiscount);

        btnCancelDiscount = new QPushButton(discountWidget);
        btnCancelDiscount->setObjectName(QString::fromUtf8("btnCancelDiscount"));

        horizontalLayout_3->addWidget(btnCancelDiscount);


        verticalLayout_5->addLayout(horizontalLayout_3);

        rbCoupon = new QRadioButton(discountWidget);
        rbCoupon->setObjectName(QString::fromUtf8("rbCoupon"));

        verticalLayout_5->addWidget(rbCoupon);

        rbMoney = new QRadioButton(discountWidget);
        rbMoney->setObjectName(QString::fromUtf8("rbMoney"));

        verticalLayout_5->addWidget(rbMoney);

        resumeWidget = new QWidget(page_Adds);
        resumeWidget->setObjectName(QString::fromUtf8("resumeWidget"));
        resumeWidget->setGeometry(QRect(-110, 490, 580, 492));
        resumeWidget->setMinimumSize(QSize(580, 380));
        verticalLayout_7 = new QVBoxLayout(resumeWidget);
        verticalLayout_7->setSpacing(4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(4, 4, 4, 4);
        lblTitle = new QLabel(resumeWidget);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        lblTitle->setWordWrap(true);

        verticalLayout_7->addWidget(lblTitle);

        tableSuspendedSales = new QTableView(resumeWidget);
        tableSuspendedSales->setObjectName(QString::fromUtf8("tableSuspendedSales"));
        tableSuspendedSales->setMinimumSize(QSize(280, 0));
        tableSuspendedSales->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableSuspendedSales->setSelectionMode(QAbstractItemView::SingleSelection);
        tableSuspendedSales->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableSuspendedSales->setSortingEnabled(true);
        tableSuspendedSales->setCornerButtonEnabled(false);

        verticalLayout_7->addWidget(tableSuspendedSales);

        groupBox_2 = new QGroupBox(resumeWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 100));
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setSpacing(4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(4, 4, 4, 4);
        contentTable = new QTableWidget(groupBox_2);
        if (contentTable->columnCount() < 2)
            contentTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        contentTable->setHorizontalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        contentTable->setHorizontalHeaderItem(1, __qtablewidgetitem19);
        contentTable->setObjectName(QString::fromUtf8("contentTable"));

        verticalLayout_6->addWidget(contentTable);


        verticalLayout_7->addWidget(groupBox_2);

        creditWidget = new QWidget(page_Adds);
        creditWidget->setObjectName(QString::fromUtf8("creditWidget"));
        creditWidget->setGeometry(QRect(30, 210, 400, 440));
        sizePolicy.setHeightForWidth(creditWidget->sizePolicy().hasHeightForWidth());
        creditWidget->setSizePolicy(sizePolicy);
        creditWidget->setMinimumSize(QSize(400, 440));
        gridLayout_4 = new QGridLayout(creditWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        creditContent = new QTextEdit(creditWidget);
        creditContent->setObjectName(QString::fromUtf8("creditContent"));
        sizePolicy10.setHeightForWidth(creditContent->sizePolicy().hasHeightForWidth());
        creditContent->setSizePolicy(sizePolicy10);
        creditContent->setMinimumSize(QSize(160, 0));

        gridLayout_4->addWidget(creditContent, 0, 0, 4, 1);

        widget_2 = new QWidget(creditWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy17.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy17);
        verticalLayout_9 = new QVBoxLayout(widget_2);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_16 = new QLabel(widget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy16.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy16);

        verticalLayout_9->addWidget(label_16);

        editClientIdForCredit = new QLineEdit(widget_2);
        editClientIdForCredit->setObjectName(QString::fromUtf8("editClientIdForCredit"));
        sizePolicy15.setHeightForWidth(editClientIdForCredit->sizePolicy().hasHeightForWidth());
        editClientIdForCredit->setSizePolicy(sizePolicy15);
        editClientIdForCredit->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_9->addWidget(editClientIdForCredit);


        gridLayout_4->addWidget(widget_2, 0, 1, 1, 1);

        creditPaymentWidget = new QWidget(creditWidget);
        creditPaymentWidget->setObjectName(QString::fromUtf8("creditPaymentWidget"));
        QSizePolicy sizePolicy18(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy18.setHorizontalStretch(0);
        sizePolicy18.setVerticalStretch(0);
        sizePolicy18.setHeightForWidth(creditPaymentWidget->sizePolicy().hasHeightForWidth());
        creditPaymentWidget->setSizePolicy(sizePolicy18);
        creditPaymentWidget->setMinimumSize(QSize(0, 50));
        verticalLayout_8 = new QVBoxLayout(creditPaymentWidget);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_18 = new QLabel(creditPaymentWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy2.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy2);
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_18, 0, 0, 1, 1);

        editCreditTendered = new MibitLineEdit(creditPaymentWidget);
        editCreditTendered->setObjectName(QString::fromUtf8("editCreditTendered"));
        sizePolicy15.setHeightForWidth(editCreditTendered->sizePolicy().hasHeightForWidth());
        editCreditTendered->setSizePolicy(sizePolicy15);
        editCreditTendered->setMinimumSize(QSize(120, 0));
        editCreditTendered->setMaximumSize(QSize(200, 16777215));

        gridLayout_5->addWidget(editCreditTendered, 0, 1, 1, 1);

        label_19 = new QLabel(creditPaymentWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy16.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy16);
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_19, 1, 0, 1, 1);

        lblCreditChange = new QLabel(creditPaymentWidget);
        lblCreditChange->setObjectName(QString::fromUtf8("lblCreditChange"));
        sizePolicy16.setHeightForWidth(lblCreditChange->sizePolicy().hasHeightForWidth());
        lblCreditChange->setSizePolicy(sizePolicy16);
        lblCreditChange->setTextFormat(Qt::RichText);
        lblCreditChange->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblCreditChange->setMargin(0);

        gridLayout_5->addWidget(lblCreditChange, 1, 1, 1, 1);


        verticalLayout_8->addLayout(gridLayout_5);

        chKeepDebit = new QCheckBox(creditPaymentWidget);
        chKeepDebit->setObjectName(QString::fromUtf8("chKeepDebit"));
        QSizePolicy sizePolicy19(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy19.setHorizontalStretch(0);
        sizePolicy19.setVerticalStretch(0);
        sizePolicy19.setHeightForWidth(chKeepDebit->sizePolicy().hasHeightForWidth());
        chKeepDebit->setSizePolicy(sizePolicy19);

        verticalLayout_8->addWidget(chKeepDebit);


        gridLayout_4->addWidget(creditPaymentWidget, 1, 1, 1, 1);

        widget = new QWidget(creditWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy16.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy16);
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btnPayCredit = new QPushButton(widget);
        btnPayCredit->setObjectName(QString::fromUtf8("btnPayCredit"));
        sizePolicy19.setHeightForWidth(btnPayCredit->sizePolicy().hasHeightForWidth());
        btnPayCredit->setSizePolicy(sizePolicy19);

        horizontalLayout_5->addWidget(btnPayCredit);

        btnPrintCreditReport = new QPushButton(widget);
        btnPrintCreditReport->setObjectName(QString::fromUtf8("btnPrintCreditReport"));

        horizontalLayout_5->addWidget(btnPrintCreditReport);

        btnCancelCreditPayment = new QPushButton(widget);
        btnCancelCreditPayment->setObjectName(QString::fromUtf8("btnCancelCreditPayment"));
        sizePolicy19.setHeightForWidth(btnCancelCreditPayment->sizePolicy().hasHeightForWidth());
        btnCancelCreditPayment->setSizePolicy(sizePolicy19);

        horizontalLayout_5->addWidget(btnCancelCreditPayment);


        gridLayout_4->addWidget(widget, 3, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 2, 1, 1, 1);

        mainPanel->addWidget(page_Adds);
        splitter->addWidget(mainPanel);

        hboxLayout->addWidget(splitter);

#ifndef UI_QT_NO_SHORTCUT
        labelCashAmount->setBuddy(editAmount);
        labelCardNumber->setBuddy(editCardNumber);
#endif // QT_NO_SHORTCUT

        retranslateUi(mainview);

        groupWidgets->setCurrentIndex(2);
        stackedWidget_2->setCurrentIndex(1);
        mainPanel->setCurrentIndex(0);
        stackedWidget_3->setCurrentIndex(1);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainview);
    } // setupUi

    void retranslateUi(QWidget *mainview)
    {
        mainview->setWindowTitle(tr2i18n("Form", 0));
        rbFilterByPopularity->setText(tr2i18n("Best sellers", 0));
        rbFilterBySubCategory->setText(tr2i18n("Sub", 0));
#ifndef UI_QT_NO_TOOLTIP
        btnCurrency->setToolTip(tr2i18n("Currency conversion", 0));
#endif // QT_NO_TOOLTIP
        btnCurrency->setText(tr2i18n("$", 0));
        btnCurrency->setShortcut(tr2i18n("Ctrl+Alt+C", 0));
        groupDetails->setTitle(QString());
        labelDetailDesc->setText(tr2i18n("label", 0));
        labelDetailPrice->setText(tr2i18n("label", 0));
        labelDetailDiscount->setText(tr2i18n("label", 0));
        labelDetailPoints->setText(tr2i18n("label", 0));
        labelDetailUnits->setText(tr2i18n("label", 0));
        labelDetailTotalTaxes->setText(tr2i18n("label", 0));
        lblSubtotalPre->setText(tr2i18n("Subtotal:", 0));
        lblSubtotal->setText(QString());
        labelDetailTax1->setText(tr2i18n("label", 0));
        lblSaleTaxesPre->setText(tr2i18n("Taxes:", 0));
        lblSaleTaxes->setText(QString());
        groupPayment->setTitle(tr2i18n("Payment", 0));
        groupClient->setTitle(tr2i18n("Client", 0));
        labelDetailTax2->setText(tr2i18n("label", 0));
        labelTotalDiscountpre->setText(tr2i18n("Discount:", 0));
        labelTotalDiscount->setText(QString());
        groupSaleDate->setTitle(tr2i18n("Sale Date", 0));
        groupTotals->setTitle(QString());
        buttonSearchDone_2->setText(tr2i18n("Go back", 0));
        labelDetailPhoto->setText(QString());
        buttonSearchDone_3->setText(tr2i18n("Go back", 0));
        labelBanner->setText(QString());
        rbFilterByCategory->setText(tr2i18n("Category:", 0));
        rbFilterByDesc->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(tr2i18n("Qty", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(tr2i18n("Units", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(tr2i18n("Description", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(tr2i18n("Price", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(tr2i18n("Discount", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(tr2i18n("Total", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(tr2i18n("Code", 0));
        labelTotalpre->setText(tr2i18n("Total:", 0));
        labelTotal->setText(QString());
        label->setText(tr2i18n("Client:", 0));
        btnAddClient->setText(tr2i18n("+", 0));
        lblClientDetails->setText(QString());
        checkCash->setText(tr2i18n("Ca&sh", 0));
        labelCashAmount->setText(tr2i18n("$", 0));
        editAmount->setInputMask(QString());
        editAmount->setText(QString());
        checkCard->setText(tr2i18n("Ca&rd", 0));
        checkOwnCredit->setText(tr2i18n("&Internal Credit", 0));
        btnChangeSaleDate->setText(tr2i18n("Change Sale Date", 0));
        labelCardNumber->setText(tr2i18n("  #:", 0));
        editCardNumber->setInputMask(tr2i18n("0000-0000-0000-0000", 0));
        editCardNumber->setText(tr2i18n("---", 0));
        labelAuthNumber->setText(tr2i18n("Aut #:", 0));
        editCardAuthNumber->setText(tr2i18n("-", 0));
        labelChangepre->setText(tr2i18n("Change:", 0));
        labelChange->setText(QString());
        label_5->setText(tr2i18n("Enter item description:", 0));
        labelImageSearch->setText(tr2i18n("TextLabel", 0));
        buttonSearchDone->setText(tr2i18n("Go back", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableSearch->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(tr2i18n("Description", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableSearch->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(tr2i18n("Price", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableSearch->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(tr2i18n("Price with Tax", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableSearch->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(tr2i18n("Stock", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableSearch->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(tr2i18n("Alphacode", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableSearch->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(tr2i18n("Code", 0));
        labelSearchMsg->setText(tr2i18n("<html><head/><body><p><br/></p></body></html>", 0));
        label_2->setText(tr2i18n("Reprint Ticket", 0));
        lblTicketDatePicker->setText(tr2i18n("Show tickets before", 0));
        btnTicketPrint->setText(tr2i18n("Print selected ticket", 0));
        btnTicketDone->setText(tr2i18n("Back", 0));
        label_4->setText(tr2i18n("Return Products", 0));
        label_6->setText(tr2i18n("Ticket number:", 0));
        label_9->setText(tr2i18n("TextLabel", 0));
        label_7->setText(tr2i18n("Date and time:", 0));
        label_10->setText(tr2i18n("TextLabel", 0));
        label_8->setText(tr2i18n("Client:", 0));
        label_11->setText(tr2i18n("TextLabel", 0));
        label_3->setText(tr2i18n("Select the products to return", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableReturnProducts->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(tr2i18n("Code", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableReturnProducts->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(tr2i18n("Description", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableReturnProducts->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(tr2i18n("Qty on purchase", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableReturnProducts->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(tr2i18n("Price", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableReturnProducts->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(tr2i18n("Qty to return", 0));
        groupBox->setTitle(tr2i18n("Selected products details", 0));
        lblReturnProdQty->setText(tr2i18n("TextLabel", 0));
        label_15->setText(tr2i18n("Currency Conversion", 0));
        label_12->setText(tr2i18n("Factor:", 0));
        label_13->setText(tr2i18n("Quantity:", 0));
        label_14->setText(tr2i18n("Result", 0));
        btnConvCancel->setText(tr2i18n("Cancel", 0));
        btnConvOk->setText(tr2i18n("Ok", 0));
        lbl_discounts->setText(tr2i18n("Select how do you want to apply the discount:", 0));
        rbPriceChange->setText(tr2i18n("Change Price", 0));
        rbPercentage->setText(tr2i18n("By Percentage", 0));
        btnApplyDiscount->setText(tr2i18n("Apply", 0));
        btnCancelDiscount->setText(tr2i18n("Cancel", 0));
        rbCoupon->setText(tr2i18n("By coupon code", 0));
        rbMoney->setText(tr2i18n("By dollar and cents", 0));
        lblTitle->setText(tr2i18n("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The next sales are suspended. Please <span style=\" font-weight:600;\">select one to resume</span> and press the <span style=\" font-weight:600; font-style:italic;\">Ok</span> button; or press the <span style=\" font-weight:600; font-style:italic;\">cancel</span>  button to <span style=\" font-weight:600;\">start a new one</span>.</p></body></html>", 0));
        groupBox_2->setTitle(tr2i18n("Contents", 0));
        QTableWidgetItem *___qtablewidgetitem18 = contentTable->horizontalHeaderItem(0);
        ___qtablewidgetitem18->setText(tr2i18n("Qty", 0));
        QTableWidgetItem *___qtablewidgetitem19 = contentTable->horizontalHeaderItem(1);
        ___qtablewidgetitem19->setText(tr2i18n("Description", 0));
        label_16->setText(tr2i18n("Enter Client Id:", 0));
        label_18->setText(tr2i18n("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; font-style:italic; color:#0c8eff;\">Tendered:</span></p></body></html>", 0));
        label_19->setText(tr2i18n("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; font-style:italic; color:#0c8eff;\">Change:</span></p></body></html>", 0));
        lblCreditChange->setText(tr2i18n("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; font-style:italic; color:#0c8eff;\">0.0</span></p></body></html>", 0));
        chKeepDebit->setText(tr2i18n("Keep change as debit.", 0));
        btnPayCredit->setText(tr2i18n("Pay", 0));
        btnPrintCreditReport->setText(tr2i18n("Print", 0));
        btnCancelCreditPayment->setText(tr2i18n("Close", 0));
    } // retranslateUi

};

namespace Ui {
    class mainview: public Ui_mainview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINVIEW_H

