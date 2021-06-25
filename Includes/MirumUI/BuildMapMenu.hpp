/*
 * SinglePlayer.hpp
 *
 *  Created on: 15 θών. 2021 γ.
 *      Author: mayor
 */


#pragma once
#include "../UI/Functions/Scale.hpp"
#include "../General/TexturesManager.hpp"
#include "../General/MenuManager.hpp"
#include "MainMenu.hpp"
#include <vector>

#include "../Builder/BuilderProcessor.hpp"
#include "../UI/All.hpp"

//class MainMenu;

class SinglePlayerMenu : public UI::Menu {
private:
//	Builder::Processor processor;

	class BackButton : public UI::Button {
	private:
		void released(const sf::Event& event) override;
	public:
		BackButton();
	};

	const size_t map_size;
	const size_t sprite_size = 16;
	BackButton _back;
public:
	SinglePlayerMenu(size_t _map_size);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
