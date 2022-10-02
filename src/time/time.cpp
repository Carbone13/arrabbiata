#include "time.hpp"
#include "GLFW/glfw3.h"

void Time::poll()
{
    auto now = static_cast<float>(glfwGetTime());

    delta = now - lastTime;
    lastTime = now;

    accumulator += delta;
}
