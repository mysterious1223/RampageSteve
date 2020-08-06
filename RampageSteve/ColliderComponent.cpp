// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "ColliderComponent.h"


ColliderComponent::ColliderComponent (Entity*& entity, PhysicsBodyComponent* phy) : Component(entity),
_isCollided(false), _t_entity(nullptr)
{
    //empty for now
    
    
    
    
    // when objects collide a function in here will be triggered
}

ColliderComponent::ColliderComponent (Entity*& entity) : Component(entity){
    
}


bool ColliderComponent::init()
{


    return true;
}

void ColliderComponent::update(const float& dt)
{
    
}
void ColliderComponent::updateInput (const float& dt, sf::Event* event)
{
    
}
void OnCollision (Entity *& b){
    
    // how can we get our AI to detect a collision?
    // can we some how reference this call in our simple AI, but why?
    
    // return is collided. But with what?
    
}

void ColliderComponent::updateRender(sf::RenderTarget* target)
{
}

ColliderComponent::~ColliderComponent()
{
    
}
