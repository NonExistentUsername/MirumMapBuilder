/*
 * SinglePlayerMenu.cpp
 *
 *  Created on: 15 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/BuildMapMenu.hpp"

SinglePlayerMenu::SinglePlayerMenu(size_t _map_size): map_size(_map_size) {}

void SinglePlayerMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
//	target.draw(processor, states);
	target.draw(_back, states);
}
