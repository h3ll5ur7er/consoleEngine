#pragma once

#include "math/vector/vec2f.hpp"
#include "math/vector/vec3f.hpp"

typedef struct Vertex {
public:
    Vec3f position;
    Vec3f normal;
    Vec3f color;
    Vec2f texcoord;
    float depth;
} Vertex;