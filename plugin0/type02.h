/*!
 * file type02.h
 * brief file for the definition of the class "Type02"
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
#ifndef TYPE02_H
#define TYPE02_H

#include <QObject>
#include <QString>
#include <QVariant>

#include <i_plugin_type_factory.h>
#include <i_type.h>

#include "plugin0_global.h"

class PLUGIN0_SHARED_EXPORT Type02 : public IType, public IPluginTypeFactory<Type02>
{
	Q_OBJECT
	Q_INTERFACES(IType)

	explicit Type02(const QVariant & parameters, QObject *parent = nullptr);

public:
	inline static QString	getTypeNameInternal()	{	return QStringLiteral("Type02");	};
	static QObject * createInternal(const QVariant & parameters, QObject * parent) {
		return new Type02(parameters, parent);
	};
	QVariant getParameters() Q_DECL_OVERRIDE;

public slots:
	void	sltParameters() Q_DECL_OVERRIDE;

signals:
	void	sigParameters(const QVariant & parameters);

private:
	QVariant	m_prms;
};

#endif // TYPE02_H
