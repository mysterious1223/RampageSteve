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

class Entity : public sf::Sprite
{
public:
    
    
	Entity(ConfigurationData* cf);
    Entity () {};


	~Entity();

	// Ability to add components (configured in here)
    [[nodiscard]]
	bool AddComponent(Component*);



    [[nodiscard]]
    bool runInputUpdate (const float& dt,sf::Event*);
    
	
	// maybe a run actions call to use components? [Overridable] - make this automatically call component updates?
    [[nodiscard]]
	bool runActionsUpdate(const float& dt);
    [[nodiscard]]
	bool DrawThis(sf::RenderTarget*);
  
    [[nodiscard]]
    const std::vector<Component*> getComponents ();
    [[nodiscard]]
    const std::string getName () {return this->_name;};
    
    // DEPRECIATED
    [[deprecated]]
    void RangedAttack (const sf::Vector2f &);
    
    //[[nodiscard]] // check if component exist WE WILL NEED TEMPATING
    template <typename T>
    [[nodiscard]] 
    inline const bool checkIfContainsComponent(){
        
        for (auto& comp : this->getComponents())
        {
            // get components holds pointers
            if (dynamic_cast<T*>(comp))
            {
                
                return true;
            }
            
        }
       
        return false;
    }
    
    // check if entity is deleted
    const bool& isEntityDeleted () const {return this->_isDead;}
    
    void setIsDead () {this->_isDead = true;}
    
private:

	std::vector <Component*> _entity_components;
    
    std::string _name;
    
    
    // Only works for integer positions along X or Y cant be used for range attacks. I think
    sf::Vector2f getDirection (const sf::Vector2f&) const;
    
    
    // is dead
    bool _isDead;
    
    //sf::RectangleShape borderRect;
};

#endif //ENTITY_H
