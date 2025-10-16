#pragma once
#include "Scene.h"
#include "GameScene.h"
#include "MenuScene.h"
#include "ConfigScene.h"
#include <map>
#include <cassert>

class SceneManager {
private:
	std::map<std::string, Scene*> scenes;
	Scene* currentScene;
	GameData* gameData;
	bool playing;

public:
	SceneManager() {
		gameData = new GameData;
		playing = true;
		currentScene = nullptr;
	}
	~SceneManager();
	void Init();
	void Run();

private:
	void Draw();
	void Update();
};

void SceneManager::Init() {
	srand(time(NULL));

	scenes["MainMenu"] = new MenuScene;
	scenes["Config"] = new ConfigScene(gameData); //com no tenim un constructor per defecte, hem de pasar "data" a les escenes per a utilitzar-les
	scenes["Game"] = new GameScene(gameData);

	currentScene = scenes["MainMenu"];
}

void SceneManager::Run() {
	while (playing) {
		Draw();
		Update();
		if (currentScene->IsFinished())
		{
			//Change scene
			currentScene->End();

			std::string nextScene = currentScene->GetNextScene();

			if (nextScene.size() == 0) //we assume that an empty string = Exit
			{
				playing = false;
			}
			else {

				//SWAP SCENES
				assert(scenes.find(nextScene) != scenes.end());
				currentScene = scenes[nextScene];

				currentScene->Start();
			}
		}
	}
}

void SceneManager::Draw() {


}

void SceneManager::Update() {
	
}