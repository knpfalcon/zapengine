#ifndef ZLOG_H
#define ZLOG_H

#include "zapengine/base.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef ZLOG_ON
#define NONE 0  //General Info
#define INFO 1  //General Info
#define WARN 2  //Non-critical oddities
#define FAIL 3  //Failure, quitting
#define LOAD 4  //File loading or creating.


#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

#define BOLD_ON "\x1b[1m"
#define BOLD_OFF "\x1b[22m"
    void zlog(char *file, int line, int type, char *format, ...);
#define zlog(type, format, ...) (zlog(__FILE__, __LINE__, type, format, ##__VA_ARGS__))

#else
#define zlog(type, format, ...)
#endif


#ifdef __cplusplus
}
#endif

#endif
