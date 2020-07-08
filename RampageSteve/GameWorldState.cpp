// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "GameWorldState.h"





GameWorldState::GameWorldState(std::vector<ConfigurationData*> &res) : GameState(res) {

	printf("[+] Game World State initialized\n");


    this->GameEntities = new std::vector<Entity*>();

    
	// We will prob have a player selection screen. We should create the functionality without implemenation. We can then use this array
	// Game State can have player selection?

	if (!this->gameResources.empty())
	{
		// Resources loaded we can now assign them game objects
		// no character selectection as yet

		for (auto& x : this->gameResources)
		{
            //1024, 768
            
            
            if (x->getEntityType() == EntityType::Background)
            {
                background = new Entity (x);
                //background->setPosition(1024, 768/2);
				float i = 0;
				BackgroundScrollingComponent* bck = new BackgroundScrollingComponent(background);

				background->AddComponent(bck);
                
                //this->GameEntities->push_back(background);
                
            }
            
			if (x->getEntityType() == EntityType::Player)
			{
				// player config
				Entity* player = new Entity(x);
				player->setPosition(sf::Vector2f(0,0));


				// test
				PhysicsBodyComponent* phybod = new PhysicsBodyComponent(player);
				//Component* control = new CharacterControllerComponent(player, phybod);
				CharacterControllerComponent* control = new CharacterControllerComponent(player, phybod);
                // collider
                ColliderComponent* collider = new ColliderComponent (player, phybod);
                // RangedCombat
                RangedCombatComponent* ranged = new RangedCombatComponent (player,control);
                
				player->AddComponent(control);
				player->AddComponent(phybod);
                player->AddComponent(collider);
                player->AddComponent(ranged);
                
                
                this->GameEntities->push_back(player);
				// end of test
			}
            if (x->getEntityType() == EntityType::Enemy)
            {
                // this is enemy;
                
                Entity* enemy = new Entity(x);
                enemy->setPosition(sf::Vector2f(500,0));
                PhysicsBodyComponent* phybod = new PhysicsBodyComponent(enemy);
                ColliderComponent* collider = new ColliderComponent (enemy, phybod);
                
                
                
                enemy->AddComponent(phybod);
                enemy->AddComponent(collider);
                
                this->GameEntities->push_back(enemy);
            }
		}

	}
	else
	{
		printf("[!] Error, couldn't load\n");
		this->isEnd = true;
	}




}


bool GameWorldState::update(const float& dt)
{

	//player->runActionsUpdate(dt);
	//background->runActionsUpdate(dt);
    
    // loop through our vector of game entities
    //
    
    this->background->runActionsUpdate(dt);
    
    
    
    for (auto &a : *this->GameEntities)
    {
        a->runActionsUpdate(dt);
        
        for (auto obj : a->getComponents())
        {
           
            
            if (dynamic_cast<ColliderComponent*>(obj))
            {
                //printf ("contains a collider\n");
                
                //works
                
                
                //if contains collider we can perform physics actions
                for (auto& entity : *this->GameEntities)
                {
                    
                    if (a != entity)
                    {
                        
                        // Collision Will ONLY check for bullets tagged items
                        
                        if (a->getGlobalBounds().intersects(entity->getGlobalBounds()))
                        {
                            printf ("Collision occured %s <-> %s\n", a->getName().c_str(), entity->getName().c_str());
                            
                            
                            
                        }
                    }
                }
                
                
                
            }
        }
        
    }
    
    
    // We will check if has collider then check ? idk
    
    
    
 
	return true;
}



bool GameWorldState::render(sf::RenderTarget* target)
{
	
    //target->draw(*background);

	//target->draw(*player);


	//background->DrawThis(target);
	//player->DrawThis(target);

    this->background->DrawThis(target);
    
    
    for (auto &a : *this->GameEntities)
    {
        a->DrawThis(target);
    }
    
	return true;
}

void GameWorldState::updateInput(const float& dt, sf::Event* event)
{

    
    // Global input events PAUSE etc.
	if (event->type == sf::Event::KeyPressed) {
		if (event->key.code == sf::Keyboard::Escape) {
			printf("[+] ESC clicked\n");
			this->isEnd = true;
		}
	}
    
    //this->background->runInputUpdate(dt, event);
    
    //player->runInputUpdate(dt, event);

    for (auto &a : *this->GameEntities)
    {
        a->runInputUpdate(dt, event);
    }
    
}

GameWorldState::~GameWorldState()
{
    
    // TEST ONLY
    
    //if (this->background != nullptr)
    delete this->background;
    if (!this->GameEntities->empty())
    {
        for (auto &a : *this->GameEntities)
        {
            delete a;
        }
        this->GameEntities->clear();
        delete this->GameEntities;
    }
    if (!this->gameResources.empty())
    {
        for (auto&gr : this->gameResources)
        {
            delete gr;
        }
        this->gameResources.clear();
    }
}
