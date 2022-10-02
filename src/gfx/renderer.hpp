#ifndef ARRABBIATA_RENDERER_HPP
#define ARRABBIATA_RENDERER_HPP

#include <map>
#include <vector>

#include "global.hpp"
#include "platform/platform.hpp"
#include "GLFW/glfw3native.h"
#include <iostream>

#include "bgfx/bgfx.h"
#include "glm/glm.hpp"
#include "vertex.hpp"
#include <glm/ext/matrix_transform.hpp>
#include "camera/camera.hpp"
#include "atlas/atlas.hpp"

struct Renderer
{
    struct SpriteEntry
    {
        AtlasTexture texture;
        glm::vec2 position {0.0f};
        glm::vec2 scale {1.0f};
        float rotation { 0.0f};
        glm::vec4 color { 1.0f};
    };

    Renderer ();

    void prepare ();
    void render (SpriteEntry sprite);
    void render (AtlasTexture texture, glm::vec2 position = glm::vec2(0.0f), glm::vec2 scale = glm::vec2{1.0f}, float rotation = 0);
    void submit ();

private:
    const int stride = 64 + 16;

    std::map<char, std::vector<SpriteEntry>> batches;

    bgfx::UniformHandle s_Texture {bgfx::kInvalidHandle};
    bgfx::ProgramHandle program {bgfx::kInvalidHandle};

    bgfx::VertexLayout vertexLayout {};
    bgfx::VertexBufferHandle vbh {};
    bgfx::IndexBufferHandle ibh {};

    const Vertex vertices[4]
            {
                    // pos           // tex
                    Vertex{0.0f, 1.0f, 0, 0x7fff},
                    Vertex{1.0f, 0.0f, 0x7fff, 0},
                    Vertex{0.0f, 0.0f, 0, 0},
                    Vertex{1.0f, 1.0f, 0x7fff, 0x7fff},
            };

    const uint16_t indices[6]
            {
                    0, 1, 2,
                    0, 3, 1
            };
};


#endif //ARRABBIATA_RENDERER_HPP
