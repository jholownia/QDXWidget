#-------------------------------------------------
#
# Project created by QtCreator 2014-03-03T20:22:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QDXWidget
TEMPLATE = app


SOURCES += main.cpp\
        qdxwidget.cpp \
    d3dbase.cpp

HEADERS  += qdxwidget.h \
    d3dbase.h

win32:CONFIG(release, debug|release): LIBS += -L"C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86/" -ld3dx11
else:win32:CONFIG(debug, debug|release): LIBS += -L"C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86/" -ld3dx11d

INCLUDEPATH += "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include"
DEPENDPATH += "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include"
