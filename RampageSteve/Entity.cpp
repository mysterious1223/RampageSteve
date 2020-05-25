#include "Entity.h"

Entity::Entity(ConfigurationData* cf) : sf::Sprite (cf->getResources()->thisTexture)
{
	this->entity_components = std::vector <Component*>();
}

bool Entity::AddComponent(Component* comp)
{

	if (comp->init())
	{
		this->entity_components.push_back(comp);

		return true;
	}

	return false;
}

bool Entity::runInputUpdate (float& dt,sf::Event* event)
{
    for (auto& c : this->entity_components)
    {
        c->updateInput(dt, event);
    }


	return true;
}

bool Entity::runActionsUpdate(float& dt)
{
	
	for (auto& c : this->entity_components)
	{
		c->update(dt);
	}



	return true;
}

bool Entity::DrawThis(sf::RenderTarget* target)
{

	for (auto& c : this->entity_components)
	{
		c->updateRender(target);
	}




	target->draw(*this);




	return true;
}

Entity::~Entity()
{
	// remove the entity vector

	if (!this->entity_components.empty())
	{
		for (auto& c : this->entity_components)
		{
			delete c;
			
		}
		this->entity_components.clear();
	}
}
