/***************************************************************************
 *   Copyright (C) 2012 by Miguel Chavez Gamboa                            *
 *   miguel.chavez.gamboa@gmail.com                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/
#include <KLocale>
#include <KMessageBox>
#include <KFileDialog>

#include <QByteArray>

#include "dialogseriefolios.h"
#include "../../mibitWidgets/mibitlineedit.h"

DialogSerieFoliosUI::DialogSerieFoliosUI( QWidget *parent )
: QFrame( parent )
{
    setupUi( this );
}

DialogSerieFolios::DialogSerieFolios( QWidget *parent )
: KDialog( parent )
{
    ui = new DialogSerieFoliosUI( this );
    setMainWidget( ui );
    setCaption( i18n("Agregar Serie de Folios") );
    setButtons( KDialog::Ok|KDialog::Cancel );
    setDefaultButton(KDialog::NoDefault); //disable default button (return Pressed)
    enableButton(KDialog::Ok, false);

    connect( ui->editNumAprobacion, SIGNAL(textEdited(const QString &)), SLOT(validate())  );
    connect( ui->editFolioFinal, SIGNAL(textEdited(const QString &)), SLOT(validate())  );
    connect( ui->editFolioInicial, SIGNAL(textEdited(const QString &)), SLOT(validate())  );
    connect( ui->calendarWidget, SIGNAL(selectionChanged()), SLOT(validate())  );
    
    connect( ui->btnCambiarCbb   , SIGNAL( clicked() ), this, SLOT( changeCBB() ) );

    //QRegExp regexpName("[A-Za-z_0-9\\s\\\\/\\-]+");//any letter, number, both slashes, dash and lower dash. and any space
    //QRegExpValidator *regexpAlpha = new QRegExpValidator(regexpName, this);
    //ui->editClientCode->setValidator(regexpAlpha);

    //TODO: Validar fecha, que no sea mayor a TODAY.
    //      Validar folios, que inicial corresponda a final ( A100 -> A200 ) que la serie sea igual en ambas.
    //      Que todos los datos esten llenos (fecha, numero, folios, cbb)
    

    ui->editNumAprobacion->setEmptyMessage(i18n("Num. de aprobación de folios otorgado por el SAT."));
    ui->editFolioInicial->setEmptyMessage(i18n("Ejemplo: 100 ó A100"));
    ui->editFolioFinal->setEmptyMessage(i18n("Ejemplo: 1000 ó A1000"));

    //today
    ui->calendarWidget->setSelectedDate(QDate::currentDate());
    ui->calendarWidget->setMaximumDate( QDate::currentDate()/*.addDays(1)*/ ); //today
    
    //QTimer::singleShot(750, this, SLOT(validate()));
    ui->editNumAprobacion->setFocus();
    cantidadFolios = 0;
    ui->editFolioFinal->setAutoClearError(true);
    ui->editFolioInicial->setAutoClearError(true);
}

DialogSerieFolios::~DialogSerieFolios()
{
    delete ui;
}

void DialogSerieFolios::changeCBB()
{
  QString fname = KFileDialog::getOpenFileName();
  if (!fname.isEmpty()) {
    QPixmap p = QPixmap(fname);
    setCBB(p);
    validate();
  }
}

void DialogSerieFolios::validate()
{
    bool valido = false;

    //NumAprobacion
    if ( !ui->editNumAprobacion->text().isEmpty() )
        valido = true;
    else valido = false;
    
    //Fecha checado con el calendarWidget->maximumDate

    //validar que haya cbb.
    if ( cbbPix.isNull() )
        valido =  (valido && false);
    else valido = (valido && true);

    //Validar que no esten vacios los folios.
    if ( ui->editFolioFinal->text().isEmpty() || ui->editFolioInicial->text().isEmpty() )
        valido = (valido && false);
    else {
        //Validar serie de folio, que sean iguales
        QString serieI; QString serieF; qulonglong folioI=0; qulonglong folioF=0;
        QRegExp expr("((^[A-Z]*)(\\d+)$)", Qt::CaseInsensitive, QRegExp::RegExp);
        if (expr.indexIn(ui->editFolioInicial->text()) != -1  ) {
            serieI = expr.cap(2);
            folioI = expr.cap(3).toULongLong();
            qDebug()<<"Serie I:"<<serieI<<" Folio I:"<<folioI;
        }
        if (expr.indexIn(ui->editFolioFinal->text()) != -1  ) {
            serieF = expr.cap(2);
            folioF = expr.cap(3).toULongLong();
            qDebug()<<"Serie F:"<<serieF<<" Folio F:"<<folioF;
        }
        //que sean iguales....
        if ( serieI == serieF && folioI < folioF)
            valido = (valido && true);
        else
            valido = false;
        //calcular cantidad de folios
        if (folioI == 0) {
            //WARNING: No se permite folio inicial 000  (cero).
            folioI = 1; //autocorregir!
            ui->editFolioInicial->setText(serieI+"1");
            qDebug()<<"No se permite que el folio inicial sea CERO. Autocorriegiendo a 1";
        }
        if (folioF == 0) {
            //WARNING No se permite folio final 000 (cero)
            valido = false;
            ui->editFolioFinal->setError("No se permite que el folio final sea CERO.");
            qDebug()<<"No se permite que el folio final sea CERO.";
        }
        cantidadFolios = folioF-folioI + 1; //+1 porque siempre empieza desde 1, no 0.  Ej:  1 - 10 +1 = 10, de folio 1 al folio 10 son 10 folios.
        if (cantidadFolios <= 0)
            valido = false;
        //TODO & WARNING: Falta validar que no se solapen rangos de folios existentes.
        //                Ej. Si existen los folios A1 a A5, y se quiere insertar A3 a A20, entonces A3,A4,A5 se estan SOLAPANDO (duplicando).
        //                Esto se maneja en la bd, no se permiten folios repetidos (primary key)
    }

    enableButton(KDialog::Ok, valido);
}

// } 9169

#include "dialogseriefolios.moc"
