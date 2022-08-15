
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>

#include "engine/engine.hpp"
#include "math/vector/vec2i.hpp"
#include "math/vector/vec3f.hpp"
#include "math/matrix/mat4f.hpp"
#include "rendering/data/vertex.hpp"


void Engine::pen() {
    penColor = color_t();
}
void Engine::pen(color_t color) {
    penColor = color;
}
void Engine::pen(uint8_t r, uint8_t g, uint8_t b) {
    penColor = {r, g, b};
}
void Engine::pen(Vec3f color) {
    penColor = {(uint8_t)color.x, (uint8_t)color.y, (uint8_t)color.z};
}
void Engine::pixel(int x, int y) { // TODO: add depth
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }
    screenBuffer[y * WIDTH + x] = penColor;
}
void Engine::pixel(int x, int y, float d) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }
    if (screenBuffer[y * WIDTH + x].d > d) {
        return;
    }
    screenBuffer[y * WIDTH + x] = {penColor.r, penColor.g, penColor.b, 15, d};
}

void Engine::line(int x0, int y0, int x1, int y1){
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    while (true) {
        pixel(x0, y0);
        if (x0 == x1 && y0 == y1) {
            break;
        }
        int e2 = err;
        if (e2 > -dx) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy) {
            err += dx;
            y0 += sy;
        }
    }
}
// void Engine::line(int x0, int y0, int x1, int y1, std::vector<Vec2i>& points) {
//     int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int sx = x0 < x1 ? 1 : -1;
//     int sy = y0 < y1 ? 1 : -1;
//     int err = (dx > dy ? dx : -dy) / 2;
//     while (true) {
//         points.push_back(Vec2i(x0, y0));
//         pixel(x0, y0);
//         if (x0 == x1 && y0 == y1) {
//             break;
//         }
//         int e2 = err;
//         if (e2 > -dx) {
//             err -= dy;
//             x0 += sx;
//         }
//         if (e2 < dy) {
//             err += dx;
//             y0 += sy;
//         }
//     }
// }
void Engine::hline(int x, int y, int length){
    for (int i = 0; i < length; i++) {
        pixel(x + i, y);
    }
}
void Engine::vline(int x, int y, int length){
    for (int i = 0; i < length; i++) {
        pixel(x, y + i);
    }
}
void Engine::frect(int x, int y, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            pixel(x + j, y + i);
        }
    }
}
void Engine::rect(int x, int y, int w, int h){
    for (int i = 0; i < h; i++) {
        pixel(x, y + i);
        pixel(x + w - 1, y + i);
    }
    for (int i = 0; i < w; i++) {
        pixel(x + i, y);
        pixel(x + i, y + h - 1);
    }
}

void Engine::circle(int x, int y, int r) {
    for (int j = y-r; j <= y+r; j++) {
        for (int i = x-r; i <= x+r; i++) {
            float _x = i-x;
            float _y = j-y;
            float svalue = _x*_x + _y*_y - r*r;
            float value = svalue<0 ? -svalue : svalue;
            if (value <= 1.6) {
                pixel(i, j);
            }
        }
    }
}
void Engine::fcircle(int x, int y, int r){
    for (int j = y-r; j <= y+r; j++) {
        for (int i = x-r; i <= x+r; i++) {
            float _x = i-x;
            float _y = j-y;
            if (((_x*_x)+(_y*_y)-(r*r)) <= 1) {
                pixel(i, j);
            }
        }
    }
}
void Engine::ellipse(int x, int y, int a, int b){
    for (int j = y-b; j <= y+b; j++) {
        for (int i = x-a; i <= x+a; i++) {
            float _x = (float)i-x;
            float _y = (float)j-y;
            float _a = (float)a;
            float _b = (float)b;
            float svalue = ((_x*_x)/(_a*_a)+(_y*_y)/(_b*_b))-1;
            float value = svalue<0?-svalue:svalue;
            
            if (value < 0.1) {
                pixel(i, j);
            }
        }
    }
}
void Engine::fellipse(int x, int y, int a, int b){
    for (int j = y-b; j <= y+b; j++) {
        for (int i = x-a; i <= x+a; i++) {
            float _x = i-x;
            float _y = j-y;
            if (((_x*_x)/(a*a)+(_y*_y)/(b*b))-1 <= 0.1) {
                pixel(i, j);
            }
        }
    }
}

