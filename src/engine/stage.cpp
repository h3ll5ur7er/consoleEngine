#include "engine/engine.hpp"

#include "scenes/modelRendererScene.hpp"
#include "scenes/raycasterScene.hpp"

std::shared_ptr<Scene> currentScene;

void Engine::init(){
    loadScene(0);
}

void Engine::loadScene(int i){
    if(currentScene){
        currentScene->terminate();
    }
    switch(i){
        case 0:
            currentScene = std::make_shared<RaycasterScene>(shared_from_this());
            break;
        case 1:
            currentScene = std::make_shared<ModelRendererScene>(shared_from_this());
            break;
        default:
            currentScene = std::make_shared<ModelRendererScene>(shared_from_this());
            break;
    }

    currentScene->init();
}

void Engine::update(int64_t time, int64_t dt){
    currentScene->update(time, dt);
}

void Engine::draw(int64_t time, int64_t dt){
    currentScene->draw(time, dt);
}

