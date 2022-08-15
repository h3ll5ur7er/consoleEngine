#pragma once

#include "math/math.hpp"

class Camera {
public:
    Vec3f position = {0, 0, 0};
    Vec3f rotation = {0, 0, 0};
    virtual Mat4f view() = 0;
    virtual Mat4f projection() = 0;
};
