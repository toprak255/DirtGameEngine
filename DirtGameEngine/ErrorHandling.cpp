#include "ErrorHandling.hpp"
#include <iostream>

void dgm::error_callback(int error, const char* description)
{
	std::cerr << "Error: " << description << std::endl;
}
