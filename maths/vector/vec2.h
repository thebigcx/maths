#pragma once

#include <ostream>
#include <cassert>

#include "vec.h"

namespace math
{

template<typename T>
class vec<2, T>
{
public:
    constexpr vec<2, T>()
        : x(0), y(0)
    {
    }

    constexpr vec<2, T>(T _x, T _y)
        : x(_x), y(_y)
    {
    }

    constexpr vec<2, T>(T v)
        : x(v), y(v)
    {
    }

    template<typename U>
    constexpr vec<2, T>(const vec<3, U>& v)
        : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) {}

    template<typename U>
    constexpr vec<2, T>(const vec<4, U>& v)
        : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) {}

    template<typename U>
    constexpr vec<2, T>(const vec<2, U>& v)
        : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) {}

    template<typename A, typename B>
    constexpr vec<2, T>(const A& a, const B& b)
        : x(static_cast<T>(a)), y(static_cast<T>(b)) {}

    T& operator[](length_t index)
    {
        assert(index >= 0 && index < 2);
        switch (index)
        {
            case 0: return x;
            case 1: return y;
            default: return x;
        }
    }

    const T& operator[](length_t index) const
    {
        assert(index >= 0 && index < 2);
        switch (index)
        {
            case 0: return x;
            case 1: return y;
            default: return x;
        }
    }

    vec<2, T>& operator=(const vec<2, T>& v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    // Conversion
    template<typename U>
    vec<2, T>& operator=(const vec<2, U>& v)
    {
        x = static_cast<T>(v.x);
        y = static_cast<T>(v.y);
    }

    vec<2, T>& operator+=(const vec<2, T>& v)
    {
        *this = *this + v;
        return *this;
    }

    vec<2, T>& operator+=(const T& n)
    {
        *this = *this + n;
        return *this;
    }

    vec<2, T>& operator-=(const vec<2, T>& v)
    {
        *this = *this - v;
        return *this;
    }

    vec<2, T>& operator-=(const T& n)
    {
        *this = *this - n;
        return *this;
    }

    vec<2, T>& operator*=(const vec<2, T>& v)
    {
        *this = *this * v;
        return *this;
    }

    vec<2, T>& operator*=(const T& s)
    {
        *this = *this * s;
        return *this;
    }

    vec<2, T>& operator/=(const vec<2, T>& v)
    {
        *this = *this / v;
        return *this;
    }

    vec<2, T>& operator/=(const T& s)
    {
        *this = *this * s;
        return *this;
    }

    vec<2, T>& operator++()
    {
        x++; y++;
        return *this;
    }

    vec<2, T>& operator--()
    {
        x--; y--;
        return *this;
    }

    union { T x, r, s; };
    union { T y, g, t; };
};

template<typename T>
vec<2, T> operator+(const vec<2, T>& v)
{
    return v;
}

template<typename T>
vec<2, T> operator-(const vec<2, T>& v)
{
    return vec<2, T>(-v.x, -v.y);
}

template<typename T>
bool operator==(const vec<2, T>& v1, const vec<2, T>& v2)
{
    return v1.x == v2.x && v1.y == v2.y;
}

template<typename T>
bool operator!=(const vec<2, T>& v1, const vec<2, T>& v2)
{
    return v1.x != v2.x || v1.y != v2.y;
}

template<typename T>
vec<2, T> operator+(const vec<2, T>& v1, const vec<2, T>& v2)
{
    return vec<2, T>(v1.x + v2.x, v1.y + v2.y);
}

template<typename T>
vec<2, T> operator+(const vec<2, T>& v, const T& s)
{
    return vec<2, T>(v.x + s, v.y + s);
}

template<typename T>
vec<2, T> operator+(const T& s, const vec<2, T>& v)
{
    return v + s;
}

template<typename T>
vec<2, T> operator-(const vec<2, T>& v1, const vec<2, T>& v2)
{
    return vec<2, T>(v1.x - v2.x, v1.y - v2.y);
}

template<typename T>
vec<2, T> operator-(const vec<2, T>& v, const T& s)
{
    return vec<2, T>(v.x - s, v.y - s);
}

template<typename T>
vec<2, T> operator-(const T& s, const vec<2, T>& v)
{
    return v - s;
}

template<typename T>
vec<2, T> operator*(const vec<2, T>& v1, const vec<2, T>& v2)
{
    return vec<2, T>(v1.x * v2.x, v1.y * v2.y);
}

template<typename T>
vec<2, T> operator*(const vec<2, T>& v, const T& s)
{
    return vec<2, T>(v.x * s, v.y * s);
}

template<typename T>
vec<2, T> operator*(const T& s, const vec<2, T>& v)
{
    return v * s;
}

template<typename T>
vec<2, T> operator/(const vec<2, T>& v1, const vec<2, T>& v2)
{
    return vec<2, T>(v1.x / v2.x, v1.y / v2.y);
}

template<typename T>
vec<2, T> operator/(const vec<2, T>& v, const T& s)
{
    return vec<2, T>(v.x / s, v.y / s);
}

template<typename T>
vec<2, T> operator/(const T& s, const vec<2, T>& v)
{
    return v / s;
}

typedef vec<2, float>        vec2;
typedef vec<2, int>          ivec2;
typedef vec<2, long>         lvec2;
typedef vec<2, double>       dvec2;
typedef vec<2, unsigned int> uvec2;

}
