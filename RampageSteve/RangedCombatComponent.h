/*
    Author: Kevin Singh
    
    This class for now will give an entity RangedCombatComponent

 */
/*
 Controls ranged combat AND ranged combat controls
 
 in the future we can modify to handle many projectile
 
 */


#pragma once
#ifndef RANGEDCOMBATCOMPONENT_H
#define RANGEDCOMBATCOMPONENT_H
#include "Globals.h"



class Component;
class CharacterControllerComponent;
class RangedCombatComponent : public Component
{
public:
	RangedCombatComponent(Entity*&, const bool& isControllable = false);
    [[nodiscard]]
	bool init();

	void update(const float& dt);

	void updateInput(const float& dt, sf::Event*);

	void updateRender(sf::RenderTarget* target);
    [[nodiscard]] // we need to check if the entity provided contains a Projectile component
    bool addProjectile (Entity*&);

	~RangedCombatComponent();
private:
    
    // Projectile list? Inherits entity?
    
    bool _isControllable;
    sf::Vector2f _mouseClickedLocation;
    bool _isMouseClicked;
    
    
    // list of projectiles
    std::vector<Entity*> _projectiles;
};


#endif // RANGEDCOMBATCOMPONENT_H
