/*
 * Textures.hpp
 *
 *  Created on: 1 апр. 2021 г.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class TexturesManager {
private:
public:
	static const std::shared_ptr<sf::Texture> Button;
	static const std::shared_ptr<sf::Texture> ButtonPressed;

	static const std::shared_ptr<sf::Texture> ButtonRed;
	static const std::shared_ptr<sf::Texture> ButtonRedPressed;

	static const std::shared_ptr<sf::Texture> ButtonYellow;
	static const std::shared_ptr<sf::Texture> ButtonYellowPressed;

	static const std::shared_ptr<sf::Texture> ButtonGreen;
	static const std::shared_ptr<sf::Texture> ButtonGreenPressed;
};
