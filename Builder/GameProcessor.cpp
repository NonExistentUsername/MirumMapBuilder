/*
 * GameProcessor.cpp
 *
 *  Created on: 24 θών. 2021 γ.
 *      Author: mayor
 */

#include "../Includes/Builder/BuilderProcessor.hpp"
#include "../Includes/General/Settings/Game.hpp"

namespace Builder {
	void Processor::drawRays(sf::RenderTarget& target, const sf::RenderStates& states) const {
		std::vector<Vector2d> points = map.get()->get_light_points(map.get()->user.get()->position);

		sf::Vector2f _scaled_user_position(map.get()->user.get()->position.x,
										   map.get()->user.get()->position.y);
		_scaled_user_position = Scale(_scaled_user_position);

		for(const auto& point : points) {
			drawLine(target, states, _scaled_user_position,
					 Scale(sf::Vector2f(point.x, point.y)), sf::Color::Yellow);

			//////////////////////////////////////////////////////
			///
			///		drawPoint is so slow..
			///
			//////////////////////////////////////////////////////
			drawPoint(target, states, point, 10, sf::Color::Yellow);
		}

		for(size_t i = 1; i < points.size(); ++i) {
			drawLine(target, states,
					Scale(sf::Vector2f(points[i - 1].x, points[i - 1].y)),
					Scale(sf::Vector2f(points[i].x, points[i].y)), sf::Color::Yellow);
		}
		drawLine(target, states,
				Scale(sf::Vector2f(points[points.size() - 1].x, points[points.size() - 1].y)),
				Scale(sf::Vector2f(points[0].x, points[0].y)), sf::Color::Yellow);
	}

	void Processor::drawUserRay(sf::RenderTarget& target, const sf::RenderStates& states) const {
		sf::Vector2f _mouse_position = UnScale(sf::Vector2f(sf::Mouse::getPosition(window)));
		Rayd ray(map.get()->user.get()->position, Vector2d(_mouse_position.x, _mouse_position.y) - map.get()->user.get()->position);

		Vector2d intersection = map.get()->get_ray_intersection(ray);

		drawPoint(target, states, intersection, 15, sf::Color::Yellow);

		drawLine(target, states,
				Scale(sf::Vector2f(ray.start.x, ray.start.y)),
				Scale(sf::Vector2f(_mouse_position.x, _mouse_position.y)), sf::Color::Yellow);
	}

	void Processor::processPlayerMove() {
		static std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

		auto duration = std::chrono::steady_clock::now() - start;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			map.get()->user.get()->moveX(-Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			map.get()->user.get()->moveX(Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			map.get()->user.get()->moveY(-Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			map.get()->user.get()->moveY(Settings::Game::playerSpeed * std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000000.);
		}

		start = std::chrono::steady_clock::now();
	}

	Processor::Processor() : map(new Map()) {
		EventManager::frameEvent += MY_METHOD_HANDLER(Processor::processPlayerMove);
	}

	void Processor::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(*(map.get()), states);

		drawRays(target, states);
	}

	Processor::~Processor() {
		EventManager::frameEvent -= MY_METHOD_HANDLER(Processor::processPlayerMove);
	}
}
