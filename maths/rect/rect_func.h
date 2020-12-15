#pragma once

#include "rect.h"

namespace math
{

template<typename T>
bool contains(const math::rect<T>& r, const math::vec<2, T>& v)
{
	return v.x > r.x && v.x < r.x + r.w && v.y > r.y && v.y < r.y + r.h;
}

template<typename T>
bool intersects(const math::rect<T>& a, const math::rect<T>& b)
{
	return b.x < a.x + a.w && b.x + b.w > a.x &&
		   b.y < a.y + a.h && b.y + b.h > a.y;
}

template<typename T>
math::vec<2, T> intersection(const math::rect<T>& a, const math::rect<T>& b)
{
	return vec<2, T>(abs(b.x - a.x + a.w), abs(b.y - a.y + a.h));
}

}