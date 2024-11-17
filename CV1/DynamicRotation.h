#pragma once
#include "Rotation.h"

class DynamicRotation : public BasicTransformation
{
private:
	glm::vec3 axis;
	float angle;
public:
	DynamicRotation(float angle, glm::vec3 axis);
	void updateRotation(float angle, glm::vec3 axis);
	glm::mat4 getTransformMatrix() const override;
};

