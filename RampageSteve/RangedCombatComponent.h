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
	RangedCombatComponent(Entity*&,std::vector<Entity*>&, const bool& isControllable = false);
    [[nodiscard]]
	bool init();

	void update(const float& dt);

	void updateInput(const float& dt, sf::Event*);

	void updateRender(sf::RenderTarget* target);
    [[nodiscard]] // we need to check if the entity provided contains a Projectile component
    bool addProjectile (Entity*&);
    [[nodiscard]]
    bool addProjectiles (const std::vector <Entity*>&);
    
    [[nodiscard]]
    inline const unsigned getProjectileCount () const {return _projectiles.size();}
    
	~RangedCombatComponent();
private:
    
    // Projectile list? Inherits entity?
    
    Entity* instantiate_Projectile (const sf::Vector2f&);
    
    
    bool _isControllable;
    sf::Vector2f _mouseClickedLocation;
    bool _isMouseClicked;
    
    
    // list of projectiles
    std::vector<Entity*> _projectiles;
    std::vector<Entity*> &_entities;
    
    //const unsigned _MAX_BULLETS_ = 1;
    
    //unsigned _curr_bullets;
    
    // timeout clock
    //sf::Clock _timer;
    // timing out
    //bool _isTimeout;
    // timeout time
    //const float _timeoutTime = .1;
    
    bool _fired = false;
};


#endif // RANGEDCOMBATCOMPONENT_H
