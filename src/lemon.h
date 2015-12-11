/***************************************************************************
 *   Copyright (C) 2007-2009 by Miguel Chavez Gamboa                  *
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
#ifndef LEMON_H
#define LEMON_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <kxmlguiwindow.h>

#include "ui_prefs_base.h"
#include "ui_store_data.h"
#include "ui_prefs_db.h"
#include "ui_pref_style.h"
#include "ui_pref_security.h"
#include "ui_pref_printers.h"
#include "ui_facturas_data.h"

class lemonView;

/**
 * This class serves as the main window for lemon.  It handles the
 * menus, toolbars, and status bars.
 *
 * @short Main window class
 * @author Miguel Chavez Gamboa <miguel.chavez.gamboa@gmail.com>
 * @version 2007.11
 */
class lemon : public KXmlGuiWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    lemon();

    /**
     * Default Destructor
     */
    virtual ~lemon();

public Q_SLOTS:
    // DBus interface

protected:
    /**
     *  Method to load the users file into the configuration widget's list
         */
    void populateUsersList();

    /**
     * Method used to populate available styles in the configuration list...
     */
    void populateStyleList();


private slots:
    /**
     *  Slot used to launching the preferences dialog.
         */
    void optionsPreferences();
    /**
     * Slot used to changing the mainwindow's status bar
     */
    void changeStatusbar(const QString& text);
    /**
     * Slot used to changing the mainwindows's caption text
     */
    void changeCaption(const QString& text);
    /**
     * Slot used to disable the UI (kposview_base widget)
     */
    void disableUi();
    void disableLogin();
    /**
     * Slot used to enable the UI (kposview_base widget)
     */
    void enableUi();
    void enableLogin();
    /**
     * Slot used to disable the Preferences action
     */
    void disableConfig();
    /**
     * Slot used to enable the Preferences action
     */
    void enableConfig();
    /**
     * Slot used to get selected style from the configuration list...
     */
    void sLitemActivated(QListWidgetItem *item);
    /**
     * SLot used to update the clock on status bar
     */
    void updateClock();
    /**
     * Slot used to update the username on the statusbar
     */
    void updateUserName();
    /**
     * Slot used to update the date on the statusbar
     */
    void updateDate();
    /**
     * Slot used to update transaction label
     */
    void updateTransaction();
    /**
     * Slot used to hide the mainMenu
     */
    void hideMenuBar();
    /**
     * Slot used to quit the application by the admin user.
     */
    void salir();
    /**
     * Slot used to hide the toolbars...
     */
    void hideToolBars();
    void showToolBars();
    /**
     * Slot used to check if the ui can be enabled
     **/
    void reactOnLogOn();
    void reactOnStartedOp();
    void loadStyle();
    void triggerGridAction();

    void showDBConfigDialog();

    void enableStartOp();
    void disableStartOp();

private:
    void setupActions();

private:
    Ui::prefs_base  ui_prefs_base ;
    Ui::store_data ui_store_data;
    Ui::prefs_db ui_prefs_db;
    Ui::pref_style ui_pref_style;
    Ui::pref_security ui_pref_security;
    Ui::pref_printers ui_pref_printers;
    Ui::facturas_data ui_facturas_data;

    lemonView *m_view;
    QLabel *labelUserInfo;
    QLabel *labelDate;
    QLabel *labelTime;
    QLabel *labelTransaction;
protected:
    bool queryClose();
};

#endif // LEMON_H
