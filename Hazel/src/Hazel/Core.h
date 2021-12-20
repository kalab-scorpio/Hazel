#pragma once

#ifdef HZ_PLATFORM_WINDOWS
    #ifdef HZ_BUILD_DLL
        #define HAZEL_API _declspec(dllexport)
    #else
        #define HAZEL_API _declspec(dllimport)
    #endif
#else
    #define HAZEL_API 
#endif

#define BIT(x) (1 << x)

#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)