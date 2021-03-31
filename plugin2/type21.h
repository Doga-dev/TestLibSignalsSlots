/*!
 * file type21.h
 * brief file for the definition of the class "Type21"
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
#ifndef TYPE21_H
#define TYPE21_H

#include <QObject>
#include <QString>
#include <QVariant>

#include <i_plugin_type_factory.h>
#include <i_type.h>

#include "plugin2_global.h"

class PLUGIN2_SHARED_EXPORT Type21 : public IType, public IPluginTypeFactory<Type21>
{
	Q_OBJECT
	Q_INTERFACES(IType)

	explicit Type21(const QVariant & parameters, QObject * parent);

public:
	inline static QString	getTypeNameInternal()	{	return QStringLiteral("Type21");	};
	static QObject * createInternal(const QVariant & parameters, QObject * parent) {
		return new Type21(parameters, parent);
	};
	QVariant getParameters() Q_DECL_OVERRIDE;

public slots:
	void	sltParameters() Q_DECL_OVERRIDE;

signals:
	void	sigParameters(const QVariant & parameters);

private:
	QVariant	m_prms;
};

#endif // TYPE21_H
