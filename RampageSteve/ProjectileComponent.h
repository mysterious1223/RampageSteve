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
	ProjectileComponent(Entity*&);
    [[nodiscard]]
	bool init();

	void update(const float& dt);

	void updateInput(const float& dt, sf::Event*);

	void updateRender(sf::RenderTarget* target);

	~ProjectileComponent();
    
private:
    // set target position
    [[nodiscard]]
    bool setTargetPosition (const sf::Vector2f&);
    
    // target
    sf::Vector2f _targetPos;
    
    // isTarget set
    bool _isTargetSet;
    
    //friend
    friend class RangedCombatComponent;
    
};


#endif //PROJECTILECOMPONENT_H
