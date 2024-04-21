#include "util.hh"

std::string Util::CurrentTime() {
    time_t rawTime;
    struct tm* timeinfo;

    time(&rawTime);
    timeinfo = localtime(&rawTime);
    
    char buffer[80];
    strftime(buffer, 80, "%H:%M:%S", timeinfo);

    return std::string(buffer);
}

void Util::Log(const char* format, ...) {
    int n = 0;
    size_t size = 0;
    char* ret = nullptr;
    va_list ap;

    va_start(ap, format);
    n = vsnprintf(ret, size, format, ap);
    va_end(ap);

    if (n < 0) {
        return;
    }
    
    size = n + 1;
    ret = (char*) malloc(size);
    if (ret == nullptr) {
        return;
    }

    va_start(ap, format);
    n = vsnprintf(ret, size, format, ap);
    va_end(ap);

    if (n < 0) {
        free(ret);
        return;
    }

    printf("[%s] %s\n", CurrentTime().c_str(), ret);
    free(ret);
}

void Util::Error(const char* format, ...) {
    size_t n = 0;
    size_t size = 0;
    char* ret = nullptr;
    va_list ap;

    va_start(ap, format);
    n = vsnprintf(ret, size, format, ap);
    va_end(ap);

    if (n < 0) {
        return;
    }

    size = n + 1;
    ret = (char*) malloc(size);
    if (ret == nullptr) {
        return;
    }

    va_start(ap, format);
    n = vsnprintf(ret, size, format, ap);
    va_end(ap);

    if (n < 0) {
        free(ret);
        return;
    }

    fprintf(stderr, "[err] %s\n", ret);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR ENCOUNTERED", ret, nullptr);
    free(ret);
    exit(EXIT_FAILURE);
}
