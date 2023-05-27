#include "zapengine/base.h"
#include "zapengine/zlog.h"


#ifdef ZLOG_ON
// Quick logging to file when ZLOG_ON is defined. A good replacement for printf.
#undef zlog
void zlog(char *file, int line, int type, char *format, ...)
{
    static bool erase_log = true;
    va_list v_ptr;
    FILE *fp;

    fp = fopen("log.txt", erase_log ? "w" : "a");
    if (fp)
    {
        va_start(v_ptr, format);

        if (type == INFO)
        {
            fprintf(fp, "INFO: ");
            vfprintf(fp, format, v_ptr);
            fprintf(fp, " [%s:%d]", file, line);
            fprintf(fp, "\n");

            printf(COLOR_GREEN BOLD_ON"INFO: " BOLD_OFF);
            vprintf(format, v_ptr);
            printf(COLOR_BLUE " [%s:%d]", file, line);
            printf("\n" COLOR_RESET);
        }
        else if (type == WARN)
        {
            fprintf(fp, "WARN: ");
            vfprintf(fp, format, v_ptr);
            fprintf(fp, " [%s:%d]", file, line);
            fprintf(fp, "\n");

            printf(COLOR_YELLOW BOLD_ON"WARN: " BOLD_OFF);
            vprintf(format, v_ptr);
            printf(COLOR_BLUE " [%s:%d]", file, line);
            printf("\n" COLOR_RESET);
        }
        else if (type == FAIL)
        {
            fprintf(fp, "FAIL: ");
            vfprintf(fp, format, v_ptr);
            fprintf(fp, " [%s:%d]", file, line);
            fprintf(fp, "\n");

            printf(COLOR_RED BOLD_ON"FAIL: " BOLD_OFF);
            vprintf(format, v_ptr);
            printf(COLOR_BLUE " [%s:%d]", file, line);
            printf("\n"COLOR_RESET);
        }
        else if (type == LOAD)
        {
            fprintf(fp, "LOAD: ");
            vfprintf(fp, format, v_ptr);
            fprintf(fp, " [%s:%d]", file, line);
            fprintf(fp, "\n");

            printf(COLOR_MAGENTA  BOLD_ON "LOAD: " BOLD_OFF);
            vprintf(format, v_ptr);
            printf(COLOR_BLUE " [%s:%d]", file, line);
            printf("\n"COLOR_RESET);
        }
        else if (type == NONE)
        {
            vfprintf(fp, format, v_ptr);
            fprintf(fp, "\n");

            printf(COLOR_CYAN  BOLD_ON "");
            vprintf(format, v_ptr);
            printf("\n"COLOR_RESET);
        }

        va_end(v_ptr);
        fclose(fp);
    }
    erase_log = false;
}
#endif