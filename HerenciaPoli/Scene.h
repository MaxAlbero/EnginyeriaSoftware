#pragma once
#include <string>

class Scene {
protected:
	int ID;
	std::string name;

public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;
};