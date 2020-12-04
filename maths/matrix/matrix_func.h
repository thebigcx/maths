#pragma once

#include <string>

#include "mat4x4.h"

namespace math
{

template<int width, int height, typename T>
static std::string str(const mat<width, height, T>& matrix)
{
    std::string s;
    for (int x = 0 ; x < width ; x++)
    {
        for (int y = 0 ; y < height ; y++)
        {
            s.append(std::to_string(m_cells[y][x]));
            s.append(", ");
        }
        s.append("\n");
    }

    return s;
}

}