// Scene2D.hpp
#pragma once

#include <vector>
#include <glm/glm.hpp>

namespace dgm {
    //Template class for scene objects
    class SceneObject2D {
    public:
        std::vector<float> vecs;
        virtual ~SceneObject2D();

    private:
        std::vector<SceneObject2D*> children;
    };



    class Entity2D : public SceneObject2D {
    public:
        void move(float x, float y);

    };
    class Shape2D : public SceneObject2D {

    };

//2D Scene function
    class Scene2D {
    public:
        std::vector<SceneObject2D*> objects;
        Shape2D* newShape(std::vector<float>* vertices = {});
        Entity2D* newEntity(std::vector<float>* vertices = {});
        void remove(SceneObject2D* child);
        ~Scene2D();
    };

/*function definitions*/

//function for creating a new scene
    Scene2D* newScene();

}//namespace end