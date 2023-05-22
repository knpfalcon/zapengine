#ifndef BASE_H
#define BASE_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

#define _ZAP_DLL   __declspec(dllimport)

#define ZAP_VAR(type, name)                   extern _ZAP_DLL type name
#define ZAP_ARRAY(type, name)                 extern _ZAP_DLL type name[]
#define ZAP_FUNC(type, name, args)            extern type name args
#define ZAP_METHOD(type, name, args)          type (*name) args
#define ZAP_FUNCPTR(type, name, args)         extern _ZAP_DLL type (*name) args

#ifdef __cplusplus
}
#endif

#endif