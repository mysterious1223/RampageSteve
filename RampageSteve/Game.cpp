#include "Game.h"

Game::Game()
{

	this->viewSize = sf::Vector2f(1024, 768);
	sf::VideoMode vm(viewSize.x, viewSize.y);


	this->window = new sf::RenderWindow(vm, GAME_WINDOW_NAME, sf::Style::Default);
	this->dt = 0.f;

	sfEvent = sf::Event();



	this->initStates();

}

void Game::initStates()
{
	// push our game into the stack

	//GameWorldState* myState = new GameWorldState ();
    this->resources = resourceLoader->loadEntityResourceConfig(pathToConfig);

    this->states.push(new GameWorldState (resources));
    this->states.push(new GameMainMenuState (resources));
    
	
}

void Game::updateDT()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();

		if (!this->states.empty()) 
		{
			// pass input into
			this->states.top()->updateInput(this->dt, &this->sfEvent);
		}
		// GLOBAL inputs? like cntrl alt delete?
		
	}
}

void Game::MainUpdate()
{
	this->updateEvents();

	// add state check here
	// State loops
	if (!this->states.empty())
	{
		if (!this->states.top()->update(this->dt))
		{
			// if false we should call the clean up and crash

			printf("[!] State has encountered an issue");
			// trigger clean up
		}

		if (this->states.top()->isStateEnd())
		{
			printf("[+] State trigger shut down \n");


			//delete current state and save its values
			// clean this up
			auto& temp = this->states.top();

			delete temp;

			this->states.pop();

		}
		if (GameState::isAppEnd)
		{
			printf("App is ending!\n");

			if (!this->EndGame())
			{
				printf("Game Can't end!\n");
			}
		}

	}

	if (this->states.empty()) {
		printf("[!] Failed no states running...\n");
		this->isApplicationEnd = true;
	}
}

void Game::render()
{
	// drawings
	this->window->clear(sf::Color::Black);

	if (!this->states.empty())
	{
		if (!this->states.top()->render(this->window))
		{
			printf("[!] Error rendering a state\n");
		}
	}
	this->window->display();
}

void Game::run()
{
	while (window->isOpen()) {
		this->updateDT();
		this->MainUpdate();
		this->render();

		if (this->isApplicationEnd)
		{
			break;
		}
	}
}

Game::~Game()
{
    /*
    if (!this->resources.empty())
    {
        for (auto& element : this->resources)
        {
            delete element;
        }
        
    }
    */
	if (resourceLoader != nullptr)
		delete resourceLoader;

	while (!this->states.empty())
	{
		auto& temp =  this->states.top();

		delete temp;

		this->states.pop();


	}
	if (window != nullptr)
	{
		delete window;
	}

	printf("[!!!] GAME TERMINATED\n");
}

bool Game::EndGame()
{
	printf("Cleaning up and ending game\n");

	while (!this->states.empty())
	{
		auto& temp = this->states.top();

		delete temp;

		this->states.pop();

	}


	return true;
}
