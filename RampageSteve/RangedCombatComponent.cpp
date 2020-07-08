// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "RangedCombatComponent.h"


RangedCombatComponent::RangedCombatComponent (Entity* entity) : Component(entity)
{
    
}
RangedCombatComponent::RangedCombatComponent(Entity* entity, CharacterControllerComponent* controller) : Component(entity)
{
    // link the controller to this component
    this->_controller = controller;
}


bool RangedCombatComponent::init()
{


    return true;
}

void RangedCombatComponent::update(const float& dt)
{
    
}
void RangedCombatComponent::updateInput (const float& dt, sf::Event* event)
{
    
}

void RangedCombatComponent::updateRender(sf::RenderTarget* target)
{
}

RangedCombatComponent::~RangedCombatComponent()
{
    
}
