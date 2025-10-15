#include "ConfigScene.h"
#include "GameScene.h"
#include "MenuScene.h"
#include <map>
#include <cassert>
#include "GameData.h"


int main() {
	srand(time(NULL));

	std::map<std::string, Scene*> scenes;
	Scene* currentScene;

	GameData* data = new GameData;


	scenes["MainMenu"] = new MenuScene;
	scenes["Config"] = new ConfigScene(data); //com no tenim un constructor per defecte, hem de pasar "data" a les escenes per a utilitzar-les
	scenes["Game"] = new GameScene(data);

	currentScene = scenes["MainMenu"];

	bool playing = true;
	currentScene->Start();

	while (playing) {
		currentScene->Draw();
		currentScene->Update();
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

	//CLEANUP
	delete data;

	for (auto val : scenes) {
		delete val.second;
	}

}