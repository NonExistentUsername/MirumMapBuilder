/*
 * Menu.hpp
 *
 *  Created on: 28 мар. 2021 г.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

namespace UI {
	class Menu : public sf::Drawable {
	public:
		Menu();

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

		virtual ~Menu();
	};
}
