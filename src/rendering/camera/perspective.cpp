#include "rendering/camera/perspective.hpp"

PerspectiveCamera::PerspectiveCamera(float fov, float aspect, float near, float far) : fov(fov), aspect(aspect), near(near), far(far) {}

Mat4f PerspectiveCamera::projection() {
    return Mat4f::perspectiveProjection(fov, aspect, near, far);
}

Mat4f PerspectiveCamera::view() {
    return Mat4f::lookAt(position, Mat4f::rotation(rotation) * Vec3f::forward(), Vec3f::up());
    return Mat4f::lookAt(position, Mat4f::rotation(rotation) * Vec3f::forward(), Vec3f::up());
}