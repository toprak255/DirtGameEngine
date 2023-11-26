//main.cpp
#include "DirtGameEngine.hpp"
#include <iostream>
std::vector<float> shape1 = { 0.3, 0.3,  0.3, 0.6,  0.6 ,0.6,  0.6 ,0.3 };
std::vector<float> shape2 = { 0.1, 0.1,  0.1, 0.2,  0.2 ,0.2,  0.2 ,0.1 };

//Create a new scene
dgm::Scene2D* root = dgm::newScene();


//Place objects into scene
//dgm::Shape2D* fSquare = root->newShape(&abc);//optional vertices

dgm::Shape2D* shape = dgm::newShape(root, &shape1);
dgm::Entity2D* entity2 = dgm::newEntity(root, &shape2);

void loopFunc() {

    //Render the scene
    dgm::drawScene(root);
    if (entity2) {
        entity2->move(0.001, 0.001);
    }
    //std::cout << 1/dgm::deltaT << std::endl;
    //using built in delta time 
    

}
int main() {
    
    //root->remove(entity2);
    //dgm::removeEntity(root, entity2);
    //dgm::WindowSettings::vsync = false; //default value is true
    if (dgm::initWindow() != 0) {return -1;}
    dgm::mainLoop(loopFunc);
    delete root;
    dgm::Close();
    return 0;   
}
