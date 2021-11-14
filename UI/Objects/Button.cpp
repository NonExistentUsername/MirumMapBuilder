/*
 * Button.cpp
 *
 *  Created on: 3 мая 2021 г.
 *      Author: mayor
 */

#include "../../Includes/UI/Objects/Button.hpp"
#include "../../Includes/General/EventManager.hpp"
#include "../../Includes/General/Settings/USer.hpp"

#include "../../Includes/UI/Functions/Drawing.hpp"

#include <iostream>

namespace UI {
	Button::Button() {
		EventManager::buttonPressed += MY_METHOD_HANDLER(Button::pressed);
		EventManager::buttonReleased += MY_METHOD_HANDLER(Button::_released);
	}

	void Button::pressed(const sf::Event& event) {
		if(canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
			is_pressed = true;
		}
	}

	void Button::_released(const sf::Event& event) {
		if(is_pressed && canvas.contains(UnScale(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			released(event);
		is_pressed = false;
	}

	bool Button::isPressed() const {
		return is_pressed;
	}

	void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		sf::FloatRect _scaledCanvas = Scale(canvas);
		if(is_pressed) {
			_scaledCanvas.top += ScaleSize(4);
			_scaledCanvas.height -= ScaleSize(4);
			drawImage(target, states, _scaledCanvas, TexturesManager::ButtonPressed);
		} else
			drawImage(target, states, _scaledCanvas, TexturesManager::Button);
		drawText(target, states, _scaledCanvas, text, textColor);
	}

    sf::IntRect Button::getCanvas() const {
    	return canvas;
    }

    std::string Button::getText() const {
    	return text;
    }

    void Button::setCanvas(sf::IntRect canvas) {
    	this->canvas = std::move(canvas);
    }

    void Button::setText(std::string text) {
    	this->text = std::move(text);
    }

	Button::~Button() {
		EventManager::buttonPressed -= MY_METHOD_HANDLER(Button::pressed);
		EventManager::buttonReleased -= MY_METHOD_HANDLER(Button::_released);
	}
}
