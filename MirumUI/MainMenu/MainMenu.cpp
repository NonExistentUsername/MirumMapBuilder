/*
 * MainMenu.cpp
 *
 *  Created on: 3 мая 2021 г.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/MainMenu.hpp"

MainMenu::MainMenu(): _mapSize(&_textManager), _buildMap(&_mapSize) {}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(exit, states);
	target.draw(settingsMenu, states);
	target.draw(_buildMap, states);
	target.draw(_mapSize, states);
}

MainMenu::~MainMenu() {}
