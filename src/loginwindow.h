/***************************************************************************
 *   Copyright (C) 2007-2009 by Miguel Chavez Gamboa             *
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

#ifndef _LOGINWINDOW_H_
#define _LOGINWINDOW_H_

#include <QDialog>
#include <QHash>
#include <QtSql>

#include "structs.h"

class QLineEdit;
class QLabel;
class QPushButton;
class QString;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QSpacerItem;
class QSqlDatabase;

/** This class is for asking login and password.
 *  Derived from QDialog, but to use full screen and no borders.
 *  Also to have an image in the background.
 *
 * @short A Login Window
 * @author Miguel Chavez Gamboa  miguel.chavez.gamboa@gmail.com
**/
class LoginWindow : public QDialog
{
  Q_OBJECT
  private:
    QLineEdit   *editUsername;
    QLineEdit   *editPassword;
    QLabel      *labelPrompt;
    QLabel      *imageError;
    QLabel      *mainImage;
    QLabel      *labelError;
    QLabel      *labelUsername;
    QLabel      *labelPassword;
    QLabel      *labelCaption;
    QPushButton *btnOk;
    QPushButton *btnQuit;
    QVBoxLayout *vLayout;
    QVBoxLayout *editsLayout;
    QHBoxLayout *errorLayout;
    QHBoxLayout *middleLayout;
    QHBoxLayout *okLayout;
    QHBoxLayout *quitLayout;
    QGridLayout *gridLayout;
    QSpacerItem *spacerItemBottom;
    QSpacerItem *spacerItemTop;
    QHash<QString, UserInfo> uHash;
    QSqlDatabase db;
    bool wantQuit;
    qulonglong userId;

  public:
    enum Mode
      {
        FullScreen = 0,
        PasswordOnly = 1
      };
    LoginWindow::Mode currentMode;
    LoginWindow(QString caption,
                QString prompt,
                LoginWindow::Mode mode=LoginWindow::FullScreen);
    ~LoginWindow();

    QString username();
    QString password();
    int     getUserRole() { return userRole; }
    qulonglong getUserId();
    void clearLines();
    bool checkPassword();
    void setPrompt(QString text);
    void setCaption(QString text);
    void showErrorMessage(QString text);
    void setDb(QSqlDatabase database);
    bool wantToQuit();
    void setUsername(QString un);
    void setUsernameReadOnly(bool val);
    void focusPassword();
    void reloadUsers();
  private:
    int  userRole;
    
  protected slots:
    void acceptIt();
    void setQuit();
    void hideError();
    void showAdminPhoto();
    void updateUserPhoto(const QString &);
    QHash<QString, UserInfo> getUsers();

  private slots:
    virtual void paintEvent(QPaintEvent*);
};

#endif
