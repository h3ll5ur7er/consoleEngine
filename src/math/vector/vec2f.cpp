#include <math.h>
#include "math/vector/vec2f.hpp"
#include "math/vector/vec2i.hpp"


Vec2f::Vec2f():
    v{0,0},
    x(v[0]),
    y(v[1]) {}

Vec2f::Vec2f(float x, float y):
    v{x,y},
    x(v[0]),
    y(v[1]) {}

Vec2f::Vec2f(float n):
    v{n,n},
    x(v[0]),
    y(v[1]) {}

Vec2f::Vec2f(const Vec2f& other):
    v{other.x, other.y},
    x(v[0]),
    y(v[1]) {}

Vec2f& Vec2f::operator=(const Vec2f& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Vec2f::operator Vec2i() const {
    return {(int)x, (int)y};
}

Vec2f Vec2f::operator+(const Vec2f& other) const {
    return Vec2f(x + other.x, y + other.y);
}

Vec2f Vec2f::operator-(const Vec2f& other) const {
    return Vec2f(x - other.x, y - other.y);
}

Vec2f Vec2f::operator*(const Vec2f& other) const {
    return Vec2f(x * other.x, y * other.y);
}

Vec2f Vec2f::operator/(const Vec2f& other) const {
    return Vec2f(x / other.x, y / other.y);
}

Vec2f Vec2f::operator*(float scalar) const {
    return Vec2f(x * scalar, y * scalar);
}

Vec2f Vec2f::operator/(float scalar) const {
    return Vec2f(x / scalar, y / scalar);
}

Vec2f Vec2f::operator-() const {
    return Vec2f(-x, -y);
}

Vec2f& Vec2f::operator+=(const Vec2f& other)  {
    x += other.x;
    y += other.y;
    return *this;
}

Vec2f& Vec2f::operator-=(const Vec2f& other)  {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2f& Vec2f::operator*=(const Vec2f& other)  {
    x *= other.x;
    y *= other.y;
    return *this;
}

Vec2f& Vec2f::operator/=(const Vec2f& other)  {
    x /= other.x;
    y /= other.y;
    return *this;
}

Vec2f& Vec2f::operator*=(float scalar)  {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vec2f& Vec2f::operator/=(float scalar)  {
    x /= scalar;
    y /= scalar;
    return *this;
}

bool Vec2f::operator==(const Vec2f& other) const {
    return x == other.x && y == other.y;
}

bool Vec2f::operator!=(const Vec2f& other) const {
    return !(*this == other);
}

float Vec2f::length() const {
    return std::sqrt(lengthSquared());
}

float Vec2f::lengthSquared() const {
    return x * x + y * y;
}

Vec2f Vec2f::normalized() const {
    float len = length();
    if (len == 0) {
        return Vec2f(0, 0);
    }
    return Vec2f(x / len, y / len);
}

Vec2f Vec2f::normalize() {
    float len = length();
    if (len == 0) {
        return Vec2f(0, 0);
    }
    x /= len;
    y /= len;
    return *this;
}

float Vec2f::dot(const Vec2f& other) const {
    return x * other.x + y * other.y;
}

float Vec2f::cross(const Vec2f& other) const {
    return x * other.y - y * other.x;
}

float Vec2f::distance(const Vec2f& other) const {
    return (*this - other).length();
}

float Vec2f::distanceSquared(const Vec2f& other) const {
    return (*this - other).lengthSquared();
}

float Vec2f::angle(const Vec2f& other) const {
    return std::atan2(cross(other), dot(other));
}

Vec2f Vec2f::rotate(float angle) const {
    float c = std::cos(angle);
    float s = std::sin(angle);
    return Vec2f(x * c - y * s, x * s + y * c);
}

Vec2f Vec2f::rotateAround(float angle, const Vec2f& center) const {
    return (*this - center).rotate(angle) + center;
}
std::string Vec2f::toString() const {
    return std::string("(") + std::to_string(x) + ", " + std::to_string(y) + ")";
}

Vec2f Vec2f::lerp(const Vec2f& a, const Vec2f& b, float t) {
    return a + (b - a) * t;
}

Vec2f Vec2f::zero() {
    return {0, 0};
}
Vec2f Vec2f::one() {
    return {1, 1};
}
Vec2f Vec2f::up() {
    return {0, -1};
}
Vec2f Vec2f::down() {
    return {0, 1};
}
Vec2f Vec2f::left() {
    return {-1, 0};
}
Vec2f Vec2f::right() {
    return {1, 0};
}
