#include "atlas.hpp"
#include "global.hpp"
#include "resource_loader/resource_loader.hpp"

const uint64_t pixelArtFlags =
        BGFX_SAMPLER_MAG_POINT |
        BGFX_SAMPLER_MIN_POINT |
        BGFX_SAMPLER_UVW_CLAMP;

Atlas::Atlas()
{
    // load atlases

    TextureInfo info{};
    atlases[*"main_atlas"] = std::pair<TextureHandle, TextureInfo>
            (global.resourceLoader->loadTexture("res/atlas.png", pixelArtFlags, 0, &info),
                                            info);

    // load textures
    insertTexture("blue_rect", "main_atlas", vec4(0, 0, 6, 4));
    insertTexture("yellow_rect", "main_atlas", vec4(6, 0, 4, 4));
    insertTexture("green_rect", "main_atlas", vec4(0, 4, 16, 5));
}
