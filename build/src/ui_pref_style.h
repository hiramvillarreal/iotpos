#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'pref_style.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREF_STYLE_H
#define UI_PREF_STYLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pref_style
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *kcfg_useStyle;
    QVBoxLayout *vboxLayout1;
    QListWidget *styleList;
    QLineEdit *kcfg_styleName;
    QLabel *labelPreview;

    void setupUi(QWidget *pref_style)
    {
        if (pref_style->objectName().isEmpty())
            pref_style->setObjectName(QString::fromUtf8("pref_style"));
        pref_style->resize(369, 354);
        vboxLayout = new QVBoxLayout(pref_style);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        kcfg_useStyle = new QGroupBox(pref_style);
        kcfg_useStyle->setObjectName(QString::fromUtf8("kcfg_useStyle"));
        kcfg_useStyle->setCheckable(true);
        vboxLayout1 = new QVBoxLayout(kcfg_useStyle);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        styleList = new QListWidget(kcfg_useStyle);
        styleList->setObjectName(QString::fromUtf8("styleList"));

        vboxLayout1->addWidget(styleList);

        kcfg_styleName = new QLineEdit(kcfg_useStyle);
        kcfg_styleName->setObjectName(QString::fromUtf8("kcfg_styleName"));
        kcfg_styleName->setReadOnly(true);

        vboxLayout1->addWidget(kcfg_styleName);

        labelPreview = new QLabel(kcfg_useStyle);
        labelPreview->setObjectName(QString::fromUtf8("labelPreview"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelPreview->sizePolicy().hasHeightForWidth());
        labelPreview->setSizePolicy(sizePolicy);

        vboxLayout1->addWidget(labelPreview);


        vboxLayout->addWidget(kcfg_useStyle);


        retranslateUi(pref_style);

        QMetaObject::connectSlotsByName(pref_style);
    } // setupUi

    void retranslateUi(QWidget *pref_style)
    {
        pref_style->setWindowTitle(tr2i18n("Form", 0));
        kcfg_useStyle->setTitle(tr2i18n("Use style sheet", 0));
        labelPreview->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pref_style: public Ui_pref_style {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PREF_STYLE_H

