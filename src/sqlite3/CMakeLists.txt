cmake_minimum_required(VERSION 3.25.0)

project(
  sqlite3
  VERSION 1.0.0
  LANGUAGES CXX C)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(${PROJECT_NAME}
            sqlite3.c
            sqlite3.h
            sqlite3ext.h)
