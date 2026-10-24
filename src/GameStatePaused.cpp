#include "GameStatePaused.h"
#include "Game.h"

GameStatePaused::GameStatePaused(Game& game) : GameState(game) {}

GameStatePaused::~GameStatePaused(){}

void GameStatePaused::InitState(){}

void GameStatePaused::EnterState(){}

void GameStatePaused::Update(float dt){}

void GameStatePaused::ExitState(){}

void GameStatePaused::Render(sf::RenderWindow& window){}

void GameStatePaused::KeyPressed(const sf::Event::KeyPressed* event){}

void GameStatePaused::KeyReleased(const sf::Event::KeyReleased* event){}

void GameStatePaused::MouseButtonPressed(const sf::Event::MouseButtonPressed* event){}

void GameStatePaused::MouseButtonReleased(const sf::Event::MouseButtonReleased* event){}
