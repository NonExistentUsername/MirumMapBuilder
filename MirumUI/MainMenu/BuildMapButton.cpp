/*
 * PlayButton.cpp
 *
 *  Created on: 15 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/BuildMapMenu.hpp"
#include "../../Includes/MirumUI/MainMenu.hpp"


MainMenu::BuildMap::BuildMap(MapSize* _mapSize) {
	mapSize = _mapSize;

	canvas.height = 50;
	canvas.width = 300;

	canvas.left = 1920/2 - canvas.width/2;
	canvas.top = 300;

//	texture = TexturesManager::Button;

	text = "Build Map";
}

void MainMenu::BuildMap::released(const sf::Event& event) {
	if(!(mapSize->empty()) && canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
		UI::MenuManager::openMenu<BuildMapMenu>(mapSize->get_size());
	}
}

MainMenu::BuildMap::~BuildMap() {}
