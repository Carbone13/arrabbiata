#include <iostream>
#include "platform.hpp"
#include "resource_loader/resource_loader.hpp"
#include "stb_image.h"

void Platform::createWindow ()
{
    if (glfwInit() == GLFW_FALSE)
    {
        std::cerr << " [FAIL] : Could not initialize GLFW" << std::endl;
    }


    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Arrabbiata", nullptr, nullptr);
    glfwSetWindowAspectRatio(window, 16, 9);

    GLFWimage images[1];
    images[0].pixels = stbi_load("res/icon/icon_1.png", &images[0].width, &images[0].height, 0, 4); //rgba channels
    glfwSetWindowIcon(window, 1, images);
    stbi_image_free(images[0].pixels);
}

Platform::Platform()
{
    createWindow();
}

void Platform::poll()
{
    glfwPollEvents();
}