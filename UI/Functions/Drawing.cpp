/*
 * drawImage.cpp
 *
 *  Created on: 11 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/UI/Functions/Drawing.hpp"
#include "../../Includes/UI/Functions/Scale.hpp"

#include "../../Includes/General/Settings/User.hpp"
#include "../../Includes/General/TexturesManager.hpp"

#include <string>

void drawImage(sf::RenderTarget& target, const sf::RenderStates& states, const sf::FloatRect& _scaledCanvas, const std::shared_ptr<sf::Texture> texture) {
	if(texture.get()) {
		sf::Sprite _sprite;

		_sprite.setPosition(_scaledCanvas.left, _scaledCanvas.top);
		_sprite.setTexture(*(texture.get()));

		_sprite.setScale(sf::Vector2f(_scaledCanvas.width / (float)texture.get()->getSize().x,
									 _scaledCanvas.height / (float)texture.get()->getSize().y));

		target.draw(_sprite, states);
	}
}

void drawText(sf::RenderTarget& target, const sf::RenderStates& states, const sf::FloatRect& _scaledCanvas, const std::string& text, const sf::Color& _color) {
	if(!text.empty()) {
		static sf::Text _text;
		_text.setFont(Settings::User::textFont);
		_text.setCharacterSize(ScaleSize(Settings::User::fontSize));
		_text.setString(text);
		_text.setFillColor(_color);

		sf::Vector2f _canvasCenter = Center(_scaledCanvas);
		_text.setPosition(sf::Vector2f(
				_canvasCenter.x - _text.getLocalBounds().width / 2.,
				_canvasCenter.y - ScaleSize(Settings::User::fontSize) / 2.));

		target.draw(_text, states);
	}
}

void drawTextL(sf::RenderTarget& target, const sf::RenderStates& states, const sf::FloatRect& _scaledCanvas, const std::string& text, const sf::Color& _color) {
	if(!text.empty()) {
		static sf::Text _text;
		_text.setFont(Settings::User::textFont);
		_text.setCharacterSize(ScaleSize(Settings::User::fontSize));
		_text.setString(text);
		_text.setFillColor(_color);

		sf::Vector2f _canvasCenter = Center(_scaledCanvas);
		_text.setPosition(sf::Vector2f(
				_scaledCanvas.left,
				_canvasCenter.y - ScaleSize(Settings::User::fontSize) / 2.));

		target.draw(_text, states);
	}
}

void drawPoint(sf::RenderTarget& target, const sf::RenderStates& states, const Geometry::Vector2d& _position, float _size, const sf::Color& _color) {
	static sf::CircleShape point;
	_size *= std::min(Settings::User::Kx(), Settings::User::Ky());
	point.setRadius(_size);
	point.setPosition(_position.x * Settings::User::Kx() - _size, _position.y * Settings::User::Ky() - _size);
	point.setFillColor(_color);
	target.draw(point, states);
}

void drawLine(sf::RenderTarget& target, const sf::RenderStates& states, const sf::Vector2f& _scaledStartPoint, const sf::Vector2f& _scaledEndPoint, const sf::Color& _color) {
	sf::Vertex line[] = {
		sf::Vertex(_scaledStartPoint),
		sf::Vertex(_scaledEndPoint)
	};

	line[0].color = line[1].color = _color;

	target.draw(line, 2, sf::Lines, states);
}

void drawRectangle(sf::RenderTarget& target, const sf::RenderStates& states, const sf::FloatRect& _scaledCanvas, const sf::Color& _color) {
	sf::RectangleShape rect;

	rect.setPosition(_scaledCanvas.left, _scaledCanvas.top);
	rect.setFillColor(_color);
	rect.setSize(sf::Vector2f(_scaledCanvas.width, _scaledCanvas.height));

	target.draw(rect, states);
}
