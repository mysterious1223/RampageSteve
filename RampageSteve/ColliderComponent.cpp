#include "ColliderComponent.h"


ColliderComponent::ColliderComponent (Entity* entity, PhysicsBodyComponent* phy) : Component(entity)
{
    //empty for now
}



bool ColliderComponent::init()
{


    return true;
}

void ColliderComponent::update(float& dt)
{
    
}
void ColliderComponent::updateInput (float& dt, sf::Event* event)
{
    
}

void ColliderComponent::updateRender(sf::RenderTarget* target)
{
}

ColliderComponent::~ColliderComponent()
{
    
}
