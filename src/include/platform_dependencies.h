#ifndef PLATFORM_DEPENDENCIES_H
#define PLATFORM_DEPENDENCIES_H
#include <fstream>
#include <string>

#ifdef _WIN32
    #define mips_null_str L""
    #define mips_str std::wstring
    #define mips_char wchar_t
    #define mips_str_stream std::stringstream
    #define mips_f_stream std::wifstream
#elif __linux__
    #define mips_null_str ""
    #define mips_str std::string
    #define mips_char char
    #define mips_str_stream std::stringstream
    #define mips_f_stream std::ifstream
#endif

#endif // PLATFORM_DEPENDENCIES_H