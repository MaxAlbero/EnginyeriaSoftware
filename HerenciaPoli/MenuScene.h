#pragma once
#include "Scene.h"
#include <iostream>
#include <conio.h>

class MenuScene : public Scene {
	// Inherited via Scene
	void Start() override { }
	void Update() override { }
	void Draw() override;
	void End() override;
};

//MenuScene.cpp
void MenuScene::Update() {
	char choice = _getch();

	switch (choice)
	{
	case 1:
		//go to game
		break;
	case 2:
		//go to config
		break;
	case 3:
		//exit
		break;
	}
}

void MenuScene::Draw() {
	std::cout << "Welcome to the bes game evar!\n\n";
	std::cout << "Please enter your choice: \n";
	std::cout << " -> 1: Play\n";
	std::cout << " -> 2: Config\n";
	std::cout << " -> 3: Exit\n";
	std::cout << "Please enter your choice: ";
}