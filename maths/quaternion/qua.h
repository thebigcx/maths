#pragma once

#include "../vector/vec.h"

namespace math
{

template<typename T>
class qua
{
public:
    qua() = default;

    qua(const qua& q)
        : w(q.w), x(q.x), y(q.y), z(q.z) {}

    qua(T _w, T _x, T _y, T _z)
        : w(_w), x(_x), y(_y), z(_z) {}

    qua& operator=(const qua& q)
    {
        w = q.w;
        x = q.x;
        y = q.y;
        z = q.z;

        return *this;
    }

    ~qua() = default;

    T w, x, y, z;

    void operator+=(const qua& q)
    {
        *this = operator+(q);
    }

    qua operator+(const qua& q) const
    {
        return qua(w + q.w, x + q.x, y + q.y, z + q.z);
    }

    void operator-=(const qua& q)
    {
        *this = operator*(q);
    }

    qua operator-(const qua& q) const
    {
       return qua(w - q.w, x - q.x, y - q.y, z - q.z);
    }

    void operator*=(const qua& q)
    {
        *this = operator*(q);
    }

    qua operator*(const qua& q) const
    {
        qua p(*this);

        return qua(p.w * q.w - p.x * q.x - p.y * q.y - p.z * q.z,
                   p.w * q.x + p.x * q.w + p.y * q.z - p.z * q.y,
                   p.w * q.y + p.y * q.w + p.z * q.x - p.x * q.z,
                   p.w * q.z + p.z * q.w + p.x * q.y - p.y * q.x);
    }

    void operator*=(const T& v)
    {
        *this = operator*(v);
    }

    qua operator*(const T& s) const
    {
        return qua(w * s, x * s, y * s, z * s);
    }

    void operator/=(const T& s)
    {
        *this = operator/(s);
    }

    qua operator/(const T& s) const
    {
        return qua(w / s, x / s, y / s, z / s);
    }

};

typedef qua<float> quat;
typedef qua<double> dquat;
typedef qua<float> fquat;


}