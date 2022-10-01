#ifndef ARRABBIATA_TIME_HPP
#define ARRABBIATA_TIME_HPP

#include "GLFW/glfw3.h"

struct Time
{
    float delta;

    void poll();

private:
    float lastTime {0};
};

#endif //ARRABBIATA_TIME_HPP
