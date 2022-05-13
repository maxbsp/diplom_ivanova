QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    employesloader.cpp \
    main.cpp \
    mainwindow.cpp \
    diagram_builder.cpp \
    employee.cpp \
    matrix.cpp \
    matrixconverter.cpp \
    point.cpp

HEADERS += \
    employesloader.h \
    mainwindow.h \
    diagram_builder.h \
    employee.h \
    forward_declarations.h \
    matrix.h \
    matrixconverter.h \
    point.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    employes.txt
