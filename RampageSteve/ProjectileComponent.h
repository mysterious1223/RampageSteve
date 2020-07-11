/*
    Author: Kevin Singh
    
    This class for now will give an entity RangedCombatComponent

 */
/*
 Controls ranged combat AND ranged combat controls
 
 in the future we can modify to handle many projectile
 
 */


#pragma once
#ifndef PROJECTILECOMPONENT_H
#define PROJECTILECOMPONENT_H
#include "Globals.h"


// This will be inherited by a bullet or etc? in the future we can do that. For now we only need one kind of projectile
class Component;
class ProjectileComponent : public Component
{
public:
	ProjectileComponent(Entity*&, const float&);
    [[nodiscard]]
	bool init();

	void update(const float& dt);

	void updateInput(const float& dt, sf::Event*);

	void updateRender(sf::RenderTarget* target);

	~ProjectileComponent();
    
private:
    // set target position
    [[nodiscard]] // target , current
    bool setTargetPosition (const sf::Vector2f&, const sf::Vector2f&);
    
    // move entity to position
    void moveToTarget (const float& dt);
    
    // target
    sf::Vector2f _targetPos;
    sf::Vector2f _initPos;
    sf::Vector2f _targetDiff;
    
    // isTarget set
    bool _isTargetSet;
    
    // speed
    float _speed;
    
    // duration clock
    sf::Clock _timer;
    
    // max duration
    float _max_dur;
    
    //friend
    friend class RangedCombatComponent;
    
};


#endif //PROJECTILECOMPONENT_H
