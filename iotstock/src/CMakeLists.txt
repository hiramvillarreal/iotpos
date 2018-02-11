
set(iotstock_SRCS
   iotstock.cpp
   main.cpp
   iotstockview.cpp
   usersdelegate.cpp
   usereditor.cpp
   clienteditor.cpp
   promoeditor.cpp
   producteditor.cpp
   purchaseeditor.cpp
   offersdelegate.cpp
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

kde4_add_ui_files( iotstock_SRCS
  ui/iotstockview_base.ui
  ui/prefs_base.ui
  ui/prefs_db.ui
  ui/pref_printers.ui
  ui/edituser_widget.ui
  ui/editclient_widget.ui
  ui/editpromo_widget.ui
  ui/producteditor.ui
  ui/purchaseeditor.ui
  ui/subcategoryeditor.ui
  )


kde4_add_kcfg_files(iotstock_SRCS settings.kcfgc )

kde4_add_executable(iotstock ${iotstock_SRCS})

FIND_PROGRAM(GETTEXT_MSGFMT_EXECUTABLE msgfmt)

IF(NOT GETTEXT_MSGFMT_EXECUTABLE)
        MESSAGE(
"------
                 NOTE: msgfmt not found. Translations will *not* be installed
------")
ELSE(NOT GETTEXT_MSGFMT_EXECUTABLE)

        SET(catalogname iotstock)

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

target_link_libraries(iotstock
  ${KDE4_KDEUI_LIBS}
  ${KDE4_KIO_LIBS}
  ${QT_LIBRARIES}
  ${QT_QTSQL_LIBRARY}
  #${KDE4_KDEPRINT_LIBS}
)

install(TARGETS iotstock DESTINATION ${BIN_INSTALL_DIR} )

########### install files ###############

install( FILES iotstock.desktop  DESTINATION  ${XDG_APPS_INSTALL_DIR} )
install( FILES iotstockui.rc  DESTINATION  ${DATA_INSTALL_DIR}/iotstock )
install( FILES iotstock.kcfg  DESTINATION  ${KCFG_INSTALL_DIR} )
#For KNotifications
install( FILES iotstock.notifyrc DESTINATION ${DATA_INSTALL_DIR}/iotstock)

