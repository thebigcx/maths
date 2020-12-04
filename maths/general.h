#pragma once

#include <cmath>

namespace math
{

static constexpr double map(double value, double istart, double istop, double ostart, double ostop) noexcept
{
    return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
}

static constexpr double clamp(double value, double min, double max) noexcept
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

static constexpr double max(double a, double b) noexcept
{
    return a > b ? a : b;
}

static constexpr double min(double a, double b) noexcept
{
    return a < b ? a : b;
}

static constexpr double sqrt(double val) noexcept
{
    return std::sqrt(val);
}

static constexpr double abs(double val) noexcept
{
    return std::abs(val);
}

} // namespace math