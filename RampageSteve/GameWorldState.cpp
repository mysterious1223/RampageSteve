// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "GameWorldState.h"





GameWorldState::GameWorldState(std::vector<ConfigurationData*> &res) : GameState(res), _gameEntities(std::vector<Entity*>()),
_projectiles(std::vector<Entity*>()), _instantiated_objects(std::vector<Entity*>()){

	printf("[+] Game World State initialized\n");



    
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
				//float i = 0;
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
                //std::unique_ptr <Entity> player(new Entity (x));
				Entity* player = new Entity(x);
				player->setPosition(sf::Vector2f(0,0));

    
				// test
				PhysicsBodyComponent* phybod = new PhysicsBodyComponent(player);
				//Component* control = new CharacterControllerComponent(player, phybod);
				CharacterControllerComponent* control = new CharacterControllerComponent(player, phybod);
                // collider
                ColliderComponent* collider = new ColliderComponent (player, phybod);
                // RangedCombat This will need to be added later
                RangedCombatComponent* ranged = new RangedCombatComponent (player,this->_instantiated_objects,true);
                
                // entity stats
                EntityStatsComponent* stats = new EntityStatsComponent (player);
                Stats_Container _stats_;
                
                _stats_._attack_dmg = 1;
                _stats_._health = 5;
                
                stats->setBaseStats(_stats_);
                
                
                if (!player->AddComponent(control)) {printf ("Player Error loading controller comp\n");}
                if (!player->AddComponent(phybod)) {printf ("Player Error loading phy comp\n");}
                if (!player->AddComponent(collider)) {printf ("Player Error loading coll comp\n");}
                if (!player->AddComponent(ranged)) {printf ("Player Error loading range comp\n");}
                if (!player->AddComponent(stats)) {printf ("Player Error loading stats comp\n");}
            
                // check if object contains a component
                //player->checkIfContainsComponent<ColliderComponent>();
                
              
                
                
                this->_gameEntities.push_back(player);
				// end of test
			}
            if (x->getEntityType() == EntityType::Enemy)
            {
                // this is enemy;
                
                Entity* enemy = new Entity(x);
                enemy->setPosition(sf::Vector2f(500,0));
                PhysicsBodyComponent* phybod = new PhysicsBodyComponent(enemy);
                ColliderComponent* collider = new ColliderComponent (enemy, phybod);
                
                // entity stats
                EntityStatsComponent* stats = new EntityStatsComponent (enemy);
                Stats_Container _stats_;
                
                _stats_._attack_dmg = 1;
                _stats_._health = 7;
                
                
                stats->setBaseStats(_stats_);
                
                
                if (!enemy->AddComponent(phybod)) {printf ("enemy Error loading phy comp\n");}
                if (!enemy->AddComponent(collider)) {printf ("enemy Error loading coll comp\n");}
                if (!enemy->AddComponent(stats)) {printf ("Player Error loading stats comp\n");}
                
                this->_gameEntities.push_back(enemy);
            }
            // Projectile set up
            if (x->getEntityType() == EntityType::Projectile)
            {
                // We will need to pass by ref our vector of game entities into Ranged
                // How can we do this? We will need to load all the resources then allocate player, then other items?
                // seperate config? no
                // We can store projectiles in there own array. Later in the init we can place projectile into our player range component
                // add to projectile list
                
                
                Entity *projectile = new Entity(x);
                //projectile->setPosition(sf::Vector2f(0,0));
                // a dummy projectile
                ProjectileComponent* proj_comp = new ProjectileComponent(projectile, 0.0f);
                //PhysicsBodyComponent* phybod = new PhysicsBodyComponent(projectile);
                //ColliderComponent* collider = new ColliderComponent (projectile, phybod);
                
                if(!projectile->AddComponent(proj_comp)){printf ("Projectile failed to be added\n");}
                //if(!projectile->AddComponent(phybod)){printf ("PHY failed to be added\n");}
                //if(!projectile->AddComponent(collider)){printf ("COLL failed to be added\n");}
                
                this->_projectiles.push_back(projectile); // this works for now, but what about enemies? they all share the same projectile? Create temp list. We can call init player? then include this? init enemies include this?
                // In init or something we will need to load projectile into ranged?
                // later we can select the different projectile types
                // We will need to add test items to the list
                
                
                // todo
                // in init or seperate function we will need to add the projectile list to ranged component, depending on
                // what object they belong to.
                
                
            }
		}

	}
	else
	{
		printf("[!] Error, couldn't load\n");
		this->isEnd = true;
	}


    if (!init())
    {
        this->isEnd = true;
    }
    

}
bool GameWorldState::init (){
    
    // init
    // load projectiles into player?
    
    if (!this->_projectiles.empty())
    {
    
        for (auto& obj : this->_gameEntities)
        {
            if (obj->_thisConfig->getEntityType() == EntityType::Player)
            {
                // this is player we only need to load projectiles into this object
                RangedCombatComponent* rngTemp = static_cast<RangedCombatComponent*>(obj->GetComponent<RangedCombatComponent>());
                
                if (rngTemp != nullptr)
                {
                    printf ("Loaded range combat component\n");
                    
                    if(!rngTemp->addProjectiles(this->_projectiles)){printf ("Error importing projectiles\n");}
                    
                }
                else{
                    printf ("Failed to load ranged combat component for configuration\n");
                }
            }
        }
    }
    else
    {
        printf ("No projectiles found...\n");
    }
    
    // start background on seperate thread?
    //std::thread background_thread (update_background());
    
    //background_thread.join();
    
    //std::thread gameplay_thread;
    
    
    
    printf ("[+] init game complete\n");
    return true;
}
/*
bool GameWorldState::update_background()
{
    sf::Clock clock;
    while (true)
    {
        sf::Time dt = clock.restart();
        if (!this->background->runActionsUpdate(dt.asSeconds())) {
            printf ("Failed to update background\n");
            break;
            
        }
        
        
    }
    
    return false;
}
*/
void GameWorldState::cleanDeletedEntities ()
{
    for (unsigned i = 0; i < this->_gameEntities.size(); i ++)
    {
        if (this->_gameEntities [i]->isEntityDeleted())
        {
            Entity *t_ptr = this->_gameEntities[i];
            
            this->_gameEntities.erase(this->_gameEntities.begin() + i);
            
            delete t_ptr;
        }
    }
    
}

