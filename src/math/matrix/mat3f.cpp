#include <math.h>
#include "math/matrix/mat3f.hpp"
#include "math/matrix/mat2f.hpp"
#include "math/vector/vec3f.hpp"


Mat3f::Mat3f():
    m{
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    } {}
Mat3f::Mat3f(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22):
    m{
        {m00, m01, m02},
        {m10, m11, m12},
        {m20, m21, m22}
    } {}
Mat3f::Mat3f(const Mat3f& m):
    m{
        {m.m[0][0], m.m[0][1], m.m[0][2]},
        {m.m[1][0], m.m[1][1], m.m[1][2]},
        {m.m[2][0], m.m[2][1], m.m[2][2]}
    } {}
Mat3f::Mat3f(const Mat2f& m):
    m{
        {m.m[0][0], m.m[0][1], 0},
        {m.m[1][0], m.m[1][1], 0},
        {0, 0, 1}
    } {}

Mat3f& Mat3f::operator=(const Mat3f& other) {
    m[0][0] = other.m[0][0];
    m[0][1] = other.m[0][1];
    m[0][2] = other.m[0][2];
    m[1][0] = other.m[1][0];
    m[1][1] = other.m[1][1];
    m[1][2] = other.m[1][2];
    m[2][0] = other.m[2][0];
    m[2][1] = other.m[2][1];
    m[2][2] = other.m[2][2];
    return *this;
}
Mat3f Mat3f::operator*(const Mat3f& other) const {
    Mat3f result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result.m[i][j] += m[i][k] * other.m[k][j];
            }
        }
    }
    return result;
}
Vec3f Mat3f::operator*(const Vec3f& v) const {
    Vec3f r;
    for (int j = 0; j < 3; j++) {
        r.x += m[0][j] * v.x;
    }
    for (int j = 0; j < 3; j++) {
        r.y += m[1][j] * v.y;
    }
    for (int j = 0; j < 3; j++) {
        r.z += m[2][j] * v.z;
    }
    return r;
}
Mat3f Mat3f::operator*(float s) const {
    Mat3f r;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            r.m[i][j] = m[i][j] * s;
        }
    }
    return r;
}
Mat3f Mat3f::operator/(float s) const {
    Mat3f r;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            r.m[i][j] = m[i][j] / s;
        }
    }
    return r;
}
Mat3f& Mat3f::operator*=(const Mat3f& m) {
    *this = *this * m;
    return *this;
}
Mat3f& Mat3f::operator*=(float s) {
    *this = *this * s;
    return *this;
}
Mat3f& Mat3f::operator/=(float s) {
    *this = *this / s;
    return *this;
}
Mat3f Mat3f::transpose() const {
    Mat3f r;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            r.m[i][j] = m[j][i];
        }
    }
    return r;
}
Mat3f Mat3f::inverse() const {
    Mat3f r;
    float det = determinant();
    if (det == 0) {
        return r;
    }
    det = 1 / det;
    r.m[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) * det;
    r.m[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) * det;
    r.m[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * det;
    r.m[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) * det;
    r.m[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * det;
    r.m[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) * det;
    r.m[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) * det;
    r.m[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) * det;
    r.m[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) * det;
    return r;
}
float Mat3f::determinant() const {
    return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
           m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
           m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}

Mat3f Mat3f::identity() {
    Mat3f r;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            r.m[i][j] = (i == j) ? 1 : 0;
        }
    }
    return r;
}
Mat3f Mat3f::translation(float tx, float ty) {
    Mat3f r = identity();
    r.m[0][2] = tx;
    r.m[1][2] = ty;
    return r;
}
Mat3f Mat3f::translation(const Vec3f& t) {
    return translation(t.x, t.y);
}
Mat3f Mat3f::scale(float sx, float sy) {
    Mat3f r = identity();
    r.m[0][0] = sx;
    r.m[1][1] = sy;
    return r;
}
Mat3f Mat3f::scale(const Vec3f& s) {
    return scale(s.x, s.y);
}
Mat3f Mat3f::shear(float sx, float sy) {
    Mat3f r = identity();
    r.m[0][1] = sx;
    r.m[1][0] = sy;
    return r;
}
Mat3f Mat3f::shear(const Vec3f& s) {
    return shear(s.x, s.y);
}
Mat3f Mat3f::rotation(float angleX, float angleY, float angleZ) {
    Mat3f r = identity();
    float c = cos(angleX);
    float s = sin(angleX);
    r.m[0][0] = c;
    r.m[0][1] = -s;
    r.m[1][0] = s;
    r.m[1][1] = c;
    c = cos(angleY);
    s = sin(angleY);
    r.m[0][0] *= c;
    r.m[0][0] -= s * r.m[1][0];
    r.m[0][1] *= c;
    r.m[0][1] -= s * r.m[1][1];
    r.m[1][0] *= c;
    r.m[1][0] += s * r.m[0][0];
    r.m[1][1] *= c;
    r.m[1][1] += s * r.m[0][1];
    c = cos(angleZ);
    s = sin(angleZ);
    r.m[0][0] *= c;
    r.m[0][0] -= s * r.m[2][0];
    r.m[0][1] *= c;
    r.m[0][1] -= s * r.m[2][1];
    r.m[1][0] *= c;
    r.m[1][0] += s * r.m[2][0];
    r.m[1][1] *= c;
    r.m[1][1] += s * r.m[2][1];
    r.m[2][0] *= c;
    r.m[2][0] += s * r.m[0][0];
    r.m[2][1] *= c;
    r.m[2][1] += s * r.m[0][1];
    return r;
}
Mat3f Mat3f::rotation(const Vec3f& t) {
    return rotation(t.x, t.y, t.z);
}
