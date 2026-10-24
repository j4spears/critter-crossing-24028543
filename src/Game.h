
#ifndef SFML_GAME_H
#define SFML_GAME_H

#include <SFML/Graphics.hpp>
#include "GameStateMachine.h"



class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void keyPressed(const sf::Event::KeyPressed* event);
  void keyReleased(const sf::Event::KeyReleased* event);
  void mouseButtonPressed(const sf::Event::MouseButtonPressed* event);
  void mouseButtonReleased(const sf::Event::MouseButtonReleased* event);
  sf::Vector2f getMousePositionf();

  sf::RenderWindow& getWindow();

  GameStateMachine state_machine;


  

 private:
  sf::RenderWindow& window;
  
};

#endif // SFML_GAME_H
