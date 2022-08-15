#include <math.h>

#include "math/matrix/mat2f.hpp"
#include "math/vector/vec2f.hpp"

Mat2f::Mat2f():
    m{{1,0},{0,1}} {}
Mat2f::Mat2f(float m00, float m01, float m10, float m11):
    m{{m00,m01},{m10,m11}} {}
Mat2f::Mat2f(const Mat2f& other):
    m{{other.m[0][0],other.m[0][1]},{other.m[1][0],other.m[1][1]}} {}


Mat2f& Mat2f::operator=(const Mat2f& other){
    m[0][0] = other.m[0][0];
    m[0][1] = other.m[0][1];
    m[1][0] = other.m[1][0];
    m[1][1] = other.m[1][1];
    return *this;
}
Mat2f Mat2f::operator*(const Mat2f& other) const {
    return Mat2f(m[0][0]*other.m[0][0]+m[0][1]*other.m[1][0],
                 m[0][0]*other.m[0][1]+m[0][1]*other.m[1][1],
                 m[1][0]*other.m[0][0]+m[1][1]*other.m[1][0],
                 m[1][0]*other.m[0][1]+m[1][1]*other.m[1][1]);
}
Vec2f Mat2f::operator*(const Vec2f& other) const {
    return Vec2f(m[0][0]*other.x+m[0][1]*other.y,
                 m[1][0]*other.x+m[1][1]*other.y);
}
Mat2f Mat2f::operator*(float scalar) const {
    return Mat2f(m[0][0]*scalar,m[0][1]*scalar,m[1][0]*scalar,m[1][1]*scalar);
}
Mat2f Mat2f::operator/(float scalar) const {
    return Mat2f(m[0][0]/scalar,m[0][1]/scalar,m[1][0]/scalar,m[1][1]/scalar);
}
Mat2f Mat2f::operator-() const {
    return Mat2f(-m[0][0],-m[0][1],-m[1][0],-m[1][1]);
}
Mat2f& Mat2f::operator*=(const Mat2f& other){
    *this = *this * other;
    return *this;
}
Mat2f& Mat2f::operator*=(float scalar){
    *this = *this * scalar;
    return *this;
}
Mat2f& Mat2f::operator/=(float scalar){
    *this = *this / scalar;
    return *this;
}
Mat2f Mat2f::transpose() const {
    return Mat2f(m[0][0],m[1][0],m[0][1],m[1][1]);
}
float Mat2f::determinant() const {
    return m[0][0]*m[1][1]-m[0][1]*m[1][0];
}
Mat2f Mat2f::inverse() const {
    float det = determinant();
    return Mat2f(m[1][1]/det,-m[0][1]/det,-m[1][0]/det,m[0][0]/det);
}
Mat2f Mat2f::orthogonal() const {
    return Mat2f(m[0][0],-m[1][0],m[1][0],m[0][0]);
}

Mat2f Mat2f::identity() {
    return Mat2f(1,0,0,1);
}
Mat2f Mat2f::scale(float sx, float sy) {
    return Mat2f(sx,0,0,sy);
}
Mat2f Mat2f::scale(const Vec2f& s) {
    return Mat2f(s.x,0,0,s.y);
}
Mat2f Mat2f::shear(float sx, float sy) {
    return Mat2f(1,sy,sx,1);
}
Mat2f Mat2f::shear(const Vec2f& s) {
    return Mat2f(1,s.y,s.x,1);
}
Mat2f Mat2f::rotation(float angle) {
    float c = cos(angle);
    float s = sin(angle);
    return Mat2f(c,-s,s,c);
}
Mat2f Mat2f::rotation(const Vec2f& t) {
    return Mat2f(t.x, -t.y, t.y, t.x);
}