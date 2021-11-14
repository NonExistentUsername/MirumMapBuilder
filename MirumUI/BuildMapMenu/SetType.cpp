/*
 * SetType.cpp
 *
 *  Created on: 27 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/BuildMapMenu.hpp"

BuildMapMenu::MapCellEditor::SetType::SetType() {
	canvas.top = 400;
	canvas.left = 1670;

	canvas.height = 54;
	canvas.width = 250;

	strings = {"0", "1", "2", "3", "4", "5", "6", "7", "8"};
	text = "0";
}


size_t BuildMapMenu::MapCellEditor::SetType::get_type() const {
	size_t _type = 0;
	for(char c : text) {
		_type *= 10;
		_type += c - '0';
	}
	return _type;
}

BuildMapMenu::MapCellEditor::SetType::~SetType() {

}

