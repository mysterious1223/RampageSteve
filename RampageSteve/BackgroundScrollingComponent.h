#pragma once
#ifndef BACKGROUNDSCROLLINGCOMPONENT_H
#define BACKGROUNDSCROLLINGCOMPONENT_H
#include "Globals.h"

class Component;
class BackgroundScrollingComponent : public Component
{
public:
	BackgroundScrollingComponent(Entity*);

	bool init();

	void update(const float& dt);

	void updateInput(const float& dt, sf::Event*);

	void updateRender(sf::RenderTarget* target);

	~BackgroundScrollingComponent();
private:
	float speed = 0;
	float maxX = 0;

    Entity* childInstance = nullptr;

};


#endif // BACKGROUNDSCROLLINGCOMPONENT_H
