#ifndef ARRABBIATA_ATLAS_HPP
#define ARRABBIATA_ATLAS_HPP
#include <map>

#include "bgfx/bgfx.h"
#include "glm/vec4.hpp"

using namespace glm;
using namespace bgfx;

struct AtlasTexture
{
    char atlas;
    vec4 area;
};

struct Atlas
{
    std::map<char, std::pair<TextureHandle, TextureInfo>> atlases;
    std::map<char, AtlasTexture> textures;

    Atlas ();

    void insertTexture (const char *_name, const char *_atlas, vec4 area)
    {
        textures.insert(std::pair<char, AtlasTexture>
                                (
                                        *_name,
                                        AtlasTexture { *_atlas, area }
                                        ));
    }
};


#endif //ARRABBIATA_ATLAS_HPP
