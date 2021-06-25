/*
 * ButtonList.cpp
 *
 *  Created on: 9 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/UI/Objects/ButtonList.hpp"
#include "../../Includes/UI/Functions/Drawing.hpp"

namespace UI {
	ButtonList::ButtonList() {}

	void ButtonList::buttonReleased(const sf::Event& event) {
		if(enabled) {
			enabled = false;

			sf::FloatRect _scaledCanvas = Scale(canvas);
			for(size_t id = 0; id < strings.size(); ++id) {
				_scaledCanvas.top += _scaledCanvas.height;
				if(_scaledCanvas.contains(event.mouseButton.x, event.mouseButton.y)) {
					processChange(id);
				}
			}

		} else {
			if(Scale(canvas).contains(event.mouseButton.x, event.mouseButton.y))
				enabled = true;
		}
	}

	void ButtonList::processChange(size_t id) {
		text = strings[id];
	}

	void ButtonList::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		sf::FloatRect _scaledCanvas = Scale(canvas);
		drawImage(target, states, _scaledCanvas, texture);
		drawText(target, states, _scaledCanvas, text, textColor);

		if(enabled) {
			for(const auto& str : strings) {
				_scaledCanvas.top += _scaledCanvas.height;
				drawImage(target, states, _scaledCanvas, texture);
				drawText(target, states, _scaledCanvas, str, textColor);
			}
		}
	}

	ButtonList::~ButtonList() {}
}
