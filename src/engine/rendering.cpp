
#include <cstring>
#include <iostream>
#include <sstream>

#include "engine/engine.hpp"

#include "engine/constants.hpp"

void Engine::clear() {
    memset(screenBuffer, 0, sizeof(screenBuffer));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        screenBuffer[i].d = -100000.0f;
    }
}

void Engine::setPixel(int x, int y, color_t color) {
    screenBuffer[y * WIDTH + x] = color;
}

void Engine::flip() {
    std::cout << RESET;
    for (int y = 0; y < HEIGHT; y+=2) {
        std::stringstream ss;
        ss << std::string(LEFT_OFFSET, ' ');
        for (int x = 0; x < WIDTH; x++) {
            ss << colorize(screenBuffer[y * WIDTH + x], screenBuffer[(y+1) * WIDTH + x])<< "▄";
            // ss << visualizeDepth(screenBuffer[y * WIDTH + x], screenBuffer[(y+1) * WIDTH + x])<< "▄";
        }
        std::cout << ss.str() << RESET_COLOR << std::endl;
    }
    std::cout << SET_CURSOR(0, HEIGHT/2 + TOP_OFFSET + BOTTOM_OFFSET) << RESET_COLOR << std::endl;
}

