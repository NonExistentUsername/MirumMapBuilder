/*
 * FPScounter.cpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/UI/Objects/FPScounter.hpp"
#include <SFML/Graphics.hpp>
#include <string>

namespace UI {
	FPS::FPS() {}

	void FPS::start() {
		_start = std::chrono::steady_clock::now();
	}

	void FPS::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        auto dur = std::chrono::steady_clock::now() - _start;
    	sf::Text _text;
		_text.setFont(Settings::User::textFont);
		_text.setCharacterSize(ScaleSize(Settings::User::fontSize));
		_text.setString(std::to_string(std::chrono::duration_cast<std::chrono::microseconds>(dur).count()/1000.) + " ms.");
		_text.setFillColor(sf::Color::Black);

		sf::Vector2f _canvasCenter = Center(Scale(sf::FloatRect(0, 0, 300, 50)));
		_text.setPosition(sf::Vector2f(
    				_canvasCenter.x - _text.getLocalBounds().width / 2.,
    				_canvasCenter.y - ScaleSize(Settings::User::fontSize) / 2.));

		target.draw(_text, states);
	}

	FPS::~FPS() {}
}

