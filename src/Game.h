
#ifndef SFML_GAME_H
#define SFML_GAME_H

#include <SFML/Graphics.hpp>
#include "GameStateMachine.h"
#include "GameStateMenu.h"
#include "GameStateGameplay.h"
#include "GameStatePaused.h"


class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseButtonPressed(const sf::Event::MouseButtonPressed* event);
  void mouseButtonReleased(const sf::Event::MouseButtonReleased* event);
  void keyPressed(const sf::Event::KeyPressed* event);
  void keyReleased(const sf::Event::KeyReleased* event);

  GameStateMachine game_state_machine;

 private:
  sf::RenderWindow& window;
  
  sf::Texture background_texture;
  sf::Sprite background = sf::Sprite(background_texture);

};

#endif // SFML_GAME_H
