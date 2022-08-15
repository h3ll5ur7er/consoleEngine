#include "rendering/camera/orthographic.hpp"




OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top, float near, float far) : left(left), right(right), bottom(bottom), top(top), near(near), far(far) {}

Mat4f OrthographicCamera::projection() {
    return Mat4f::orthographicProjection(left, right, bottom, top, near, far);
}

Mat4f OrthographicCamera::view() {
    return Mat4f::lookAt(position, Mat4f::rotation(rotation) * Vec3f::forward(), Vec3f::up());
}
