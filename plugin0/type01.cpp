/*!
 * file type01.cpp
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

#include <QDebug>

#include "type01.h"

Type01::Type01(const QVariant & parameters, QObject * parent) : IType(parent)
  , m_prms(parameters)
{
	if (QObject::connect(this, & Type01::sigParameters, this, &Type01::sltTraceSignalEmit)) {
		qDebug() << Q_FUNC_INFO << "signal connection done";
	} else {
		qDebug() << Q_FUNC_INFO << "signal connection fail";
	}
	emit sigParameters("test constructor connection");
}

QVariant Type01::getParameters()
{
	return m_prms;
	qDebug() << Q_FUNC_INFO << "before emit";
	emit sigParameters("test getParameters");
	qDebug() << Q_FUNC_INFO << "after emit";
}

void Type01::sltParameters()
{
	qDebug() << Q_FUNC_INFO << "before emit";
	emit sigParameters(m_prms);
	qDebug() << Q_FUNC_INFO << "after emit";
}

void Type01::sltTraceSignalEmit(const QVariant & parameters)
{
	qDebug() << Q_FUNC_INFO << parameters;
}
