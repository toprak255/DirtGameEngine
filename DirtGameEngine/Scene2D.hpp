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
        unsigned int texture;
    private:
        std::vector<SceneObject2D*> children;
    };



    class Entity2D : public SceneObject2D {
    public:
        //void (*entityFunction)(void);
        void move(float x, float y);

        //Entity2D(void (*function)(void)) : entityFunction(function) {}

    };

    class Shape2D : public SceneObject2D {

    };

//2D Scene function
    class Scene2D {
    public:
        glm::vec3 background = { 0,0,0 };
        std::vector<SceneObject2D*> objects;
        std::vector<SceneObject2D*> entities;
        Shape2D* newShape(std::vector<float>* vertices = {});
        //Entity2D* newEntity(std::vector<float>* vertices = {});
        void remove(SceneObject2D* child);
        ~Scene2D();
    };


//function for creating a new scene
    Scene2D* newScene();
    // void(*func)(void)

    Entity2D* newEntity(Scene2D* scene, std::vector<float>* vertices = {});
    Shape2D* newShape(Scene2D* scene, std::vector<float>* vertices = {});
    void removeObject(Scene2D * scene, SceneObject2D * child);
    void removeEntity(Scene2D * scene, SceneObject2D * child);
    

}//namespace end