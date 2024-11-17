#pragma once
#include "Rotation.h"

class DynamicRotation : public BasicTransformation
{
private:
	glm::vec3 axis;
	float angle;
	float speed;
public:
	DynamicRotation(float angle, glm::vec3 axis, float speed);
	void updateRotation(float angle, glm::vec3 axis, float speed);
	glm::mat4 getTransformMatrix() override;
};

