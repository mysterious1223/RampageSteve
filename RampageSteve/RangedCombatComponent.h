/*
    Author: Kevin Singh
    
    This class for now will give an entity RangedCombatComponent

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
	RangedCombatComponent(Entity*);
    RangedCombatComponent(Entity*, CharacterControllerComponent*);
	bool init();

	void update(const float& dt);

	void updateInput(const float& dt, sf::Event*);

	void updateRender(sf::RenderTarget* target);

	~RangedCombatComponent();
private:

    CharacterControllerComponent * _controller;
};


#endif // RANGEDCOMBATCOMPONENT_H
