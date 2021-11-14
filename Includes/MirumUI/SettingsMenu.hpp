/*
 * SettingsMenu.hpp
 *
 *  Created on: 2 апр. 2021 г.
 *      Author: mayor
 */

//#include "MainMenu.hpp"
#pragma once
#include "../UI/Functions/Scale.hpp"
#include "../General/TexturesManager.hpp"
#include <vector>
#include "../UI/All.hpp"

//class MainMenu;

class SettingsMenu : public UI::Menu {
private:
	class BackButton : public UI::Button {
	private:
		void released(const sf::Event& event) override;
	public:
		BackButton();
	};

	class ChangeResolutionButtonList : public UI::ButtonList {
	private:
		void processChange(size_t id) override;
	public:
		ChangeResolutionButtonList();

//		~ChangeResolutionButtonList();
	};

	ChangeResolutionButtonList _changeResolution;
	BackButton _back;
public:
	SettingsMenu();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
