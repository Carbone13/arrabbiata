#ifndef ARRABBIATA_GLOBAL_HPP
#define ARRABBIATA_GLOBAL_HPP

#include "main.hpp"

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

struct Platform;
struct Renderer;
struct Input;
struct Time;

struct Global
{
    Platform *platform;
    Renderer *renderer;
    Input *input;
    Time *time;

    Global () = default;
};

// extern global, see main.cpp
extern Global global;

#endif //ARRABBIATA_GLOBAL_HPP
