/*
 * Point.hpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

#include "../General/GlobalVariables.hpp"

#include <SFML/Graphics.hpp>
#include <memory>
#include <math.h>
#include <iostream>

namespace Geometry {

	template<class T>
	struct Vector2 {
		T x, y;

		Vector2() {}
		Vector2(T _x, T _y): x(_x), y(_y) {}
//		Vector2(T&& _x, T&& _y): x(std::move(_x)), y(std::move(_y)) {}
		template<class U>
		Vector2(const sf::Vector2<U>& other): x(other.x), y(other.y) {}

		Vector2(const Vector2<T>& other): x(other.x), y(other.y) {}
		Vector2(const sf::Vector2<T>& other): x(other.x), y(other.x) {}

		Vector2<T>& operator=(Vector2<T> other) {
			x = std::move(other.x);
			y = std::move(other.y);
			return *this;
		}

		T size() const {
			return sqrt(x * x + y * y);
		}

		void normalize() {
			(*this) /= size();
		}

		void rotate(T angle) {
			T new_x = x * cos(angle) - y * sin(angle);
			T new_y = x * sin(angle) + y * cos(angle);
			x = new_x;
			y = new_y;
		}

//////////////////////////////////////////////////////////////////////////////////////////

		Vector2<T> operator+(T val) const {
			return Vector2<T>(x + val, y + val);
		}

		Vector2<T> operator-(T val) const {
			return Vector2<T>(x - val, y - val);
		}

		Vector2<T> operator*(T val) const {
			return Vector2<T>(x * val, y * val);
		}

		Vector2<T> operator/(T val) const {
			return Vector2<T>(x / val, y / val);
		}

//////////////////////////////////////////////////////////////////////////////////////////

		Vector2<T>& operator+=(T val) {
			x += val;
			y += val;
			return *this;
		}

		Vector2<T>& operator-=(T val) {
			x -= val;
			y -= val;
			return *this;
		}

		Vector2<T>& operator*=(T val) {
			x *= val;
			y *= val;
			return *this;
		}

		Vector2<T>& operator/=(T val) {
			x /= val;
			y /= val;
			return *this;
		}

//////////////////////////////////////////////////////////////////////////////////////////

		Vector2<T> operator+(const Vector2<T>& val) const {
			return Vector2<T>(x + val.x, y + val.y);
		}

		Vector2<T> operator-(const Vector2<T>& val) const {
			return Vector2<T>(x - val.x, y - val.y);
		}

		Vector2<T> operator*(const Vector2<T>& val) const {
			return Vector2<T>(x * val.x, y * val.y);
		}

		Vector2<T> operator/(const Vector2<T>& val) const {
			return Vector2<T>(x / val.x, y / val.y);
		}

//////////////////////////////////////////////////////////////////////////////////////////

		Vector2<T>& operator+=(const Vector2<T>& val) {
			x += val.x;
			y += val.y;
			return *this;
		}

		Vector2<T>& operator-=(const Vector2<T>& val) {
			x -= val.x;
			y -= val.y;
			return *this;
		}

		Vector2<T>& operator*=(const Vector2<T>& val) {
			x *= val.x;
			y *= val.y;
			return *this;
		}

		Vector2<T>& operator/=(const Vector2<T>& val) {
			x /= val.x;
			y /= val.y;
			return *this;
		}

//////////////////////////////////////////////////////////////////////////////////////////

		bool operator==(const Vector2<T>& other) const {
			return (std::abs(x - other.x) <= EPS) && (std::abs(y - other.y) <= EPS);
		}

//////////////////////////////////////////////////////////////////////////////////////////


		~Vector2() {}
	};

	template<class T, class U>
	Vector2<T> operator*(U lhs, const Vector2<T>& rhs) {
		return rhs * lhs;
	}

	typedef Vector2<double> Vector2d;
	using Vector2f = Vector2<float>;
	using Vector2i = Vector2<int>;
}
