#include "GameState.h"



GameState::GameState(std::vector<ConfigurationData*> res)
{

	

	this->isEnd = false;
    
    this->gameResources = res;
}



bool GameState::isStateEnd()
{
	return this->isEnd;
}


GameState::~GameState()
{
}


