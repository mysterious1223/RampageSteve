// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "GameWorldState.h"





GameWorldState::GameWorldState(std::vector<ConfigurationData*> &res) : GameState(res) {

	printf("[+] Game World State initialized\n");


    this->GameEntities = std::vector<Entity*>();

    
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

				if (!background->AddComponent(bck))
                {
                    printf ("Failed!\n");
                }
                
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
                RangedCombatComponent* ranged = new RangedCombatComponent (player,true);
                
                if (!player->AddComponent(control)) {printf ("Player Error loading controller comp\n");}
                if (!player->AddComponent(phybod)) {printf ("Player Error loading phy comp\n");}
                if (!player->AddComponent(collider)) {printf ("Player Error loading coll comp\n");}
                if (!player->AddComponent(ranged)) {printf ("Player Error loading range comp\n");}
		
            
                // check if object contains a component
                //player->checkIfContainsComponent<ColliderComponent>();
                
                this->GameEntities.push_back(player);
				// end of test
			}
            if (x->getEntityType() == EntityType::Enemy)
            {
                // this is enemy;
                
                Entity* enemy = new Entity(x);
                enemy->setPosition(sf::Vector2f(500,0));
                PhysicsBodyComponent* phybod = new PhysicsBodyComponent(enemy);
                ColliderComponent* collider = new ColliderComponent (enemy, phybod);
                
                
                
                if (!enemy->AddComponent(phybod)) {printf ("enemy Error loading phy comp\n");}
                if (!enemy->AddComponent(collider)) {printf ("enemy Error loading coll comp\n");}
                
                this->GameEntities.push_back(enemy);
            }
		}

	}
	else
	{
		printf("[!] Error, couldn't load\n");
		this->isEnd = true;
	}




}

void GameWorldState::cleanDeletedEntities ()
{
    for (unsigned i = 0; i < this->GameEntities.size(); i ++)
    {
        if (this->GameEntities [i]->isEntityDeleted())
        {
            Entity *t_ptr = this->GameEntities[i];
            
            this->GameEntities.erase(this->GameEntities.begin() + i);
            
            delete t_ptr;
        }
    }
    
}

bool GameWorldState::update(const float& dt)
{

    // remove deleted entities
    cleanDeletedEntities ();
    
	//player->runActionsUpdate(dt);
	//background->runActionsUpdate(dt);
    
    // loop through our vector of game entities
    //
    
    if (!this->background->runActionsUpdate(dt)) {printf ("Failed to update background\n");}
    
    
    
    for (auto &a : this->GameEntities)
    {
        if (!a->runActionsUpdate(dt)) {printf ("Failed to update entity\n");}
        
        // check if entity contains the collider component
        if (a->checkIfContainsComponent<ColliderComponent>())
        {
            for (auto& entity : this->GameEntities)
            {
                
                if (a != entity)
                {
                    
                    // Collision Will ONLY check for bullets tagged items
                    
                    if (a->getGlobalBounds().intersects(entity->getGlobalBounds()))
                    {
                        printf ("Collision detected %s <-> %s\n", a->getName().c_str(), entity->getName().c_str());
                        
                        if (a->getName() == "")
                        {
                            
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

    if (!this->background->DrawThis(target)) {printf ("Failed to draw background\n");}
    
    
    for (auto &a : this->GameEntities)
    {
        if (!a->DrawThis(target)) {printf ("Failed to draw entity\n");}
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

    for (auto &a : this->GameEntities)
    {
        
        if (!a->runInputUpdate(dt, event)) {printf ("Failed to update entity input\n");}
    }
    
}

GameWorldState::~GameWorldState()
{
    
    // TEST ONLY
    
    //if (this->background != nullptr)
    delete this->background;
    if (!this->GameEntities.empty())
    {
        for (auto &a : this->GameEntities)
        {
            delete a;
        }
        this->GameEntities.clear();
        //delete this->GameEntities;
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
