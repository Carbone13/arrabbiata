#ifndef ARRABBIATA_VERTEX_HPP
#define ARRABBIATA_VERTEX_HPP

#include <cstdint>

struct Vertex
{
    float x;
    float y;
    int16_t u;
    int16_t v;

    Vertex(float x, float y, int16_t u, int16_t v) : x(x), y(y), u(u), v(v){}
};

#endif //ARRABBIATA_VERTEX_HPP
