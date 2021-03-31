#ifndef PLUGIN3_H
#define PLUGIN3_H

#include "plugin3_global.h"
#include <interface_plugin.h>

class PLUGIN3_SHARED_EXPORT Plugin3 : public IPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "IPlugin")
  Q_INTERFACES(IPlugin)

public:
	explicit Plugin3(QObject * parent = nullptr);

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

#endif // PLUGIN3_H
