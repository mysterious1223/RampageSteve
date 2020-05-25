#include "GameState.h"

GameState::GameState(sf::Vector2f& viewSize)
{

	this->screenSize = viewSize;

	this->isEnd = false;
}



bool GameState::isStateEnd()
{
	return this->isEnd;
}


GameState::~GameState()
{
}


