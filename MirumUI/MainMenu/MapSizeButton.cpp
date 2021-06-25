/*
 * MapSize.cpp
 *
 *  Created on: 25 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/MainMenu.hpp"
#include "../../Includes/UI/Functions/Drawing.hpp"

MainMenu::MapSize::MapSize(UI::TextManager* _textManager): UI::InputText(_textManager) {
	canvas.left = 200;
	canvas.top = 200;

	canvas.height = 50;
	canvas.width = 450;

	text = "16";
}

MainMenu::MapSize::~MapSize() {}

void MainMenu::MapSize::processEnteredText(const sf::Event::KeyEvent& key) {
	if(text.size() == 0) {
		if(sf::Keyboard::Num1 <= key.code && key.code <= sf::Keyboard::Num9 && text.size() < 3)
			text += static_cast<char>(key.code - sf::Keyboard::Num0 + '0');
	} else
	if(sf::Keyboard::Num0 <= key.code && key.code <= sf::Keyboard::Num9 && text.size() < 3)
		text += static_cast<char>(key.code - sf::Keyboard::Num0 + '0');
	else
	if(sf::Keyboard::Backspace == key.code)
		text.pop_back();
}

bool MainMenu::MapSize::empty() const {
	return text.empty();
}

size_t MainMenu::MapSize::get_size() const {
	size_t _size = 0;
	for(char c : text) {
		_size *= 10;
		_size += c - '0';
	}
	return _size;
}

void MainMenu::MapSize::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	std::string _text;
	if(text.size() > 0)
		_text = "Map size: " + text + " x "+ text;
	else
		_text = "Map size: 0 x 0";
	sf::FloatRect _scaledCanvas = Scale(canvas);
	drawRectangle(target, states, _scaledCanvas, sf::Color::Yellow);
	drawTextL(target, states, _scaledCanvas, _text, textColor);
	_scaledCanvas.top -= ScaleSize(52);
	drawTextL(target, states, _scaledCanvas, "Sprite size: 16 x 16", textColor);
}
