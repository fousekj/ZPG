#include "SpotLight.h"

SpotLight::SpotLight(glm::vec3 position, glm::vec3 direction, glm::vec3 color, float cutOff, int id)
{
	this->position = position;
	this->direction = direction;
	this->color = color;
	this->cutOff = cutOff;
	this->id = id;
}

void SpotLight::notify_observers()
{
	for (auto observer : observers)
	{
		observer->update(*this, this->id);
	}
}