void Engine::triangle(int x1, int y1, int x2, int y2, int x3, int y3){
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}
// void Engine::triangle(int x1, int y1, int x2, int y2, int x3, int y3, std::vector<Vec2i>& points){
//     line(x1, y1, x2, y2, points);
//     line(x2, y2, x3, y3, points);
//     line(x3, y3, x1, y1, points);
// }

bool isRight(int x, int y, int x1, int y1, int x2, int y2) {
    return ((x2 - x1)*(y - y1) - (y2 - y1)*(x - x1)) > 0;
}

void Engine::ftriangle(int x1, int y1, int x2, int y2, int x3, int y3){
    triangle(x1, y1, x2, y2, x3, y3);
    int xmin = x1 < x2 ? x1<x3 ? x1 : x3 : x2<x3 ? x2 : x3;
    int xmax = x1 > x2 ? x1>x3 ? x1 : x3 : x2>x3 ? x2 : x3;
    int ymin = y1 < y2 ? y1<y3 ? y1 : y3 : y2<y3 ? y2 : y3;
    int ymax = y1 > y2 ? y1>y3 ? y1 : y3 : y2>y3 ? y2 : y3;
    for (int i = xmin; i <= xmax; i++) {
        for (int j = ymin; j <= ymax; j++) {
            bool r1 = isRight(i, j, x1, y1, x2, y2);
            bool r2 = isRight(i, j, x2, y2, x3, y3);
            bool r3 = isRight(i, j, x3, y3, x1, y1);
            if (r1 && r2 && r3) {
                pixel(i, j);
            }
        }
    }
}

// void Engine::ftriangle(int x1, int y1, int x2, int y2, int x3, int y3, std::vector<Vec2i>& points){
//     triangle(x1, y1, x2, y2, x3, y3, points);

//     int xmin = x1 < x2 ? x1<x3 ? x1 : x3 : x2<x3 ? x2 : x3;
//     int xmax = x1 > x2 ? x1>x3 ? x1 : x3 : x2>x3 ? x2 : x3;
//     int ymin = y1 < y2 ? y1<y3 ? y1 : y3 : y2<y3 ? y2 : y3;
//     int ymax = y1 > y2 ? y1>y3 ? y1 : y3 : y2>y3 ? y2 : y3;


//     std::vector<std::vector<float>> rows;
//     rows.reserve(ymax-ymin+1);
//     for (int i = 0; i <= ymax-ymin; i++) {
//         rows.push_back(std::vector<float>());
//         rows[i].reserve(xmax-xmin+1);
//     }
//     for (int i = 0; i < points.size(); i++) {
//         rows[points[i].y-ymin].push_back(points[i].x);
//     }
//     for (int i = 0; i < rows.size(); i++) {
//         std::sort(rows[i].begin(), rows[i].end());
//     }
//     for (int i = 0; i < rows.size(); i++) {
//         auto row = rows[i];
//         auto start = row[0];
//         auto end = row[row.size()-1];
//         for (int j = 0; j < end-start; j++) {
//             pixel(start + j, ymin + i);
//         }
//     }
// }


void Engine::pixel(Vec2i pos){
    pixel(pos.x, pos.y);
}
void Engine::line(Vec2i start, Vec2i end){
    line(start.x, start.y, end.x, end.y);
}
void Engine::hline(Vec2i start, int length){
    hline(start.x, start.y, length);
}
void Engine::vline(Vec2i start, int length){
    vline(start.x, start.y, length);
}
void Engine::rect(Vec2i origin, Vec2i size) {
    rect(origin.x, origin.y, size.x, size.y);
}
void Engine::frect(Vec2i origin, Vec2i size) {
    frect(origin.x, origin.y, size.x, size.y);
}
void Engine::circle(Vec2i center, int r) {
    circle(center.x, center.y, r);
}
void Engine::fcircle(Vec2i center, int r) {
    fcircle(center.x, center.y, r);
}
void Engine::ellipse(Vec2i center, int a, int b) {
    ellipse(center.x, center.y, a, b);
}
void Engine::fellipse(Vec2i center, int a, int b) {
    fellipse(center.x, center.y, a, b);
}
void Engine::triangle(Vec2i p1, Vec2i p2, Vec2i p3) {
    triangle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
}
void Engine::ftriangle(Vec2i p1, Vec2i p2, Vec2i p3) {
    ftriangle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
}

