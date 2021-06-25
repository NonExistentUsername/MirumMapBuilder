/*
 * Functions.hpp
 *
 *  Created on: 23 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once


#include "Segment.hpp"
#include "Vector2.hpp"

namespace Geometry {
	const double pi = 3.14159265358979323846264338327950288419716939937510;

	template<class T>
	inline void rotate(Segment<T>& segment, const Vector2<T>& relative_point, double angle) {
		segment.start -= relative_point;
		segment.end -= relative_point;

		segment.start.rotate(angle);
		segment.end.rotate(angle);

		segment.start += relative_point;
		segment.end += relative_point;
	}

	inline double degree_to_radian(double degree) {
		return degree * pi / 180.;
	}

	template<class T>
	inline T get_length(const Vector2<T> lhs, const Vector2<T> rhs) {
		return sqrt((rhs.x - lhs.x) * (rhs.x - lhs.x) + (rhs.y - lhs.y) * (rhs.y - lhs.y));
	}
}
