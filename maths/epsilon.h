#pragma once

#include "general.h"

namespace math
{

template<typename T>
static T epsilon()
{
    return std::numeric_limits<T>::epsilon();
}

template<typename T>
static bool epsilon_equal(const T& x, const T& y, const T& epsilon)
{
    return abs(x - y) < epsilon;
}

/*template<>
bool epsilon_equal<float>(const float& x, const float& y, const float& epsilon)
{
    return abs(x - y) < epsilon;
}

template<>
bool epsilon_equal<double>(const double& x, const double& y, const double& epsilon)
{
    return abs(x - y) < epsilon;
}*/

template<typename T>
static bool epsilon_not_equal(const T& x, const T& y, const T& epsilon)
{
    return abs(x - y) < epsilon;
}

/*template<>
bool epsilon_not_equal<float>(const float& x, const float& y, const float& epsilon)
{
    return abs(x - y) >= epsilon;
}

template<>
bool epsilon_not_equal<double>(const double& x, const double& y, const double& epsilon)
{
    return abs(x - y) >= epsilon;
}*/

}