/*!
 * file plugin0.cpp
 * brief file for the definition of the class "Plugin0"
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

#include "plugin0.h"
#include "type01.h"
#include "type02.h"

Plugin0::Plugin0(QObject * parent)
{
	setParent(parent);
	m_types.insert(Type01::typeName(), & Type01::create);
	m_types.insert(Type02::typeName(), & Type02::create);
}

QString Plugin0::pluginId()
{
	return QStringLiteral("0e8936b7-1f99-4a69-ba4a-c5e5a6a83a68");
}

QString Plugin0::pluginName()
{
	return QStringLiteral("Plugin 0");
}

QStringList Plugin0::pluginTypes()
{
	return m_types.keys();
}

IVersion Plugin0::pluginVersion()
{
	return IVersion(QStringLiteral("1.0.0.0"), (QObject *) this);
}

void Plugin0::getId()
{
	emit id(pluginId());
}

void Plugin0::getName()
{
	emit name(pluginName());
}

void Plugin0::getTypes()
{
	emit types(pluginTypes());
}

void Plugin0::getVersion()
{
	emit version(pluginVersion());
}
