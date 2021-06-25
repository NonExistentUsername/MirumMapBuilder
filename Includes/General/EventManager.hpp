/*
 * EventManager.hpp
 *
 *  Created on: 5 апр. 2021 г.
 *      Author: mayor
 */
#pragma once
#include <SFML/Graphics.hpp>
#include "../Tools/EventHandler.hpp"

#include <iostream>

class EventManager {
private:
	//sf::Event lastEvent;
public:
	static TEvent<const sf::Event&> buttonReleased;
	static TEvent<const sf::Event&> buttonPressed;
	static TEvent<const sf::Event&> buttonUnPressed;
	static TEvent<const sf::Event::KeyEvent&> textEntered;
	static TEvent<> frameEvent;

	static void processEvent(const sf::Event& event);
};
