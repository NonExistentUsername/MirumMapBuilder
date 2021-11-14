/*
 * MapCellEditor.cpp
 *
 *  Created on: 27 θών. 2021 γ.
 *      Author: mayor
 */

#include "../../Includes/MirumUI/BuildMapMenu.hpp"


void BuildMapMenu::MapCellEditor::buttonPressed(const sf::Event& event) {
}

void BuildMapMenu::MapCellEditor::buttonReleased(const sf::Event& event) {
	if(is_enabled_texture_editor) {
		size_t type = _setType.get_type();

		std::shared_ptr<sf::Texture> texture = TexturesManager::Room_Builder[type];
		sf::Vector2u texture_size = texture.get()->getSize() / (uint32_t)16;
		size_t _count = texture_size.x * texture_size.y;

		sf::FloatRect image_rect = image_canvas;
		image_rect.top += scrolled;
//		image_rect = Scale(image_rect);

		const sf::Vector2f _mouse_pos(UnScale(sf::Vector2f(sf::Mouse::getPosition(window))));

		for(size_t id = 0; id < _count; ++id) {
			if(image_rect.contains(_mouse_pos)) {
//				std::cerr << "id founded = " << id << std::endl;

				map_editor.get_selected_cell_texture().type = (ROOMS)_setType.get_type();
				map_editor.get_selected_cell_texture().id = id;
				map_editor.get_selected_cell_texture().is_empty = false;

				break;
			}

			image_rect.top += image_rect.height;
		}

		is_enabled_texture_editor = false;
	} else
	if(image_canvas.contains(UnScale(sf::Vector2f(sf::Mouse::getPosition(window))))) {
		if(!is_enabled_texture_editor) {
			is_enabled_texture_editor = true;

			scrolled = 0;
		}
	}
}


void BuildMapMenu::MapCellEditor::processScroll(const sf::Event::MouseWheelScrollEvent& event) {
	if(canvas.contains(UnScale(sf::Vector2f(sf::Mouse::getPosition(window))))) {
		if(is_enabled_texture_editor) {
			scrolled += event.delta * 20;
//			std::cerr << "scrolled = " << scrolled << std::endl;
		}
	}
}

sf::Sprite BuildMapMenu::MapCellEditor::get_sprite_by_id(std::shared_ptr<sf::Texture> texture, const size_t id) const {
	sf::Sprite result;

	sf::Vector2u texture_size = texture.get()->getSize() / (uint32_t)16;

	sf::IntRect texture_rect;

	texture_rect.top = id / texture_size.x;
	texture_rect.left = 16 * (id - texture_rect.top * texture_size.x);
	texture_rect.top *= 16;

	texture_rect.width = 16;
	texture_rect.height = 16;

//	result.set
//	sf::?

	result.setTexture(*(texture.get()), true);
	result.setTextureRect(texture_rect);

//	result.set

	return result;
}

void BuildMapMenu::MapCellEditor::drawSelector(sf::RenderTarget& target, const sf::RenderStates &states) const {
	size_t type = _setType.get_type();

	std::shared_ptr<sf::Texture> texture = TexturesManager::Room_Builder[type];
	sf::Vector2u texture_size = texture.get()->getSize() / (uint32_t)16;
	size_t _count = texture_size.x * texture_size.y;

	sf::FloatRect image_rect = image_canvas;
	image_rect.top += scrolled;
	image_rect = Scale(image_rect);

//	sf::Sprite sprite;

//	sprite.setTexture(*(texture.get()));
	{
//		LOG_DURATION("drawSelector Forchik");
		for(size_t id = 0; id < _count; ++id) {
			sf::Sprite sprite = get_sprite_by_id(texture, id);

			sprite.setPosition(image_rect.left, image_rect.top);

			sf::FloatRect g = sprite.getGlobalBounds();
			sprite.setScale(image_rect.width / g.width, image_rect.height / g.height);

			target.draw(sprite, states);

			image_rect.top += image_rect.height;
		}
	}
}

void BuildMapMenu::MapCellEditor::drawTexture(sf::RenderTarget& target, const sf::RenderStates &states) const {
	const BuildMapMenu::MapEditor::cell& _cell = map_editor.get_selected_cell_texture();
	const sf::Vector2<size_t> _cell_position = map_editor.get_selected_cell_position();

	if(_cell.is_empty) {
		sf::RectangleShape rectangle;

		if(_cell_position.x % 2 == _cell_position.y % 2) {
			rectangle.setFillColor(sf::Color::Magenta);
		} else {
			rectangle.setFillColor(sf::Color::Yellow);
		}

		rectangle.setPosition(Scale(sf::Vector2f{image_canvas.left, image_canvas.top}));
		rectangle.setSize(Scale(sf::Vector2f{image_canvas.width, image_canvas.height}));

		target.draw(rectangle, states);
	} else {
		sf::Sprite sprite;

		sprite.setPosition(Scale(sf::Vector2f{image_canvas.left, image_canvas.top}));
		sprite.setTexture(*(TexturesManager::Room_Builder[_cell.type].get()));

		sf::Vector2u texture_size = TexturesManager::Room_Builder[_cell.type].get()->getSize() / (uint32_t)16;

		sf::IntRect texture_rect;

		texture_rect.top = _cell.id / texture_size.x;
		texture_rect.left = 16 * (_cell.id - texture_rect.top * texture_size.x);
		texture_rect.top *= 16;

		texture_rect.width = 16;
		texture_rect.height = 16;

		sprite.setTextureRect(texture_rect);

		sf::Vector2f scaled_size = Scale(sf::Vector2f{image_canvas.width, image_canvas.height});
		sprite.setScale(scaled_size.x / 16., scaled_size.y / 16.);

		target.draw(sprite);
	}
}

BuildMapMenu::MapCellEditor::MapCellEditor(MapEditor* _map_editor): map_editor(*_map_editor) {
	canvas.top = 0;
	canvas.left = 1620;

	canvas.height = 1080;
	canvas.width = 300;

	image_canvas.height = 200;
	image_canvas.width = 200;
	image_canvas.top = 50;
	image_canvas.left = 1670;

	EventManager::buttonReleased += MY_METHOD_HANDLER(BuildMapMenu::MapCellEditor::buttonReleased);
	EventManager::mouseWheelScrolled += MY_METHOD_HANDLER(BuildMapMenu::MapCellEditor::processScroll);
}

void BuildMapMenu::MapCellEditor::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	drawTexture(target, states);

	if(is_enabled_texture_editor) {
		drawSelector(target, states);
	} else {
		sf::FloatRect text_canvas;
		text_canvas.width = 250;
		text_canvas.height = 54;
		text_canvas.top = 350;
		text_canvas.left = 1670;

		drawText(target, states, Scale(text_canvas), "Type:", sf::Color::Black);
		target.draw(_setType, states);
	}
}

BuildMapMenu::MapCellEditor::~MapCellEditor() {
	EventManager::buttonReleased -= MY_METHOD_HANDLER(BuildMapMenu::MapCellEditor::buttonReleased);
	EventManager::mouseWheelScrolled -= MY_METHOD_HANDLER(BuildMapMenu::MapCellEditor::processScroll);
}
