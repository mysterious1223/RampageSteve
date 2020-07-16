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
    Projectile,
	None

};

typedef struct {
    unsigned int _health;
    unsigned int _attackDmg;
    
    
    // other things can be kept
    
} Entity_stats;

class Entity : public sf::Sprite
{
public:
    
    
    // we need a copy constructor for this?
    
	Entity(ConfigurationData*& cf);
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
            if (dynamic_cast<T*>(comp) != nullptr)
            {
                
                return true;
            }
            
        }
       
        return false;
    }
    template <typename T>
    [[nodiscard]]
    inline Component* GetComponent(){
        
        for (auto& comp : this->getComponents())
        {
            // get components holds pointers
            if (dynamic_cast<T*>(comp) != nullptr)
            {
                
                return comp;
            }
            
        }
       
        return nullptr;
    }
    // DOES NOT DELETE POINTERS DONT USE THIS Unless instantiation is taking place
    void clearComponents ();
    
    // check if entity is deleted
    const bool& isEntityDeleted () const {return this->_isDead;}
    
    void setIsDead () {this->_isDead = true;}
    
    void setParentEntity (Entity*& entity) {this->_parentEntity = entity;};
    
    
    
private:

	std::vector <Component*> _entity_components;
    
    std::string _name;
    
    
    // Only works for integer positions along X or Y cant be used for range attacks. I think
    sf::Vector2f getDirection (const sf::Vector2f&) const;
    
    //config
    ConfigurationData* _thisConfig;
    
    
    // is dead
    bool _isDead;
    
    // parent Entity
    Entity* _parentEntity;
    
    
   
    
    //sf::RectangleShape borderRect;
    friend class GameWorldState;
};

#endif //ENTITY_H
