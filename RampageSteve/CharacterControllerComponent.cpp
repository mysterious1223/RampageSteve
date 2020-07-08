// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "CharacterControllerComponent.h"

CharacterControllerComponent::CharacterControllerComponent(Entity*& entity) : Component (entity)
{
    // Maybe this should also take in the physics component?
  
}

CharacterControllerComponent::CharacterControllerComponent(Entity*& entity, PhysicsBodyComponent* comp) : Component(entity)
{
    // for objects with physics
    phyBod = comp;
    printf("Linked to physics comp \n");
}

bool CharacterControllerComponent::init()
{
	return true;
}

void CharacterControllerComponent::update(const float& dt)
{
    
    // combat componenets should be controlled by themselves
    //if (this->isMouseClicked)
    //{
        // trigger the attack
        // maybe change this so that it triggers ranged attacks?
        // Not sure how we should do this
        //this->thisEntity->RangedAttack(this->mouseClickedLocation);
        
    //}
    
    if (this->isSpaceDown)
    {
        if (!this->phyBod->triggerJump()) {printf ("Failed to trigger jump\n");}
    }
    if (this->isDDown)
    {
        if (!this->phyBod->moveRight()) {printf ("Failed to trigger move right\n");}
        
    }
    if (this->isADown)
    {
        if (!this->phyBod->moveLeft()) {printf ("Failed to trigger move left\n");}
       
    }
    


    
    if (!this->isADown && !this->isDDown)
    {
        if (!this->phyBod->moveStop(dt)) {printf ("Failed to stop\n");}
        
     
    }
}
void CharacterControllerComponent::updateInput (const float& dt, sf::Event* event)
{
    
    /*
        This will HANDLE all INPUT INCLUDE ATTACKS and will be linked to a attack component are something
     a pointer for this object will link it to attack
     
     */
    /*
    if (event->type == sf::Event::MouseButtonPressed)
    {
        //float mX = (float) event->mouseButton.x;
        //float mY = (float) event->mouseButton.y;
        this->mouseClickedLocation = sf::Vector2f (event->mouseButton.x, event->mouseButton.y);
        
        this->isMouseClicked = true;
    }
    if (event->type == sf::Event::MouseButtonReleased)
    {
        //float mX = (float) event->mouseButton.x;
        //float mY = (float) event->mouseButton.y;
        
        
        this->isMouseClicked = false;
    }
    */
    
    if (event->type == sf::Event::KeyPressed)
    {
        if (event->key.code == sf::Keyboard::D)
        {
            this->isDDown = true;
        }
        if (event->key.code == sf::Keyboard::A)
        {
            this->isADown = true;
        }
        if (event->key.code == sf::Keyboard::W)
        {
            this->isWDown = true;
        }
        if (event->key.code == sf::Keyboard::S)
        {
            this->isSDown = true;
        }


        if (event->key.code == sf::Keyboard::Space)
        {
            this->isSpaceDown = true;
        }
    }
    
    
    if (event->type == sf::Event::KeyReleased)
    {
        if (event->key.code == sf::Keyboard::D)
        {
            this->isDDown = false;
        }
        if (event->key.code == sf::Keyboard::A)
        {
            this->isADown = false;
        }
        if (event->key.code == sf::Keyboard::W)
        {
            this->isWDown = false;
        }
        if (event->key.code == sf::Keyboard::S)
        {
            this->isSDown = false;
        }

        if (event->key.code == sf::Keyboard::Space)
        {
            this->isSpaceDown = false;
        }
    }
    /*
    
    if (event.type == sf::Event::MouseMoved)
    {
        //printf("new mouse x,y: %d,%d\n", event.mouseMove.x, event.mouseMove.y);
        //heroSprite.setScale(-1, 1);

        if (event.mouseMove.x<PlayerPosition.x)
            heroSprite.setScale(-1, 1);
        if(event.mouseMove.x > PlayerPosition.x)
            heroSprite.setScale(1, 1);
    }
    if (event.type == sf::Event::MouseLeft)
    {
        printf("mouse left\n");
    }    //printf("mouse left\n");

    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            printf("click mouse x,y: %d,%d\n", event.mouseButton.x, event.mouseButton.y);

        }
    }
     
     
     */
}

void CharacterControllerComponent::updateRender(sf::RenderTarget* target)
{
}

CharacterControllerComponent::~CharacterControllerComponent()
{
    
}
