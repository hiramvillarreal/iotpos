/***************************************************************************
 *   Copyright (C) 2013-2015 by Hiram R. Villarreal                      *
 *   hiramvillarreal.ap@gmail.com                                          *
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



#include "iotpos.h"
#include "settings.h"

#include <kapplication.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <klocale.h>
#include <kurl.h>
#include <QPixmap>
#include <ksplashscreen.h>
#include <kstandarddirs.h>

#include <QProcess>
#include <QStringList>
#include <QString>
#include <QDir>
#include <QDate>

static const char description[] =
    I18N_NOOP("IotPOS, A point of sale for linux");

static const char version[] = "0.9.6.0 | March 04, 2013";

KSplashScreen *splash;

int main(int argc, char **argv)
{
    KAboutData about("iotpos", 0, ki18n("iotpos"), version, ki18n(description), KAboutData::License_GPL, ki18n("(C) 2007-2011 Miguel Chavez Gamboa"), KLocalizedString(), 0, "miguel@iotpospos.org");
    about.addAuthor( ki18n("Miguel Chavez Gamboa"), KLocalizedString(), "miguel@iotpospos.org" );
    about.setBugAddress("bugs.iotpos@iotpospos.org");
    KCmdLineArgs::init(argc, argv, &about);

    about.addCredit(ki18n("Biel Frontera"), ki18n("Code contributor"));
    about.addCredit(ki18n("Vitali Kari"), ki18n("Code contributor"));
    about.addCredit(ki18n("Jose Nivar"), ki18n("Many ideas, bug reports and testing"));
    about.addCredit(ki18n("Roberto Aceves"), ki18n("Many ideas and general help"));
    about.addCredit(ki18n("Benjamin Burt"), ki18n("Many ideas, Documentation Writer, How-to Videos Creation, and general help and support"));
    
    KCmdLineOptions options;
    //options.add("+[URL]", ki18n( "Document to open" ));
    KCmdLineArgs::addCmdLineOptions(options);
    KApplication app;

    // register ourselves as a dcop client
    //app.dcopClient()->registerAs(app.name(), false);

    // see if we are starting with session management
    if (app.isSessionRestored())
        RESTORE(iotpos)
    else
    {
        // no session.. just start up normally
        KCmdLineArgs *args = KCmdLineArgs::parsedArgs();
        if (args->count() == 0)
        {
            QPixmap image (KStandardDirs().findResource("data", "iotpos/images/splash_screen.png"));
            splash = new KSplashScreen(image, Qt::WindowStaysOnTopHint);
            splash->show();

  /*         //NOTE: Is this the best place to launch the backup process?
     //       QString fn = QString("%1/iotpos-backup/").arg(QDir::homePath());
    //        QDir dir;
    //        if (!dir.exists(fn))
    //            dir.mkdir(fn);
     //       fn = fn+QString("iotpos-db--backup.sql");//.arg(QDateTime::currentDateTime().toString("dd-MMM-yyyy__hh.mm.AP"));
            qDebug()<<"BACKUP DATABASE at " << fn;
            
            QStringList params;
            QString pswd = "-p" + Settings::editDBPassword();
            QString usr  = "-u" + Settings::editDBUsername();
            QString hst  = "-h" + Settings::editDBServer();
            QString dnm  = Settings::editDBName();
            QString fnm  = "-r" + fn;
            params << hst << usr << pswd << fnm << dnm;
            QProcess mysqldump;
            mysqldump.start("mysqldump", params);
            mysqldump.waitForFinished();
            //NOTE: The process above does not consider an error (network, mysql config, wrong password/user, etc..) and does not inform such if it happens.
            //      It just gives an empty backup file. But once everything is working fine, it will give a backup every day.
            //QProcess process;
            //process.startDetached("/bin/sh", QStringList()<< "/home/pi/iotpos/scripts/dropbox.sh");*/
            iotpos *widget = new iotpos;
            widget->show();
          //  widget->hide();
            widget->show();
            splash->finish(widget);
        }
        else
        {
            int i = 0;
            for (; i < args->count(); i++)
            {
                iotpos *widget = new iotpos;
                widget->show();
             //   widget->hide();
             //   widget->show();
                qDebug()<<"iotpos "<<i;
            }
        }
        args->clear();
    }

    return app.exec();
}
