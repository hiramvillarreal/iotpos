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
 *   GNU Lesser General Public License for more details.                   *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General  Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/


#include "mibittip.h"

#include <QtGui>
#include <QTimeLine>
#include <QSize>
#include <QRect>
#include <QLabel>
#include <QPixmap>

//#include <QGraphicsSvgItem

MibitTip::MibitTip( QWidget *parent, QWidget *partner, const QString &file, const QPixmap &icon, const TipPosition &drawOn  )
    : QSvgWidget( parent )
{
    if (file != 0 ) {
        setSVG(file);
        fileName = file;
    } else fileName = "";

    //set temporal max h & w --- and predefined ones.
    maxWidth = 200;
    maxHeight= 200;
    setMaximumHeight(maxHeight);
    setMinimumHeight(0);
    setFixedHeight(0);
    //save parent and partner pointers
    m_parent = parent;
    m_partner= partner;
    m_tipPosition = drawOn;
    closedByUser = false;
    timeToLive = 4000;


    //create labels
    img    = new QLabel();
    layout = new QVBoxLayout();
    text   = new QLabel("");
    setIcon(icon);
    img->setMaximumHeight(32);
    img->setAlignment(Qt::AlignCenter);
    if ( m_tipPosition == tpAbove ) {
        layout->addWidget(text);
        layout->addWidget(img);
        // a hack... "rotated_"+
        load(fileName);
    } else {
        layout->addWidget(img);
        layout->addWidget(text);
    }

    layout->setContentsMargins(8, 8, 8, 8); //setMargin(9);
    setLayout(layout);
    text->setWordWrap(true);
    text->setMargin(5);

    timeLine = new QTimeLine(1000, this);
    timeLine->setFrameRange(0, maxHeight);
    connect(timeLine, SIGNAL(frameChanged(int)), this, SLOT(morph(int)));
}

MibitTip::~MibitTip ()
{
}

void MibitTip::showTip( const QString &msg, const int ttl)
{
    timeToLive = ttl;
    timeLine->setFrameRange(0, maxHeight);
    text->setText( msg );
    /// Warning: if a tip is showing, if another showTip() is called, it not animated, just changed the msg.
    if (timeLine->state() == QTimeLine::NotRunning && size().height() <= 0) {
        show();
        //make it grow
        timeLine->setDirection(QTimeLine::Forward);
        timeLine->start();
        //autoShrink
        QTimer::singleShot(timeToLive-1000, this, SLOT(autoHide()));
    } //else qDebug()<<"Animation running... sorry";
}

void MibitTip::morph(int newSize)
{
    //get some positions...
    QRect listRect(m_partner->rect());
    QPoint below = m_partner->mapToGlobal(listRect.bottomLeft());
    QPoint above = m_partner->mapToGlobal(listRect.topLeft());
    QPoint windowPos = m_parent->mapToGlobal(QPoint(0,0)); //the window is the parent, we assume this.

    //correct global positions with current window position.
    below = below - windowPos;
    above = above -windowPos;

    //where to draw above or below its partner
    if ( m_tipPosition == tpBelow ) { //here will grow from top to bottom
        listRect.setX(below.x()+10);
        listRect.setY(below.y()-3);
        setGeometry(listRect);
        //set fixed width and height
    } else {                        // here will grow from bottom to top and the image inverted
        //load the inverted background image
        //QGraphicsSvgItem svgItem(fileName);
        //svgItem.rotate(180);
        //QSvgRenderer *theRenderer = renderer();
        /// How to pass the rotated svg item to the renderer or QSvgWidget loader?

        int newY = above.y() - newSize + 3;
        listRect.setX(above.x()+10);
        listRect.setY(newY);
        setGeometry(listRect);
    }
    setFixedHeight(newSize);
    setFixedWidth(m_partner->width()-20);
    //qDebug()<<"New size:"<<newSize;
}

void MibitTip::autoHide()
{
    if ( !closedByUser) {
        timeLine->setDirection(QTimeLine::Backward); // timeLine->toggleDirection();  //reverse!
        timeLine->start();
    } else closedByUser = !closedByUser;
}

void MibitTip::setSVG(const QString &file)
{
    load(file); //we can load also from a Byte Array.
}

void MibitTip::setIcon(const QPixmap &icon)
{
     img->setPixmap(icon);
 }


void MibitTip::mousePressEvent ( QMouseEvent * )
{
    autoHide(); //we simply want to close the tip on any mouse click
    closedByUser = true;
}
