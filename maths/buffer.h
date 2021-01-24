#pragma once

#include "vector/vec.h"
#include "matrix/mat.h"

namespace math
{

template<length_t L, typename T>
const T* buffer(const vec<L, T>& v)
{
    return &(v.x);
}

template<length_t L, typename T>
T* buffer(vec<L, T>& v)
{
    return &(v.x);
}

template<length_t W, length_t H, typename T>
const T* buffer(const mat<W, H, T>& m)
{
    return &(m[0].x);
}

template<length_t W, length_t H, typename T>
T* buffer(mat<W, H, T>& m)
{
    return &(m[0].x);
}

}