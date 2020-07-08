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
    
    
};


#endif //PROJECTILECOMPONENT_H
