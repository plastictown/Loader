#pragma once
#ifdef COW_EXPORTS
#define COW_API extern "C" __declspec(dllexport)
#else
#define COW_API __declspec(dllimport)
#endif

COW_API const char* sound();
COW_API float weight();