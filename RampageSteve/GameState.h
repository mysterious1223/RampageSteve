#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "Globals.h"


class ConfigurationData;

class GameState {

public:

	GameState(std::vector<ConfigurationData*>);



	// main state loop
	virtual bool update(float&) = 0;

	//Render loop
	virtual bool render(sf::RenderTarget* target = nullptr) = 0;

	//input update
	virtual void updateInput(float&, sf::Event*) = 0;


	
	// check if state is end and perform cleanup
	bool isStateEnd();

	// end app

	inline static bool isAppEnd = false;

	virtual ~GameState();
protected:
	// isEnd
	// end state
	bool isEnd = false;
	


    std::vector<ConfigurationData*> gameResources;
private:
	// stack of game states in this class probably only used in menus or maybe scene loading
	std::stack <GameState*> states;


	

	// end state triggers a return value causing state to end
	//void setendState(bool);
};

#endif // // GAMESTATE_H
