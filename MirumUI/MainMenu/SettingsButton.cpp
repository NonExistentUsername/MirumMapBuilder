/*
 * SettingsButton.cpp
 *
 *  Created on: 11 мая 2021 г.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/MainMenu.hpp"

void MainMenu::SettingsButton::released(const sf::Event& event) {
	if(canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
		UI::MenuManager::openMenu<SettingsMenu>();
}

MainMenu::SettingsButton::SettingsButton() {
	canvas.height = 50;
	canvas.width = 200;

	canvas.left = 1920/2 - canvas.width/2;
	canvas.top = 500;

	text = "Settings";
}

MainMenu::SettingsButton::~SettingsButton() {}
