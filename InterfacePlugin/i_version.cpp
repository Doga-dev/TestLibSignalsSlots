/*!
 * file i_version.cpp
 * brief file for the definition of the class "IVersion"
 * author chapet
 * date 2021-3-30
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

#include "i_version.h"

IVersion::IVersion(uint64_t version, QObject * parent) : QObject(parent)
  , m_version(version)
{}

IVersion::IVersion(const QString & version, QObject * parent) : IVersion(0, parent)
{
	fromString(version);
}

IVersion::IVersion(uint16_t major, uint16_t minor, uint16_t patch, uint16_t compil, QObject * parent)
	: IVersion((((uint64_t)major) << 48) + (((uint64_t)minor) << 32) + (((uint64_t)patch) << 16) + (((uint64_t)compil) << 0), parent)
{}

IVersion::IVersion(const IVersion & other) : IVersion(other.toUInt(), other.parent())
{}

QString IVersion::toString(EnVersionLevel level)
{
	QString res;
	if (level >= EnVersionLevel::CeVlMajor) {
		res += QString::number((int)major());
	}
	if (level >= EnVersionLevel::CeVlMinor) {
		res += separator() + QString::number((int)minor());
	}
	if (level >= EnVersionLevel::CeVlPatch) {
		res += separator() + QString::number((int)patch());
	}
	if (level >= EnVersionLevel::CeVlCompil) {
		res += separator() + QString::number((int)compil());
	}
	return res;
}

void IVersion::fromUint(uint64_t version)
{
	if (m_version == version)
		return;

	m_version = version;
	emit versionChanged(this);
}

bool IVersion::fromString(const QString & versionString, EnVersionLevel wantedLevel)
{
	QStringList list = versionString.split(separator());
	int size = list.count();
	if ((((int) wantedLevel + 1) >= size) && (size <= EnVersionLevel::_CeVlNbrLevel)) {
		bool		ok = true;
		int			val;
		uint64_t	res = 0;
		for (int var = 0 ; (var < size) && ok ; ++var) {
			val = list.value(var).toInt(& ok);
			if (ok && (0 <= val) && (val < 65536)) {
				res += ((uint64_t)val) << (64 - (16 * (var + 1)));
			} else {
				ok = false;
			}
		}
		if (ok) {
			fromUint(res);
			return true;
		}
	}
	return false;
}
