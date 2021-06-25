/*
 * InputText.cpp
 *
 *  Created on: 24 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/UI/Objects/InputText.hpp"
#include "../../Includes/UI/Objects/TextManager.hpp"
#include "../../Includes/UI/Functions/Drawing.hpp"
#include "../../Includes/UI/Functions/Scale.hpp"

namespace UI {

	void InputText::buttonReleased(const sf::Event& event) {
		if(canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
			textManager->set(this);
		}
	}

	InputText::InputText(TextManager* _textManager) {
		textManager = _textManager;
//		EventManager::textEntered += MY_METHOD_HANDLER(InputText::processEnteredText);
		EventManager::buttonReleased += MY_METHOD_HANDLER(InputText::buttonReleased);
	}

	void InputText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		drawText(target, states, Scale(canvas), text, textColor);
	}

	InputText::~InputText() {
//		EventManager::textEntered -= MY_METHOD_HANDLER(InputText::processEnteredText);
		EventManager::buttonReleased -= MY_METHOD_HANDLER(InputText::buttonReleased);
	}
}


