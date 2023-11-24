//Window.cpp
#include "Window.hpp"

GLFWwindow* dgm::window;
GLFWmonitor* dgm::monitor;

// Window.cpp
#include "Window.hpp"

glm::vec2 dgm::WindowSettings::screenSize = { 600, 600 };
char dgm::WindowSettings::title[40] = "DGM Demo Window";
bool dgm::WindowSettings::vsync = true;