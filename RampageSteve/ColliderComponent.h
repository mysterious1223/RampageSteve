/*
    Author: Kevin Singh
    
    This class for now will symbolically classify an entity of it is collidable. The check will be done in GameState.

 */

#pragma once
#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H
#include "Globals.h"



class Component;
class PhysicsBodyComponent;
class ColliderComponent : public Component
{
public:
	ColliderComponent(Entity*, PhysicsBodyComponent*);

	bool init();

	void update(float& dt);

	void updateInput(float& dt, sf::Event*);

	void updateRender(sf::RenderTarget* target);

	~ColliderComponent();
private:

};


#endif // COLLIDERCOMPONENT_H
