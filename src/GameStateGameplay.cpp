#include "GameStateGameplay.h"
#include "Game.h"

GameStateGameplay::GameStateGameplay(Game& game) : GameState(game) {}

GameStateGameplay::~GameStateGameplay(){}

void GameStateGameplay::InitState()
{
	font = new sf::Font();
	font->openFromFile("../Data/Fonts/OpenSans-Bold.ttf");
	score_text = new sf::Text(*font);
	score_text->setString("Score: 0");
	score_text->setCharacterSize(40);
	score_text->setPosition(sf::Vector2f(game.getWindow().getSize().x - 200, 50));

	animals[0] = sf::Texture{ "../Data/Images/Critter Crossing/elephant.png" };
	passports[0] = sf::Texture{ "../Data/Images/Critter Crossing/elephant passport.png" };
	animals[1] = sf::Texture{ "../Data/Images/Critter Crossing/moose.png" };
	passports[1] = sf::Texture{ "../Data/Images/Critter Crossing/moose passport.png" };
	animals[2] = sf::Texture{ "../Data/Images/Critter Crossing/penguin.png" };
	passports[2] = sf::Texture{ "../Data/Images/Critter Crossing/penguin passport.png" };
	animal = new sf::Sprite(animals[0]);
	passport = new sf::Sprite(passports[0]);

	bg_texture = new sf::Texture{ "../Data/Images/WhackaMole Worksheet/background.png" };
	background = new sf::Sprite(*bg_texture);

	accept_button = new sf::Sprite(*accept_button_texture);
	accept_button->setPosition({ 800, 400 });
	accept_button->setScale({ 0.5, 0.5 });
	ui_accept = new sf::Sprite(*ui_accept_texture);

	reject_button = new sf::Sprite(*reject_button_texture);
	reject_button->setPosition({ 800, 450 });
	reject_button->setScale({ 0.5, 0.5 });
	ui_reject = new sf::Sprite(*ui_reject_texture);

	next_button = new sf::Sprite(*next_button_texture);
	next_button->setPosition({ 440, 250 });
	next_button->setScale({ 0.5, 0.5 });
	ui_well_spotted = new sf::Sprite(*ui_well_spotted_texture);
	ui_well_spotted->setPosition({ 400, 200 });
	ui_well_spotted->setScale({ 0.5, 0.5 });
	retry_button = new sf::Sprite(*retry_button_texture);
	retry_button->setPosition({ 440, 240 });
	retry_button->setScale({ 0.5, 0.5 });
	ui_fail_match = new sf::Sprite(*ui_fail_match_texture);
	ui_fail_match->setPosition({ 400, 200 });
	ui_fail_match->setScale({ 0.5, 0.5 });
	ui_fail_no_match = new sf::Sprite(*ui_fail_no_match_texture);
	ui_fail_no_match->setPosition({ 400, 200 });
	ui_fail_no_match->setScale({ 0.5, 0.5 });
}

void GameStateGameplay::EnterState()
{
	score = 0;

	if (game.state_machine.getPreviousState() == game.state_machine.states["MENU"])
	{
		match = newAnimal();
	}
}

void GameStateGameplay::Update(float dt)
{
	if (dragged) { dragSprite(dragged); }
}

void GameStateGameplay::ExitState()
{
	delete[] animals;
	delete[] passports;
	delete animal;
	delete passport;
	delete bg_texture;
	delete background;
	delete accept_button;
	delete ui_accept;
	delete reject_button;
	delete ui_reject;
}

void GameStateGameplay::Render(sf::RenderWindow& window)
{
	
	game.getWindow().draw(*background);
	game.getWindow().draw(*animal);
    game.getWindow().draw(*score_text);

	if (!passport_returned)
	{
		game.getWindow().draw(*passport);

		if (accepted == true)
		{
			game.getWindow().draw(*ui_accept);
		}
		else if (accepted == false)
		{
			game.getWindow().draw(*ui_reject);
		}

	}
	else
	{
		if (accepted == true)
		{
			if (match)
			{
				game.getWindow().draw(*next_button);
			}
			else
			{
				game.getWindow().draw(*ui_fail_no_match);
				game.getWindow().draw(*retry_button);
			}
		}

		if (accepted == false)
		{
			if (match)
			{
				game.getWindow().draw(*ui_fail_match);
				game.getWindow().draw(*retry_button);
			}
			else
			{
				game.getWindow().draw(*ui_well_spotted);
				game.getWindow().draw(*next_button);
			}

		}
	}
	
	if (show_choices)
	{
		game.getWindow().draw(*accept_button);
		game.getWindow().draw(*reject_button);
	}
}

