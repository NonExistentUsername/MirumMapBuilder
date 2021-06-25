/*
 * Init.cpp
 *
 *  Created on: 28 мар. 2021 г.
 *      Author: mayor
 */
#include "../Includes/General/Init.hpp"
#include "../Includes/General/MenuManager.hpp"
#include "../Includes/MirumUI/MainMenu.hpp"
#include "../Includes/General/GlobalVariables.hpp"

sf::RenderWindow createWindow() {
    const sf::Vector2<uint16_t> windowSize = Settings::User::getWindowSize();
    return sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), Settings::User::windowName, Settings::User::getWindowStyle(), Settings::User::getContextSettings());
}

void reloadWindow() {
	window.close();
    const sf::Vector2<uint16_t> windowSize = Settings::User::getWindowSize();
	window.create(sf::VideoMode(windowSize.x, windowSize.y), Settings::User::windowName, Settings::User::getWindowStyle(), Settings::User::getContextSettings());
	window.setFramerateLimit(60);
}

void init() {
	UI::MenuManager::openMenu<MainMenu>();
}
