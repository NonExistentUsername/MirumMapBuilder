/*
 * SettingsMenu.cpp
 *
 *  Created on: 11 ��� 2021 �.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/SettingsMenu.hpp"

SettingsMenu::SettingsMenu() {}

void SettingsMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_back, states);
	target.draw(_changeResolution, states);
}
