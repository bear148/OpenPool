#include "app.hh"

App::App():
    running(true)
{
    video.Init();
}

App::~App() {
    video.Free();
}

App& App::Instance() {
    static App app;

    return app;
}

void App::Update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT: {
                running = false;
                break;
            }
        }
    }
}
