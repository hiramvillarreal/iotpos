#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'checker.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKER_H
#define UI_CHECKER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_priceChecker
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *titleTop;
    QLabel *titleBottom;
    QLabel *titleImg;
    QGridLayout *gridLayout_2;
    QLabel *labelPCName;
    QLabel *labelPhoto;
    QGridLayout *gridLayout;
    QLabel *labelPClPrice;
    QLabel *labelPCPrice;
    QLabel *labelPClDiscount;
    QLabel *labelPCDiscount;
    QLabel *labelPClTotal;
    QLabel *labelPCTotal;
    QHBoxLayout *hboxLayout;
    QLabel *labelPCCode;
    QLineEdit *editCode;
    QLabel *labelPCClose;

    void setupUi(QWidget *priceChecker)
    {
        if (priceChecker->objectName().isEmpty())
            priceChecker->setObjectName(QString::fromUtf8("priceChecker"));
        priceChecker->resize(500, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(priceChecker->sizePolicy().hasHeightForWidth());
        priceChecker->setSizePolicy(sizePolicy);
        priceChecker->setMinimumSize(QSize(500, 300));
        priceChecker->setMaximumSize(QSize(504, 301));
        verticalLayout_2 = new QVBoxLayout(priceChecker);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(8, -1, -1, 8);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleTop = new QLabel(priceChecker);
        titleTop->setObjectName(QString::fromUtf8("titleTop"));
        titleTop->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(titleTop);

        titleBottom = new QLabel(priceChecker);
        titleBottom->setObjectName(QString::fromUtf8("titleBottom"));
        titleBottom->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(titleBottom);


        horizontalLayout->addLayout(verticalLayout);

        titleImg = new QLabel(priceChecker);
        titleImg->setObjectName(QString::fromUtf8("titleImg"));
        titleImg->setMinimumSize(QSize(96, 96));
        titleImg->setMaximumSize(QSize(96, 96));

        horizontalLayout->addWidget(titleImg);


        verticalLayout_2->addLayout(horizontalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(8, 8, 0, -1);
        labelPCName = new QLabel(priceChecker);
        labelPCName->setObjectName(QString::fromUtf8("labelPCName"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelPCName->sizePolicy().hasHeightForWidth());
        labelPCName->setSizePolicy(sizePolicy1);
        labelPCName->setMinimumSize(QSize(0, 30));
        labelPCName->setIndent(0);

        gridLayout_2->addWidget(labelPCName, 0, 0, 1, 1);

        labelPhoto = new QLabel(priceChecker);
        labelPhoto->setObjectName(QString::fromUtf8("labelPhoto"));
        labelPhoto->setMinimumSize(QSize(128, 128));
        labelPhoto->setMaximumSize(QSize(128, 128));
        labelPhoto->setFrameShape(QFrame::NoFrame);
        labelPhoto->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelPhoto, 0, 1, 2, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelPClPrice = new QLabel(priceChecker);
        labelPClPrice->setObjectName(QString::fromUtf8("labelPClPrice"));
        labelPClPrice->setMaximumSize(QSize(16777215, 22));
        labelPClPrice->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelPClPrice, 0, 0, 1, 1);

        labelPCPrice = new QLabel(priceChecker);
        labelPCPrice->setObjectName(QString::fromUtf8("labelPCPrice"));
        labelPCPrice->setIndent(20);

        gridLayout->addWidget(labelPCPrice, 0, 1, 1, 1);

        labelPClDiscount = new QLabel(priceChecker);
        labelPClDiscount->setObjectName(QString::fromUtf8("labelPClDiscount"));
        labelPClDiscount->setMaximumSize(QSize(16777215, 22));
        labelPClDiscount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelPClDiscount, 1, 0, 1, 1);

        labelPCDiscount = new QLabel(priceChecker);
        labelPCDiscount->setObjectName(QString::fromUtf8("labelPCDiscount"));
        labelPCDiscount->setIndent(15);

        gridLayout->addWidget(labelPCDiscount, 1, 1, 1, 1);

        labelPClTotal = new QLabel(priceChecker);
        labelPClTotal->setObjectName(QString::fromUtf8("labelPClTotal"));
        labelPClTotal->setMaximumSize(QSize(16777215, 22));
        labelPClTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelPClTotal, 2, 0, 1, 1);

        labelPCTotal = new QLabel(priceChecker);
        labelPCTotal->setObjectName(QString::fromUtf8("labelPCTotal"));
        labelPCTotal->setIndent(20);

        gridLayout->addWidget(labelPCTotal, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(4, -1, 4, -1);
        labelPCCode = new QLabel(priceChecker);
        labelPCCode->setObjectName(QString::fromUtf8("labelPCCode"));

        hboxLayout->addWidget(labelPCCode);

        editCode = new QLineEdit(priceChecker);
        editCode->setObjectName(QString::fromUtf8("editCode"));

        hboxLayout->addWidget(editCode);


        verticalLayout_2->addLayout(hboxLayout);

        labelPCClose = new QLabel(priceChecker);
        labelPCClose->setObjectName(QString::fromUtf8("labelPCClose"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelPCClose->sizePolicy().hasHeightForWidth());
        labelPCClose->setSizePolicy(sizePolicy2);
        labelPCClose->setMaximumSize(QSize(16777215, 20));
        labelPCClose->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelPCClose);

#ifndef UI_QT_NO_SHORTCUT
        labelPCCode->setBuddy(editCode);
#endif // QT_NO_SHORTCUT

        retranslateUi(priceChecker);

        QMetaObject::connectSlotsByName(priceChecker);
    } // setupUi

    void retranslateUi(QWidget *priceChecker)
    {
        priceChecker->setWindowTitle(tr2i18n("Form", 0));
        titleTop->setText(QString());
        titleBottom->setText(QString());
        titleImg->setText(QString());
        labelPCName->setText(QString());
        labelPhoto->setText(QString());
        labelPClPrice->setText(QString());
        labelPCPrice->setText(QString());
        labelPClDiscount->setText(QString());
        labelPCDiscount->setText(QString());
        labelPClTotal->setText(QString());
        labelPCTotal->setText(QString());
        labelPCCode->setText(QString());
        labelPCClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class priceChecker: public Ui_priceChecker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CHECKER_H

