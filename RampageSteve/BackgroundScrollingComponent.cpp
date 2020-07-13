#include "BackgroundScrollingComponent.h"


BackgroundScrollingComponent::BackgroundScrollingComponent(Entity*& entity) : Component(entity)
{


	// The goal would be to eventually clone entity and have 2 of them
	//this->maxX = screenWidth;
    

    // We will create a collider component
   

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

    //printf ("width %f", this->thisEntity->getLocalBounds().width);
    
    this->maxX = this->thisEntity->getLocalBounds().width - 2;
    
    
	this->speed = -300;
    
    
   
    this->childInstance->setPosition(this->maxX, 0);
    this->thisEntity->setPosition(0, 0);
    

	return true;
}

void BackgroundScrollingComponent::update(const float& dt)
{
    
    
    
	this->thisEntity->move(this->speed * dt, 0);
    this->childInstance->move(speed * dt, 0);
    
    // check distance between both instance
    float dist = sqrt(
                      pow(this->childInstance->getPosition().x - this->thisEntity->getPosition().x, 2)
                          + pow(this->childInstance->getPosition().y - this->thisEntity->getPosition().y, 2)
                      ) - 1;
  
    
    printf ("Distance %f\n",dist);

	if (this->thisEntity->getPosition().x <= -this->maxX)
	{
        
        
		this->thisEntity->setPosition(dist, 0);
        //printf ("swapping for parent %f\n", this->thisEntity->getPosition().x);
	}
    
    if (this->childInstance->getPosition().x <= - dist)
    {
        this->childInstance->setPosition(dist, 0);
        //printf ("swapping for child %f\n", this->childInstance->getPosition().x);
    }
    
    
}



void BackgroundScrollingComponent::updateInput(const float&  dt, sf::Event*)
{
}

void BackgroundScrollingComponent::updateRender(sf::RenderTarget* target)
{
    if (!this->childInstance->DrawThis(target)) {printf ("Background failed to render\n");}
}

BackgroundScrollingComponent::~BackgroundScrollingComponent()
{
    if (this->childInstance != nullptr)
        delete this->childInstance;
}
