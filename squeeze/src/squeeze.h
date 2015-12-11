/***************************************************************************
 *   Copyright (C) 2007-2009 by Miguel Chavez Gamboa                       *
 *   miguel.chavez.gamboa@gmail.com                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *

 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#ifndef SQUEEZE_H
#define SQUEEZE_H

#include "ui_prefs_base.h"
#include "ui_prefs_db.h"
#include "ui_pref_printers.h"

#include <kxmlguiwindow.h>

#include <QDragEnterEvent>
#include <QDropEvent>

class KLed;
class KToggleAction;
class squeezeView;
class QPrinter;
class QTimer;


/**
 * This class serves as the main window for squeeze.  It handles the
 * menus, toolbars, and status bars.
 *
 * @short Main window class
 * @author Miguel Chavez Gamboa <miguel.chavez.gamboa@gmail.com>
 * @version 0.1
 */
class squeeze : public KXmlGuiWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    squeeze();

    /**
     * Default Destructor
     */
    virtual ~squeeze();


//public Q_SLOTS:

private slots:
    void optionsPreferences();
    void changeCaption(const QString& text);
    void changeStatusbar(const QString& text);

    void setConnection(bool yes);
    void setConnected();
    void setDisconnected();
    void enableUI();
    void disableUI();
    void salir();
    void loadStyle();
    void showDBConfigDialog();
    void fixGeom();

private:
    void setupActions();

private:
    squeezeView *m_view;
    Ui::prefs_base ui_prefs_base ;
    Ui::prefs_db ui_prefs_db;
    Ui::pref_printers ui_pref_printers;
    
    KLed *led;
    QTimer *timer;

    QPrinter   *m_printer;

  protected:
    bool queryClose();
};

#endif // SQUEEZE_H
