#include <cmath>
#include "scenes/raycasterScene.hpp"
#include "engine/engine.hpp"
#include "math/math.hpp"
#include "engine/debug.hpp"

RaycasterScene::RaycasterScene(std::shared_ptr<Engine> engine):
    Scene(engine) { }

void RaycasterScene::init() {

}

void RaycasterScene::terminate() {

}

void RaycasterScene::update(int64_t time, int64_t dt) {
    if(button(Key::Up) || button(Key::W)) {
        playerPos += playerDirection * playerSpeed;
    }
    if(button(Key::Down) || button(Key::S)) {
        playerPos -= playerDirection * playerSpeed/2;
    }
    if(button(Key::Left) || button(Key::A)) {
        playerAngle -= playerSpeed.y;
        fmodf(playerAngle, 2*PI);
        playerDirection = {cosf(playerAngle), sinf(playerAngle)};
    }
    if(button(Key::Right) || button(Key::D)) {
        playerAngle += playerSpeed.y;
        fmodf(playerAngle, 2*PI);
        playerDirection = {cosf(playerAngle), sinf(playerAngle)};
    }
}
void RaycasterScene::drawRays() {

    // DDA algorithm
    // https://en.wikipedia.org/wiki/Digital_differential_analyzer

    // for each ray
    



    // float m = playerDirection.y/playerDirection.x;
    // float m1 = 1.0f/m;
    // float m2 = m*m;
    // float m12 = m1*m1;
    // Vec2f scale = {
    //     sqrtf(1.0f+m2),
    //     sqrtf(1.0f+m12)
    // };
    // // float dx = Vec2f::right().dot(playerDirection);
    // // float dy = Vec2f::down().dot(playerDirection);
    // bool hit = false;
    // int stepsX = 0;
    // int stepsY = 0;
    // Vec2f hitPoint = playerPos;
    // int d = 0;
    // engine->pen(Color::cyan);
    // Vec2i tilePos = hitPoint/gridSize;
    // auto startOffset = Vec2f::one() - ((playerPos - tilePos)/gridSize);
    // float distX = startOffset.x*scale.x;
    // float distY = startOffset.y*scale.y;
    // while(!hit) {
    //     tilePos = hitPoint/gridSize;
    //     auto idx = (int)(tilePos.y) * mapSize.x + (int)tilePos.x;
    //     if (idx < 0 || idx >= mapSize.x * mapSize.y || map[idx] == 1) {
    //         hit = true;
    //     }
    //     else if(distX>distY){
    //         distX += scale.x * gridSize.x;
    //         hitPoint = playerPos + playerDirection * distX;
    //     } else {
    //         distY += scale.y * gridSize.y;
    //         hitPoint = playerPos + playerDirection * distY;
    //     }
    //     engine->pixel(hitPoint);
    //     d++;
    // }
    // for (int i = 1; i < 5; i++) {
    //     engine->pen(Color::magenta);
    //     engine->line(playerPos, hitPoint);
    //     debug(playerDirection.toString() + hitPoint.toString());
    // }
    // return;











    // Vec2f ray = static_cast<Vec2f>(static_cast<Vec2i>(playerPos / gridSize)) * gridSize;
    // auto aTan = -1/tanf(playerAngle);
    // Vec2f grid = {gridSize.x, gridSize.y};
    // Vec2f rayX = {0, playerAngle > PI ? ray.y - 0.0001f : ray.y + grid.y};
    // rayX.x = (playerPos.y - rayX.y) * aTan + playerPos.x;
    // Vec2f rayOffsetX = {
    //     0,
    //     playerAngle > PI ? -grid.y : grid.y
    // }; 
    // rayOffsetX.x = -rayOffsetX.y * aTan;

    // Vec2f rayY = {playerAngle > PI ? ray.x - 0.0001f : ray.x + grid.x, 0};
    // rayY.y = (playerPos.x - rayY.x) / aTan + playerPos.y;
    // Vec2f rayOffsetY = {
    //     playerAngle > PI ? -grid.x : grid.x,
    //     0
    // };
    // rayOffsetY.y = -rayOffsetY.x / aTan;

    // int dof = 0;
    // int dofMax = 8;
    // Vec2i hitPoint;
    // while (dof < dofMax) {
    //     if((rayX - playerPos).lengthSquared() < (rayY - playerPos).lengthSquared()) {
    //         auto tileX = static_cast<Vec2i>(rayX / gridSize);
    //         auto indexX = tileX.y * mapSize.x + tileX.x;
    //         if (indexX < 0 || indexX >= mapSize.x * mapSize.y || map[indexX] == 1) {
    //             dof = dofMax;
    //             hitPoint = static_cast<Vec2i>(rayX);
    //         } else {
    //             rayX += rayOffsetX;
    //             dof++;
    //         }
    //     } else {
    //         auto tileY = static_cast<Vec2i>(rayY / gridSize);
    //         auto indexY = tileY.y * mapSize.x + tileY.x;
    //         if (indexY < 0 || indexY >= mapSize.x * mapSize.y || map[indexY] == 1) {
    //             dof = dofMax;
    //             hitPoint = static_cast<Vec2i>(rayY);
    //         } else {
    //             rayY += rayOffsetY;
    //             dof++;
    //         }
    //     }
    // }
    // debug(playerPos.toString() + " " + rayX.toString() + " " + rayY.toString() + " " + hitPoint.toString() + "                            ");
    // engine->pen(Color::red);
    // engine->line(playerPos + Vec2i::one(), rayY + Vec2i::one());

    // engine->pen(Color::blue);
    // engine->line(playerPos - Vec2i::one(), rayY - Vec2i::one());
}

void RaycasterScene::drawPlayer() {
    engine->pen(Color::yellow);
    engine->fcircle(playerPos, 2);
    engine->line(playerPos, playerPos + playerDirection * 100);
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
            engine->pen(Color::gray);
            engine->pixel(p0);
            engine->pixel(p0 + Vec2i::right() * (gridSize.x-1));
            engine->pixel(p0 + Vec2i::down() * (gridSize.y-1));
            engine->pixel(p0 + gridSize - Vec2i::one());
        }
    }
    
}

void RaycasterScene::draw(int64_t time, int64_t dt) {
    drawMap();
    drawPlayer();
    drawRays();
}

