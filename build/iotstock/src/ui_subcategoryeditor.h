#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'subcategoryeditor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBCATEGORYEDITOR_H
#define UI_SUBCATEGORYEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_subcategoryEditor
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblName;
    QLineEdit *editName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblChildText;
    QToolButton *btnAdd;
    QListWidget *listView;

    void setupUi(QWidget *subcategoryEditor)
    {
        if (subcategoryEditor->objectName().isEmpty())
            subcategoryEditor->setObjectName(QString::fromUtf8("subcategoryEditor"));
        subcategoryEditor->resize(402, 61);
        verticalLayout = new QVBoxLayout(subcategoryEditor);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lblName = new QLabel(subcategoryEditor);
        lblName->setObjectName(QString::fromUtf8("lblName"));

        horizontalLayout->addWidget(lblName);

        editName = new QLineEdit(subcategoryEditor);
        editName->setObjectName(QString::fromUtf8("editName"));

        horizontalLayout->addWidget(editName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lblChildText = new QLabel(subcategoryEditor);
        lblChildText->setObjectName(QString::fromUtf8("lblChildText"));
        lblChildText->setMaximumSize(QSize(16777215, 0));

        horizontalLayout_2->addWidget(lblChildText);

        btnAdd = new QToolButton(subcategoryEditor);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setMinimumSize(QSize(0, 0));
        btnAdd->setMaximumSize(QSize(16777215, 0));

        horizontalLayout_2->addWidget(btnAdd);


        verticalLayout->addLayout(horizontalLayout_2);

        listView = new QListWidget(subcategoryEditor);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setMaximumSize(QSize(16777215, 0));

        verticalLayout->addWidget(listView);

#ifndef UI_QT_NO_SHORTCUT
        lblName->setBuddy(editName);
#endif // QT_NO_SHORTCUT

        retranslateUi(subcategoryEditor);

        QMetaObject::connectSlotsByName(subcategoryEditor);
    } // setupUi

    void retranslateUi(QWidget *subcategoryEditor)
    {
        subcategoryEditor->setWindowTitle(tr2i18n("Editor", 0));
        lblName->setText(tr2i18n("label", 0));
        lblChildText->setText(tr2i18n("label", 0));
#ifndef UI_QT_NO_TOOLTIP
        btnAdd->setToolTip(tr2i18n("Add new", 0));
#endif // QT_NO_TOOLTIP
        btnAdd->setText(tr2i18n("+", 0));
    } // retranslateUi

};

namespace Ui {
    class subcategoryEditor: public Ui_subcategoryEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SUBCATEGORYEDITOR_H

