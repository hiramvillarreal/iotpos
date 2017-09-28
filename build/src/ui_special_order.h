#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'special_order.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECIAL_ORDER_H
#define UI_SPECIAL_ORDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "../../mibitWidgets/mibitlineedit.h"
#include "kdatetimewidget.h"

QT_BEGIN_NAMESPACE

class Ui_specialOrderEditor
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget_2;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QLabel *lbl;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lblTransId;
    QLabel *lblStatus;
    QComboBox *usersCombo;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *clientsCombo;
    QToolButton *btnMoreClients;
    QPushButton *btnNewClient;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_8;
    QSpinBox *editQty;
    QSpacerItem *horizontalSpacer;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_4;
    KDateTimeWidget *deliveryDT;
    QLabel *lblDateError;
    QLabel *lblNotes;
    QTextEdit *editNotes;
    QLabel *lblNoteL;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QFrame *groupsPanel;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QListView *sourcePView;
    QSpacerItem *verticalSpacer;
    QTableWidget *groupView;
    QGridLayout *gridLayout_2;
    QLineEdit *editAddQty;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *btnAdd;
    QToolButton *btnRemove;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *editFilter;
    QPushButton *btnFilter;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblPayment;
    QDoubleSpinBox *editPayment;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lblPriceLabel;
    QLabel *lblPrice;
    QFrame *frameClient;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_4;
    MibitLineEdit *editClientName;
    QTextEdit *editClientAddress;
    MibitLineEdit *editClientPhone;
    MibitLineEdit *editClientMail;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnClientCancel;
    QPushButton *btnClientAdd;

    void setupUi(QWidget *specialOrderEditor)
    {
        if (specialOrderEditor->objectName().isEmpty())
            specialOrderEditor->setObjectName(QString::fromUtf8("specialOrderEditor"));
        specialOrderEditor->resize(490, 856);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(specialOrderEditor->sizePolicy().hasHeightForWidth());
        specialOrderEditor->setSizePolicy(sizePolicy);
        specialOrderEditor->setMinimumSize(QSize(490, 0));
        specialOrderEditor->setMaximumSize(QSize(550, 16777215));
        verticalLayout = new QVBoxLayout(specialOrderEditor);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget_2 = new QTabWidget(specialOrderEditor);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setTabPosition(QTabWidget::East);
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lbl = new QLabel(tab_2);
        lbl->setObjectName(QString::fromUtf8("lbl"));
        lbl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lbl, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lblTransId = new QLabel(tab_2);
        lblTransId->setObjectName(QString::fromUtf8("lblTransId"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblTransId->sizePolicy().hasHeightForWidth());
        lblTransId->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(lblTransId);

        lblStatus = new QLabel(tab_2);
        lblStatus->setObjectName(QString::fromUtf8("lblStatus"));
        lblStatus->setFrameShape(QFrame::StyledPanel);
        lblStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(lblStatus);

        usersCombo = new QComboBox(tab_2);
        usersCombo->setObjectName(QString::fromUtf8("usersCombo"));
        usersCombo->setMinimumSize(QSize(150, 0));

        horizontalLayout_7->addWidget(usersCombo);


        gridLayout->addLayout(horizontalLayout_7, 0, 1, 1, 1);

        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setLayoutDirection(Qt::LeftToRight);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_14, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        clientsCombo = new QComboBox(tab_2);
        clientsCombo->setObjectName(QString::fromUtf8("clientsCombo"));
        clientsCombo->setMinimumSize(QSize(230, 0));

        horizontalLayout_5->addWidget(clientsCombo);

        btnMoreClients = new QToolButton(tab_2);
        btnMoreClients->setObjectName(QString::fromUtf8("btnMoreClients"));

        horizontalLayout_5->addWidget(btnMoreClients);

        btnNewClient = new QPushButton(tab_2);
        btnNewClient->setObjectName(QString::fromUtf8("btnNewClient"));

        horizontalLayout_5->addWidget(btnNewClient);


        gridLayout->addLayout(horizontalLayout_5, 1, 1, 1, 1);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        editQty = new QSpinBox(tab_2);
        editQty->setObjectName(QString::fromUtf8("editQty"));
        editQty->setMinimumSize(QSize(50, 0));

        horizontalLayout_8->addWidget(editQty);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_8, 2, 1, 1, 1);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        deliveryDT = new KDateTimeWidget(tab_2);
        deliveryDT->setObjectName(QString::fromUtf8("deliveryDT"));

        horizontalLayout_4->addWidget(deliveryDT);

        lblDateError = new QLabel(tab_2);
        lblDateError->setObjectName(QString::fromUtf8("lblDateError"));

        horizontalLayout_4->addWidget(lblDateError);


        gridLayout->addLayout(horizontalLayout_4, 3, 1, 1, 1);

        lblNotes = new QLabel(tab_2);
        lblNotes->setObjectName(QString::fromUtf8("lblNotes"));

        gridLayout->addWidget(lblNotes, 4, 0, 1, 1);

        editNotes = new QTextEdit(tab_2);
        editNotes->setObjectName(QString::fromUtf8("editNotes"));
        editNotes->setMaximumSize(QSize(16777215, 60));
        editNotes->setTabChangesFocus(true);

        gridLayout->addWidget(editNotes, 5, 0, 1, 2);

        lblNoteL = new QLabel(tab_2);
        lblNoteL->setObjectName(QString::fromUtf8("lblNoteL"));
        lblNoteL->setStyleSheet(QString::fromUtf8("font-weight:bold;"));
        lblNoteL->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblNoteL, 4, 1, 1, 1);

        tabWidget_2->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget_2);

        tabWidget = new QTabWidget(specialOrderEditor);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupsPanel = new QFrame(tab);
        groupsPanel->setObjectName(QString::fromUtf8("groupsPanel"));
        gridLayout_3 = new QGridLayout(groupsPanel);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupsPanel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setWordWrap(true);

        horizontalLayout_2->addWidget(label_2);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 3);

        sourcePView = new QListView(groupsPanel);
        sourcePView->setObjectName(QString::fromUtf8("sourcePView"));
        sourcePView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        sourcePView->setAlternatingRowColors(false);
        sourcePView->setSelectionMode(QAbstractItemView::MultiSelection);
        sourcePView->setSelectionBehavior(QAbstractItemView::SelectRows);
        sourcePView->setModelColumn(0);

        gridLayout_3->addWidget(sourcePView, 1, 0, 3, 1);

        verticalSpacer = new QSpacerItem(78, 63, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 1, 1, 1);

        groupView = new QTableWidget(groupsPanel);
        if (groupView->columnCount() < 2)
            groupView->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        groupView->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        groupView->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        groupView->setObjectName(QString::fromUtf8("groupView"));
        groupView->setStyleSheet(QString::fromUtf8(""));
        groupView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        groupView->setSelectionMode(QAbstractItemView::SingleSelection);
        groupView->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout_3->addWidget(groupView, 1, 2, 4, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        editAddQty = new QLineEdit(groupsPanel);
        editAddQty->setObjectName(QString::fromUtf8("editAddQty"));
        editAddQty->setMinimumSize(QSize(50, 0));
        editAddQty->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(editAddQty, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        btnAdd = new QToolButton(groupsPanel);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setMinimumSize(QSize(30, 25));
        btnAdd->setMaximumSize(QSize(30, 25));
        btnAdd->setIconSize(QSize(0, 0));

        gridLayout_2->addWidget(btnAdd, 0, 1, 1, 1);

        btnRemove = new QToolButton(groupsPanel);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));
        btnRemove->setMinimumSize(QSize(30, 0));
        btnRemove->setMaximumSize(QSize(30, 16777215));

        gridLayout_2->addWidget(btnRemove, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(78, 63, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 3, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(groupsPanel);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        editFilter = new QLineEdit(groupsPanel);
        editFilter->setObjectName(QString::fromUtf8("editFilter"));

        horizontalLayout_6->addWidget(editFilter);

        btnFilter = new QPushButton(groupsPanel);
        btnFilter->setObjectName(QString::fromUtf8("btnFilter"));
        btnFilter->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_6->addWidget(btnFilter);


        gridLayout_3->addLayout(horizontalLayout_6, 4, 0, 1, 1);


        horizontalLayout->addWidget(groupsPanel);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        groupBox = new QGroupBox(specialOrderEditor);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(100, 0));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lblPayment = new QLabel(groupBox);
        lblPayment->setObjectName(QString::fromUtf8("lblPayment"));

        horizontalLayout_3->addWidget(lblPayment);

        editPayment = new QDoubleSpinBox(groupBox);
        editPayment->setObjectName(QString::fromUtf8("editPayment"));
        editPayment->setMinimumSize(QSize(125, 0));
        editPayment->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        editPayment->setMinimum(1);
        editPayment->setMaximum(1e+09);

        horizontalLayout_3->addWidget(editPayment);

        horizontalSpacer_3 = new QSpacerItem(150, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        lblPriceLabel = new QLabel(groupBox);
        lblPriceLabel->setObjectName(QString::fromUtf8("lblPriceLabel"));
        sizePolicy1.setHeightForWidth(lblPriceLabel->sizePolicy().hasHeightForWidth());
        lblPriceLabel->setSizePolicy(sizePolicy1);
        lblPriceLabel->setLayoutDirection(Qt::LeftToRight);
        lblPriceLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lblPriceLabel);

        lblPrice = new QLabel(groupBox);
        lblPrice->setObjectName(QString::fromUtf8("lblPrice"));

        horizontalLayout_3->addWidget(lblPrice);


        verticalLayout->addWidget(groupBox);

        frameClient = new QFrame(specialOrderEditor);
        frameClient->setObjectName(QString::fromUtf8("frameClient"));
        frameClient->setFrameShape(QFrame::StyledPanel);
        frameClient->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frameClient);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        editClientName = new MibitLineEdit(frameClient);
        editClientName->setObjectName(QString::fromUtf8("editClientName"));
        editClientName->setMinimumSize(QSize(300, 0));

        gridLayout_4->addWidget(editClientName, 0, 0, 1, 2);

        editClientAddress = new QTextEdit(frameClient);
        editClientAddress->setObjectName(QString::fromUtf8("editClientAddress"));
        editClientAddress->setMaximumSize(QSize(16777215, 60));
        editClientAddress->setTabChangesFocus(true);
        editClientAddress->setAcceptRichText(false);

        gridLayout_4->addWidget(editClientAddress, 1, 0, 1, 2);

        editClientPhone = new MibitLineEdit(frameClient);
        editClientPhone->setObjectName(QString::fromUtf8("editClientPhone"));
        editClientPhone->setMinimumSize(QSize(150, 0));
        editClientPhone->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(editClientPhone, 2, 0, 1, 1);

        editClientMail = new MibitLineEdit(frameClient);
        editClientMail->setObjectName(QString::fromUtf8("editClientMail"));
        editClientMail->setMinimumSize(QSize(150, 0));
        editClientMail->setMaximumSize(QSize(100, 16777215));

        gridLayout_4->addWidget(editClientMail, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        btnClientCancel = new QPushButton(frameClient);
        btnClientCancel->setObjectName(QString::fromUtf8("btnClientCancel"));

        horizontalLayout_9->addWidget(btnClientCancel);

        btnClientAdd = new QPushButton(frameClient);
        btnClientAdd->setObjectName(QString::fromUtf8("btnClientAdd"));

        horizontalLayout_9->addWidget(btnClientAdd);


        verticalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout->addWidget(frameClient);

#ifndef UI_QT_NO_SHORTCUT
        label_14->setBuddy(clientsCombo);
        label_4->setBuddy(editQty);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(editQty, editNotes);
        QWidget::setTabOrder(editNotes, sourcePView);
        QWidget::setTabOrder(sourcePView, editAddQty);
        QWidget::setTabOrder(editAddQty, btnAdd);
        QWidget::setTabOrder(btnAdd, btnRemove);
        QWidget::setTabOrder(btnRemove, groupView);
        QWidget::setTabOrder(groupView, editFilter);
        QWidget::setTabOrder(editFilter, btnFilter);
        QWidget::setTabOrder(btnFilter, editPayment);
        QWidget::setTabOrder(editPayment, tabWidget);
        QWidget::setTabOrder(tabWidget, usersCombo);
        QWidget::setTabOrder(usersCombo, tabWidget_2);

        retranslateUi(specialOrderEditor);

        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(specialOrderEditor);
    } // setupUi

    void retranslateUi(QWidget *specialOrderEditor)
    {
        specialOrderEditor->setWindowTitle(tr2i18n("Special Order", 0));
        lbl->setText(tr2i18n("Ticket :", 0));
        lblTransId->setText(tr2i18n("#", 0));
        lblStatus->setText(tr2i18n("Vendor:", 0));
        label_14->setText(tr2i18n("&Client:", 0));
#ifndef UI_QT_NO_TOOLTIP
        btnMoreClients->setToolTip(tr2i18n("launch a dialog with more options", 0));
#endif // QT_NO_TOOLTIP
        btnMoreClients->setText(tr2i18n("...", 0));
        btnNewClient->setText(tr2i18n("New Client", 0));
        label_4->setText(tr2i18n("&Qty:", 0));
        label_6->setText(tr2i18n("Delivery date:", 0));
        lblDateError->setText(QString());
        lblNotes->setText(tr2i18n("Notes:", 0));
        lblNoteL->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), tr2i18n("Special Item", 0));
        label_2->setText(tr2i18n("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic;\">Select</span> products from the left list and click the '&gt;' button to <span style=\" font-weight:600;\">add</span> them to the group on the right. You can<span style=\" font-style:italic;\"> </span><span style=\" font-weight:600; font-style:italic;\">increment</span><span style=\" font-weight:600;\"> </span>item quantities on the right table by <span style=\" font-weight:600;\">double clicking</span> on the item</p></body></html>", 0));
        QTableWidgetItem *___qtablewidgetitem = groupView->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(tr2i18n("Qty", 0));
        QTableWidgetItem *___qtablewidgetitem1 = groupView->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(tr2i18n("Description", 0));
