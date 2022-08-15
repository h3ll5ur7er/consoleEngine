#include "engine/debug.hpp"

#include <iostream>
#include <string>
#include "engine/constants.hpp"

#include "math/math.hpp"


int fps_buffer_index = 0;
int64_t fps_buffer[FPS_BUFFER_SIZE] = {0,0,0,0,0,0,0,0,0,0};
int64_t usage_buffer[FPS_BUFFER_SIZE] = {0,0,0,0,0,0,0,0,0,0};
int64_t update_buffer[FPS_BUFFER_SIZE] = {0,0,0,0,0,0,0,0,0,0};
int64_t draw_buffer[FPS_BUFFER_SIZE] = {0,0,0,0,0,0,0,0,0,0};

std::string messages[DEBUG_MESSAGE_COUNT] = {
    "FPS: 00.00 Usage: 00.00 % (Update: 0.00 %, Draw: 0.00 %, Other: 00.00 %)",
    "<debug>",
    "",
    "",
    "" };

void stats() {
    for (size_t i = 0; i < DEBUG_MESSAGE_COUNT; i++)
    {
        std::cout << SET_CURSOR(LEFT_OFFSET, i+2) << RESET_COLOR;
        std::cout << messages[i];
    }
}

void logFps(int64_t totalTime, int64_t usedTime, int64_t updateTime, int64_t drawTime) {
    fps_buffer[fps_buffer_index] = totalTime;
    update_buffer[fps_buffer_index] = updateTime;
    draw_buffer[fps_buffer_index] = drawTime;
    usage_buffer[fps_buffer_index++] = usedTime;
    fps_buffer_index %= FPS_BUFFER_SIZE;
    int sumFrame = 0;
    int sumUsage = 0;
    int sumUpdate = 0;
    int sumDraw = 0;
    for (int i = 0; i < FPS_BUFFER_SIZE; i++) {
        sumFrame += fps_buffer[i];
        sumUsage += usage_buffer[i];
        sumUpdate += update_buffer[i];
        sumDraw += draw_buffer[i];
    }
    float frameAvgNs = (float)sumFrame / FPS_BUFFER_SIZE;
    float usageAvgNs = (float)sumUsage / FPS_BUFFER_SIZE;
    float updateAvgNs = (float)sumUpdate / FPS_BUFFER_SIZE;
    float drawAvgNs = (float)sumDraw / FPS_BUFFER_SIZE;

    float fps = 1000000000.0f / frameAvgNs;
    float usagePercent = ((float)usedTime / (float)totalTime) * 100;
    float updatePercent = ((float)updateTime / (float)totalTime) * 100;
    float drawPercent = ((float)drawTime / (float)totalTime) * 100;
    messages[0] = std::string("FPS: ").append(toFixed(fps))
                    .append(" Usage: ").append(toFixed(usagePercent)).append(" %")
                    .append(" (Update: ").append(toFixed(updatePercent)).append(" %")
                    .append(", Draw: ").append(toFixed(drawPercent)).append(" %")
                    .append(", Other: ").append(toFixed(usagePercent-(updatePercent + drawPercent))).append(" %)                               ");
}

void debug(std::string message) {
    messages[1] = message;
}