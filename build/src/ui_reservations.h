#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'reservations.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESERVATIONS_H
#define UI_RESERVATIONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reservationsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblTitle;
    QTableView *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancelReservation;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *contentTable;
    QFrame *confirmFrame;
    QVBoxLayout *verticalLayout_3;
    QLabel *msgPanel;
    QRadioButton *chReimbursement;
    QRadioButton *chNoReimbursement;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnYes;
    QPushButton *btnNo;

    void setupUi(QWidget *reservationsDialog)
    {
        if (reservationsDialog->objectName().isEmpty())
            reservationsDialog->setObjectName(QString::fromUtf8("reservationsDialog"));
        reservationsDialog->resize(335, 385);
        verticalLayout = new QVBoxLayout(reservationsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblTitle = new QLabel(reservationsDialog);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        lblTitle->setWordWrap(true);

        verticalLayout->addWidget(lblTitle);

        tableWidget = new QTableView(reservationsDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(280, 0));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);
        tableWidget->setCornerButtonEnabled(false);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCancelReservation = new QPushButton(reservationsDialog);
        btnCancelReservation->setObjectName(QString::fromUtf8("btnCancelReservation"));

        horizontalLayout->addWidget(btnCancelReservation);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(reservationsDialog);
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

        confirmFrame = new QFrame(reservationsDialog);
        confirmFrame->setObjectName(QString::fromUtf8("confirmFrame"));
        confirmFrame->setMinimumSize(QSize(0, 135));
        confirmFrame->setFrameShape(QFrame::NoFrame);
        confirmFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(confirmFrame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        msgPanel = new QLabel(confirmFrame);
        msgPanel->setObjectName(QString::fromUtf8("msgPanel"));
        msgPanel->setWordWrap(true);

        verticalLayout_3->addWidget(msgPanel);

        chReimbursement = new QRadioButton(confirmFrame);
        chReimbursement->setObjectName(QString::fromUtf8("chReimbursement"));

        verticalLayout_3->addWidget(chReimbursement);

        chNoReimbursement = new QRadioButton(confirmFrame);
        chNoReimbursement->setObjectName(QString::fromUtf8("chNoReimbursement"));
        chNoReimbursement->setChecked(true);

        verticalLayout_3->addWidget(chNoReimbursement);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnYes = new QPushButton(confirmFrame);
        btnYes->setObjectName(QString::fromUtf8("btnYes"));

        horizontalLayout_2->addWidget(btnYes);

        btnNo = new QPushButton(confirmFrame);
        btnNo->setObjectName(QString::fromUtf8("btnNo"));

        horizontalLayout_2->addWidget(btnNo);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(confirmFrame);


        retranslateUi(reservationsDialog);

        QMetaObject::connectSlotsByName(reservationsDialog);
    } // setupUi

    void retranslateUi(QWidget *reservationsDialog)
    {
        reservationsDialog->setWindowTitle(tr2i18n("Reservations", 0));
        lblTitle->setText(tr2i18n("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Lucida Grande'; font-size:8pt;\">The next sales are reserved. Please </span><span style=\" font-family:'Lucida Grande'; font-size:8pt; font-weight:600;\">select one to finish the sale</span><span style=\" font-family:'Lucida Grande'; font-size:8pt;\"> and press the </span><span style=\" font-family:'Lucida Grande'; font-size:8pt; font-weight:600; font-style:italic;\">Ok</span><span style=\" font-family:'Lucida Grande'; font-size:8pt;\"> button; or press the </span><span style=\" font-family:'Lucida Grande'; font-size:8pt; font-weight:600;"
                        " font-style:italic;\">Cancel Selected</span><span style=\" font-family:'Lucida Grande'; font-size:8pt;\">  button to </span><span style=\" font-family:'Lucida Grande'; font-size:8pt; font-weight:600;\">cancel the selected reservation</span><span style=\" font-family:'Lucida Grande'; font-size:8pt;\">.</span></p></body></html>", 0));
        btnCancelReservation->setText(tr2i18n("Cancel Selected", 0));
        groupBox->setTitle(tr2i18n("Contents", 0));
        QTableWidgetItem *___qtablewidgetitem = contentTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(tr2i18n("Qty", 0));
        QTableWidgetItem *___qtablewidgetitem1 = contentTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(tr2i18n("Description", 0));
        msgPanel->setText(tr2i18n("Are you sure to cancel the selected reservation?", 0));
        chReimbursement->setText(tr2i18n("Make a Reimbursement", 0));
        chNoReimbursement->setText(tr2i18n("DO NOT Make a Reimbursement", 0));
        btnYes->setText(tr2i18n("Yes", 0));
        btnNo->setText(tr2i18n("No", 0));
    } // retranslateUi

};

namespace Ui {
    class reservationsDialog: public Ui_reservationsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // RESERVATIONS_H

