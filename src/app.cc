#include "app.hh"

App::App():
    running(true),
    gameFolder(Util::DirName(Util::GetExecutableLocation()))
{
    image.Init();
    video.Init();

    poolBalls.Init(
        video.renderer,
        gameFolder + "/pballs/sheet.png",
        80
    );
}

App::~App() {
    image.Free();
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
    Render();
}

void App::Render() {
    SDL_SetRenderDrawColor(video.renderer, 0, 0, 25, 255);
    SDL_RenderClear(video.renderer);

    Vec2 block;

    block.x = 39;
    block.y = 39;
    // TO-DO Render something to the screen
    for (int i = 0; i < 17; i++) {
        block.x += 39;
        poolBalls.RenderTile(
            video.renderer,
            i,
            block
        );
    }


    SDL_RenderPresent(video.renderer);
}
