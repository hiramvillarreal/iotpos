#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'editpromo_widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPROMO_WIDGET_H
#define UI_EDITPROMO_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "kdatepicker.h"

QT_BEGIN_NAMESPACE

class Ui_promoEditor
{
public:
    QGridLayout *gridLayout;
    QLabel *label9;
    QGridLayout *gridLayout1;
    QListView *productsList;
    QRadioButton *chByName;
    QLineEdit *editName;
    QRadioButton *chByCat;
    QComboBox *comboCategory;
    QLabel *label_9;
    QDoubleSpinBox *spinboxDiscount;
    QLabel *label;
    QGroupBox *groupValidDate_2;
    QVBoxLayout *vboxLayout;
    KDatePicker *offersDatepickerStart;
    QGroupBox *groupValidDate;
    QVBoxLayout *vboxLayout1;
    KDatePicker *offersDatepickerEnd;
    QDoubleSpinBox *spinboxPrice;

    void setupUi(QWidget *promoEditor)
    {
        if (promoEditor->objectName().isEmpty())
            promoEditor->setObjectName(QString::fromUtf8("promoEditor"));
        promoEditor->resize(541, 290);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(promoEditor->sizePolicy().hasHeightForWidth());
        promoEditor->setSizePolicy(sizePolicy);
        promoEditor->setMinimumSize(QSize(532, 290));
        gridLayout = new QGridLayout(promoEditor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label9 = new QLabel(promoEditor);
        label9->setObjectName(QString::fromUtf8("label9"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label9->sizePolicy().hasHeightForWidth());
        label9->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label9, 0, 0, 1, 1);

        gridLayout1 = new QGridLayout();
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        productsList = new QListView(promoEditor);
        productsList->setObjectName(QString::fromUtf8("productsList"));

        gridLayout1->addWidget(productsList, 0, 0, 4, 1);

        chByName = new QRadioButton(promoEditor);
        chByName->setObjectName(QString::fromUtf8("chByName"));
        chByName->setChecked(true);

        gridLayout1->addWidget(chByName, 0, 1, 1, 1);

        editName = new QLineEdit(promoEditor);
        editName->setObjectName(QString::fromUtf8("editName"));

        gridLayout1->addWidget(editName, 1, 1, 1, 2);

        chByCat = new QRadioButton(promoEditor);
        chByCat->setObjectName(QString::fromUtf8("chByCat"));

        gridLayout1->addWidget(chByCat, 2, 1, 1, 2);

        comboCategory = new QComboBox(promoEditor);
        comboCategory->setObjectName(QString::fromUtf8("comboCategory"));

        gridLayout1->addWidget(comboCategory, 3, 1, 1, 2);


        gridLayout->addLayout(gridLayout1, 1, 0, 1, 5);

        label_9 = new QLabel(promoEditor);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        spinboxDiscount = new QDoubleSpinBox(promoEditor);
        spinboxDiscount->setObjectName(QString::fromUtf8("spinboxDiscount"));

        gridLayout->addWidget(spinboxDiscount, 2, 1, 1, 1);

        label = new QLabel(promoEditor);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 2, 1, 1);

        groupValidDate_2 = new QGroupBox(promoEditor);
        groupValidDate_2->setObjectName(QString::fromUtf8("groupValidDate_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupValidDate_2->sizePolicy().hasHeightForWidth());
        groupValidDate_2->setSizePolicy(sizePolicy2);
        groupValidDate_2->setMinimumSize(QSize(120, 0));
        vboxLayout = new QVBoxLayout(groupValidDate_2);
        vboxLayout->setSpacing(2);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(4, 4, 4, 4);
        offersDatepickerStart = new KDatePicker(groupValidDate_2);
        offersDatepickerStart->setObjectName(QString::fromUtf8("offersDatepickerStart"));

        vboxLayout->addWidget(offersDatepickerStart);


        gridLayout->addWidget(groupValidDate_2, 3, 0, 1, 2);

        groupValidDate = new QGroupBox(promoEditor);
        groupValidDate->setObjectName(QString::fromUtf8("groupValidDate"));
        sizePolicy2.setHeightForWidth(groupValidDate->sizePolicy().hasHeightForWidth());
        groupValidDate->setSizePolicy(sizePolicy2);
        groupValidDate->setMinimumSize(QSize(150, 0));
        vboxLayout1 = new QVBoxLayout(groupValidDate);
        vboxLayout1->setSpacing(2);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        vboxLayout1->setContentsMargins(4, 4, 4, 4);
        offersDatepickerEnd = new KDatePicker(groupValidDate);
        offersDatepickerEnd->setObjectName(QString::fromUtf8("offersDatepickerEnd"));

        vboxLayout1->addWidget(offersDatepickerEnd);


        gridLayout->addWidget(groupValidDate, 3, 2, 1, 3);

        spinboxPrice = new QDoubleSpinBox(promoEditor);
        spinboxPrice->setObjectName(QString::fromUtf8("spinboxPrice"));
        spinboxPrice->setMaximum(1e+06);
        spinboxPrice->setSingleStep(0.1);

        gridLayout->addWidget(spinboxPrice, 2, 3, 1, 2);

#ifndef UI_QT_NO_SHORTCUT
        label_9->setBuddy(spinboxDiscount);
#endif // QT_NO_SHORTCUT

        retranslateUi(promoEditor);

        QMetaObject::connectSlotsByName(promoEditor);
    } // setupUi

    void retranslateUi(QWidget *promoEditor)
    {
        promoEditor->setWindowTitle(tr2i18n("Form", 0));
        label9->setText(tr2i18n("Discount for product:", 0));
        chByName->setText(tr2i18n("Filter by name", 0));
        chByCat->setText(tr2i18n("Filter by category", 0));
        label_9->setText(tr2i18n("Discount percentage:", 0));
        label->setText(tr2i18n("New product price:", 0));
        groupValidDate_2->setTitle(tr2i18n("Valid From", 0));
        groupValidDate->setTitle(tr2i18n("Valid Until", 0));
    } // retranslateUi

};

namespace Ui {
    class promoEditor: public Ui_promoEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EDITPROMO_WIDGET_H

