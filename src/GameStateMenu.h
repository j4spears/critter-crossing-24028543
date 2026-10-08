#pragma once

#ifndef SFML_GAMESTATEMENU_H
#define SFML_GAMESTATEMENU_H

#include "GameState.h"

class GameStateMenu : public GameState
{
	public:
	GameStateMenu();
	~GameStateMenu();
	void EnterState() override;
	void Update(float dt) override;
	void ExitState() override;
	void Render(sf::RenderWindow& window) override;
	void KeyPressed(sf::Event event) override;
	void KeyReleased(sf::Event event) override;
	void MouseButtonPressed(sf::Event event) override;
	void MouseButtonReleased(sf::Event event) override;
};

#endif // SFML_GAMESTATEMENU_H