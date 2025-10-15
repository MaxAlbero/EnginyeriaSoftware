#pragma once
#pragma once
#include "Scene.h"
#include <conio.h>
#include <iostream>

class ConfigScene : public Scene {
public:
	void Start() override {}
	void End() override {}
	void Update() override;
	void Draw() override;
};

void ConfigScene::Update() {
	int value;
	std::cin >> value;
	
	//ASSIGN VALUE TO NUMFACES

	//GOTO MENU
}

void ConfigScene::Draw() {
	std::cout << "Enter the amount of faced the dice has: ";
}
