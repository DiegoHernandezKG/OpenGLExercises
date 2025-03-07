#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>

typedef glm::vec3 Point;

typedef struct Line
{
    Point start;
    Point end;

    inline Line() {}
    inline Line(const Point& s, const Point& e): start(s), end(e) {}
}Line;




#endif