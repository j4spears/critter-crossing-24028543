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
		virtual void KeyPressed(sf::Event event);
		virtual void KeyReleased(sf::Event event);
		virtual void MouseButtonPressed(sf::Event event);
		virtual void MouseButtonReleased(sf::Event event);
};

#endif // SFML_GAMESTATE_H