float lerp(float a, float b, float t) {
    return a + (b-a)*t;
}

void vertline(Vertex v0, Vertex v1, std::vector<Vertex>& vertices) {
    auto x0 = (float)(int)v0.position.x;
    auto y0 = (float)(int)v0.position.y;
    auto x1 = (float)(int)v1.position.x;
    auto y1 = (float)(int)v1.position.y;

    auto dx = std::abs(x1 - x0);
    auto dy = std::abs(y1 - y0);
    auto sx = x0 < x1 ? 1.0f : -1.0f;
    auto sy = y0 < y1 ? 1.0f : -1.0f;
    auto err = (dx > dy ? dx : -dy) / 2;
    int i = 0;
    while (true) {
        i++;
        vertices.push_back({Vec3f(x0, y0, 0), Vec3f(0, 0, 0), Vec3f(0,0,0), Vec2f(0,0), 0});
        if (std::abs(x0-x1) < 0.25f && std::abs(y0 - y1) < 0.25f) {
            break;
        }
        int e2 = err;
        if (e2 > -dx) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy) {
            err += dx;
            y0 += sy;
        }
    }
    auto offset = vertices.size() - i;
    float step = 1.0f;
    if(i > 1) {
        step = 1.0f / (i-1);
    }

    for (size_t n = 0; n < i; n++)
    {
        vertices[offset + n].depth      =        lerp(v0.depth,    v1.depth,    step * n);
        vertices[offset + n].color      = Vec3f::lerp(v0.color,    v1.color,    step * n);
        vertices[offset + n].normal     = Vec3f::lerp(v0.normal,   v1.normal,   step * n);
        vertices[offset + n].texcoord   = Vec2f::lerp(v0.texcoord, v1.texcoord, step * n);
    }
    
}


void Engine::triangle(Vertex p1, Vertex p2, Vertex p3) {
    std::vector<Vertex> vertices;
    vertline(p1, p2, vertices);
    vertline(p2, p3, vertices);
    vertline(p3, p1, vertices);
    for (auto& v : vertices) {
        pen(v.color);
        pixel(v.position.x, v.position.y);
    }
    
}
void Engine::ftriangle(Vertex p1, Vertex p2, Vertex p3) {

    std::vector<Vertex> vertices;
    vertline(p1, p2, vertices);
    vertline(p2, p3, vertices);
    vertline(p3, p1, vertices);

    int minY = (int)std::min({p1.position.y, p2.position.y, p3.position.y});
    int maxY = (int)std::max({p1.position.y, p2.position.y, p3.position.y});

    std::vector<std::vector<Vertex>> rows;
    rows.reserve((int)(maxY - minY) + 1);
    for (float y = 0; y <= (maxY-minY); y++) {
        rows.push_back(std::vector<Vertex>());
    }

    for (auto& v : vertices) {
        auto i = (int)v.position.v[1] - (int)minY;
        Vertex v2 = v;
        rows[i].push_back(v2);
    }

    for (auto& row : rows) {
        std::sort(row.begin(), row.end(), [](Vertex& vtx1, Vertex& vtx2) {
            return vtx1.position.x < vtx2.position.x;
        });
    }
    for (auto& row : rows) {
        auto v0 = row[0];
        auto v1 = row[row.size()-1];
        auto minX = v0.position.x;
        auto maxX = v1.position.x;
        auto dx = maxX - minX;
        auto step = 1.0f;
        if(dx > 1) {
            step = 1.0f / (dx-1);
        }
        // std::cout << "step: " << step << std::endl;

        for (float x = 0; x <= dx; x++) {
            auto depth = lerp(v0.depth, v1.depth, step * x);
            auto color = Vec3f::lerp(v0.color, v1.color, step * x);
            auto normal = Vec3f::lerp(v0.normal, v1.normal, step * x);
            auto texcoord = Vec2f::lerp(v0.texcoord, v1.texcoord, step * x);
            pen(color);
            // std::cout<<depth<< std::endl;
            pixel(minX + x, v0.position.y, depth);
        }
    }

}