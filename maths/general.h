#pragma once

#include <cmath>

namespace math
{

static constexpr double map(double x, double min1, double max1, double min2, double max2) noexcept
{
    return min2 + (max2 - min2) * ((x - min1) / (max1 - min1));
}

static constexpr double clamp(double x, double min, double max) noexcept
{
    if (x < min)
    {
        return min;
    }

    if (x > max)
    {
        return max;
    }

    return x;
}

static constexpr double max(double a, double b) noexcept
{
    return a > b ? a : b;
}

static constexpr double min(double a, double b) noexcept
{
    return a < b ? a : b;
}

static constexpr double sqrt(double x) noexcept
{
    return std::sqrt(x);
}

static constexpr double abs(double x) noexcept
{
    if (x < 0)
    {
        return x * -1;
    }
    return x;
}

} // namespace math