#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "Globals.h"

class GameState {

public:

	GameState(sf::Vector2f& viewSize);



	// main state loop
	virtual bool update(float&) = 0;

	//Render loop
	virtual bool render(sf::RenderTarget* target = nullptr) = 0;

	//input update
	virtual void updateInput(float&, sf::Event*) = 0;


	
	// check if state is end and perform cleanup
	bool isStateEnd();



	sf::Vector2f getScreenSize() { return this->screenSize; };

	virtual ~GameState();
protected:
	// isEnd
	bool isEnd;
private:
	// stack of game states in this class probably only used in menus or maybe scene loading
	std::stack <GameState*> states;

	sf::Vector2f screenSize;
	

	// end state triggers a return value causing state to end
	//void setendState(bool);
};

#endif // // GAMESTATE_H
