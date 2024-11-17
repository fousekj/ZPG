#include "DynamicRotation.h"

DynamicRotation::DynamicRotation(float angle, glm::vec3 axis, float speed)
{
	this->angle = angle;
	this->axis = axis;
	this->speed = speed;
}

void DynamicRotation::updateRotation(float angle, glm::vec3 axis, float speed)
{
	this->angle = angle;
	this->axis = axis;
	this->speed = speed;
}

glm::mat4 DynamicRotation::getTransformMatrix()
{
	float new_angle = this->angle + this->speed;
	if (new_angle > 360.f)
		new_angle = 0.f;
	this->angle = new_angle;

	return glm::rotate(glm::mat4(1.0f), glm::radians(new_angle), this->axis);
}
