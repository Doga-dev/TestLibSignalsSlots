/*!
 * file type11.h
 * brief file for the definition of the class "Type11"
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
#ifndef TYPE11_H
#define TYPE11_H

#include <QObject>
#include <QString>
#include <QVariant>

#include <i_plugin_type_factory.h>
#include <i_type.h>

#include "plugin1_global.h"

class PLUGIN1_SHARED_EXPORT Type11 : public IType, public IPluginTypeFactory<Type11>
{
	Q_OBJECT
	Q_INTERFACES(IType)

	explicit Type11(const QVariant & parameters, QObject * parent);

public:
	inline static QString	getTypeNameInternal()	{	return QStringLiteral("Type11");	};
	static QObject * createInternal(const QVariant & parameters, QObject * parent) {
		return new Type11(parameters, parent);
	};
	QVariant getParameters() Q_DECL_OVERRIDE;

public slots:
	void	sltParameters() Q_DECL_OVERRIDE;

signals:
	void	sigParameters(const QVariant & parameters);

private:
	QVariant	m_prms;
};

#endif // TYPE11_H
