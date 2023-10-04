#include "DirtGameEngine.hpp"
#include "Shapes.hpp"



void dgm::circle(int res,float x, float y,int bDiameter) {
	std::vector<vec2> circle;
	float angle = 6.28318530718f / res;
	for (int i = 0; i < res; i++) {
		vec2 abc{ (x + cos(i * angle) * bDiameter) / dgm::WindowSettings.screenSize.x, (y + sin(i * angle) * bDiameter) / dgm::WindowSettings.screenSize.y };
	}
}

