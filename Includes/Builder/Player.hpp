/*
 * Player.hpp
 *
 *  Created on: 16 ���. 2021 �.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "../Geometry/Vector2.hpp"

#include <string>
#include <iostream>
#include <chrono>

namespace Builder {
	class Player : public sf::Drawable {
	private:
		using Point = Geometry::Vector2<double>;

		Point position;

		friend class Processor;
		friend class Map;
	public:
		Player();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		void move(const Point& vector);
		void moveX(double value);
		void moveY(double value);

		~Player();
	};
}
