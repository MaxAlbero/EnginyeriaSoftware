#pragma once
#include <map>
#include <string>
#include "Scene.h"
#include <time.h>



class GameEngine {


	std::map<std::string, Scene*> scenes;
	Scene* currentScene;
};