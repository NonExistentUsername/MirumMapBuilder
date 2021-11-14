/*
 * LoadMapButton.cpp
 *
 *  Created on: 24 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/BuildMapMenu.hpp"
#include "../../Includes/MirumUI/MainMenu.hpp"
#include "../../Includes/General/MenuManager.hpp"

BuildMapMenu::BackButton::BackButton() {
	canvas.left = 0;
	canvas.top = 0;
	canvas.height = 54;
	canvas.width = 200;

	text = "Back";
}

void BuildMapMenu::BackButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::FloatRect _scaledCanvas = Scale(canvas);
	if(this->isPressed()) {
		_scaledCanvas.top += ScaleSize(4);
		_scaledCanvas.height -= ScaleSize(4);
		drawImage(target, states, _scaledCanvas, TexturesManager::ButtonYellowPressed);
	} else
		drawImage(target, states, _scaledCanvas, TexturesManager::ButtonYellow);
	drawText(target, states, _scaledCanvas, text, textColor);
}

void BuildMapMenu::BackButton::released(const sf::Event& event) {
	if(canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
		UI::MenuManager::openMenu<MainMenu>();
}
