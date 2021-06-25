/*
 * EventManager.cpp
 *
 *  Created on: 2 ��� 2021 �.
 *      Author: mayor
 */

#include "../Includes/General/EventManager.hpp"
#include <iostream>

TEvent<const sf::Event&> EventManager::buttonReleased;
TEvent<const sf::Event&> EventManager::buttonPressed;
TEvent<const sf::Event&> EventManager::buttonUnPressed;
TEvent<const sf::Event::KeyEvent&> EventManager::textEntered;
TEvent<> EventManager::frameEvent;

void EventManager::processEvent(const sf::Event& event) {
	switch(event.type) {
	case sf::Event::MouseButtonReleased:
		buttonUnPressed(event);
		buttonReleased(event);
	break;
	case sf::Event::MouseButtonPressed:
		buttonPressed(event);
	break;
	case sf::Event::KeyPressed:
		textEntered(event.key);
	break;
	default:
	break;
	}
}
