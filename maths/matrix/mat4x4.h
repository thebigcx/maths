#pragma once

#include <cmath>
#include <iostream>

#include "../vector/vec3.h"
#include "../vector/vec4.h"
#include "../math.h"
#include "mat.h"

namespace math
{

template<typename T>
class mat<4, 4, T>
{
private:
    typedef vec<4, T> column_type;

public:
    mat<4, 4, T>()
        : m_cells{ column_type(0), column_type(0), column_type(0), column_type(0) }
    {}

    mat<4, 4, T>(const T& s)
        : m_cells{ column_type(s, 0, 0, 0), column_type(0, s, 0, 0), column_type(0, 0, s, 0), column_type(0, 0, 0, s) }
    {}

    mat<4, 4, T>(const mat<3, 3, T>& m)
        : m_cells{ column_type(m[0], 0), column_type(m[1], 0), column_type(m[2], 0), column_type(0, 0, 0, 1) }
    {}

    mat<4, 4, T>(const column_type& v0, const column_type& v1, const column_type& v2, const column_type& v3)
        : m_cells{ column_type(v0), column_type(v1), column_type(v2), column_type(v3) }
    {
        
    }

    mat<4, 4, T>(
        const T& m00, const T& m10, const T& m20, const T& m30,
        const T& m01, const T& m11, const T& m21, const T& m31,
        const T& m02, const T& m12, const T& m22, const T& m32,
        const T& m03, const T& m13, const T& m23, const T& m33
    )
        : m_cells{ { m00, m10, m20, m30 }, 
                   { m01, m11, m12, m13 }, 
                   { m02, m12, m22, m32 }, 
                   { m30, m31, m32, m33 } } {}

    column_type& operator[](int i)
    {
        return this->m_cells[i];
    }

    const column_type& operator[](int i) const
    {
        return this->m_cells[i];
    }

private:
    column_type m_cells[4];
};

template<typename T>
mat<4, 4, T> operator*(const mat<4, 4, T>& m, const T& s)
{
    mat<4, 4, T> result = m;

    result[0] *= s;
    result[1] *= s;
    result[2] *= s;
    result[3] *= s;

    return result;
}

template<typename T>
vec<3, T> operator*(const mat<4, 4, T>& m, const vec<3, T>& v)
{
    vec<3, T> result;

    result.x = m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2];
    result.y = m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2];
    result.z = m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2];

    return result;
}

template<typename T>
mat<4, 4, T> operator*(const mat<4, 4, T>& m1, const mat<4, 4, T>& m2)
{
    mat<4, 4, T> result;

    result[0] = m1[0] * m2[0][0] + m1[1] * m2[0][1] + m1[2] * m2[0][2] + m1[3] * m2[0][3];
    result[1] = m1[0] * m2[1][0] + m1[1] * m2[1][1] + m1[2] * m2[1][2] + m1[3] * m2[1][3];
    result[2] = m1[0] * m2[2][0] + m1[1] * m2[2][1] + m1[2] * m2[2][2] + m1[3] * m2[2][3];
    result[3] = m1[0] * m2[3][0] + m1[1] * m2[3][1] + m1[2] * m2[3][2] + m1[3] * m2[3][3];

    return result;
}

template<typename T>
vec<4, T> operator*(const mat<4, 4, T>& m, const vec<4, T>& v)
{
    vec<4, T> result;

    result.x = m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2] + m[3][0] * v[3];
    result.y = m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2] + m[3][1] * v[3];
    result.z = m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2] + m[3][2] * v[3];
    result.w = m[0][3] * v[0] + m[1][3] * v[1] + m[2][3] * v[2] + m[3][3] * v[3];

    return result;
}

typedef mat<4, 4, float>        mat4;
typedef mat<4, 4, int>          imat4;
typedef mat<4, 4, long>         lmat4;
typedef mat<4, 4, double>       dmat4;
typedef mat<4, 4, unsigned int> umat4;

}
