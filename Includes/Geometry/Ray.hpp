/*
 * Ray.hpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

#include "Vector2.hpp"
#include "Segment.hpp"
#include "enums.hpp"

namespace Geometry{
	template<class T> class Line;

	template<class T>
	struct Ray {
		using Point = Vector2<T>;

//		new_point = start + direction * T;
		Point start, direction;

		Ray(Point _start, Point _direction): start(_start), direction(_direction) {
			direction.normalize();
		}
		Ray(Segment<T> segment): start((segment.start)), direction(segment.end - segment.start) {
			direction.normalize();
		}

/*
 * 		point = start1 + direction1 * T1
 * 		point = start2 + direction2 * T2
 *		start2 + direction2 * T2 = start1 + direction1 * T1
 *		\/ \/ \/ \/ \/ \/ \/
 *		start2.x + direction2.x * T2 = start1.x + direction1.x * T1
 *		start2.y + direction2.y * T2 = start1.y + direction1.y * T1
 *
 * 		(start2.x + direction2.x * T2 - start1.x) / direction1.x = T1
 * 		(start2.y + direction2.y * T2 - start2.y) / direction2.y = T1
 *
 * 		direction1.y * (start2.x - start1.x + direction2.x * T2) = direction1.x * (start2.y - start1.y + direction2.y * T2)
 * 		direction1.y * start2.x - direction.y * start1.x + direction1.y * direction2.x * T2 =
 * 		= direction1.x * start2.y - direction1.x * start1.y + direction1.x * direction2.y * T2
 *
 * 		direction1.y * start2.x - direction.y * start1.x - direction1.x * start2.y + direction1.x * start1.y =
 * 		= T2 * (direction1.x * direction2.y - direction1.y * direction2.x)
 * 		T2 = (direction1.y * (start2.x - start1.x) + direction1.x * (start1.y - start2.y)) / (direction1.x * direction2.y - direction1.y * direction2.x)
 *
 *		start2.x + direction2.x * T2 = start1.x + direction1.x * T1
 *		T1 = (start2.x + direction2.x * T2 - start1.x) / direction1.x
 *
 */

/*
 *
 * 		start.x + direction.x * T = point.x
 *	    start.y + direction.y * T = point.y
 *
 *	    (point.x - start.x) / direction.x = T
 *
 */

		bool contains(const Vector2<T>& point) const {
			if(std::abs(direction.x) <= EPS) {
				T _T = (point.y - start.y) / direction.y;
				return (_T >= 0) && std::abs(start.x + direction.x * _T - point.x) <= EPS;
			} else {
				T _T = (point.x - start.x) / direction.x;
				return (_T >= 0) && std::abs(start.y + direction.y * _T - point.y) <= EPS;
			}
		}

		bool intersect(const Ray<T>& other) const {
			if(other.direction == direction || other.direction == -1. * direction)
				return false;

			T _T2 = (direction.y * (other.start.x - start.x) + direction.x * (start.y - other.start.y)) / (direction.x * other.direction.y - direction.y * other.direction.x);
			T _T1 = (other.start.x + other.direction.x * _T2 - start.x) / direction.x;

			return (_T2 >= 0 && _T1 >= 0);
		}

		bool intersect(const Segment<T>& other) const {
			const Ray<T> _other_ray(other);
			return intersect(_other_ray) && other.contains(_other_ray.get_intersection(*this));
		}

		Point get_intersection(const Segment<T>& other) const {
			return this->get_intersection(Ray<T>(other));
		}

		Point get_intersection(const Ray<T>& other) const {
//			if(other.direction == direction || other.direction == -1. * direction)
//				return point;

			T _T2 = (direction.y * (other.start.x - start.x) + direction.x * (start.y - other.start.y)) / (direction.x * other.direction.y - direction.y * other.direction.x);
			T _T1 = direction.x != 0 ?
					(other.start.x + other.direction.x * _T2 - start.x) / direction.x :
					(other.start.y + other.direction.y * _T2 - start.y) / direction.y;

//			if(_T1 < EPS || _T2 < EPS) {
//				return point;
//			}
			return start + direction * _T1;
		}
	};

	using Rayd = Ray<double>;
}
