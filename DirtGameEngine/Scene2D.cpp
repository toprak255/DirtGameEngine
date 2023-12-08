#include "Scene2D.hpp"


dgm::Shape2D* dgm::newShape(dgm::Scene2D* scene) {
	dgm::Shape2D* child = new dgm::Shape2D();
	scene->objects.push_back(child);
	return child;
}

dgm::Entity2D* dgm::newEntity(dgm::Scene2D* scene) {
	dgm::Entity2D* child = new dgm::Entity2D();
	scene->entities.push_back(child);
	return child;
}

void dgm::Entity2D::callFunction() {
	if (entityFunction) {
		entityFunction();
	}
}
void dgm::removeObject(Scene2D* scene, SceneObject2D* child) {
	auto it = std::find(scene->objects.begin(), scene->objects.end(), child);
	if (it != scene->objects.end()) {
		scene->objects.erase(it);
		delete child;
	}
}
void dgm::removeEntity(Scene2D* scene, SceneObject2D* child) {
	auto it = std::find(scene->entities.begin(), scene->entities.end(), child);
	if (it != scene->entities.end()) {
		scene->entities.erase(it);
		delete child;
	}
}
// Move each vertex's position
void dgm::Entity2D::move(float deltaX, float deltaY) {
	for (int i = 0; i < vecs.size(); i += 4) {
		vecs[i] += deltaX;      
		vecs[i + 1] += deltaY;  
	}
}

dgm::Scene2D::~Scene2D() {
	for (const auto& object : objects) {
		delete object;
	}
	for (const auto& entity : entities) {
		delete entity;
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