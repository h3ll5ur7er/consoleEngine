#pragma once

#include "scenes/scene.hpp"
#include "math/vector/vec3f.hpp"
#include "math/matrix/mat4f.hpp"
#include "rendering/data/model.hpp"

class Engine;
class PerspectiveCamera;

class ModelRendererScene : public Scene {
public:
    ModelRendererScene(std::shared_ptr<Engine> engine);
    
private:
    std::shared_ptr<Engine> engine;
    std::shared_ptr<PerspectiveCamera> camera;
    Mat4f modelRotation;
    Vec3f deltaRot;
    Mat4f rotationTransform;
    Mat4f modelTranslation1;
    Mat4f modelTranslation2;
    std::shared_ptr<Model> cube;

    void init();
    void terminate();
    void update(int64_t time, int64_t dt);
    void draw(int64_t time, int64_t dt);

};

