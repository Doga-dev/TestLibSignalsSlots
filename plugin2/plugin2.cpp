/*!
 * file plugin2.cpp
 * brief file for the definition of the class "Plugin2"
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

#include "plugin2.h"
#include "type21.h"
#include "type22.h"

Plugin2::Plugin2(QObject * parent)
{
	setParent(parent);
	m_types.insert(Type21::typeName(), & Type21::create);
	m_types.insert(Type22::typeName(), & Type22::create);
}

QString Plugin2::pluginId()
{
	return QStringLiteral("28b34ca7-a4e7-4b93-a970-f7fbace67426");
}

QString Plugin2::pluginName()
{
	return QStringLiteral("Plugin 2");
}

QStringList Plugin2::pluginTypes()
{
	return m_types.keys();
}

IVersion Plugin2::pluginVersion()
{
	return IVersion(QStringLiteral("1.0.0.0"), (QObject *) this);
}

void Plugin2::getId()
{
	emit id(pluginId());
}

void Plugin2::getName()
{
	emit name(pluginName());
}

void Plugin2::getTypes()
{
	emit types(pluginTypes());
}

void Plugin2::getVersion()
{
	emit version(pluginVersion());
}
