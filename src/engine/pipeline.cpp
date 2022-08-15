#include <iostream>
#include "engine/engine.hpp"

#include "math/matrix/mat4f.hpp"
#include "rendering/data/model.hpp"
#include "rendering/data/vertex.hpp"
#include "rendering/camera/camera.hpp"


void Engine::setCamera(std::shared_ptr<Camera> camera) {
    this->camera = camera;
}

void Engine::rasterize(std::shared_ptr<Model> model, Mat4f world) {
    auto p    = camera->projection();
    auto view = camera->view();
    auto mv   = view * world;
    auto mvp  = p * view * world;
    auto vertices = model->vertices;
    auto indices = model->indices;
    // Object to camera space
    for (auto& v: vertices) {
        v.position = mv * v.position;
    }
    // calculate camera space normals
    for (int i = 0; i < indices.size(); i += 3) {
        auto p0 = vertices[indices[i]].position;
        auto p1 = vertices[indices[i + 1]].position;
        auto p2 = vertices[indices[i + 2]].position;
        auto l1 = p1 - p0;
        auto l2 = p2 - p0;
        auto normal = l1.cross(l2).normalized();
        vertices[indices[i]].normal = normal;
        vertices[indices[i]].depth = p0.z;
        vertices[indices[i + 1]].normal = normal;
        vertices[indices[i + 1]].depth = p1.z;
        vertices[indices[i + 2]].normal = normal;
        vertices[indices[i + 2]].depth = p2.z;
    }
    // camera to clip space
    for (auto& v: vertices) {
        v.position = p * v.position;
    }
    // exit(0);
    // Clip space to NDC
    for (auto& v: vertices) {
        v.position /= v.position.z;
    }
    // NDC to screen space
    for (auto& v: vertices) {
        v.position = (v.position + Vec3f(1, 1, 0)) * Vec3f(0.5 * WIDTH, 0.5 * HEIGHT, 1);
    }
    // Draw
    for (int i = 0; i < indices.size(); i += 3) {
        //only draw if the triangle is in faces the camera
        Vertex v0 = vertices[indices[i + 0]];
        Vertex v1 = vertices[indices[i + 1]];
        Vertex v2 = vertices[indices[i + 2]];
        auto l0 = (v1.position-v0.position);
        auto l1 = (v2.position-v0.position);
        auto n = l0.cross(l1).normalized();
        auto center = (v0.position + v1.position + v2.position) / 3;
        auto cameraRay = center - camera->position;
        if (v0.normal.z>0) {
            // pen(v0.color);
            ftriangle(v0, v1, v2);
            // triangle(v0, v1, v2);
        }
    }
}