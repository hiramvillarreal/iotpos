/**************************************************************************
*   Copyright © 2007-2011 by Miguel Chavez Gamboa                         *
*   miguel@lemonpos.org                                                   *
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
#ifndef PROVIDERSEDITOR_H
#define PROVIDERSEDITOR_H

#include <KDialog>
#include <QDate>
#include <QtGui>
#include <QPixmap>
#include <QtSql>

#include "ui_providerseditor.h"

class MibitFloatPanel;
class MibitTip;
#include "../../src/structs.h"

class ProvidersEditorUI : public QFrame, public Ui::providersEditor
{
  Q_OBJECT
  public:
    ProvidersEditorUI( QWidget *parent=0 );
};

class ProvidersEditor : public KDialog
{
  Q_OBJECT
  public:
    ProvidersEditor( QWidget *parent=0, bool newProvider = false, const QSqlDatabase& database=QSqlDatabase() );
    ~ProvidersEditor();

    ProviderInfo getProviderInfo() { return m_pInfo; };
    void    setDb(QSqlDatabase database);
    void    setProviderId(qulonglong id);
    
private slots:
    void    addItem();
    void    removeItem();
    void    setupModel();
    void    checkFieldsState();
  protected slots:
    virtual void slotButtonClicked(int button);
  private:
    ProvidersEditorUI *ui;
    QSqlDatabase db;
    ProviderInfo m_pInfo;
    MibitFloatPanel *panel;
    QSqlRelationalTableModel *m_model, *m_model2;
    bool modelCreated;
};

#endif
