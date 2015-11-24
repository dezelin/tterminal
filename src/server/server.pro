TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stock.cpp \
    portfolio.cpp \
    trader.cpp \
    transaction.cpp

HEADERS += \
    stock.h \
    portfolio.h \
    trader.h \
    transaction.h

LIBS += -lwt -lwtdbo
