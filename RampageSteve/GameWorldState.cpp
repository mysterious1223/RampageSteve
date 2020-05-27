#include "GameWorldState.h"





GameWorldState::GameWorldState(sf::Vector2f& viewSize, std::vector<ConfigurationData*> res) : GameState(viewSize, res) {

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
				float i = 0;
				BackgroundScrollingComponent* bck = new BackgroundScrollingComponent(background, viewSize.x);

				background->AddComponent(bck);
            }
            
			if (x->getEntityType() == EntityType::Player)
			{
				// player config
				player = new Entity(x);
				player->setPosition(sf::Vector2f(0,0));


				// test
				PhysicsBodyComponent* phybod = new PhysicsBodyComponent(player);
				//Component* control = new CharacterControllerComponent(player, phybod);
				CharacterControllerComponent* control = new CharacterControllerComponent(player, phybod);

				player->AddComponent(control);
				player->AddComponent(phybod);

				// end of test
			}
		}

	}
	else
	{
		printf("[!] Error, couldn't load\n");
		this->isEnd = true;
	}




}


bool GameWorldState::update(float& dt)
{

	player->runActionsUpdate(dt);
	background->runActionsUpdate(dt);
    
 
	return true;
}

bool GameWorldState::render(sf::RenderTarget* target)
{
	
    //target->draw(*background);

	//target->draw(*player);


	background->DrawThis(target);
	player->DrawThis(target);

	return true;
}

void GameWorldState::updateInput(float& dt, sf::Event* event)
{

    
    // Global input events PAUSE etc.
	if (event->type == sf::Event::KeyPressed) {
		if (event->key.code == sf::Keyboard::Escape) {
			printf("[+] ESC clicked\n");
			this->isEnd = true;
		}
	}
    
    
    
    player->runInputUpdate(dt, event);

    
    
}

GameWorldState::~GameWorldState()
{
    
    // TEST ONLY
    if (player != nullptr)
        delete player;
    if (background != nullptr)
    delete background;
    
    if (!this->gameResources.empty())
    {
        for (auto&gr : this->gameResources)
        {
            delete gr;
        }
        this->gameResources.clear();
    }
}
