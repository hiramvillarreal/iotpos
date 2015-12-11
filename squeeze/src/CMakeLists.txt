
set(squeeze_SRCS
   squeeze.cpp
   main.cpp
   squeezeview.cpp
   usersdelegate.cpp
   usereditor.cpp
   clienteditor.cpp
   promoeditor.cpp
   producteditor.cpp
   purchaseeditor.cpp
   offersdelegate.cpp
   dialogseriefolios.cpp
   subcategoryeditor.cpp
   ../../src/inputdialog.cpp
   ../../src/loginwindow.cpp
   ../../src/misc.cpp
   ../../src/hash.cpp
   ../../src/sha1.cc
   ../../src/productdelegate.cpp
   ../../dataAccess/azahar.cpp
   ../../mibitWidgets/mibitfloatpanel.cpp
   ../../mibitWidgets/mibitlineedit.cpp
   ../../mibitWidgets/mibittip.cpp
   ../../mibitWidgets/mibitnotifier.cpp
   ../../printing/print-dev.cpp
   ../../printing/print-cups.cpp
 )

kde4_add_ui_files( squeeze_SRCS
  ui/squeezeview_base.ui
  ui/prefs_base.ui
  ui/prefs_db.ui
  ui/pref_printers.ui
  ui/edituser_widget.ui
  ui/editclient_widget.ui
  ui/editpromo_widget.ui
  ui/producteditor.ui
  ui/purchaseeditor.ui
  ui/editfolios.ui
  ui/subcategoryeditor.ui
  )


kde4_add_kcfg_files(squeeze_SRCS settings.kcfgc )

kde4_add_executable(squeeze ${squeeze_SRCS})

FIND_PROGRAM(GETTEXT_MSGFMT_EXECUTABLE msgfmt)

IF(NOT GETTEXT_MSGFMT_EXECUTABLE)
        MESSAGE(
"------
                 NOTE: msgfmt not found. Translations will *not* be installed
------")
ELSE(NOT GETTEXT_MSGFMT_EXECUTABLE)

        SET(catalogname squeeze)

        ADD_CUSTOM_TARGET(translations ALL)

        FILE(GLOB PO_FILES po/*.po)

        FOREACH(_poFile ${PO_FILES})
                GET_FILENAME_COMPONENT(_lang ${_poFile} NAME_WE)
                SET(_gmoFile ${CMAKE_CURRENT_BINARY_DIR}/${_lang}.gmo)
                ADD_CUSTOM_COMMAND(TARGET translations
                        COMMAND ${GETTEXT_MSGFMT_EXECUTABLE} -o ${_gmoFile} ${_poFile}
                        DEPENDS ${_poFile})
                INSTALL(FILES ${_gmoFile} DESTINATION ${LOCALE_INSTALL_DIR}/${_lang}/LC_MESSAGES/ RENAME ${catalogname}.mo)
        ENDFOREACH(_poFile ${PO_FILES})

ENDIF(NOT GETTEXT_MSGFMT_EXECUTABLE)

target_link_libraries(squeeze
  ${KDE4_KDEUI_LIBS}
  ${KDE4_KIO_LIBS}
  ${QT_LIBRARIES}
  ${QT_QTSQL_LIBRARY}
  #${KDE4_KDEPRINT_LIBS}
)

install(TARGETS squeeze DESTINATION ${BIN_INSTALL_DIR} )

########### install files ###############

install( FILES squeeze.desktop  DESTINATION  ${XDG_APPS_INSTALL_DIR} )
install( FILES squeezeui.rc  DESTINATION  ${DATA_INSTALL_DIR}/squeeze )
install( FILES squeeze.kcfg  DESTINATION  ${KCFG_INSTALL_DIR} )
#For KNotifications
install( FILES squeeze.notifyrc DESTINATION ${DATA_INSTALL_DIR}/squeeze)

