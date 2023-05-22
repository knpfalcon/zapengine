#ifndef ZLOG_H
#define ZLOG_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

    ZAP_FUNC(void, zlog, (const char *format, ...));

#ifdef __cplusplus
}
#endif

#endif