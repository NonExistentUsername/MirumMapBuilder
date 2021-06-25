/*
 * drawImage.hpp
 *
 *  Created on: 11 θών. 2021 γ.
 *      Author: mayor
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "../../Geometry/Vector2.hpp"
#include <memory>

void drawImage(sf::RenderTarget& target, const sf::RenderStates& states, const sf::FloatRect& _scaledCanvas, const std::shared_ptr<sf::Texture> texture);

void drawText(sf::RenderTarget& target, const sf::RenderStates& states, const sf::FloatRect& _scaledCanvas, const std::string& text, const sf::Color& _color);
void drawTextL(sf::RenderTarget& target, const sf::RenderStates& states, const sf::FloatRect& _scaledCanvas, const std::string& text, const sf::Color& _color);

void drawPoint(sf::RenderTarget& target, const sf::RenderStates& states, const Geometry::Vector2d& _position, const float _size, const sf::Color& _color); // SUPER PUPER

void drawLine(sf::RenderTarget& target, const sf::RenderStates& states, const sf::Vector2f& _scaledStartPoint, const sf::Vector2f& _scaledEndPoint, const sf::Color& _color);

void drawRectangle(sf::RenderTarget& target, const sf::RenderStates& states, const sf::FloatRect& _scaledCanvas, const sf::Color& _color);
