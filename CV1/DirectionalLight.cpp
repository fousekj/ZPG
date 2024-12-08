#include "DirectionalLight.h"

/**
* @file DirectionalLight.cpp
* 
* @brief DirectionalLight file with functions definitions
* 
* @author Jiøí Fousek FOU0027
*/

DirectionalLight::DirectionalLight(glm::vec3 direction, glm::vec3 color, int id)
{
	this->direction = direction;
	this->color = color;
	this->id = id;
}

void DirectionalLight::notify_observers()
{
	for (auto observer : observers)
	{
		observer->update(*this);
	}
}
