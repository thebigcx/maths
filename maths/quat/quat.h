#pragma once

#include "../vector/vec.h"

namespace math
{

class quat
{
private:
    typedef float value_type;
    typedef vec<3, value_type> vec_type;

public:
    quat() = default;

    quat(const value_type& uS, const vec_type& uV)
        : s(uS), v(uV) {}

    quat(const quat& value)
        : s(value.s), v(value.v) {}

    quat& operator=(const quat& value)
    {
        s = value.s;
        v = value.v;

        return *this;
    }

    ~quat() = default;

    vec_type v;
    value_type s;

    void operator+=(const quat& q)
    {
        s += q.s;
        v += q.v;
    }

    quat operator+(const quat& q) const
    {
        value_type scalar = s + q.s;
        vec_type imaginary = v + q.v;

        return quat(scalar, imaginary);
    }

    void operator-=(const quat& q)
    {
        s -= q.s;
        v -= q.v;
    }

    quat operator-(const quat& q) const
    {
        value_type scalar = s - q.s;
        vec_type imaginary = v - q.v;

        return quat(scalar, imaginary);
    }
};

}