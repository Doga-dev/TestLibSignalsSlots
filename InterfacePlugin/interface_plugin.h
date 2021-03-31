#ifndef INTERFACE_PLUGIN_H
#define INTERFACE_PLUGIN_H

#include "interface_plugin_global.h"

#include <QMap>
#include <QObject>
#include <QString>
#include <QVariant>

#include "fast_delegate.h"
#include "i_version.h"
#include "interface_plugin_global.h"

typedef fastdelegate::FastDelegate2<const QVariant &, QObject *, QObject *>	TypeFactoryFunc;

class INTERFACE_PLUGIN_SHARED_EXPORT IPlugin : public QObject
{
	Q_OBJECT
public:
	IPlugin(QObject * parent = nullptr);
	virtual ~IPlugin() {}

	virtual QString			pluginId			() = 0;		// identifiant du driver pour la remonté d'information (traces)
	virtual QString			pluginName			() = 0;		// nom du driver pour le listing des modules sur l'interface graphique
	virtual QStringList		pluginTypes			() = 0;		// list tous les types que peut instancier le plugin
	virtual IVersion		pluginVersion		() = 0;		// version du driver pour le listing des modules sur l'interface graphique (+ traces)

	QObject *				getInstance			(const QString & type, const QVariant & parameters, QObject * parent);

public slots:
	virtual void			getId				() = 0;
	virtual void			getName				() = 0;
	virtual void			getTypes			() = 0;
	virtual void			getVersion			() = 0;

signals:
	// Signal to be emitted in getName()
	void		id			(QString value);
	void		name		(QString value);
	void		types		(QStringList values);
	void		version		(IVersion value);

protected:
	QMap<QString, TypeFactoryFunc>	m_types;
};

#define IPluginIID "fr.doga.rd.box.IPlugin"
Q_DECLARE_INTERFACE(IPlugin, IPluginIID)

#endif // INTERFACE_PLUGIN_H
