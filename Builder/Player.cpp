/*
 * Player.cpp
 *
 *  Created on: 16 θών. 2021 γ.
 *      Author: mayor
 */

#include "../Includes/Builder/Player.hpp"

#include "../Includes/General/EventManager.hpp"
#include "../Includes/General/Settings/Game.hpp"
#include "../Includes/UI/Functions/Scale.hpp"

namespace Builder {
	Player::Player(): position(1920/2, 1080/2) {}

	void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		static sf::CircleShape image;

		float _scaledSize = ScaleSize(30);
		Point _scaledPos = Scale(position);
		_scaledPos.x -= _scaledSize;
		_scaledPos.y -= _scaledSize;

		image.setPosition(_scaledPos.x, _scaledPos.y);
		image.setFillColor(sf::Color::Black);
		image.setRadius(ScaleSize(30));

		target.draw(image);
	}

	void Player::move(const Point& vector) {
		position += vector;
	}

	void Player::moveX(double value) {
		position.x += value;
	}

	void Player::moveY(double value) {
		position.y += value;
	}

	Player::~Player() {}
}
