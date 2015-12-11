/***************************************************************************
 *   Copyright (C) 2007-2009 by Miguel Chavez Gamboa                  *
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

#include "loginwindow.h"
#include "hash.h"
#include "settings.h"
#include "enums.h"

#include <QtGui>
#include <QPixmap>
#include <kiconloader.h>
#include <klocale.h>
#include <kstandarddirs.h>
#include "../dataAccess/azahar.h"


#include <QSqlDatabase>
#include <QTimer>

LoginWindow::LoginWindow(QString caption,
                         QString prompt,
                         LoginWindow::Mode mode)
{
  setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
  setWindowModality(Qt::ApplicationModal);
  currentMode = mode;
  userId = 0;

  //controls
  vLayout       = new QVBoxLayout(this);
  errorLayout   = new QHBoxLayout();
  editsLayout   = new QVBoxLayout();
  middleLayout  = new QHBoxLayout();
  okLayout      = new QHBoxLayout();
  quitLayout    = new QHBoxLayout();
  imageError    = new QLabel(this);
  mainImage     = new QLabel(this);
  labelError    = new QLabel(this);
  labelUsername = new QLabel(this);
  labelPassword = new QLabel(this);
  labelCaption  = new QLabel(this);
  labelPrompt   = new QLabel(this);
  editUsername  = new QLineEdit(this);
  editPassword  = new QLineEdit(this);
  btnQuit       = new QPushButton(DesktopIcon("system-shutdown", 48), i18n("&Quit"));
  btnOk         = new QPushButton(DesktopIcon("dialog-ok-apply", 48), i18n("&Ok"), this);
  spacerItemBottom= new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
  spacerItemTop = new QSpacerItem(20, 115, QSizePolicy::Minimum, QSizePolicy::Maximum);
  QSpacerItem *spacerItemBtn = new QSpacerItem(16, 16, QSizePolicy::Minimum, QSizePolicy::Maximum);
  QSpacerItem *spacerItemBtn2 = new QSpacerItem(8, 8, QSizePolicy::Minimum, QSizePolicy::Maximum);

  //layout
  vLayout->addWidget(labelCaption);
  vLayout->addWidget(labelPrompt);
  errorLayout->addStretch(200);
  errorLayout->addWidget(imageError);
  errorLayout->addWidget(labelError);
  //grid for username/passwords fields and labels
  gridLayout = new QGridLayout();
  editUsername->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
  editPassword->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
  labelUsername->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
  labelPassword->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
  gridLayout->addWidget(labelUsername, 0, 0, 1, 1);
  gridLayout->addWidget(editUsername, 0, 1, 1, 1);
  gridLayout->addWidget(labelPassword, 1, 0, 1, 1);
  gridLayout->addWidget(editPassword, 1, 1, 1, 1);


  if (mode == LoginWindow::FullScreen) vLayout->addItem(spacerItemTop);
  okLayout->addStretch(100);
  okLayout->addWidget(btnOk);
  quitLayout->addStretch(100);
  okLayout->addWidget(btnQuit);
  editsLayout->addItem(spacerItemBtn);
  editsLayout->addLayout(gridLayout);
  editsLayout->addItem(spacerItemBtn2);
  editsLayout->addLayout(okLayout);
  if (mode == LoginWindow::FullScreen) editsLayout->addWidget(btnQuit); else btnQuit->hide();

  middleLayout->addStretch(200);
  middleLayout->addWidget(mainImage);
  middleLayout->addLayout(editsLayout);
  vLayout->addLayout(middleLayout);
  vLayout->addLayout(errorLayout);
  if (mode == LoginWindow::FullScreen) vLayout->addItem(spacerItemBottom);

  btnOk->setMaximumSize(QSize(140, 27));
  btnQuit->setMaximumSize(QSize(140, 27));
  btnOk->setMinimumSize(QSize(120, 27));
  btnQuit->setMinimumSize(QSize(120, 27));
  editUsername->setMinimumSize(QSize(120, 28));
  editPassword->setMinimumSize(QSize(120, 28));
  editUsername->setMaximumSize(QSize(160, 28));
  editPassword->setMaximumSize(QSize(160, 28));

  //FIXME: Para el cuadro de login&password, se necesita un groupbox para ponerle el fondo semitransparente.
  //Porque para diferentes resoluciones de pantalla, se acomodara el layout de diferente forma.


//NOTE: Using this lines, even with --style=plastique, the stylesheet is not applied.
//   this->setStyle(new QPlastiqueStyle);
//   btnQuit->setStyle(new QPlastiqueStyle);
//   qDebug()<<"Plasique set to loginwindow!";


  //ObjectName is needed for styling... via stylesheets.
  labelCaption->setObjectName("labelCaption");
  labelPrompt->setObjectName("labelPrompt");
  labelError->setObjectName("labelError");

  //qDebug()<<"Geometry:"<<geom;
  QString str("admin");
  QString path; QPixmap pixm;
  QPixmap copia;
  switch (mode)
  {
    case LoginWindow::FullScreen:
      setWindowState(Qt::WindowFullScreen);
      setObjectName("loginDialog");
      mainImage->setPixmap(DesktopIcon("lemon-user", 128));
      imageError->setPixmap(DesktopIcon("dialog-cancel", 48));
      setGeometry(QApplication::desktop()->screenGeometry(this));
      break;
    case LoginWindow::PasswordOnly:
      setObjectName("passwordDialog");
      //labelUsername->hide();
      //editUsername->hide();
      editPassword->setMaximumSize(QSize(120, 28));
      mainImage->setPixmap(DesktopIcon("lemon-user", 128));
      imageError->setPixmap(DesktopIcon("dialog-cancel", 22));
      QTimer::singleShot(3000, this, SLOT(showAdminPhoto()));
      resize(348,215); //Size of the login background...
      path = KStandardDirs::locate("appdata", "styles/");
      pixm = QPixmap(path + Settings::styleName() + "/passwordBackground_wide.png");
      //qDebug()<<"password image path:"<<path + Settings::styleName();
      setMask( pixm.mask() );
      //FIXME:Why at widescreen 1280x800, the dialogs moves to 0,0 ? -- only with compiz
      break;
    default:
      break;
  }

  mainImage->setAlignment(Qt::AlignHCenter);
  mainImage->setMinimumSize(QSize(128, 128));
  mainImage->setMaximumSize(QSize(128,128));
  mainImage->setGeometry(0,0,128,128);
  mainImage->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
  setCaption(caption);
  setPrompt(prompt);
  labelUsername->setText(i18n("Username:"));
  labelPassword->setText(i18n("Password:"));
  editPassword->setEchoMode(QLineEdit::Password);
  btnOk->setDefault(false);
  btnQuit->setDefault(false);
  hideError();

  connect(editUsername, SIGNAL(returnPressed()), editPassword, SLOT(setFocus()));
  connect(editPassword, SIGNAL(returnPressed()),               SLOT(acceptIt()));
  connect(btnOk,        SIGNAL(clicked()),                     SLOT(acceptIt()));
  connect(btnQuit,      SIGNAL(clicked()),      this,          SLOT(setQuit()));
  connect(editUsername, SIGNAL(textEdited(const QString &)),   SLOT(updateUserPhoto(const QString &)));

  uHash.clear();
  wantQuit = false;

}

/* This is a workaround for the login/password dialog background.
 * Simply draw the pixmap, instead the style painting.
 * NOTE: This may not be styleable... so this can confuse users that wants to change its image via stylesheet.
*/
void LoginWindow::paintEvent(QPaintEvent* event){
  QDialog::paintEvent(event);
  QPainter painter(this);
  painter.setClipRegion(event->region());
  QString path = KStandardDirs::locate("appdata", "styles/");
  QPixmap bg; QString fileName;
  //getting style source.
  fileName = path + Settings::styleName() + "/" + Settings::styleName() + ".qss";
  QFile file(fileName);
  file.open(QFile::ReadOnly);
  QString styleSheet = QLatin1String(file.readAll());
  //replace fakepath to the real path..
  QString bgName;
  int indxs = styleSheet.indexOf("]loginBackground");
  int indxe = styleSheet.indexOf(")", indxs);
  /*indxe = indxe-1;*/ indxs = indxs+1;
  bgName = styleSheet.mid(indxs,indxe-indxs);
  //qDebug()<<" index start:"<<indxs<<" index end:"<<indxe<<" string:"<<bgName<< " OMG: How many times this is updated! (painted)...";
  

  switch (currentMode)
  {
    case LoginWindow::FullScreen:
      //if (QApplication::desktop()->screenGeometry(this) != geometry()) setGeometry(QApplication::desktop()->screenGeometry(this));
      setWindowState( windowState() | Qt::WindowFullScreen );
      bg = QPixmap(path + Settings::styleName() + "/" + bgName);
      break;
    case LoginWindow::PasswordOnly:
      bg = QPixmap(path + Settings::styleName() + "/passwordBackground_wide.png");
      break;
    default:
      break;
  }
  //qDebug()<<"password image path:"<<path + Settings::styleName();
  painter.drawPixmap(QPoint(0,0), bg);
}

