#pragma once
#include <cstdint>
#include <string>
#include <vector>

#include "rendering/data/vertex.hpp"

class Triangle {
public:
    Vertex v[3];
    Vertex& v0, v1, v2;
    inline Triangle(): v{Vertex(),Vertex(),Vertex()}, v0{v[0]}, v1{v[1]}, v2{v[2]} {}
    inline Triangle(const Triangle& other): v{other.v0, other.v1, other.v2}, v0{v[0]}, v1{v[1]}, v2{v[2]} {}
    inline Triangle(Vertex v0, Vertex v1, Vertex v2): v{v0, v1, v2}, v0{v[0]}, v1{v[1]}, v2{v[2]} {}

    inline Vertex& operator[](size_t i) { return v[i]; }

    inline Triangle& operator=(const Triangle& other) {
        if (this != &other) {
            v[0] = other.v[0];
            v[1] = other.v[1];
            v[2] = other.v[2];
        }
        return *this;
    }
};