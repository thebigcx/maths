#pragma once

#include <string>

#include "mat4x4.h"

namespace math
{

template<int width, int height, typename T>
static std::string to_string(const mat<width, height, T>& matrix)
{
    std::string s;
    for (unsigned int x = 0 ; x < width ; x++)
    {
        for (unsigned int y = 0 ; y < height ; y++)
        {
            s.append(std::to_string(matrix[y][x]));
            s.append(", ");
        }
        s.append("\n");
    }

    return s;
}

template<typename T>
static mat<4, 4, T> inverse(const mat<4, 4, T>& m)
{
    T coef00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
    T coef02 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
    T coef03 = m[1][2] * m[2][3] - m[2][2] * m[1][3];

    T coef04 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
    T coef06 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
    T coef07 = m[1][1] * m[2][3] - m[2][1] * m[1][3];

    T coef08 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
    T coef10 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
    T coef11 = m[1][1] * m[2][2] - m[2][1] * m[1][2];

    T coef12 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
    T coef14 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
    T coef15 = m[1][0] * m[2][3] - m[2][0] * m[1][3];

    T coef16 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
    T coef18 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
    T coef19 = m[1][0] * m[2][2] - m[2][0] * m[1][2];

    T coef20 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
    T coef22 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
    T coef23 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

    vec<4, T> Fac0(coef00, coef00, coef02, coef03);
    vec<4, T> Fac1(coef04, coef04, coef06, coef07);
    vec<4, T> Fac2(coef08, coef08, coef10, coef11);
    vec<4, T> Fac3(coef12, coef12, coef14, coef15);
    vec<4, T> Fac4(coef16, coef16, coef18, coef19);
    vec<4, T> Fac5(coef20, coef20, coef22, coef23);

    vec<4, T> Vec0(m[1][0], m[0][0], m[0][0], m[0][0]);
    vec<4, T> Vec1(m[1][1], m[0][1], m[0][1], m[0][1]);
    vec<4, T> Vec2(m[1][2], m[0][2], m[0][2], m[0][2]);
    vec<4, T> Vec3(m[1][3], m[0][3], m[0][3], m[0][3]);

    vec<4, T> Inv0(Vec1 * Fac0 - Vec2 * Fac1 + Vec3 * Fac2);
    vec<4, T> Inv1(Vec0 * Fac0 - Vec2 * Fac3 + Vec3 * Fac4);
    vec<4, T> Inv2(Vec0 * Fac1 - Vec1 * Fac3 + Vec3 * Fac5);
    vec<4, T> Inv3(Vec0 * Fac2 - Vec1 * Fac4 + Vec2 * Fac5);

    vec<4, T> SignA(+1, -1, +1, -1);
    vec<4, T> SignB(-1, +1, -1, +1);
    mat<4, 4, T> Inverse(Inv0 * SignA, Inv1 * SignB, Inv2 * SignA, Inv3 * SignB);

    vec<4, T> Row0(Inverse[0][0], Inverse[1][0], Inverse[2][0], Inverse[3][0]);

    vec<4, T> Dot0(m[0] * Row0);
    T Dot1 = (Dot0.x + Dot0.y) + (Dot0.z + Dot0.w);

    T OneOverDeterminant = static_cast<T>(1) / Dot1;

    return Inverse * OneOverDeterminant;
}

}