#include "DirectionalLight.h"

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
