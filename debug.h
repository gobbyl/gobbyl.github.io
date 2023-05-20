#pragma once
#ifdef DEBUG 
#include <iostream>

constexpr const char* filename_without_path(const char* path) {
    const char* result = path;
    while (*path != '\0')
        if (*path++ == '\\') result = path;

    return result;
}

#define str(s) #s
#define FILELINE(line) filename_without_path(__FILE__) << ":" << str(line)

#define LOG(x) std::cerr  << "INFO : " << "[" << FILELINE(__LINE__) << "][" << __FUNCTION__ << "] " << x << std::endl;
#define LOGVAR(x,y) std::cerr  << "INFO : " << "[" << FILELINE(__LINE__) << "][" << __FUNCTION__ << "] " << x <<":" << y << std::endl;
#define LOGL(x) std::cerr  << "INFO : " << "[" << FILELINE(__LINE__) << "][" << __FUNCTION__ << "] " << x << std::endl << std::endl;
#define LOGVARN(x,y) std::cerr  << "INFO : " << "[" << FILELINE(__LINE__) << "][" << __FUNCTION__ << "] " << x <<":" << y << std::endl << std::endl;
#define LOGNN(x) std::cerr  << std::endl << "INFO : " << "[" << FILELINE(__LINE__) << "][" << __FUNCTION__ << "] " << x << std::endl;
#define LOGVARNN(x,y) std::cerr  << std::endl << "INFO : " << "[" << FILELINE(__LINE__) << "][" << __FUNCTION__ << "] " << x <<":" << y << std::endl;

#else
#define LOG(x)
#define LOGVAR(x,y)
#define LOGN(x)
#define LOGVARN(x,y)
#define LOGNN(x)
#define LOGVARNN(x,y)
#endif