QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = main
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += Demo.cpp Node.cpp Tree.cpp Screen.cpp
HEADERS += Screen.hpp

# Define a custom target to run the program
run.target = tree
run.commands = ./main
run.depends = first # Depend on the first build target, ensuring the program is built before running

QMAKE_EXTRA_TARGETS += run

# Add the tree executable to the clean files
QMAKE_CLEAN += main Demo.o