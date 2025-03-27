#pragma once
#ifdef _WIN32
    #define RAYGL_API __declspec(dllexport)
#else
    #define RAYGL_API
#endif
