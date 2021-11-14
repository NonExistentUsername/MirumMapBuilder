/*
 * Textures.cpp
 *
 *  Created on: 1 апр. 2021 г.
 *      Author: mayor
 */

#include "../Includes/General/TexturesManager.hpp"
#include <iostream>

std::shared_ptr<sf::Texture> loadTexture(const std::string& path) {
	std::shared_ptr<sf::Texture> texture = std::shared_ptr<sf::Texture>(new sf::Texture());

	if(!texture.get()->loadFromFile(path))
		std::exit(EXIT_FAILURE);

	return texture;
}

const std::shared_ptr<sf::Texture> TexturesManager::Button = loadTexture("textures/blue_button02.png");
const std::shared_ptr<sf::Texture> TexturesManager::ButtonPressed = loadTexture("textures/blue_button03.png");

const std::shared_ptr<sf::Texture> TexturesManager::ButtonRed = loadTexture("textures/red_button02.png");
const std::shared_ptr<sf::Texture> TexturesManager::ButtonRedPressed = loadTexture("textures/red_button03.png");

const std::shared_ptr<sf::Texture> TexturesManager::ButtonYellow = loadTexture("textures/yellow_button02.png");
const std::shared_ptr<sf::Texture> TexturesManager::ButtonYellowPressed = loadTexture("textures/yellow_button03.png");

const std::shared_ptr<sf::Texture> TexturesManager::ButtonGreen = loadTexture("textures/green_button02.png");
const std::shared_ptr<sf::Texture> TexturesManager::ButtonGreenPressed = loadTexture("textures/green_button03.png");

/*
 *
 *
enum ROOMS {
	_3D_WALLS,
	ARCHED_ENTRYWAYS,
	BASEBOARDS,
	BORDERS,
	FLOOR_CONNECTORS,
	FLOOR_PATHS,
	FLOOR_SHADOWS,
	FLOORS,
	BUILDER_WALLS,
};
 */

const std::vector<std::shared_ptr<sf::Texture>> TexturesManager::Room_Builder = []() {
	std::vector<std::shared_ptr<sf::Texture>> _room_builder(9);

	_room_builder[ROOMS::_3D_WALLS] = loadTexture("textures/Room_Builder/Room_Builder_3d_walls_16x16.png");
	_room_builder[ROOMS::ARCHED_ENTRYWAYS] = loadTexture("textures/Room_Builder/Room_Builder_Arched_Entryways_16x16.png");
	_room_builder[ROOMS::BASEBOARDS] = loadTexture("textures/Room_Builder/Room_Builder_Baseboards_16x16.png");
	_room_builder[ROOMS::BORDERS] = loadTexture("textures/Room_Builder/Room_Builder_borders_16x16.png");
	_room_builder[ROOMS::FLOOR_CONNECTORS] = loadTexture("textures/Room_Builder/Room_Builder_Floor_Connectors_16x16.png");
	_room_builder[ROOMS::FLOOR_PATHS] = loadTexture("textures/Room_Builder/Room_Builder_Floor_Paths_16x16.png");
	_room_builder[ROOMS::FLOOR_SHADOWS] = loadTexture("textures/Room_Builder/Room_Builder_Floor_Shadows_16x16.png");
	_room_builder[ROOMS::FLOORS] = loadTexture("textures/Room_Builder/Room_Builder_Floors_16x16.png");
	_room_builder[ROOMS::BUILDER_WALLS] = loadTexture("textures/Room_Builder/Room_Builder_Walls_16x16.png");

	return _room_builder;
}();
//const std::shared_ptr<sf::Texture> TexturesManager::Room_Builder[9] = loadRoomBuilder();
