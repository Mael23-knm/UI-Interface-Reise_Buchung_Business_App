QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    airport.cpp \
    algorithmen.cpp \
    booking.cpp \
    buchungsdetails.cpp \
    check.cpp \
    customer.cpp \
    ergebnisprufungen.cpp \
    flightbooking.cpp \
    heap.cpp \
    hotelbooking.cpp \
    main.cpp \
    rentalcarreservation.cpp \
    sortfunktor.cpp \
    trainticket.cpp \
    travel.cpp \
    travelagency.cpp \
    travelagencyui.cpp

HEADERS += \
    airport.h \
    booking.h \
    buchungsdetails.h \
    check.h \
    customer.h \
    digraph.h \
    ergebnisprufungen.h \
    flightbooking.h \
    heap.h \
    hotelbooking.h \
    rentalcarreservation.h \
    sortfunktor.h \
    trainticket.h \
    travel.h \
    travelagency.h \
    travelagencyui.h

FORMS += \
    buchungsdetails.ui \
    ergebnisprufungen.ui \
    travelagencyui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
