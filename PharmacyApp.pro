QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += sql

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bloodwork.cpp \
    createprescription.cpp \
    createuser.cpp \
    database.cpp \
    main.cpp \
    mainwindow.cpp \
    medication.cpp \
    patient.cpp \
    prescription.cpp \
    technician.cpp

HEADERS += \
    bloodwork.h \
    createprescription.h \
    createuser.h \
    database.h \
    mainwindow.h \
    medication.h \
    patient.h \
    prescription.h \
    technician.h

FORMS += \
    createprescription.ui \
    createuser.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
