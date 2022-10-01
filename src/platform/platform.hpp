#ifndef ARRABBIATA_PLATFORM_HPP
#define ARRABBIATA_PLATFORM_HPP

#include <global.hpp>

#include "GLFW/glfw3.h"

struct Platform
{
    GLFWwindow *window {nullptr};

    Platform ();

    void poll();

private:
    void createWindow ();
};

#endif //ARRABBIATA_PLATFORM_HPP
