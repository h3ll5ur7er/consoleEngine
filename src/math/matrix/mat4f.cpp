#include <math.h>
#include <iostream>
#include <sstream>
#include "math/matrix/mat4f.hpp"
#include "math/matrix/mat3f.hpp"
#include "math/vector/vec4f.hpp"
#include "math/vector/vec3f.hpp"


Mat4f::Mat4f():
    m{
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    } {}
Mat4f::Mat4f(float n):
    m{
        {n, 0, 0, 0},
        {0, n, 0, 0},
        {0, 0, n, 0},
        {0, 0, 0, n}
    } {}
Mat4f::Mat4f(float m00, float m01, float m02, float m03,
        float m10, float m11, float m12, float m13,
        float m20, float m21, float m22, float m23,
        float m30, float m31, float m32, float m33):
    m{
        {m00, m01, m02, m03},
        {m10, m11, m12, m13},
        {m20, m21, m22, m23},
        {m30, m31, m32, m33}
    } {}
Mat4f::Mat4f(const Mat3f& other):
    m{
        {other.m[0][0], other.m[0][1], other.m[0][2], 0},
        {other.m[1][0], other.m[1][1], other.m[1][2], 0},
        {other.m[2][0], other.m[2][1], other.m[2][2], 0},
        {0, 0, 0, 1}
    } {}
Mat4f::Mat4f(const Mat4f& other):
    m{
        {other.m[0][0], other.m[0][1], other.m[0][2], other.m[0][3]},
        {other.m[1][0], other.m[1][1], other.m[1][2], other.m[1][3]},
        {other.m[2][0], other.m[2][1], other.m[2][2], other.m[2][3]},
        {other.m[3][0], other.m[3][1], other.m[3][2], other.m[3][3]}
    } {}
Mat4f& Mat4f::operator=(const Mat4f& other) {
    m[0][0] = other.m[0][0];
    m[0][1] = other.m[0][1];
    m[0][2] = other.m[0][2];
    m[0][3] = other.m[0][3];
    m[1][0] = other.m[1][0];
    m[1][1] = other.m[1][1];
    m[1][2] = other.m[1][2];
    m[1][3] = other.m[1][3];
    m[2][0] = other.m[2][0];
    m[2][1] = other.m[2][1];
    m[2][2] = other.m[2][2];
    m[2][3] = other.m[2][3];
    m[3][0] = other.m[3][0];
    m[3][1] = other.m[3][1];
    m[3][2] = other.m[3][2];
    m[3][3] = other.m[3][3];
    return *this;
}
Mat4f Mat4f::operator*(const Mat4f& other) const {
    Mat4f result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                result.m[i][j] += m[i][k] * other.m[k][j];
            }
        }
    }
    return result;
}
Vec4f Mat4f::operator*(const Vec4f& v) const {
    Vec4f result;
    for (int i = 0; i < 4; i++) {
        result.v[i] = 0;
        for (int j = 0; j < 4; j++) {
            result.v[i] += m[i][j] * v.v[j];
        }
    }
    result.x = result.v[0];
    result.y = result.v[1];
    result.z = result.v[2];
    result.w = result.v[3];
    return result;
}

