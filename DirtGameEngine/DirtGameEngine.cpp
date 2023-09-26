//DirtGameEngine.cpp
#include "DirtGameEngine.hpp"

#pragma comment(lib,"glew32.lib")
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm.hpp>
#include <Windows.h>
#include <chrono>

#include <iostream>
#include <limits>

int argc = 0;
char** argv = nullptr;
long double dgm::deltaT = 0.0;
dgm::WindowSettingsStruct dgm::WindowSettings;
dgm::SceneSettingsStruct dgm::SceneSettings;
dgm::EngineSettingsStruct dgm::EngineSettings;

auto previousTime = std::chrono::high_resolution_clock::now();

void placeHolder(void) {};

void dgm::initWindow() {
	if (SceneSettings.Depth) {
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
		glEnable(GL_DEPTH_TEST);
	}
	else {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	}
	glutInit(&argc, argv);
	glutInitContextVersion(WindowSettings.majorVer, WindowSettings.minorVer);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
	if (WindowSettings.fullscreen == true) {
		SetProcessDPIAware();
		glutInitWindowSize(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
		glutCreateWindow(WindowSettings.title);
		glutFullScreen();
	}
	else {
		glutInitWindowSize(WindowSettings.screenSize.x, WindowSettings.screenSize.y);
		glutCreateWindow(WindowSettings.title);
	}
	GLenum glewInitResult = glewInit();
	if (glewInitResult != GLEW_OK) {
		std::cerr << "GLEW initialization failed: " << glewGetErrorString(glewInitResult) << std::endl;
	}
	//glViewport(0, EngineSettings.canvasSize.x, 0, EngineSettings.canvasSize.y);
	glViewport(0, 0, WindowSettings.screenSize.x, WindowSettings.screenSize.y);

	gluOrtho2D(0, EngineSettings.canvasSize.x, 0, EngineSettings.canvasSize.y);
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glLoadIdentity();



}

void dgm::Rectangle(float* x, float* y, float* w, float* h) {

}

/*
	GLuint vbo1;  // Vertex Buffer Object for the first set of vertices
	glGenBuffers(1, &vbo1);
	glBindBuffer(GL_ARRAY_BUFFER, vbo1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	/////////////////////////////////////////////////////////////////////////

	GLuint vao1;  // Vertex Array Object for the first set of vertices
	glGenVertexArrays(1, &vao1);
	glBindVertexArray(vao1);

	// Configure the attribute layout for the first set of vertices
	glBindBuffer(GL_ARRAY_BUFFER, vbo1);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);

	//////////////////////////////////////////////////////////////////

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Use the shader program if you have one
	// glUseProgram(shaderProgram);

	// Render the first set of vertices
	glBindVertexArray(vao1);
	glColor4ubv(dgm::WindowSettings.Color);
	glDrawArrays(GL_POLYGON, 0, 4);  // Draw the first set of vertices
	// Unbind the vertex arrays
	glBindVertexArray(0);


	//glutSwapBuffers();
	*/
void dgm::drawVertex3d(float* vertices) {
	
	// Vertex data for the first set of vertices
	
	GLuint vbo1;  // Vertex Buffer Object for the first set of vertices
	glGenBuffers(1, &vbo1);
	glBindBuffer(GL_ARRAY_BUFFER, vbo1);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 12 * 3, vertices, GL_STATIC_DRAW);


	/////////////////////////////////////////////////////////////////////////

	GLuint vao1;  // Vertex Array Object for the first set of vertices
	glGenVertexArrays(1, &vao1);
	glBindVertexArray(vao1);

	// Configure the attribute layout for the first set of vertices
	glBindBuffer(GL_ARRAY_BUFFER, vbo1);
	glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 3, GL_INT, GL_FALSE, 3 * sizeof(int), (void*)0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	//////////////////////////////////////////////////////////////////
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glClearColor(dgm::WindowSettings.bgColor.r, dgm::WindowSettings.bgColor.g, dgm::WindowSettings.bgColor.b, dgm::WindowSettings.bgColor.a);


	// Use the shader program if you have one
	// glUseProgram(shaderProgram);

	// Render the first set of vertices
	glBindVertexArray(vao1);
	glColor4ubv(dgm::WindowSettings.Color);
	glDrawArrays(GL_POLYGON, 0, 4);  // Draw the first set of vertices
	// Unbind the vertex arrays
	glBindVertexArray(0);

	glutSwapBuffers();
	
	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		// Print or log the error here
		std::cerr << "OpenGL Error: " << error << std::endl;
	}

}

//void dgm::renderU(){
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClearColor(dgm::windowSettings.bgColor.r, dgm::windowSettings.bgColor.g, dgm::windowSettings.bgColor.b, dgm::windowSettings.bgColor.a);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClearColor(windowSettings.bgColor);
	//dgm::drawVertexArr();
	//glutSwapBuffers();
//}

void funcDeltaTime(){
	auto currentTime = std::chrono::high_resolution_clock::now();
	//std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::chrono::duration<double> frameDuration = currentTime - previousTime;
	dgm::deltaT = frameDuration.count();
	previousTime = currentTime;
	//std::cout << "Fps: " << 1 / dgm::deltaT << std::endl;
}
//gets called at every update 
void dgm::renderU(void(*func)(void)) {
	if (func != nullptr) {
		glutDisplayFunc(func);
	}
	else{
		glutDisplayFunc(func);
		//glutDisplayFunc(placeHolder);
	}
	glutPostRedisplay();

}
//gets called every frame
void dgm::renderF(void(*func)(void)) {

	if (func != nullptr); {
		glutIdleFunc(func); 
	}

	if (dgm::EngineSettings.EnableDeltaTime){
	funcDeltaTime();}


}

void reshape(int x, int y) {
	if (dgm::WindowSettings.windowState == DGM_FIXED) {
		glutReshapeWindow(dgm::WindowSettings.screenSize.x, dgm::WindowSettings.screenSize.y);
	}


}
void keebFunc(unsigned char c, int x, int y) {
	//glutPostRedisplay();
	std::cout << static_cast<int>(c) << std::endl;
}
void specialFunc(int c,int x, int y) {
	std::cout << static_cast<int>(c) << std::endl;

}
void dgm::Close() {
	glutLeaveMainLoop();
	delete[] WindowSettings.Color;
}

//function pointer allows user to call a function of their choice on demand
void dgm::Loop(void(*func)(void)) {
	//glOrtho2(EngineSettings.canvasSize.);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keebFunc);
	glutKeyboardFunc(keebFunc);
	glutSpecialFunc(specialFunc);

	//passed function is called here
	if (func != nullptr) {func();}
	glutMainLoop();
}