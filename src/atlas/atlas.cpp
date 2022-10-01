#include "atlas.hpp"
#include "global.hpp"
#include "resource_loader/resource_loader.hpp"

const uint64_t pixelArtFlags =
        BGFX_SAMPLER_MAG_POINT |
        BGFX_SAMPLER_MIN_POINT |
        BGFX_SAMPLER_UVW_CLAMP;

Atlas::Atlas()
{
    atlas = global.resourceLoader->loadTexture("res/atlas.png", pixelArtFlags, 0, &info);
}
