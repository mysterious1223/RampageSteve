#include "PhysicsBodyComponent.h"

PhysicsBodyComponent::PhysicsBodyComponent(Entity* entity) : Component (entity)
{

}

bool PhysicsBodyComponent::init()
{
	// init calls
	// called when component is added to entity

	// MIGHT CAUSE ERROR WHEN LINKING CONTROLLER TO THIS OBJECT, BUT HOPEFULLY THE POINTER DOESNT RETURN THREAD ERRORs
	

	// needs to be drawn using plan in notebook
	borderRect = sf::RectangleShape (sf::Vector2f(this->thisEntity->getLocalBounds().width, this->thisEntity->getLocalBounds().height));
	

	// add color to border
	AddDebugBorder();


	

	return true;
}

void PhysicsBodyComponent::update(float& dt)
{

	//this->ApplyForceToHorizontalVelocity(-1);


	// debug
	borderRect.setPosition(this->thisEntity->getPosition());


	
	sf::Vector2f EntityPosition = this->thisEntity->getPosition();
	// physics calculation and updates


	// return false if cant
	applyGravity(dt);

	EntityPosition.y -= this->vertical_velocity * dt;
	EntityPosition.x += this->horizontal_velocity * dt;




	// must be at end
	// check DEBUG TEST WE WILL USE PHYSICS for this later
	if (EntityPosition.y >= groundY)
	{
		this->isGrounded = true;
	}
		
	
	this->thisEntity->setPosition(EntityPosition);
}

void PhysicsBodyComponent::updateInput(float& dt, sf::Event*)
{
}

void PhysicsBodyComponent::updateRender(sf::RenderTarget* target)
{
	// debug
	target->draw(borderRect);

}

bool PhysicsBodyComponent::triggerJump()
{

	//printf("Jump\n");

	this->vertical_velocity = this->jump_vel;
	this->isGrounded = false;
	
	return true;
}

bool PhysicsBodyComponent::moveRight()
{
	this->ApplyForceToHorizontalVelocity(1);

	return true;
}

bool PhysicsBodyComponent::moveLeft()
{
	this->ApplyForceToHorizontalVelocity(-1);
	return true;
}

bool PhysicsBodyComponent::moveStop(float& dt)
{


	// research drag?
	this->StopForceToHorizontalVelocity(dt);
	return true;
}

PhysicsBodyComponent::~PhysicsBodyComponent()
{

}

void PhysicsBodyComponent::AddDebugBorder()
{

	borderRect.setFillColor(sf::Color(255, 0, 0, 255));
}

void PhysicsBodyComponent::ApplyForceToHorizontalVelocity(int dir)
{
	this->horizontal_velocity = (this->speed * dir);
}

void PhysicsBodyComponent::StopForceToHorizontalVelocity(float &dt)
{

	
	this->horizontal_velocity -= this->horizontal_velocity * dampening * dt;
}

void PhysicsBodyComponent::applyGravity(float& dt)
{

	// Dont apply gravity if it is grounded

	if (!this->isGrounded)
		this->vertical_velocity -= this->mass * this->gravity_rate * dt;
	else
		this->vertical_velocity = 0;

	
}
