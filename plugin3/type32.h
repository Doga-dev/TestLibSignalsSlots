/*!
 * file type32.h
 * brief file for the definition of the class "Type32"
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
#ifndef TYPE32_H
#define TYPE32_H

#include <QObject>
#include <QString>
#include <QVariant>

#include <i_plugin_type_factory.h>
#include <i_type.h>

#include "plugin3_global.h"

class PLUGIN3_SHARED_EXPORT Type32 : public IType, public IPluginTypeFactory<Type32>
{
	Q_OBJECT
	Q_INTERFACES(IType)

	explicit Type32(const QVariant & parameters, QObject *parent = nullptr);

public:
	inline static QString	getTypeNameInternal()	{	return QStringLiteral("Type32");	};
	static QObject * createInternal(const QVariant & parameters, QObject * parent) {
		return new Type32(parameters, parent);
	};
	QVariant getParameters() Q_DECL_OVERRIDE;

public slots:
	void	sltParameters() Q_DECL_OVERRIDE;

signals:
	void	sigParameters(const QVariant & parameters);

private:
	QVariant	m_prms;
};

#endif // TYPE32_H
