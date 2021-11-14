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
//#include "../Geometry/Vector2.hpp"
#include "MainMenu.hpp"
#include <vector>

#include "../Builder/BuilderProcessor.hpp"
#include "../UI/All.hpp"

//class MainMenu;

class BuildMapMenu : public UI::Menu {
private:
//	Builder::Processor processor;

	class BackButton : public UI::Button {
	private:
		void released(const sf::Event& event) override;
	public:
		BackButton();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};

	class MapEditor : public sf::Drawable {	public:
		struct cell {
			bool is_empty = true;

			ROOMS type;
			uint32_t id;
		};
	protected:
//		friend class MapCellEditor;

		sf::Vector2f _delta_point;
		bool moving = false;
		void buttonPressed(const sf::Event& event);
		void buttonReleased(const sf::Event& event);
		void update();

		const size_t map_size;
		const float cell_size = 16;
		sf::Vector2<size_t> selected_cell{0, 0};

		std::vector<std::vector<cell>> map;

		sf::FloatRect canvas;

		float scale = 1.;
		sf::Vector2f map_position;

		void processScroll(const sf::Event::MouseWheelScrollEvent& event);

		sf::Vector2f get_relative_mouse_position() const;

		sf::Vector2<int> get_id() const;

		void drawOutline(sf::RenderTarget& target, const sf::RenderStates &states, size_t x, size_t y) const;
		void drawCell(sf::RenderTarget& target, const sf::RenderStates &states, size_t x, size_t y) const;

	public:
		MapEditor(size_t _map_size);

		void resetScale();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		sf::Vector2<size_t> get_selected_cell_position() const;
		const cell& get_selected_cell_texture() const;
		cell& get_selected_cell_texture();

		~MapEditor();
	};

	class MapCellEditor : public sf::Drawable {
	private:
		MapEditor& map_editor;

		sf::FloatRect canvas;
		sf::FloatRect image_canvas;

		bool is_enabled_texture_editor = false;
		float scrolled = 0.;

		class SetType : public UI::ButtonList {
		private:

		friend class ResetMapScaleButton;
		public:
			SetType();

			size_t get_type() const;

			~SetType();
		};

		SetType _setType;

		void buttonPressed(const sf::Event& event);
		void buttonReleased(const sf::Event& event);
		void processScroll(const sf::Event::MouseWheelScrollEvent& event);

		sf::Sprite get_sprite_by_id(std::shared_ptr<sf::Texture> texture, const size_t id) const;

		void drawSelector(sf::RenderTarget& target, const sf::RenderStates &states) const;
		void drawTexture(sf::RenderTarget& target, const sf::RenderStates &states) const;
	public:
		MapCellEditor(MapEditor* _map_editor);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		~MapCellEditor();
	};

	class ResetMapScaleButton : public UI::Button {
	private:
		MapEditor* map_editor;

		void released(const sf::Event& event) override;
	public:
		ResetMapScaleButton(MapEditor* _map_editor);
	};

	MapEditor _map_editor;
	BackButton _back;
	ResetMapScaleButton _reset_map_scale;
	MapCellEditor _map_cell_editor;
public:
	BuildMapMenu(size_t _map_size);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
