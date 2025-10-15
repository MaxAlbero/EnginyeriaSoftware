#pragma once
#pragma once
#include "Scene.h"
#include <conio.h>
#include <iostream>
#include "GameData.h"

class ConfigScene : public Scene {
private:
	GameData* data;
public:
	ConfigScene(GameData* data) : data(data) {
		nextScene = "MainMenu";
	}
	void Start() override {}
	void End() override {}
	void Update() override;
	void Draw() override;
	bool const IsFinished() override { return true; }
	//std::string const GetNextScene() { return "Config"; }
};

void ConfigScene::Update() {
	int value;
	std::cin >> value;
	
	//ASSIGN VALUE TO NUMFACES
	try
	{
		data->SetNumberOfFaces(value);
	}
	catch (const std::string msg)
	{
		std::cout << msg << std::endl;
	}

	//GOTO MENU
}

void ConfigScene::Draw() {
	std::cout << "\nEnter the amount of faced the dice has: ";
}
