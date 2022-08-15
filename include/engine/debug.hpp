#pragma once

#include <cstdint>
#include <string>

#define FPS_BUFFER_SIZE 10
#define DEBUG_MESSAGE_COUNT 5

void stats();
void logFps(int64_t totalTime, int64_t usedTime, int64_t updateTime, int64_t drawTime);
void debug(std::string message);
