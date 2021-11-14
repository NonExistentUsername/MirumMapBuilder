/*
 * SinglePlayerMenu.cpp
 *
 *  Created on: 15 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/BuildMapMenu.hpp"

BuildMapMenu::BuildMapMenu(size_t _map_size): _map_editor(_map_size), _reset_map_scale(&_map_editor), _map_cell_editor(&_map_editor) {}

void BuildMapMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
//	target.draw(processor, states);
	target.draw(_map_editor, states);

	sf::RectangleShape rectangle;
	rectangle.setPosition(0, 0);
	rectangle.setSize(Scale(sf::Vector2f{200, 1080}));
	rectangle.setFillColor(sf::Color(220, 220, 220, 255));

	target.draw(rectangle, states);
	rectangle.setPosition(Scale(sf::Vector2f{1620, 0}));
	rectangle.setSize(Scale(sf::Vector2f{300, 1080}));

	target.draw(rectangle, states);

	target.draw(_back, states);
	target.draw(_reset_map_scale, states);
	target.draw(_map_cell_editor, states);
}
