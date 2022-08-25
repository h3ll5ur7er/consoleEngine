#pragma once

#include "scenes/scene.hpp"
#include "math/vector/vec2i.hpp"
#include "math/vector/vec2f.hpp"

class Engine;

constexpr Vec2i gridSize = {13, 13};
constexpr Vec2i mapSize = {9, 9};
class RaycasterScene : public Scene {
public:
    RaycasterScene(std::shared_ptr<Engine> engine);
    

    void init() override;
    void terminate() override;
    void update(int64_t time, int64_t dt) override;
    void draw(int64_t time, int64_t dt) override;
private:
    // Vec2f playerPos = {gridSize.x + gridSize.x/2+1, gridSize.y + gridSize.y/2+1};
    Vec2f playerPos = {gridSize.x, gridSize.y};
    float playerAngle = 0.0001f;
    Vec2f playerDirection = {1, 0.0001f};
    Vec2f playerSpeed = {0.2f, 0.1f};
    uint8_t map[mapSize.x * mapSize.y] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 0, 1, 0, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 1, 1, 0, 1,
        1, 0, 1, 0, 0, 0, 1, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1,
    };
    void drawRays();
    void drawPlayer();
    void drawMap();
    
};

