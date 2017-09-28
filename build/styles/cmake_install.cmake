# Install script for directory: /home/earth/iotpos/styles

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
   "/usr/share/kde4/apps/iotpos/styles/tip.svg;/usr/share/kde4/apps/iotpos/styles/rotated_tip.svg;/usr/share/kde4/apps/iotpos/styles/floating_bottom.svg;/usr/share/kde4/apps/iotpos/styles/floating_top.svg;/usr/share/kde4/apps/iotpos/styles/panel_top_big.svg;/usr/share/kde4/apps/iotpos/styles/dialog.svg")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/share/kde4/apps/iotpos/styles" TYPE FILE FILES
    "/home/earth/iotpos/styles/tip.svg"
    "/home/earth/iotpos/styles/rotated_tip.svg"
    "/home/earth/iotpos/styles/floating_bottom.svg"
    "/home/earth/iotpos/styles/floating_top.svg"
    "/home/earth/iotpos/styles/panel_top_big.svg"
    "/home/earth/iotpos/styles/dialog.svg"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/earth/iotpos/build/styles/simple/cmake_install.cmake")
  include("/home/earth/iotpos/build/styles/elegant/cmake_install.cmake")

endif()

