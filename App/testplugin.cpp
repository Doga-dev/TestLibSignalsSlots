/*!
 * file testplugin.cpp
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

#include <QDebug>

#include "testplugin.h"
#include "../InterfacePlugin/interface_plugin.h"

TestPlugin::TestPlugin(QObject * parent) : QObject(parent)
  , m_plugin(nullptr)
{
//	m_plugin = getNewInterface(this);
//	QObject::connect(m_plugin.data(), & Interface::answer, this, & TestPlugin::receive);
//	QObject::connect(this, & TestPlugin::send, m_plugin.data(), & Interface::reply);
}

void TestPlugin::start()
{
	emit send("petit texte");
}

void TestPlugin::receive(QVariant prm)
{
	qDebug() << Q_FUNC_INFO << prm;
}
