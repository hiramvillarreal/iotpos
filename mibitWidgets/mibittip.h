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

#ifndef MIBITTIP_H
#define MIBITTIP_H

#include <QSvgWidget>

class QTimeLine;
class QVBoxLayout;
class QSize;
class QString;
class QLabel;
class QPixmap;

enum TipPosition {tpBelow, tpAbove};


/**
  * This class is used to display animated messages
  * growing or shrinking when showing/hiding.
  *
  * The concept is based on the idea of providing a less
  * intrusive message when the user needs some little information.
  * The concept is sometimes refered as "No dialogs on dialogs".
  *
  *  It loads a file in SVG format and render it as the skin.
  *  As it is an SVG, it can be scaled to any size.
  *
  *  It is resized according to its parter, and displayed
  *  horizontally centered and vertically positioned below
  *  or above its partner.
  *
  *  This was designed for lemonPOS project.
  *
  **/


class MibitTip : public QSvgWidget
{
  Q_OBJECT
  public:
    explicit MibitTip( QWidget *parent = 0,
                       QWidget *partner = 0,
                       const QString &file = 0,
                       const QPixmap &icon = 0,
                       const TipPosition &drawOn = tpBelow );
    virtual ~MibitTip();

    /**
      * This method shows a tip frame centered horizontally and on bottom of  its parter.
      * It should be parented on a bigger widget to be visible (for example the main window)
      * and also must be the same parent for the parter (must be on the same container).
      * Its partner is the widget where the tip frame will be shown on.
      *
      */
    void showTip( const QString &msg, const int ttl );
    void setSVG( const QString &file );
    void setIcon(const QPixmap &icon );
    void setMaxHeight(int h) { maxHeight = h; }
    void setMaxWidth(int w) { maxWidth = w; }
    void setSize(const int &w, const int &h) { setMaxHeight(h); setMaxWidth(w); }

  private:
    QWidget *m_parent;
    QWidget *m_partner;
    QTimeLine *timeLine;
    QLabel *text;
    QVBoxLayout *layout;
    QLabel *img;
    TipPosition m_tipPosition;
    int maxHeight;
    int maxWidth;
    QString fileName;
    bool closedByUser;
    int timeToLive;

  protected:
    void mousePressEvent ( QMouseEvent * event );

  private slots:
    void morph(int newSize);
    void autoHide();
};


#endif // MIBITTIP_H
