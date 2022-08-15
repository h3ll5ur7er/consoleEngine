#pragma once

#define COLOR_CHANNELS 4
#define COLOR_BITS_PER_CHANNEL 4
#define COLOR_MAX 16

#define TOP_OFFSET 10
#define BOTTOM_OFFSET 10
#define LEFT_OFFSET 5
#define TARGET_FPS 30

#define WIDTH 120
#define HEIGHT 120


#define SET_CURSOR(x,y) "\x1b["<<y<<";"<<x<<"H"

#define RESET_CURSOR SET_CURSOR(0, TOP_OFFSET)
#define RESET_COLOR "\x1b[0m"
#define RESET RESET_COLOR << RESET_CURSOR


#define FG(color) "\x1b[38;2;"<<color.r*16<<";"<<color.g*16<<";"<<color.b*16<<"m"
#define BG(color) "\x1b[48;2;"<<color.r*16<<";"<<color.g*16<<";"<<color.b*16<<"m"
#define colorize(bg, fg) BG(bg) << FG(fg)

#define FGDepth(color) "\x1b[38;2;"<<color.d<<";"<<color.d<<";"<<color.d<<"m"
#define BGDepth(color) "\x1b[48;2;"<<color.d<<";"<<color.d<<";"<<color.d<<"m"
#define visualizeDepth(bg, fg) BGDepth(bg) << FGDepth(fg)

