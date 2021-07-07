//
// Created by caiotava on 4/18/21.
//

#ifndef SDLBOOK_CMAKE_VECTOR2D_H
#define SDLBOOK_CMAKE_VECTOR2D_H

#include<math.h>

class Vector2D {
public:
    Vector2D(float x, float y): x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

    void setX(float v) { x = v; }
    void setY(float v) { y = v; }

    float length() { return sqrt((x * x) + (y * y)); }

    void normalize() {
        float l = length();

        if (l > 0) {
            (*this) *= 1 / l;
        }
    }

    Vector2D operator+(const Vector2D v) const { return Vector2D(x + v.x, y + v.y); }

    friend Vector2D& operator+=(Vector2D& dest, Vector2D& src) {
        dest.x += src.x;
        dest.y += src.y;

        return dest;
    }

    Vector2D operator*(float scalar) { return Vector2D(x * scalar, y * scalar); }

    Vector2D operator*=(float scalar) {
        x *= scalar;
        y *= scalar;

        return *this;
    }

    Vector2D operator-(const Vector2D& v) { return Vector2D(x - v.x, y - v.y); }

    friend Vector2D& operator-=(Vector2D& dest, Vector2D& src) {
        dest.x -= src.x;
        dest.y -= src.y;

        return dest;
    }

    Vector2D operator/(float scalar) { return Vector2D(x / scalar, y / scalar); }

    Vector2D& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;

        return *this;
    }

private:
    float x;
    float y;
};


#endif //SDLBOOK_CMAKE_VECTOR2D_H
