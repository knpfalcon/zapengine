#ifndef VERSION_H
#define VERSION_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

    ZAP_FUNC(int, z_get_version_major, (void));
    ZAP_FUNC(int, z_get_version_minor, (void));
    ZAP_FUNC(int, z_get_version_revision, (void));

#ifdef __cplusplus
}
#endif
#endif
