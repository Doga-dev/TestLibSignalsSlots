#ifndef PLUGIN2_H
#define PLUGIN2_H

#include "plugin2_global.h"
#include <interface_plugin.h>

class PLUGIN2_SHARED_EXPORT Plugin2 : public IPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID IPluginIID)
  Q_INTERFACES(IPlugin)

public:
	explicit Plugin2(QObject * parent = nullptr);

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

#endif // PLUGIN2_H
