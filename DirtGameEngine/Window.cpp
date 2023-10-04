#include "DirtGameEngine.hpp"
#include <GL/freeglut.h>
#include <iostream>

int argc = 0;
char** argv = nullptr;

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
		std::cerr << glewGetErrorString(glewInitResult) << std::endl;
	}
	//glViewport(0, EngineSettings.canvasSize.x, 0, EngineSettings.canvasSize.y);
	//glViewport(0, 0, WindowSettings.screenSize.x, WindowSettings.screenSize.y);
	//gluOrtho2D(0, EngineSettings.canvasSize.x, 0, EngineSettings.canvasSize.y);
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glLoadIdentity();
	//shader();



}