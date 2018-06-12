#ifndef PRINTLOG_GLOBAL_H
#define PRINTLOG_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PRINTLOG_LIBRARY)
#  define PRINTLOGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PRINTLOGSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PRINTLOG_GLOBAL_H