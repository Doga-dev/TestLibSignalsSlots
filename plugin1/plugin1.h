#ifndef PLUGIN1_H
#define PLUGIN1_H

#include "plugin1_global.h"
#include <interface_plugin.h>

class PLUGIN1_SHARED_EXPORT Plugin1 : public IPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID IPluginIID)
  Q_INTERFACES(IPlugin)

public:
	explicit Plugin1(QObject * parent = nullptr);

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

#endif // PLUGIN1_H
