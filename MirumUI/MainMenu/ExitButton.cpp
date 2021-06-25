/*
 * ExitButton.cpp
 *
 *  Created on: 11 мая 2021 г.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/MainMenu.hpp"

MainMenu::ExitButton::ExitButton() {
	canvas.height = 50;
	canvas.width = 200;

	canvas.left = 1920/2 - canvas.width/2;
	canvas.top = 600;

	texture = TexturesManager::Button;

	text = "Exit";
}

void MainMenu::ExitButton::released(const sf::Event& event) {
	if(canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
		std::exit(EXIT_SUCCESS);
	}
}

MainMenu::ExitButton::~ExitButton() {}
