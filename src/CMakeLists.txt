#MCH: Deshabilitar debug (para alivianar el ejecutable).
#     cmake -DCMAKE_BUILD_TYPE=release -DCMAKE_INSTALL_PREFIX=/opt/kde4

set(iotpos_SRCS
   iotpos.cpp
   main.cpp
   iotposview.cpp
   sha1.cc
   hash.cpp
   gaveta.cpp
   inputdialog.cpp
   loginwindow.cpp
   productdelegate.cpp
   misc.cpp
   specialordereditor.cpp
   ../dataAccess/azahar.cpp
   pricechecker.cpp
   ticketpopup.cpp
   ../printing/print-dev.cpp
   ../printing/print-cups.cpp
   ../mibitWidgets/mibitfloatpanel.cpp
   ../mibitWidgets/mibitlineedit.cpp
   ../mibitWidgets/mibittip.cpp
   ../mibitWidgets/mibitpassworddlg.cpp
   ../mibitWidgets/mibitnotifier.cpp
   soselector.cpp
   sostatus.cpp
   resume.cpp
   reservations.cpp
   saleqtydelegate.cpp
   dialogclientdata.cpp
   ../iotstock/src/clienteditor.cpp
   bundlelist.cpp
   #printers/sp500.cpp
   BasketPriceCalculationService.cpp
   nouns/BasketEntryPriceSummary.cpp
   nouns/BasketPriceSummary.cpp
   nouns/User.cpp
   nouns/Currency.cpp
 )

#qt4_add_dbus_adaptor(iotpos_SRCS org.kde.iotpos.iotpos.xml iotpos.h iotpos)


kde4_add_ui_files( iotpos_SRCS
  ui/mainview.ui
  ui/prefs_base.ui
  ui/pref_printers.ui
  ui/store_data.ui
  ui/prefs_db.ui
  ui/pref_style.ui
  ui/pref_security.ui
  ui/special_order.ui
  ui/soselector.ui
  ui/sostatus.ui
  ui/resume.ui
  ui/reservations.ui
  ui/checker.ui
  ui/datoscliente.ui
  ../iotstock/src/ui/editclient_widget.ui
  )

kde4_add_kcfg_files(iotpos_SRCS settings.kcfgc )

kde4_add_executable(iotpos ${iotpos_SRCS})

target_link_libraries(iotpos
  ${KDE4_KDEUI_LIBS}
  ${KDE4_KIO_LIBS}
  ${QT_LIBRARIES}
  ${QT_QTSQL_LIBRARY}
)

FIND_PROGRAM(GETTEXT_MSGFMT_EXECUTABLE msgfmt)

IF(NOT GETTEXT_MSGFMT_EXECUTABLE)
        MESSAGE(
"------
                 NOTE: msgfmt not found. Translations will *not* be installed
------")
ELSE(NOT GETTEXT_MSGFMT_EXECUTABLE)

        SET(catalogname iotpos)

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

install(TARGETS iotpos DESTINATION ${BIN_INSTALL_DIR} )

##### client #####
#set(iotpos_client_SRCS
#    iotpos_client.cpp
# )
#kde4_add_executable(iotpos_client ${iotpos_client_SRCS})
#target_link_libraries(iotpos_client ${KDE4_KDECORE_LIBS})
#install(TARGETS iotpos_client DESTINATION ${BIN_INSTALL_DIR} )

########### install files ###############

install( FILES iotpos.desktop  DESTINATION  ${XDG_APPS_INSTALL_DIR} )
install( FILES iotposui.rc     DESTINATION  ${DATA_INSTALL_DIR}/iotpos )
# With next line... the user needs to read/write the file...
install( FILES iotposrc        DESTINATION  ${CONFIG_INSTALL_DIR} )
#install( FILES iotposrc        DESTINATION  ${HOME}/.kde/share/config/ )
install( FILES iotpos.kcfg     DESTINATION  ${KCFG_INSTALL_DIR} )
#For KNotifications
install( FILES iotpos.notifyrc DESTINATION ${DATA_INSTALL_DIR}/iotpos)

