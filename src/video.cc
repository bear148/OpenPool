#include "video.hh"
#include "util.hh"

void cVideo::Init() {
    // Init sdl stuff
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        Util::Error("SDL Init failure: %s\n", SDL_GetError());        
    }
    
    window = SDL_CreateWindow(
        (std::string(CNAME) + " " + CVER).c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 860,
        SDL_WINDOW_RESIZABLE
    );

    if (window == nullptr) {
        Util::Error("Window creation failure: %s\n", SDL_GetError());
    }
    Util::Log("Window created successfully");
    
    renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (renderer == nullptr) {
        Util::Error("Render creation failure: %s\n", SDL_GetError());
    }
    Util::Log("Renderer created Successfully");

    SDL_RenderSetLogicalSize(renderer, SCREEN_W, SCREEN_H);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

void cVideo::Free() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
