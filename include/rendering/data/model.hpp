#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <memory>

#include "rendering/data/vertex.hpp"
#include "rendering/data/triangle.hpp"

class Model {
public:
    Model();
    Model(const Model& other);
    Model(std::vector<Vertex> vertices, std::vector<uint16_t> indices);

    static std::shared_ptr<Model> load(const std::string& filename);
    void draw();

private:
public:
    std::vector<Triangle> triangles;
};