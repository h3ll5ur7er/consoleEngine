#include <iostream>
#include "engine/engine.hpp"
#include "math/vector/vec2f.hpp"
#include "math/vector/vec3f.hpp"
#include "math/vector/vec4f.hpp"
#include "math/matrix/mat4f.hpp"

void printMat4f(Mat4f m) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << m.m[i][j] << " ";
        }
        std::cout << "\r\n";
    }
}

void mat4fTests() {
    std::cout << "Mat4fTests" << "\r\n";
    Mat4f m;
    Vec3f vec = {2.0f,3.0f,4.0f};
    Vec4f vec4 = vec;
    std::cout << "vec: " << vec.toString() << "\r\n";
    
    std::cout << vec4.toString() << "\r\n";
    std::cout << vec4.v[0] << " " << vec4.x << "\r\n";
    std::cout << vec4.v[1] << " " << vec4.y << "\r\n";
    std::cout << vec4.v[2] << " " << vec4.z << "\r\n";
    std::cout << vec4.v[3] << " " << vec4.w << "\r\n";

    std::cout << "vec4: " << vec4.toString() << "\r\n";

    std::cout << "\r\n" << "Identity" << "\r\n";
    // printMat4f(m = Mat4f::identity());
    // printVec3f(m * vec);
    std::cout << "\r\n" << "Translation" << "\r\n";
    std::cout << (m = Mat4f::translation({1, 2, 3})).toString() << "\r\n";
    std::cout << "Actual  "<<"\r\n" << (m * vec).toString()<< "\r\n";
    std::cout << "Expected" << "(3.000000, 5.000000, 7.000000)"<< "\r\n";
    // std::cout << "\r\n" << "rotX" << "\r\n";
    // std::cout << (m = Mat4f::rotationX(PI / 2)).toString() << "\r\n";
    // std::cout << (m * vec).toString()<< "\r\n";
    // std::cout << "\r\n" << "rotY" << "\r\n";
    // std::cout << (m = Mat4f::rotationY(PI / 2)).toString() << "\r\n";
    // std::cout << (m * vec).toString()<< "\r\n";
    // std::cout << "\r\n" << "rotZ" << "\r\n";
    // std::cout << (m = Mat4f::rotationZ(PI / 2)).toString() << "\r\n";
    // std::cout << (m * vec).toString()<< "\r\n";
    // std::cout << "\r\n" << "rotXYZ" << "\r\n";
    // std::cout << (m = Mat4f::rotationZ(PI / 2) * Mat4f::rotationY(PI / 2) * Mat4f::rotationX(PI / 2)).toString() << "\r\n";
    // std::cout << (m * vec).toString()<< "\r\n";

    std::cout << "\r\n";
}


void vec4fTests() {
    Vec2f v2_0 = {0.0f,0.0f};
    Vec2f v2_1 = {1.0f,1.0f};

    Vec3f v3_0 = {0.0f,0.0f,0.0f};
    Vec3f v3_1 = {1.0f,1.0f,1.0f};
    
    Vec4f v4_0 = {1.0f,1.0f,1.0f,1.0f};
    Vec4f v4_1 = {1.0f,1.0f,1.0f,1.0f};
    v4_0.x = 42;
    v4_0.v[2] = 69;
    std::cout << "Vec4fTests" << "\r\n";
    std::cout << v4_0.toString() << "\r\n";
    std::cout << v4_0.v[0] << " " << v4_0.x << "\r\n";
    std::cout << v4_0.v[1] << " " << v4_0.y << "\r\n";
    std::cout << v4_0.v[2] << " " << v4_0.z << "\r\n";
    std::cout << v4_0.v[3] << " " << v4_0.w << "\r\n";

    std::cout << "Vec3fTests" << "\r\n";
    std::cout << "lerp" << "\r\n";
    std::cout << Vec3f::lerp(v3_0, v3_1, 0.5).toString() << "\r\n";

    std::cout << "Vec2fTests" << "\r\n";
    std::cout << "lerp" << "\r\n";
    std::cout << Vec2f::lerp(v2_0, v2_1, 0.5).toString() << "\r\n";

}


void processKey(Key key) {
    switch (key) {
        case Key::Up:
            std::cout << "up\r\n";
            break;
        case Key::Down:
            std::cout << "down\r\n";
            break;
        case Key::Left:
            std::cout << "left\r\n";
            break;
        case Key::Right:
            std::cout << "right\r\n";
            break;
        case Key::Escape:
            std::cout << "escape\r\n";
            exit(0);
            break;
    }
}


void rawTermTest() {
    enableRawMode();
    while(true) {
        updateKeys();
        if(pressed(Key::Escape)) {
            exit(0);
            break;
        }
        if(pressed(Key::Up)) {
            std::cout << "up\r\n";
        }
        if(pressed(Key::Down)) {
            std::cout << "down\r\n";
        }
        if(pressed(Key::Left)) {
            std::cout << "left\r\n";
        }
        if(pressed(Key::Right)) {
            std::cout << "right\r\n";
        }
    }
}

void Engine::tests() {
    // std::cout << "Engine Tests" << "\r\n";
    // rawTermTest();
    // mat4fTests();
    // vec4fTests();
    // exit(0);
}