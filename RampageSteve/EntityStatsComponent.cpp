// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "EntityStatsComponent.h"


EntityStatsComponent::EntityStatsComponent (Entity*& entity) : Component(entity), _stats()
{
    //empty for now
}


bool EntityStatsComponent::init()
{


    return true;
}

void EntityStatsComponent::update(const float& dt)
{
    
}
void EntityStatsComponent::updateInput (const float& dt, sf::Event* event)
{
    
}

void EntityStatsComponent::updateRender(sf::RenderTarget* target)
{
}
void EntityStatsComponent::setBaseStats (const Stats_Container& stats)
{
    this->_stats = stats;
    
}
// Take dmg
const float EntityStatsComponent::dealDmgToThis (const unsigned& dmg) {
    
    //float remaining_hp = this->_stats._health;
    
    
    
    if (this->_stats._health >= 1)
    {
        // we can deal dmg
        //this->_stats._health
        this->_stats._health -= dmg;
        
        printf ("Health declined %d,%d \n", this->_stats._health, dmg);
        
        if (this->_stats._health >= 1){
            
            
            return this->_stats._health;
        }
        else
        {
            printf ("Entity is dead %s\n", this->thisEntity->getName().c_str());
            this->thisEntity->setIsDead();
            return this->_stats._health;
        }
        
    }
    else
    {
        printf ("Entity is dead %s\n", this->thisEntity->getName().c_str());
        this->thisEntity->setIsDead();
        return this->_stats._health;
    }
    
    
    return 0;
    
}

// Deal dmg
bool EntityStatsComponent::attackEntity (Entity*& entity) {
    
    if (entity->checkIfContainsComponent<EntityStatsComponent>())
    {
        // entity has component
        EntityStatsComponent* entity_stats = static_cast<EntityStatsComponent*>( entity->GetComponent<EntityStatsComponent>() ) ;
        
        if (entity_stats->_stats._health >= 1 && !entity->isEntityDeleted())
        {
            // if has health and not deleted
            entity_stats->dealDmgToThis(this->_stats._attack_dmg);
          
            
        }
        else
            return false;
        
        
        return true;
        
    }
    else
        return false;
    
    
    
    return false;
    
}


EntityStatsComponent::~EntityStatsComponent()
{
    
}
