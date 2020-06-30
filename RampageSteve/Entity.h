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
    UI,
	None

};
enum class EntityType {
	Player,
	Enemy,
	Background,
	Platform,
    StaticBackground,
    UI_Image,
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



    
    bool runInputUpdate (const float& dt,sf::Event*);
    
	
	// maybe a run actions call to use components? [Overridable] - make this automatically call component updates?
	bool runActionsUpdate(const float& dt);
    
	bool DrawThis(sf::RenderTarget*);
  

    const std::vector<Component*> getComponents ();
    
    const std::string getName () {return this->name;};
    
    
    void RangedAttack (const sf::Vector2f &);
    
    
private:

	std::vector <Component*> entity_components;
    
    std::string name;
    
    
    // Only works for integer positions along X or Y cant be used for range attacks. I think
    sf::Vector2f getDirection (const sf::Vector2f&) const;
    
    
    //sf::RectangleShape borderRect;
};

#endif //ENTITY_H
