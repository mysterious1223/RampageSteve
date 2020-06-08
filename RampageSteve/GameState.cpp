// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "GameState.h"



GameState::GameState(std::vector<ConfigurationData*>& res) : gameResources{ res } , isEnd{false}
{

	
    
}



bool GameState::isStateEnd()
{
	return this->isEnd;
}


GameState::~GameState()
{
}


