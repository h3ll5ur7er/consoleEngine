#pragma once

#include <string>

class Vec2i;

typedef struct Vec2f {
public:
    float v[2];
    float& x, y;
    Vec2f();
    Vec2f(float n);
    Vec2f(float x, float y);
    Vec2f(const Vec2f& other);
    float* operator[](int i) const;
    Vec2f& operator=(const Vec2f& other);
    operator Vec2i() const;
    Vec2f operator+(const Vec2f& other) const;
    Vec2f operator-(const Vec2f& other) const;
    Vec2f operator*(const Vec2f& other) const;
    Vec2f operator/(const Vec2f& other) const;
    Vec2f operator*(float scalar) const;
    Vec2f operator/(float scalar) const;
    Vec2f operator-() const;
    Vec2f& operator+=(const Vec2f& other);
    Vec2f& operator-=(const Vec2f& other);
    Vec2f& operator*=(const Vec2f& other);
    Vec2f& operator/=(const Vec2f& other);
    Vec2f& operator*=(float scalar);
    Vec2f& operator/=(float scalar);
    bool operator==(const Vec2f& other) const;
    bool operator!=(const Vec2f& other) const;
    float length() const;
    float lengthSquared() const;
    Vec2f normalize();
    Vec2f normalized() const;
    float dot(const Vec2f& other) const;
    float cross(const Vec2f& other) const;
    float distance(const Vec2f& other) const;
    float distanceSquared(const Vec2f& other) const;
    float angle(const Vec2f& other) const;
    Vec2f rotate(float angle) const;
    Vec2f rotateAround(float angle, const Vec2f& center) const;
    std::string toString() const;
    static Vec2f lerp(const Vec2f& a, const Vec2f& b, float t);
} Vec2f;