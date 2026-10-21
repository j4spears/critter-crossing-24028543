#include "GameStateGameplay.h"
#include "Game.h"


GameStateGameplay::GameStateGameplay(Game& game) : GameState(game) {}

GameStateGameplay::~GameStateGameplay(){}

void GameStateGameplay::EnterState()
{
}

void GameStateGameplay::Update(float dt)
{
}

void GameStateGameplay::ExitState()
{
}

void GameStateGameplay::Render(sf::RenderWindow& window)
{
}

void GameStateGameplay::KeyPressed(const sf::Event::KeyPressed* event)
{
}

void GameStateGameplay::KeyReleased(const sf::Event::KeyReleased* event)
{
}

void GameStateGameplay::MouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
}

void GameStateGameplay::MouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
}
