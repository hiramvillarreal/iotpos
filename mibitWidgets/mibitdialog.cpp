/***************************************************************************
 *   Copyright (C) 2009 by Miguel Chavez Gamboa                            *
 *   miguel@lemonpos.org                                                   *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Lesser General  Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Lesser General  Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General  Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#include "mibitdialog.h"

#include <QPixmap>
#include <QString>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimeLine>
#include "ease-effects/qtimeline.h"
#include <QTimer>
#include <QPushButton>
#include <QKeyEvent>
#include <QDebug>

MibitDialog::MibitDialog( QWidget *parent, const QString &msg, const QString &file, const QPixmap &icon, AnimationType animation )
        : QSvgWidget( parent )
{
    if (file != 0) setSVG(file);

    m_parent = parent;
    animType = animation;
    setMinimumHeight(100);
    setFixedSize(0,0); //until show we grow it
    setMaxHeight(maxH); //default sizes
    setMaxWidth(maxW);
    animRate = 500; //default animation speed (half second rate).
    shakeTimeToLive = 0;
    par = false; parTimes = 0;


    img      = new QLabel();
    hLayout   = new QHBoxLayout();
    vLayout  = new QVBoxLayout();
    text     = new QLabel(msg);
    btnClose = new QPushButton("Close"); ///TODO: what about translations???
    shakeTimer = new QTimer(this);
    shakeTimer->setInterval(20);


    img->setPixmap(icon);
    img->setMaximumHeight(54); //the icon size is hardcoded now.
    img->setMaximumWidth(54);
    img->setAlignment(Qt::AlignLeft);
    img->setMargin(4);

    btnClose->setMaximumWidth(120);

    setLayout(vLayout);
    text->setWordWrap(true);
    text->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
    text->setMargin(5);


    hLayout->addWidget(img,0,Qt::AlignCenter);
    hLayout->addWidget(text,1,Qt::AlignCenter);
    vLayout->addLayout(hLayout,2);
    vLayout->addWidget(btnClose,1,Qt::AlignCenter);
    timeLine  = new QTimeLine(animRate, this);
    wTimeLine = new QTimeLine(2000, this);
    wTimeLine->setFrameRange(90,190);
    wTimeLine->setCurveShape(QTimeLine::CosineCurve);
    connect(timeLine, SIGNAL(frameChanged(int)), this, SLOT(animate(int)));
    connect(wTimeLine, SIGNAL(frameChanged(int)), this, SLOT(waveIt(int)));
    connect(btnClose,SIGNAL(clicked()),this, SLOT(hideDialog()));
    connect(timeLine,SIGNAL(finished()), this, SLOT(onAnimationFinished()));
    connect(shakeTimer,SIGNAL(timeout()), this, SLOT(shakeIt()));
}

MibitDialog::~MibitDialog()
{
}


void MibitDialog::showDialog(const QString &msg, AnimationType animation )
{
    //set default msg if the sent is empty. Also set the animation -the same way-.
    if (msg.isEmpty()) setMessage(text->text()); else setMessage( msg );
    if (animation == 0) setAnimationType( atSlideDown ); else setAnimationType( animation );

    setGeometry(-1000,-1000,0,0);
    show();
    //update steps for animation, now that the window is showing.

    int maxStep; int minStep = 0;
    switch (animType) {
        case atSlideDown:
            maxStep = (m_parent->geometry().height()/2)-(maxHeight/2);
            minStep = -maxHeight;
            break;
        case atSlideUp:
            maxStep = (m_parent->geometry().height()/2)-(maxHeight/2);
            minStep = maxHeight + m_parent->geometry().height();
            break;
        case atGrowCenterH:
            maxStep = maxWidth;
            minStep = 0;
            break;
        case atGrowCenterV:
            maxStep= maxHeight;
            minStep = 0;
            break;
    }

    /// QTimeLine: Hacer una curva de movimiento armonico criticamente amortiguado.
    timeLine->setFrameRange(minStep,maxStep);
    //make it grow...
    timeLine->setDirection(QTimeLine::Forward);
    timeLine->start();
    btnClose->setFocus();
}

void MibitDialog::animate(const int &step)
{
    //get some sizes...
    QRect windowGeom = m_parent->geometry();
    int midPointX = (windowGeom.width()/2);
    int midPointY = (windowGeom.height()/2);
    int newY;
    int newX;

    QRect dRect;
    switch (animType) {
        case atGrowCenterV:   // Grow from Center Vertically..
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
        case atGrowCenterH:   // Grow from Center Horizontally...
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
        case atSlideDown:  // slide Up
        case atSlideUp:    // Slide down
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

void MibitDialog::hideDialog()
{
    timeLine->toggleDirection();//reverse!
    timeLine->start();
}

void MibitDialog::onAnimationFinished()
{
    if (timeLine->direction() == QTimeLine::Backward) {
        close();
        shakeTimer->stop();
    }
}


void MibitDialog::setSVG(const QString &file)
{
    load(file);
}

void MibitDialog::setIcon(const QPixmap &icon)
{
     img->setPixmap(icon);
 }

void MibitDialog::setMessage(const QString &msg)
{
    text->setText(msg);
}

void MibitDialog::setTextColor(const QString &color)
{
    text->setStyleSheet(QString("color:%1").arg(color));
}

void MibitDialog::shake()
{
    shakeTimer->start();
    if ( shakeTimeToLive > 0 ) QTimer::singleShot(shakeTimeToLive,shakeTimer,SLOT(stop()));
}

void MibitDialog::shakeIt()
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


void MibitDialog::wave()
{
    wTimeLine->start();
}

void MibitDialog::waveIt(const int &step)
{
    if (timeLine->state() == QTimeLine::NotRunning || !shakeTimer->isActive() ) {
    setGeometry(geometry().x(),step, geometry().width(), geometry().height());
    } else qDebug()<<"Dialog is in active animation.";
}

void MibitDialog::keyPressEvent ( QKeyEvent * event )
{
    if ( event->key() == Qt::Key_Escape )
    {
        hideDialog();
    } //else ignore event.
}
