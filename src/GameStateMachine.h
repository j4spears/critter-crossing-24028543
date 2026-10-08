#pragma once

#ifndef SFML_GAMESTATEMACHINE_H
#define SFML_GAMESTATEMACHINE_H



#include "GameState.h"

class GameStateMachine
{
	public:
	GameStateMachine();
	~GameStateMachine();
	void init(std::shared_ptr<GameState> initial_state);
	void ChangeState(std::shared_ptr<GameState> new_state);
	void Update(float dt);
	void Render(sf::RenderWindow& window);
	void KeyPressed(sf::Event event);
	void KeyReleased(sf::Event event);
	void MouseButtonPressed(sf::Event event);
	void MouseButtonReleased(sf::Event event);

	private:
	std::shared_ptr<GameState> current_state;
};

#endif // SFML_GAMESTATEMACHINE_H