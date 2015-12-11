/***************************************************************************
 *   Copyright (C) 2009 by Miguel Chavez Gamboa                            *
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
 *   GNU Lesser General  Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General  Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#include "mibitnotifier.h"

#include <QPixmap>
#include <QIcon>
#include <QString>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimeLine>
#include <QTimer>
#include <QDebug>

MibitNotifier::MibitNotifier(QWidget *parent, const QString &file, const QPixmap &icon, const bool &onTop)
        : QSvgWidget( parent )
{
    if (file != 0) setSVG(file);

    m_parent = parent;
    m_onTop = onTop;
    m_canClose = false;
    m_fileName = file;
    setMinimumHeight(100);
    setFixedSize(0,0); //until show we grow it
    setMaxHeight(max_H); //default sizes
    setMaxWidth(max_W);
    animRate = 500; //default animation speed (half second rate).

    img        = new QLabel();
    hLayout    = new QHBoxLayout();
    message    = new QLabel("");


    img->setPixmap(icon);
    img->setMaximumHeight(54); //the icon size is hardcoded now.
    img->setMaximumWidth(54);
    img->setAlignment(Qt::AlignLeft);
    img->setMargin(4);

    setLayout(hLayout);
    message->setWordWrap(true);
    message->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
    message->setMargin(10);
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    sizePolicy.setHeightForWidth(message->sizePolicy().hasHeightForWidth());
    message->setSizePolicy(sizePolicy);

    hLayout->addWidget(img,0,Qt::AlignLeft);
    hLayout->addWidget(message,1,Qt::AlignJustify);

    timeLine  = new QTimeLine(animRate, this);
    connect(timeLine, SIGNAL(frameChanged(int)), this, SLOT(animate(int)));
    connect(timeLine,SIGNAL(finished()), this, SLOT(onAnimationFinished()));
}

void MibitNotifier::showNotification( const QString &msg, const int &timeToLive) //timeToLive = 0 : not auto hide it.
{
    /// Warning: if a tip is showing, if another showTip() is called, it is ignored.
    if (timeLine->state() == QTimeLine::NotRunning && !m_canClose /*size().height() <= 0*/) {
        //set default msg if the sent is empty.
        if (!msg.isEmpty()) {
            setMessage( msg );
            message->setMinimumWidth(maxWidth-70);
        } else setMessage(message->text()); 
        //change svg skin if is not on top.
        if (!m_onTop) setSVG("rotated_"+m_fileName); else setSVG(m_fileName);
        setGeometry(-1000,-1000,0,0);
        show();
        //update steps for animation, now that the window is showing.
        int maxStep; int minStep = 0;

        if ( m_onTop ) {
            minStep = -maxHeight;
            maxStep =  0;
        } else {
            maxStep = m_parent->geometry().height()-maxHeight;
            minStep = m_parent->geometry().height();
        }
        //qDebug()<<" MaxStep:"<<maxStep<<" MinStep:"<<minStep;

        timeLine->setFrameRange(minStep,maxStep);
        //make it grow
        timeLine->setDirection(QTimeLine::Forward);
        timeLine->start();

        if (timeToLive > 0 ) QTimer::singleShot(timeToLive,this,SLOT(hideDialog()));
    }
}

void MibitNotifier::animate(const int &step)
{
    //get some sizes...
    QRect windowGeom = m_parent->geometry();
    int midPointX = (windowGeom.width()/2);
    int newX; int newW;
    QRect dRect;
    if (maxWidth < min_W ) newW = min_W; else newW = maxWidth;
    if ((midPointX-(newW/2)) < 0) newX = 0; else newX = midPointX - (newW/2);

    dRect.setX(newX);
    setFixedWidth(newW);

    dRect.setY(step);
    setGeometry(dRect);
    setFixedHeight(maxHeight);

    if (m_onTop) { // Sliding from top
        if (step == -maxHeight) setFixedHeight(0);
    } else {       // Sliding from bottom
        if (step == m_parent->geometry().height()) setFixedHeight(0);
    } 
}

void MibitNotifier::hideOnUserRequest()
{
    hideDialog();
}

void MibitNotifier::hideDialog()
{
    if ( m_canClose ) {
        timeLine->toggleDirection();//reverse!
        timeLine->start();
    }
}

void MibitNotifier::onAnimationFinished()
{
    if (timeLine->direction() == QTimeLine::Backward) {
        close();
        m_canClose = false;
    } else m_canClose = true;
}

void MibitNotifier::setOnBottom(const bool &sOnBottom)
{
    // only changes the position when the notification is not showing..
    if (timeLine->state() == QTimeLine::NotRunning && size().height() <= 0)    m_onTop = !sOnBottom;
}


void MibitNotifier::setSVG(const QString &file)
{
    load(file);
}

void MibitNotifier::setIcon(const QPixmap &icon)
{
     img->setPixmap(icon);
 }

void MibitNotifier::setMessage(const QString &msg)
{
    message->setText(msg);
}

void MibitNotifier::setTextColor(const QString &color)
{
    message->setStyleSheet(QString("color:%1").arg(color));
}

void MibitNotifier::mousePressEvent ( QMouseEvent * )
{
    hideOnUserRequest();
}

MibitNotifier::~MibitNotifier() {}


