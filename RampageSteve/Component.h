#pragma once
#ifndef _COMPONENT_H_
#define _COMPONENT_H_
#include "Globals.h"


class Entity;
class Component
{
public:
	// take in component type
    Component(Entity* entity) {thisEntity = entity;};

    // When component is added to an entity this is automatically called
	virtual bool init() = 0;

	virtual void update(float& dt) = 0;

    virtual void updateInput (float& dt, sf::Event*) = 0;

    virtual void updateRender(sf::RenderTarget* target) = 0;

    
    virtual ~Component(){printf ("Parent of Component destroyed\n");};

protected:

    Entity* thisEntity = nullptr;


};

#endif // _COMPONENT_H_
