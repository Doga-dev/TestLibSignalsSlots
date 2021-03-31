/*!
 * file plugin3.cpp
 * brief file for the definition of the class "Plugin3"
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

#include "plugin3.h"
#include "type31.h"
#include "type32.h"

Plugin3::Plugin3(QObject * parent)
{
	setParent(parent);
	m_types.insert(Type31::typeName(), & Type31::create);
	m_types.insert(Type32::typeName(), & Type32::create);
}

QString Plugin3::pluginId()
{
	return QStringLiteral("66369133-5bec-45aa-b505-45985453306b");
}

QString Plugin3::pluginName()
{
	return QStringLiteral("Plugin 3");
}

QStringList Plugin3::pluginTypes()
{
	return m_types.keys();
}

IVersion Plugin3::pluginVersion()
{
	return IVersion(QStringLiteral("1.0.0.0"), (QObject *) this);
}

void Plugin3::getId()
{
	emit id(pluginId());
}

void Plugin3::getName()
{
	emit name(pluginName());
}

void Plugin3::getTypes()
{
	emit types(pluginTypes());
}

void Plugin3::getVersion()
{
	emit version(pluginVersion());
}
