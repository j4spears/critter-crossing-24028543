#include "GameStateMenu.h"

GameStateMenu::GameStateMenu()
{
}

GameStateMenu::~GameStateMenu()
{
}

void GameStateMenu::EnterState()
{
}

void GameStateMenu::Update(float dt)
{
}

void GameStateMenu::ExitState()
{
}

void GameStateMenu::Render(sf::RenderWindow& window)
{
	window.draw(temp_sprite);
}

void GameStateMenu::KeyPressed(const sf::Event::KeyPressed* event)
{
}

void GameStateMenu::KeyReleased(const sf::Event::KeyReleased* event)
{
}

void GameStateMenu::MouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
}

void GameStateMenu::MouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
}
