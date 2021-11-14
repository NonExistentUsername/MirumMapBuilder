/*
 * ResetMapScaleButton.cpp
 *
 *  Created on: 27 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/BuildMapMenu.hpp"

void BuildMapMenu::ResetMapScaleButton::released(const sf::Event& event) {
	map_editor->resetScale();
}

BuildMapMenu::ResetMapScaleButton::ResetMapScaleButton(MapEditor* _map_editor) {
	canvas.left = 0;
	canvas.top = 50;

	canvas.height = 50;
	canvas.width = 200;

	text = "Reset Pos";

	map_editor = _map_editor;
}

