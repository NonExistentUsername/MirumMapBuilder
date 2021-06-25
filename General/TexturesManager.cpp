/*
 * Textures.cpp
 *
 *  Created on: 1 апр. 2021 г.
 *      Author: mayor
 */

#include "../Includes/General/TexturesManager.hpp"

std::shared_ptr<sf::Texture> loadTexture(const std::string& path) {
	std::shared_ptr<sf::Texture> texture = std::shared_ptr<sf::Texture>(new sf::Texture());

	if(!texture.get()->loadFromFile(path))
		std::exit(EXIT_FAILURE);

	return texture;
}

const std::shared_ptr<sf::Texture> TexturesManager::Button = loadTexture("textures/blue_button02.png");
const std::shared_ptr<sf::Texture> TexturesManager::ButtonPressed = loadTexture("textures/blue_button03.png");

const std::shared_ptr<sf::Texture> TexturesManager::ButtonRed = loadTexture("textures/red_button02.png");
const std::shared_ptr<sf::Texture> TexturesManager::ButtonRedPressed = loadTexture("textures/red_button03.png");

const std::shared_ptr<sf::Texture> TexturesManager::ButtonYellow = loadTexture("textures/yellow_button02.png");
const std::shared_ptr<sf::Texture> TexturesManager::ButtonYellowPressed = loadTexture("textures/yellow_button03.png");

const std::shared_ptr<sf::Texture> TexturesManager::ButtonGreen = loadTexture("textures/green_button02.png");
const std::shared_ptr<sf::Texture> TexturesManager::ButtonGreenPressed = loadTexture("textures/green_button03.png");
