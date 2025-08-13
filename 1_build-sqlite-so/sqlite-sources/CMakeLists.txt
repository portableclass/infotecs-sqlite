cmake_minimum_required(VERSION 3.10)
project(SQLiteBuild LANGUAGES C)

set(SOURCES sqlite3.c)
add_library(sqlite3 SHARED ${SOURCES})

# MSVC
if(MSVC)
  target_compile_definitions(sqlite3 PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