bool GameWorldState::update(const float& dt)
{
    
    //printf ("%d\n", this->_gameEntities.size());

    // remove deleted entities
    cleanDeletedEntities ();
    
    
    

    
	//player->runActionsUpdate(dt);
	//background->runActionsUpdate(dt);
    
    // loop through our vector of game entities
    //
    
    if (!this->background->runActionsUpdate(dt)) {printf ("Failed to update background\n");}
    
    
    if (!this->_gameEntities.empty())
    {
        for (auto &a : this->_gameEntities)
        {
           
            //printf ("error? %p \n", a);
            
            // bugged call
            if (!a->runActionsUpdate(dt)) {printf ("Failed to update entity\n");}
            //printf ("over error? %p \n", a);
            // check if entity contains the collider component
            if (a->checkIfContainsComponent<ColliderComponent>())
            {
                 
                
                for (auto& entity : this->_gameEntities)
                {
                    // both must have collider
                    if (entity->checkIfContainsComponent<ColliderComponent>() && (entity->_parentEntity != a &&
                                                                                  a->_parentEntity != entity))
                    {
                        if (a != entity && a != NULL )
                        {
                            
                            
                                // Collision Will ONLY check for bullets tagged items
                                // there is a bug here that needs to be fixed
                                if (a->getGlobalBounds().intersects(entity->getGlobalBounds()))
                                {
                                    //printf ("Collision detected %s <-> %s\n", a->getName().c_str(), entity->getName().c_str());
                                    
                                    // Kill the entity that gets hit?
                                    if (a->checkIfContainsComponent<ProjectileComponent>())
                                    {
                                        // contains bullet
                                        printf ("Entity %s got hit\n", entity->getName().c_str());
                                        
                                        // IMPLEMENT STATS COMPONENT
                                        
                                        //a->_parentEntity->GetComponent<EntityStatsComponent>()
                                        if (entity->checkIfContainsComponent<EntityStatsComponent>())
                                        {
                                            
                                            EntityStatsComponent* thisstats = static_cast<EntityStatsComponent*>
                                            (a->_parentEntity->GetComponent<EntityStatsComponent>());//->attackEntity(entity);
                                            
                                            thisstats->attackEntity(entity);
                                            
                                            
                                            a->setIsDead();
                                        }
                                        
                                        // we can pull the health and deal damage?
                                        //entity->setIsDead();
                                        
                                        // destroy bullets no matter what
                                        
                                    }
                                    
                                }
                        }
                    }
                }
            }
            
            
        }
    }
    
    
    // We will check if has collider then check ? idk
    
    
    // slow as fuck
    if (!this->_instantiated_objects.empty())
    {
        this->_gameEntities.push_back(this->_instantiated_objects.back());
        this->_instantiated_objects.pop_back();
    }
 
	return true;
}



bool GameWorldState::render(sf::RenderTarget* target)
{
	
    //target->draw(*background);

	//target->draw(*player);


	//background->DrawThis(target);
	//player->DrawThis(target);

    if (!this->background->DrawThis(target)) {printf ("Failed to draw background\n");}
    
    
    for (auto &a : this->_gameEntities)
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

    for (auto &a : this->_gameEntities)
    {
        
        if (!a->runInputUpdate(dt, event)) {printf ("Failed to update entity input\n");}
    }
    
}

GameWorldState::~GameWorldState()
{
    
    // TEST ONLY
    
    //if (this->background != nullptr)
    delete this->background;
    if (!this->_gameEntities.empty())
    {
        for (auto &a : this->_gameEntities)
        {
            delete a;
        }
        this->_gameEntities.clear();
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
