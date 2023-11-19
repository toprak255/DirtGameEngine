//main.cpp
#include "DirtGameEngine.hpp"
#include <iostream>
std::vector<float> abc = { 0.3, 0.3,  0.3, 0.6,  0.6 ,0.6,  0.6 ,0.3 };


dgm::Scene2D* root = dgm::newScene();
dgm::Shape2D* fSquare = root->newShape(&abc);//optional vertices
 //fSquare->vecs= {0.3, 0.3,  0.3, 0.6,  0.6 ,0.6,  0.6 ,0.3   }; this also works


void renderFunc() {
    dgm::drawScene(root);
    //std::cout << dgm::deltaT << std::endl;

}
int main() {
    if (dgm::initWindow() != 0) {return -1;}
    dgm::renderLoop(renderFunc);
    delete root;
    dgm::Close();
    return 0;   
}
