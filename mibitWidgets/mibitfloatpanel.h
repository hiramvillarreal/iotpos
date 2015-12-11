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

#ifndef MIBITFLOATPANEL_H
#define MIBITFLOATPANEL_H

#include <QSvgWidget>
class QTimeLine;
class QString;
class QHBoxLayout;
class QLabel;
class QPixmap;

/**
  * This class is used to display an animated floating panel
  * on Top, Bottom, Left or Right edges of its parent.
  * Svg themed and borderless.
  *
  * The panel content is added with the addWidget() method,
  * The simple way is to create a QWidget with all its content
  * with its layout -in designer or by code-.
  * It will be reparented automatically when added to the panel.
  * Dont forget to set the panel size according to your needs.
  *
  */


    enum PanelPosition  {Top = 1, Bottom = 2, Left = 3, Right = 4 };
    enum PanelModes     {pmAuto = 1, pmManual=2};
    enum PanelConstants {pMinH= 100, pMinW = 100 };


class MibitFloatPanel : public QSvgWidget
{
Q_OBJECT
public:
    MibitFloatPanel(QWidget *parent = 0, const QString &file = 0, PanelPosition position = Top, const int &w=100, const int &h=100);
    ~MibitFloatPanel();
    void addWidget(QWidget * widget);
    void setPosition(const PanelPosition pos);
    void setSVG(const QString &file);
    void setMaxHeight(const int &m)   { setMaximumHeight(m); maxHeight = m; reposition(); }
    void setMaxWidth(const int &m)   { setMaximumWidth(m); maxWidth = m; reposition(); }
    void setSize( const int &w, const int &h ) { setMaxHeight(h); setMaxWidth(w); }
    void setMode(const PanelModes mode) { m_mode = mode; }
    void reParent(QWidget *newparent);
    void setHiddenTotally(bool val) { m_hideTotally = val; }

private:
    QTimeLine *timeLine;
    QHBoxLayout *hLayout;
    QWidget *m_parent;
    QString m_fileName;
    bool canBeHidden;
    bool m_hideTotally;
    int maxHeight;
    int maxWidth;
    int animRate;
    PanelPosition m_position;
    PanelModes m_mode;
    int margin;
signals:
    void hiddenOnUserRequest();
public slots:
    void showPanel();
    void showPanelDelayed();
    void hidePanel() { hideDialog(); }
    void fixPos();
private slots:
    void animate(const int &step);
    void hideOnUserRequest();
    void hideDialog();
    void onAnimationFinished();
    void reposition();
protected:
    void enterEvent ( QEvent * event );
    void leaveEvent ( QEvent * event );
    void keyPressEvent ( QKeyEvent * event );
};

#endif // MIBITFLOATPANEL_H
