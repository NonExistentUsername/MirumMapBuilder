/*
 * EventManager.cpp
 *
 *  Created on: 2 мая 2021 г.
 *      Author: mayor
 */

#include "../Includes/General/EventManager.hpp"
#include "../Includes/General/GlobalVariables.hpp"
#include <iostream>

bool EventManager::hasFocus = true;

TEvent<const sf::Event&> EventManager::buttonReleased;
TEvent<const sf::Event&> EventManager::buttonPressed;
TEvent<const sf::Event::KeyEvent&> EventManager::keyPressed;
TEvent<const sf::Event::MouseWheelScrollEvent&> EventManager::mouseWheelScrolled;
TEvent<> EventManager::frameEvent;

void EventManager::processEvents() {
	sf::Event event;
    while(window.pollEvent(event)) {
        if	(event.type == sf::Event::Closed)
            window.close();

        processEvent(event);
    }
    if(hasFocus)
    	frameEvent();
}

void EventManager::processEvent(const sf::Event& event) {
    if(event.type == sf::Event::GainedFocus)
		hasFocus = true;
	else
	if(event.type == sf::Event::LostFocus) {
		hasFocus = false;
		return;
	} else
    if(!hasFocus)
    	return;

    switch(event.type) {
    case sf::Event::MouseButtonReleased:
		buttonReleased(event);
	break;
	case sf::Event::MouseButtonPressed:
		buttonPressed(event);
	break;
	case sf::Event::KeyPressed:
		keyPressed(event.key);
	break;
	case sf::Event::MouseWheelScrolled:
		mouseWheelScrolled(event.mouseWheelScroll);
	break;
//	case sf::Event::Mouse
	default:
	break;
	}
}
