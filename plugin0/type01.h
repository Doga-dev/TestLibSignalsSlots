/*!
 * file type01.h
 * brief file for the definition of the class "Type01"
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
#ifndef TYPE01_H
#define TYPE01_H

#include <QObject>
#include <QString>
#include <QVariant>

#include <i_plugin_type_factory.h>
#include <i_type.h>

#include "plugin0_global.h"

class PLUGIN0_SHARED_EXPORT Type01 : public IType, public IPluginTypeFactory<Type01>
{
	Q_OBJECT
	Q_INTERFACES(IType)

public:
	explicit Type01(const QVariant & parameters = QVariant(), QObject * parent = nullptr);

	inline static QString	getTypeNameInternal()	{	return QStringLiteral("Type01");	};
	static QObject * createInternal(const QVariant & parameters, QObject * parent) {
		return new Type01(parameters, parent);
	};
	QVariant getParameters() Q_DECL_OVERRIDE;

public slots:
	void	sltParameters() Q_DECL_OVERRIDE;
	void	sltTraceSignalEmit(const QVariant & parameters);

signals:
	void	sigParameters(const QVariant & parameters);

private:
	QVariant	m_prms;
};

#endif // TYPE01_H
