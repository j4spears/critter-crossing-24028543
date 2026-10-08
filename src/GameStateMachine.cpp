#include "GameStateMachine.h"

GameStateMachine::GameStateMachine()
{
}

GameStateMachine::~GameStateMachine()
{
}

void GameStateMachine::init(std::shared_ptr<GameState> initial_state)
{
	current_state = initial_state;
	current_state->EnterState();
}

void GameStateMachine::ChangeState(std::shared_ptr<GameState> new_state)
{
	current_state->ExitState();
	current_state = new_state;
	current_state->EnterState();
}

void GameStateMachine::Update(float dt)
{
	current_state->Update(dt);
}

void GameStateMachine::Render(sf::RenderWindow& window)
{
	current_state->Render(window);
}

void GameStateMachine::KeyPressed(const sf::Event::KeyPressed* event)
{
	current_state->KeyPressed(event);
}

void GameStateMachine::KeyReleased(const sf::Event::KeyReleased* event)
{
	current_state->KeyReleased(event);
}

void GameStateMachine::MouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
	current_state->MouseButtonPressed(event);
}

void GameStateMachine::MouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
	current_state->MouseButtonReleased(event);
}