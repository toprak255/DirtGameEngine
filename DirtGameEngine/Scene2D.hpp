//Scene2D.hpp
#pragma once

#include <vector>
#include <glm/glm.hpp>

namespace dgm {
//add button & entity class
//create a view matrix and add that to button

    class Shape2D {
    public:
        //Shape2D(std::vector<float>* vecs) : vecs(vecs) {}
        std::vector<float> vecs;
        glm::vec4 color;

        ~Shape2D();
    private:
        std::vector<Shape2D*> children;

    };

    class Scene2D {
    public:
        std::vector<Shape2D*> objects;

        //void add(Shape2D* child);
        Shape2D* newShape(std::vector<float>* vertices={});
        //void drawScene() {};
        void remove(Shape2D* child);

        ~Scene2D();
    private:

    };
    //
    Scene2D* newScene();

}