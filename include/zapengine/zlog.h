#ifndef ZLOG_H
#define ZLOG_H

#include "zapengine/base.h"


#ifdef __cplusplus
extern "C" {
#endif

#ifdef ZLOG_ON
    ZAP_FUNC(void, zlog, (const char *format, ...));
#else
#define zlog(a, ...)
#endif


#ifdef __cplusplus
}
#endif

#endif