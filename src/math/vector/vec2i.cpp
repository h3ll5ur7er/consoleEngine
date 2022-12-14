#include "math/vector/vec2i.hpp"
#include "math/vector/vec2f.hpp"


Vec2i::Vec2i():
    x(0),
    y(0) {}
Vec2i::Vec2i(int x, int y):
    x(x),
    y(y) {}
    
int Vec2i::operator[](int i) const{
    return (&x)[i];
}
Vec2i Vec2i::operator+(const Vec2i& other) const {
    return Vec2i(x + other.x, y + other.y);
}
Vec2i Vec2i::operator-(const Vec2i& other) const {
    return Vec2i(x - other.x, y - other.y);
}
Vec2i Vec2i::operator*(const Vec2i& other) const {
    return Vec2i(x * other.x, y * other.y);
}
Vec2i Vec2i::operator/(const Vec2i& other) const {
    return Vec2i(x / other.x, y / other.y);
}
Vec2i& Vec2i::operator+=(const Vec2i& other) {
    x += other.x;
    y += other.y;
    return *this;
}
Vec2i& Vec2i::operator-=(const Vec2i& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}
Vec2i& Vec2i::operator*=(const Vec2i& other) {
    x *= other.x;
    y *= other.y;
    return *this;
}
Vec2i& Vec2i::operator/=(const Vec2i& other) {
    x /= other.x;
    y /= other.y;
    return *this;
}
bool Vec2i::operator==(const Vec2i& other) const {
    return x == other.x && y == other.y;
}
bool Vec2i::operator!=(const Vec2i& other) const {
    return x != other.x || y != other.y;
}
Vec2i Vec2i::operator-() const {
    return Vec2i(-x, -y);
}
Vec2i Vec2i::operator/(int scalar) const {
    return Vec2i(x / scalar, y / scalar);
}
Vec2i Vec2i::operator*(int scalar) const {
    return Vec2i(x * scalar, y * scalar);
}
int Vec2i::lengthSquared() const {
    return x * x + y * y;
}

Vec2i Vec2i::zero() {
    return Vec2i(0, 0);
}
Vec2i Vec2i::one() {
    return Vec2i(1, 1);
}
Vec2i Vec2i::up() {
    return Vec2i(0, -1);
}
Vec2i Vec2i::down() {
    return Vec2i(0, 1);
}
Vec2i Vec2i::left() {
    return Vec2i(-1, 0);
}
Vec2i Vec2i::right() {
    return Vec2i(1, 0);
}
std::string Vec2i::toString() const {
    return std::string("(") + std::to_string(x) + ", " + std::to_string(y) + ")";
}
