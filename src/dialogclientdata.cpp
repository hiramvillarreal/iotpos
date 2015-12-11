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

#include "dialogclientdata.h"

DialogClientDataUI::DialogClientDataUI( QWidget *parent )
: QFrame( parent )
{
    setupUi( this );
}

DialogClientData::DialogClientData( QWidget *parent )
: KDialog( parent )
{
    ui = new DialogClientDataUI( this );
    setMainWidget( ui );
    setCaption( i18n("Datos del Cliente") );
    setButtons( KDialog::Ok/*|KDialog::Cancel */);
    setDefaultButton(KDialog::NoDefault); //disable default button (return Pressed)
    enableButton(KDialog::Ok, false);

    connect( ui->editNombre, SIGNAL(textEdited(const QString &)), SLOT(validate())  );
    connect( ui->editRFC, SIGNAL(textEdited(const QString &)), SLOT(validate())  );

    //TODO: Validar RFC.
    //QRegExp regexpName("[A-Za-z_0-9\\s\\\\/\\-]+");//any letter, number, both slashes, dash and lower dash. and any space
    //QRegExpValidator *regexpAlpha = new QRegExpValidator(regexpName, this);
    //ui->editRFC->setValidator(regexpAlpha);

    ui->editNombre->setFocus();
}

DialogClientData::~DialogClientData()
{
    delete ui;
}

void DialogClientData::validate()
{
    bool valido = false;

    if ( !ui->editNombre->text().isEmpty() && !ui->editRFC->text().isEmpty())
        valido = true;
    
    enableButton(KDialog::Ok, valido);
}

QString DialogClientData::getDireccion()
{
    QString t = ui->editDireccion->toPlainText();
    return t;
}

#include "dialogclientdata.moc"
