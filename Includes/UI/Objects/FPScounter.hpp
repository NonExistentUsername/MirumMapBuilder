/*
 * FPScounter.hpp
 *
 *  Created on: 19 θών. 2021 γ.
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
	class FPS : public sf::Drawable {
	protected:
		sf::IntRect canvas{0, 0, 250, 50};
		std::chrono::steady_clock::time_point _start;
	public:
		FPS();

		void start();
	    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		~FPS();
	};
}
