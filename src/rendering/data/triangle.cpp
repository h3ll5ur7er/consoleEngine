#include "rendering/data/triangle.hpp"
#include "engine/constants.hpp"
#include <iostream>
Triangle::Triangle():
    v{  Vertex(),
        Vertex(),
        Vertex()},
    v0{v[0]},
    v1{v[1]},
    v2{v[2]} {}

Triangle::Triangle(const Triangle& other):
    v{  other.v0,
        other.v1,
        other.v2},
    v0{v[0]},
    v1{v[1]},
    v2{v[2]} {}

Triangle::Triangle(Vertex v0, Vertex v1, Vertex v2):
    v{v0, v1, v2},
    v0{v[0]},
    v1{v[1]},
    v2{v[2]} {}

Vertex& Triangle::operator[](size_t i) { return v[i]; }

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        v[0] = other.v[0];
        v[1] = other.v[1];
        v[2] = other.v[2];
    }
    return *this;
}

Triangle& Triangle::operator*=(const Mat4f& transform) {
    v0.position = transform * v0.position;
    v1.position = transform * v1.position;
    v2.position = transform * v2.position;
    return *this;
}

void Triangle::calculateNormal() {
    auto l1 = v1.position - v0.position;
    auto l2 = v2.position - v0.position;
    auto normal = l1.cross(l2).normalized();
    v0.normal = normal;
    v1.normal = normal;
    v2.normal = normal;
    v0.depth = v0.position.z;
    v1.depth = v1.position.z;
    v2.depth = v2.position.z;
}
Vec3f Triangle::center() const {
    return (v0.position + v1.position + v2.position) / 3;
}

void Triangle::toScreenSpace() {
    v0.position /= v0.position.z;
    v0.position = (v0.position + Vec3f(1, 1, 0)) * Vec3f(0.5 * WIDTH, 0.5 * HEIGHT, 1);

    v1.position /= v1.position.z;
    v1.position = (v1.position + Vec3f(1, 1, 0)) * Vec3f(0.5 * WIDTH, 0.5 * HEIGHT, 1);
    
    v2.position /= v2.position.z;
    v2.position = (v2.position + Vec3f(1, 1, 0)) * Vec3f(0.5 * WIDTH, 0.5 * HEIGHT, 1);
}