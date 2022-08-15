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
        std::cout << std::endl;
    }
}

void mat4fTests() {
    std::cout << "Mat4fTests" << std::endl;
    Mat4f m;
    Vec3f vec = {2.0f,3.0f,4.0f};
    Vec4f vec4 = vec;
    std::cout << "vec: " << vec.toString() << std::endl;
    
    std::cout << vec4.toString() << std::endl;
    std::cout << vec4.v[0] << " " << vec4.x << std::endl;
    std::cout << vec4.v[1] << " " << vec4.y << std::endl;
    std::cout << vec4.v[2] << " " << vec4.z << std::endl;
    std::cout << vec4.v[3] << " " << vec4.w << std::endl;

    std::cout << "vec4: " << vec4.toString() << std::endl;

    std::cout << std::endl << "Identity" << std::endl;
    // printMat4f(m = Mat4f::identity());
    // printVec3f(m * vec);
    std::cout << std::endl << "Translation" << std::endl;
    std::cout << (m = Mat4f::translation({1, 2, 3})).toString() << std::endl;
    std::cout << "Actual  "<<std::endl << (m * vec).toString()<< std::endl;
    std::cout << "Expected" << "(3.000000, 5.000000, 7.000000)"<< std::endl;
    // std::cout << std::endl << "rotX" << std::endl;
    // std::cout << (m = Mat4f::rotationX(PI / 2)).toString() << std::endl;
    // std::cout << (m * vec).toString()<< std::endl;
    // std::cout << std::endl << "rotY" << std::endl;
    // std::cout << (m = Mat4f::rotationY(PI / 2)).toString() << std::endl;
    // std::cout << (m * vec).toString()<< std::endl;
    // std::cout << std::endl << "rotZ" << std::endl;
    // std::cout << (m = Mat4f::rotationZ(PI / 2)).toString() << std::endl;
    // std::cout << (m * vec).toString()<< std::endl;
    // std::cout << std::endl << "rotXYZ" << std::endl;
    // std::cout << (m = Mat4f::rotationZ(PI / 2) * Mat4f::rotationY(PI / 2) * Mat4f::rotationX(PI / 2)).toString() << std::endl;
    // std::cout << (m * vec).toString()<< std::endl;

    std::cout << std::endl;
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
    std::cout << "Vec4fTests" << std::endl;
    std::cout << v4_0.toString() << std::endl;
    std::cout << v4_0.v[0] << " " << v4_0.x << std::endl;
    std::cout << v4_0.v[1] << " " << v4_0.y << std::endl;
    std::cout << v4_0.v[2] << " " << v4_0.z << std::endl;
    std::cout << v4_0.v[3] << " " << v4_0.w << std::endl;

    std::cout << "Vec3fTests" << std::endl;
    std::cout << "lerp" << std::endl;
    std::cout << Vec3f::lerp(v3_0, v3_1, 0.5).toString() << std::endl;

    std::cout << "Vec2fTests" << std::endl;
    std::cout << "lerp" << std::endl;
    std::cout << Vec2f::lerp(v2_0, v2_1, 0.5).toString() << std::endl;

}


void Engine::tests() {
    // mat4fTests();
    // vec4fTests();
    // exit(0);
}