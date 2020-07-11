// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "RangedCombatComponent.h"


RangedCombatComponent::RangedCombatComponent (Entity*& entity,std::vector<Entity*>& entityList, const bool& isControllable) : Component(entity), _isMouseClicked(false),_entities (entityList),// _curr_bullets (0), _isTimeout(false),
_mouseClickedLocation(sf::Vector2f())
{
    // member to check if this is a controlled object
    this->_isControllable = isControllable;
    //this->_entities = entityList;
}

bool RangedCombatComponent::init()
{
    

    return true;
}
// create a new projectile object so we can move and place into gameentities
Entity* RangedCombatComponent::instantiate_Projectile (const sf::Vector2f& toPos){
    
    // copy the top element
    //std::unique_ptr<Entity> ptr (new Entity); We should replace all local pointer with this
    Entity *inst_projectile = new Entity;
    *inst_projectile = *this->_projectiles [0];
    
    inst_projectile->clearComponents();
    
    inst_projectile->setPosition(this->thisEntity->getPosition());
    
    
    
    
    // need need projectile to move to position. So we need to retireve the ProectileObject
    ProjectileComponent * entityProjectile = new ProjectileComponent (inst_projectile, 700);
    if (!inst_projectile->AddComponent(entityProjectile)) {printf ("Ranged projectile comp failed\n");}
    
    
    // we NEED TO COPY PROJECTILE COMPONENT
    
    //ProjectileComponent* entityProjectile = dynamic_cast<ProjectileComponent*>(inst_projectile->GetComponent<ProjectileComponent>());
    
    
    //if (entityProjectile == nullptr)
      //  return nullptr;
    
    // change ownership to this instance, Why the fuck?
    //entityProjectile->changeOwnership(inst_projectile);
    
    if (!entityProjectile->setTargetPosition(toPos, this->thisEntity->getPosition())) {}
    
    

    //this->_curr_bullets ++;
    return inst_projectile;
    
}

void RangedCombatComponent::update(const float& dt)
{
    if (this->_isMouseClicked)
    {
        //printf ("Ranged combat fire %f, %f \n", this->_mouseClickedLocation.x, this->_mouseClickedLocation.y);
        
        
        // the issue is that the bullets are generating way too fast and allocating too much memory.
        // create a buffer (eventually) to restrict the number of bullets generated
        // We need to limit how often we can signal for a new bullet
        // first we need to make the bullet move when instantiated
        // second we can either track how far it is from our player or how much time has elapsed
        // third if player spams we can store bullets in a buffer if buffer max is reached player can fire any more
        
        if (!this->_fired )// && this->_curr_bullets < this->_MAX_BULLETS_)
        {
            
            Entity* tempEntity = instantiate_Projectile(this->_mouseClickedLocation);
            
            this->_entities.push_back(tempEntity);
            
            //printf ("size %d\n", this->_entities.size());
            this->_fired = true;
        }
        /*
        else if (this->_isTimeout)
        {
            // in timeout mode
            if (this->_timer.getElapsedTime().asSeconds() >= this->_timeoutTime)
            {
                //reset
                this->_isTimeout = false;
                this->_curr_bullets = 0;
                
            }
        }
        else
        {
            // we need to time out
            this->_isTimeout = true;
            this->_timer.restart();
        }
         */
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
            this->_fired = false;
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
    
    // check if entity is projectile
    if (entity->checkIfContainsComponent<ProjectileComponent>())
    {
        this->_projectiles.push_back(entity);
        return true;
    }
    
    return false;
    
}
bool RangedCombatComponent::addProjectiles (const std::vector <Entity*>& projectiles)
{
    for (auto p : projectiles)
    {
        // if any of the entity DOES not contains a projectile component return false
        if (!p->checkIfContainsComponent<ProjectileComponent>())
        {
            return false;
        }
    }
    this->_projectiles = projectiles;
    return true;
}
RangedCombatComponent::~RangedCombatComponent()
{
    if (!this->_projectiles.empty())
    {
        for (auto &a : this->_projectiles)
        {
            delete a;
        }
    }
}
