//Scene2D.cpp
#include "Scene2D.hpp"

/*
void dgm::Scene2D::add(Shape2D * child) {
	objects.push_back(child);
};
*/
dgm::Shape2D* dgm::Scene2D::newShape(std::vector<float>* vertices) {
	Shape2D* child = new Shape2D;
	if (!vertices->empty()) {
		child->vecs = *vertices;
	}
	objects.push_back(child);
	return child;
}

void dgm::Scene2D::remove(Shape2D* child) {
	auto it = std::find(objects.begin(),objects.end(),child);
	if (it != objects.end()) {
		objects.erase(it);
		delete child;
	}
}
dgm::Scene2D::~Scene2D() {
	for (const auto& object : objects) {
		delete object;
	}
}



//widgets or whatever

dgm::Shape2D::~Shape2D() {
	for (const auto& child : children) {
		delete child;
	}
}

dgm::Scene2D* dgm::newScene() {
	return new Scene2D();

}



