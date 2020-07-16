#pragma once
#ifndef _COMPONENT_H_
#define _COMPONENT_H_
#include "Globals.h"


class Entity;
class Component
{
public:
	// take in component type
    // need to change all the *& back to * maybe a cause of our issues? Projectile not moving
    Component(Entity*& entity) {thisEntity = entity;};

    // When component is added to an entity this is automatically called
	virtual bool init() = 0;

	virtual void update(const float& dt) = 0;

    virtual void updateInput (const float& dt, sf::Event*) = 0;

    virtual void updateRender(sf::RenderTarget* target) = 0;

    inline void changeOwnership (Entity*& entity) {thisEntity = entity;}
    
    
    virtual ~Component() = default;

protected:

    Entity* thisEntity = nullptr;


};

#endif // _COMPONENT_H_
