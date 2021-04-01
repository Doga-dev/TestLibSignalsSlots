QT       -= gui

TARGET = Plugin1
TEMPLATE = lib
CONFIG += plugin

DEFINES += PLUGIN1_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
	plugin1.cpp \
	type11.cpp \
	type12.cpp

HEADERS += \
		plugin1.h \
		plugin1_global.h \
		type11.h \
		type12.h

unix {
	target.path = /usr/lib
	INSTALLS += target
}

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../InterfacePlugin/lib/ -lInterfacePlugin
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../InterfacePlugin/lib/debug/ -lInterfacePlugin
#else:unix: LIBS += -L$$PWD/../InterfacePlugin/lib/ -lInterfacePlugin
LIBS += -L$$PWD/../InterfacePlugin/lib/ -lInterfacePlugin

INCLUDEPATH += $$PWD/../InterfacePlugin
DEPENDPATH += $$PWD/../InterfacePlugin

DESTDIR = ../App/plugins
