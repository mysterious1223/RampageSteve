#include "GameMainMenuState.h"


GameMainMenuState::GameMainMenuState(std::vector<ConfigurationData*> res) : GameState(res) {
    
    //printf ("GameMainMenuState\n");
    
}

// main state loop
bool GameMainMenuState::update(float&)
{
    return true;
}


//Render loop
bool GameMainMenuState::render(sf::RenderTarget* target)
{
    
    return true;
}

//input update
void GameMainMenuState::updateInput(float&, sf::Event*)
{
    
}
GameMainMenuState::~GameMainMenuState()
{
    
}
