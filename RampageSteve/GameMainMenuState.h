#pragma once
#ifndef GAMEMAINMENUSTATE_H
#define GAMEMAINMENUSTATE_H
#include "Globals.h"

// Base class for all states

class ConfigurationData;
class GameState;
class GamMainMenuState : public GameState
{
public:
    
    
	GamMainMenuState(std::vector<ConfigurationData*> res);

    
	// main state loop
	bool update(float&);


	//Render loop
	bool render(sf::RenderTarget* target);

	//input update
	void updateInput(float&, sf::Event*);


private:
	// temp
	//Entity* player = nullptr;
    //Entity* background = nullptr;
	//std::vector<ConfigurationData*> gameResources;

    //std::vector <Entity*> *GameEntities = nullptr;
    
    //Entity* background = nullptr;
	~GamMainMenuState();
};

#endif //// GAMEMAINMENUSTATE_H


