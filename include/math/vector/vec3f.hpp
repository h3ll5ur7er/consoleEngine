#pragma once

#include <string>

struct Vec2f;


typedef struct Vec3f {
public:
    float v[3];
    float& x, y, z;
    Vec3f();
    Vec3f(float x, float y, float z);
    Vec3f(float n);
    Vec3f(const Vec2f& other);
    Vec3f(const Vec2f& other, float z);
    Vec3f(const Vec3f& other);
    Vec3f& operator=(const Vec3f& other);
    Vec3f operator+(const Vec3f& other) const;
    Vec3f operator-(const Vec3f& other) const;
    Vec3f operator*(const Vec3f& other) const;
    Vec3f operator/(const Vec3f& other) const;
    Vec3f operator*(float scalar) const;
    Vec3f operator/(float scalar) const;
    Vec3f operator-() const;
    Vec3f& operator+=(const Vec3f& other);
    Vec3f& operator-=(const Vec3f& other);
    Vec3f& operator*=(const Vec3f& other);
    Vec3f& operator/=(const Vec3f& other);
    Vec3f& operator*=(float scalar);
    Vec3f& operator/=(float scalar);
    bool operator==(const Vec3f& other) const;
    bool operator!=(const Vec3f& other) const;
    Vec2f xy() const;
    Vec2f xz() const;
    Vec2f yz() const;
    float length() const;
    float lengthSquared() const;
    Vec3f normalize();
    Vec3f normalized() const;
    float dot(const Vec3f& other) const;
    Vec3f cross(const Vec3f& other) const;
    float distance(const Vec3f& other) const;
    float distanceSquared(const Vec3f& other) const;
    float angle(const Vec3f& other) const;
    Vec3f rotate(float angle) const;
    Vec3f rotateAround(float angle, const Vec3f& center) const;
    std::string toString(bool integer = false) const;

    static Vec3f zero();
    static Vec3f one();
    static Vec3f up();
    static Vec3f down();
    static Vec3f left();
    static Vec3f right();
    static Vec3f forward();
    static Vec3f back();

    static Vec3f lerp(const Vec3f& a, const Vec3f& b, float t);
} Vec3f;
