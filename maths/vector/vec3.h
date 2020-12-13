#pragma once

#include <ostream>
#include <cmath>

#include "vec.h"
#include "vec2.h"

namespace math
{

template<typename T>
class vec<3, T>
{
public:
    vec<3, T>()
        : x(0), y(0), z(0)
    {
    }

    vec<3, T>(T x, T y, T z)
        : x(x), y(y), z(z)
    {
    }

    vec<3, T>(T v)
        : x(v), y(v), z(v)
    {
    }

    vec<3, T>(const vec<2, T>& vec, T z)
        : x(vec.x), y(vec.y), z(z)
    {
    }
    
    vec<3, T>(const vec<4, T>& vec)
        : x(vec.x), y(vec.y), z(vec.z)
    {
    }

    vec<3, T> operator+(const vec<3, T>& val) const
    {
        return vec<3, T>(x + val.x, y + val.y, z + val.z);
    }

    vec<3, T> operator+(const T& num) const
    {
        return vec<3, T>(x + num, y + num, z + num);
    }

    vec<3, T> operator-(const vec<3, T>& val) const
    {
        return vec<3, T>(x - val.x, y - val.y, z - val.z);
    }

    vec<3, T> operator-(const T& num) const
    {
        return vec<3, T>(x - num, y - num, z - num);
    }

    vec<3, T> operator-()
    {
        return vec<3, T>(-x, -y, -z);
    }

    vec<3, T> operator*(const vec<3, T>& val) const
    {
        return vec<3, T>(x * val.x, y * val.y, z * val.z);
    }

    vec<3, T> operator*(const T& scl) const
    {
        return vec<3, T>(x * scl, y * scl, z * scl);
    }

    vec<3, T> operator/(const vec<3, T>& val) const
    {
        return vec<3, T>(x / val.x, y / val.y, z / val.z);
    }

    vec<3, T> operator/(const T& scl) const
    {
        return vec<3, T>(x / scl, y / scl, z / scl);
    }

    vec<3, T>& operator+=(const vec<3, T>& val)
    {
        *this = *this + val;
        return *this;
    }

    vec<3, T>& operator+=(const T& num)
    {
        x += num;
        y += num;
        z += num;
        return *this;
    }

    vec<3, T>& operator-=(const vec<3, T>& val)
    {
        *this = *this - val;
        return *this;
    }

    vec<3, T>& operator-=(const T& num)
    {
        x -= num;
        y -= num;
        z -= num;
        return *this;
    }

    vec<3, T>& operator*=(const vec<3, T>& val)
    {
        *this = *this * val;
        return *this;
    }

    vec<3, T>& operator*=(const T& scl)
    {
        x *= scl;
        y *= scl;
        z *= scl;
        return *this;
    }

    vec<3, T>& operator/=(const vec<3, T>& val)
    {
        *this = *this / val;
        return *this;
    }

    vec<3, T>& operator/=(const T& scl)
    {
        x /= scl;
        y /= scl;
        z /= scl;
        return *this;
    }

    bool operator==(const vec<3, T>& val)
    {
        return x == val.x && y == val.y && z == val.z;
    }

    bool operator!=(const vec<3, T>& val)
    {
        return !operator==(val);
    }

    T& operator[](int index)
    {
        switch (index)
        {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default: return x;
        }
    }

    T operator[](int index) const
    {
        switch (index)
        {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default: return x;
        }
    }

    union { T x, r, s; };
    union { T y, g, t; };
    union { T z, b, p; };
};

typedef vec<3, float>        vec3;
typedef vec<3, int>          ivec3;
typedef vec<3, long>         lvec3;
typedef vec<3, double>       dvec3;
typedef vec<3, unsigned int> uvec3;

}
