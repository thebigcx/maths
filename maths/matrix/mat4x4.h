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
    {
        
    }

    mat<4, 4, T>(float val)
    {
        for (unsigned int i = 0 ; i < 4 ; i++)
        {
            m_cells[i][i] = val;
        }
    }

    mat<4, 4, T>(const mat<3, 3, T>& matrix)
    {
        for (unsigned int x = 0; x < 3; x++)
        for (unsigned int y = 0; y < 3; y++)
        {
            m_cells[x][y] = matrix[x][y];
        }

        m_cells[3][3] = 1.f;
    }

    mat<4, 4, T> operator*(const mat<4, 4, T>& m2) const
    {
        mat<4, 4, T> result;

        result[0] = (*this)[0] * m2[0].x + (*this)[1] * m2[0].y + (*this)[2] * m2[0].z + (*this)[3] * m2[0].w;
        result[1] = (*this)[0] * m2[1].x + (*this)[1] * m2[1].y + (*this)[2] * m2[1].z + (*this)[3] * m2[1].w;
        result[2] = (*this)[0] * m2[2].x + (*this)[1] * m2[2].y + (*this)[2] * m2[2].z + (*this)[3] * m2[2].w;
        result[3] = (*this)[0] * m2[3].x + (*this)[1] * m2[3].y + (*this)[2] * m2[3].z + (*this)[3] * m2[3].w;

        return result;
    }

    vec<4, T> operator*(const vec<4, T>& val) const
    {
        vec<4, T> result;

        result.x = getRow(0).x * val.x + getRow(0).y * val.y + getRow(0).z * val.z + getRow(0).w * val.w;
        result.y = getRow(1).x * val.x + getRow(1).y * val.y + getRow(1).z * val.z + getRow(1).w * val.w;
        result.z = getRow(2).x * val.x + getRow(2).y * val.y + getRow(2).z * val.z + getRow(2).w * val.w;
        result.w = getRow(3).x * val.x + getRow(3).y * val.y + getRow(3).z * val.z + getRow(3).w * val.w;

        return result;
    }

    vec<3, T> operator*(const vec<3, T>& val) const
    {
        vec<3, T> result;

        result.x = getRow(0).x * val.x + getRow(0).y * val.y + getRow(0).z * val.z;
        result.y = getRow(1).x * val.x + getRow(1).y * val.y + getRow(1).z * val.z;
        result.z = getRow(2).x * val.x + getRow(2).y * val.y + getRow(2).z * val.z;

        return result;
    }

    vec<4, T> getRow(int i) const
    {
        return vec<4, T>(m_cells[0][i], m_cells[1][i], m_cells[2][i], m_cells[3][i]);
    }

    column_type& operator[](int index)
    {
        return m_cells[index];
    }

    column_type operator[](int index) const
    {
        return m_cells[index];
    }

private:
    column_type m_cells[4];

    friend const T* buffer<>(const mat<4, 4, T>& mat);
};

typedef mat<4, 4, float>        mat4;
typedef mat<4, 4, int>          imat4;
typedef mat<4, 4, long>         lmat4;
typedef mat<4, 4, double>       dmat4;
typedef mat<4, 4, unsigned int> umat4;

}
