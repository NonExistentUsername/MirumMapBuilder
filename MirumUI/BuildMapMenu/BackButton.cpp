/*
 * LoadMapButton.cpp
 *
 *  Created on: 24 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/BuildMapMenu.hpp"
#include "../../Includes/MirumUI/MainMenu.hpp"
#include "../../Includes/General/MenuManager.hpp"

SinglePlayerMenu::BackButton::BackButton() {
	canvas.left = 0;
	canvas.top = 0;
	canvas.height = 54;
	canvas.width = 150;

	text = "Back";
}


void SinglePlayerMenu::BackButton::released(const sf::Event& event) {
	if(canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
		UI::MenuManager::openMenu<MainMenu>();
}
