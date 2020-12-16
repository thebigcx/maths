#pragma once

#include "mat4x4.h"

namespace math
{

/*template<int width, int height, typename T>
mat<width, height, T> identity()
{
    mat<width, height, T> matrix;
        
    for (unsigned int x = 0; x < width; x++)
    for (unsigned int y = 0; y < height; y++)
    {
        if (x == y)
        {
            matrix[x][y] = static_cast<T>(1);
        }
    }

    return matrix;
}*/

template<int w, int h>
mat<w, h, float> identity()
{
    return mat<w, h, float>(1.f);
}

template<int w, int h>
mat<w, h, double> identity()
{
    return mat<w, h, double>(1.d);
}

template<int w, int h>
mat<w, h, int> identity()
{
    return mat<w, h, int>(1);
}

template<int w, int h>
mat<w, h, unsigned int> identity()
{
    return mat<w, h, unsigned int>(1);
}

template<int w, int h>
mat<w, h, long> identity()
{
    return mat<w, h, long>(1);
}

template<typename T>
mat<4, 4, T> translate(const mat<4, 4, T>& m, const vec<3, T>& v)
{
    mat<4, 4, T> result = m;

    result[3][0] += v.x * m[0][0];
    result[3][1] += v.y * m[1][1];
    result[3][2] += v.z * m[2][2];

    return result;
}

template<typename T>
mat<4, 4, T> scale(const mat<4, 4, T>& m, const vec<3, T>& s)
{
    mat<4, 4, T> result = m;

    result[0] *= vec<4, T>(s, static_cast<T>(1));
    result[1] *= vec<4, T>(s, static_cast<T>(1));
    result[2] *= vec<4, T>(s, static_cast<T>(1));

    return result;
}

template<typename T>
mat<4, 4, T> rotate(const mat<4, 4, T>& m, T angle, const vec<3, T>& v)
{
    mat<4, 4, T> rotate = m;

    T c = math::cos(angle);
    T s = math::sin(angle);
    T omc = static_cast<T>(1) - c;

    vec<3, T> axis(normalize(v));

    T x = axis.x;
    T y = axis.y;
    T z = axis.z;

    rotate[0][0] = x * x * omc + c;
    rotate[0][1] = y * x * omc + z * s;
    rotate[0][2] = x * z * omc - y * s;

    rotate[1][0] = x * y * omc - z * s;
    rotate[1][1] = y * y * omc + c;
    rotate[1][2] = y * z * omc + x * s;

    rotate[2][0] = x * z * omc + y * s;
    rotate[2][1] = y * z * omc - x * s;
    rotate[2][2] = z * z * omc + c;

    mat<4, 4, T> result;
    result[0] = m[0] * rotate[0][0] + m[1] * rotate[0][1] + m[2] * rotate[0][2];
    result[1] = m[0] * rotate[1][0] + m[1] * rotate[1][1] + m[2] * rotate[1][2];
    result[2] = m[0] * rotate[2][0] + m[1] * rotate[2][1] + m[2] * rotate[2][2];
    result[3] = m[3];

    return result;
}

template<typename T>
mat<4, 4, T> ortho(T left, T right, T bottom, T top, T near, T far)
{
    mat<4, 4, T> mat(static_cast<T>(1));

    mat[0][0] = static_cast<T>(2) / (right - left);
    mat[1][1] = static_cast<T>(2) / (top - bottom);
    mat[2][2] = static_cast<T>(-2) / (far - near);

    mat[3][0] = -(right + left) / (right - left);
    mat[3][1] = -(top + bottom) / (top - bottom);
    mat[3][2] = -(far + near) / (far - near);

    return mat;
}

template<typename T>
mat<4, 4, T> perspective(T fovy, T aspect, T zNear, T zFar)
{
    mat<4, 4, T> result;

    result[0][0] = static_cast<T>(1) / (aspect * math::tan(fovy / static_cast<T>(2)));
    result[1][1] = static_cast<T>(1) / math::tan(fovy / static_cast<T>(2));
    result[2][2] = -(zFar + zNear) / (zFar - zNear);
    result[2][3] = -static_cast<T>(1);
    result[3][2] = -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear);

    return result;
}

template<typename T>
mat<4, 4, T> lookAt(const vec<3, T>& pos, const vec<3, T>& object, const vec<3, T>& up)
{
    mat<4, 4, T> result(static_cast<T>(1));

    vec<3, T> f = math::normalize(object - pos);
    vec<3, T> s = math::normalize(math::cross(f, up));
    vec<3, T> u = math::cross(s, f);

    result[0][0] = s.x;
    result[1][0] = s.y;
    result[2][0] = s.z;

    result[0][1] = u.x;
    result[1][1] = u.y;
    result[2][1] = u.z;

    result[0][2] = -f.x;
    result[1][2] = -f.y;
    result[2][2] = -f.z;

    result[3][0] = -math::dot(s, pos);
    result[3][1] = -math::dot(u, pos);
    result[3][2] =  math::dot(f, pos);

    return result;
}

template<typename T>
static mat<3, 3, T> translate(const mat<3, 3, T>& m, const vec<2, T>& v)
{
    mat<3, 3, T> result = m;

    result[2][0] += v.x * result[0][0];
    result[2][1] += v.y * result[1][1];

    return result;
}

template<typename T>
static mat<3, 3, T> rotate(const mat<3, 3, T>& m, T angle)
{
    mat<3, 3, T> result = m;

    result[0][0] *= math::cos(angle);
    result[1][0] *= -math::sin(angle);
    result[0][1] *= math::sin(angle);
    result[1][1] *= math::cos(angle);

    return result;
}

template<typename T>
static mat<3, 3, T> scale(const mat<3, 3, T>& m, const vec<2, T>& s)
{
    mat<3, 3, T> result = m;

    result[0] *= vec<3, T>(s, 1);
    result[1] *= vec<3, T>(s, 1);

    return result;
}

}
