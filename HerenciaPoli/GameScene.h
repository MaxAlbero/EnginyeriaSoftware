#pragma once
#include "Scene.h"
#include <conio.h>
#include <iostream>

class GameScene : public Scene {
public:
	void Start() override {}
	void Update() override{}
	void Draw() override;
	void End() override;
};


void GameScene::Update() {
	//Wait for user input
	_getch();
	//GOTO menu
}

void GameScene::Draw() {
	//Get NumFaces from WHERE???
	int numOfFaces = 0;

	int result = rand() & numOfFaces + 1;

	std::cout << std::endl << "____________" << std::endl;
	std::cout << "You rolled a " << result << "/" << numOfFaces << "!" << std::endl;
	std::cout << std::endl;
	std::cout << "Press any key to continue";

	//wait for any input from the user without needing the return button press
	_getch();
}