void GameStateGameplay::KeyPressed(const sf::Event::KeyPressed* event)
{
	if (event->code == sf::Keyboard::Key::Space)
	{
		match = newAnimal();
	}
}

void GameStateGameplay::KeyReleased(const sf::Event::KeyReleased* event){}

void GameStateGameplay::MouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
	sf::Vector2f click = static_cast<sf::Vector2f>(event->position);

	if (event->button == sf::Mouse::Button::Left) 
	{
		if (passport->getGlobalBounds().contains(click) && accepted.has_value())
		{
			dragged = passport;

			sf::Vector2f mouse_position = game.getMousePositionf();
			drag_offset = mouse_position - dragged->getPosition();
		}
		
		if (show_choices && !accepted.has_value())
		{
			if (accept_button->getGlobalBounds().contains(click))
			{
				accepted = true;
				show_choices = false;
			}
			else if (reject_button->getGlobalBounds().contains(click))
			{
				accepted = false;
				show_choices = false;
			}
		}

		if (next_button->getGlobalBounds().contains(click))
		{
			if (accepted == true && match || accepted == false && !match)
			{
				match = newAnimal();
			}
		}

		if (retry_button->getGlobalBounds().contains(click))
		{
			if (accepted == false && match || accepted == true && !match)
			{
				match = newAnimal();
				score_text->setString("Score: " + std::to_string(score));
			}
		}
	}
	else if (event->button == sf::Mouse::Button::Right)
	{
		if (passport->getGlobalBounds().contains(click) && !accepted.has_value())
		{
			show_choices = !show_choices;
		}
	}
}

void GameStateGameplay::MouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{

	if (event->button == sf::Mouse::Button::Left)
	{
		if (dragged == passport)
		{
			if (dragged->getPosition().x < game.getWindow().getSize().x / 3 && dragged->getPosition().y < game.getWindow().getSize().y / 3)
			{
				passport_returned = true;

				if (accepted == true && match || accepted == false && !match)
				{
					score++;
					score_text->setString("Score: " + std::to_string(score));
				}
				else if (accepted == false && match || accepted == true && !match)
				{
					if (score > session_high_score)
					{
						session_high_score = score;
					}
					score = 0;
				}
			}

			passport->setPosition(sf::Vector2f(game.getWindow().getSize().x / 2, game.getWindow().getSize().y / 3));
			ui_accept->setPosition({ passport->getPosition().x + 50, passport->getPosition().y + 30 });
			ui_reject->setPosition({ passport->getPosition().x + 50, passport->getPosition().y + 30 });
		}

		dragged = nullptr;
	}
}

bool GameStateGameplay::newAnimal()
{
	passport_returned = false;
	accepted = std::nullopt;

	int animal_index = rand() % 3;
	int passport_index = rand() % 3;

	animal->setTexture(animals[animal_index], true);
	animal->setScale({1.8, 1.8});
	animal->setPosition(sf::Vector2f(game.getWindow().getSize().x / 12, game.getWindow().getSize().y / 12));

	passport->setTexture(passports[passport_index]);
	passport->setScale({0.6, 0.6});
	passport->setPosition(sf::Vector2f(game.getWindow().getSize().x / 2, game.getWindow().getSize().y / 3));

	ui_accept->setPosition({ passport->getPosition().x + 50, passport->getPosition().y + 30 });
	ui_reject->setPosition({ passport->getPosition().x + 50, passport->getPosition().y + 30 });

	if (animal_index == passport_index)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GameStateGameplay::dragSprite(sf::Sprite* sprite)
{
	sf::Vector2f mouse_position = game.getMousePositionf();
	sf::Vector2f drag_position = mouse_position - drag_offset;
	sprite->setPosition(drag_position);
	ui_accept->setPosition({ drag_position.x + 50, drag_position.y + 30});
	ui_reject->setPosition({ drag_position.x + 50, drag_position.y + 30 });
}
