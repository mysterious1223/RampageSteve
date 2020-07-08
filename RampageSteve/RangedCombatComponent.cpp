// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "RangedCombatComponent.h"


RangedCombatComponent::RangedCombatComponent (Entity*& entity, const bool& isControllable) : Component(entity), _isMouseClicked(false),
_mouseClickedLocation(sf::Vector2f())
{
    // member to check if this is a controlled object
    this->_isControllable = isControllable;
    
}

bool RangedCombatComponent::init()
{
    

    return true;
}

void RangedCombatComponent::update(const float& dt)
{
    if (this->_isMouseClicked)
    {
        printf ("Ranged combat fire %f, %f \n", this->_mouseClickedLocation.x, this->_mouseClickedLocation.y);
    }
    
}
void RangedCombatComponent::updateInput (const float& dt, sf::Event* event)
{
    // if controllable we can read inputs
    if (this->_isControllable)
    {
        if (event->type == sf::Event::MouseButtonPressed)
        {
            //float mX = (float) event->mouseButton.x;
            //float mY = (float) event->mouseButton.y;
            this->_mouseClickedLocation = sf::Vector2f (event->mouseButton.x, event->mouseButton.y);
            
            this->_isMouseClicked = true;
        }
        if (event->type == sf::Event::MouseButtonReleased)
        {
            //float mX = (float) event->mouseButton.x;
            //float mY = (float) event->mouseButton.y;
            
            
            this->_isMouseClicked = false;
        }
        
    }
}

void RangedCombatComponent::updateRender(sf::RenderTarget* target)
{
}
bool RangedCombatComponent::addProjectile (Entity*& entity)
{
   
    // Projectivel type
    //if (entity->checkIfContainsComponent<>())
    
    
    this->_projectiles.push_back(entity);
}
RangedCombatComponent::~RangedCombatComponent()
{
    
}
