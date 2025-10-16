#pragma once
#include "Scene.h"
#include "GameData.h"

class GameScene : public Scene {
private:
	GameData* data;
public:
	GameScene(GameData* data) : data(data) {//constructor per copia de data
		nextScene = "MainMenu";
	} 
	void Start() override {}
	void End() override {}
	void Update() override;
	void Draw() override;
	bool const IsFinished() override { return true; }
	//std::string const GetNextScene() { return "Game"; }
};

void GameScene::Update() {
	//Wait for user input

	//GOTO menu

}

void GameScene::Draw() {

	//Get NumFaces from WHERE???
	int numOfFaces = data->GetNumberOfFaces();

	int result = rand() % numOfFaces + 1;

	std::cout << std::endl << "-----------" << std::endl;
	std::cout << "You rolled a " << result << "/" << numOfFaces << "!" << std::endl;
	std::cout << std::endl;
	std::cout << "Press any key to continue";
	std::cout << std::endl;

	//wait for any input from the user without needing the return button press
	_getch();
}
