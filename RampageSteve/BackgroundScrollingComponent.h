#pragma once
#ifndef BACKGROUNDSCROLLINGCOMPONENT_H
#define BACKGROUNDSCROLLINGCOMPONENT_H
#include "Globals.h"

class Component;
class BackgroundScrollingComponent : public Component
{
public:
	BackgroundScrollingComponent(Entity*, float& screenWidth);

	bool init();

	void update(float& dt);

	void updateInput(float& dt, sf::Event*);

	void updateRender(sf::RenderTarget* target);

	~BackgroundScrollingComponent();
private:
	float speed = 0;
	float maxX = 0;

    Entity* childInstance = nullptr;

};


#endif // BACKGROUNDSCROLLINGCOMPONENT_H
