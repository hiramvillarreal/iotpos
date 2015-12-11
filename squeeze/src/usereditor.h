/***************************************************************************
 *   Copyright (C) 2007-2009 by Miguel Chavez Gamboa                       *
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
#ifndef USEREDITOR_H
#define USEREDITOR_H

#include <KDialog>
#include <QtGui>
#include "ui_edituser_widget.h"

class UserEditorUI : public QFrame, public Ui::userEditor
{
  Q_OBJECT
  public:
    UserEditorUI( QWidget *parent=0 );
};

class UserEditor : public KDialog
{
  Q_OBJECT
  public:
    UserEditor( QWidget *parent=0 );
    ~UserEditor();
    void setUserName(QString uname);
    void setRealName(QString rname) { ui->editUsersName->setText(rname); };
    void setAddress(QString address) { ui->editUsersAddress->setText(address); } ;
    void setPhone(QString phone) { ui->editUsersPhone->setText(phone); };
    void setCell(QString cell) { ui->editUsersCell->setText(cell); };
    void setPhoto(QPixmap photo) { ui->labelUsersPhoto->setPixmap(photo); pix = photo; };
    void setId(long int id) { userId = id; };
    void setUserRole(const int &role);
    void disableRoles(const bool &yes) {ui->groupRoles->setDisabled(yes);};
    void disallowAdminChange(const bool &yes);

    QString getUserName(){ return ui->editUsersUsername->text();};
    QString getRealName(){ return ui->editUsersName->text();};
    QString getAddress(){ return ui->editUsersAddress->toPlainText();};
    QString getPhone(){ return ui->editUsersPhone->text();};
    QString getCell(){ return ui->editUsersCell->text();};
    QString getNewPassword() { return ui->editUsersPassword->text(); };
    QPixmap getPhoto(){ return pix;};
    int     getUserRole();

  private slots:
    void changePhoto();
    void checkName();


  private:
    UserEditorUI *ui;
    long int userId;
    QPixmap pix;
};

#endif
