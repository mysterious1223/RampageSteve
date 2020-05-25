#include "BackgroundScrollingComponent.h"


BackgroundScrollingComponent::BackgroundScrollingComponent(Entity* entity, float& screenWidth) : Component(entity)
{


	// The goal would be to eventually clone entity and have 2 of them
	this->maxX = screenWidth;
    
    

}

bool BackgroundScrollingComponent::init()
{
    
    // to create two new versions of entity we might need to use operator overloading

    // or create another sprite? Enity will contain a list of sprites?
    //this->childInstance = new Entity (*entity);
    
    //we need a copy consctructor
    //memcpy(this->childInstance, entity, sizeof(entity));
    
    // Copy the value to a new pointer
    this->childInstance = new Entity();
    *this->childInstance = *this->thisEntity;

    
    
    
	this->speed = -300;
    
    
   
    this->childInstance->setPosition(this->maxX, 0);
    this->thisEntity->setPosition(0, 0);
    

	return true;
}

void BackgroundScrollingComponent::update(float& dt)
{
    
    
    
	this->thisEntity->move(this->speed *dt, 0);
    this->childInstance->move(speed * dt, 0);
    
    
  
    

	if (this->thisEntity->getPosition().x <= -this->maxX)
	{
        
        
		this->thisEntity->setPosition(this->maxX, 0);
        printf ("swapping for parent %f\n", this->thisEntity->getPosition().x);
	}
    
    if (this->childInstance->getPosition().x <= -this->maxX)
    {
        this->childInstance->setPosition(this->maxX, 0);
        printf ("swapping for child %f\n", this->childInstance->getPosition().x);
    }
    
    
}



void BackgroundScrollingComponent::updateInput(float& dt, sf::Event*)
{
}

void BackgroundScrollingComponent::updateRender(sf::RenderTarget* target)
{
    this->childInstance->DrawThis(target);
}

BackgroundScrollingComponent::~BackgroundScrollingComponent()
{
    if (this->childInstance != nullptr)
        delete this->childInstance;
}
