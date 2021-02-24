QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += sql

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bloodwork.cpp \
    bloodworktablemodel.cpp \
    calendarmanager.cpp \
    calendarview.cpp \
    createbloodwork.cpp \
    createprescription.cpp \
    createuser.cpp \
    database.cpp \
    expiredview.cpp \
    loginwindow.cpp \
    main.cpp \
    mainscreen.cpp \
    medication.cpp \
    patient.cpp \
    prescription.cpp \
    prescriptiontablemodel.cpp \
    technician.cpp \
    usertablemodel.cpp \
    viewbloodwork.cpp \
    viewprescription.cpp \
    viewusers.cpp

HEADERS += \
    bloodwork.h \
    bloodworktablemodel.h \
    calendarmanager.h \
    calendarview.h \
    createbloodwork.h \
    createprescription.h \
    createuser.h \
    database.h \
    expiredview.h \
    loginwindow.h \
    mainscreen.h \
    medication.h \
    patient.h \
    prescription.h \
    prescriptiontablemodel.h \
    technician.h \
    usertablemodel.h \
    viewbloodwork.h \
    viewprescription.h \
    viewusers.h

FORMS += \
    calendarview.ui \
    createbloodwork.ui \
    createprescription.ui \
    createuser.ui \
    expiredview.ui \
    loginwindow.ui \
    mainscreen.ui \
    viewbloodwork.ui \
    viewprescription.ui \
    viewusers.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
