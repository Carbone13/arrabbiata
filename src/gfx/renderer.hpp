#ifndef ARRABBIATA_RENDERER_HPP
#define ARRABBIATA_RENDERER_HPP
// std
#include <map>
#include <vector>
// refs
#include "atlas/atlas.hpp"
// gfx
#include "bgfx/bgfx.h"
#include "vertex.hpp"
// maths
#include "glm/glm.hpp"

using namespace glm;
using namespace bgfx;

struct Renderer
{
    struct SpriteEntry
    {
        AtlasTexture texture;
        vec2 position {0.0f};
        vec2 scale {1.0f};
        float rotation { 0.0f};
        vec4 color { 1.0f};
    };

    Renderer ();

    void prepare ();
    void render (SpriteEntry sprite);
    void render (AtlasTexture texture, vec2 position = vec2(0.0f), vec2 scale = vec2{1.0f}, float rotation = 0);
    void submit ();

private:
    const int stride = 64 + 16; // 64 bits for transform, 16 bits for Atlas area

    std::map<char, std::vector<SpriteEntry>> batches;

    UniformHandle s_Texture {kInvalidHandle};
    ProgramHandle program {kInvalidHandle};

    VertexLayout vertexLayout {};
    VertexBufferHandle vbh {};
    IndexBufferHandle ibh {};

    const Vertex vertices[4]
    {
            // pos       // tex
        {0.0f, 1.0f, 0, 0x7fff},
        {1.0f, 0.0f, 0x7fff, 0},
        {0.0f, 0.0f, 0, 0},
        {1.0f, 1.0f, 0x7fff, 0x7fff},
    };

    const uint16_t indices[6]
    {
        0, 1, 2,
        0, 3, 1
    };
};


#endif //ARRABBIATA_RENDERER_HPP
