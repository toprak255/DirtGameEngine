#include "Scene2D.hpp"


dgm::Object2D* dgm::newObject(dgm::Scene2D* scene) {
	dgm::Object2D* child = new dgm::Object2D();
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
void dgm::removeObject(Scene2D* scene, TemplateObject2D* child) {
	auto it = std::find(scene->objects.begin(), scene->objects.end(), child);
	if (it != scene->objects.end()) {
		scene->objects.erase(it);
		delete child;
	}
}
void dgm::removeEntity(Scene2D* scene, TemplateObject2D* child) {
	auto it = std::find(scene->entities.begin(), scene->entities.end(), child);
	if (it != scene->entities.end()) {
		scene->entities.erase(it);
		delete child;
	}
}
// Move each vertex's position
void dgm::Entity2D::move(float x, float y) {
 
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






dgm::TemplateObject2D::~TemplateObject2D(){
	/*
	for (SceneObject2D* child : children) {
		delete child;
	}
	*/
}