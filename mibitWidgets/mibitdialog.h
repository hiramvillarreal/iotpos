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

#ifndef MIBITDIALOG_H
#define MIBITDIALOG_H

#include <QSvgWidget>
class QTimeLine;
class QString;
class QHBoxLayout;
class QVBoxLayout;
class QLabel;
class QPixmap;
class QPushButton;

/**
  * This class is used to display animated dialogs appering on screen's
  * top or middle. Are svg themed and borderless.
  * It can also shake it or wave it to take user's attention.
  *
  * The animation types are four:
  *   atGrowCenterV: This makes the dialog appear growing from the center in the Y axe.
  *   atGrowCenterH: This makes the dialog appear growing from the center in the X axe.
  *   atSlideDown:   This makes the dialog appear sliding down from the top of its parent.
  *   atSlideUp:     This makes the dialog appear sliding up from the bottom of its parent.
  *
  *
  */

enum AnimationType { atGrowCenterV=1, atGrowCenterH=2, atSlideDown=3, atSlideUp=4 };
enum Sizes         { maxH=300, maxW=400 };

class MibitDialog : public QSvgWidget
{
Q_OBJECT
public:
    MibitDialog(QWidget *parent = 0, const QString &msg = 0, const QString &file = 0, const QPixmap &icon = 0, AnimationType animation = atSlideDown );
    ~MibitDialog();
    void showDialog( const QString &msg = 0, AnimationType animation = atSlideDown );
    // Tratar de hacer un metodo similar al QDialog::getDouble()... con static
    void setSVG(const QString &file);
    void setIcon(const QPixmap &icon);
    void setMessage(const QString &msg);
    void setTextColor(const QString &color);

    void setAnimationType(const AnimationType &atype) { animType = atype; }
    void setAnimationRate(const int &r) { animRate = r; }
    void setMaxHeight(const int &m)   { setMaximumHeight(m); maxHeight = m; }
    void setMaxWidth(const int &m)    { setMaximumWidth(m); maxWidth = m;   }
    void setSize(const int &w, const int &h) { setMaxWidth(w); setMaxHeight(h);    }
    void setShakeTTL(const int &timeToLive = 0){ shakeTimeToLive = timeToLive;} //timeToLive = 0 means shake until closed.
private:
    QTimeLine *timeLine;
    QTimeLine *wTimeLine;
    QTimer *shakeTimer;
    QLabel *text;
    QLabel *title;
    //QLabel *btn; //we will paint the close icon.
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;
    QLabel *img;
    QPushButton *btnClose;
    AnimationType animType;
    QWidget *m_parent;
    int maxWidth;
    int maxHeight;
    int animRate;
    int shakeTimeToLive;
    bool par;
    unsigned int parTimes;

private slots:
    void animate(const int &step);
    void shakeIt();
    void waveIt(const int &step);
    void hideDialog();
    void onAnimationFinished();
public slots:
    void shake();
    void wave();
protected:
    void keyPressEvent ( QKeyEvent * event );

};

#endif // MIBITDIALOG_H
