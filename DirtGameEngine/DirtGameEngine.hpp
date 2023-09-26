//DirtGameEngine.hpp
#pragma once

#define DGM_FIXED 0x0101
#define DGM_FREE 0x0102
#include "Keyboard.h"
#include <glm.hpp>
#include <GL/glew.h>

namespace dgm{


//defines window properties
struct WindowSettingsStruct {
		int majorVer = 4;
		int minorVer = 2;	
		int windowState = DGM_FIXED;
		bool fullscreen = false;
		glm::vec2 screenSize = { 600, 300 };
		//Red, Green, Blue and Alpha values for background color in 0-1 range;
		glm::fvec4 bgColor;
		//Red, Green, Blue and Alpha values in 8 bit range;
		GLubyte* Color = new GLubyte[4]{ 255, 100, 120, 255 };
		char title[40] = "DGM Demo Window";
};
//defines scene settings
struct SceneSettingsStruct{
	bool Depth = 0;
};struct EngineSettingsStruct{
	bool EnableDeltaTime = 0;
	glm::vec2 canvasSize = {100,100};
};

extern dgm::WindowSettingsStruct WindowSettings;
extern dgm::SceneSettingsStruct SceneSettings;
extern dgm::EngineSettingsStruct EngineSettings;

//delta time, gets updated every frame
extern long double deltaT;


	//Initializes window with given parameters
	//Check dgm::windowSettings for more
	void initWindow();

	//used to load images TODO
	void loadImg();
	//Renders at updates
	void renderU(void(*func)(void) = nullptr);
	//Renders on every frame , good for animated stuff
	void renderF(void(*func)(void) = nullptr);
	//handles keyboard TODO
	void keyboard(unsigned char c, int x, int y);
	//Draws a rectangle to the screen according to given values TODO
	void  Rectangle(float* x, float* y, float* w, float* h);

	void Cuboid();

	// TODO
	void drawVertex3d(float* vertices);
	void drawVertex3f(float* vertices[]);
	//Quits the main loop and destroys dynamically allocated elements
	void Close();

	//Starts the mainloop for program to run
	void Loop(void(*func)(void)=nullptr);
}