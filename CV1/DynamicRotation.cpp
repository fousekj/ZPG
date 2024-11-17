#include "DynamicRotation.h"

DynamicRotation::DynamicRotation(float angle, glm::vec3 axis)
{
	this->angle = angle;
	this->axis = axis;
}

void DynamicRotation::updateRotation(float angle, glm::vec3 axis)
{
	this->angle = angle;
	this->axis = axis;
}

glm::mat4 DynamicRotation::getTransformMatrix() const
{
	float new_angle = this->angle + 1.f;
	return glm::rotate(glm::mat4(1.0f), glm::radians(new_angle), this->axis);
}
