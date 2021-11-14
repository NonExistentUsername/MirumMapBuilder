/*
 * MapEditor.cpp
 *
 *  Created on: 26 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/BuildMapMenu.hpp"
#include "../../Includes/UI/Functions/Scale.hpp"

BuildMapMenu::MapEditor::MapEditor(size_t _map_size): map_size(_map_size), map(_map_size, std::vector<cell>(_map_size)), map_position(200, 0) {
	canvas.left = 200;
	canvas.top = 0;

	canvas.height = 1080;
	canvas.width = 1420;

	EventManager::mouseWheelScrolled += MY_METHOD_HANDLER(BuildMapMenu::MapEditor::processScroll);
	EventManager::buttonPressed += MY_METHOD_HANDLER(BuildMapMenu::MapEditor::buttonPressed);
	EventManager::buttonReleased += MY_METHOD_HANDLER(BuildMapMenu::MapEditor::buttonReleased);
	EventManager::frameEvent += MY_METHOD_HANDLER(BuildMapMenu::MapEditor::update);
}

//void BuildMapMenu::MapEditor::resetPosition() {


void BuildMapMenu::MapEditor::buttonPressed(const sf::Event& event) {
	if(canvas.contains(UnScale(sf::Vector2f(sf::Mouse::getPosition(window))))) {
		if(!moving && event.mouseButton.button == sf::Mouse::Middle) {
			moving = true;
			_delta_point = get_relative_mouse_position();
		} else
		if(event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2<int> _id = get_id();

			if(_id.x != -1)
				selected_cell = sf::Vector2<size_t>(_id);
		}
	}
}

void BuildMapMenu::MapEditor::buttonReleased(const sf::Event& event) {
	moving = false;
}

void BuildMapMenu::MapEditor::processScroll(const sf::Event::MouseWheelScrollEvent& event) {
	if(canvas.contains(UnScale(sf::Vector2f(sf::Mouse::getPosition(window))))) {
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
			float delta = scale;
			scale += event.delta / 10.;
			scale = std::max<float>(scale, 1.);
			scale = std::min<float>(scale, 25.);
			delta -= scale;

			sf::Vector2f _mouse_position(get_relative_mouse_position());
			map_position = (map_position + _mouse_position * delta);
		}
	}
}

sf::Vector2f BuildMapMenu::MapEditor::get_relative_mouse_position() const {
	sf::Vector2f _mouse_position(sf::Mouse::getPosition(window));

	float k = std::min<float>(Settings::User::Kx(), Settings::User::Ky());
	_mouse_position = _mouse_position / k;
	_mouse_position -= map_position;

	return _mouse_position / scale;
}

void BuildMapMenu::MapEditor::drawCell(sf::RenderTarget& target, const sf::RenderStates &states, size_t x, size_t y) const {
	if(map[x][y].is_empty) {
		sf::RectangleShape rectangle;

		if(x % 2 == y % 2) {
			rectangle.setFillColor(sf::Color::Magenta);
		} else {
			rectangle.setFillColor(sf::Color::Yellow);
		}

		float _scaled_cell_size = ScaleSize(cell_size * scale);
		float k = std::min<float>(Settings::User::Kx(), Settings::User::Ky());
		sf::Vector2f _scaled_map_position(map_position.x + x * cell_size * scale, map_position.y + y * cell_size * scale);
		_scaled_map_position = _scaled_map_position * k;

		rectangle.setPosition(_scaled_map_position);
		rectangle.setSize(sf::Vector2f{_scaled_cell_size, _scaled_cell_size});

		target.draw(rectangle, states);
	} else {
		sf::Sprite sprite;

		float _scaled_cell_size = ScaleSize(scale);
		float k = std::min<float>(Settings::User::Kx(), Settings::User::Ky());
		sf::Vector2f _scaled_map_position(map_position.x + x * cell_size * scale, map_position.y + y * cell_size * scale);
		_scaled_map_position = _scaled_map_position * k;

		sprite.setPosition(_scaled_map_position);
		sprite.setTexture(*(TexturesManager::Room_Builder[map[x][y].type].get()));

		sf::Vector2u texture_size = TexturesManager::Room_Builder[map[x][y].type].get()->getSize() / (uint32_t)16;

		sf::IntRect texture_rect;

		texture_rect.top = map[x][y].id / texture_size.x;
		texture_rect.left = 16 * (map[x][y].id - texture_rect.top * texture_size.x);
		texture_rect.top *= 16;

		texture_rect.width = 16;
		texture_rect.height = 16;

		sprite.setTextureRect(texture_rect);
		sprite.setScale(k * scale, k * scale);

		target.draw(sprite);
	}
}

sf::Vector2<int> BuildMapMenu::MapEditor::get_id() const {
	sf::Vector2f _mouse_pos(get_relative_mouse_position());

	if(_mouse_pos.x < 0 || _mouse_pos.x > cell_size * (float)map_size || _mouse_pos.y < 0 || _mouse_pos.y > cell_size * (float)map_size)
		return {-1, -1};

	return {(int)std::floor(_mouse_pos.x / cell_size), (int)std::floor(_mouse_pos.y / cell_size)};
}

void BuildMapMenu::MapEditor::drawOutline(sf::RenderTarget& target, const sf::RenderStates &states, size_t x, size_t y) const {
	sf::RectangleShape rectangle;

	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(5);
	rectangle.setFillColor(sf::Color::Transparent);

	float _scaled_cell_size = ScaleSize(cell_size * scale);
	float k = std::min<float>(Settings::User::Kx(), Settings::User::Ky());
	sf::Vector2f _scaled_map_position(map_position.x + x * cell_size * scale, map_position.y + y * cell_size * scale);
	_scaled_map_position = _scaled_map_position * k;

	rectangle.setPosition(_scaled_map_position);
	rectangle.setSize(sf::Vector2f{_scaled_cell_size, _scaled_cell_size});

	target.draw(rectangle, states);
}

void BuildMapMenu::MapEditor::resetScale() {
	scale = 1.;
	map_position.x = 200;
	map_position.y = 0;
}

void BuildMapMenu::MapEditor::update() {
	if(moving) {
		map_position -= _delta_point - get_relative_mouse_position();
	}
}

void BuildMapMenu::MapEditor::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for(size_t x = 0; x < map_size; ++x)
		for(size_t y = 0; y < map_size; ++y)
			drawCell(target, states, x, y);

	drawOutline(target, states, selected_cell.x, selected_cell.y);
}

sf::Vector2<size_t> BuildMapMenu::MapEditor::get_selected_cell_position() const {
	return selected_cell;
}

const BuildMapMenu::MapEditor::cell& BuildMapMenu::MapEditor::get_selected_cell_texture() const {
	return map[selected_cell.x][selected_cell.y];
}

BuildMapMenu::MapEditor::cell& BuildMapMenu::MapEditor::get_selected_cell_texture() {
	return map[selected_cell.x][selected_cell.y];
}


BuildMapMenu::MapEditor::~MapEditor() {
	EventManager::mouseWheelScrolled -= MY_METHOD_HANDLER(BuildMapMenu::MapEditor::processScroll);
	EventManager::buttonPressed -= MY_METHOD_HANDLER(BuildMapMenu::MapEditor::buttonPressed);
	EventManager::buttonReleased -= MY_METHOD_HANDLER(BuildMapMenu::MapEditor::buttonReleased);
	EventManager::frameEvent -= MY_METHOD_HANDLER(BuildMapMenu::MapEditor::update);
}
