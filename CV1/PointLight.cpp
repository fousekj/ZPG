#include "PointLight.h"

PointLight::PointLight(glm::vec3 position, glm::vec3 color, int id)
{
	this->position = position;
	this->color = color;
	this->id = id;
}

void PointLight::setPosition(glm::vec3 position)
{
	this->position = position;
}

void PointLight::setColor(glm::vec3 color)
{
	this->color = color;
}

void PointLight::notify_observers()
{
	for (int i = 0; i < this->observers.size(); i++)
	{
		this->observers[i]->update(*this, this->id);
	}
}
