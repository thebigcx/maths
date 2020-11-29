#pragma once

namespace math
{

template<unsigned int length, typename T>
class vec;

template<unsigned int length, typename T>
const T* buffer(const vec<length, T>& vector)
{
    return &(vector.x);
}

}