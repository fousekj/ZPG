#include "Scale.h"

Scale::Scale(float scale)
{
	this->scale = scale;
}

glm::mat4 Scale::getTransformMatrix() const
{
	return glm::scale(glm::mat4(1.f), glm::vec3(scale));
}
