#ifndef ARRABBIATA_GLOBAL_HPP
#define ARRABBIATA_GLOBAL_HPP

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

#define RENDER_WIDTH 16
#define RENDER_HEIGHT 9

struct Platform;
struct Renderer;
struct Time;
struct Camera;
struct ResourceLoader;
struct Atlas;

struct Global
{
    Platform *platform;
    Renderer *renderer;
    Time *time;
    Camera *camera;
    ResourceLoader *resourceLoader;
    Atlas *atlas;

    Global () = default;
};

// extern global, see main.cpp
extern Global global;

#endif //ARRABBIATA_GLOBAL_HPP
