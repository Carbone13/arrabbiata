#include "global.hpp"

#include "platform/platform.hpp"
#include "gfx/renderer.hpp"
#include "input/input.hpp"
#include "time/time.hpp"

Global global {};

int main ()
{
    Platform platform;
    global.platform = &platform;

    Renderer renderer;
    global.renderer = &renderer;

    Input input ;
    global.input = &input;

    while (!glfwWindowShouldClose(global.platform->window))
    {
        global.platform->poll();
        global.time->poll();

        // check if escape is pressed
        if (global.input->keyPressed(GLFW_KEY_ESCAPE))
        {
            glfwSetWindowShouldClose(global.platform->window, 1); // exit
        }

        bgfx::frame();
    }

    closeApplication();
}

void closeApplication ()
{

}