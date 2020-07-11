#pragma once
#ifndef GAMEWORLDSTATE_H
#define GAMEWORLDSTATE_H
#include "Globals.h"

// Base class for all states

class ConfigurationData;
class Entity;
class GameState;

// holder for child and parent entity, Will be used later when we add projectiles to enemy
typedef struct {
    Entity* projectile;
    Entity* parentEntity;
} Relationship_container_;


class GameWorldState : public GameState
{
public:
    
    
	GameWorldState(std::vector<ConfigurationData*> &res);

    [[nodiscard]]
    bool init ();
    
	// main state loop
    [[nodiscard]]
	bool update(const float&);


	//Render loop
    [[nodiscard]]
	bool render(sf::RenderTarget* target);

	//input update
	void updateInput(const float&, sf::Event*);


private:
	// temp
	//Entity* player = nullptr;
    //Entity* background = nullptr;
	//std::vector<ConfigurationData*> gameResources;

    std::vector <Entity*> _gameEntities;
    std::vector <Entity*> _projectiles;
    
    Entity* background = nullptr;
	~GameWorldState();
    
    // sweep for deleted objects
    void cleanDeletedEntities ();
};

#endif //// GAMEWORLDSTATE_H


/*
TODO

Test input and end app option by setting up a key bind to escape and killing application?

*/