Vec3f Mat4f::operator*(const Vec3f& v) const {
    Vec4f vector = Vec4f(v);
    Vec4f result = (*this) * vector;
    Vec3f v3 = result.xyz();
    return v3;
}
Mat4f Mat4f::operator*(float s) const {
    Mat4f result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = m[i][j] * s;
        }
    }
    return result;
}
Mat4f Mat4f::operator/(float s) const {
    Mat4f result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = m[i][j] / s;
        }
    }
    return result;
}
Mat4f& Mat4f::operator*=(const Mat4f& other) {
    *this = *this * other;
    return *this;
}
Mat4f& Mat4f::operator*=(float s) {
    *this = *this * s;
    return *this;
}
Mat4f& Mat4f::operator/=(float s) {
    *this = *this / s;
    return *this;
}
Mat4f Mat4f::transpose() const {
    Mat4f result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = m[j][i];
        }
    }
    return result;
}
Mat4f Mat4f::inverse() const {
    Mat4f result;
    float det = determinant();
    if (det == 0) {
        return result;
    }
    det = 1.0f / det;
    result.m[0][0] = (m[1][1] * m[2][2] * m[3][3] - m[1][1] * m[2][3] * m[3][2] - m[1][2] * m[2][1] * m[3][3] + m[1][2] * m[2][3] * m[3][1] + m[1][3] * m[2][1] * m[3][2] - m[1][3] * m[2][2] * m[3][1]) * det;
    result.m[0][1] = (-m[0][1] * m[2][2] * m[3][3] + m[0][1] * m[2][3] * m[3][2] + m[0][2] * m[2][1] * m[3][3] - m[0][2] * m[2][3] * m[3][1] - m[0][3] * m[2][1] * m[3][2] + m[0][3] * m[2][2] * m[3][1]) * det;
    result.m[0][2] = (m[0][1] * m[1][2] * m[3][3] - m[0][1] * m[1][3] * m[3][2] - m[0][2] * m[1][1] * m[3][3] + m[0][2] * m[1][3] * m[3][1] + m[0][3] * m[1][1] * m[3][2] - m[0][3] * m[1][2] * m[3][1]) * det;
    result.m[0][3] = (-m[0][1] * m[1][2] * m[2][3] + m[0][1] * m[1][3] * m[2][2] + m[0][2] * m[1][1] * m[2][3] - m[0][2] * m[1][3] * m[2][1] - m[0][3] * m[1][1] * m[2][2] + m[0][3] * m[1][2] * m[2][1]) * det;
    result.m[1][0] = (-m[1][0] * m[2][2] * m[3][3] + m[1][0] * m[2][3] * m[3][2] + m[1][2] * m[2][0] * m[3][3] - m[1][2] * m[2][3] * m[3][0] - m[1][3] * m[2][0] * m[3][2] + m[1][3] * m[2][2] * m[3][0]) * det;
    result.m[1][1] = (m[0][0] * m[2][2] * m[3][3] - m[0][0] * m[2][3] * m[3][2] - m[0][2] * m[2][0] * m[3][3] + m[0][2] * m[2][3] * m[3][0] + m[0][3] * m[2][0] * m[3][2] - m[0][3] * m[2][2] * m[3][0]) * det;
    result.m[1][2] = (-m[0][0] * m[1][2] * m[3][3] + m[0][0] * m[1][3] * m[3][2] + m[0][2] * m[1][0] * m[3][3] - m[0][2] * m[1][3] * m[3][0] - m[0][3] * m[1][0] * m[3][2] + m[0][3] * m[1][2] * m[3][0]) * det;
    result.m[1][3] = (m[0][0] * m[1][2] * m[2][3] - m[0][0] * m[1][3] * m[2][2] - m[0][2] * m[1][0] * m[2][3] + m[0][2] * m[1][3] * m[2][0] + m[0][3] * m[1][0] * m[2][2] - m[0][3] * m[1][2] * m[2][0]) * det;
    result.m[2][0] = (m[1][0] * m[2][1] * m[3][3] - m[1][0] * m[2][3] * m[3][1] - m[1][1] * m[2][0] * m[3][3] + m[1][1] * m[2][3] * m[3][0] + m[1][3] * m[2][0] * m[3][1] - m[1][3] * m[2][1] * m[3][0]) * det;
    result.m[2][1] = (-m[0][0] * m[2][1] * m[3][3] + m[0][0] * m[2][3] * m[3][1] + m[0][1] * m[2][0] * m[3][3] - m[0][1] * m[2][3] * m[3][0] - m[0][3] * m[2][0] * m[3][1] + m[0][3] * m[2][1] * m[3][0]) * det;
    result.m[2][2] = (m[0][0] * m[1][1] * m[3][3] - m[0][0] * m[1][3] * m[3][1] - m[0][1] * m[1][0] * m[3][3] + m[0][1] * m[1][3] * m[3][0] + m[0][3] * m[1][0] * m[3][1] - m[0][3] * m[1][1] * m[3][0]) * det;
    result.m[2][3] = (-m[0][0] * m[1][1] * m[2][3] + m[0][0] * m[1][3] * m[2][1] + m[0][1] * m[1][0] * m[2][3] - m[0][1] * m[1][3] * m[2][0] - m[0][3] * m[1][0] * m[2][1] + m[0][3] * m[1][1] * m[2][0]) * det;
    result.m[3][0] = (-m[1][0] * m[2][1] * m[3][2] + m[1][0] * m[2][2] * m[3][1] + m[1][1] * m[2][0] * m[3][2] - m[1][1] * m[2][2] * m[3][0] - m[1][2] * m[2][0] * m[3][1] + m[1][2] * m[2][1] * m[3][0]) * det;
    result.m[3][1] = (m[0][0] * m[2][1] * m[3][2] - m[0][0] * m[2][2] * m[3][1] - m[0][1] * m[2][0] * m[3][2] + m[0][1] * m[2][2] * m[3][0] + m[0][2] * m[2][0] * m[3][1] - m[0][2] * m[2][1] * m[3][0]) * det;
    result.m[3][2] = (-m[0][0] * m[1][1] * m[3][2] + m[0][0] * m[1][2] * m[3][1] + m[0][1] * m[1][0] * m[3][2] - m[0][1] * m[1][2] * m[3][0] - m[0][2] * m[1][0] * m[3][1] + m[0][2] * m[1][1] * m[3][0]) * det;
    result.m[3][3] = (m[0][0] * m[1][1] * m[2][2] - m[0][0] * m[1][2] * m[2][1] - m[0][1] * m[1][0] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1] - m[0][2] * m[1][1] * m[2][0]) * det;
    return result;
}

