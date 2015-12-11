/***************************************************************************
 *   Copyright (C) 2009-2011 by Miguel Chavez Gamboa                       *
 *   miguel@lemonpos.org                                                   *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Lesser General Public License for more details.                   *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General  Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#include "mibitpassworddlg.h"

#include <QPixmap>
#include <QString>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimeLine>
//#include "ease-effects/qtimeline.h"
#include <QTimer>
#include <QPushButton>
#include <QKeyEvent>
#include <QDebug>

MibitPasswordDialog::MibitPasswordDialog( QWidget *parent, const QString &msg, const QString &file, const QPixmap &icon, AnimationTypeP animation )
        : QSvgWidget( parent ) //setting parent = 0 makes the dialog a window, capable to use the setWidowModality(Qt::ApplicationModal).
{
    //setWindowFlags(Qt::FramelessWindowHint);//this makes frameless but with a background.. and cannot be transparent!
    //setWindowModality(Qt::ApplicationModal); //This only works for windows (not widgets like this)

    if (file != 0) setSVG(file);

    m_parent = parent;
    animType = animation;
    setMinimumHeight(100);
    setFixedSize(0,0); //until show we grow it
    setMaxHeight(pmaxH); //default sizes
    setMaxWidth(pmaxW);
    animRate = 500; //default animation speed (half second rate).
    shakeTimeToLive = 0;
    par = false; parTimes = 0;
    if (closeMsg.isEmpty()) closeMsg = "Ok";


    img      = new QLabel();
    hLayout   = new QHBoxLayout();
    vLayout  = new QVBoxLayout();
    text     = new QLabel(msg);
    //btnClose = new QPushButton(closeMsg); ///TODO: what about translations???
    editPassword = new QLineEdit(this);
    shakeTimer = new QTimer(this);
    shakeTimer->setInterval(20);


    img->setPixmap(icon);
    img->setMaximumHeight(70); //the icon size is hardcoded now.
    img->setMaximumWidth(70);
    img->setAlignment(Qt::AlignLeft);
    img->setMargin(4);

    //btnClose->setMaximumWidth(120);
    editPassword->setEchoMode(QLineEdit::Password);

    setLayout(vLayout);
    text->setWordWrap(true);
    text->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
    text->setMargin(5);


    hLayout->addWidget(img,0,Qt::AlignCenter);
    hLayout->addWidget(text,1,Qt::AlignCenter);
    vLayout->addLayout(hLayout,2);
    vLayout->addWidget(editPassword,1,Qt::AlignCenter);
    //vLayout->addWidget(btnClose,1,Qt::AlignCenter);
    timeLine  = new QTimeLine(animRate, this);
    wTimeLine = new QTimeLine(2000, this);
    wTimeLine->setFrameRange(90,190);
    wTimeLine->setCurveShape(QTimeLine::CosineCurve);
    connect(timeLine, SIGNAL(frameChanged(int)), this, SLOT(animate(int)));
    connect(wTimeLine, SIGNAL(frameChanged(int)), this, SLOT(waveIt(int)));
    //connect(btnClose,SIGNAL(clicked()),this, SLOT(hideDialog()));
    connect(timeLine,SIGNAL(finished()), this, SLOT(onAnimationFinished()));
    connect(shakeTimer,SIGNAL(timeout()), this, SLOT(shakeIt()));
}

MibitPasswordDialog::~MibitPasswordDialog()
{
}


void MibitPasswordDialog::showDialog(const QString &msg, AnimationTypeP animation )
{
    //set default msg if the sent is empty. Also set the animation -the same way-.
    if (msg.isEmpty()) setMessage(text->text()); else setMessage( msg );
    if (animation == 0) setAnimationType( atpSlideDown ); else setAnimationType( animation );

    setGeometry(-1000,-1000,0,0);
    show();
    //update steps for animation, now that the window is showing.

    int maxStep = 0, minStep = 0;
    switch (animType) {
        case atpSlideDown:
            maxStep = (m_parent->geometry().height()/2)-(maxHeight/2);
            minStep = -maxHeight;
            break;
        case atpSlideUp:
            maxStep = (m_parent->geometry().height()/2)-(maxHeight/2);
            minStep = maxHeight + m_parent->geometry().height();
            break;
        case atpGrowCenterH:
            maxStep = maxWidth;
            minStep = 0;
            break;
        case atpGrowCenterV:
            maxStep= maxHeight;
            minStep = 0;
            break;
    }

    #if QT_VERSION >= 0x040600
      timeLine->setEasingCurve(QEasingCurve::OutBounce); // QEasingCurve::OutBounce is since Qt 4.6 only.. will not compile with Qt 4.5 or earlier
    #endif
    timeLine->setFrameRange(minStep,maxStep);
    //make it grow...
    timeLine->setDirection(QTimeLine::Forward);
    timeLine->start();
    editPassword->setFocus();
}

void MibitPasswordDialog::animate(const int &step)
{
    //get some sizes...
    QRect windowGeom = m_parent->geometry();
    int midPointX = (windowGeom.width()/2);
    int midPointY = (windowGeom.height()/2);
    int newY;
    int newX;

    QRect dRect;
    switch (animType) {
        case atpGrowCenterV:   // Grow from Center Vertically..
            if ((midPointY - step/2) < 0 ) newY = 0; else newY = midPointY - step/2;
            if ((midPointX-(maxWidth/2)) < 0) newX = 0; else newX = midPointX - maxWidth/2;
            dRect.setX(newX);
            dRect.setY(newY);
            dRect.setWidth(step);
            dRect.setHeight(maxHeight);
            setGeometry(dRect);
            setFixedHeight(step);
            setFixedWidth(maxWidth);
            break;
        case atpGrowCenterH:   // Grow from Center Horizontally...
            if ((midPointX - step/2) < 0 ) newX = 0; else newX = midPointX - step/2;
            if ((midPointY-(maxHeight/2)) < 0) newY = 0; else newY = midPointY - maxHeight/2;
            dRect.setX(newX);
            dRect.setY(newY);
            dRect.setWidth(maxWidth);
            dRect.setHeight(step);
            setGeometry(dRect);
            setFixedHeight(maxHeight);
            setFixedWidth(step);
            break;
        case atpSlideDown:  // slide Up
        case atpSlideUp:    // Slide down
            if ((midPointX-(maxWidth/2)) < 0) newX = 0; else newX = midPointX - maxWidth/2;
            dRect.setX(newX);
            dRect.setY(step);
            dRect.setWidth(maxWidth);
            dRect.setHeight(maxHeight);
            setGeometry(dRect);
            setFixedHeight(maxHeight);
            setFixedWidth(maxWidth);
            break;
        default:
           break;
    }
}

void MibitPasswordDialog::hideDialog()
{
    timeLine->toggleDirection();//reverse!
    timeLine->start();
}

void MibitPasswordDialog::onAnimationFinished()
{
    if (timeLine->direction() == QTimeLine::Backward) {
        close();
        shakeTimer->stop();
    }
}


void MibitPasswordDialog::setSVG(const QString &file)
{
    load(file);
}

void MibitPasswordDialog::setIcon(const QPixmap &icon)
{
     img->setPixmap(icon);
 }

void MibitPasswordDialog::setMessage(const QString &msg)
{
    text->setText(msg);
}

void MibitPasswordDialog::setTextColor(const QString &color)
{
    text->setStyleSheet(QString("color:%1").arg(color));
}

void MibitPasswordDialog::shake()
{
    shakeTimer->start();
    if ( shakeTimeToLive > 0 ) QTimer::singleShot(shakeTimeToLive,shakeTimer,SLOT(stop()));
}

void MibitPasswordDialog::shakeIt()
{
    if (par) {
        if (parTimes < 5) {
            if ( parTimes % 2 == 0 )
                setGeometry(geometry().x()-3, geometry().y()+3, geometry().width(), geometry().height());
            else
                setGeometry(geometry().x()+3, geometry().y()+3, geometry().width(), geometry().height());
        }
        parTimes++;
        if (parTimes >39) {
            parTimes = 0;
        }
    }
    else {
        if (parTimes < 5) {
            if ( parTimes % 2 == 0 )
                setGeometry(geometry().x()+3, geometry().y()-3, geometry().width(), geometry().height());
            else
                setGeometry(geometry().x()-3, geometry().y()-3, geometry().width(), geometry().height());
        }
    }

    par = !par;
}


void MibitPasswordDialog::wave()
{
    wTimeLine->start();
}

void MibitPasswordDialog::waveIt(const int &step)
{
    if (timeLine->state() == QTimeLine::NotRunning || !shakeTimer->isActive() ) {
    setGeometry(geometry().x(),step, geometry().width(), geometry().height());
    } else qDebug()<<"Dialog is in active animation.";
}

void MibitPasswordDialog::keyPressEvent ( QKeyEvent * event )
{
    if ( event->key() == Qt::Key_Escape )
    {
        // hideDialog();
        // on password dialog ESC key pressed, we cannot close it.
        qDebug()<<"MibitPasswordDialog::ESC key pressed";
    }
    else if ( event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return ) {
        //emit the enter event.
        qDebug()<<"MibitPasswordDialog::Enter key pressed";
        emit returnPressed();
    }
}
