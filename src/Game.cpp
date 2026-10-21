
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window), state_machine(*this)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
	animals[0] = sf::Texture{ "../Data/Images/Critter Crossing/elephant.png" };
	passports[0] = sf::Texture{ "../Data/Images/Critter Crossing/elephant passport.png" };

	animals[1] = sf::Texture{ "../Data/Images/Critter Crossing/moose.png" };
	passports[1] = sf::Texture{ "../Data/Images/Critter Crossing/moose passport.png" };

	animals[2] = sf::Texture{ "../Data/Images/Critter Crossing/penguin.png" };
	passports[2] = sf::Texture{ "../Data/Images/Critter Crossing/penguin passport.png" };

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