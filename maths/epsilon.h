#pragma once

#include "general.h"
#include "constants.h"

namespace math
{

template<typename T>
static bool epsilon_equal(const T& x, const T& y, const T& epsilon)
{
    return abs(x - y) < epsilon;
}

template<typename T>
static bool epsilon_not_equal(const T& x, const T& y, const T& epsilon)
{
    return abs(x - y) >= epsilon;
}

}