#include <math.h>
#include <algorithm>
#include <iostream>
#include "math/vector/vec3f.hpp"
#include "math/vector/vec2f.hpp"

Vec3f::Vec3f():
    v{0, 0, 0},
    x(v[0]),
    y(v[1]),
    z(v[2]) {}

Vec3f::Vec3f(float x, float y, float z):
    v{x,y,z},
    x(v[0]),
    y(v[1]),
    z(v[2]) {}

Vec3f::Vec3f(float n):
    v{n, n, n},
    x(v[0]),
    y(v[1]),
    z(v[2]) {}

Vec3f::Vec3f(const Vec2f& other):
    v{other.x, other.y, 0},
    x(v[0]),
    y(v[1]),
    z(v[2]) {}

Vec3f::Vec3f(const Vec2f& other, float z):
    v{other.x, other.y, z},
    x(v[0]),
    y(v[1]),
    z(v[2]) {}

Vec3f::Vec3f(const Vec3f& other):
    v{other.x, other.y, other.z},
    x(v[0]),
    y(v[1]),
    z(v[2]) {}

Vec3f& Vec3f::operator=(const Vec3f& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

Vec3f Vec3f::operator+(const Vec3f& other) const {
    return {x + other.x, y + other.y, z + other.z};
}

Vec3f Vec3f::operator-(const Vec3f& other) const {
    return {x - other.x, y - other.y, z - other.z};
}

Vec3f Vec3f::operator*(const Vec3f& other) const {
    return {x * other.x, y * other.y, z * other.z};
}

Vec3f Vec3f::operator/(const Vec3f& other) const {
    return {x / other.x, y / other.y, z / other.z};
}

Vec3f Vec3f::operator*(float scalar) const {
    return {x * scalar, y * scalar, z * scalar};
}

Vec3f Vec3f::operator/(float scalar) const {
    return {x / scalar, y / scalar, z / scalar};
}

Vec3f Vec3f::operator-() const {
    return {-x, -y, -z};
}

Vec3f& Vec3f::operator+=(const Vec3f& other)  {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vec3f& Vec3f::operator-=(const Vec3f& other)  {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vec3f& Vec3f::operator*=(const Vec3f& other)  {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

Vec3f& Vec3f::operator/=(const Vec3f& other)  {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

Vec3f& Vec3f::operator*=(float scalar)  {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Vec3f& Vec3f::operator/=(float scalar)  {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

Vec2f Vec3f::xy() const {
    return Vec2f(x, y);
}

Vec2f Vec3f::xz() const {
    return Vec2f(x, z);
}

Vec2f Vec3f::yz() const {
    return Vec2f(y, z);
}

float Vec3f::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

float Vec3f::lengthSquared() const {
    return x * x + y * y + z * z;
}

Vec3f Vec3f::normalized() const {
    float len = length();
    return {x / len, y / len, z / len};
}

Vec3f Vec3f::normalize() {
    float len = length();
    x /= len;
    y /= len;
    z /= len;
    return *this;
}

float Vec3f::dot(const Vec3f& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vec3f Vec3f::cross(const Vec3f& other) const {
    return {y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x};
}

float Vec3f::distance(const Vec3f& other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2) + std::pow(z - other.z, 2));
}

float Vec3f::distanceSquared(const Vec3f& other) const {
    return std::pow(x - other.x, 2) + std::pow(y - other.y, 2) + std::pow(z - other.z, 2);
}

float Vec3f::angle(const Vec3f& other) const {
    return std::acos(dot(other) / (length() * other.length()));
}

Vec3f Vec3f::rotate(float angle) const {
    float c = std::cos(angle);
    float s = std::sin(angle);
    return {x * c - y * s, x * s + y * c, z};
}

Vec3f Vec3f::rotateAround(float angle, const Vec3f& center) const {
    Vec3f v = *this - center;
    v = v.rotate(angle);
    return v + center;
}
std::string Vec3f::toString(bool integer) const {
    if (integer) {
        return std::string("(") + std::to_string((int)x) + ", " + std::to_string((int)y) + ", " + std::to_string((int)z) + ")";
    } else {
        return std::string("(") + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
    }
}


Vec3f Vec3f::zero() { return {0, 0, 0}; };
Vec3f Vec3f::one() { return {1, 1, 1}; };
Vec3f Vec3f::up() { return {0, 1, 0}; };
Vec3f Vec3f::down() { return {0, -1, 0}; };
Vec3f Vec3f::left() { return {-1, 0, 0}; };
Vec3f Vec3f::right() { return {1, 0, 0}; };
Vec3f Vec3f::forward() { return {0, 0, 1}; };
Vec3f Vec3f::back() { return {0, 0, -1}; };

float clamp(float value, float min, float max) {
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    } else {
        return value;
    }
}

Vec3f Vec3f::lerp(const Vec3f& a, const Vec3f& b, float t) {
    return a + (b - a) * clamp(t, 0.0f, 1.0f);
}