#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'store_data.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STORE_DATA_H
#define UI_STORE_DATA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_store_data
{
public:
    QGridLayout *gridLayout;
    QLineEdit *kcfg_storePhone;
    QLabel *label_2;
    QLineEdit *kcfg_storeAddress;
    QLabel *label;
    QLineEdit *kcfg_editStoreName;
    QLabel *label_5;
    QLineEdit *kcfg_editTicketMessage;
    QLabel *label_3;
    QLineEdit *kcfg_storeLogo;
    QLabel *label_4;
    QCheckBox *kcfg_chLogoOnTop;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *store_data)
    {
        if (store_data->objectName().isEmpty())
            store_data->setObjectName(QString::fromUtf8("store_data"));
        store_data->resize(495, 289);
        gridLayout = new QGridLayout(store_data);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        kcfg_storePhone = new QLineEdit(store_data);
        kcfg_storePhone->setObjectName(QString::fromUtf8("kcfg_storePhone"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(kcfg_storePhone->sizePolicy().hasHeightForWidth());
        kcfg_storePhone->setSizePolicy(sizePolicy);
        kcfg_storePhone->setMinimumSize(QSize(300, 0));
        kcfg_storePhone->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(kcfg_storePhone, 2, 1, 1, 1);

        label_2 = new QLabel(store_data);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        kcfg_storeAddress = new QLineEdit(store_data);
        kcfg_storeAddress->setObjectName(QString::fromUtf8("kcfg_storeAddress"));
        sizePolicy.setHeightForWidth(kcfg_storeAddress->sizePolicy().hasHeightForWidth());
        kcfg_storeAddress->setSizePolicy(sizePolicy);
        kcfg_storeAddress->setMinimumSize(QSize(300, 0));
        kcfg_storeAddress->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(kcfg_storeAddress, 1, 1, 1, 1);

        label = new QLabel(store_data);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 0));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        kcfg_editStoreName = new QLineEdit(store_data);
        kcfg_editStoreName->setObjectName(QString::fromUtf8("kcfg_editStoreName"));
        sizePolicy.setHeightForWidth(kcfg_editStoreName->sizePolicy().hasHeightForWidth());
        kcfg_editStoreName->setSizePolicy(sizePolicy);
        kcfg_editStoreName->setMinimumSize(QSize(300, 0));
        kcfg_editStoreName->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(kcfg_editStoreName, 0, 1, 1, 1);

        label_5 = new QLabel(store_data);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(0, 0));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        kcfg_editTicketMessage = new QLineEdit(store_data);
        kcfg_editTicketMessage->setObjectName(QString::fromUtf8("kcfg_editTicketMessage"));
        sizePolicy.setHeightForWidth(kcfg_editTicketMessage->sizePolicy().hasHeightForWidth());
        kcfg_editTicketMessage->setSizePolicy(sizePolicy);
        kcfg_editTicketMessage->setMinimumSize(QSize(300, 0));
        kcfg_editTicketMessage->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(kcfg_editTicketMessage, 3, 1, 1, 1);

        label_3 = new QLabel(store_data);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(0, 0));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        kcfg_storeLogo = new QLineEdit(store_data);
        kcfg_storeLogo->setObjectName(QString::fromUtf8("kcfg_storeLogo"));
        sizePolicy.setHeightForWidth(kcfg_storeLogo->sizePolicy().hasHeightForWidth());
        kcfg_storeLogo->setSizePolicy(sizePolicy);
        kcfg_storeLogo->setMinimumSize(QSize(300, 0));
        kcfg_storeLogo->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(kcfg_storeLogo, 4, 1, 1, 1);

        label_4 = new QLabel(store_data);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(0, 0));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        kcfg_chLogoOnTop = new QCheckBox(store_data);
        kcfg_chLogoOnTop->setObjectName(QString::fromUtf8("kcfg_chLogoOnTop"));

        gridLayout->addWidget(kcfg_chLogoOnTop, 5, 1, 1, 1);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 6, 1, 1, 1);

#ifndef UI_QT_NO_SHORTCUT
        label_2->setBuddy(kcfg_storeAddress);
        label->setBuddy(kcfg_editStoreName);
        label_5->setBuddy(kcfg_storeLogo);
        label_3->setBuddy(kcfg_storePhone);
        label_4->setBuddy(kcfg_editTicketMessage);
#endif // QT_NO_SHORTCUT

        retranslateUi(store_data);

        QMetaObject::connectSlotsByName(store_data);
    } // setupUi

    void retranslateUi(QWidget *store_data)
    {
        store_data->setWindowTitle(tr2i18n("Form", 0));
        label_2->setText(tr2i18n("&Address:", 0));
        label->setText(tr2i18n("&Name:", 0));
        label_5->setText(tr2i18n("Store Logo:", 0));
        label_3->setText(tr2i18n("&Phone:", 0));
        label_4->setText(tr2i18n("Ticket &Message:", 0));
        kcfg_chLogoOnTop->setText(tr2i18n("Print Logo on ticket top, otherwise at the right", 0));
    } // retranslateUi

};

namespace Ui {
    class store_data: public Ui_store_data {};
} // namespace Ui

QT_END_NAMESPACE

#endif // STORE_DATA_H

