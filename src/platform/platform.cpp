#include <iostream>
#include "platform.hpp"

void Platform::createWindow ()
{
    if (glfwInit() == GLFW_FALSE)
    {
        std::cerr << " [FAIL] : Could not initialize GLFW" << std::endl;
    }

    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "2D Renderer", nullptr, nullptr);
}

Platform::Platform()
{
    createWindow();
}

void Platform::poll()
{
    glfwPollEvents();
}