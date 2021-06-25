/*
 * MenuManager.hpp
 *
 *  Created on: 2 апр. 2021 г.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
//#include<stdarg.h>
#include "../UI/Objects/Menu.hpp"

namespace UI {
	class MenuManager {
	private:
		static std::unique_ptr<UI::Menu> currentMenu;
	public:

		template<class T, class... Args>
		static void openMenu(Args... args) {
			currentMenu.reset(new T(args...));
		}

		static void draw(sf::RenderWindow& window);
	};
}
