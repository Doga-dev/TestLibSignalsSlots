/*!
 * file type11.cpp
 * brief file for the definition of the class "Type11"
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

#include "type11.h"

Type11::Type11(const QVariant & parameters, QObject * parent) : IType(parent)
  , m_prms(parameters)
{
}

QVariant Type11::getParameters()
{
	return m_prms;
}

void Type11::sltParameters()
{
	qDebug() << Q_FUNC_INFO;
	emit sigParameters(m_prms);
}
