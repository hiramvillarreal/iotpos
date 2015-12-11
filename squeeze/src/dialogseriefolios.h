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
#ifndef DIALOGSERIEFOLIOS_H
#define DIALOGSERIEFOLIOS_H

#include <KDialog>
#include <QtGui>
#include "ui_editfolios.h"

class DialogSerieFoliosUI : public QFrame, public Ui::serieFoliosEditor
{
  Q_OBJECT
  public:
    DialogSerieFoliosUI( QWidget *parent=0 );
};

class DialogSerieFolios : public KDialog
{
  Q_OBJECT
  public:
    DialogSerieFolios( QWidget *parent=0 );
    ~DialogSerieFolios();
    QString getNumeroAprobacion(){ return ui->editNumAprobacion->text();};
    QDate   getFechaAprobacion(){ return ui->calendarWidget->selectedDate();};
    
    QString getFolioInicial(){ return ui->editFolioInicial->text();};
    QString getFolioFinal(){ return ui->editFolioFinal->text();};
    int     getCantidadFolios() { return cantidadFolios; };
    QPixmap getCBB(){ return cbbPix;};

    void setCBB(QPixmap pix) { ui->lblCbb->setPixmap(pix); cbbPix = pix; };


  private slots:
    void changeCBB();
    void validate();


  private:
    DialogSerieFoliosUI *ui;
    QPixmap cbbPix;
    int cantidadFolios;
};

#endif