float Mat4f::determinant() const
{
    float result = 0.0f;
    result = m[0][0] * (m[1][1] * m[2][2] * m[3][3] - m[1][1] * m[2][3] * m[3][2] - m[1][2] * m[2][1] * m[3][3] + m[1][2] * m[2][3] * m[3][1] + m[1][3] * m[2][1] * m[3][2] - m[1][3] * m[2][2] * m[3][1]);
    result -= m[0][1] * (m[1][0] * m[2][2] * m[3][3] - m[1][0] * m[2][3] * m[3][2] - m[1][2] * m[2][0] * m[3][3] + m[1][2] * m[2][3] * m[3][0] + m[1][3] * m[2][0] * m[3][2] - m[1][3] * m[2][2] * m[3][0]);
    result += m[0][2] * (m[1][0] * m[2][1] * m[3][3] - m[1][0] * m[2][3] * m[3][1] - m[1][1] * m[2][0] * m[3][3] + m[1][1] * m[2][3] * m[3][0] + m[1][3] * m[2][0] * m[3][1] - m[1][3] * m[2][1] * m[3][0]);
    result -= m[0][3] * (m[1][0] * m[2][1] * m[3][2] - m[1][0] * m[2][2] * m[3][1] - m[1][1] * m[2][0] * m[3][2] + m[1][1] * m[2][2] * m[3][0] + m[1][2] * m[2][0] * m[3][1] - m[1][2] * m[2][1] * m[3][0]);
    return result;
}

