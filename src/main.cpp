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
    Platform platform {};
    global.platform = &platform;

    Renderer renderer {};
    global.renderer = &renderer;

    ResourceLoader resourceLoader {};
    global.resourceLoader = &resourceLoader;

    Atlas atlas {};
    global.atlas = &atlas;

    Time time {};
    global.time = &time;

    Camera camera {};
    global.camera = &camera;

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

        auto blue_rect = global.atlas->textures[*"blue_rect"];
        auto yellow_rect = global.atlas->textures[*"yellow_rect"];
        auto green_rect = global.atlas->textures[*"green_rect"];

        global.renderer->render(blue_rect, glm::vec2(4.0, -3.0f));
        //global.renderer->render(blue_rect, glm::vec2(-2.0, 1.0f));
        global.renderer->render(yellow_rect, glm::vec2(-4.0, 3.0f));
        //global.renderer->render(green_rect, glm::vec2(0.0, 0.0f));

        global.renderer->submit();
        debug();
    }

    closeApplication();
}

void closeApplication ()
{

}