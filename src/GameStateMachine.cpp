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

void GameStateMachine::KeyPressed(sf::Event event)
{
	current_state->KeyPressed(event);
}

void GameStateMachine::KeyReleased(sf::Event event)
{
	current_state->KeyReleased(event);
}

void GameStateMachine::MouseButtonPressed(sf::Event event)
{
	current_state->MouseButtonPressed(event);
}

void GameStateMachine::MouseButtonReleased(sf::Event event)
{
	current_state->MouseButtonReleased(event);
}
