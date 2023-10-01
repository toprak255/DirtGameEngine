//DirtGameEngine.cpp
#include "DirtGameEngine.hpp"

#pragma comment(lib,"glew32.lib")
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm.hpp>
#include <Windows.h>
#include <chrono>
#include "Collision.hpp"
#include <iostream>




int argc = 0;
char** argv = nullptr;

std::vector<std::vector<vec2>> shapes;
long double dgm::deltaT = 0.0;

dgm::WindowSettingsStruct dgm::WindowSettings;
dgm::SceneSettingsStruct dgm::SceneSettings;
dgm::EngineSettingsStruct dgm::EngineSettings;

auto previousTime = std::chrono::high_resolution_clock::now();

void placeHolder(void) {};
GLuint program;
/*
void shader() {
	// Create a program object
	GLuint program = glCreateProgram();
	//GLuint program = glCreateProgram();

	// Create a vertex shader object
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	// Provide the vertex shader source code
	const char* vertexShaderSource = R"(
#version 430 core

layout (location = 0) in vec3 position; // The input vertex position

void main() {
  // Normalize the position using the built-in function
  vec3 normalized_position = normalize(position);

  // Pass the normalized position to the next stage
  gl_Position = vec4(normalized_position, 1.0);
}

)";

	// Set the vertex shader source code
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

	// Compile the vertex shader
	glCompileShader(vertexShader);

	// Check for compilation errors
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << infoLog << std::endl;
	}

	// Create a fragment shader object
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	// Provide the fragment shader source code
	const char* fragmentShaderSource = R"(
	#version 330 core
	in vec4 color; // The input vertex color
	out vec4 FragColor; // The output fragment color

	void main()
	{
	  // Assign the output color
	  FragColor = color;
	}
	)";

	// Set the fragment shader source code
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

	// Compile the fragment shader
	glCompileShader(fragmentShader);

	// Check for compilation errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout <<infoLog << std::endl;
	}

	// Attach the shader objects to the program object
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	// Link the program object
	glLinkProgram(program);

	// Check for linking errors
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << infoLog << std::endl;
	}

	// Delete the shader objects after linking
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}
*/
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

void dgm::Rectangle() {

	std::vector<vec2> vertices1 = {
		{ -0.5f, -0.5f }, // Vertex 1
		{ -0.5f,  0.5f }, // Vertex 2
		{  0.5f,  0.9f },  // Vertex 3
		{  0.5f, -0.5f } // Vertex 4
\
	};



	std::vector<vec2> vertices2 = {
		{ 0.0f, 0.0f},
		{ 0.0f, 0.9f},
		{ 0.9f, 0.9f},

	};

	shapes.push_back(vertices1);
	shapes.push_back(vertices2);


}
void dgm::drawShapes() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(dgm::WindowSettings.bgColor.r, dgm::WindowSettings.bgColor.g, dgm::WindowSettings.bgColor.b, dgm::WindowSettings.bgColor.a);
	glColor3f(0.9, 0.9, .9);
	for (auto shape : shapes) {
		GLuint vbo1;  // Vertex Buffer Object for the current set of vertices
		glGenBuffers(1, &vbo1);
		glBindBuffer(GL_ARRAY_BUFFER, vbo1);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * shape.size()*2, shape.data(), GL_STATIC_DRAW);

		GLuint vao1;  // Vertex Array Object for the current set of vertices
		glGenVertexArrays(1, &vao1);
		glBindVertexArray(vao1);

		// Configure the attribute layout for the current set of vertices
		glBindBuffer(GL_ARRAY_BUFFER, vbo1);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
		//glUseProgram(program);
		// Render the current set of vertices
		glBindVertexArray(vao1);
		//glColor4ubv(dgm::WindowSettings.Color);
		glDrawArrays(GL_TRIANGLE_FAN, 0, shape.size());  // Draw the current set of vertices
		// Unbind the vertex arrays
		//glBindVertexArray(0);

		// Delete the buffers and vertex arrays when done
		//glDeleteBuffers(1, &vbo1);
		//glDeleteVertexArrays(1, &vao1);
	}
	glutSwapBuffers();
}
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
	//glUseProgram(shaderProgram);

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


void funcDeltaTime(){
	auto currentTime = std::chrono::high_resolution_clock::now();
	//std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::chrono::duration<double> frameDuration = currentTime - previousTime;
	dgm::deltaT = frameDuration.count();
	previousTime = currentTime;
	//std::cout << "Fps: " << 1 / dgm::deltaT << std::endl;
}

void dgm::renderU(void(*func)(void)) {
	if (func != nullptr) {
	drawShapes();
		glutDisplayFunc(func);
	}
	else{
		glutDisplayFunc(placeHolder);
	}

}
//gets called every frame
void dgm::renderF(void(*func)(void)) {
	if (func != nullptr); {
		glutIdleFunc(func); 
	}

	if (dgm::EngineSettings.EnableDeltaTime){
	funcDeltaTime();}

	glutPostRedisplay();//calls for an update

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
	//shader();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keebFunc);
	glutKeyboardFunc(keebFunc);
	glutSpecialFunc(specialFunc);

	//passed function is called here
	if (func != nullptr) {func();}
	glutMainLoop();
}