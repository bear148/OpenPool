#ifndef OPENPOOL_VIDEO_HH
#define OPENPOOL_VIDEO_HH

#include "__i.hh"

class cVideo {
public:
    SDL_Renderer* renderer;
    SDL_Window* window;

    cVideo() {}

    void Init();
    void dDrawTriangle();
    void Free();
};

#endif
