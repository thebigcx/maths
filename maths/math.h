#pragma once

#include <cmath>
#include <ctime>
#include <cstdlib>

namespace math
{

struct random
{
    static void initSeed()
    {
        std::srand(std::time(nullptr));
    }

    static double generate(int min, int max)
    {
        double f = (double)std::rand() / RAND_MAX;
        return min + f * (max - min);
    }
};

static double map(double value, double istart, double istop, double ostart, double ostop)
{
    return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
}

static double clamp(double value, double min, double max)
{
    if (value < min)
    {
        return min;
    }

    if (value > max)
    {
        return max;
    }

    return value;
}

static double radians(float deg)
{
    return deg * static_cast<float>(0.01745329251994329576923690768489);
}

static int degrees(float rad)
{
    return rad * static_cast<float>(57.295779513082320876798154814105);
}

static double sin(double x)
{
    return std::sin(x);
}

static double cos(double x)
{
    return std::cos(x);
}

static double tan(double x)
{
    return std::tan(x);
}

static double asin(double x)
{
    return std::asin(x);
}

static double acos(double x)
{
    return std::acos(x);
}

static double atan(double x)
{
    return std::atan(x);
}

static double asinh(double x)
{
    return std::asinh(x);
}

static double acosh(double x)
{
    return std::acosh(x);
}

static double atanh(double x)
{
    return std::atanh(x);
}

static double csc(double x)
{
    return 1.f / std::sin(x);
}

static double sec(double x)
{
    return 1.f / std::cos(x);
}

static double cot(double x)
{
    return 1.f / std::cos(x);
}

} // namespace Math

