#pragma once
#include <string>
#include <iostream>
#include <conio.h>

class Scene {
protected:
	std::string nextScene;

public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;
	virtual bool const IsFinished() = 0; //Returns true when the scene has to end
	std::string const GetNextScene() { return nextScene; }
};