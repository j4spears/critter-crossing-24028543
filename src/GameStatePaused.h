#pragma once

#ifndef SFML_GAMESTATEPAUSED_H
#define SFML_GAMESTATEPAUSED_H


#include "GameState.h"

class GameStatePaused : public GameState
{
	public:
	GameStatePaused();
	~GameStatePaused();
	void EnterState() override;
	void Update(float dt) override;
	void ExitState() override;
	void Render(sf::RenderWindow& window) override;
	void KeyPressed(sf::Event event) override;
	void KeyReleased(sf::Event event) override;
	void MouseButtonPressed(sf::Event event) override;
	void MouseButtonReleased(sf::Event event) override;
};

#endif // SFML_GAMESTATEPAUSED_H