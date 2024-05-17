cmake_minimum_required(VERSION 3.25.0)

project(
  RefrigeratorMonitor-Src
  VERSION 3.45.3
  LANGUAGES C)

add_subdirectory(./sqlite3/)

add_library(${PROJECT_NAME} kt_utility.h db_manager.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC sqlite3)
