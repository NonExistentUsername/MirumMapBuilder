/*
 * MenuManager.cpp
 *
 *  Created on: 2 ���. 2021 �.
 *      Author: mayor
 */

#include "../Includes/General/MenuManager.hpp"

namespace UI {
	std::unique_ptr<UI::Menu> MenuManager::currentMenu = nullptr;

	void MenuManager::draw(sf::RenderWindow& window) {
		if(currentMenu.get())
			window.draw(*currentMenu.get());
	}
}
