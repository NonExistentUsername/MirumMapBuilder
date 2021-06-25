/*
 * TextManager.hpp
 *
 *  Created on: 25 ���. 2021 �.
 *      Author: mayor
 */

#pragma once

#include "InputText.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

namespace UI {
	class InputText;

	class TextManager {
	private:
		InputText* inputText = nullptr;

		void processEsc();
		void processTextEntered(const sf::Event::KeyEvent& key);
	protected:
		void set(InputText* _inputText);

		friend class InputText;
	public:
		TextManager();

		~TextManager();
	};
}
