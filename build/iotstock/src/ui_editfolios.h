#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading UI file 'editfolios.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITFOLIOS_H
#define UI_EDITFOLIOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "../../mibitWidgets/mibitlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_serieFoliosEditor
{
public:
    QGridLayout *gridLayout;
    QLabel *label_14;
    MibitLineEdit *editNumAprobacion;
    QVBoxLayout *verticalLayout;
    QLabel *label_18;
    QLabel *lblCbb;
    QPushButton *btnCambiarCbb;
    QLabel *label_4;
    QCalendarWidget *calendarWidget;
    QLabel *label_5;
    MibitLineEdit *editFolioInicial;
    QLabel *label_16;
    MibitLineEdit *editFolioFinal;
    QLabel *lblTotalFolios;

    void setupUi(QWidget *serieFoliosEditor)
    {
        if (serieFoliosEditor->objectName().isEmpty())
            serieFoliosEditor->setObjectName(QString::fromUtf8("serieFoliosEditor"));
        serieFoliosEditor->resize(458, 368);
        gridLayout = new QGridLayout(serieFoliosEditor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_14 = new QLabel(serieFoliosEditor);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 0, 0, 1, 2);

        editNumAprobacion = new MibitLineEdit(serieFoliosEditor);
        editNumAprobacion->setObjectName(QString::fromUtf8("editNumAprobacion"));

        gridLayout->addWidget(editNumAprobacion, 1, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_18 = new QLabel(serieFoliosEditor);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setWordWrap(true);

        verticalLayout->addWidget(label_18);

        lblCbb = new QLabel(serieFoliosEditor);
        lblCbb->setObjectName(QString::fromUtf8("lblCbb"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblCbb->sizePolicy().hasHeightForWidth());
        lblCbb->setSizePolicy(sizePolicy);
        lblCbb->setMinimumSize(QSize(128, 128));
        lblCbb->setFrameShape(QFrame::StyledPanel);
        lblCbb->setFrameShadow(QFrame::Sunken);
        lblCbb->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblCbb);

        btnCambiarCbb = new QPushButton(serieFoliosEditor);
        btnCambiarCbb->setObjectName(QString::fromUtf8("btnCambiarCbb"));

        verticalLayout->addWidget(btnCambiarCbb);


        gridLayout->addLayout(verticalLayout, 1, 2, 3, 1);

        label_4 = new QLabel(serieFoliosEditor);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 2);

        calendarWidget = new QCalendarWidget(serieFoliosEditor);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);

        gridLayout->addWidget(calendarWidget, 3, 0, 1, 2);

        label_5 = new QLabel(serieFoliosEditor);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        editFolioInicial = new MibitLineEdit(serieFoliosEditor);
        editFolioInicial->setObjectName(QString::fromUtf8("editFolioInicial"));

        gridLayout->addWidget(editFolioInicial, 4, 1, 1, 1);

        label_16 = new QLabel(serieFoliosEditor);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 5, 0, 1, 1);

        editFolioFinal = new MibitLineEdit(serieFoliosEditor);
        editFolioFinal->setObjectName(QString::fromUtf8("editFolioFinal"));

        gridLayout->addWidget(editFolioFinal, 5, 1, 1, 1);

        lblTotalFolios = new QLabel(serieFoliosEditor);
        lblTotalFolios->setObjectName(QString::fromUtf8("lblTotalFolios"));

        gridLayout->addWidget(lblTotalFolios, 5, 2, 1, 1);

#ifndef UI_QT_NO_SHORTCUT
        label_14->setBuddy(editNumAprobacion);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(editNumAprobacion, btnCambiarCbb);

        retranslateUi(serieFoliosEditor);

        QMetaObject::connectSlotsByName(serieFoliosEditor);
    } // setupUi

    void retranslateUi(QWidget *serieFoliosEditor)
    {
        serieFoliosEditor->setWindowTitle(tr2i18n("Form", 0));
        label_14->setText(tr2i18n("&N\303\272m de Aprobaci\303\263n:", 0));
        label_18->setText(tr2i18n("C\303\263digo de barras bidimensional (CBB):", 0));
        lblCbb->setText(QString());
        btnCambiarCbb->setText(tr2i18n("Agregar CBB", 0));
        label_4->setText(tr2i18n("Fecha de Aprobaci\303\263n:", 0));
        label_5->setText(tr2i18n("Folio Inicial:", 0));
        label_16->setText(tr2i18n("Folio Final:", 0));
        lblTotalFolios->setText(tr2i18n(".", 0));
    } // retranslateUi

};

namespace Ui {
    class serieFoliosEditor: public Ui_serieFoliosEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EDITFOLIOS_H

