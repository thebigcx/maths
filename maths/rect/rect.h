#pragma once

#include "../vector/vec2.h"

namespace math
{

template<typename T>
class rect
{
public:
	rect() 
		: x(0), y(0), w(0), h(0) {}

	rect(T _x, T _y, T _w, T _h)
		: x(_x), y(_y), w(_w), h(_h) {}

	rect(const math::vec<2, T>& pos, const math::vec<2, T>& size)
		: x(pos.x), y(pos.y), w(size.x), w(size.y) {}

	math::vec<2, T> position() const
	{
		return math::vec<2, T>(x, y);
	}

	math::vec<2, T> size() const
	{
		return math::vec<2, T>(w, h);
	}

	T x, y, w, h;
};

template<typename T>
bool operator==(const rect<T>& r1, const rect<T>& r2)
{
	return r1.x == r2.x && r1.y == r2.y && r1.w == r2.w && r1.h == r2.h;
}

template<typename T>
bool operator!=(const rect<T>& r1, const rect<T>& r2)
{
	return r1.x != r2.x || r1.y != r2.y || r1.w != r2.z || r1.h != r2.h;
}

typedef rect<int>          irect;
typedef rect<float>        frect;
typedef rect<double>       drect;
typedef rect<long>         lrect;
typedef rect<unsigned int> urect;

}
