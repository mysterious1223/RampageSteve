#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include "Globals.h"

class Component;
enum class ObjectType;
enum class EntityType;

enum class ObjectType {
	Dynamic,
	Static,
    Scenery,
	None

};
enum class EntityType {
	Player,
	Enemy,
	Background,
	Platform,
    StaticBackground,
	None

};

// Should this be a virtual class?
class Entity : public sf::Sprite
{
public:
	Entity(ConfigurationData* cf);
    Entity () {};


	~Entity();

	// Ability to add components (configured in here)
	bool AddComponent(Component*);



    
    bool runInputUpdate (float& dt,sf::Event*);
    
	
	// maybe a run actions call to use components? [Overridable] - make this automatically call component updates?
	bool runActionsUpdate(float& dt);
    
	bool DrawThis(sf::RenderTarget*);
  

    const std::vector<Component*> getComponents ();
    
private:

	std::vector <Component*> entity_components;
};

#endif //ENTITY_H
