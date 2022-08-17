#include <math.h>
#include "scenes/raycasterScene.hpp"
#include "engine/engine.hpp"

RaycasterScene::RaycasterScene(std::shared_ptr<Engine> engine):
    Scene(engine) { }

void RaycasterScene::init() {

}

void RaycasterScene::terminate() {

}

void RaycasterScene::update(int64_t time, int64_t dt) {
    playerAngle += 0.01;
    playerDirection = Vec2f(std::cos(playerAngle), -std::sin(playerAngle));

}

void RaycasterScene::drawPlayer() {
    engine->pen(Color::yellow);
    // engine->pixel(playerPos * gridSize + gridSize/2);
    engine->fcircle(playerPos * gridSize + gridSize/2, 2);
    engine->line(playerPos * gridSize + gridSize/2, (playerPos * gridSize + gridSize/2) + playerDirection * 5);
}
void RaycasterScene::drawMap() {
    for (size_t y = 0; y < mapSize.y; y++) {
        for (size_t x = 0; x < mapSize.x; x++) {
            Vec2i pos = {x, y};
            auto p0 = pos * gridSize;
            auto p1 = (pos + Vec2i::one()) * gridSize;
            auto b = Vec2i::one();
            switch (map[y * mapSize.x + x]) {
                case 0:
                    engine->pen(Color::black);
                    break;
                case 1:
                    engine->pen(Color::white);
                    break;
                default:
                    break;
            }
            engine->frect(p0, gridSize);

        }
    }
    
}

void RaycasterScene::draw(int64_t time, int64_t dt) {
    drawMap();
    drawPlayer();
}

