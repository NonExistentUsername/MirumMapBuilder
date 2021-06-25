/*
 * ButtonList.hpp
 *
 *  Created on: 9 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "../../General/GlobalVariables.hpp"
#include "../../General/TexturesManager.hpp"
#include "../Functions/Scale.hpp"
#include "Button.hpp"
#include "ImageWithText.hpp"
#include "EmptyButton.hpp"

#include <vector>
//#include <string>

namespace UI {
	class ButtonList : public EmptyButton {
	protected:
		sf::IntRect canvas;
		std::shared_ptr<sf::Texture> texture;
		std::string text;
		sf::Color textColor;

		std::vector<std::string> strings;
		bool enabled = false;

		virtual void buttonReleased(const sf::Event& event);

		virtual void processChange(size_t id);

		ButtonList();
	public:
	    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	    virtual ~ButtonList();
	};
};
