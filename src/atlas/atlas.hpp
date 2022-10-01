#ifndef ARRABBIATA_ATLAS_HPP
#define ARRABBIATA_ATLAS_HPP

#include "bgfx/bgfx.h"

struct Atlas
{
    bgfx::TextureHandle atlas;
    bgfx::TextureInfo info;
    Atlas ();
};

#endif //ARRABBIATA_ATLAS_HPP
