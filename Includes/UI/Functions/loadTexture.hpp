/*
 * loadTexture.hpp
 *
 *  Created on: 3 ��� 2021 �.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

sf::Texture loadTexture(std::string path) {
	sf::Texture texture;
	if(!texture.loadFromFile(path))
		std::exit(EXIT_FAILURE);
	return texture;
}
