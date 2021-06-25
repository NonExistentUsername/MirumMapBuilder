/*
 * Image.cpp
 *
 *  Created on: 11 ���. 2021 �.
 *      Author: mayor
 */

#include "../../Includes/UI/Objects/Image.hpp"

#include "../../Includes/UI/Functions/Drawing.hpp"

namespace UI {
	Image::Image() {}

	void Image::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		sf::FloatRect _scaledCanvas = Scale(canvas);
		drawImage(target, states, _scaledCanvas, texture);
	}

	Image::~Image() {}
}
