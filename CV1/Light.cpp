#include "Light.h"

Light::Light(glm::vec3 position, glm::vec3 color)
{
	this->position = position;
	this->color = color;
}

void Light::setPosition(glm::vec3 position)
{
	this->position = position;
}

void Light::setColor(glm::vec3 color)
{
	this->color = color;
}

void Light::notify_observers()
{
	for (int i = 0; i < this->observers.size(); i++)
	{
		this->observers[i]->update(*this, 0);
	}
}
