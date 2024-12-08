#include "SpotLight.h"

/**
* @file SpotLight.cpp
* 
* @brief SpotLight class implementation
* 
* @author Jiøí Fousek FOU0027
*/

SpotLight::SpotLight(Camera* camera, glm::vec3 color, float cutOff, float outerCutOff, int id)
{
	this->camera = camera;
	this->color = color;
	this->cutOff = cutOff;
	this->outerCutOff = outerCutOff;
	this->id = id;
	this->position = camera->getPosition();
	this->direction = camera->getFront();
}

void SpotLight::notify_observers()
{
	this->position = camera->getPosition();
	this->direction = camera->getFront();
	for (auto observer : observers)
	{
		observer->update(*this, this->id);
	}
}
