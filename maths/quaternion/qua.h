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

    qua(const vec<3, T>& eulerAngle)
    {
        vec<3, T> c = math::cos(eulerAngle * T(0.5));
        vec<3, T> s = math::sin(eulerAngle * T(0.5));

        this->w = c.x * c.y * c.z + s.x * s.y * s.z;
		this->x = s.x * c.y * c.z - c.x * s.y * s.z;
		this->y = c.x * s.y * c.z + s.x * c.y * s.z;
		this->z = c.x * c.y * s.z - s.x * s.y * c.z;
    }
    
    qua& operator=(const qua& q)
    {
        w = q.w; x = q.x; y = q.y; z = q.z;
        return *this;
    }

    template<typename U>
    qua& operator=(const qua<U>& q)
    {
        w = static_cast<T>(q.w);
        x = static_cast<T>(q.x);
        y = static_cast<T>(q.y);
        z = static_cast<T>(q.z);

        return *this;
    }

    ~qua() = default;

    T w, x, y, z;

    qua& operator+=(const qua& q)
    {
        *this = operator+(q);
        return *this;
    }

    qua& operator-=(const qua& q)
    {
        *this = operator*(q);
        return *this;
    }

    qua& operator*=(const qua& q)
    {
        *this = operator*(q);
        return *this;
    }

    qua& operator*=(const T& v)
    {
        *this = operator*(v);
        return *this;
    }

    qua& operator/=(const T& s)
    {
        *this = operator/(s);
        return *this;
    }
};

typedef qua<float> quat;
typedef qua<double> dquat;
typedef qua<float> fquat;

template<typename T>
qua<T> operator+(const qua<T>& q)
{
    return q;
}

template<typename T>
qua<T> operator-(const qua<T>& q)
{
    return qua<T>(-q.w, -q.x, -q.y, -q.z);
}

template<typename T>
qua<T> operator+(const qua<T>& q1, const qua<T>& q2)
{
    return qua(q1.w + q2.w, q1.x + q2.x, q1.y + q2.y, q1.z + q2.z);
}

template<typename T>
qua<T> operator-(const qua<T>& q1, const qua<T>& q2)
{
    return qua(q1.w - q2.w, q1.x - q2.x, q1.y - q2.y, q1.z - q2.z);
}

template<typename T>
qua<T> operator*(const qua<T>& q1, const qua<T>& q2)
{
    return qua<T>(q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
                  q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
                  q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z,
                  q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x);
}

template<typename T>
qua<T> operator*(const qua<T>& q, const T& s)
{
    return qua(q.w * s, q.x * s, q.y * s, q.z * s);
}

template<typename T>
qua<T> operator*(const T& s, const qua<T>& q)
{
    return q * s;
}

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
qua<T> operator/(const qua<T>& q, const T& s)
{
    return qua(q.w / s, q.x / s, q.y / s, q.z / s);
}

template<typename T>
qua<T> operator/(const T& s, const qua<T>& q)
{
    return q * s;
}

template<typename T>
bool operator==(const qua<T>& q1, const qua<T>& q2)
{
    return q1.w == q2.w && q1.x == q2.x && q1.y == q2.y && q1.z == q2.z;
}

template<typename T>
bool operator!=(const qua<T>& q1, const qua<T>& q2)
{
    return q1.w != q2.w || q1.x != q2.x || q1.y != q2.y || q1.z != q2.z;
}


}