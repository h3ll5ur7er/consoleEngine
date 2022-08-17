#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <memory>

#include "rendering/data/model.hpp"




Model::Model():triangles() {}
Model::Model(const Model& other):triangles(other.triangles) {}
Model::Model(std::vector<Vertex> vertices, std::vector<uint16_t> indices):triangles() {
    for (size_t i = 0; i < indices.size(); i += 3) {
        triangles.push_back(Triangle(vertices[indices[i]], vertices[indices[i + 1]], vertices[indices[i + 2]]));
    }
}

std::shared_ptr<Model> Model::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + filename);
    }
    std::string line;
    std::vector<Vertex> vertices;
    std::vector<uint16_t> indices;
    while (std::getline(file, line)) {
        if (line.substr(0, 2) == "v ") {
            std::stringstream ss(line.substr(2));
            float x, y, z;
            int r, g, b;
            ss >> x >> y >> z >> r >> g >> b;
            vertices.push_back({Vec3f(x,y,z), Vec3f(), Vec3f(r,g,b), Vec2f(), 0.0f});
        } else if (line.substr(0, 2) == "f ") {
            std::stringstream ss(line.substr(2));
            float i0, i1, i2;
            ss >> i0 >> i1 >> i2;
            indices.push_back(i0-1);
            indices.push_back(i1-1);
            indices.push_back(i2-1);
        }
    }
    return std::make_shared<Model>(vertices, indices);
}
void Model::draw() {}