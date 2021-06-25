/*
 * Image.hpp
 *
 *  Created on: 11 θών. 2021 γ.
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
	class Image : public sf::Drawable {
	protected:
		sf::IntRect canvas;
		std::shared_ptr<sf::Texture> texture;
	public:
		Image();

	    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	    virtual ~Image();
	};
}
