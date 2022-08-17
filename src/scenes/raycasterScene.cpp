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
    if(pressed(Key::Up)) {
        playerPos.y -= 1;
    }
    if(pressed(Key::Down)) {
        playerPos.y += 1;
    }
    if(pressed(Key::Left)) {
        playerPos.x -= 1;
    }
    if(pressed(Key::Right)) {
        playerPos.x += 1;
    }

}

void RaycasterScene::drawPlayer() {
    engine->pen(Color::yellow);
    // engine->pixel(playerPos * gridSize + gridSize/2);
    engine->fcircle(playerPos * gridSize + gridSize/2, 2);
    engine->line(playerPos * gridSize + gridSize/2, (playerPos * gridSize + gridSize/2) + playerDirection * 5);
}
void RaycasterScene::drawMap() {
    for (int y = 0; y < mapSize.y; y++) {
        for (int x = 0; x < mapSize.x; x++) {
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

