#pragma once
#ifndef _CHARACTERCONTROLLERCOMPONENT_H_
#define _CHARACTERCONTROLLERCOMPONENT_H_
#include "Globals.h"

class Component;
class PhysicsBodyComponent;
class CharacterControllerComponent : public Component
{
public:

    CharacterControllerComponent(Entity*);
	CharacterControllerComponent(Entity*, PhysicsBodyComponent* comp);

    // with pyhiscs Component
    // CharacterControllerComponent(Entity*);

	bool init();

	void update(float& dt);
    
    void updateInput (float& dt, sf::Event*);

    void updateRender(sf::RenderTarget* target);

	~CharacterControllerComponent();
private:
   
    
    bool isDDown = false;
    bool isADown = false;
    bool isSDown = false;
    bool isWDown = false;
    
    bool isSpaceDown = false;
    PhysicsBodyComponent* phyBod = nullptr;
    
};


#endif // _CHARACTERCONTROLLERCOMPONENT_H_

