// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "ProjectileComponent.h"


ProjectileComponent::ProjectileComponent (Entity*& entity) : Component(entity), _targetPos(sf::Vector2f()), _isTargetSet (false)
{
    
}
// initialize target position
bool ProjectileComponent::setTargetPosition (const sf::Vector2f& pos)
{
    this->_targetPos = pos;
    this->_isTargetSet = true;
    
    return true;
}
bool ProjectileComponent::init()
{
    // ?
    //reset at init
    this->_targetPos = sf::Vector2f ();
    this->_isTargetSet = false;

    return true;
}

void ProjectileComponent::update(const float& dt)
{
    if (this->_isTargetSet)
    {
        // we can move our entity
        //this->thisEntity->move(10*dt, 10*dt);
        //printf ("from proj : %p\n", this->thisEntity);
        //printf ("Moving %f, %f\n", this->thisEntity->getPosition().x,this->thisEntity->getPosition().y);
    }
    
}
void ProjectileComponent::updateInput (const float& dt, sf::Event* event)
{
   
}

void ProjectileComponent::updateRender(sf::RenderTarget* target)
{
}

ProjectileComponent::~ProjectileComponent()
{
     
}
