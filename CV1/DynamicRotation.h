#pragma once
#include "Rotation.h"

/**
* @file DynamicRotation.h
* 
* @brief DynamicRotation class
* 
* Class for dynamic rotation of object
* 
* @author Jiøí Fousek FOU0027
* 
*/

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

