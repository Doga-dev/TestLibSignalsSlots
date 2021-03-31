/*!
 * file interface_type.h
 * brief file for the definition of the class "interface_type"
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
#ifndef I_TYPE_H
#define I_TYPE_H

#include <QObject>
#include <QVariant>

#include "interface_plugin_global.h"

class INTERFACE_PLUGIN_SHARED_EXPORT IType : public QObject
{
	Q_OBJECT

public:
	explicit IType(QObject * parent = nullptr);
	virtual ~IType() {}

	virtual QVariant	getParameters	() = 0;

public slots:
	virtual void		sltParameters	() = 0;

signals:
	void		sigParameters	(const QVariant & parameters);
};

#define ITypeIID "fr.doga.rd.box.IType"
Q_DECLARE_INTERFACE(IType, ITypeIID)

#endif // I_TYPE_H
