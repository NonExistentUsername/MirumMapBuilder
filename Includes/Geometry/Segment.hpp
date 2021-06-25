/*
 * Line.hpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */
#pragma once

#include "Vector2.hpp"
#include "../General/GlobalVariables.hpp"
#include "enums.hpp"
#include <math.h>

namespace Geometry {
	template<class T> class Line;
	template<class T> class Ray;

	template<class T>
	struct Segment {
		using Point = Vector2<T>;

		Point start, end;

		Segment(T start_x, T start_y, T end_x, T end_y): start(std::move(start_x), std::move(start_y)), end(std::move(end_x), std::move(end_y)) {}
		Segment(Point _start, Point _end): start(std::move(_start)), end(std::move(_end)) {}

		bool contains(const Point& point) const {
			return Ray<T>(*this).contains(point)
					&& (std::min(start.x, end.x) - EPS <= point.x
					&& std::min(start.y, end.y) - EPS <= point.y
					&& point.x <= std::max(start.x, end.x) + EPS
					&& point.y <= std::max(start.y, end.y) + EPS);
		}

		float get_size() const {
			return std::sqrt((end.x - start.x) * (end.x - start.x)
					+ (end.y - start.y) * (end.y - start.y));
		}

		bool intersects(const Segment<T>& other) const {
			Point _intersection_point = Ray<T>(other).get_intersection(*this);
			return this->contains(_intersection_point) && other.contains(_intersection_point);
		}

		Point get_intersection(const Segment<T>& other) const {
			return Ray<T>(*this).get_intersection(other);
		}

		~Segment() {}
	};

	using Segmentf = Segment<float>;
	using Segmentd = Segment<double>;
	using Segmenti = Segment<int>;
}
