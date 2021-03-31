#include <QCoreApplication>
#include <QDir>
#include <QPluginLoader>
#include <interface_plugin.h>

#include <QDebug>
#include <QSignalSpy>
#include <QTimer>

#include "d_plugins_loader.h"

int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);

	QDir dir(qApp->applicationDirPath());
	dir.cd("plugins");

	DPluginsLoader pluginsLoader(dir.path());

	return 0;
//	return a.exec();
}
