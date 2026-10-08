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
	void KeyPressed(const sf::Event::KeyPressed* event) override;
	void KeyReleased(const sf::Event::KeyReleased* event) override;
	void MouseButtonPressed(const sf::Event::MouseButtonPressed* event) override;
	void MouseButtonReleased(const sf::Event::MouseButtonReleased* event) override;
};

#endif // SFML_GAMESTATEPAUSED_H