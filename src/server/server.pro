TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -Wno-deprecated-declarations

SOURCES += main.cpp \
    stock.cpp \
    portfolio.cpp \
    trader.cpp \
    transaction.cpp \
    repository.cpp \
    terminalservice.cpp

HEADERS += \
    stock.h \
    portfolio.h \
    trader.h \
    transaction.h \
    repository.h \
    terminalservice.h

LIBS += -lcpprest -lboost_system -lssl -lcrypto -lwt -lwtdbo
