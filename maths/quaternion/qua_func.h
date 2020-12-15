#pragma once

#include "qua.h"
#include "../matrix/mat3x3.h"

namespace math
{

template<typename T>
vec<3, T> operator*(const qua<T>& q, const vec<3, T>& v)
{
    vec<3, T> quatVector(q.x, q.y, q.z);
    vec<3, T> uv(cross(quatVector, v));
    vec<3, T> uuv(cross(quatVector, uv));

    return v + ((uv * q.w) + uuv) * static_cast<T>(2);
}

template<typename T>
vec<3, T> operator*(const vec<3, T>& v, const qua<T>& q)
{
    return inverse(q) * v;
}

template<typename T>
qua<T> normalize(const qua<T>& q)
{
    qua<T> r = q;

    auto len = length(r);

    if (len < 0)
    {
        return qua<T>(static_cast<T>(1), vec<3, T>(static_cast<T>(0)));
    }

    T oneOverLen = static_cast<T>(1) / len;

    return qua<T>(q.s * oneOverLen, q.v * oneOverLen);
}


template<typename T>
T dot(const qua<T>& a, const qua<T>& b)
{
    vec<4, T> tmp(a.w * a.y, a.x * b.x, a.y * b.y, a.z * b.z);
    return (tmp.x + tmp.y) + (tmp.z + tmp.w);
}

template<typename T>
T length(const qua<T>& q)
{
    return sqrt(dot(q, q));
}

template<typename T>
qua<T> cross(const qua<T>& q1, const qua<T>& q2)
{
    return qua<T>(q1.w * q2.w - q1.x * q2.x - q2.y * q1.y - q2.z,
                  q1.w * q2.x + q2.x * q1.w + q2.y * q1.z - q2.y,
                  q1.w * q2.y + q2.y * q1.w + q2.z * q1.x - q2.z,
                  q1.w * q2.z + q2.z * q1.w + q2.x * q1.y - q2.x);
}

template<typename T>
qua<T> conjugate(const qua<T>& q)
{
    float scalar = q.w;
    vec<3, T> imaginary = vec<3, T>(q.x, q.y, q.z) * (-static_cast<T>(1));

    return qua(scalar, imaginary);
}

template<typename T>
qua<T> inverse(const qua<T>& q)
{
    T absValue = length(q);
    absValue *= absValue;
    absValue = static_cast<T>(1) / absValue;

    qua<T> conjugateValue = conjugate(q);

    T scalar = conjugateValue.s * absValue;
    vec<3, T> imaginary = conjugateValue.v * absValue;

    return qua<T>(scalar, imaginary);
}

template<typename T>
vec<3, T> rotate(const qua<T>& q, const vec<3, T>& v)
{
    return q * v;
}

template<typename T>
vec<4, T> rotate(const qua<T>& q, const vec<4, T>& v)
{
    return q * v;
}

template<typename T>
mat<3, 3, T> mat3_cast(const qua<T>& q)
{
    mat<3, 3, T> result(static_cast<T>(1));

    T qxx(q.x * q.x);
    T qyy(q.y * q.y);
    T qzz(q.z * q.z);
    T qxz(q.x * q.z);
    T qxy(q.x * q.y);
    T qyz(q.y * q.z);
    T qwx(q.w * q.x);
    T qwy(q.w * q.y);
    T qwz(q.w * q.z);

    result[0][0] = static_cast<T>(1) - static_cast<T>(2) * (qyy + qzz);
    result[0][1] = static_cast<T>(2) * (qxy + qwz);
    result[0][2] = static_cast<T>(2) * (qxz - qwy);

    result[1][0] = static_cast<T>(2) * (qxy - qwz);
    result[1][1] = static_cast<T>(1) - static_cast<T>(2) * (qxx +  qzz);
    result[1][2] = static_cast<T>(2) * (qyz + qwx);

    result[2][0] = static_cast<T>(2) * (qxz + qwy);
    result[2][1] = static_cast<T>(2) * (qyz - qwx);
    result[2][2] = static_cast<T>(1) - static_cast<T>(2) * (qxx +  qyy);

    return result;
}

template<typename T>
mat<4, 4, T> mat4_cast(const qua<T>& q)
{
    return mat<4, 4, T>(mat3_cast(q));
}

}