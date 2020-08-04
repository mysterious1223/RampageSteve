/*
 Kevin Singh
 Keeps all const vars and header definitions
 */

#pragma once
// contain headers?

#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <cmath>
#include <thread> 
#if __APPLE__
#include <unistd.h>
#endif


#include <SFML/Graphics.hpp>
#include <stack>

#ifndef SFML_GUI_H
#include "sfml_gui.h"

#endif //


#ifndef __GAME_H__
#include "Game.h"
#endif //__GAME_H__
#ifndef RESOURCELOADER_H
#include "ResourceLoader.h"
#endif //RESOURCELOADER_H
#ifndef GAMESTATE_H
#include "GameState.h"
#include "GameWorldState.h"
#include "GameMainMenuState.h"
#endif //GAMESTATE_H

#ifndef  _COMPONENT_H_
#include "Component.h"
#include "CharacterControllerComponent.h"
#include "PhysicsBodyComponent.h"
#include "BackgroundScrollingComponent.h"
#include "ColliderComponent.h"
#include "RangedCombatComponent.h"
#include "ProjectileComponent.h"
#include "EntityStatsComponent.h"
#include "SimpleAIComponent.h"
#endif //  _COMPONENT_H_



#ifndef ENTITY_H
#include "Entity.h"
#endif //ENTITY_H



// All constant strings / and or variables
#define GAME_WINDOW_NAME "Rampage Steve Engine .0001PRE - Alpha"

//config location
const std::string pathToConfig = "EntityConfigurations/Entities.config";

// Works on mac
//const std::string pathToConfigMac = "Resources/EntityConfigurations/Entities.config";


