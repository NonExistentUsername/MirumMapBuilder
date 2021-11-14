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
	private:
		void pressed(const sf::Event& event);
		void _released(const sf::Event& event);

		bool is_pressed = false;
	protected:
		sf::IntRect canvas;
		std::string text;
		sf::Color textColor = sf::Color(255, 255, 255);

		bool isPressed() const;
		virtual void released(const sf::Event& event) = 0;

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

