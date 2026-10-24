#include "GameState.h"

#include "Game.h"


GameState::GameState(Game& game) : game(game){}

GameState::~GameState(){}

void GameState::InitState(){}

void GameState::EnterState(){}

void GameState::Update(float dt){}

void GameState::ExitState(){}

void GameState::Render(sf::RenderWindow& window){}

void GameState::KeyPressed(const sf::Event::KeyPressed* event){}

void GameState::KeyReleased(const sf::Event::KeyReleased* event){}

void GameState::MouseButtonPressed(const sf::Event::MouseButtonPressed* event){}

void GameState::MouseButtonReleased(const sf::Event::MouseButtonReleased* event){}