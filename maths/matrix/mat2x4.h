#pragma once

#include "mat.h"

namespace math
{

template<typename T>
class mat<2, 4, T>
{
private:
    typedef vec<4, T> column_type;

public:
    mat<2, 4, T>()
    {
    }

    mat<2, 4, T>(float val)
    {
        for (unsigned int i = 0 ; i < 2 ; i++)
        {
            m_cells[i][i] = val;
        }
    }

    mat<2, 4, T> operator*(const mat<2, 4, T>& m2)
    {
        mat<2, 4, T> result;

        // Multiply them together
        //result[0] = m_cells[0] * m2[0].x + m_cells[1] * m2[0].y + m_cells[2] * m2[0].z;
        //result[1] = m_cells[0] * m2[1].x + m_cells[1] * m2[1].y + m_cells[2] * m2[1].z;

        return result;
    }

    vec<2, T> getRow(int i) const
    {
        return vec<2, T>(m_cells[0][i], m_cells[1][i]);
    }

private:
    column_type m_cells[2];
};

typedef mat<2, 4, float>        mat2x4;
typedef mat<2, 4, int>          imat2x4;
typedef mat<2, 4, long>         lmat2x4;
typedef mat<2, 4, double>       dmat2x4;
typedef mat<2, 4, unsigned int> umat2x4;

}