void LoginWindow::setDb(QSqlDatabase database)
{
  db = database;
  if (!db.isOpen()) db.open();
  if (!db.isOpen()) //If not open, is mysql not running???
  {
    qDebug()<<"************ ERROR: mysql is maybe not running **************";
    qDebug()<<db.lastError();
    qDebug()<<"*************************************************************";
    done(QDialog::Rejected);
  }
}

LoginWindow::~LoginWindow()
{
}

QString LoginWindow::username()
{
  return editUsername->text();
}

QString LoginWindow::password()
{
  return editPassword->text();
}

void LoginWindow::clearLines()
{
  editUsername->clear();
  editPassword->clear();
  editUsername->setFocus();
}

void LoginWindow::setPrompt(QString text)
{
  labelPrompt->setText(text);
}

void LoginWindow::setCaption(QString text)
{
  labelCaption->setText(text);
}

bool LoginWindow::checkPassword()
{
  if (uHash.isEmpty()) uHash = getUsers();
  bool result=false;
  bool showError=false;
  QString user;
  
  // Now we use roles and username is requiered even for administrator(s).
  user = username();

  //NOTE: Update uHash from database?..
  if (uHash.contains(user)) {
    UserInfo uInfo = uHash.value(user);
    userRole = uInfo.role;
    userId   = uInfo.id;
    QString givenPass = Hash::password2hash((uInfo.salt+password()).toLocal8Bit());
    if (givenPass == uInfo.password) {
      // Condition #1 : USER PASSWORD satisfied!
      // Condition #2: if FullScreen means any user can be validated else in PasswordOnly ONLY Admin/Supervisor can be validated
      if (currentMode == PasswordOnly) { //really not only password since roles are implemented.
        if ((uInfo.role == roleAdmin) || (uInfo.role == roleSupervisor)) {
          result = true;
        } else {
          result=false;
        }
      } else { //any  user role
        result = true;
      }
    }//if password is ok
    else {
      showError = true;
    }
  } else showError = true;
  if (showError) showErrorMessage(i18n("Invalid username or password"));
  return result;
}

