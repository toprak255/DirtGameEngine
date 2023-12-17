// Window.hpp
#pragma once


enum windowType {
    GLFW_INCLUDE_NONE,
    DGM_FULLSCREEN,
    DGM_MAXIMIZED,           
    DGM_WINDOWED       ,     
    DGM_WINDOWEDFULLSCREEN  ,
};
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace dgm {
    extern GLFWwindow* window;
    extern GLFWmonitor* monitor;

    namespace WindowSettings {
        extern glm::vec2 screenSize;
        extern char title[40];
        extern bool vsync;
    };
}
