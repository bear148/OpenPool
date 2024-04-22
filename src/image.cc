#include "image.hh"
#include "util.hh"

void cImages::Init() {
    int flags = IMG_INIT_PNG;
    if (IMG_Init(flags) != flags) {
        Util::Error("SDL_image init failure");
    }
}

void cImages::Free() {
    IMG_Quit();
}
