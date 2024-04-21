#ifndef OPENPOOL_UTIL_HH
#define OPENPOOL_UTIL_HH

#include "__i.hh"

namespace Util {
    void Error(const char* format, ...);
    void Log(const char* format, ...);
    std::string CurrentTime();
}

#endif
