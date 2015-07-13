TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -Wno-unused-local-typedefs

PRODUCT=../Product

GMOCK_DIR = D:/gmock-1.6.0
GTEST_DIR = $$GMOCK_DIR/gtest

INCLUDEPATH += $$GMOCK_DIR/include
INCLUDEPATH += $$GTEST_DIR/include
INCLUDEPATH += $$GMOCK_DIR
INCLUDEPATH += $$GTEST_DIR

include(../headers.pro)

SOURCES += \
   $$GTEST_DIR/src/gtest-all.cc \
   $$GMOCK_DIR/src/gmock-all.cc \
   $$GMOCK_DIR/src/gmock_main.cc \
    sometest.cpp

HEADERS += example.hpp
HEADERS += constexprvalue.hpp
HEADERS += constructordestructormock.hpp

GTEST_HEADERS += $$files($$GTEST_DIR/include/gtest/*.h)
GTEST_HEADERS += $$files($$GMOCK_DIR/include/gmock/*.h)
GTEST_HEADERS += $$files($$GTEST_DIR/include/gtest/internal/*.h)
GTEST_HEADERS += $$files($$GMOCK_DIR/include/gmock/internal/*.h)

//HEADERS += $$GTEST_HEADERS



