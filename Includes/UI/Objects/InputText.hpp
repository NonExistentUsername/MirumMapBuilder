/*
 * InputText.hpp
 *
 *  Created on: 24 ���. 2021 �.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>

namespace UI {
	class TextManager;

	class InputText : public sf::Drawable {
	protected:
		sf::IntRect canvas;
		sf::Color textColor;
		std::string text;
		TextManager* textManager;

		void buttonReleased(const sf::Event& event);
		virtual void processEnteredText(const sf::Event::KeyEvent& key) = 0;

		friend class TextManager;
	public:
		InputText(TextManager* _textManager);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		virtual ~InputText();
	};
}
