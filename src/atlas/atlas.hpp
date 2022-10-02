#ifndef ARRABBIATA_ATLAS_HPP
#define ARRABBIATA_ATLAS_HPP

#include <map>
#include "bgfx/bgfx.h"
#include "glm/vec4.hpp"
#include<string>
#include <iostream>

struct AtlasTexture
{
    char atlas;
    glm::vec4 area;
};

struct Atlas
{
    std::map<char, std::pair<bgfx::TextureHandle, bgfx::TextureInfo>> atlases;
    std::map<char, AtlasTexture> textures;

    Atlas ();

    void insertTexture (const char *_name, const char *_atlas, glm::vec4 area)
    {
        textures.insert(std::pair<char, AtlasTexture>
                                (
                                        *_name,
                                        AtlasTexture { *_atlas, area }
                                        ));
    }
};


#endif //ARRABBIATA_ATLAS_HPP
