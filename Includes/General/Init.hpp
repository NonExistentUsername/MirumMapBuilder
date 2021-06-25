/*
 * Init.hpp
 *
 *  Created on: 23 мар. 2021 г.
 *      Author: mayor
 */

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//#include "../UI/UI.hpp"
#include <memory>
#include "Settings/User.hpp"

sf::RenderWindow createWindow();
void reloadWindow();

void init();

