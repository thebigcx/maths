#pragma once

#include "mat.h"

namespace math
{

template<typename T>
class mat<2, 3, T>
{
private:
    typedef vec<3, T> column_type;

public:
    mat<2, 3, T>()
    {
    }

    mat<2, 3, T>(float val)
    {
        for (unsigned int i = 0 ; i < 2 ; i++)
        {
            m_cells[i][i] = val;
        }
    }

    mat<2, 3, T> operator*(const mat<2, 3, T>& m2)
    {
        mat<2, 3, T> result;

        // Multiply them together
        //result[0] = m_cells[0] * m2[0].x + m_cells[1] * m2[0].y + m_cells[2] * m2[0].z;
        //result[1] = m_cells[0] * m2[1].x + m_cells[1] * m2[1].y + m_cells[2] * m2[1].z;

        return result;
    }

    vec<2, T> getRow(int i) const
    {
        return vec<3, T>(m_cells[0][i], m_cells[1][i]);
    }

private:
    column_type m_cells[2];
};

typedef mat<2, 3, float>        mat2x3;
typedef mat<2, 3, int>          imat2x3;
typedef mat<2, 3, long>         lmat2x3;
typedef mat<2, 3, double>       dmat2x3;
typedef mat<2, 3, unsigned int> umat2x3;

}
