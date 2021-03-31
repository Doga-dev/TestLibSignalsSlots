/*!
 * file type12.h
 * brief file for the definition of the class "Type12"
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
#ifndef TYPE12_H
#define TYPE12_H

#include <QObject>
#include <QString>
#include <QVariant>

#include <i_plugin_type_factory.h>
#include <i_type.h>

#include "plugin1_global.h"

class PLUGIN1_SHARED_EXPORT Type12 : public IType, public IPluginTypeFactory<Type12>
{
	Q_OBJECT
	Q_INTERFACES(IType)

	explicit Type12(const QVariant & parameters, QObject *parent = nullptr);

public:
	inline static QString	getTypeNameInternal()	{	return QStringLiteral("Type12");	};
	static QObject * createInternal(const QVariant & parameters, QObject * parent) {
		return new Type12(parameters, parent);
	};
	QVariant getParameters() Q_DECL_OVERRIDE;

public slots:
	void	sltParameters() Q_DECL_OVERRIDE;

signals:
	void	sigParameters(const QVariant & parameters);

private:
	QVariant	m_prms;
};

#endif // TYPE12_H
