/***************************************************************************
 *   Copyright (C) 2009 by Miguel Chavez Gamboa                            *
 *   miguel@lemonpos.org                                                   *
 *                                                                         *
 *   This is based on the KLineEdit class                                  *
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

#include "mibitlineedit.h"

#include <QtGui>
#include <QTimer>

MibitLineEdit::MibitLineEdit( QWidget *parent )
    : QLineEdit( parent )
{
  qDebug()<<"creating MibitLineEdit";
    drawEmptyMsg = false;
    actualColor  = 0;
    timer = new QTimer(this);
    shakeTimeToLive = 0;
    par = false; parTimes = 0;

    shakeTimer = new QTimer(this);
    shakeTimer->setInterval(20);
    timer->setInterval(30);
    emptyMessage = "Type here..."; //what about localization?
    connect(this, SIGNAL(textEdited( const QString & ) ), SLOT(onTextChange(const QString &)) );
    connect(timer, SIGNAL(timeout()), this, SLOT(stepColors()));
    connect(shakeTimer,SIGNAL(timeout()), this, SLOT(shakeIt()));
}

MibitLineEdit::~MibitLineEdit ()
{
}

QString MibitLineEdit::getEmptyMessage() const
{
    return emptyMessage;
}

void MibitLineEdit::setEmptyMessage( const QString &msg )
{
    emptyMessage = msg;
    drawEmptyMsg = text().isEmpty();
    update();
}

void MibitLineEdit::paintEvent( QPaintEvent *ev )
{
    QLineEdit::paintEvent( ev );

    if ( text().isEmpty() ) {
        QPainter p(this);
        QFont f = font();
        f.setItalic(true);
        p.setFont(f);

        QColor color(palette().color(foregroundRole()));
        color.setAlphaF(0.5);
        p.setPen(color);

        //FIXME: fugly alert!
        // qlineedit uses an internal qstyleoption set to figure this out
        // and then adds a hardcoded 2 pixel interior to that.
        // probably requires fixes to Qt itself to do this cleanly
        // see define horizontalMargin 2 in qlineedit.cpp
        QStyleOptionFrame opt;
        initStyleOption(&opt);
        QRect cr = style()->subElementRect(QStyle::SE_LineEditContents, &opt, this);
        cr.setLeft(cr.left() + 2);
        cr.setRight(cr.right() - 2);

        p.drawText(cr, Qt::AlignLeft|Qt::AlignVCenter, emptyMessage);
    }
}


void MibitLineEdit::setError( const QString& msg )
    {
        timer->start(); //timer for colors
        //set tooltip
        setToolTip(msg);
        if (autoClear) {
            //create a timer to clear the error.
            QTimer::singleShot(5000,this,SLOT(clearError()));
        }
    }

void MibitLineEdit::stepColors()
{
    if (actualColor > 199) {
        actualColor=0;
        timer->stop();
        return;
    } else {
        actualColor=actualColor+2;
    }
    setStyleSheet(QString(" QLineEdit { background: rgb(255,%1,0); color:white; font-weight: bold;}").arg(actualColor));
}

void MibitLineEdit::clearError( )
    {
        timer->stop(); //disable timer to disable stepColors.
        setStyleSheet("");
        setToolTip("");
    }

///This function needs to be called before the setError() one... to enable the Qtimer::singleShot
void MibitLineEdit::setAutoClearError( const bool& state )
    {
        autoClear = state;
    }

void MibitLineEdit::onTextChange(const QString &)
{
    //clear the error
    clearError();
}

void MibitLineEdit::focusInEvent( QFocusEvent *ev )
{
    if ( drawEmptyMsg )
    {
        drawEmptyMsg = false;
        update();
    }
    QLineEdit::focusInEvent( ev );
}

void MibitLineEdit::focusOutEvent( QFocusEvent *ev )
{
    if ( text().isEmpty() )
    {
        drawEmptyMsg = true;
        update();
    }
    QLineEdit::focusOutEvent( ev );
}

void MibitLineEdit::keyPressEvent ( QKeyEvent * event )
{
  // Check for our special keys +,Enter (specific for lemonPOS)
  // The Enter key is the one located at the numeric pad. The other is called RETURN.
  if ( event->key() == Qt::Key_Plus || event->key() == Qt::Key_Enter )
      emit plusKeyPressed();
  //anyway we must send enter and + key events...
  QLineEdit::keyPressEvent(event);
}


void MibitLineEdit::shake()
{
    shakeTimer->start();
    QTimer::singleShot(3000,shakeTimer,SLOT(stop()));
}

void MibitLineEdit::shakeIt()
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
