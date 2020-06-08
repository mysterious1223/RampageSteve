#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include "Globals.h"

class ConfigurationData;
class ResourceLoader;
class GameState;
class GameWorldState;
class GameMainMenuState;
class Game
{
public:

	Game();


	void initStates();

	// Loopers
	// Runs a call to update dt
	void updateDT();
	// poll event will be looped and checked in here
	void updateEvents();
	void MainUpdate();

	// Render
	void render();

	// run game in main
	void run();

	~Game();

private:
	float dt;
	sf::Clock dtClock;
	sf::RenderWindow* window;
	sf::Event sfEvent;
	sf::Vector2f viewSize;

    std::vector<ConfigurationData*> resources;
    
	std::stack<GameState*> states;

	bool EndGame();


	bool isApplicationEnd = false;
};
static ResourceLoader * resourceLoader = nullptr;

#endif //// __GAME_H__
