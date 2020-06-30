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

	void update(const float& dt);
    
    void updateInput (const float& dt, sf::Event*);

    void updateRender(sf::RenderTarget* target);

	~CharacterControllerComponent();
private:
   
    
    bool isDDown = false;
    bool isADown = false;
    bool isSDown = false;
    bool isWDown = false;
    
    bool isSpaceDown = false;
    
    bool isMouseClicked = false;
    sf::Vector2f mouseClickedLocation;
    
    PhysicsBodyComponent* phyBod = nullptr;
    
};


#endif // _CHARACTERCONTROLLERCOMPONENT_H_

