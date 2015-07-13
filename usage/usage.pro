TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -Wno-unused-local-typedefs

SOURCES += main.cpp

include(../headers.pro)

