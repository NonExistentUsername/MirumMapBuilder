/*
 * GameProcessor.hpp
 *
 *  Created on: 15 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "../../Includes/UI/Functions/Drawing.hpp"
#include "../Geometry/Functions.hpp"
#include "../Geometry/Ray.hpp"

#include "../Tools/Profile.hpp"

#include <string>
#include <iostream>
#include <memory>
#include "../Builder/Map.hpp"
#include "../Builder/Player.hpp"

using namespace Geometry;

namespace Builder {
	class Processor : public sf::Drawable {
	private:
		std::unique_ptr<Map> map;

		void drawRays(sf::RenderTarget& target, const sf::RenderStates& states) const;
		void drawUserRay(sf::RenderTarget& target, const sf::RenderStates& states) const;

		void processPlayerMove();
	public:
		Processor();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		~Processor();
	};
}
