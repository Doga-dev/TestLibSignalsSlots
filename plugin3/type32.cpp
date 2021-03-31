/*!
 * file type32.cpp
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

#include <QDebug>

#include "type32.h"

Type32::Type32(const QVariant & parameters, QObject * parent) : IType(parent)
  , m_prms(parameters)
{
}

QVariant Type32::getParameters()
{
	return m_prms;
}

void Type32::sltParameters()
{
	qDebug() << Q_FUNC_INFO;
	emit sigParameters(m_prms);
}
