/*!
 * file d_plugins_loader.cpp
 * brief file for the definition of the class "DPluginLoader"
 * author chapet
 * date 2021-3-30
 *
 * details
 *
 * copyright
 ****************************************************************************
 *        Ce logiciel est la propriete de DOGA®.
 *         -------------------------------------
 *
 *    Il ne peut etre reproduit ni communique en totalite ou partie sans
 *    son autorisation ecrite.
 *
 ****************************************************************************
 *        This software is the property of DOGA®.
 *         -------------------------------------
 *
 *    It cannot be reproduced nor disclosed entirely or partially without
 *    a written agreement.
 *
 ****************************************************************************
 */

#include <QDebug>
#include <QDir>
#include <QPluginLoader>
#include <QSignalSpy>
#include <QTimer>

#include "d_plugins_loader.h"
#include <i_type.h>

DPluginsLoader::DPluginsLoader(const QString & pluginsPath, QObject * parent) : QObject(parent)
  , m_plugins()
  , m_types()
{
	QDir dir(pluginsPath);
	for (auto &filename : dir.entryList(QDir::Files)) {
		QPluginLoader loader(dir.absoluteFilePath(filename));
		auto * instance = loader.instance();
		if (instance) {
			IPlugin * plugin = qobject_cast<IPlugin *>(instance);
			if (plugin) {
				QString name = plugin->pluginName();
				if (! name.isEmpty()) {
					QSharedPointer<IPlugin> ptr = QSharedPointer<IPlugin>(plugin);
					m_plugins.insert(name, ptr);
					QStringList types = plugin->pluginTypes();
					if (! types.isEmpty()) {
						foreach (QString type, types) {
							m_types.insert(type, ptr);
							qDebug() << "Type" << type << "loaded !";
						}
					}
					qDebug() << "Plugin" << name << "loaded !";
					checkSignalEmit(ptr.data());
				}
			}
		}
	}
	if (m_plugins.isEmpty()) {
		qDebug() << "Couldn't load any plugin!";
		return;
	}
	foreach (QString key, m_types.keys()) {
		checkTypeCreation(key);
	}
}

bool DPluginsLoader::checkSignalEmit(IPlugin * plugin)
{
	bool ret = false;
	// Verify plugin emits its `name` with `QSignalSpy`.
	QSignalSpy spy(plugin, & IPlugin::name);
	QTimer::singleShot(100, plugin, & IPlugin::getName);
	spy.wait();
	if (spy.count() == 1) {
		auto name = spy.takeFirst().at(0).toString();
		qDebug() << "Plugin emitted name:" << name;
		ret = true;
	} else {
		qDebug() << "Not emitted!";
	}
	return ret;
}

bool DPluginsLoader::checkTypeCreation(const QString & type)
{
	const QVariant prm("un peu de texte");
	bool ret = m_types.contains(type);

	if (ret) {
		pIPlugin plugin = m_types.value(type);
		QObject * object = plugin->getInstance(type, prm, this);
		IType * tp01 = qobject_cast<IType *>(object);
		QVariant params = tp01->getParameters();
		if (params == prm) {
			qDebug() << type << "return parameters" << params;
		} else {
			qDebug() << type <<  "did not return good values!" << params;
			ret = false;
		}
//		if (ret) {
//			QObject::connect(tp01, & IType::sigParameters, this, & DPluginsLoader::sltReceiveSignal);
//			tp01->sltParameters();
//		}
		if (ret) {
			// Verify plugin emits its `name` with `QSignalSpy`.
			QSignalSpy spy(tp01, & IType::sigParameters);
			QTimer::singleShot(100, tp01, & IType::sltParameters);
			spy.wait();
			if (spy.count() == 1) {
				auto prms = spy.takeFirst().at(0).toString();
				qDebug() << type << "emitted parameters:" << prms;
			} else {
				qDebug() << type << "did not emit parameters!";
				ret = false;
			}
		}
	}
	return ret;
}

void DPluginsLoader::sltReceiveSignal(const QVariant & parameters)
{
	IType * sndr = qobject_cast<IType *>(sender());
	qDebug() << Q_FUNC_INFO << sndr << parameters;
	if (sndr) {
		sndr->deleteLater();
	}
}
