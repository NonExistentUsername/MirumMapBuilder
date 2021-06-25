/*
 * User.cpp
 *
 *  Created on: 19 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/General/Settings/User.hpp"
#include <iostream>

#include "../../Includes/General/Init.hpp"

namespace Settings {

	sf::ContextSettings User::contextSettings = []() {
		sf::ContextSettings context_settings;
		context_settings.antialiasingLevel = 8;
		return context_settings;
	}();

	uint32_t User::windowStyle = sf::Style::Titlebar | sf::Style::Close;

	const sf::Vector2<uint16_t> User::defaultWindowSize(1920, 1080);

	sf::Vector2<uint16_t> User::windowSize(1280, 800);

	const uint16_t User::fontSize = 20;

	const std::string User::windowName = "Mirum";

	double User::kx = (double)windowSize.x / (double)defaultWindowSize.x;
	double User::ky = (double)windowSize.y / (double)defaultWindowSize.y;

	const sf::Font User::textFont = []() {
		sf::Font Font;

		if (!Font.loadFromFile("fonts/PressStart2P-Regular.ttf"))
			std::exit(EXIT_FAILURE);

		return Font;
	}();

	User::User() {}

	const sf::Vector2<uint16_t>& User::getWindowSize() {
		return windowSize;
	}

	const sf::ContextSettings& User::getContextSettings() {
		return contextSettings;
	}

	const uint32_t User::getWindowStyle() {
		return windowStyle;
	}

	const double User::Kx() {
		return kx;
	}

	const double User::Ky() {
		return ky;
	}

	const sf::Vector2f User::K() {
		return sf::Vector2f(kx, ky);
	}

	void User::changeWindowSize(sf::Vector2<uint16_t> newWindowSize) {
		windowSize = newWindowSize;
		kx = (double)windowSize.x / (double)defaultWindowSize.x;
		ky = (double)windowSize.y / (double)defaultWindowSize.y;
		reloadWindow();
	}

	User::~User() {}
}

