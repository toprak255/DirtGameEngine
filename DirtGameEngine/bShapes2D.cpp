#include "bShapes2D.hpp"
#include <iostream>
#include <math.h>
#include "Window.hpp"



std::vector<float> dgm::Shape2D::Rectangle(glm::vec2 bottomLeft, glm::vec2 size) {

}

std::vector<float> dgm::Shape2D::nGon(glm::vec2 center, float radius, int cornerCount)
{
	std::vector<float> vecs;
	if (cornerCount < 3) {
		std::cerr << "dgm::nGon, Amount of corners can't be less than 3 \n";
		return vecs;
	}
	else {
		float angle = 6.28318530718f / cornerCount;
		float scale = 1.0f / dgm::WindowSettings::screenSize.y * radius;
		for (int i{ 0 }; i < cornerCount; i++) {

			vecs.emplace_back(center.x + cos(i * angle) * scale);
			vecs.emplace_back(center.y + sin(i * angle) * scale);
			vecs.emplace_back(center.x);
			vecs.emplace_back(center.y);
			vecs.emplace_back(center.x + cos((i + 1) * angle) * scale);
			vecs.emplace_back(center.y + sin((i + 1) * angle) * scale);
		}
		return vecs;
	}
}
