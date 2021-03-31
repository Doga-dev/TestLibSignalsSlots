#-------------------------------------------------
#
# Project created by QtCreator 2018-05-24T17:04:25
#
#-------------------------------------------------

QT       -= gui

TARGET = InterfacePlugin
TEMPLATE = lib

DEFINES += INTERFACE_PLUGIN_LIBRARY

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
	i_type.cpp \
	i_version.cpp \
	interface_plugin.cpp

HEADERS += \
		fast_delegate.h \
		i_plugin_type_factory.h \
		i_type.h \
		i_version.h \
		interface_plugin.h \
		interface_plugin_global.h

unix {
	target.path = /usr/lib
	INSTALLS += target
}

DESTDIR = $$PWD/lib
