#include "GameState.h"

GameState::GameState(sf::Vector2f& viewSize, std::vector<ConfigurationData*> res)
{

	this->screenSize = viewSize;

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


