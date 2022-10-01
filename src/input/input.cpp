#include "input.hpp"

bool Input::keyPressed(int key)
{
    return glfwGetKey(global.platform->window, key) == GLFW_PRESS;
}
