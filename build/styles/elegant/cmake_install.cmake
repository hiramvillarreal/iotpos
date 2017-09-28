# Install script for directory: /home/earth/iotpos/styles/elegant

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/share/kde4/apps/iotpos/styles/elegant/backg.png;/usr/share/kde4/apps/iotpos/styles/elegant/button.png;/usr/share/kde4/apps/iotpos/styles/elegant/button_hover.png;/usr/share/kde4/apps/iotpos/styles/elegant/checkbox_off.png;/usr/share/kde4/apps/iotpos/styles/elegant/checkbox_on.png;/usr/share/kde4/apps/iotpos/styles/elegant/checks_bg.png;/usr/share/kde4/apps/iotpos/styles/elegant/editbox.png;/usr/share/kde4/apps/iotpos/styles/elegant/groupbox.png;/usr/share/kde4/apps/iotpos/styles/elegant/headers.png;/usr/share/kde4/apps/iotpos/styles/elegant/headerview.png;/usr/share/kde4/apps/iotpos/styles/elegant/headerview_hover.png;/usr/share/kde4/apps/iotpos/styles/elegant/hgroupbox.png;/usr/share/kde4/apps/iotpos/styles/elegant/loginBackground.png;/usr/share/kde4/apps/iotpos/styles/elegant/loginBackground_1280x800.png;/usr/share/kde4/apps/iotpos/styles/elegant/loginBackground_1280x1024.png;/usr/share/kde4/apps/iotpos/styles/elegant/loginBackground_1024x768.png;/usr/share/kde4/apps/iotpos/styles/elegant/passwordBackground.png;/usr/share/kde4/apps/iotpos/styles/elegant/passwordBackground_wide.png;/usr/share/kde4/apps/iotpos/styles/elegant/radiobutton_off.png;/usr/share/kde4/apps/iotpos/styles/elegant/radiobutton_on.png;/usr/share/kde4/apps/iotpos/styles/elegant/tira.png;/usr/share/kde4/apps/iotpos/styles/elegant/dialog.png;/usr/share/kde4/apps/iotpos/styles/elegant/elegant.qss")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/share/kde4/apps/iotpos/styles/elegant" TYPE FILE FILES
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
endif()

