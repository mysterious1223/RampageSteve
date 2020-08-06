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
	ColliderComponent(Entity*&, PhysicsBodyComponent*);
    ColliderComponent (Entity*&);
    [[nodiscard]]
	bool init();

	void update(const float& dt);

	void updateInput(const float& dt, sf::Event*);

	void updateRender(sf::RenderTarget* target);
    
    
    // how should we structure the collision handling, we need this for the AI component
    // trigger a call back with (Entity A, Enttity B)
    // How can we implement this?
    inline void Iscollide (Entity * entity, const bool& isCollide) {this->_isCollided = isCollide; this->_t_entity = entity;};

    
	~ColliderComponent();
private:

    bool _isCollided;
    Entity* _t_entity;
    
    friend class SimpleAIComponent;
};


#endif // COLLIDERCOMPONENT_H
