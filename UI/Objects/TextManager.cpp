/*
 * TextManager.cpp
 *
 *  Created on: 25 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/UI/Objects/TextManager.hpp"
#include "../../Includes/General/EventManager.hpp"

namespace UI {
	TextManager::TextManager() {
		EventManager::textEntered += MY_METHOD_HANDLER(TextManager::processTextEntered);
		EventManager::frameEvent += MY_METHOD_HANDLER(TextManager::processEsc);
	}

	void TextManager::processEsc() {
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			inputText = nullptr;
	}

	void TextManager::processTextEntered(const sf::Event::KeyEvent& key) {
		if(inputText)
			inputText->processEnteredText(key);
	}


	void TextManager::set(InputText* _inputText) {
		inputText = _inputText;
	}

	TextManager::~TextManager() {
		EventManager::textEntered -= MY_METHOD_HANDLER(TextManager::processTextEntered);
		EventManager::frameEvent -= MY_METHOD_HANDLER(TextManager::processEsc);
	}
}
