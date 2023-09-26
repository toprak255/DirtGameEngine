//Source.cpp
#include "DirtGameEngine.hpp"
#include <iostream>

	void draw() {
		float vertices[12] = {
			.0 ,.0 , .1,
			.20,.90, .2,
			.20,.10, .1,
			.10,.0 , .2
		};

	dgm::drawVertex3d(vertices);
	
	}






int main() {


	dgm::WindowSettings.screenSize={500,500};
	dgm::EngineSettings.EnableDeltaTime = 1;
	dgm::WindowSettings.fullscreen = false; 
	dgm::WindowSettings.windowState = DGM_FIXED;
	dgm::WindowSettings.bgColor = { .3, .5, .3, 1.f };
	dgm::EngineSettings.canvasSize = { 10,10 };
	dgm::initWindow();
	dgm::renderU(draw);

	//doesnt work
	//does work
	//dgm::renderF(draw);
	

	dgm::Loop();
	//return EXIT_SUCCESS;
}
