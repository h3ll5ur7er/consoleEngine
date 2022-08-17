#pragma once

#include "scenes/scene.hpp"
#include "math/vector/vec2i.hpp"
#include "math/vector/vec2f.hpp"

class Engine;

class RaycasterScene : public Scene {
public:
    RaycasterScene(std::shared_ptr<Engine> engine);
    

    void init() override;
    void terminate() override;
    void update(int64_t time, int64_t dt) override;
    void draw(int64_t time, int64_t dt) override;
private:
    Vec2i mapSize = {6, 6};
    Vec2i gridSize = {10, 10};
    Vec2i playerPos = {1, 1};
    float playerAngle = 0;
    Vec2f playerDirection = {1, 0};
    uint8_t map[6*6] = {
        1, 1, 1, 1, 1, 1,
        1, 0, 0, 1, 0, 1,
        1, 0, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 0, 1,
        1, 1, 1, 1, 1, 1,
    };
    void drawPlayer();
    void drawMap();
    
};

