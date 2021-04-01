/*!
 * file interface_type.cpp
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

#include <QDebug>

#include "i_type.h"

IType::IType(QObject * parent) : QObject(parent)
{
	QObject::connect(this, &IType::sigParameters, this, &IType::sltItfTraceSignalEmit);
}

void IType::sltItfTraceSignalEmit(const QVariant & parameters)
{
	qDebug() << Q_FUNC_INFO << parameters;
}
