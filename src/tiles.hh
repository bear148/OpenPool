#ifndef OPENPOOL_TILES_HH
#define OPENPOOL_TILES_HH

#include "types.hh"
#include "__i.hh"

class PoolBallTileSheet {
    public:
        uint32_t tSize;
        SDL_Texture* image;

        PoolBallTileSheet();
        void Init(SDL_Renderer* renderer, std::string path, uint32_t p_tileSize);
        void Free();
        UVec2 GetTexturePosition(uint32_t id);
        void RenderTile(SDL_Renderer* renderer, uint32_t id, Vec2 pos);
        void RenderSubTile(SDL_Renderer* renderer, uint32_t id, Vec2 pos, Rect source);
};

#endif
