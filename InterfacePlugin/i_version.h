/*!
 * \file i_version.h
 * \brief file for the definition of the interface "IVersion"
 * \author chapet
 * \date 2021-2-25
 *
 * \details
 *
 * \copyright
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
#ifndef I_VERSION_H
#define I_VERSION_H

#include <QObject>
#include <QString>
#include <QStringList>

#include "interface_plugin_global.h"

typedef enum _enVersionLevel {
	CeVlMajor,
	CeVlMinor,
	CeVlPatch,
	CeVlCompil,
	_CeVlNbrLevel
} EnVersionLevel;

class INTERFACE_PLUGIN_SHARED_EXPORT IVersion: public QObject
{
	Q_OBJECT
public:
	explicit IVersion(uint64_t version = 0, QObject * parent = nullptr);
	explicit IVersion(const QString & version, QObject * parent = nullptr);
	explicit IVersion(uint16_t major, uint16_t minor, uint16_t patch = 0, uint16_t compil = 0, QObject * parent = nullptr);
	IVersion(const IVersion & other);
	~IVersion() {}

	inline uint64_t		toUInt		() const	{	return m_version;	}
	QString				toString	(EnVersionLevel level = EnVersionLevel::CeVlCompil);

	inline uint16_t		major		() const	{	return (uint16_t)((m_version >> 48) & 0xFFFF);	}
	inline uint16_t		minor		() const	{	return (uint16_t)((m_version >> 32) & 0xFFFF);	}
	inline uint16_t		patch		() const	{	return (uint16_t)((m_version >> 16) & 0xFFFF);	}
	inline uint16_t		compil		() const	{	return (uint16_t)((m_version >>  0) & 0xFFFF);	}

	void				fromUint	(uint64_t version);
	bool				fromString	(const QString & versionString, EnVersionLevel wantedLevel = EnVersionLevel::CeVlMajor);

	inline void			operator =	(const IVersion & other)	{	fromUint(other.toUInt());	}
	inline bool			operator ==	(const IVersion & other)	{	return (toUInt() == other.toUInt());	}
	inline bool			operator !=	(const IVersion & other)	{	return (toUInt() != other.toUInt());	}
	inline bool			operator >	(const IVersion & other)	{	return (toUInt() >  other.toUInt());	}
	inline bool			operator <=	(const IVersion & other)	{	return (toUInt() <= other.toUInt());	}
	inline bool			operator <	(const IVersion & other)	{	return (toUInt() <  other.toUInt());	}
	inline bool			operator >=	(const IVersion & other)	{	return (toUInt() >= other.toUInt());	}

	static inline QString	separator()	{	return QStringLiteral(".");	}

signals:
	void		versionChanged(IVersion * version);

private:
	uint64_t m_version;
};

#define IVersionIID "fr.doga.rd.box.IVersion"
Q_DECLARE_INTERFACE(IVersion, IVersionIID) // define this out of namespace scope

#endif // I_VERSION_H
