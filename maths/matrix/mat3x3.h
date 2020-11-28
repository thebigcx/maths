#pragma once

#include "mat.h"

namespace math
{

template<typename T>
class mat<3, 3, T>
{
private:
    typedef vec<3, T> column_type;

public:
    mat<3, 3, T>()
    {
    }

    mat<3, 3, T>(float val)
    {
        for (int i = 0 ; i < 3 ; i++)
        {
            m_cells[i][i] = val;
        }
    }

    mat<3, 3, T>(const mat<4, 4, T>& matrix)
    {
        for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
        {
            m_cells[x][y] = matrix[x][y];
        }
    }

    mat<3, 3, T> operator*(const mat<3, 3, T>& m2)
    {
        mat<3, 3, T> result;

        // Multiply them together
        result[0] = m_cells[0] * m2[0].x + m_cells[1] * m2[0].y + m_cells[2] * m2[0].z;
        result[1] = m_cells[0] * m2[1].x + m_cells[1] * m2[1].y + m_cells[2] * m2[1].z;
        result[2] = m_cells[0] * m2[2].x + m_cells[1] * m2[2].y + m_cells[2] * m2[2].z;

        return result;
    }

    vec<3, T> operator*(const vec<3, T>& val)
    {
        vec<3, T> result;

        result.x = getRow(0).x * val.x + getRow(0).y * val.y + getRow(0).z * val.z;
        result.y = getRow(1).x * val.x + getRow(1).y * val.y + getRow(1).z * val.z;
        result.z = getRow(2).x * val.x + getRow(2).y * val.y + getRow(2).z * val.z;

        return result;
    }

    vec<3, T> getRow(int i) const
    {
        return vec<3, T>(m_cells[0][i], m_cells[1][i], m_cells[2][i]);
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
    column_type m_cells[3];

    friend const T* buffer<>(const mat<3, 3, T>& mat);
};

typedef mat<3, 3, float>        mat3;
typedef mat<3, 3, int>          imat3;
typedef mat<3, 3, long>         lmat3;
typedef mat<3, 3, double>       dmat3;
typedef mat<3, 3, unsigned int> umat3;

}
