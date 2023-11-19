// Window.hpp
#pragma once

#define GLFW_INCLUDE_NONE
#define DGM_FULLSCREEN          0x10
#define DGM_MAXIMIZED           0x11
#define DGM_WINDOWED            0x12
#define DGM_WINDOWEDFULLSCREEN  0x13

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace dgm {
    extern GLFWwindow* window;
    extern GLFWmonitor* monitor;

    namespace WindowSettings {
        extern glm::vec2 screenSize;
        extern char title[40];
    };
}
