#ifndef OPENPOOL_TYPES_HH
#define OPENPOOL_TYPES_HH

#include "__i.hh"

struct Vec2 {
    int32_t x, y;
};

struct UVec2 {
    uint32_t x, y;
};

struct FVec2 {
    float x, y;
};

struct WVec2 {
    size_t x, y;
};

typedef SDL_Rect Rect;

struct FRect {
    float x, y, w, h;
};

#endif
