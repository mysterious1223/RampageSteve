#pragma once
#ifndef _PHYSICS_BODY_H_
#define _PHYSICS_BODY_H_

#include "Globals.h"

class PhysicsBodyComponent : public Component
{
public:
	PhysicsBodyComponent(Entity*);

	// with pyhiscs Component
	// CharacterControllerComponent(Entity*);

	bool init();

	void update(float& dt);

	void updateInput(float& dt, sf::Event*);

	void updateRender(sf::RenderTarget* target);


	// triggers
	bool triggerJump();


	// Move right
	bool moveRight();

	// Move left
	bool moveLeft();


	// Stop Horizonal movement
	bool moveStop(float& dt);


	~PhysicsBodyComponent();
private:
	
	void AddDebugBorder();

	void ApplyForceToHorizontalVelocity(int dir);
	void StopForceToHorizontalVelocity(float& dt);
	// gravity
	void applyGravity(float& dt);

	// assume it is grounded
	bool isGrounded = false;

	float horizontal_velocity = 0.0f;
	float vertical_velocity = 0.0f;
	float speed = 150;
	float jump_vel = 410;
	float mass = 75;
	const float gravity_rate = 9.80f;
	
	float dampening = 1;

	// if jump is triggered this should be called
	bool isJump = false;
	//sf::Rect borderRect;
	sf::RectangleShape borderRect;


	// temp ground static position
	float groundY = 500;

};



#endif // _PHYSICS_BODY_H_