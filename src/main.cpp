#include <iomanip>
#include "global.hpp"

#include "platform/platform.hpp"
#include "gfx/renderer.hpp"
#include "input/input.hpp"
#include "time/time.hpp"
#include "camera/camera.hpp"
#include "resource_loader/resource_loader.hpp"
#include "atlas/atlas.hpp"

Global global {};

void debug ()
{
    auto dt = std::stringstream() << "FRAME: "
                                  << std::fixed << std::setprecision(3)
                                  << global.time->delta << " ms";
    bgfx::dbgTextPrintf(0, 0, ((0x2 + 0) << 4) | 0xF, dt.str().c_str());
    
    auto str =
            std::stringstream() << "DRAW CALL: " << bgfx::getStats()->numDraw;
    bgfx::dbgTextPrintf(0, 1, ((0x2 + 1) << 4) | 0xF, str.str().c_str());
}

int main ()
{
    Platform platform;
    global.platform = &platform;

    Renderer renderer;
    global.renderer = &renderer;

    Time time;
    global.time = &time;

    Camera camera;
    global.camera = &camera;

    ResourceLoader resourceLoader;
    global.resourceLoader = &resourceLoader;

    Atlas atlas;
    global.atlas = &atlas;

    while (!glfwWindowShouldClose(global.platform->window))
    {
        global.platform->poll();
        global.renderer->prepare();
        global.time->poll();

        // check if escape is pressed
        if (Input::keyPressed(GLFW_KEY_ESCAPE))
        {
            glfwSetWindowShouldClose(global.platform->window, 1); // exit
        }

        global.renderer->render(global.atlas->atlas,
                                Renderer::SpriteEntry
                                { glm::vec4(0, 0, 6, 4)
                                });
        global.renderer->render(global.atlas->atlas,
                                Renderer::SpriteEntry
                                        { glm::vec4(0, 0, 6, 4),
                                          glm::vec2(-3.0f, 2.0f)
                                        });
        global.renderer->render(global.atlas->atlas,
                                Renderer::SpriteEntry
                                        { glm::vec4(0, 0, 6, 4),
                                          glm::vec2(+3.0f, -2.0f)
                                        });
        global.renderer->submit();
        debug();
    }

    closeApplication();
}

void closeApplication ()
{

}