#include "time.hpp"

void Time::poll()
{
    auto now = glfwGetTime();
    delta = lastTime - now;
    lastTime = now;
}
