/*
 * ButtonClass.hpp
 *
 *  Created on: 26 мар. 2021 г.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "../../General/GlobalVariables.hpp"
#include "../../General/TexturesManager.hpp"
#include "../Functions/Scale.hpp"

#include <iostream>
#include <string>

namespace UI {
	class Button : public sf::Drawable {
	protected:
		sf::IntRect canvas;
		std::shared_ptr<sf::Texture> texture = TexturesManager::Button;
		std::string text;
		sf::Color textColor = sf::Color(255, 255, 255);

		virtual void pressed(const sf::Event& event);
		virtual void unPressed(const sf::Event& event);
		virtual void released(const sf::Event& event);

		Button();
	public:
	    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	    sf::IntRect getCanvas() const;
	    std::string getText() const;

	    void setCanvas(sf::IntRect canvas);
	    void setText(std::string text);

	    virtual ~Button();
	};
};

