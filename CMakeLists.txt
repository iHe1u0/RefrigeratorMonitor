cmake_minimum_required(VERSION 3.25.0)

project(
  RefrigeratorMonitor
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add my source
add_subdirectory(${CMAKE_SOURCE_DIR}/src/)

# Include dir
include_directories(${CMAKE_SOURCE_DIR}/src/)
# include_directories(${CMAKE_SOURCE_DIR}/src/sqlitelib/)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES main.cpp mainwindow.cpp mainwindow.h mainwindow.ui)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(RefrigeratorMonitor MANUAL_FINALIZATION ${PROJECT_SOURCES})
else()
  add_executable(RefrigeratorMonitor ${PROJECT_SOURCES})
endif()

target_link_libraries(RefrigeratorMonitor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                                  RefrigeratorMonitor-Src)

set_target_properties(
  RefrigeratorMonitor
  PROPERTIES MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
             MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
             MACOSX_BUNDLE_SHORT_VERSION_STRING
             ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
             MACOSX_BUNDLE TRUE
             WIN32_EXECUTABLE TRUE)

install(
  TARGETS RefrigeratorMonitor
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(RefrigeratorMonitor)
endif()
