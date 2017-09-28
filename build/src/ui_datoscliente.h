#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'datoscliente.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATOSCLIENTE_H
#define UI_DATOSCLIENTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_datosCliente
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *editNombre;
    QLabel *label_6;
    QLineEdit *editRFC;
    QLabel *label_2;
    QTextEdit *editDireccion;

    void setupUi(QWidget *datosCliente)
    {
        if (datosCliente->objectName().isEmpty())
            datosCliente->setObjectName(QString::fromUtf8("datosCliente"));
        datosCliente->resize(395, 162);
        gridLayout = new QGridLayout(datosCliente);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(datosCliente);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 0));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        editNombre = new QLineEdit(datosCliente);
        editNombre->setObjectName(QString::fromUtf8("editNombre"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(editNombre->sizePolicy().hasHeightForWidth());
        editNombre->setSizePolicy(sizePolicy1);
        editNombre->setMinimumSize(QSize(300, 0));
        editNombre->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(editNombre, 0, 1, 1, 1);

        label_6 = new QLabel(datosCliente);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        editRFC = new QLineEdit(datosCliente);
        editRFC->setObjectName(QString::fromUtf8("editRFC"));
        editRFC->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(editRFC, 1, 1, 1, 1);

        label_2 = new QLabel(datosCliente);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        editDireccion = new QTextEdit(datosCliente);
        editDireccion->setObjectName(QString::fromUtf8("editDireccion"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(editDireccion->sizePolicy().hasHeightForWidth());
        editDireccion->setSizePolicy(sizePolicy2);
        editDireccion->setMaximumSize(QSize(16777215, 100));
        editDireccion->setTabChangesFocus(true);

        gridLayout->addWidget(editDireccion, 2, 1, 1, 1);

#ifndef UI_QT_NO_SHORTCUT
        label->setBuddy(editNombre);
#endif // QT_NO_SHORTCUT

        retranslateUi(datosCliente);

        QMetaObject::connectSlotsByName(datosCliente);
    } // setupUi

    void retranslateUi(QWidget *datosCliente)
    {
        datosCliente->setWindowTitle(tr2i18n("Form", 0));
        label->setText(tr2i18n("&Nombre:", 0));
        label_6->setText(tr2i18n("RFC:", 0));
        label_2->setText(tr2i18n("Direcci\303\263n:", 0));
    } // retranslateUi

};

namespace Ui {
    class datosCliente: public Ui_datosCliente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DATOSCLIENTE_H

