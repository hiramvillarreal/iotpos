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
    QRadioButton *kcfg_smallTicketCUPS;
    QRadioButton *kcfg_smallTicketDotMatrix;
    QHBoxLayout *horizontalLayout;
    QLabel *Printerdevice;
    QLineEdit *kcfg_printerDevice;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *kcfg_printerCodec;
    QRadioButton *kcfg_bigReceipt;
    QSpacerItem *verticalSpacer;
    QCheckBox *kcfg_printBalances;
    QCheckBox *kcfg_printChangedDateTicket;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *pref_printers)
    {
        if (pref_printers->objectName().isEmpty())
            pref_printers->setObjectName(QString::fromUtf8("pref_printers"));
        pref_printers->resize(512, 292);
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
        kcfg_smallTicketCUPS = new QRadioButton(kcfg_printTicket);
        kcfg_smallTicketCUPS->setObjectName(QString::fromUtf8("kcfg_smallTicketCUPS"));
        kcfg_smallTicketCUPS->setChecked(true);

        verticalLayout->addWidget(kcfg_smallTicketCUPS);

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

        spacerItem = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_2->addItem(spacerItem);


        retranslateUi(pref_printers);

        QMetaObject::connectSlotsByName(pref_printers);
    } // setupUi

    void retranslateUi(QWidget *pref_printers)
    {
        pref_printers->setWindowTitle(tr2i18n("Form", 0));
        kcfg_printTicket->setTitle(tr2i18n("Print the ticket as", 0));
        kcfg_smallTicketCUPS->setText(tr2i18n("Small receipt using a thermal ticket printer (using CUPS)", 0));
        kcfg_smallTicketDotMatrix->setText(tr2i18n("Small receipt using thermal  printer (using /dev/ttyAMA0)", 0));
        Printerdevice->setText(tr2i18n("Printer Device:", 0));
        label_2->setText(tr2i18n("Printer Codec:", 0));
        kcfg_bigReceipt->setText(tr2i18n("Big format [A4, Letter] receipt using normal printer (using CUPS)", 0));
        kcfg_printBalances->setText(tr2i18n("Print Balances on your selected printer (above).", 0));
        kcfg_printChangedDateTicket->setText(tr2i18n("Print Date Changed Tickets", 0));
    } // retranslateUi

};

namespace Ui {
    class pref_printers: public Ui_pref_printers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PREF_PRINTERS_H

