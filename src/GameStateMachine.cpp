#include "GameStateMachine.h"

#include "Game.h"

GameStateMachine::GameStateMachine(Game& game) : game(game){}

GameStateMachine::~GameStateMachine(){}

void GameStateMachine::init()
{
	states = 
	{
		{"MENU",std::make_shared<GameStateMenu>(game)},
		{"GAMEPLAY",std::make_shared<GameStateGameplay>(game)},
		{"PAUSED",std::make_shared<GameStatePaused>(game)}
	};

	for (const auto& [name, state] : states)
	{
		state->InitState();
	}

	previous_state = states["MENU"];
	current_state = states["GAMEPLAY"];
	current_state->EnterState();
}

void GameStateMachine::ChangeState(std::shared_ptr<GameState> new_state)
{
	previous_state = current_state;
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

std::shared_ptr<GameState> GameStateMachine::getPreviousState()
{
	return previous_state;
}
