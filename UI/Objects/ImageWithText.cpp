/*
 * ImageWithText.cpp
 *
 *  Created on: 11 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/UI/Objects/ImageWithText.hpp"

#include "../../Includes/UI/Functions/Drawing.hpp"

namespace UI {
	ImageWithText::ImageWithText() {}

	void ImageWithText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		sf::FloatRect _scaledCanvas = Scale(canvas);
		drawImage(target, states, _scaledCanvas, texture);
		drawText(target, states, _scaledCanvas, text, textColor);
	}

	ImageWithText::~ImageWithText() {}
}

