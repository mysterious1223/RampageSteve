#pragma once
#ifndef _PHYSICS_BODY_H_
#define _PHYSICS_BODY_H_

#include "Globals.h"

class PhysicsBodyComponent : public Component
{
public:
	PhysicsBodyComponent(Entity*&);

	// with pyhiscs Component
	// CharacterControllerComponent(Entity*);
    [[nodiscard]]
	bool init();

	void update(const float& dt);

	void updateInput(const float& dt, sf::Event*);

	void updateRender(sf::RenderTarget* target);


	// triggers
    [[nodiscard]]
	bool triggerJump();


	// Move right
    [[nodiscard]]
	bool moveRight();

	// Move left
    [[nodiscard]]
	bool moveLeft();


	// Stop Horizonal movement
    [[nodiscard]]
	bool moveStop(const float& dt);


	~PhysicsBodyComponent();
private:
	
	void AddDebugBorder();

	void ApplyForceToHorizontalVelocity(const int& dir);
	void StopForceToHorizontalVelocity(const float& dt);
	// gravity
	void applyGravity(const float& dt);

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
