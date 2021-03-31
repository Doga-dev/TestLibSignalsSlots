/*!
 * file testplugin.h
 * brief file for the definition of the class "TestPlugin"
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
#ifndef TESTPLUGIN_H
#define TESTPLUGIN_H

#include <QObject>

#include "../InterfacePlugin/interface_plugin.h"

class TestPlugin : public QObject
{
	Q_OBJECT
public:
	explicit TestPlugin(QObject *parent = nullptr);

	void start();

public slots:
	void receive(QVariant prm);

signals:
	void send(QVariant prm);

private:
	IPlugin		* m_plugin;
};

#endif // TESTPLUGIN_H
