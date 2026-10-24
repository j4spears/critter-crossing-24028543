
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window) : window(game_window), state_machine(*this)
{
  srand(time(NULL));
}

Game::~Game()
{
}

bool Game::init()
{

	state_machine.init();
  return true;
}

void Game::update(float dt)
{
	state_machine.Update(dt);
}

void Game::render()
{
	state_machine.Render(window);
}

void Game::keyPressed(const sf::Event::KeyPressed* event)
{
	state_machine.KeyPressed(event);
}

void Game::keyReleased(const sf::Event::KeyReleased* event)
{
	state_machine.KeyReleased(event);
}

void Game::mouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
	state_machine.MouseButtonPressed(event);

}

void Game::mouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
	state_machine.MouseButtonReleased(event);
}

sf::Vector2f Game::getMousePositionf()
{
	sf::Vector2i mouse_position = sf::Mouse::getPosition(getWindow());
	sf::Vector2f mouse_positionf = static_cast<sf::Vector2f>(mouse_position);
	return mouse_positionf;
}

sf::RenderWindow& Game::getWindow()
{
	return window;
}
