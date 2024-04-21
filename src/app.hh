#ifndef OPENPOOL_APP_HH
#define OPENPOOL_APP_HH

#include "util.hh"
#include "video.hh"

class App {
    public:
        bool running;
        cVideo video;

        App();
        ~App();
        static App& Instance();

        void Update();
        void Render();
};

#endif
