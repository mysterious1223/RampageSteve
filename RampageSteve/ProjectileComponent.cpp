// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "ProjectileComponent.h"


ProjectileComponent::ProjectileComponent (Entity*& entity) : Component(entity)
{
    
    
}

bool ProjectileComponent::init()
{
    

    return true;
}

void ProjectileComponent::update(const float& dt)
{
    
    
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
