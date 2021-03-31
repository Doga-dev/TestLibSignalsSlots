#ifndef PLUGIN0_GLOBAL_H
#define PLUGIN0_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PLUGIN0_LIBRARY)
#define PLUGIN0_SHARED_EXPORT Q_DECL_EXPORT
#else
#define PLUGIN0_SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PLUGIN0_GLOBAL_H
