#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'pref_security.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREF_SECURITY_H
#define UI_PREF_SECURITY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pref_security
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *kcfg_allowAnyUserToQuit;
    QCheckBox *kcfg_lowSecurityMode;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *pref_security)
    {
        if (pref_security->objectName().isEmpty())
            pref_security->setObjectName(QString::fromUtf8("pref_security"));
        pref_security->resize(400, 300);
        verticalLayout = new QVBoxLayout(pref_security);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        kcfg_allowAnyUserToQuit = new QCheckBox(pref_security);
        kcfg_allowAnyUserToQuit->setObjectName(QString::fromUtf8("kcfg_allowAnyUserToQuit"));

        verticalLayout->addWidget(kcfg_allowAnyUserToQuit);

        kcfg_lowSecurityMode = new QCheckBox(pref_security);
        kcfg_lowSecurityMode->setObjectName(QString::fromUtf8("kcfg_lowSecurityMode"));

        verticalLayout->addWidget(kcfg_lowSecurityMode);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(spacerItem);


        retranslateUi(pref_security);

        QMetaObject::connectSlotsByName(pref_security);
    } // setupUi

    void retranslateUi(QWidget *pref_security)
    {
        pref_security->setWindowTitle(tr2i18n("Security", 0));
        kcfg_allowAnyUserToQuit->setText(tr2i18n("Allow any user to quit, asking for administrator's password", 0));
        kcfg_lowSecurityMode->setText(tr2i18n("Do not ask for admin password (Low Security Mode)", 0));
    } // retranslateUi

};

namespace Ui {
    class pref_security: public Ui_pref_security {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PREF_SECURITY_H

