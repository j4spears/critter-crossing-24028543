#pragma once

#ifndef SFML_GAMESTATEGAMEPLAY_H
#define SFML_GAMESTATEGAMEPLAY_H



#include "GameState.h"

class GameStateGameplay : public GameState
{
	public:
	GameStateGameplay();
	~GameStateGameplay();
	void EnterState() override;
	void Update(float dt) override;
	void ExitState() override;
	void Render(sf::RenderWindow& window) override;
	void KeyPressed(sf::Event event) override;
	void KeyReleased(sf::Event event) override;
	void MouseButtonPressed(sf::Event event) override;
	void MouseButtonReleased(sf::Event event) override;
};

#endif // SFML_GAMESTATEGAMEPLAY_H