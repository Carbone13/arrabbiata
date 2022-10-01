#define GLFW_EXPOSE_NATIVE_WIN32

#include "renderer.hpp"

void initializeBgfx ()
{
    bgfx::Init i {};

    i.type = bgfx::RendererType::Count; // automatically choose a renderer
    i.resolution.width = WINDOW_WIDTH;
    i.resolution.height = WINDOW_HEIGHT;
    i.resolution.reset = BGFX_RESET_VSYNC; // activate vsync
    i.platformData.nwh = glfwGetWin32Window(global.platform->window);

    if(!bgfx::init(i))
    {
        std::cerr << " - [FAIL] : Could not initialize BGFX" << std::endl;
    }

    bgfx::reset(WINDOW_WIDTH, WINDOW_HEIGHT, BGFX_RESET_VSYNC, i.resolution.format);
    bgfx::setDebug(BGFX_DEBUG_TEXT);
    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x003030FF, 1.0f, 0);
}

Renderer::Renderer()
{
    initializeBgfx();
}
