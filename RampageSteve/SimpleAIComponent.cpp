// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "SimpleAIComponent.h"


SimpleAIComponent::SimpleAIComponent (Entity*& entity, ColliderComponent*& coll) : Component(entity), _target (nullptr), _coll(coll)
{
    //empty for now
    
}


bool SimpleAIComponent::init()
{
    printf ("AI Component loaded\n");

    return true;
}

void SimpleAIComponent::update(const float& dt)
{
    // Check radius area for objects?
    // Should we statically bound to player?
    if (this->_target != nullptr)
    {
        // move to target
        
        // this logic works
        if (!this->moveToTarget(dt))
        {
            printf ("Failed to move to target\n");
        }
        
        if (_coll->_isCollided)
        {
            //printf ("Collision detected with an object in simple AI\n");
            
            if (_coll->_t_entity == this->_target)
            {
                //printf ("IT IS OUR TARGET!\n");
                // Logic for interacting with entity
                
                if (this->_target->checkIfContainsComponent<EntityStatsComponent>())
                {
                                            
                    EntityStatsComponent* thisstats = static_cast<EntityStatsComponent*>
                                (this->thisEntity->GetComponent<EntityStatsComponent>());//->attackEntity(entity);
                                            
                    thisstats->attackEntity(this->_target);
                                            
                                            
                    //a->setIsDead();
                }
                
                
            }
            
        }
    
    
    }
    
}
bool SimpleAIComponent::moveToTarget (const float &dt)
{
    
    
    
    // formula is wrong
    //float distance = sqrt((pow(this->_target->getPosition().x, 2)-this->thisEntity->getPosition().x ) -
    //((pow(this->_target->getPosition().y, 2)-this->thisEntity->getPosition().y)));
    
    
    //printf ("Moving to target...\n");
    
   // if (distance > 150){
    sf::Vector2f diff = this->_target->getPosition() - this->thisEntity->getPosition();
    sf::Vector2f uv = sf::Vector2f
        (
    (diff.x / sqrt(pow(diff.x, 2) + pow(diff.y, 2))),
    (diff.y / sqrt(pow(diff.x, 2) + pow(diff.y, 2)))
        );
        
    this->thisEntity->move((uv.x * 100) * dt, (uv.y * 100) * dt);
    //    printf ("%f\n", distance);
        
        // we need to check if the player has jumped. If they did we will need to fly to them
        // Or disable gravity?
        
      //  return false;
    
   // }
    //printf ("%f\n", distance);
                          
    
    
    
    return true;
    
}
void SimpleAIComponent::updateInput (const float& dt, sf::Event* event)
{
    
}

void SimpleAIComponent::updateRender(sf::RenderTarget* target)
{
}
bool SimpleAIComponent::setTarget (Entity*& tar)
{
    printf ("Targer locked!\n");
    
    this->_target = tar;
    
    if (tar != nullptr)
        return true;
    else
        return false;
}
SimpleAIComponent::~SimpleAIComponent()
{
    
}
