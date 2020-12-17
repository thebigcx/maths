#pragma once

#include "vector/vec.h"
#include "matrix/mat.h"

namespace math
{

template<unsigned int length, typename T>
const T* buffer(const vec<length, T>& v)
{
    return &(v.x);
}

template<unsigned int length, typename T>
T* buffer(vec<length, T>& v)
{
    return &(v.x);
}

template<int width, int height, typename T>
const T* buffer(const mat<width, height, T>& m)
{
    return &(m[0].x);
}

template<int width, int height, typename T>
T* buffer(mat<width, height, T>& m)
{
    return &(m[0].x);
}

}