//main.cpp
#include "DirtGameEngine.hpp"
#include <iostream>
std::vector<float> abc = { 0.3, 0.3,  0.3, 0.6,  0.6 ,0.6,  0.6 ,0.3 };
std::vector<float> shape2 = { 0.1, 0.1,  0.1, 0.2,  0.2 ,0.2,  0.2 ,0.1 };

//Create a new scene
dgm::Scene2D* root = dgm::newScene();

//Place objects into scene
dgm::Shape2D* fSquare = root->newShape(&abc);//optional vertices
dgm::Entity2D* entity1 = root->newEntity(&shape2);//optional vertices
 //fSquare->vecs= {0.3, 0.3,  0.3, 0.6,  0.6 ,0.6,  0.6 ,0.3   }; this also works

void renderFunc() {
    //Render the scene
    dgm::drawScene(root);
  
    std::cout << 1/dgm::deltaT << std::endl;
    //built in delta time 
    entity1->move(0.1*dgm::deltaT, 0.05*dgm::deltaT);

}
int main() {
    //dgm::WindowSettings::vsync = false; //default value is true
    if (dgm::initWindow() != 0) {return -1;}
    dgm::renderLoop(renderFunc);
    delete root;
    dgm::Close();
    return 0;   
}
