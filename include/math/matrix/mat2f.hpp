#pragma once

#include <string>

class Vec2f;

class Mat2f {
public:
    float m[2][2];
    Mat2f();
    Mat2f(float m00, float m01, float m10, float m11);
    Mat2f(const Mat2f& other);
    Mat2f& operator=(const Mat2f& other);
    Mat2f operator*(const Mat2f& other) const;
    Vec2f operator*(const Vec2f& other) const;
    Mat2f operator*(float scalar) const;
    Mat2f operator/(float scalar) const;
    Mat2f operator-() const;
    Mat2f& operator*=(const Mat2f& other);
    Mat2f& operator*=(float scalar);
    Mat2f& operator/=(float scalar);
    Mat2f transpose() const;
    float determinant() const;
    Mat2f inverse() const;
    Mat2f orthogonal() const;

    static Mat2f identity();
    static Mat2f scale(float sx, float sy);
    static Mat2f scale(const Vec2f& s);
    static Mat2f shear(float sx, float sy);
    static Mat2f shear(const Vec2f& s);
    static Mat2f rotation(float angle);
    static Mat2f rotation(const Vec2f& t);
};
