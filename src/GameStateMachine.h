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
	void KeyPressed(const sf::Event::KeyPressed* event);
	void KeyReleased(const sf::Event::KeyReleased* event);
	void MouseButtonPressed(const sf::Event::MouseButtonPressed* event);
	void MouseButtonReleased(const sf::Event::MouseButtonReleased* event);

	private:
	std::shared_ptr<GameState> current_state;
};

#endif // SFML_GAMESTATEMACHINE_H