// DirtGameEngine.cpp

#include "DirtGameEngine.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "ErrorHandling.hpp"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <chrono>
#include <Windows.h>
GLuint vbo1;
GLuint vao1;
GLuint vertexShader;
GLuint fragmentShader;
GLuint shader;
long double dgm::deltaT;
auto previousTime = std::chrono::steady_clock::now();


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    std::cout << width << " / " << height << std::endl;
    glm::mat4 projection = glm::ortho(.0f, 1.0f, 0.0f, 1.0f * height / width, -1.0f, 1.0f);
    //glm::mat4 projection = glm::ortho(.0f, 1.0f* width / height, .0f , 1.0f , -1.0f, 1.0f);
    glUniformMatrix4fv(glGetUniformLocation(shader, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
}


// Vertex Shader
const char* vertexShaderSource = R"(
#version 430 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 projection;

void main() {
    gl_Position = projection * vec4(aPos, 0.0, 1.0);
    TexCoord = aTexCoord;
}
)";

// Fragment Shader
const char* fragmentShaderSource = R"(
#version 430 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture1;

void main() {
    FragColor = texture(texture1, TexCoord);
}
)";


int dgm::initWindow() {
    if (!glfwInit()) {
        std::cerr << "GLFW initialization failed" << std::endl;
        return -1;
    }

    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, WindowSettings::majorVer);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);
    monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    int x, y;
    dgm::getScreenSize(&x,&y);
    window = glfwCreateWindow(WindowSettings::screenSize.x, WindowSettings::screenSize.y, WindowSettings::title, NULL, NULL);
    //glfwSetWindowSize(window, 600, 600);
    //glfwMaximizeWindow(window);

    /*
    if (EngineSettings::debugMode == true) {
        glfwSetErrorCallback(error_callback);
    }
    */
    if (!window) {
        std::cerr << "Window initialization failed" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGL()) {
        // GLAD failed to load OpenGL functions
        return -1;
    }
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    if (dgm::WindowSettings::vsync) {

       glfwSwapInterval(1);
    }
    //
    glClearColor(.2f, .2f, .2f, .0f);
    glGenBuffers(1, &vbo1);
    glGenVertexArrays(1, &vao1);

    /////////

    int success;
    char infoLog[512];



    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    ///error checking for vertex
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };
    ///
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    ///error checking for fragment shader
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    };


    ////
    shader = glCreateProgram();
   
    glAttachShader(shader, vertexShader);
    glAttachShader(shader, fragmentShader);
    //glBindAttribLocation(shader, 0, "aPos");
    glLinkProgram(shader);
    ///Link error checking
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    ////
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    //
    glUseProgram(shader);   
//
    GLint projectionLocation = glGetUniformLocation(shader, "projection");
    if (projectionLocation == -1) {
        std::cerr << "Uniform projection not found in the shader program." << std::endl;
    }
    //
    
    //change this shit below
    glm::mat4 projection = glm::ortho(.0f, 1.0f, 0.0f, 1.0f * 1080 / 1920, -1.0f, 1.0f);
  

    glUniformMatrix4fv(glGetUniformLocation(shader, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
  //  

        glBindVertexArray(vao1);
        //
        glBindBuffer(GL_ARRAY_BUFFER, vbo1);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));

        glBindVertexArray(vao1);
        glBindBuffer(GL_ARRAY_BUFFER, vbo1);
 
 //
    return 0;
}

void dgm::drawScene(Scene2D* scene) {

    //to do: use triangle strips
    //strip generator
    //make shape inputs something proper
    //compare fps
    // glMultiDrawArrays noway
    for (const auto& object : scene->objects) {
        glBindTexture(GL_TEXTURE_2D, object->texture);
        glUniform1i(glGetUniformLocation(shader, "texture1"), 0);

        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * object->vecs.size(), object->vecs.data(), GL_STATIC_DRAW);
        glDrawArrays(GL_TRIANGLE_FAN, 0, object->vecs.size() / 2);
    }

    for (const auto& entity : scene->entities) {
        entity->callFunction();
        glBindTexture(GL_TEXTURE_2D, entity->texture);
        glUniform1i(glGetUniformLocation(shader, "texture1"), 0);

        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * entity->vecs.size(), entity->vecs.data(), GL_STATIC_DRAW);
        glDrawArrays(GL_TRIANGLE_FAN, 0, entity->vecs.size() / 2);
    }
}



void dgm::getScreenSize(int* x, int* y) {
    GLFWmonitor* primary = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(primary);
    *x = mode->width;
    *y = mode->height;
}
//calls the passed function at every single frame generated
void dgm::mainLoop(void(*func)(void)) {
        if (func == NULL) {
            std::cerr << " mainLoop function needs an input " << std::endl;
            glfwTerminate();
        }
    while (!glfwWindowShouldClose(window)) {
  
        glClear(GL_COLOR_BUFFER_BIT);
        //
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsed = currentTime-previousTime;
        //deltaT = elapsed.count();
        deltaT = std::chrono::duration_cast<std::chrono::duration<double>>(elapsed).count();
        previousTime = currentTime;
        func();
        glfwSwapBuffers(window);
        glfwPollEvents();

    }
}

void dgm::Close() {
    glDeleteVertexArrays(1, &vao1);
    glDeleteBuffers(1, &vbo1);
    //glDeleteTextures(1, &texture); 
    //loop through textures to delete them
    glDeleteProgram(shader);
    glfwTerminate();
}
