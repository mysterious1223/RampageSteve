#pragma once
#ifndef GAMEMAINMENUSTATE_H
#define GAMEMAINMENUSTATE_H
#include "Globals.h"

// Base class for all states

using namespace SFML_GUI;

class ConfigurationData;
class GameState;
class GameMainMenuState : public GameState
{
public:
    
    
	GameMainMenuState(std::vector<ConfigurationData*> &res);
   
	// main state loop
    bool update(float&);


	//Render loop
    bool render(sf::RenderTarget* target);

	//input update
    void updateInput(float&, sf::Event*);

   
private:
    ~GameMainMenuState();
    
    sf::Texture PlayButtonTexture, QuitButtonTexture;
    GUI_items::MenuItem* PlayButton = nullptr;
    GUI_items::MenuItem* QuitButton = nullptr;
    SFML_GUI::UI_Layouts::MainMenuFlowLayout * MainMenuLayout = nullptr;
    
  
    // Callbacks
    
    static void PlayGame ();
    static void EndGame();
    
    inline static bool IsMenuOver = false;


};



#endif //// GAMEMAINMENUSTATE_H


