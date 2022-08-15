#pragma once

#include <cstdint>

typedef struct {
    uint8_t r, g, b, a;
    float d;
} color_t;


class Color {
    public:
    static constexpr color_t black = {0, 0, 0, 15, 0};
    static constexpr color_t red = {15, 0, 0, 15, 0};
    static constexpr color_t green = {0, 15, 0, 15, 0};
    static constexpr color_t yellow = {15, 15, 0, 15, 0};
    static constexpr color_t blue = {0, 0, 15, 15, 0};
    static constexpr color_t magenta = {15, 0, 15, 15, 0};
    static constexpr color_t cyan = {0, 15, 15, 15, 0};
    static constexpr color_t white = {15, 15, 15, 15, 0};
    static constexpr color_t gray = {7, 7, 7, 15, 0};
    static constexpr color_t light_red = {15, 0, 0, 15, 0};
    static constexpr color_t light_green = {0, 15, 0, 15, 0};
    static constexpr color_t light_yellow = {15, 15, 0, 15, 0};
    static constexpr color_t light_blue = {0, 0, 15, 15, 0};
    static constexpr color_t light_magenta = {15, 0, 15, 15, 0};
    static constexpr color_t light_cyan = {0, 15, 15, 15, 0};
    static constexpr color_t light_white = {15, 15, 15, 15, 0};
};
