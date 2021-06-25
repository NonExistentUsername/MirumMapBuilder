/*
 * MainMenu.hpp
 *
 *  Created on: 29 мар. 2021 г.
 *      Author: mayor
 */

#pragma once
#include "../UI/Objects/Menu.hpp"
#include "../UI/Objects/Button.hpp"
#include "../UI/Objects/InputText.hpp"
#include "../UI/Objects/TextManager.hpp"
#include "../UI/Functions/Scale.hpp"
#include "../General/TexturesManager.hpp"
#include "../General/MenuManager.hpp"
#include "SettingsMenu.hpp"

#include <iostream>

class MainMenu : public UI::Menu {
private:
	class ExitButton : public UI::Button {
	private:
		void released(const sf::Event& event) override;
	public:
		ExitButton();

		~ExitButton();
	};

	class SettingsButton : public UI::Button {
	private:
		void released(const sf::Event& event) override;
	public:
		SettingsButton();

		~SettingsButton();
	};

	class MapSize;

	class BuildMap : public UI::Button {
	private:
		MapSize* mapSize;

		void released(const sf::Event& event) override;
	public:
		BuildMap(MapSize* _mapSize);

		~BuildMap();
	};

	class MapSize : public UI::InputText {
	private:
		void processEnteredText(const sf::Event::KeyEvent& key) override;

		friend BuildMap;
	public:
		MapSize(UI::TextManager* _textManager);

		bool empty() const;
		size_t get_size() const;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		~MapSize();
	};

	UI::TextManager _textManager;
	ExitButton exit;
	SettingsButton settingsMenu;
	MapSize _mapSize;
	BuildMap _buildMap;
public:
	MainMenu();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	~MainMenu();
};
