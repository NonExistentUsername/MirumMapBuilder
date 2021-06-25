/*
 * EmptyButton.cpp
 *
 *  Created on: 11 мая 2021 г.
 *      Author: mayor
 */

#include "../../Includes/UI/Objects/EmptyButton.hpp"
#include "../../Includes/General/Settings/User.hpp"
#include "../../Includes/General/EventManager.hpp"

#include <iostream>

namespace UI {
	EmptyButton::EmptyButton() {
		EventManager::buttonPressed += MY_METHOD_HANDLER(EmptyButton::buttonPressed);
		EventManager::buttonUnPressed += MY_METHOD_HANDLER(EmptyButton::buttonUnPressed);
		EventManager::buttonReleased += MY_METHOD_HANDLER(EmptyButton::buttonReleased);
	}

	void EmptyButton::buttonPressed(const sf::Event& event) {}
	void EmptyButton::buttonUnPressed(const sf::Event& event) {}
	void EmptyButton::buttonReleased(const sf::Event& event) {}

	EmptyButton::~EmptyButton() {
		EventManager::buttonPressed -= MY_METHOD_HANDLER(EmptyButton::buttonPressed);
		EventManager::buttonUnPressed -= MY_METHOD_HANDLER(EmptyButton::buttonUnPressed);
		EventManager::buttonReleased -= MY_METHOD_HANDLER(EmptyButton::buttonReleased);
	}
}
