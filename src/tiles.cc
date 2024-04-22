#include "tiles.hh"
#include "util.hh"

PoolBallTileSheet::PoolBallTileSheet():
    image(nullptr)
{

}

void PoolBallTileSheet::Init(SDL_Renderer* renderer, std::string path, uint32_t p_tileSize) {
    image = IMG_LoadTexture(renderer, path.c_str());
    tSize = p_tileSize;
    SDL_SetTextureBlendMode(image, SDL_BLENDMODE_BLEND);
    if (image == nullptr) {
        Util::Error("IMG_LoadTexture failure: Returned Null | %s", IMG_GetError());
        exit(EXIT_FAILURE);
    }
}

void PoolBallTileSheet::Free() {
    if (image != nullptr) {
        SDL_DestroyTexture(image);
    }
}

UVec2 PoolBallTileSheet::GetTexturePosition(uint32_t id) {
    SDL_Point textureSize;
    SDL_QueryTexture(image, nullptr, nullptr, &textureSize.x, &textureSize.y);

    return {
        id % (textureSize.x / tSize) * tSize,
        id / (textureSize.x / tSize) * tSize
    };
}

void PoolBallTileSheet::RenderTile(SDL_Renderer* renderer, uint32_t id, Vec2 pos) {
    UVec2 texturePos = GetTexturePosition(id);
    SDL_Rect destRect = {
        pos.x, pos.y, (int) tSize, (int) tSize
    };
    SDL_Rect sourceRect = {
        (int) texturePos.x, (int) texturePos.y, (int) tSize, (int) tSize
    };

    SDL_RenderCopy(renderer, image, &sourceRect, &destRect);
}
