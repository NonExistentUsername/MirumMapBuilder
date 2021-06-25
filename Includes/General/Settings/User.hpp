/*
 * Settings.hpp
 *
 *  Created on: 23 мар. 2021 г.
 *      Author: mayor
 */
#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

namespace Settings {
	class User
	{
	private:
		static sf::Vector2<uint16_t> windowSize;
		static sf::ContextSettings contextSettings;
		static uint32_t windowStyle;

		static double kx, ky;
	public:
		static const sf::Vector2<uint16_t> defaultWindowSize;
		static const std::string windowName;
		static const sf::Font textFont;
		static const uint16_t fontSize;

		User();

		static const sf::Vector2<uint16_t>& getWindowSize();
		static const sf::ContextSettings& getContextSettings();
		static const uint32_t getWindowStyle();

		static const double Kx();
		static const double Ky();
		static const sf::Vector2f K();

		static void changeWindowSize(sf::Vector2<uint16_t> newWindowSize);

		~User();
	};
}
