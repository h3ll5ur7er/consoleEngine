#include "engine/engine.hpp"
#include "engine/debug.hpp"

#include <chrono>
#include <thread>

bool __running = true;

void Engine::run() {
    enableRawMode();
    auto targetFrameTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::milliseconds(1000 / TARGET_FPS));
    init();
    auto appStartTs = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds lastTickDuration(0);
    std::chrono::nanoseconds lastFrameDuration(0);
    while (__running) {
        auto tickStartTs = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(tickStartTs - appStartTs).count();
        auto dt = std::chrono::duration_cast<std::chrono::nanoseconds>(lastTickDuration).count();
        updateKeys();
        if (pressed(Key::Escape)) { __running = false; }
        update(time, dt);
        auto updateEndTs = std::chrono::high_resolution_clock::now();
        draw(time, dt);
        auto drawEndTs = std::chrono::high_resolution_clock::now();
        stats();
        flip();

        auto tickEndTs = std::chrono::high_resolution_clock::now();
        lastTickDuration = (tickEndTs - tickStartTs);
        std::this_thread::sleep_for(targetFrameTime - lastTickDuration);
        auto frameEndTs = std::chrono::high_resolution_clock::now();
        lastFrameDuration = (frameEndTs - tickStartTs);
        logFps(lastFrameDuration.count(), lastTickDuration.count(), (updateEndTs - tickStartTs).count(), (drawEndTs - updateEndTs).count());
    }
}

