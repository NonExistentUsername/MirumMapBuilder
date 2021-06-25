/*
 * RenderFrame.cpp
 *
 *  Created on: 28 ���. 2021 �.
 *      Author: mayor
 */

#include "../Includes/General/RenderFrame.hpp"
#include "../Includes/General/GlobalVariables.hpp"
#include "../Includes/General/MenuManager.hpp"
#include "../Includes/Tools/Profile.hpp"

void renderFrame(sf::RenderWindow& window) {
    window.clear(sf::Color(255, 255, 255));

    {
//    	LOG_DURATION("RenderFrame time");
//    	window.draw(*menuGraph.get());
    	UI::MenuManager::draw(window);
    }
}
