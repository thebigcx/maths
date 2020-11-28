#pragma once

#include <cmath>

namespace math
{

static constexpr double radians(float deg)
{
    return deg * static_cast<float>(0.01745329251994329576923690768489);
}

static constexpr int degrees(float rad)
{
    return rad * static_cast<float>(57.295779513082320876798154814105);
}

static constexpr double sin(double x)
{
    return std::sin(x);
}

static constexpr double cos(double x)
{
    return std::cos(x);
}

static constexpr double tan(double x)
{
    return std::tan(x);
}

static constexpr double asin(double x)
{
    return std::asin(x);
}

static constexpr double acos(double x)
{
    return std::acos(x);
}

static constexpr double atan(double x)
{
    return std::atan(x);
}

static constexpr double asinh(double x)
{
    return std::asinh(x);
}

static constexpr double acosh(double x)
{
    return std::acosh(x);
}

static constexpr double atanh(double x)
{
    return std::atanh(x);
}

static constexpr double csc(double x)
{
    return 1.f / std::sin(x);
}

static constexpr double sec(double x)
{
    return 1.f / std::cos(x);
}

static constexpr double cot(double x)
{
    return 1.f / std::cos(x);
}

}; // namespace math