void LoginWindow::showErrorMessage(QString text)
{
  labelError->setText(text);
  if (currentMode == LoginWindow::FullScreen) imageError->setPixmap(DesktopIcon("dialog-cancel", 48));
  else imageError->setPixmap(DesktopIcon("dialog-cancel", 22));
  QTimer::singleShot(3000, this, SLOT(hideError()));
}

void LoginWindow::hideError()
{
  labelError->clear();
  //image hiding-showing moves the content and it flickers the graphics vertically.
  //so lets change the image.
  if (currentMode == LoginWindow::FullScreen) imageError->setPixmap(DesktopIcon("document-encrypt", 48));
  else imageError->setPixmap(DesktopIcon("document-encrypt", 22));
}

void LoginWindow::acceptIt()
{
  if (checkPassword()) QDialog::accept();
}


void LoginWindow::updateUserPhoto(const QString &text)
{

//   QByteArray salt = getSalt();
//   QString    pass = password2hash((salt+"mangostan"));
//   qDebug()<<"creating new salt:"<<salt;
//   qDebug()<<"creating new hashed password:"<<pass;

  if (uHash.isEmpty()) uHash = getUsers();
  if (uHash.contains(text)) {
    UserInfo info = uHash.value(text);
    userId = info.id;
    QPixmap pix;
    pix.loadFromData(info.photo); //Photos are saved as 128x128 pngs or jpgs...
    if (!pix.isNull()) mainImage->setPixmap(pix);
  }
  else {
    //Repaint image if it is the same??? how to know it is the same?
    mainImage->setPixmap(DesktopIcon("lemon-user", 128));
  }
  mainImage->setAlignment(Qt::AlignCenter);
}

void LoginWindow::showAdminPhoto()
{
  updateUserPhoto("admin");
}


QHash<QString, UserInfo> LoginWindow::getUsers()
{
  QHash<QString,UserInfo> hash;
  hash.clear();

  Azahar *myDb = new Azahar;
  myDb->setDatabase(db);
  hash = myDb->getUsersHash();
  delete myDb;
  return hash;
}

void LoginWindow::setQuit()
{
  qDebug()<<"SetQuit..";
  wantQuit = true;
  QDialog::reject();
}

bool LoginWindow::wantToQuit()
{
  return wantQuit;
  qDebug()<<"Wants to quit!";
}

void LoginWindow::setUsername(QString un)
{
  editUsername->setText(un);
  editUsername->setReadOnly(true);
}

void LoginWindow::setUsernameReadOnly(bool val)
{
  editUsername->setReadOnly(val);
}

void LoginWindow::focusPassword()
{
  editPassword->setFocus();
}

qulonglong LoginWindow::getUserId()
{
  return userId;
}

void LoginWindow::reloadUsers()
{
    uHash = getUsers();
}

#include "loginwindow.moc"
