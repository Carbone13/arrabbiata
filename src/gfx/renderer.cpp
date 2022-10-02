#define GLFW_EXPOSE_NATIVE_WIN32

#include "renderer.hpp"

#include "_compiled/shaders/sprite/sprite.vs.hpp"
#include "_compiled/shaders/sprite/sprite.fs.hpp"

void initializeBgfx ()
{
    bgfx::Init i {};
    bgfx::PlatformData pd {};
    pd.nwh = glfwGetWin32Window(global.platform->window);

    i.type = bgfx::RendererType::Count; // automatically choose a renderer
    i.resolution.width = WINDOW_WIDTH;
    i.resolution.height = WINDOW_HEIGHT;
    i.resolution.reset = BGFX_RESET_VSYNC; // activate vsync
    i.platformData = pd;

    if(!bgfx::init(i))
    {
        std::cerr << " - [FAIL] : Could not initialize BGFX" << std::endl;
    }

    bgfx::reset(WINDOW_WIDTH, WINDOW_HEIGHT, BGFX_RESET_VSYNC, i.resolution.format);
    bgfx::setDebug(BGFX_DEBUG_TEXT);
    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x003030FF, 1.0f, 0);
    bgfx::setViewRect(0, 0, 0, bgfx::BackbufferRatio::Equal);
}

Renderer::Renderer()
{
    initializeBgfx();

    s_Texture = bgfx::createUniform("s_Texture", bgfx::UniformType::Sampler);

    vertexLayout.begin();
    vertexLayout.add(bgfx::Attrib::Position,
                     2, bgfx::AttribType::Float);
    vertexLayout.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Int16, true, true);
    vertexLayout.end();

    vbh = bgfx::createVertexBuffer(bgfx::makeRef(vertices, sizeof(vertices)),
                                   vertexLayout);

    ibh = bgfx::createIndexBuffer(bgfx::makeRef(indices, sizeof(indices)));

    auto vs = bgfx::createShader(bgfx::makeRef(sprite_vs, sizeof(sprite_vs)));
    auto fs = bgfx::createShader(bgfx::makeRef(sprite_fs, sizeof(sprite_fs)));
    program = bgfx::createProgram(vs, fs, true);
}

void Renderer::prepare()
{
    //bgfx::touch(0);
    global.camera->prepare();
}

void Renderer::submit()
{
    for (const auto& batch : batches)
    {
        auto atlas = global.atlas->atlases[batch.first].first;
        auto atlasInfo = global.atlas->atlases[batch.first].second;

        auto sprites = batch.second;

        // bind texture
        bgfx::setTexture(0, s_Texture, atlas);

        bgfx::InstanceDataBuffer idb{};
        bgfx::allocInstanceDataBuffer(&idb, sprites.size(), stride);
        uint8_t *data = idb.data;

        for (auto sprite : sprites)
        {
            auto spriteArea = sprite.texture.area;
            auto scale = sprite.scale * glm::vec2(sprite.texture.area.z, sprite.texture.area.w);

            auto* mtx = (glm::mat4x4*)(float*)data;

            // translate
            *mtx = glm::translate(glm::mat4x4{1.0f}, glm::vec3(sprite.position, 0.0f));
            // rotate (centered pivot)
            *mtx = glm::translate(*mtx, glm::vec3(0.5f * scale.x, 0.5f * scale.y, 0.0f));
            *mtx = glm::rotate(*mtx, glm::radians(sprite.rotation), glm::vec3(0.0f, 0.0f, 1.0f));
            *mtx = glm::translate(*mtx, glm::vec3(-0.5f * scale.x, -0.5f * scale.y, 0.0f));
            // scale
            *mtx = glm::scale(*mtx, glm::vec3(scale, 1.0f));

            auto* area = (float*)&data[64];
            area[0] = spriteArea.x / (float)atlasInfo.width;
            area[1] = spriteArea.y / (float)atlasInfo.height;
            area[2] = spriteArea.z / (float)atlasInfo.width;
            area[3] = spriteArea.w / (float)atlasInfo.height;

            data += stride;
        }

        // Set vertex and index buffer.
        bgfx::setVertexBuffer(0, vbh);
        bgfx::setIndexBuffer(ibh);

        // Set instance data buffer.
        bgfx::setInstanceDataBuffer(&idb);

        // Set render states.
        bgfx::setState(BGFX_STATE_DEFAULT);

        // Submit primitive for rendering to view 0.
        bgfx::submit(0, program);

        sprites.clear();
    }

    bgfx::frame();
}

void Renderer::render(Renderer::SpriteEntry sprite)
{
    batches[sprite.texture.atlas].push_back(sprite);
}

void Renderer::render(AtlasTexture texture, glm::vec2 position, glm::vec2 scale, float rotation)
{
    batches[texture.atlas].push_back({texture, position, scale, rotation});
}


