#include "Translation.h"

/**
* @file Translation.cpp
* 
* @brief Translation class implementation
* 
* @author Jiøí Fousek FOU0027
*/

Translation::Translation(glm::vec3 position)
{
	this->position = position;
}

glm::mat4 Translation::getTransformMatrix()
{
	return glm::translate(glm::mat4(1.f), this->position);
}


