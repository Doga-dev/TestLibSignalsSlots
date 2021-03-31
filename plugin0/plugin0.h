#ifndef PLUGIN0_H
#define PLUGIN0_H

#include "plugin0_global.h"
#include <interface_plugin.h>

class PLUGIN0_SHARED_EXPORT Plugin0 : public IPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "IPlugin")
	Q_INTERFACES(IPlugin)

public:
	explicit Plugin0(QObject * parent = nullptr);

	// IPlugin interface
public:
	QString			pluginId		() Q_DECL_OVERRIDE;
	QString			pluginName		() Q_DECL_OVERRIDE;
	QStringList		pluginTypes		() Q_DECL_OVERRIDE;
	IVersion		pluginVersion	() Q_DECL_OVERRIDE;

public slots:
	void			getId			() Q_DECL_OVERRIDE;
	void			getName			() Q_DECL_OVERRIDE;
	void			getTypes		() Q_DECL_OVERRIDE;
	void			getVersion		() Q_DECL_OVERRIDE;
};

#endif // PLUGIN0_H
