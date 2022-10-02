#include "main.hpp"
#include <iomanip>
#include "global.hpp"

#include "platform/platform.hpp"
#include "gfx/renderer.hpp"
#include "input/input.hpp"
#include "time/time.hpp"
#include "camera/camera.hpp"
#include "resource_loader/resource_loader.hpp"
#include "atlas/atlas.hpp"
#include "glm/gtc/constants.hpp"

Global global {};

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
        global.time->poll();
        global.platform->poll();

        update();

        while (global.time->shouldPhysicsTick())
        {
            tick();
            global.time->registerOneTick();
        }

        render();
        debug_stats();
    }
}

void tick ()
{

}

void update ()
{
    // check if escape is pressed
    if (Input::keyPressed(GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(global.platform->window, 1); // exit
    }

    vec2 input { Input::getAxis(GLFW_KEY_D, GLFW_KEY_A),
                      Input::getAxis(GLFW_KEY_W, GLFW_KEY_S)};

    if (input != glm::zero<glm::vec2>())
        input = glm::normalize(input);

    global.camera->setPosition(global.camera->getPosition() + 7.0f * global.time->delta * input);
}

void render ()
{
    global.renderer->prepare();

    auto blue_rect = global.atlas->textures[*"blue_rect"];
    auto yellow_rect = global.atlas->textures[*"yellow_rect"];
    auto green_rect = global.atlas->textures[*"green_rect"];

    global.renderer->render(blue_rect, glm::vec2(4.0, -3.0f));
    global.renderer->render(blue_rect, glm::vec2(-2.0, 1.0f));
    global.renderer->render(yellow_rect, glm::vec2(-4.0, 3.0f));
    //global.renderer->render(green_rect, glm::vec2(0.0, 0.0f));

    global.renderer->submit();
}

void debug_stats ()
{
    DEBUG_MILLISECONDS("FRAME: ", global.time->delta, 0);
    DEBUG_NUMBER("DRAW CALL: ", bgfx::getStats()->numDraw, 1);
}