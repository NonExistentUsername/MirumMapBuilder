/*
 * BackButton.cpp
 *
 *  Created on: 11 мая 2021 г.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/SettingsMenu.hpp"
#include "../../Includes/MirumUI/MainMenu.hpp"

void SettingsMenu::BackButton::released(const sf::Event& event) {
	if(canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
		UI::MenuManager::openMenu<MainMenu>();
}

SettingsMenu::BackButton::BackButton() {
	canvas.height = 50;
	canvas.width = 200;

	canvas.left = 25;
	canvas.top = 25;

	texture = TexturesManager::Button;

	text = "Back";
}
