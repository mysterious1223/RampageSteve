#pragma once
#ifndef GAMEWORLDSTATE_H
#define GAMEWORLDSTATE_H
#include "Globals.h"

// Base class for all states
class ConfigurationData;
class Entity;
class GameState;
class GameWorldState : public GameState
{
public:
	GameWorldState(sf::Vector2f&);


	// main state loop
	bool update(float&);

	//Render loop
	bool render(sf::RenderTarget* target);

	//input update
	void updateInput(float&, sf::Event*);


private:
	// temp
	Entity* player = nullptr;
    Entity* background = nullptr;
	std::vector<ConfigurationData*> gameResources;

	~GameWorldState();
};

#endif //// GAMEWORLDSTATE_H


/*
TODO

Test input and end app option by setting up a key bind to escape and killing application?

*/
