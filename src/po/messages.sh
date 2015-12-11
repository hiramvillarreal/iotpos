#
# NOTA: Cambiar el ejecutable de extractrc... porque agarra el de kde3 y no jala.


# invoke the extractrc script on all .ui, .rc, and .kcfg files in the sources
# the results are stored in a pseudo .cpp file to be picked up by xgettext.
#$EXTRACTRC `find . -name \*.rc -o -name \*.ui -o -name \*.kcfg` > rc.cpp
# if your application contains tips-of-the-day, call preparetips as well.
#$PREPARETIPS > tips.cpp
# call xgettext on all source files. If your sources have other filename
# extensions besides .cc, .cpp, and .h, just add them in the find call.
#$XGETTEXT `find . -name \*.cc -o -name \*.cpp -o -name \*.h` -o lemon.pot


#!/bin/sh
BASEDIR="../"   # root of translatable sources
PROJECT="lemon"  # project name
BUGADDR="http://sourceforge.net/tracker/?atid=1011570&group_id=209899&func=browse" 
WDIR=`pwd`          # working dir

#MCH needed extractrc is from /opt/kde4/bin.

echo ${PROJECT}
echo "Preparing rc files"
cd ${BASEDIR}/ui
# we use simple sorting to make sure the lines do not jump around too much from system to system
#find . -name '*.rc' -o -name '*.ui' -o -name '*.kcfg' | sort > ${WDIR}/rcfiles.list
#Note: Aug 9 2012. I only include the .ui files, since .rc and .kcfg are useless for translate.
find . -name '*.ui' | sort > ${WDIR}/rcfiles.list
xargs --arg-file=${WDIR}/rcfiles.list extractrc > ${WDIR}/extractedrc.cpp
# additional string for KAboutData
echo 'i18nc("NAME OF TRANSLATORS","Your names");' >> ${WDIR}/extractedrc.cpp
echo 'i18nc("EMAIL OF TRANSLATORS","Your emails");' >> ${WDIR}/extractedrc.cpp
cd ${WDIR}
echo "Done preparing rc files"


echo "Extracting messages"
# go for azahar strings! hard coded way
echo ${BASEDIR}../dataAccess/azahar.cpp > ${WDIR}/infiles.list


cd $WDIR
cd ${BASEDIR}
# see above on sorting
find . -name '*.cpp' -o -name '*.h' -o -name '*.c' | sort >> ${WDIR}/infiles.list
echo "extractedrc.cpp" >> ${WDIR}/infiles.list
cd ${WDIR}
xgettext --from-code=UTF-8 -C -kde -ci18n -ki18n:1 -ki18nc:1c,2 -ki18np:1,2 -ki18ncp:1c,2,3 -ktr2i18n:1 \
    -kI18N_NOOP:1 -kI18N_NOOP2:1c,2 -kaliasLocale -kki18n:1 -kki18nc:1c,2 -kki18np:1,2 -kki18ncp:1c,2,3 \
   --msgid-bugs-address="${BUGADDR}" \
     --files-from=infiles.list -D ${BASEDIR} -D ${WDIR} -o ${PROJECT}.pot || { echo "error while calling xgettext. aborting."; exit 1; }
echo "Done extracting messages"


echo "Merging translations"
catalogs=`find . -name '*.po'`
for cat in $catalogs; do
  echo $cat
  msgmerge -o $cat.new $cat ${PROJECT}.pot
  mv $cat.new $cat
done
echo "Done merging translations"


echo "Cleaning up"
cd ${WDIR}
#rm rcfiles.list
#rm infiles.list
rm extractedrc.cpp
echo "Done"
