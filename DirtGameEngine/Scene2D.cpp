#include "Scene2D.hpp"


dgm::Shape2D* dgm::Scene2D::newShape(std::vector<float>* vertices) {
	Shape2D* child = new Shape2D;
	if (!vertices->empty()) {
		child->vecs = *vertices;
	}
	objects.push_back(child);
	return child;}


dgm::Entity2D* dgm::Scene2D::newEntity(std::vector<float>* vertices) {
	Entity2D* child = new Entity2D;
	if (!vertices->empty()) {
		child->vecs = *vertices;
	}
	objects.push_back(child);
	return child;}

void dgm::Entity2D::move(float x, float y) {
	for (int i=0; i < vecs.size(); i++) {
		if (i % 2 == 0) {
			vecs[i] += x;
		}
		else {
			vecs[i] += y;
		}
	}
}
void dgm::Scene2D::remove(SceneObject2D* child) {
	auto it = std::find(objects.begin(), objects.end(), child);
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
dgm::Scene2D* dgm::newScene() {
	return new Scene2D();

}






dgm::SceneObject2D::~SceneObject2D(){
	/*
	for (SceneObject2D* child : children) {
		delete child;
	}
	*/
}