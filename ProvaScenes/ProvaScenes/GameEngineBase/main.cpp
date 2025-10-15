#include "ConfigScene.h"
#include "GameScene.h"
#include "MenuScene.h"
#include <map>

int main() {
	srand(time(NULL));

	scenes["MainMenu"] = new MenuScene;
	scenes["Config"] = new ConfigScene;
	scenes["Game"] = new GameScene;

	currentScene = scenes["MainMenu"];

	bool playing = true;

	while (playing) {
		currentScene->Draw();
		currentScene->Update();
	}

}


