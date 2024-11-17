#include "Translation.h"

Translation::Translation(glm::vec3 position)
{
	this->position = position;
}

glm::mat4 Translation::getTransformMatrix()
{
	return glm::translate(glm::mat4(1.f), this->position);
}


