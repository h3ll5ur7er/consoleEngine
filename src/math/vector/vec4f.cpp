#include <math.h>
#include "math/vector/vec4f.hpp"
#include "math/vector/vec3f.hpp"



Vec4f::Vec4f():
    v{0, 0, 0, 0},
    x(v[0]),
    y(v[1]),
    z(v[2]),
    w(v[3]) {}
Vec4f::Vec4f(float n):
    v{n, n, n, n},
    x(v[0]),
    y(v[1]),
    z(v[2]),
    w(v[3]) {}
Vec4f::Vec4f(float x, float y, float z, float w):
    v{x,y,z,w},
    x(v[0]),
    y(v[1]),
    z(v[2]),
    w(v[3]) {}
Vec4f::Vec4f(const Vec4f& other):
    v{other.x, other.y, other.z, other.w},
    x(v[0]),
    y(v[1]),
    z(v[2]),
    w(v[3]) {}
Vec4f::Vec4f(const Vec3f& other):
    v{other.x, other.y, other.z, 1},
    x(v[0]),
    y(v[1]),
    z(v[2]),
    w(v[3]) {}
Vec4f& Vec4f::operator=(const Vec4f& other) {
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
    return *this;
}

Vec4f Vec4f::operator+(const Vec4f& other) const {
    return Vec4f(x + other.x, y + other.y, z + other.z, w + other.w);
}
Vec4f Vec4f::operator-(const Vec4f& other) const {
    return Vec4f(x - other.x, y - other.y, z - other.z, w - other.w);
}
Vec4f Vec4f::operator*(const Vec4f& other) const {
    return Vec4f(x * other.x, y * other.y, z * other.z, w * other.w);
}
Vec4f Vec4f::operator/(const Vec4f& other) const {
    return Vec4f(x / other.x, y / other.y, z / other.z, w / other.w);
}
Vec4f Vec4f::operator*(float scalar) const {
    return Vec4f(x * scalar, y * scalar, z * scalar, w * scalar);
}
Vec4f Vec4f::operator/(float scalar) const {
    return Vec4f(x / scalar, y / scalar, z / scalar, w / scalar);
}
Vec4f Vec4f::operator-() const {
    return Vec4f(-x, -y, -z, -w);
}
Vec4f& Vec4f::operator+=(const Vec4f& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}
Vec4f& Vec4f::operator-=(const Vec4f& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}
Vec4f& Vec4f::operator*=(const Vec4f& other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
    return *this;
}
Vec4f& Vec4f::operator/=(const Vec4f& other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;
    return *this;
}
Vec4f& Vec4f::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
    return *this;
}
Vec4f& Vec4f::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
    return *this;
}
bool Vec4f::operator==(const Vec4f& other) const {
    return x == other.x && y == other.y && z == other.z && w == other.w;
}
bool Vec4f::operator!=(const Vec4f& other) const {
    return x != other.x || y != other.y || z != other.z || w != other.w;
}
Vec3f Vec4f::xyz() const {
    if (w == 0) {
        return Vec3f(x, y, z);
    } else {
        return Vec3f(x / w, y / w, z / w);
    }
}
float Vec4f::length() const {
    return std::sqrt(x * x + y * y + z * z + w * w);
}
float Vec4f::lengthSquared() const {
    return x * x + y * y + z * z + w * w;
}
Vec4f Vec4f::normalized() const {
    float len = length();
    return Vec4f(x / len, y / len, z / len, w / len);
}
Vec4f Vec4f::normalize() {
    float len = length();
    x /= len;
    y /= len;
    z /= len;
    w /= len;
    return *this;
}
float Vec4f::dot(const Vec4f& other) const {
    return x * other.x + y * other.y + z * other.z + w * other.w;
}
Vec4f Vec4f::cross(const Vec4f& other) const {
    return Vec4f(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x, 0);
}
float Vec4f::distance(const Vec4f& other) const {
    return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z) + (w - other.w) * (w - other.w));
}
float Vec4f::distanceSquared(const Vec4f& other) const {
    return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z) + (w - other.w) * (w - other.w);
}
float Vec4f::angle(const Vec4f& other) const {
    return std::acos(dot(other) / (length() * other.length()));
}
Vec4f Vec4f::rotate(float angle) const {
    float c = std::cos(angle);
    float s = std::sin(angle);
    return Vec4f(x * c - y * s, x * s + y * c, z, w);
}
Vec4f Vec4f::rotateAround(float angle, const Vec4f& center) const {
    float c = std::cos(angle);
    float s = std::sin(angle);
    return Vec4f(x * c - y * s + center.x, x * s + y * c + center.y, z + center.z, w + center.w);
}
std::string Vec4f::toString() const {
    return std::string("(") + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + ")";
}
