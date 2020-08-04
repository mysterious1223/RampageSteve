// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "SimpleAIComponent.h"


SimpleAIComponent::SimpleAIComponent (Entity*& entity) : Component(entity)
{
    //empty for now
}


bool SimpleAIComponent::init()
{


    return true;
}

void SimpleAIComponent::update(const float& dt)
{
    
}
void SimpleAIComponent::updateInput (const float& dt, sf::Event* event)
{
    
}

void SimpleAIComponent::updateRender(sf::RenderTarget* target)
{
}

SimpleAIComponent::~SimpleAIComponent()
{
    
}
