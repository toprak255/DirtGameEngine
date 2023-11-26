//main.cpp
#include "DirtGameEngine.hpp"
#include <iostream>

std::vector<float> shape2 = { 
0.15,0.15,0.5,0.5,
0.1, 0.1, 0.0f, 0.0f,
0.1, 0.2, 0.0f, 1.0f,
0.2 ,0.2, 1.0f, 1.0f,
0.2 ,0.1, 1.0f, 0.0f,
0.1, 0.1, 0.0f, 0.0f
};
std::vector<float> shape1 = {
    0.45,0.45,0.5,0.5,
    0.3f, 0.3f, 0.0f, 0.0f, 
    0.3f, 0.6f, 0.0f, 1.0f,
    0.6f, 0.6f, 1.0f, 1.0f, 
    0.6f, 0.3f, 1.0f, 0.0f,
    0.3f, 0.3f, 0.0f, 0.0f
};

//switch to {
// {x,y}
// {x,y}
// {x,y}
// {x,y}
// }
// something like this idk proper 2d vectors

//Create a new scene
dgm::Scene2D* root = dgm::newScene();



dgm::Shape2D* shape = dgm::newShape(root, &shape1);
dgm::Entity2D* entity2 = dgm::newEntity(root, &shape2);

void loopFunc() {

    //Render the scene
    dgm::drawScene(root);
    entity2->move(0.001, 0.001);

   
}
int main() {
    if (dgm::initWindow() != 0) {return -1;}
    
    //root->remove(entity2);
    //dgm::removeEntity(root, entity2);
    //dgm::WindowSettings::vsync = false; //default value is true
    
    entity2->texture = dgm::LoadTexture("./textures/texture.png");

  
    shape->texture=dgm::LoadTexture("./textures/texture.png");

    dgm::mainLoop(loopFunc);
    delete root;
    dgm::Close();
    return 0;   
}
