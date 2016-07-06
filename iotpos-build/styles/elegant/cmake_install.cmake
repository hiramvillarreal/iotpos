# Install script for directory: /home/earth/iotpos/styles/elegant

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/apps/iotpos/styles/elegant/backg.png;/usr/local/share/apps/iotpos/styles/elegant/button.png;/usr/local/share/apps/iotpos/styles/elegant/button_hover.png;/usr/local/share/apps/iotpos/styles/elegant/checkbox_off.png;/usr/local/share/apps/iotpos/styles/elegant/checkbox_on.png;/usr/local/share/apps/iotpos/styles/elegant/checks_bg.png;/usr/local/share/apps/iotpos/styles/elegant/editbox.png;/usr/local/share/apps/iotpos/styles/elegant/groupbox.png;/usr/local/share/apps/iotpos/styles/elegant/headers.png;/usr/local/share/apps/iotpos/styles/elegant/headerview.png;/usr/local/share/apps/iotpos/styles/elegant/headerview_hover.png;/usr/local/share/apps/iotpos/styles/elegant/hgroupbox.png;/usr/local/share/apps/iotpos/styles/elegant/loginBackground.png;/usr/local/share/apps/iotpos/styles/elegant/loginBackground_1280x800.png;/usr/local/share/apps/iotpos/styles/elegant/loginBackground_1280x1024.png;/usr/local/share/apps/iotpos/styles/elegant/loginBackground_1024x768.png;/usr/local/share/apps/iotpos/styles/elegant/passwordBackground.png;/usr/local/share/apps/iotpos/styles/elegant/passwordBackground_wide.png;/usr/local/share/apps/iotpos/styles/elegant/radiobutton_off.png;/usr/local/share/apps/iotpos/styles/elegant/radiobutton_on.png;/usr/local/share/apps/iotpos/styles/elegant/tira.png;/usr/local/share/apps/iotpos/styles/elegant/dialog.png;/usr/local/share/apps/iotpos/styles/elegant/elegant.qss")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/usr/local/share/apps/iotpos/styles/elegant" TYPE FILE FILES
    "/home/earth/iotpos/styles/elegant/backg.png"
    "/home/earth/iotpos/styles/elegant/button.png"
    "/home/earth/iotpos/styles/elegant/button_hover.png"
    "/home/earth/iotpos/styles/elegant/checkbox_off.png"
    "/home/earth/iotpos/styles/elegant/checkbox_on.png"
    "/home/earth/iotpos/styles/elegant/checks_bg.png"
    "/home/earth/iotpos/styles/elegant/editbox.png"
    "/home/earth/iotpos/styles/elegant/groupbox.png"
    "/home/earth/iotpos/styles/elegant/headers.png"
    "/home/earth/iotpos/styles/elegant/headerview.png"
    "/home/earth/iotpos/styles/elegant/headerview_hover.png"
    "/home/earth/iotpos/styles/elegant/hgroupbox.png"
    "/home/earth/iotpos/styles/elegant/loginBackground.png"
    "/home/earth/iotpos/styles/elegant/loginBackground_1280x800.png"
    "/home/earth/iotpos/styles/elegant/loginBackground_1280x1024.png"
    "/home/earth/iotpos/styles/elegant/loginBackground_1024x768.png"
    "/home/earth/iotpos/styles/elegant/passwordBackground.png"
    "/home/earth/iotpos/styles/elegant/passwordBackground_wide.png"
    "/home/earth/iotpos/styles/elegant/radiobutton_off.png"
    "/home/earth/iotpos/styles/elegant/radiobutton_on.png"
    "/home/earth/iotpos/styles/elegant/tira.png"
    "/home/earth/iotpos/styles/elegant/dialog.png"
    "/home/earth/iotpos/styles/elegant/elegant.qss"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

