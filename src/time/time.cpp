#include "time.hpp"

void Time::poll()
{
    auto now = glfwGetTime();
    delta = now - lastTime;
    lastTime = now;
}
