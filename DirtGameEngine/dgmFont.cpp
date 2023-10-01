//glutText.hpp
#pragma once
#include <GL/glew.h>
#define STB_IMAGE_IMPLEMENTATION
#include  <stb_image.h>
#include <iostream>
#include <GL/freeglut.h>
#include <fstream>
#include <sstream>
#include "dgmFont.hpp"
    long double winX, winY;
    int width, height, nrChannels;
    unsigned int texture;
    std::string fontInfo, line;
    float yoffset, tempY;

    std::vector<CharInfo> charInfoList;

    std::string filepath;
    //Used for finding .fnt and .png files with same name and loading them
    int  dgm::loadFont(std::string name) {
        //Used for finding .fnt and .png files with same name and loading them
        filepath = "./assets/fonts/";
        unsigned char* data = stbi_load(filepath.append(name).append(".png").c_str(), &width, &height, &nrChannels, 0);
        if (!data) {
            std::cerr << "Error loading font bipmap texture" << std::endl;
            return EXIT_FAILURE;
        }
        std::cout << "loaded font texture" << std::endl;
        //Setting up Texture
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

        //Texture Parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //Freeing loaded image
        stbi_image_free(data);
        filepath = "./assets/fonts/";

        std::ifstream inputFile(filepath.append(name).append(".fnt").c_str()); // Replace with your file name
        if (inputFile.is_open()) {
            fontInfo.clear();
            while (std::getline(inputFile, line)) {
                fontInfo += line + "\n";
            }
            inputFile.close();
        }
        else {
            std::cerr << "Error loading font data" << std::endl;
        }

        std::stringstream ss(fontInfo);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, '\n')) {
            tokens.push_back(token);
        }

        for (const std::string& token : tokens) {
            if (token.find("char id=") != std::string::npos) {
                CharInfo charInfo;
                sscanf_s(token.c_str(), "char id=%d x=%d y=%d width=%d height=%d xoffset=%d yoffset=%d xadvance=%d page=%d chnl=%d",
                    &charInfo.id, &charInfo.x, &charInfo.y, &charInfo.width, &charInfo.height, &charInfo.xoffset,
                    &charInfo.yoffset, &charInfo.xadvance, &charInfo.page, &charInfo.chnl);
                charInfoList.push_back(charInfo);

            }
        }
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glEnableVertexAttribArray(1);
    }

    void printText(const char* text, long double X, long double Y) {
        winX = glutGet(GLUT_WINDOW_WIDTH);
        winY = glutGet(GLUT_WINDOW_HEIGHT);

        glEnable(GL_TEXTURE_2D);

        glColor3f(0.2f, 0.9f, 0.5f);
        std::vector<GLfloat> vertices;
        std::vector<GLfloat> texCoords;
        for (int i{ 0 }; text[i] != '\0'; i++) {
            //std::cout << text[i] << std::endl;
            for (const CharInfo& charInfo : charInfoList) {

                if (charInfo.id == text[i]) {
                    tempY = Y;
                    tempY -= static_cast<GLfloat>(charInfo.yoffset) / winY;
                    //glTexCoord2f(static_cast<float>(charInfo.x) / width, static_cast<float>(charInfo.y + charInfo.height) / height);
                    texCoords.push_back(static_cast<float>(charInfo.x) / width);
                    texCoords.push_back(static_cast<float>(charInfo.y + charInfo.height) / height);
                    //glVertex2f(X, tempY- static_cast<float>(charInfo.height) / winY);
                    vertices.push_back(X);
                    vertices.push_back(tempY - static_cast<float>(charInfo.height) / winY);
                    //glTexCoord2f(static_cast<float>(charInfo.x) / width, static_cast<float>(charInfo.y) / height);
                    texCoords.push_back(static_cast<float>(charInfo.x) / width);
                    texCoords.push_back(static_cast<float>(charInfo.y) / height);
                    //glVertex2f(X, tempY );
                    vertices.push_back(X);
                    vertices.push_back(tempY);
                    //glTexCoord2f(static_cast<float>(charInfo.x + charInfo.width) / width, static_cast<float>(charInfo.y) / height);
                    texCoords.push_back(static_cast<float>(charInfo.x + charInfo.width) / width);
                    texCoords.push_back(static_cast<float>(charInfo.y) / height);
                    //glVertex2f(X + static_cast<float>(charInfo.width) / winX, tempY);
                    vertices.push_back(X + static_cast<float>(charInfo.width) / winX);
                    vertices.push_back(tempY);
                    //glTexCoord2f(static_cast<float>(charInfo.x + charInfo.width)/width, static_cast<float>(charInfo.y + charInfo.height) / height);
                    texCoords.push_back(static_cast<float>(charInfo.x + charInfo.width) / width);
                    texCoords.push_back(static_cast<float>(charInfo.y + charInfo.height) / height);
                    //glVertex2f(X + static_cast<float>(charInfo.width) / winX, tempY - static_cast<float>(charInfo.height) / winY);
                    vertices.push_back(X + static_cast<float>(charInfo.width) / winX);
                    vertices.push_back(tempY - static_cast<float>(charInfo.height) / winY);
                    X += static_cast<float>(charInfo.xadvance) / winX;

                    //std::cout << "Finished rendering: " << static_cast<char>(charInfo.id) << "  Error:"<< glGetError() << std::endl;
                }
            }
        }


        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, texCoords.data());
        glVertexPointer(2, GL_FLOAT, 0, vertices.data());
        glTexCoordPointer(2, GL_FLOAT, 0, texCoords.data());
        glDrawArrays(GL_QUADS, 0, vertices.size() / 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glBindTexture(GL_TEXTURE_2D, 0);

    }
