TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        stringlength.cpp \
        tickets.cpp

HEADERS += \
    itask.h \
    stringlength.h \
    tester.h \
    tickets.h

LIBS += -lstdc++fs
