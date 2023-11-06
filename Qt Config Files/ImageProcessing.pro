QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # Depteciated API check: disables all the APIs deprecated before Qt 6.0.0



TARGET = ImageProcessing
QT += core gui widgets


SOURCES += main.cpp mainapplication.cpp


HEADERS += mainapplication.h


FORMS += mainapplication.ui
