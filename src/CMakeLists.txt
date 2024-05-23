cmake_minimum_required(VERSION 3.25.0)

project(
  RefrigeratorMonitor-Src
  VERSION 3.45.3
  LANGUAGES C)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(./sqlite3/)

add_library(${PROJECT_NAME} kt_utility.h db_manager.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC sqlite3)
