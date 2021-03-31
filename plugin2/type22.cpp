/*!
 * file type22.cpp
 * brief file for the definition of the class "Type22"
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

#include "type22.h"

Type22::Type22(const QVariant & parameters, QObject * parent) : IType(parent)
  , m_prms(parameters)
{
}

QVariant Type22::getParameters()
{
	return m_prms;
}

void Type22::sltParameters()
{
	qDebug() << Q_FUNC_INFO;
	emit sigParameters(m_prms);
}
