#pragma once

#include "camera.hpp"

class Mat4f;

class OrthographicCamera : public Camera {
public:
    float left;
    float right;
    float bottom;
    float top;
    float near;
    float far;
    OrthographicCamera(float left, float right, float bottom, float top, float near, float far);
    Mat4f view() override;
    Mat4f projection() override;
};