//main.cpp
#include "DirtGameEngine.hpp"
#include <iostream>

std::vector<float> shape2 = { 
 //triangle fan , not suitable
/* shape coordinates */ 0.1, 0.1, 
/* shape coordinates */ 0.1, 0.2, 
/* shape coordinates */ 0.2 ,0.1, 
/* shape coordinates */ 0.2 ,0.1, 
/* shape coordinates */ 0.2 ,0.2, 
/* shape coordinates */ 0.1, 0.2, 
};
std::vector<float> textureC = {
    //.0f, 0.0f,
    //.0f, 1.0f,
    //.0f, 0.0f,
    //.0f, 0.0f,
    //.0f, 1.0f,
    //.0f, 1.0f,
    //=======
    //0.1, 0.1,
    //0.1, 0.2,
    //0.2 ,0.1,
    //0.2 ,0.1,
    //0.2 ,0.2,
    //0.1, 0.2,

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



dgm::Object2D* shape = dgm::newObject(root);

dgm::Entity2D* entity2 = dgm::newEntity(root);

void loopFunc() {

    //Render the scene
    dgm::drawScene(root);
    
    entity2->position.x += 0.001f;

    //root->camPos.x += 0.01f;
    //dgm::updateCamPos(root);
   
}

int main() {
    //shape->shapeCoords = shape1;
    shape->shapeCoords = dgm::Shape2D::nGon({.5,.5},10, 6);
    entity2->shapeCoords = shape2;
    entity2->textureCoords = textureC;
    entity2->setFunction([]() {
        entity2->move(0.001, 0.001); 
        });
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
