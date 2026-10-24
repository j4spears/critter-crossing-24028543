#include "GameStateMenu.h"
#include "Game.h"

GameStateMenu::GameStateMenu(Game& game) : GameState(game){}

GameStateMenu::~GameStateMenu(){}

void GameStateMenu::InitState(){}

void GameStateMenu::EnterState(){}

void GameStateMenu::Update(float dt){}

void GameStateMenu::ExitState(){}

void GameStateMenu::Render(sf::RenderWindow& window){}

void GameStateMenu::KeyPressed(const sf::Event::KeyPressed* event){}

void GameStateMenu::KeyReleased(const sf::Event::KeyReleased* event){}

void GameStateMenu::MouseButtonPressed(const sf::Event::MouseButtonPressed* event){}

void GameStateMenu::MouseButtonReleased(const sf::Event::MouseButtonReleased* event){}
