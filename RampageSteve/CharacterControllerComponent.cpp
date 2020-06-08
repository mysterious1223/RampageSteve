// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "CharacterControllerComponent.h"

CharacterControllerComponent::CharacterControllerComponent(Entity* entity) : Component (entity)
{
    // Maybe this should also take in the physics component?
  
}

CharacterControllerComponent::CharacterControllerComponent(Entity* entity, PhysicsBodyComponent* comp) : Component(entity)
{
    // for objects with physics
    phyBod = comp;
    printf("Linked to physics comp \n");
}

bool CharacterControllerComponent::init()
{


	return true;
}

void CharacterControllerComponent::update(float& dt)
{
    if (this->isSpaceDown)
    {
        this->phyBod->triggerJump();
    }
    if (this->isDDown)
    {
        this->phyBod->moveRight();
    }
    if (this->isADown)
    {
        this->phyBod->moveLeft();
    }
    

    
    if (!this->isADown && !this->isDDown)
    {
        this->phyBod->moveStop(dt);
    }
}
void CharacterControllerComponent::updateInput (float& dt, sf::Event* event)
{
    
    /*
        This will HANDLE all INPUT INCLUDE ATTACKS and will be linked to a attack component are something
     a pointer for this object will link it to attack
     
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
