// Scene2D.hpp
#pragma once

#include <functional>
#include <vector>
#include <glm/glm.hpp>

namespace dgm {
    //Template class for scene objects
    class TemplateObject2D {
    public:
        glm::vec2 position;
        float rotation;
        float scale;
        std::vector<float> shapeCoords;
        std::vector<float> textureCoords;
        virtual ~TemplateObject2D();
        unsigned int texture;

    };


//using FunctionType = std::function<void(void)>;

    class Entity2D : public TemplateObject2D {
    public:
        //void (*entityFunction)(void);

        void setFunction(const std::function<void(void)>& func) {
            entityFunction = func;
        }

        void callFunction();

        void move(float x, float y);

        //Entity2D(void (*function)(void)) : entityFunction(function) {}
    private:
        std::function<void(void)> entityFunction{};
    };

    class Object2D : public TemplateObject2D {

    };

//2D Scene function
    class Scene2D {
    public:
        glm::vec2 camPos = { 0,0 };
        glm::vec3 background = { 0,0,0 };
        std::vector<TemplateObject2D*> objects;
        //std::vector<SceneObject2D*> entities;
        std::vector<Entity2D*> entities;

        //Entity2D* newEntity(std::vector<float>* vertices = {});
        void remove(TemplateObject2D* child);
        ~Scene2D();
    };


//function for creating a new scene
    Scene2D* newScene();
    // void(*func)(void)

    Entity2D* newEntity(Scene2D* scene);
    Object2D* newObject(Scene2D* scene);
    void removeObject(Scene2D * scene, TemplateObject2D * child);
    void removeEntity(Scene2D * scene, TemplateObject2D * child);
    

}//namespace end