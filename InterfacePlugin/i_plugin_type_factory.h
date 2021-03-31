/*!
 * file i_plugin_type_factory.h
 * brief file for the definition of the interface "IPluginTypeFactory"
 * author chapet
 * date 2021-3-31
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
#ifndef I_PLUGIN_TYPE_FACTORY_H
#define I_PLUGIN_TYPE_FACTORY_H

#include <QObject>
#include <QString>
#include <QVariant>

template <class T>
class IPluginTypeFactory
{
public:
	static QString	typeName() {
		return T::getTypeNameInternal();
	}
	static QObject * create(const QVariant & parameters, QObject * parent = nullptr) {
		return T::createInternal(parameters, parent);
	}
	static QObject * create(QObject * parent = nullptr) {
		return T::createInternal(QVariant(), parent);
	}
};

#endif // I_PLUGIN_TYPE_FACTORY_H
