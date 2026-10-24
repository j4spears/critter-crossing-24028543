#pragma once

#ifndef SFML_GAMESTATEGAMEPLAY_H
#define SFML_GAMESTATEGAMEPLAY_H

#include <optional>

#include "GameState.h"

class GameStateGameplay : public GameState
{
	public:
	GameStateGameplay(Game& game);
	~GameStateGameplay();
	void InitState() override;
	void EnterState() override;
	void Update(float dt) override;
	void ExitState() override;
	void Render(sf::RenderWindow& window) override;
	void KeyPressed(const sf::Event::KeyPressed* event) override;
	void KeyReleased(const sf::Event::KeyReleased* event) override;
	void MouseButtonPressed(const sf::Event::MouseButtonPressed* event) override;
	void MouseButtonReleased(const sf::Event::MouseButtonReleased* event) override;

	bool newAnimal();

	sf::Sprite* animal;
	sf::Sprite* passport;
	sf::Texture* animals = new sf::Texture[3];
	sf::Texture* passports = new sf::Texture[3];
	bool match;

	sf::Sprite* dragged = nullptr;
	sf::Vector2f drag_offset;
	bool passport_returned = false;
	void dragSprite(sf::Sprite* sprite);

	sf::Sprite* background;
	sf::Texture* bg_texture = new sf::Texture{ "../Data/Images/WhackaMole Worksheet/background.png" };

	sf::Sprite* accept_button;
	sf::Texture* accept_button_texture = new sf::Texture{"../Data/Images/Critter Crossing/accept button.png"};
	sf::Sprite* ui_accept;
	sf::Texture* ui_accept_texture = new sf::Texture{ "../Data/Images/Critter Crossing/accept.png" };
	sf::Sprite* reject_button;
	sf::Texture* reject_button_texture = new sf::Texture{ "../Data/Images/Critter Crossing/reject button.png" };
	sf::Sprite* ui_reject;
	sf::Texture* ui_reject_texture = new sf::Texture{ "../Data/Images/Critter Crossing/reject.png" };

	bool show_choices = false;
	std::optional<bool> accepted = std::nullopt;

	sf::Sprite* next_button;
	sf::Texture* next_button_texture = new sf::Texture{ "../Data/Images/next please ui.png" };
	sf::Sprite* ui_well_spotted;
	sf::Texture* ui_well_spotted_texture = new sf::Texture{ "../Data/Images/well spotted.png" };

	sf::Sprite* retry_button;
	sf::Texture* retry_button_texture = new sf::Texture{ "../Data/Images/retry.png" };
	sf::Sprite* ui_fail_match;
	sf::Texture* ui_fail_match_texture = new sf::Texture{ "../Data/Images/the passport was a match.png" };
	sf::Sprite* ui_fail_no_match;
	sf::Texture* ui_fail_no_match_texture = new sf::Texture{ "../Data/Images/you let in an imposter.png" };

	int score = 0;
	int session_high_score;
	sf::Font* font;
	sf::Text* score_text = new sf::Text(*font);
};

#endif // SFML_GAMESTATEGAMEPLAY_H