#pragma once
#include <GL/glew.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

/**
* @file BasicTransformation.h
 *
 * @brief BasicTransformation class
 *
 * This class is used for basic transformations
 * It is used as a base class for other transformations
 * It has one virtual method getTransformMatrix
 * which returns transformation matrix
 *
 * @Author Jiri Fousek FOU0027
*/

class BasicTransformation
{
public:
	virtual glm::mat4 getTransformMatrix() = 0;
};

