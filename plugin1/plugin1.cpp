/*!
 * file plugin1.cpp
 * brief file for the definition of the class "Plugin1"
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

#include "plugin1.h"
#include "type11.h"
#include "type12.h"

Plugin1::Plugin1(QObject * parent)
{
	setParent(parent);
	m_types.insert(Type11::typeName(), & Type11::create);
	m_types.insert(Type12::typeName(), & Type12::create);
}

QString Plugin1::pluginId()
{
	return QStringLiteral("60527a78-752d-431a-a251-9d0e6909a347");
}

QString Plugin1::pluginName()
{
	return QStringLiteral("Plugin 1");
}

QStringList Plugin1::pluginTypes()
{
	return m_types.keys();
}

IVersion Plugin1::pluginVersion()
{
	return IVersion(QStringLiteral("1.0.0.0"), (QObject *) this);
}

void Plugin1::getId()
{
	emit id(pluginId());
}

void Plugin1::getName()
{
	emit name(pluginName());
}

void Plugin1::getTypes()
{
	emit types(pluginTypes());
}

void Plugin1::getVersion()
{
	emit version(pluginVersion());
}
