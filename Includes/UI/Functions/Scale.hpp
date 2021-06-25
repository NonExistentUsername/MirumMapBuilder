/*
 * Scale.hpp
 *
 *  Created on: 29 мар. 2021 г.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "../../General/Settings/User.hpp"
#include "../../Geometry/Vector2.hpp"

template<class T>
inline sf::FloatRect Scale(const sf::Rect<T>& rect) {
	sf::FloatRect newRect(rect);

	newRect.left = rect.left * Settings::User::Kx();
	newRect.top = rect.top* Settings::User::Ky();

	newRect.width = rect.width * Settings::User::Kx();
	newRect.height = rect.height * Settings::User::Ky();

	return newRect;
}

template<class T>
inline sf::Vector2<T> Scale(const sf::Vector2<T>& vec) {
	return sf::Vector2<T>(vec.x * Settings::User::Kx(), vec.y * Settings::User::Ky());
}

template<class T>
inline Geometry::Vector2<T> Scale(const Geometry::Vector2<T>& vec) {
	return Geometry::Vector2<T>(vec.x * Settings::User::Kx(), vec.y * Settings::User::Ky());
}

template<class T>
inline sf::Vector2<T> UnScale(const sf::Vector2<T>& vec) {
	return sf::Vector2<T>(vec.x / Settings::User::Kx(), vec.y / Settings::User::Ky());
}


template<class T>
inline T ScaleSize(T size) {
	return size * std::min(Settings::User::Kx(), Settings::User::Ky());
}

template<class T>
inline sf::Vector2<T> Center(const sf::Rect<T>& rect) {
	return {rect.left + rect.width / 2, rect.top + rect.height / 2};
}

//template<class T>
//inline sf::Vector2<T> Left(const sf::Rect<T>& rect) {
//	return {rect.left, rect.top + rect.height / 2};
//}

template<class T>
inline sf::Vector2<T> LocalCenter(const sf::Rect<T>& rect) {
	return {rect.width / 2, rect.height / 2};
}

template<class T>
inline sf::Vector2<T> Factors(const sf::Vector2<T> sizes, const sf::Vector2<T> sizes_to_scale) {
	return sizes_to_scale / sizes;
}
