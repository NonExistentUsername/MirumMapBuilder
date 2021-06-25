/*
 * Map.cpp
 *
 *  Created on: 23 θών. 2021 γ.
 *      Author: mayor
 */

#include "../Includes/Builder/Map.hpp"

#include "../Includes/Geometry/Ray.hpp"
#include "../Includes/Geometry/Functions.hpp"
#include "../Includes/General/Settings/Game.hpp"
#include "../Includes/Tools/Profile.hpp"

namespace Builder {
	void Map::load_map() {
		segments.push_back(Segmentd(0, 0, 1920, 0)); 		 // 0
		segments.push_back(Segmentd(1920, 0, 1920, 1080));	 // 1
		segments.push_back(Segmentd(1920, 1080, 0, 1080));	 // 2
		segments.push_back(Segmentd(0, 1080, 0, 0)); 		 // 3

		segments.push_back(Segmentd{100, 100, 150, 300}); //4
		segments.push_back(Segmentd{300, 100, 200, 800}); //5
		segments.push_back(Segmentd{900, 900, 700, 1000}); //6
		segments.push_back(Segmentd{500, 500, 900, 500}); //7
		segments.push_back(Segmentd{500, 500, 500, 900}); //8
		segments.push_back(Segmentd{900, 900, 500, 900}); //9
		segments.push_back(Segmentd{900, 900, 900, 500}); //10
	}

	Map::Map() : user(new Player()) {
		load_map();
	}

	void Map::drawSegments(sf::RenderTarget& target, const sf::RenderStates& states) const {
		for(const Segmentd& segment : segments) {
			drawLine(target, states, Scale(sf::Vector2f(segment.start.x, segment.start.y)),
									 Scale(sf::Vector2f(segment.end.x, segment.end.y)), sf::Color::Magenta);
		}
	}

	void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(*(user.get()), states);

		drawSegments(target, states);
	}

	Vector2d Map::get_ray_intersection(const Rayd& ray) const {
		Vector2d point(ray.start);
		double min_length = INFINITY;
		for(const auto& segment : segments)
			if(ray.intersect(segment)) {
				Vector2d intersection_point = ray.get_intersection(segment);

				double length = get_length(ray.start, intersection_point);
				if(length <= min_length) {
					min_length = length;
					point = intersection_point;
				}
			}

		return point;
	}

	std::vector<Vector2d> Map::get_light_points(const Vector2d& light_source) const {
		std::vector<Vector2<double>> light_points(4 * segments.size());

		size_t id = 0;
		const double angle = 0.0001;
		for(const auto& segment : segments)
		{
			Ray<double> new_ray(light_source, segment.start - light_source);

			new_ray.direction.rotate(degree_to_radian(angle));
			light_points[id++] = get_ray_intersection(new_ray);

			new_ray.direction.rotate(degree_to_radian(-2 * angle));
			light_points[id++] = get_ray_intersection(new_ray);

			new_ray = Ray<double>(light_source, segment.end - light_source);
			new_ray.direction.rotate(degree_to_radian(angle));
			light_points[id++] = get_ray_intersection(new_ray);

			new_ray.direction.rotate(degree_to_radian(-2 * angle));
			light_points[id++] = get_ray_intersection(new_ray);
		}

		std::sort(begin(light_points), end(light_points), [&](const auto& lhs, const auto& rhs) {
			return atan2(lhs.x - light_source.x, lhs.y - light_source.y) < atan2(rhs.x - light_source.x, rhs.y - light_source.y);
		});

		return light_points;
	}

	Map::~Map() {}
}
