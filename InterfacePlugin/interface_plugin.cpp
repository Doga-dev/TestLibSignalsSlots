/*!
 * file interface_plugin.cpp
 * brief file for the definition of the interface "IPlugin"
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

#include "interface_plugin.h"


IPlugin::IPlugin(QObject * parent) : QObject(parent)
{
}

QObject * IPlugin::getInstance(const QString & type, const QVariant & parameters, QObject * parent)
{
	if (m_types.contains(type)) {
		TypeFactoryFunc func = m_types.value(type);
		return func(parameters, parent);
	}
	return nullptr;
}
