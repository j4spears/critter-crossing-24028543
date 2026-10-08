
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL)); //seeds random number generator with the current time
}

Game::~Game()
{

}


bool Game::init()
{
	game_state_machine.init(std::make_shared<GameStateMenu>());
  return true;
}


void Game::update(float dt)
{
	game_state_machine.Update(dt);
}


void Game::render()
{

}


void Game::mouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
	game_state_machine.MouseButtonPressed(event);

}


void Game::mouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
	game_state_machine.MouseButtonReleased(event);
}


void Game::keyPressed(const sf::Event::KeyPressed* event)
{
	game_state_machine.KeyPressed(event);
}


void Game::keyReleased(const sf::Event::KeyReleased* event)
{
	game_state_machine.KeyReleased(event);
}