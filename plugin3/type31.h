/*!
 * file type31.h
 * brief file for the definition of the class "Type31"
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
#ifndef TYPE31_H
#define TYPE31_H

#include <QObject>
#include <QString>
#include <QVariant>

#include <i_plugin_type_factory.h>
#include <i_type.h>

#include "plugin3_global.h"

class PLUGIN3_SHARED_EXPORT Type31 : public IType, public IPluginTypeFactory<Type31>
{
	Q_OBJECT
	Q_INTERFACES(IType)

	explicit Type31(const QVariant & parameters, QObject * parent);

public:
	inline static QString	getTypeNameInternal()	{	return QStringLiteral("Type31");	};
	static QObject * createInternal(const QVariant & parameters, QObject * parent) {
		return new Type31(parameters, parent);
	};
	QVariant getParameters() Q_DECL_OVERRIDE;

public slots:
	void	sltParameters() Q_DECL_OVERRIDE;

signals:
	void	sigParameters(const QVariant & parameters);

private:
	QVariant	m_prms;
};

#endif // TYPE31_H
