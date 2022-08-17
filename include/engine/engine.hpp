#pragma once

#include <memory>
#include <vector>

#include "engine/constants.hpp"
#include "engine/color.hpp"
#include "rendering/data/vertex.hpp"
#include "rendering/data/triangle.hpp"


class Camera;
class Model;
class Vec2i;
class Vec3f;
class Mat4f;

class Engine : public std::enable_shared_from_this<Engine> {
public:
    // tests.cpp
    void tests();

    // mainLoop.cpp
    void run();

    // rendering.cpp
    void clear();
    void flip();
    void setPixel(int x, int y, color_t color);

    // graphics.cpp
    void pen();
    void pen(color_t color);
    void pen(uint8_t r, uint8_t g, uint8_t b);
    void pen(Vec3f color);
    void pixel(int x, int y);
    void pixel(int x, int y, float d);
    void line(int x0, int y0, int x1, int y1);
    void hline(int x, int y, int length);
    void vline(int x, int y, int length);
    void rect(int x, int y, int w, int h);
    void frect(int x, int y, int w, int h);
    void circle(int x, int y, int r);
    void fcircle(int x, int y, int r);
    void ellipse(int x, int y, int a, int b);
    void fellipse(int x, int y, int a, int b);
    void triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    void ftriangle(int x1, int y1, int x2, int y2, int x3, int y3);
    void pixel(Vec2i pos);
    void line(Vec2i start, Vec2i end);
    void hline(Vec2i start, int length);
    void vline(Vec2i start, int length);
    void rect(Vec2i origin, Vec2i size);
    void frect(Vec2i origin, Vec2i size);
    void circle(Vec2i center, int r);
    void fcircle(Vec2i center, int r);
    void ellipse(Vec2i center, int a, int b);
    void fellipse(Vec2i center, int a, int b);
    void triangle(Vec2i p1, Vec2i p2, Vec2i p3);
    void ftriangle(Vec2i p1, Vec2i p2, Vec2i p3);
    void triangle(Vertex p1, Vertex p2, Vertex p3);
    void ftriangle(Vertex p1, Vertex p2, Vertex p3);
    void triangle(Triangle tri);
    void ftriangle(Triangle tri);

    // pipeline.cpp
    void setCamera(std::shared_ptr<Camera> camera);
    void rasterize(std::shared_ptr<Model> model, Mat4f world);

    // stage.cpp
    void init();
    void loadScene(int n);
    void update(int64_t time, int64_t dt);
    void draw(int64_t time, int64_t dt);

private:
    color_t screenBuffer[WIDTH * HEIGHT];
    color_t penColor;
    std::shared_ptr<Camera> camera;

};

