#pragma once

#include <string>

#include "vec.h"
#include "../general.h"

namespace math
{

// ------------------------------vec2-------------------------------

template<typename T>
static float mag(const vec<2, T>& val)
{
    return math::sqrt(val.x * val.x + val.y * val.y);
}

template<typename T>
static vec<2, T> normalize(const vec<2, T>& val)
{
    float magnitude = 1.f / math::mag(val); // Divide once (save CPU cycles)
    return vec<2, T>(val.x * magnitude, val.y * magnitude);
}

template<typename T>
static float dot(const vec<2, T>& vec1, const vec<2, T>& vec2)
{
    return vec1.x * vec2.x + vec1.y * vec2.y;
}

template<typename T>
static std::string to_string(const vec<2, T>& val)
{
    return "(" + std::to_string(val.x) + ", " + std::to_string(val.y) + ")";
}

// ------------------------------vec3-------------------------------

template<typename T>
static float mag(const vec<3, T>& val)
{
    return math::sqrt(val.x * val.x + val.y * val.y + val.z * val.z);
}

template<typename T>
static vec<3, T> normalize(const vec<3, T>& val)
{
    float magnitude = 1.f / math::mag(val);
    return vec<3, T>(val.x * magnitude, val.y * magnitude, val.z * magnitude);
}

template<typename T>
static vec<3, T> cross(const vec<3, T>& first, const vec<3, T>& second)
{
    return vec<3, T>(first.y * second.z - first.z * second.y, first.z * second.x - first.x * second.z, first.x * second.y - first.y * second.x);
}

template<typename T>
static float dot(const vec<3, T>& first, const vec<3, T>& second)
{
    return first.x * second.x + first.y * second.y + first.z * second.z;
}

template<typename T>
static std::string to_string(const vec<3, T>& val)
{
    return "(" + std::to_string(val.x) + ", " + std::to_string(val.y) + ", " + std::to_string(val.z) + ")";
}

// ------------------------------vec4-------------------------------

template<typename T>
static std::string to_string(const vec<4, T>& val)
{
    return "(" + std::to_string(val.x) + ", " + std::to_string(val.y) + ", " + std::to_string(val.z) + ", " + std::to_string(val.w) + ")";
}

// ------------------------------other-------------------------------

template<typename T>
static vec<3, T> scale(const vec<3, T>& v, const T& s)
{
    return v * s / length(v);
}

template<length_t L, typename T>
static T length(const vec<L, T>& v)
{
    return sqrt(dot(v, v));
}

// other

template<length_t L, typename T>
static vec<L, T> max(const vec<L, T>& a, const vec<L, T>& b)
{
    vec<L, T> result;
    for (length_t i = 0; i < L; i++)
    {
        result[i] = a[i] > b[i] ? a[i] : b[i];
    }

    return result;
}

template<length_t L, typename T>
static vec<L, T> min(const vec<L, T>& a, const vec<L, T>& b)
{
    vec<L, T> result;
    for (length_t i = 0; i < L; i++)
    {
        result[i] = a[i] < b[i] ? a[i] : b[i];
    }

    return result;
}

template<length_t L, typename T>
static T max(const vec<L, T>& v)
{
    T maxVal = v[0];

    for (length_t i = 0; i < L; i++)
    {
        if (v[i] > maxVal)
        {
            maxVal = v[i];
        }
    }

    return maxVal;
}

template<typename T>
static vec<2, T> reflect(const vec<2, T>& i, const vec<2, T>& n)
{
    return i - (n * (dot(i, n) * 2.f));
}

template<length_t L, typename T>
static T dist(const vec<L, T>& a, const vec<L, T>& b)
{
    T r = static_cast<T>(0);

    for (length_t i = 0; i < L; i++)
    {
        r += b[i] - a[i];
    }

    return sqrt(abs(r));
}

} // namespace math