#include <iostream>
#include <vector>

class Renderer {
private:
    int x, y;
public:
    Renderer() :
        x(0), y (0) { }
    Renderer(int x, int y){ }

    virtual void Draw() = 0;
};

class RenderManager {
private:
    std::vector<Renderer*> renderers;
public:
    void AddRenderer(Renderer* r) { renderers.push_back(r); }

    void Draw() {
        for (Renderer* r : renderers) {
            r->Draw();
            std::cout << std::endl;
        }
    }
};

class Image : public Renderer {
public:
    void Draw() override {
        std::cout << "I am an Image!" << std::endl;
    }
};
class Animation2D : public Renderer {
public:
    void Draw() override {
        std::cout << "I am an Animation2D!" << std::endl;
    }
};
class Model3D : public Renderer {
public:
    void Draw() override {
        std::cout << "I am an Model3D!" << std::endl;
    }
};

/*
int main()
{
    RenderManager* rm = new RenderManager;

    rm->AddRenderer(new Image);
    rm->AddRenderer(new Animation2D);
    rm->AddRenderer(new Model3D);
    rm->AddRenderer(new Model3D);
    rm->AddRenderer(new Animation2D);
    rm->AddRenderer(new Image);

    rm->Draw();

    return 0;
}
*/