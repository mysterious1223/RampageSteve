#include "GameMainMenuState.h"




GameMainMenuState::GameMainMenuState(std::vector<ConfigurationData*> res) : GameState(res) {
    
    
  
    if (!this->gameResources.empty())
    {
        // Resources loaded we can now assign them game objects
        // no character selectection as yet

        
        this->MainMenuLayout = new SFML_GUI::UI_Layouts::MainMenuFlowLayout (2, sf::Vector2f (1024/2, 768/2));
    
    
        
        for (auto& x : this->gameResources)
        {
         
            
            if (x->getEntityType() == EntityType::UI_Image)
            {
                if (x->getName() == "PlayButton")
                {
                    
                    this->PlayButtonTexture.loadFromFile(x->getResources()->path);
                    this->PlayButton = new SFML_GUI::GUI_items::MenuItem (&this->PlayButtonTexture);
                    this->MainMenuLayout->AddItem(this->PlayButton);
                 
                    
                    // We would need to create an instance of an object to pass pointer or use a static member not tied to class
                    
                    this->PlayButton->setOnClickCallBackFunction(GameMainMenuState::PlayGame);
                    
                }
                if (x->getName() == "QuitButton")
                {
                    
                    this->QuitButtonTexture.loadFromFile(x->getResources()->path);
                    this->QuitButton = new SFML_GUI::GUI_items::MenuItem (&this->QuitButtonTexture);
                    this->MainMenuLayout->AddItem(this->QuitButton);
                    
                    this->QuitButton->setOnClickCallBackFunction(GameMainMenuState::EndGame);
                }
            }
            
        }

    }
    else
    {
        printf("[!] Error, couldn't load\n");
        this->isEnd = true;
    }
}
void GameMainMenuState::PlayGame ()
{
    GameMainMenuState::IsMenuOver = true;
}
void GameMainMenuState::EndGame()
{
    GameState::isAppEnd = true;
}
// main state loop
bool GameMainMenuState::update(float& dt)
{
   // if (GameMainMenuState::isMenuOver)
   // {
   //     printf ("Game menu over\n");
   // }
    
    if (GameMainMenuState::IsMenuOver)
        this->isEnd = true;
    
    return true;
}


//Render loop
bool GameMainMenuState::render(sf::RenderTarget* target)
{
    this->MainMenuLayout->render(target);
    return true;
}

//input update
void GameMainMenuState::updateInput(float& dt, sf::Event* event)
{
    
    if (event->type == sf::Event::KeyPressed) {
        if (event->key.code == sf::Keyboard::Escape) {
            //printf("[+] End Main Menu State\n");
            this->isEnd = true;
        }
    }
    
    this->MainMenuLayout->updateInput(dt, event);
    
}
GameMainMenuState::~GameMainMenuState()
{
   
    
    if (this->MainMenuLayout != nullptr)
        delete this->MainMenuLayout;
    
    // Not sure if we need to clean up buttons (deleted in layout clean up)

}
