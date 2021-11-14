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
	static bool hasFocus;
public:
	static TEvent<const sf::Event&> buttonReleased;
	static TEvent<const sf::Event&> buttonPressed;
	static TEvent<const sf::Event::KeyEvent&> keyPressed;
	static TEvent<const sf::Event::MouseWheelScrollEvent&> mouseWheelScrolled;
	static TEvent<> frameEvent;

	static void processEvent(const sf::Event& event);
	static void processEvents();
};
