#ifndef PLUGIN3_GLOBAL_H
#define PLUGIN3_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PLUGIN3_LIBRARY)
#define PLUGIN3_SHARED_EXPORT Q_DECL_EXPORT
#else
#define PLUGIN3_SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PLUGIN3_GLOBAL_H
