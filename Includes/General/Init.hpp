/*
 * Init.hpp
 *
 *  Created on: 23 ���. 2021 �.
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

