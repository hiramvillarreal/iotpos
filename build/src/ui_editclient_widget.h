#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'editclient_widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCLIENT_WIDGET_H
#define UI_EDITCLIENT_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>
#include "../../mibitWidgets/mibitlineedit.h"
#include "kdatewidget.h"

QT_BEGIN_NAMESPACE

class Ui_clientEditor
{
public:
    QGridLayout *gridLayout;
    QLabel *label_14;
    QLabel *labelClientPhoto;
    MibitLineEdit *editClientName;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    MibitLineEdit *editClientPhone;
    MibitLineEdit *editClientMail;
    QPushButton *btnChangeClientPhoto;
    QLabel *label;
    QLabel *label_2;
    MibitLineEdit *editClientPoints;
    MibitLineEdit *editClientDiscount;
    QLabel *label_3;
    KDateWidget *sinceDatePicker;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    MibitLineEdit *editClientCode;
    QLabel *label_4;
    QTextEdit *editClientAddress;

    void setupUi(QWidget *clientEditor)
    {
        if (clientEditor->objectName().isEmpty())
            clientEditor->setObjectName(QString::fromUtf8("clientEditor"));
        clientEditor->resize(380, 314);
        gridLayout = new QGridLayout(clientEditor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_14 = new QLabel(clientEditor);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 0, 0, 1, 1);

        labelClientPhoto = new QLabel(clientEditor);
        labelClientPhoto->setObjectName(QString::fromUtf8("labelClientPhoto"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelClientPhoto->sizePolicy().hasHeightForWidth());
        labelClientPhoto->setSizePolicy(sizePolicy);
        labelClientPhoto->setMinimumSize(QSize(128, 128));
        labelClientPhoto->setFrameShape(QFrame::StyledPanel);
        labelClientPhoto->setFrameShadow(QFrame::Sunken);
        labelClientPhoto->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelClientPhoto, 0, 2, 6, 1);

        editClientName = new MibitLineEdit(clientEditor);
        editClientName->setObjectName(QString::fromUtf8("editClientName"));

        gridLayout->addWidget(editClientName, 3, 0, 1, 2);

        label_16 = new QLabel(clientEditor);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 4, 0, 1, 1);

        label_17 = new QLabel(clientEditor);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 6, 0, 1, 1);

        label_18 = new QLabel(clientEditor);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout->addWidget(label_18, 6, 1, 1, 1);

        editClientPhone = new MibitLineEdit(clientEditor);
        editClientPhone->setObjectName(QString::fromUtf8("editClientPhone"));
        editClientPhone->setMinimumSize(QSize(94, 0));
        editClientPhone->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(editClientPhone, 7, 0, 1, 1);

        editClientMail = new MibitLineEdit(clientEditor);
        editClientMail->setObjectName(QString::fromUtf8("editClientMail"));
        editClientMail->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(editClientMail, 7, 1, 1, 1);

        btnChangeClientPhoto = new QPushButton(clientEditor);
        btnChangeClientPhoto->setObjectName(QString::fromUtf8("btnChangeClientPhoto"));

        gridLayout->addWidget(btnChangeClientPhoto, 7, 2, 1, 1);

        label = new QLabel(clientEditor);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 8, 0, 1, 1);

        label_2 = new QLabel(clientEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 8, 1, 1, 1);

        editClientPoints = new MibitLineEdit(clientEditor);
        editClientPoints->setObjectName(QString::fromUtf8("editClientPoints"));
        editClientPoints->setMinimumSize(QSize(94, 0));
        editClientPoints->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(editClientPoints, 9, 0, 1, 1);

        editClientDiscount = new MibitLineEdit(clientEditor);
        editClientDiscount->setObjectName(QString::fromUtf8("editClientDiscount"));
        editClientDiscount->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(editClientDiscount, 9, 1, 1, 1);

        label_3 = new QLabel(clientEditor);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 10, 0, 1, 1);

        sinceDatePicker = new KDateWidget(clientEditor);
        sinceDatePicker->setObjectName(QString::fromUtf8("sinceDatePicker"));

        gridLayout->addWidget(sinceDatePicker, 11, 0, 1, 2);

        line = new QFrame(clientEditor);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 12, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 13, 0, 1, 1);

        editClientCode = new MibitLineEdit(clientEditor);
        editClientCode->setObjectName(QString::fromUtf8("editClientCode"));

        gridLayout->addWidget(editClientCode, 1, 0, 1, 2);

        label_4 = new QLabel(clientEditor);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        editClientAddress = new QTextEdit(clientEditor);
        editClientAddress->setObjectName(QString::fromUtf8("editClientAddress"));
        editClientAddress->setMaximumSize(QSize(16777215, 60));
        editClientAddress->setTabChangesFocus(true);
        editClientAddress->setAcceptRichText(false);

        gridLayout->addWidget(editClientAddress, 5, 0, 1, 2);

#ifndef UI_QT_NO_SHORTCUT
        label_14->setBuddy(editClientCode);
        label_16->setBuddy(editClientAddress);
        label_17->setBuddy(editClientPhone);
        label_18->setBuddy(editClientMail);
        label_4->setBuddy(editClientName);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(editClientCode, editClientName);
        QWidget::setTabOrder(editClientName, editClientAddress);
        QWidget::setTabOrder(editClientAddress, editClientPhone);
        QWidget::setTabOrder(editClientPhone, editClientMail);
        QWidget::setTabOrder(editClientMail, editClientPoints);
        QWidget::setTabOrder(editClientPoints, editClientDiscount);
        QWidget::setTabOrder(editClientDiscount, sinceDatePicker);
        QWidget::setTabOrder(sinceDatePicker, btnChangeClientPhoto);

        retranslateUi(clientEditor);

        QMetaObject::connectSlotsByName(clientEditor);
    } // setupUi

    void retranslateUi(QWidget *clientEditor)
    {
        clientEditor->setWindowTitle(tr2i18n("Form", 0));
        label_14->setText(tr2i18n("&Code:", 0));
        labelClientPhoto->setText(QString());
        label_16->setText(tr2i18n("&Address:", 0));
        label_17->setText(tr2i18n("Phone", 0));
        label_18->setText(tr2i18n("E-mail", 0));
        btnChangeClientPhoto->setText(tr2i18n("Change &Photo", 0));
        label->setText(tr2i18n("Points:", 0));
        label_2->setText(tr2i18n("Discount:", 0));
        label_3->setText(tr2i18n("Since:", 0));
        label_4->setText(tr2i18n("&Name:", 0));
    } // retranslateUi

};

namespace Ui {
    class clientEditor: public Ui_clientEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EDITCLIENT_WIDGET_H

