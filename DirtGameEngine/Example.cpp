#include "DirtGameEngine.hpp"


int main() {
	float x, y;
	dgm::initWindow();
	dgm::getScreenSize(&x,&y);
	dgm::renderLoop();


}