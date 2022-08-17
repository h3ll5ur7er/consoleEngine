#include <iostream>
#include "engine/engine.hpp"

#include "math/matrix/mat4f.hpp"
#include "rendering/data/model.hpp"
#include "rendering/data/vertex.hpp"
#include "rendering/camera/camera.hpp"


Vec3f lightDirection = (Vec3f::forward() + Vec3f::down()).normalized();

void Engine::setCamera(std::shared_ptr<Camera> camera) {
    this->camera = camera;
}

void Engine::rasterize(std::shared_ptr<Model> model, Mat4f world) {
    auto projection = camera->projection();
    auto view       = camera->view();
    auto triangles = model->triangles;
    for (auto& t: triangles) {
        t *= world;
        t.v0.color *= 1-std::abs(t.v0.normal.dot(lightDirection));
        // t.v0.color += 0.5f;
        t.v1.color *= 1-std::abs(t.v1.normal.dot(lightDirection));
        // t.v1.color += 0.5f;
        t.v2.color *= 1-std::abs(t.v2.normal.dot(lightDirection));
        // t.v2.color += 0.5f;

        t *= view;
        t.calculateNormal();
        
        t *= projection;
        t.toScreenSpace();
        
        auto center = t.center();
        auto cameraRay = center - camera->position;
        
        if (t.v0.normal.z>0) {
            ftriangle(t);
            // triangle(t);
        }
    }
}