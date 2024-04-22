#ifndef OPENPOOL_APP_HH
#define OPENPOOL_APP_HH

#include "image.hh"
#include "util.hh"
#include "video.hh"
#include "tiles.hh"

class App {
    public:
        bool running;
        cVideo video;
        PoolBallTileSheet poolBalls;
        cImages image;
        std::string gameFolder;

        App();
        ~App();
        static App& Instance();

        void Update();
        void Render();
};

#endif
