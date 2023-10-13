//DirtGameEngine.cpp
#define GLFW_INCLUDE_NONE
#include "DirtGameEngine.hpp"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include"ErrorHandling.hpp"
#include "Types.hpp"
#include <iostream>

/*
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}*/
GLFWwindow* window;
int dgm::initWindow() {
	if (!glfwInit()){
		std::cerr << "GLFW initialization failed" << std::endl;
		return -1;}
	if (EngineSettings::debugMode == true) {
		glfwSetErrorCallback(error_callback);}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, WindowSettings::majorVer);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, WindowSettings::minorVer);

	window = glfwCreateWindow(WindowSettings::screenSize.x, WindowSettings::screenSize.y,WindowSettings::title, NULL, NULL);
	//GLFWwindow* window = glfwCreateWindow(640, 400,"test", NULL, NULL);
	if (!window){
		std::cerr << "Window initialization failed" << std::endl;
		glfwTerminate();}
	glfwMakeContextCurrent(window);
	//glfwSetKeyCallback(window, key_callback);
}

int dgm::renderLoop() {
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
	return 0;
}