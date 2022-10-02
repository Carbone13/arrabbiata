#include "input.hpp"
#include "platform/platform.hpp"

bool Input::keyPressed(int key)
{
    return glfwGetKey(global.platform->window, key) == GLFW_PRESS;
}

int Input::getAxis(int keyA, int keyB)
{
    int v {0};

    if(keyPressed(keyA))
        v++;
    if(keyPressed(keyB))
        v--;

    return v;
}
