#pragma once

#include <glm/glm.hpp>
#include <vector>

namespace dgm {
	namespace Shape2D {
		std::vector<float> nGon(glm::vec2 center, float radius, int cornerCount);
		std::vector<float> Rectangle(glm::vec2 bottomLeft, glm::vec2 size);

	}//Shape2D namespace end
}//dgm namespace end