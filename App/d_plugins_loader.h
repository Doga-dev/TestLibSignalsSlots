/*!
 * file d_plugins_loader.h
 * brief file for the definition of the class "DPluginsLoader"
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
#ifndef D_PLUGINS_LOADER_H
#define D_PLUGINS_LOADER_H


#include <QMap>
#include <QObject>
#include <QSharedPointer>
#include <QString>

#include "interface_plugin.h"

typedef QSharedPointer<IPlugin> pIPlugin;

class DPluginsLoader : public QObject
{
	Q_OBJECT
public:
	explicit DPluginsLoader(const QString & pluginsPath, QObject * parent = nullptr);

	bool checkSignalEmit(IPlugin * plugin);

	bool checkTypeCreation(const QString & type);

public slots:
	void	sltReceiveSignal(const QVariant & parameters);

signals:

private:
	QMap<QString, pIPlugin>	m_plugins;
	QMap<QString, pIPlugin>	m_types;
};

#endif // D_PLUGINS_LOADER_H
