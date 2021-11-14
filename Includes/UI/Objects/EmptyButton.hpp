/*
 * EmptyButton.hpp
 *
 *  Created on: 4 мая 2021 г.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "../../General/GlobalVariables.hpp"
#include "../../General/TexturesManager.hpp"
#include "../Functions/Scale.hpp"

#include <iostream>
#include <string>

namespace UI {
	class EmptyButton : public sf::Drawable {
	protected:
		virtual void buttonPressed(const sf::Event& event);
		virtual void buttonReleased(const sf::Event& event);

		EmptyButton();
	public:
	    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	    virtual ~EmptyButton();
	};
};

