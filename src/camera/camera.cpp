#include "camera.hpp"

void Camera::setPosition(glm::vec2 _position)
{
    oldPosition = position;
    position = _position;
}

void Camera::recalculate()
{
    view = glm::translate(glm::mat4(1.0f), glm::vec3(-position.x, position.y, 0.0f));
}

void Camera::prepare()
{
    if(oldPosition != position)
    {
        recalculate();
    }

    bgfx::setViewTransform(0,
                           reinterpret_cast<void *>(&view),
                           reinterpret_cast<void *>(&proj));

    bgfx::setViewRect(0, 0, 0,
                      1600,
                      900);
}

