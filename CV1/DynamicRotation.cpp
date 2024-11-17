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

glm::mat4 DynamicRotation::getTransformMatrix()
{
	float new_angle = this->angle + 1.f;
	if (new_angle > 360.f)
		new_angle = 0.f;
	this->angle = new_angle;

	return glm::rotate(glm::mat4(1.0f), glm::radians(new_angle), this->axis);
}
