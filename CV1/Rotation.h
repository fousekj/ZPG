#pragma once
//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include "BasicTransformation.h"

class Rotation : public BasicTransformation
{
private:
	glm::vec3 axis;
	float angle;
public:
	Rotation(float angle, glm::vec3 axis);
	glm::mat4 getTransformMatrix() const override;
	void updateRotation(float angle, glm::vec3 axis);
};