#ifndef UI_QT_NO_TOOLTIP
        editAddQty->setToolTip(tr2i18n("Qty to add", 0));
#endif // QT_NO_TOOLTIP
#ifndef UI_QT_NO_TOOLTIP
        btnAdd->setToolTip(tr2i18n("Add selected products to the components", 0));
#endif // QT_NO_TOOLTIP
        btnAdd->setText(tr2i18n(">", 0));
#ifndef UI_QT_NO_TOOLTIP
        btnRemove->setToolTip(tr2i18n("Remove selected products from the components", 0));
#endif // QT_NO_TOOLTIP
        btnRemove->setText(tr2i18n("<", 0));
        label_3->setText(tr2i18n("Filter:", 0));
#ifndef UI_QT_NO_TOOLTIP
        editFilter->setToolTip(tr2i18n("You can filter the products by description,", 0));
#endif // QT_NO_TOOLTIP
        editFilter->setText(QString());
        btnFilter->setText(tr2i18n("...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), tr2i18n("Components", 0));
        groupBox->setTitle(tr2i18n("Price and Payment", 0));
        lblPayment->setText(tr2i18n("Payment:", 0));
        editPayment->setPrefix(QString());
        lblPriceLabel->setText(tr2i18n("Price:", 0));
        lblPrice->setText(tr2i18n("$", 0));
#ifndef UI_QT_NO_TOOLTIP
        editClientAddress->setToolTip(tr2i18n("Enter Client Address", 0));
#endif // QT_NO_TOOLTIP
        btnClientCancel->setText(tr2i18n("Cancel", 0));
        btnClientAdd->setText(tr2i18n("Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class specialOrderEditor: public Ui_specialOrderEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SPECIAL_ORDER_H

