#pragma once

#include "glm.hpp"
#include <vector>

//vector of pointer vectors
std::vector<std::vector<int*>> entities;


class Entity2D
{
public:
	glm::vec2* pos;
	int* func = NULL;
	bool* collision;
	std::vector< glm::vec2>* vertices;


};
