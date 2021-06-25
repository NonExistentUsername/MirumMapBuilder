/*
 * ChangeResolution.cpp
 *
 *  Created on: 11 мая 2021 г.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/SettingsMenu.hpp"

class ResolutionsManager {
private:
	static std::vector<std::pair<uint16_t, uint16_t>> resolutions;
public:
	static std::vector<std::string> buildStrings() {
		std::vector<std::string> strings(resolutions.size());

		size_t i = 0;
		for(const auto& resolution : resolutions) {
			strings[i] = std::to_string(resolution.first) + 'x' + std::to_string(resolution.second);
			++i;
		}

		return strings;
	}

	static void changeResolutionById(size_t id) {
		Settings::User::changeWindowSize(sf::Vector2<uint16_t>(resolutions[id].first, resolutions[id].second));
	}
};


std::vector<std::pair<uint16_t, uint16_t>> ResolutionsManager::resolutions = {
		{1920, 1080},
		{1600, 900},
		{1280, 720},
		{800, 600}
};

SettingsMenu::ChangeResolutionButtonList::ChangeResolutionButtonList() {
	canvas.height = 50;
	canvas.width = 100;
	canvas.top = 200;
	canvas.left = 1920/2 - 50;
	text = std::to_string(Settings::User::getWindowSize().x) + 'x' + std::to_string(Settings::User::getWindowSize().y);

	strings = ResolutionsManager::buildStrings();
}

void SettingsMenu::ChangeResolutionButtonList::processChange(size_t id) {
	text = strings[id];
	ResolutionsManager::changeResolutionById(id);
}
