#pragma once

#include "camera.hpp"

class Mat4f;

class PerspectiveCamera : public Camera {
public:
    float fov;
    float aspect;
    float near;
    float far;
    PerspectiveCamera(float fov, float aspect, float near, float far);
    Mat4f view() override;
    Mat4f projection() override;
};