Mat4f Mat4f::identity()
{
    Mat4f result;
    result.m[0][0] = 1.0f; result.m[0][1] = 0.0f; result.m[0][2] = 0.0f; result.m[0][3] = 0.0f;
    result.m[1][0] = 0.0f; result.m[1][1] = 1.0f; result.m[1][2] = 0.0f; result.m[1][3] = 0.0f;
    result.m[2][0] = 0.0f; result.m[2][1] = 0.0f; result.m[2][2] = 1.0f; result.m[2][3] = 0.0f;
    result.m[3][0] = 0.0f; result.m[3][1] = 0.0f; result.m[3][2] = 0.0f; result.m[3][3] = 1.0f;
    return result;
}
Mat4f Mat4f::translation(float tx, float ty, float tz)
{
    Mat4f result;
    result.m[0][0] = 1.0f; result.m[0][1] = 0.0f; result.m[0][2] = 0.0f; result.m[0][3] = tx;
    result.m[1][0] = 0.0f; result.m[1][1] = 1.0f; result.m[1][2] = 0.0f; result.m[1][3] = ty;
    result.m[2][0] = 0.0f; result.m[2][1] = 0.0f; result.m[2][2] = 1.0f; result.m[2][3] = tz;
    result.m[3][0] = 0.0f; result.m[3][1] = 0.0f; result.m[3][2] = 0.0f; result.m[3][3] = 1.0f;
    return result;
}
Mat4f Mat4f::translation(const Vec3f& t)
{
    return translation(t.x, t.y, t.z);
}
Mat4f Mat4f::scale(float sx, float sy, float sz)
{
    Mat4f result;
    result.m[0][0] = sx; result.m[0][1] = 0.0f; result.m[0][2] = 0.0f; result.m[0][3] = 0.0f;
    result.m[1][0] = 0.0f; result.m[1][1] = sy; result.m[1][2] = 0.0f; result.m[1][3] = 0.0f;
    result.m[2][0] = 0.0f; result.m[2][1] = 0.0f; result.m[2][2] = sz; result.m[2][3] = 0.0f;
    result.m[3][0] = 0.0f; result.m[3][1] = 0.0f; result.m[3][2] = 0.0f; result.m[3][3] = 1.0f;
    return result;
}
Mat4f Mat4f::scale(const Vec3f& s)
{
    return scale(s.x, s.y, s.z);
}
Mat4f Mat4f::shear(float sx, float sy, float sz)
{
    Mat4f result;
    result.m[0][0] = 1.0f; result.m[0][1] = sx;   result.m[0][2] = 0.0f; result.m[0][3] = 0.0f;
    result.m[1][0] = sy;   result.m[1][1] = 1.0f; result.m[1][2] = 0.0f; result.m[1][3] = 0.0f;
    result.m[2][0] = 0.0f; result.m[2][1] = sz;   result.m[2][2] = 1.0f; result.m[2][3] = 0.0f;
    result.m[3][0] = 0.0f; result.m[3][1] = 0.0f; result.m[3][2] = 0.0f; result.m[3][3] = 1.0f;
    return result;
}
Mat4f Mat4f::shear(const Vec3f& s)
{
    return shear(s.x, s.y, s.z);
}
Mat4f Mat4f::rotationX(float angle)
{
    Mat4f result;
    float c = cos(angle);
    float s = sin(angle);
    result.m[0][0] = 1.0f; result.m[0][1] = 0.0f; result.m[0][2] = 0.0f; result.m[0][3] = 0.0f;
    result.m[1][0] = 0.0f; result.m[1][1] = c; result.m[1][2] = -s; result.m[1][3] = 0.0f;
    result.m[2][0] = 0.0f; result.m[2][1] = s; result.m[2][2] = c; result.m[2][3] = 0.0f;
    result.m[3][0] = 0.0f; result.m[3][1] = 0.0f; result.m[3][2] = 0.0f; result.m[3][3] = 1.0f;
    return result;
}

Mat4f Mat4f::rotationY(float angle)
{
    Mat4f result;
    float c = cos(angle);
    float s = sin(angle);
    result.m[0][0] = c;    result.m[0][1] = 0.0f; result.m[0][2] = s;    result.m[0][3] = 0.0f;
    result.m[1][0] = 0.0f; result.m[1][1] = 1.0f; result.m[1][2] = 0.0f; result.m[1][3] = 0.0f;
    result.m[2][0] = -s;   result.m[2][1] = 0.0f; result.m[2][2] = c;    result.m[2][3] = 0.0f;
    result.m[3][0] = 0.0f; result.m[3][1] = 0.0f; result.m[3][2] = 0.0f; result.m[3][3] = 1.0f;
    return result;
}

