#pragma once
#include <string>

struct Vec3f;


typedef struct Vec4f {
public:
    float v[4];
    float& x, y, z, w;
    Vec4f();
    Vec4f(float n);
    Vec4f(float x, float y, float z, float w);
    Vec4f(const Vec4f& other);
    Vec4f(const Vec3f& other);
    Vec4f& operator=(const Vec4f& other);
    Vec4f operator+(const Vec4f& other) const;
    Vec4f operator-(const Vec4f& other) const;
    Vec4f operator*(const Vec4f& other) const;
    Vec4f operator/(const Vec4f& other) const;
    Vec4f operator*(float scalar) const;
    Vec4f operator/(float scalar) const;
    Vec4f operator-() const;
    Vec4f& operator+=(const Vec4f& other);
    Vec4f& operator-=(const Vec4f& other);
    Vec4f& operator*=(const Vec4f& other);
    Vec4f& operator/=(const Vec4f& other);
    Vec4f& operator*=(float scalar);
    Vec4f& operator/=(float scalar);
    bool operator==(const Vec4f& other) const;
    bool operator!=(const Vec4f& other) const;
    Vec3f xyz() const;
    float length() const;
    float lengthSquared() const;
    Vec4f normalize();
    Vec4f normalized() const;
    float dot(const Vec4f& other) const;
    Vec4f cross(const Vec4f& other) const;
    float distance(const Vec4f& other) const;
    float distanceSquared(const Vec4f& other) const;
    float angle(const Vec4f& other) const;
    Vec4f rotate(float angle) const;
    Vec4f rotateAround(float angle, const Vec4f& center) const;
    std::string toString() const;
} Vec4f;
