#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'pref_printers.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREF_PRINTERS_H
#define UI_PREF_PRINTERS_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pref_printers
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *kcfg_printTicket;
    QVBoxLayout *verticalLayout;
    QRadioButton *kcfg_smallTicketDotMatrix;
    QHBoxLayout *horizontalLayout;
    QLabel *Printerdevice;
    QLineEdit *kcfg_printerDevice;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *kcfg_printerCodec;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QCheckBox *kcfg_openDrawer;
    QCheckBox *kcfg_printZeroTicket;
    QRadioButton *kcfg_smallTicketCUPS;
    QRadioButton *kcfg_bigReceipt;
    QSpacerItem *verticalSpacer;
    QCheckBox *kcfg_printBalances;
    QCheckBox *kcfg_printChangedDateTicket;
    QCheckBox *kcfg_printSO;
    QCheckBox *kcfg_printPackContents;
    QCheckBox *kcfg_printRandomMsg;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *pref_printers)
    {
        if (pref_printers->objectName().isEmpty())
            pref_printers->setObjectName(QString::fromUtf8("pref_printers"));
        pref_printers->resize(532, 382);
        verticalLayout_2 = new QVBoxLayout(pref_printers);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        kcfg_printTicket = new QGroupBox(pref_printers);
        kcfg_printTicket->setObjectName(QString::fromUtf8("kcfg_printTicket"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(kcfg_printTicket->sizePolicy().hasHeightForWidth());
        kcfg_printTicket->setSizePolicy(sizePolicy);
        kcfg_printTicket->setMinimumSize(QSize(0, 80));
        kcfg_printTicket->setCheckable(true);
        kcfg_printTicket->setChecked(false);
        verticalLayout = new QVBoxLayout(kcfg_printTicket);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        kcfg_smallTicketDotMatrix = new QRadioButton(kcfg_printTicket);
        kcfg_smallTicketDotMatrix->setObjectName(QString::fromUtf8("kcfg_smallTicketDotMatrix"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(kcfg_smallTicketDotMatrix->sizePolicy().hasHeightForWidth());
        kcfg_smallTicketDotMatrix->setSizePolicy(sizePolicy1);
        kcfg_smallTicketDotMatrix->setChecked(false);

        verticalLayout->addWidget(kcfg_smallTicketDotMatrix);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(50, -1, -1, -1);
        Printerdevice = new QLabel(kcfg_printTicket);
        Printerdevice->setObjectName(QString::fromUtf8("Printerdevice"));

        horizontalLayout->addWidget(Printerdevice);

        kcfg_printerDevice = new QLineEdit(kcfg_printTicket);
        kcfg_printerDevice->setObjectName(QString::fromUtf8("kcfg_printerDevice"));

        horizontalLayout->addWidget(kcfg_printerDevice);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(50, -1, -1, -1);
        label_2 = new QLabel(kcfg_printTicket);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        kcfg_printerCodec = new QLineEdit(kcfg_printTicket);
        kcfg_printerCodec->setObjectName(QString::fromUtf8("kcfg_printerCodec"));

        horizontalLayout_2->addWidget(kcfg_printerCodec);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        kcfg_openDrawer = new QCheckBox(kcfg_printTicket);
        kcfg_openDrawer->setObjectName(QString::fromUtf8("kcfg_openDrawer"));

        horizontalLayout_3->addWidget(kcfg_openDrawer);


        verticalLayout->addLayout(horizontalLayout_3);

        kcfg_printZeroTicket = new QCheckBox(kcfg_printTicket);
        kcfg_printZeroTicket->setObjectName(QString::fromUtf8("kcfg_printZeroTicket"));

        verticalLayout->addWidget(kcfg_printZeroTicket);

        kcfg_smallTicketCUPS = new QRadioButton(kcfg_printTicket);
        kcfg_smallTicketCUPS->setObjectName(QString::fromUtf8("kcfg_smallTicketCUPS"));
        kcfg_smallTicketCUPS->setChecked(true);

        verticalLayout->addWidget(kcfg_smallTicketCUPS);

        kcfg_bigReceipt = new QRadioButton(kcfg_printTicket);
        kcfg_bigReceipt->setObjectName(QString::fromUtf8("kcfg_bigReceipt"));

        verticalLayout->addWidget(kcfg_bigReceipt);

        verticalSpacer = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout->addItem(verticalSpacer);

        kcfg_printBalances = new QCheckBox(kcfg_printTicket);
        kcfg_printBalances->setObjectName(QString::fromUtf8("kcfg_printBalances"));

        verticalLayout->addWidget(kcfg_printBalances);


        verticalLayout_2->addWidget(kcfg_printTicket);

        kcfg_printChangedDateTicket = new QCheckBox(pref_printers);
        kcfg_printChangedDateTicket->setObjectName(QString::fromUtf8("kcfg_printChangedDateTicket"));

        verticalLayout_2->addWidget(kcfg_printChangedDateTicket);

        kcfg_printSO = new QCheckBox(pref_printers);
        kcfg_printSO->setObjectName(QString::fromUtf8("kcfg_printSO"));

        verticalLayout_2->addWidget(kcfg_printSO);

        kcfg_printPackContents = new QCheckBox(pref_printers);
        kcfg_printPackContents->setObjectName(QString::fromUtf8("kcfg_printPackContents"));

        verticalLayout_2->addWidget(kcfg_printPackContents);

        kcfg_printRandomMsg = new QCheckBox(pref_printers);
        kcfg_printRandomMsg->setObjectName(QString::fromUtf8("kcfg_printRandomMsg"));

        verticalLayout_2->addWidget(kcfg_printRandomMsg);

        spacerItem = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_2->addItem(spacerItem);


        retranslateUi(pref_printers);

        QMetaObject::connectSlotsByName(pref_printers);
    } // setupUi

    void retranslateUi(QWidget *pref_printers)
    {
        pref_printers->setWindowTitle(tr2i18n("Form", 0));
        kcfg_printTicket->setTitle(tr2i18n("Print the ticket as", 0));
        kcfg_smallTicketDotMatrix->setText(tr2i18n("Small receipt using the thermal ticket printer (/dev/ttyAMA0)", 0));
        Printerdevice->setText(tr2i18n("Printer Device:", 0));
        label_2->setText(tr2i18n("Printer Codec:", 0));
        kcfg_openDrawer->setText(tr2i18n("Open drawer", 0));
        kcfg_printZeroTicket->setText(tr2i18n("Print  under demand (physical bottom).", 0));
        kcfg_smallTicketCUPS->setText(tr2i18n("Small receipt using a thermal ticket printer (using CUPS)", 0));
        kcfg_bigReceipt->setText(tr2i18n("Big format [A4, Letter] receipt using normal printer (using CUPS)", 0));
        kcfg_printBalances->setText(tr2i18n("Print Balances on your selected printer (above).", 0));
        kcfg_printChangedDateTicket->setText(tr2i18n("Print Date Changed Tickets", 0));
        kcfg_printSO->setText(tr2i18n("Print Special Orders", 0));
        kcfg_printPackContents->setText(tr2i18n("Print Group/Pack Contents on tickets.", 0));
        kcfg_printRandomMsg->setText(tr2i18n("Print a random message on tickets.", 0));
    } // retranslateUi

};

namespace Ui {
    class pref_printers: public Ui_pref_printers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PREF_PRINTERS_H

