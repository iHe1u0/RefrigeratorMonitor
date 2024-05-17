cmake_minimum_required(VERSION 3.25.0)

project(
  sqlite3
  VERSION 1.0.0
  LANGUAGES CXX C)

add_library(${PROJECT_NAME}
            sqlite3.c
            sqlite3.h
            sqlite3ext.h)