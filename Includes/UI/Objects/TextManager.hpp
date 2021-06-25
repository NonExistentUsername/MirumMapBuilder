/*
 * TextManager.hpp
 *
 *  Created on: 25 θών. 2021 γ.
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
