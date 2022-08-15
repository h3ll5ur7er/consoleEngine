#pragma once

class Vec3f;
class Mat2f;


class Mat3f {
public:
    float m[3][3];
    Mat3f();
    Mat3f(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22);
    Mat3f(const Mat3f& m);
    Mat3f(const Mat2f& m);
    Mat3f& operator=(const Mat3f& m);
    Mat3f operator*(const Mat3f& m) const;
    Vec3f operator*(const Vec3f& v) const;
    Mat3f operator*(float s) const;
    Mat3f operator/(float s) const;
    Mat3f& operator*=(const Mat3f& m);
    Mat3f& operator*=(float s);
    Mat3f& operator/=(float s);
    Mat3f transpose() const;
    Mat3f inverse() const;
    float determinant() const;

    static Mat3f identity();
    static Mat3f translation(float tx, float ty);
    static Mat3f translation(const Vec3f& t);
    static Mat3f scale(float sx, float sy);
    static Mat3f scale(const Vec3f& s);
    static Mat3f shear(float sx, float sy);
    static Mat3f shear(const Vec3f& s);
    static Mat3f rotation(float angleX, float angleY, float angleZ);
    static Mat3f rotation(const Vec3f& t);
};