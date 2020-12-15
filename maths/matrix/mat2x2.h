#pragma once

#pragma once

#include "mat.h"

namespace math
{

template<typename T>
class mat<2, 2, T>
{
private:
    typedef vec<2, T> column_type;

public:
    mat<2, 2, T>()
    {
    }

    mat<2, 2, T>(float val)
    {
        for (unsigned int i = 0 ; i < 2 ; i++)
        {
            m_cells[i][i] = val;
        }
    }

    mat<2, 2, T> operator*(const mat<2, 2, T>& m2)
    {
        mat<2, 2, T> result;

        // Multiply them together
        result[0] = m_cells[0] * m2[0].x + m_cells[1] * m2[0].y;
        result[1] = m_cells[0] * m2[1].x + m_cells[1] * m2[1].y;

        return result;
    }

    vec<2, T> operator*(const vec<2, T>& val)
    {
        vec<2, T> result;

        result.x = getRow(0).x * val.x + getRow(0).y * val.y;
        result.y = getRow(1).x * val.x + getRow(1).y * val.y;

        return result;
    }

    vec<2, T> getRow(int i) const
    {
        return vec<2, T>(m_cells[0][i], m_cells[1][i]);
    }

private:
    column_type m_cells[2];
};

typedef mat<2, 2, float>        mat2;
typedef mat<2, 2, int>          imat2;
typedef mat<2, 2, long>         lmat2;
typedef mat<2, 2, double>       dmat2;
typedef mat<2, 2, unsigned int> umat2;

}
