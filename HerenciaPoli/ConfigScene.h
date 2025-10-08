#pragma once
#include "Scene.h"
#include <conio.h>
#include <iostream>

class ConfigScene : public Scene {
public:
	void Start() override {}
	void Update() override {}
	void Draw() override;
	void End() override;
};


void ConfigScene::Update() {
	//Wait for user input
	int value;
	std::cin >> value;
	//GOTO menu
}

void ConfigScene::Draw() {
	std::cout << "Enter the amount of faced the dice has: ";

}