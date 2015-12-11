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

#include "mibitfloatpanel.h"

#include <QPixmap>
#include <QString>
#include <QHBoxLayout>
#include <QTimeLine>
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>

MibitFloatPanel::MibitFloatPanel(QWidget *parent, const QString &file, PanelPosition position, const int &w, const int &h)
        : QSvgWidget( parent )
{
    //setMouseTracking(true);
    m_hideTotally = false;
    margin  = 7;

    if (file != 0) setSVG(file);

    m_position = position;
    m_mode     = pmAuto;
    m_parent = parent;
    m_fileName = file;
    canBeHidden = false; //at the begining is hidden.
    setMinimumHeight(h);
    setMinimumWidth(w);
    setMaxHeight(h);
    setMaxWidth(w);
    setFixedHeight(0);
    animRate = 500; //default animation speed (half a second rate).

    hLayout    = new QHBoxLayout();
    setLayout(hLayout);

    //Postition it on its place
    QTimer::singleShot(100,this,SLOT(reposition()));

    timeLine  = new QTimeLine(animRate, this);
    connect(timeLine, SIGNAL(frameChanged(int)), this, SLOT(animate(int)));
    connect(timeLine,SIGNAL(finished()), this, SLOT(onAnimationFinished()));
}

void MibitFloatPanel::reposition()
{
    QRect windowGeom = m_parent->geometry();
    int midPointX = (windowGeom.width()/2);
    int midPointY = (windowGeom.height()/2);
    int newX; int newY;
    QRect dRect;
    if ((midPointX-(maxWidth/2)) < 0) newX = 0; else newX = midPointX - (maxWidth/2);
    if ((midPointY-(maxHeight/2)) < 0) newY = 0; else newY = midPointY - (maxHeight/2);

    //qDebug()<<"parent geometry:"<<windowGeom;

    switch (m_position) {
        case Top:
            newY = margin-maxHeight;
        break;
        case Bottom:
            newY = m_parent->height()+height()-margin;
        break;
        case Left:
            newX = margin-maxWidth;
        break;
        case Right:
            newX = m_parent->width()-margin;
        break;
    }

    dRect.setX(newX);
    dRect.setY(newY);
    setFixedWidth(maxWidth); //width maybe is not yet defined.
    setFixedHeight(maxHeight);
    setGeometry(dRect);
}

void MibitFloatPanel::addWidget(QWidget * widget)
{
    hLayout->addWidget(widget, 1, Qt::AlignCenter);
}

void MibitFloatPanel::showPanel()
{
    if (timeLine->state() == QTimeLine::NotRunning && !canBeHidden) {
        setGeometry(-1000,-1000,0,0);
        show();
        //update steps for animation, now that the panel is showing.
        int maxStep = 0, minStep = 0;

        switch (m_position) {
            case Top :
                minStep = -maxHeight+margin;
                maxStep =  -6;
            break;
            case Bottom:
                maxStep = m_parent->geometry().height()-maxHeight;
                minStep = m_parent->geometry().height()-margin;
            break;
            case Left:
                minStep = -maxWidth+margin;
                maxStep = -6;
            break;
            case Right:
                minStep = m_parent->geometry().width()-margin;
                maxStep = m_parent->geometry().width()-maxWidth;
            break;
            default:
            break;
        }

        timeLine->setFrameRange(minStep,maxStep);
        //make it grow
        timeLine->setDirection(QTimeLine::Forward);
        timeLine->start();
    } 
}

void MibitFloatPanel::animate(const int &step)
{
    //get some sizes...
    QRect windowGeom = m_parent->geometry();
    int midPointX = (windowGeom.width()/2);
    int midPointY = (windowGeom.height()/2);
    int newX;  int newY;
    QRect dRect;
    if ((midPointX-(maxWidth/2)) < 0) newX = 0; else newX = midPointX - (maxWidth/2);
    if ((midPointY-(maxHeight/2)) < 0) newY = 0; else newY = midPointY - (maxHeight/2);


    switch (m_position) {
        case Bottom:
        case Top:
            dRect.setX(newX);
            dRect.setY(step);
        break;
        case Left:
        case Right:
            dRect.setY(newY);
            dRect.setX(step);
        break;
        default:
        break;
    }

    dRect.setWidth(maxWidth);
    dRect.setHeight(maxHeight);
    setGeometry(dRect);
    setFixedHeight(maxHeight);
    setFixedWidth(maxWidth);
}

void MibitFloatPanel::hideOnUserRequest()
{
    hideDialog();
    emit hiddenOnUserRequest();
}

void MibitFloatPanel::hideDialog()
{
    if ( canBeHidden ) {
        timeLine->setDirection(QTimeLine::Backward); //reverse!
        timeLine->start();
    }
}

void MibitFloatPanel::onAnimationFinished()
{
    if (timeLine->direction() == QTimeLine::Forward) {
        canBeHidden = true;
    } else { //Backward
        canBeHidden = false;
        if (m_hideTotally) hide();
    }
}

void MibitFloatPanel::setPosition(const PanelPosition pos)
{
    // only changes the position when the notification is not showing..
    if (timeLine->state() == QTimeLine::NotRunning && !canBeHidden) {
        m_position = pos;
        //recalculate its rect and show it there...
        reposition();
    }
}


//NOTE: The svg file is not rendered correctly. It does not render the blur, i.e. the shadows
void MibitFloatPanel::setSVG(const QString &file)
{
    load(file);
}


void MibitFloatPanel::enterEvent ( QEvent * )
{
    if (m_mode == pmAuto) QTimer::singleShot(300,this,SLOT(showPanelDelayed()));
}

//This is to delay the panel showing, for those inconvenient times where you dont want to
//get the floatingpanel to appear because you are only passing above the 10pixes of the panel
//to arrive to another widget.
void MibitFloatPanel::showPanelDelayed()
{
    if (underMouse()) {
        QTimer::singleShot(100,this,SLOT(showPanel()));
    }
}

void MibitFloatPanel::leaveEvent( QEvent * )
{
    if (m_mode == pmAuto) QTimer::singleShot(100,this,SLOT(hideOnUserRequest()));
}

void MibitFloatPanel::keyPressEvent ( QKeyEvent * event )
{
    if ( event->key() == Qt::Key_Escape )
    {
        if (m_mode == pmManual)
        hideOnUserRequest();
    } //else ignore event.
}

void MibitFloatPanel::reParent(QWidget *newparent)
{
  setParent(newparent);
  m_parent = newparent;
  //update
  reposition();
}

//HACK:
//This is to fix position, the bad position is because when positioned if
//the parent is not showing, the parent size is small (100,30).
//Calling this method when the parent is showing ensures the position is correct.
void MibitFloatPanel::fixPos()
{
    hide();
    reposition();
    QTimer::singleShot(100, this, SLOT(show()));
}

MibitFloatPanel::~MibitFloatPanel() {}


