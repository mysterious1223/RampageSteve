// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "ProjectileComponent.h"


ProjectileComponent::ProjectileComponent (Entity*& entity,const float& speed) : Component(entity), _targetPos(sf::Vector2f()),_targetDiff(sf::Vector2f()), _initPos (sf::Vector2f()), _isTargetSet (false), _speed(speed), _max_dur(3)
{
    
}
// initialize target position
bool ProjectileComponent::setTargetPosition (const sf::Vector2f& t_pos, const sf::Vector2f& curr_pos)
{
    _timer.restart();
    
    this->_targetPos = t_pos;
    this->_initPos = curr_pos;
    this->_isTargetSet = true;
    
    // set the trajectory
    this->_targetDiff =  this->_targetPos - this->_initPos;
    
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
void ProjectileComponent::moveToTarget (const float& dt)
{
    // get unit vector. (point on unit circle)
    sf::Vector2f uv = sf::Vector2f
    (
    (this->_targetDiff.x / sqrt(pow(this->_targetDiff.x, 2) + pow(this->_targetDiff.y, 2))),
    (this->_targetDiff.y / sqrt(pow(this->_targetDiff.x, 2) + pow(this->_targetDiff.y, 2)))
    );
    
    this->thisEntity->move((uv.x * this->_speed) * dt, (uv.y * this->_speed) * dt);
    
    
    
    
    //this->thisEntity->move(10*dt, 10*dt);
}

void ProjectileComponent::update(const float& dt)
{
    if (this->_isTargetSet)
    {
        // we can move our entity
      
        this->moveToTarget(dt);
        if (_timer.getElapsedTime().asSeconds() >= _max_dur)
            this->thisEntity->setIsDead();
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
