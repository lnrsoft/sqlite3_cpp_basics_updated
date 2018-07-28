QT -= gui

CONFIG += c++1z console

CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    01_openDB.cpp \
    02_sqlite3_create_table.cpp \
    03_sqlite3_insert.cpp \
    04_sqlite3_select_operation.cpp \
    05_sqlite3_update_operation.cpp \
    06_sqlite3_delete_operation.cpp

LIBS += -lsqlite3
