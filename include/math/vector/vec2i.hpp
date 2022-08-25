#pragma once
#include <string>

struct Vec2f;

typedef struct Vec2i {
public:
    int x, y;
    // Vec2i();
    // Vec2i(int x, int y);
    
    int operator[](int i) const;
    operator Vec2f() const;
    Vec2i operator+(const Vec2i& other) const;
    Vec2i operator-(const Vec2i& other) const;
    Vec2i operator*(const Vec2i& other) const;
    Vec2i operator/(const Vec2i& other) const;
    Vec2i& operator+=(const Vec2i& other);
    Vec2i& operator-=(const Vec2i& other);
    Vec2i& operator*=(const Vec2i& other);
    Vec2i& operator/=(const Vec2i& other);
    bool operator==(const Vec2i& other) const;
    bool operator!=(const Vec2i& other) const;
    Vec2i operator-() const;
    Vec2i operator/(int scalar) const;
    Vec2i operator*(int scalar) const;
    int lengthSquared() const;
    std::string toString() const;

    static Vec2i zero();
    static Vec2i one();
    static Vec2i up();
    static Vec2i down();
    static Vec2i left();
    static Vec2i right();
} Vec2i;