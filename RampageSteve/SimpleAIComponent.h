/*
    Author: Kevin Singh
    
    This class for now will symbolically classify an entity of it is collidable. The check will be done in GameState.

 */

#pragma once
#ifndef SIMPLEAICOMPONENT_H
#define SIMPLEAICOMPONENT_H
#include "Globals.h"



class Component;
class SimpleAIComponent : public Component
{
public:
	SimpleAIComponent(Entity*&);
    //SimpleAIComponent (Entity*&);
    [[nodiscard]]
	bool init();

	void update(const float& dt);

	void updateInput(const float& dt, sf::Event*);

	void updateRender(sf::RenderTarget* target);

	~SimpleAIComponent();
private:

};


#endif // SIMPLEAICOMPONENT_H
