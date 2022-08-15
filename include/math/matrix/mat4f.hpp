#pragma once

#include <string>

class Vec3f;
class Vec4f;
class Mat3f;

class Mat4f {
public:
    float m[4][4];
    Mat4f();
    Mat4f(float n);
    Mat4f(float m00, float m01, float m02, float m03,
          float m10, float m11, float m12, float m13,
          float m20, float m21, float m22, float m23,
          float m30, float m31, float m32, float m33);
    Mat4f(const Mat4f& other);
    Mat4f(const Mat3f& other);
    Mat4f& operator=(const Mat4f& m);
    Mat4f operator*(const Mat4f& m) const;
    Vec4f operator*(const Vec4f& v) const;
    Vec3f operator*(const Vec3f& v) const;
    Mat4f operator*(float s) const;
    Mat4f operator/(float s) const;
    Mat4f& operator*=(const Mat4f& m);
    Mat4f& operator*=(float s);
    Mat4f& operator/=(float s);
    Mat4f transpose() const;
    Mat4f inverse() const;
    float determinant() const;
    std::string toString() const;

    static Mat4f identity();
    static Mat4f translation(float tx, float ty, float tz);
    static Mat4f translation(const Vec3f& t);
    static Mat4f scale(float sx, float sy, float sz);
    static Mat4f scale(const Vec3f& s);
    static Mat4f shear(float sx, float sy, float sz);
    static Mat4f shear(const Vec3f& s);
    static Mat4f rotationX(float angle);
    static Mat4f rotationY(float angle);
    static Mat4f rotationZ(float angle);
    static Mat4f rotation(const Vec3f& euler);

    static Mat4f perspectiveProjection(float fovy, float aspect, float zNear, float zFar);
    static Mat4f orthographicProjection(float left, float right, float bottom, float top, float zNear, float zFar);

    static Mat4f lookAt(const Vec4f& eye, const Vec4f& center, const Vec4f& up);
};
