/*
    Author: Kevin Singh
    
    This class for now will symbolically classify an entity of it is collidable. The check will be done in GameState.

 */

#pragma once
#ifndef SIMPLEAICOMPONENT_H
#define SIMPLEAICOMPONENT_H
#include "Globals.h"


// We dont need this shit until the next project where we will have different AIs
//enum class AIType;
// What kind of AI?
//enum class AIType  {
  
//};


class Component;
class ColliderComponent;
class SimpleAIComponent : public Component
{
public:
	SimpleAIComponent(Entity*&, ColliderComponent*&);
    //SimpleAIComponent (Entity*&);
    [[nodiscard]]
	bool init();

	void update(const float& dt);

	void updateInput(const float& dt, sf::Event*);

	void updateRender(sf::RenderTarget* target);
    
    // Control functions
    
    // Move to current target
    [[nodiscard]]
    bool moveToTarget (const float &);
    
    
    // move to specific position
    [[nodiscard]]
    bool moveToPos (const Entity&);
    
    [[nodiscard]]
    bool moveToPos (const sf::Vector2f&);
    
    
    // This probably should be called only when player enters perimeter?
    // set target IF one is not currently set
    [[nodiscard]]
    bool setTarget (Entity*&);
    
    
    // set sphere of influence
    inline void setSphereOfInfluence (const float& radius) {this->_detectionRadius = radius;};
    
    
    
	~SimpleAIComponent();
private:

    
    // Trigger actions when something enters withing the circle around this entity
    float _detectionRadius;
    
    
    // Maybe swap for a unique pointer?
    Entity *_target;
    ColliderComponent* _coll;
};


#endif // SIMPLEAICOMPONENT_H
