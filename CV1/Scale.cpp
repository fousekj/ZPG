#include "Scale.h"

/**
* @file Scale.cpp
 *
 * @brief Scale. file with functions definitions
 *
 * This file contains functions definitions for Scale class
 * which is used for scaling objects
 *
 * @author Jiøí Fousek FOU0027
*/

Scale::Scale(float scale)
{
	this->scale = scale;
}

glm::mat4 Scale::getTransformMatrix()
{
	return glm::scale(glm::mat4(1.f), glm::vec3(scale));
}
