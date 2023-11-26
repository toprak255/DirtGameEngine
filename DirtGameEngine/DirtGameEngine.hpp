//DirtGameEngine.hpp
#pragma once
#include <glm/glm.hpp>
#include "Window.hpp"
#include "Scene2D.hpp"
namespace dgm {



	//delta time, gets updated every frame
	extern long double deltaT;
	//void createEntity(int id, int* func = NULL, std::vector< glm::vec2>* vertices, int image, bool collision = true);
	//void createEntity(int id=NULL, void(*func)(void) = nullptr, int image=NULL, bool collision = true);

	void getScreenSize(int *x,int *y);

	void setCanvasSize(int x,int y);

	//Initializes window with given parameters
	//Check dgm::windowSettings for more
	int initWindow();

	void createScene();
	void drawScene();
	//used to load images TODO
	void loadImg();
	//Renders at updates
	void renderU(void(*func)(void) = nullptr);
	//Renders on every frame , good for animated stuff
	void renderF(void(*func)(void) = nullptr);
	//handles keyboard TODO
	void keyboard(unsigned char c, int x, int y);
	//Draws a rectangle to the screen according to given values TODO
	void  Rectangle();

	void drawScene(Scene2D* scene);

	//void drawShapes();
	//void clearShapes
	//might add object ids
	//maybe objects with ids for player , enemies etc
	void mainLoop(void(*func)(void) = nullptr);
	// TODO
	void drawVertex3d(float* vertices);
	void drawVertex3f(float* vertices[]);
	//Quits the main loop and destroys dynamically allocated elements
	void Close();

	//Starts the mainloop for program to run
//	void Loop(void(*func)(void) = nullptr);
}
