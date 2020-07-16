// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Entity.h"

Entity::Entity(ConfigurationData*& cf) : sf::Sprite (cf->getResources()->thisTexture), _entity_components(std::vector<Component*>()), _name(cf->getName()),_thisConfig (cf),_isDead(false) , _parentEntity (nullptr)

{
 

}

bool Entity::AddComponent(Component* comp)
{

	if (comp->init())
	{
		this->_entity_components.push_back(comp);

		return true;
	}

	return false;
}

bool Entity::runInputUpdate (const float& dt,sf::Event* event)
{
    if (!this->_entity_components.empty())
    {
        for (auto& c : this->_entity_components)
        {
            c->updateInput(dt, event);
        }
    }

	return true;
}

bool Entity::runActionsUpdate(const float& dt)
{
	
    if (!this->_entity_components.empty())
    {
        for (auto& c : this->_entity_components)
        {
            
            c->update(dt);
        }
    }

    
    

	return true;
}

bool Entity::DrawThis(sf::RenderTarget* target)
{

    if (!this->_entity_components.empty())
    {
        for (auto& c : this->_entity_components)
        {
            c->updateRender(target);
        }

    }


	target->draw(*this);




	return true;
}

const std::vector<Component*> Entity::getComponents() 
{
    return this->_entity_components;
}
// DEPRECIATED
[[deprecated]]
void Entity::RangedAttack (const sf::Vector2f & mPos){
    // We now have the attack position. We need to translate it to a direction
    
    sf::Vector2f dir = this->getDirection(mPos);
    
    
    //printf ("This Entity %f, %f Target %f, %f\n", this->getPosition().x, this->getPosition().y,
      //      mPos.x, mPos.y);
    
    //borderRect = sf::RectangleShape (sf::Vector2f(30, 30));
    //borderRect.setFillColor(sf::Color(255, 0, 0, 255));
    
    
    printf ("Ranged attack at %f, %f\n", dir.x, dir.y);
    
    //borderRect.move(dir.x, dir.y);
}


sf::Vector2f Entity::getDirection (const sf::Vector2f& end_position) const
{
    float h = 0;
    float v = 0;
    
    float x = (end_position.x - this->getPosition().x);
    float y = (end_position.y - this->getPosition().y);
    
    if (x != 0)
    {
            //h = round(x/x);

        h = x / abs(x);


    }
    else
        h = 0;

    if (y != 0)
    {
        v = y / abs(y);
    }
    else
        v = 0;





    return sf::Vector2f(h, v);
    
    
}
// DOES NOT DELETE POINTERS DONT USE THIS Unless instantiation is taking place
void Entity::clearComponents (){
    if (!this->_entity_components.empty())
    {
        
        this->_entity_components.clear();
    }
    
}

Entity::~Entity()
{
    printf ("[-] Destruction called on %p, %s\n", this,this->getName().c_str());
    
	// remove the entity vector

	if (!this->_entity_components.empty())
	{
		for (auto& c : this->_entity_components)
		{
			delete c;
			
		}
		this->_entity_components.clear();
	}
}
/*
template <typename T>
T Entity::checkIfContainsComponent(T val)
{
    //for (auto& comp : this->getComponents())
    //{
      //  if (dynamic_cast<T>(comp))
        //{
          //  return true;
        //}
    //}
    //return false;
    return nullptr;
}
*/
/*
 GetDirection(cocos2d::Vec2 endPoint)
 {
     

     float h = 0;
     float v = 0;

     float x = round(endPoint.x - getPosition().x);
     float y = round(endPoint.y - getPosition().y);




     if (x != 0)
     {
             //h = round(x/x);

         h = x / abs(x);


     }
     else
         h = 0;

     if (y != 0)
     {
         v = y / abs(y);
     }
     else
         v = 0;





     return cocos2d::Vec2(h, v);



 }
 */
