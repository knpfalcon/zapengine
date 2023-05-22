
#include "base.h"
#include "zapengine/zlog.h"

// Quick logging to file when JLOG_ON is defined. A good replacement for printf.
void zlog(const char *format, ...)
{
#ifdef ZLOG_ON
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
#endif
}