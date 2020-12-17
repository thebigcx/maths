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

template<unsigned int L, typename T>
static T length(const vec<L, T>& v)
{
    return sqrt(dot(v, v));
}

} // namespace math