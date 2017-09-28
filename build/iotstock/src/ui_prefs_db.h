#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'prefs_db.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFS_DB_H
#define UI_PREFS_DB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_prefs_db
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *kcfg_editDBServer;
    QLabel *label_2;
    QLineEdit *kcfg_editDBUsername;
    QLabel *label_3;
    QLineEdit *kcfg_editDBPassword;
    QLabel *label_4;
    QLineEdit *kcfg_editDBName;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *prefs_db)
    {
        if (prefs_db->objectName().isEmpty())
            prefs_db->setObjectName(QString::fromUtf8("prefs_db"));
        prefs_db->resize(323, 184);
        vboxLayout = new QVBoxLayout(prefs_db);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox = new QGroupBox(prefs_db);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        kcfg_editDBServer = new QLineEdit(groupBox);
        kcfg_editDBServer->setObjectName(QString::fromUtf8("kcfg_editDBServer"));

        gridLayout->addWidget(kcfg_editDBServer, 0, 1, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        kcfg_editDBUsername = new QLineEdit(groupBox);
        kcfg_editDBUsername->setObjectName(QString::fromUtf8("kcfg_editDBUsername"));

        gridLayout->addWidget(kcfg_editDBUsername, 1, 1, 1, 2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        kcfg_editDBPassword = new QLineEdit(groupBox);
        kcfg_editDBPassword->setObjectName(QString::fromUtf8("kcfg_editDBPassword"));
        kcfg_editDBPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(kcfg_editDBPassword, 2, 1, 1, 2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 3, 0, 1, 2);

        kcfg_editDBName = new QLineEdit(groupBox);
        kcfg_editDBName->setObjectName(QString::fromUtf8("kcfg_editDBName"));

        gridLayout->addWidget(kcfg_editDBName, 3, 2, 1, 1);


        vboxLayout->addWidget(groupBox);

        spacerItem = new QSpacerItem(305, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);

#ifndef UI_QT_NO_SHORTCUT
        label->setBuddy(kcfg_editDBServer);
        label_2->setBuddy(kcfg_editDBUsername);
        label_3->setBuddy(kcfg_editDBPassword);
        label_4->setBuddy(kcfg_editDBName);
#endif // QT_NO_SHORTCUT

        retranslateUi(prefs_db);

        QMetaObject::connectSlotsByName(prefs_db);
    } // setupUi

    void retranslateUi(QWidget *prefs_db)
    {
        prefs_db->setWindowTitle(tr2i18n("Form", 0));
        groupBox->setTitle(tr2i18n("Database", 0));
        label->setText(tr2i18n("&Server:", 0));
        label_2->setText(tr2i18n("&Username:", 0));
        label_3->setText(tr2i18n("&Password:", 0));
        kcfg_editDBPassword->setInputMask(QString());
        label_4->setText(tr2i18n("&Database Name:", 0));
    } // retranslateUi

};

namespace Ui {
    class prefs_db: public Ui_prefs_db {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PREFS_DB_H

