#pragma once

#ifndef SFML_GAMESTATEMACHINE_H
#define SFML_GAMESTATEMACHINE_H

#include "GameState.h"

#include "GameStateMenu.h"
#include "GameStateGameplay.h"
#include "GameStatePaused.h"

class Game;

class GameStateMachine
{
	public:
	GameStateMachine(Game& game);
	~GameStateMachine();
	void init();
	void ChangeState(std::shared_ptr<GameState> new_state);
	void Update(float dt);
	void Render(sf::RenderWindow& window);
	void KeyPressed(const sf::Event::KeyPressed* event);
	void KeyReleased(const sf::Event::KeyReleased* event);
	void MouseButtonPressed(const sf::Event::MouseButtonPressed* event);
	void MouseButtonReleased(const sf::Event::MouseButtonReleased* event);

	private:
	std::shared_ptr<GameState> current_state;

	protected:
		Game& game;
};

#endif // SFML_GAMESTATEMACHINE_H