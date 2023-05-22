
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include "zapengine/base.h"
#include "zapengine/zlog.h"

#ifdef ZLOG_ON
// Quick logging to file when ZLOG_ON is defined. A good replacement for printf.
void zlog(const char *format, ...)
{

    static bool erase_log = true;
    va_list v_ptr;
    FILE *fp;

    fp = fopen("log.txt", erase_log ? "w" : "a");
    if (fp)
    {
        va_start(v_ptr, format);

        vfprintf(fp, format, v_ptr);
        fprintf(fp, "\n");

        vprintf(format, v_ptr);
        printf("\n");

        va_end(v_ptr);

        fclose(fp);
    }
    erase_log = false;
}
#endif