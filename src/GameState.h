#pragma once

#ifndef SFML_GAMESTATE_H
#define SFML_GAMESTATE_H


#include <SFML/Window/WindowBase.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>

class GameState
{
	public:
		GameState();
		~GameState();
		virtual void EnterState();
		virtual void Update(float dt);
		virtual void ExitState();
		virtual void Render(sf::RenderWindow& window);
		virtual void KeyPressed(const sf::Event::KeyPressed* event);
		virtual void KeyReleased(const sf::Event::KeyReleased* event);
		virtual void MouseButtonPressed(const sf::Event::MouseButtonPressed* event);
		virtual void MouseButtonReleased(const sf::Event::MouseButtonReleased* event);
};

#endif // SFML_GAMESTATE_H