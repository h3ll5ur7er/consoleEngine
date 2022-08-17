#pragma once
#include <cstdint>
#include <string>
#include <vector>

#include "rendering/data/vertex.hpp"
#include "math/vector/vec3f.hpp"
#include "math/matrix/mat4f.hpp"

class Triangle {
public:
    Vertex v[3];
    Vertex& v0, v1, v2;
    Triangle();
    Triangle(const Triangle& other);
    Triangle(Vertex v0, Vertex v1, Vertex v2);

    Vertex& operator[](size_t i);

    Triangle& operator=(const Triangle& other);
    Triangle& operator*=(const Mat4f& transform);
    void calculateNormal();
    Vec3f center() const;
    void toScreenSpace();
};