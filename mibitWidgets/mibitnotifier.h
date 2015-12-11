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

#ifndef MIBITNOTIFIER_H
#define MIBITNOTIFIER_H

#include <QSvgWidget>
class QTimeLine;
class QString;
class QHBoxLayout;
class QLabel;
class QPixmap;

/**
  * This class is used to display animated notifications appering on parent
  * top or bottom. Are svg themed and borderless.
  *
  */

enum sizes { max_H=200, max_W=400, min_W=300, min_H=100 };

class MibitNotifier : public QSvgWidget
{
Q_OBJECT
public:
    MibitNotifier(QWidget *parent = 0, const QString &file = 0, const QPixmap &icon = 0, const bool &onTop= true);
    ~MibitNotifier();
    void showNotification( const QString &msg = 0, const int &timeToLive = 0); //timeToLive = 0 : not auto hide it.
    void setOnBottom(const bool &sOnBottom = true);
    void setSVG(const QString &file);
    void setIcon(const QPixmap &icon);
    void setMessage(const QString &msg);
    void setTextColor(const QString &color);
    void setMaxHeight(const int &m)   { setMaximumHeight(m); maxHeight = m; }
    void setMaxWidth(const int &m)   { setMaximumWidth(m); maxWidth = m; }
    void setSize( const int &w, const int &h ) { setMaxHeight(h); setMaxWidth(w); }
private:
    QTimeLine *timeLine;
    QLabel *message;
    QHBoxLayout *hLayout;
    QLabel *img;
    QWidget *m_parent;
    QString m_fileName;
    bool m_canClose;
    bool m_onTop;
    int maxHeight;
    int maxWidth;
    int animRate;
private slots:
    void animate(const int &step);
    void hideDialog();
    void hideOnUserRequest();
    void onAnimationFinished();
protected:
    void mousePressEvent ( QMouseEvent * event );
};

#endif // MIBITNOTIFIER_H
