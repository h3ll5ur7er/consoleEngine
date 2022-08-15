#include "math/math.hpp"
#include "engine/constants.hpp"
#include "engine/engine.hpp"
#include "scenes/modelRendererScene.hpp"
#include "rendering/camera/perspective.hpp"

ModelRendererScene::ModelRendererScene(std::shared_ptr<Engine> engine):
    Scene(engine),
    engine(engine),
    camera(std::make_shared<PerspectiveCamera>(PI / 3.0f, (float)HEIGHT / (float)WIDTH, 0.1f, 1000.0f)),
    modelRotation(Mat4f::identity()),
    deltaRot(Vec3f(0.1f, 0.1f, 0.0f)),
    rotationTransform(Mat4f::rotationX(0.03f) * Mat4f::rotationZ(0.01f)),
    modelTranslation1(Mat4f::translation({-0.5f, -0.5f, -0.5f})),
    modelTranslation2(Mat4f::translation({0.0f, 0.0f, 3.0f})),
    cube(Model::load("colorCube.obj")) {
        engine->setCamera(camera);
        camera->position = {0, 1, 0};
        camera->rotation = {-PI/4, 0, 0};
    }
    

void ModelRendererScene::terminate() {
}
void ModelRendererScene::init() {

    constexpr auto sizeMin = 0.0f;
    constexpr auto sizeMax = 1.0f;
}

void ModelRendererScene::update(int64_t time, int64_t dt) {
    modelRotation *= rotationTransform;
}

void ModelRendererScene::draw(int64_t time, int64_t dt) {
    engine->clear();
    engine->rasterize(cube, modelTranslation2 * modelRotation * modelTranslation1);
}
