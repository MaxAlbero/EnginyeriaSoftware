//#include <iostream>
//#include <map>
//class Renderer {
//public:
//	virtual void Draw() = 0;
//};
//
//class Image : public Renderer {
//public:
//	void Draw() override {
//		std::cout << "I am an Image!" << std::endl;
//	}
//};
//
//class Button : public Renderer {
//private:
//	Text innerText;
//
//	void Draw() override {
//
//	}
//};
//
////class Scene
////{
////protected:
////	std::
////};
//
//class SceneManager {
//private:
//	std::map<std::string, Scene*> scenes;
//	Scene* currentScene;
//public:
//	void AddScene(std::string key, Scene* value){ //Para el codigo si ya existe una 
//		assert(scenes.find(key) != scenes.end());
//		currentScene = scenes[key];
//	}
//	void SetCurrentScene(std::string key) {
//
//	}
//};
//
//class PauseScene : public Scene {
//public:
//	PauseScene() {
//
//	}
//};
//
//int main() {
//	SceneManager* sm = new SceneManager;
//
//	sm->AddScene("Menu", new MenuScene);
//
//	sm->SetCurrentScene("Pause");
//
//	sm->Draw();
//
//	return 0;
//}