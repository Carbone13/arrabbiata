#ifndef BGFX_2D_CAMERA_HPP
#define BGFX_2D_CAMERA_HPP

#include "global.hpp"

#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/scalar_constants.hpp>

#include <bgfx/bgfx.h>

using namespace glm;

class Camera
{
    vec2 screenSize {-1.0, -1.0f};

    mat4 view {1.0f};
    mat4 proj {1.0f};

    vec2 position {0.0f, 0.0f};
    vec2 oldPosition {0.0f, 0.0f};

    void recalculate();
public:
    // GETTERS
    [[nodiscard]] vec2 getPosition() const { return position; }

    // SETTERS
    void setPosition (vec2 _position);

    void prepare ();

    Camera ()
    {
        screenSize = vec2(static_cast<float>(RENDER_WIDTH), static_cast<float>(RENDER_HEIGHT));
        recalculate();

        proj = glm::ortho(
                -screenSize.x / 2.0f,
                +screenSize.x / 2.0f,
                +screenSize.y / 2.0f,
                -screenSize.y / 2.0f,
                -1000.0f,
                1000.0f);
    }
};


#endif //BGFX_2D_CAMERA_HPP
