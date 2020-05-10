QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets \
                                        multimedia \
                                        multimediawidgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    datastorage.cpp \
    debugconsole.cpp \
    main.cpp \
    mainwindow.cpp \
    popup.cpp \
    settingswindow.cpp \
    videoframegrabber.cpp \
    videowidget.cpp

HEADERS += \
    datastorage.h \
    debugconsole.h \
    mainwindow.h \
    popup.h \
    settingswindow.h \
    videoframegrabber.h \
    videowidget.h

FORMS += \
    mainwindow.ui \
    settingswindow.ui \
    videowidget.ui

TRANSLATIONS += \
    BB_en_US.ts\

RC_ICONS += eye.ico

CONFIG(debug, debug|release){
    BUILDDIR = debug
} else {
    BUILDDIR = release
}

OBJECTS_DIR = $${QT_ARCH}/obj
UI_DIR = $${QT_ARCH}/ui
MOC_DIR = $${QT_ARCH}/moc
RCC_DIR = $${QT_ARCH}/rcc
DESTDIR = $${QT_ARCH}/$$BUILDDIR
QMAKE_POST_LINK += "$(QTDIR)/bin/windeployqt $$DESTDIR"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += Resources.qrc