Mat4f Mat4f::rotationZ(float angle)
{
    Mat4f result;
    float c = cos(angle);
    float s = sin(angle);
    result.m[0][0] = c;    result.m[0][1] = -s;   result.m[0][2] = 0.0f; result.m[0][3] = 0.0f;
    result.m[1][0] = s;    result.m[1][1] = c;    result.m[1][2] = 0.0f; result.m[1][3] = 0.0f;
    result.m[2][0] = 0.0f; result.m[2][1] = 0.0f; result.m[2][2] = 1.0f; result.m[2][3] = 0.0f;
    result.m[3][0] = 0.0f; result.m[3][1] = 0.0f; result.m[3][2] = 0.0f; result.m[3][3] = 1.0f;
    return result;
}
Mat4f Mat4f::rotation(const Vec3f& euler)
{
    return rotationX(euler.x) * rotationY(euler.y) * rotationZ(euler.z);
}

Mat4f Mat4f::perspectiveProjection(float fovy, float aspect, float zNear, float zFar)
{
    Mat4f result;
    float f = 1.0f / tan(fovy * 0.5f);
    float q = (zFar + zNear) / (zNear - zFar);
    result.m[0][0] = aspect * f; result.m[0][1] = 0.0f; result.m[0][2] = 0.0f;                             result.m[0][3] = 0.0f;
    result.m[1][0] = 0.0f;       result.m[1][1] = f;    result.m[1][2] = 0.0f;                             result.m[1][3] = 0.0f;
    result.m[2][0] = 0.0f;       result.m[2][1] = 0.0f; result.m[2][2] = zFar / (zFar - zNear);            result.m[2][3] = 1.0f;
    result.m[3][0] = 0.0f;       result.m[3][1] = 0.0f; result.m[3][2] = (-zFar * zNear) / (zFar - zNear); result.m[3][3] = 0.0f;
    return result;
}
Mat4f Mat4f::orthographicProjection(float left, float right, float bottom, float top, float zNear, float zFar)
{
    Mat4f result;
    result.m[0][0] = 2.0f / (right - left); result.m[0][1] = 0.0f; result.m[0][2] = 0.0f; result.m[0][3] = 0.0f;
    result.m[1][0] = 0.0f; result.m[1][1] = 2.0f / (top - bottom); result.m[1][2] = 0.0f; result.m[1][3] = 0.0f;
    result.m[2][0] = 0.0f; result.m[2][1] = 0.0f; result.m[2][2] = -2.0f / (zFar - zNear); result.m[2][3] = 0.0f;
    result.m[3][0] = -(right + left) / (right - left); result.m[3][1] = -(top + bottom) / (top - bottom); result.m[3][2] = -(zFar + zNear) / (zFar - zNear); result.m[3][3] = 1.0f;
    return result;
}

Mat4f Mat4f::lookAt(const Vec4f& eye, const Vec4f& target, const Vec4f& up)
{
    Vec4f z = (eye - target).normalized();
    Vec4f x = up.cross(z).normalized();
    Vec4f y = z.cross(x);
    Mat4f result;
    result.m[0][0] = x.x; result.m[0][1] = x.y; result.m[0][2] = x.z; result.m[0][3] = -x.dot(eye);
    result.m[1][0] = y.x; result.m[1][1] = y.y; result.m[1][2] = y.z; result.m[1][3] = -y.dot(eye);
    result.m[2][0] = z.x; result.m[2][1] = z.y; result.m[2][2] = z.z; result.m[2][3] = -z.dot(eye);
    result.m[3][0] = 0.0f; result.m[3][1] = 0.0f; result.m[3][2] = 0.0f; result.m[3][3] = 1.0f;
    return result;
}

std::string Mat4f::toString() const {
    std::stringstream ss;
    for (int i = 0; i < 4; i++) {
        ss << "[";
        for (int j = 0; j < 4; j++) {
            ss << m[i][j] << " ";
        }
        ss << "]\n";
    }

    return ss.str();
}
