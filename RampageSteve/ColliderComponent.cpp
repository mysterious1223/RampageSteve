// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "ColliderComponent.h"


ColliderComponent::ColliderComponent (Entity*& entity, PhysicsBodyComponent* phy) : Component(entity)
{
    //empty for now
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

void ColliderComponent::updateRender(sf::RenderTarget* target)
{
}

ColliderComponent::~ColliderComponent()
{
    
}
