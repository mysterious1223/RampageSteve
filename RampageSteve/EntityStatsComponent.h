/*
    Author: Kevin Singh
    
    This class for now will symbolically classify an entity of it is collidable. The check will be done in GameState.

    Holds statistic info on entity
 
 */

#pragma once
#ifndef ENTITYSTATSCOMPONENT_H
#define ENTITYSTATSCOMPONENT_H
#include "Globals.h"


struct Stats_Container{
    
    Stats_Container () : _health (0), _attack_dmg (0), _speed (0) {};
    unsigned _health;
    unsigned _attack_dmg;
    unsigned _speed;
    
};


class Component;
class EntityStatsComponent : public Component
{
public:
	EntityStatsComponent(Entity*&);

    [[nodiscard]]
	bool init();

	void update(const float& dt);

	void updateInput(const float& dt, sf::Event*);

	void updateRender(sf::RenderTarget* target);
    
    // STATS INIT
    void setBaseStats (const Stats_Container&);
    
    // get stats
    inline const Stats_Container& getBaseStats ()
    {
        
        return this->_stats;
        
    }
    // Take dmg
    const float dealDmgToThis (const unsigned&);
    
    // Deal dmg
    bool attackEntity (Entity*&);
    

	~EntityStatsComponent();
    
   
    
private:

    
    
    Stats_Container _stats;
    
    
};


#endif // ENTITYSTATSCOMPONENT_H
