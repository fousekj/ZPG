#pragma once
#include <GL/glew.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>


class BasicTransformation
{
public:
	virtual glm::mat4 getTransformMatrix() const = 0;
};

